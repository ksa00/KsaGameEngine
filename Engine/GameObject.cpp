#include "GameObject.h"

//�R���X�g���N�^�i�e�����O���Ȃ��j
GameObject::GameObject(void) :
	GameObject(nullptr, "")
{

}


GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent),objectName_(name)

{
	childList_.clear();
	state_ = { 0, 1, 1, 0 };

	if (parent)
		transform_.pParent_ = &parent->transform_;
}

GameObject::~GameObject()
{
	for (auto it = colliderList_.begin(); it != colliderList_.end(); it++)
	{
		SAFE_DELETE(*it);
	}
	colliderList_.clear();
}

bool GameObject::isDead_()
{
	return (state_.dead != 0);
}

void GameObject::DrawSub()
{
	Draw();


	//���̎q�I�u�W�F�N�g�̕`�揈��
	for (auto it = childList_.begin(); it != childList_.end(); it++)
	{
		(*it)->DrawSub();
	}
}

void GameObject::UpdateSub()
{
	Update();
	Transform();

	for (auto it = childList_.begin(); it != childList_.end(); it++)
	{
		(*it)->UpdateSub();
	}

   	for (auto it = childList_.begin(); it != childList_.end();)
	{
		if ((*it)->isDead_() == true)
		{
			(*it)->ReleaseSub();
			SAFE_DELETE(*it);
			it = childList_.erase(it);
		}
		else
		{
			//�����蔻��
			(*it)->Collision(GetParent());
			it++;
		}
	}
}

void GameObject::ReleaseSub()
{
	//�R���C�_�[���폜
	ClearCollider();


	for (auto it = childList_.begin(); it != childList_.end(); it++)
	{
		(*it)->ReleaseSub();
		SAFE_DELETE(*it);
	}

	Release();
}

void GameObject::KillMe()
{
	state_.dead = 1;
}

void GameObject::KillAllChildren()
{
	//�q�������Ȃ��Ȃ�I���
	if (childList_.empty())
		return;

	//�C�e���[�^
	auto it = childList_.begin();	//�擪
	auto end = childList_.end();	//����

	//�q�I�u�W�F�N�g��1���폜
	while (it != end)
	{
		KillObjectSub(*it);
		delete* it;
		it = childList_.erase(it);
	}

	//���X�g���N���A
	childList_.clear();
}

void GameObject::SetPosition(XMFLOAT3 position)
{
	transform_.position_ = position;
}

void GameObject::SetPosition(float x, float y, float z)
{
	SetPosition(XMFLOAT3(x, y, z));
}
//�q�I�u�W�F�N�g���X�g���擾
std::list<GameObject*>* GameObject::GetChildList()
{
	return &childList_;
}


GameObject* GameObject::GetParent()
{
	return pParent_;
}

void GameObject::PushBackChild(GameObject* obj)
{
	assert(obj != nullptr);

	obj->pParent_ = this;
	childList_.push_back(obj);

}

void GameObject::PushFrontChild(GameObject* obj)
{
	assert(obj != nullptr);

	obj->pParent_ = this;
	childList_.push_front(obj);
}

GameObject* GameObject::FindChildObject(const string& name)
{
	//�q�������Ȃ��Ȃ�I���
	if (childList_.empty())
		return nullptr;

	//�C�e���[�^
	auto it = childList_.begin();	//�擪
	auto end = childList_.end();	//����

	//�q�I�u�W�F�N�g����T��
	while (it != end) {
		//�������O�̃I�u�W�F�N�g���������炻���Ԃ�
		if ((*it)->GetObjectName() == name)
			return *it;

		//���̎q���i���j�ȍ~�ɂ��Ȃ����T��
		GameObject* obj = (*it)->FindChildObject(name);
		if (obj != nullptr)
		{
			return obj;
		}

		//���̎q��
		it++;
	}

	//������Ȃ�����
	return nullptr;
}




const std::string& GameObject::GetObjectName(void) const
{
	return objectName_;
}

void GameObject::AddCollider(Collider* pCollider)
{
	pCollider->SetGameObject(this);
	colliderList_.push_back(pCollider);
}

void GameObject::ClearCollider()
{
	for (auto it = colliderList_.begin(); it != colliderList_.end(); it++)
	{
		SAFE_DELETE(*it);
	}
	colliderList_.clear();
}




void GameObject::Collision(GameObject* pTarget)
{
	//�������m�̓����蔻��͂��Ȃ�
	if (pTarget == nullptr || this == pTarget)
	{
		return;
	}

	//������pTarget�̃R���W���������g���ē����蔻��
	//1�̃I�u�W�F�N�g�������̃R���W�������������Ă�ꍇ������̂œ�d���[�v
	for (auto i = this->colliderList_.begin(); i != this->colliderList_.end(); i++)
	{
		for (auto j = pTarget->colliderList_.begin(); j != pTarget->colliderList_.end(); j++)
		{
			if ((*i)->IsHit(*j))
			{
				//��������
				this->OnCollision(pTarget);
			}
		}
	}

	//�q�������Ȃ��Ȃ�I���
	if (pTarget->childList_.empty())
		return;

	//�q���������蔻��
	for (auto i = pTarget->childList_.begin(); i != pTarget->childList_.end(); i++)
	{
		Collision(*i);
	}
}

GameObject* GameObject::GetRootJob()
{
	if (GetParent() == nullptr)
	{
		return this;
	}
	else return GetParent()->GetRootJob();
}

void GameObject::KillObjectSub(GameObject* obj)
{
	if (!childList_.empty())
	{
		auto list = obj->GetChildList();
		auto it = list->begin();
		auto end = list->end();
		while (it != end)
		{
			KillObjectSub(*it);
			delete* it;
			it = list->erase(it);
		}
		list->clear();
	}
	obj->Release();
}
