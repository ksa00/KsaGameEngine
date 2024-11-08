#pragma once

#include <list>
#include <string>
#include "Transform.h"
#include "Direct3D.h"

#include"Collider.h"
using std::string;
using std::list;



class GameObject
{
private:
	//�t���O
	struct OBJECT_STATE
	{
		unsigned initialized : 1;	//�������ς݂�
		unsigned entered : 1;		//�X�V���邩
		unsigned visible : 1;		//�`�悷�邩
		unsigned dead : 1;			//�폜���邩
	};
	OBJECT_STATE state_;
	GameObject* pParent_;
	list<GameObject*>	childList_;
protected:
	
	Transform			transform_;
	
	string				objectName_; //�I�u�W�F�N�g�̖��O�̕�����
	//�Փ˔��胊�X�g
	std::list<Collider*>	colliderList_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	virtual  ~GameObject();

	virtual void Initialize(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw() = 0;
	virtual void Release(void) = 0;

	bool isDead_();
	void DrawSub();
	void UpdateSub();
	void ReleaseSub();
	void KillMe();
	//�q�I�u�W�F�N�g��S�č폜
	void KillAllChildren();
	void SetPosition(XMFLOAT3 position);
	void SetPosition(float x, float y, float z);
	XMFLOAT3 GetWorldPosition() { return Transform::Float3Add(GetParent()->transform_.position_, transform_.position_); }

	//�e�I�u�W�F�N�g���擾
//�ߒl�F�e�I�u�W�F�N�g�̃A�h���X
	GameObject* GetParent();
	//�q�I�u�W�F�N�g���X�g���擾
	//�ߒl�F�q�I�u�W�F�N�g���X�g
	std::list<GameObject*>* GetChildList();
	//�q�I�u�W�F�N�g��ǉ��i���X�g�̍Ō�ցj
	//�����F�ǉ�����I�u�W�F�N�g
	void PushBackChild(GameObject* obj);

	//�q�I�u�W�F�N�g��ǉ��i���X�g�̐擪�ցj
	//�����Fobj �ǉ�����I�u�W�F�N�g
	void PushFrontChild(GameObject* obj);
	GameObject* FindChildObject(const string& name);


	//���O�ŃI�u�W�F�N�g�������i�Ώۂ͑S�́j
	//�����F�������閼�O
	//�ߒl�F�������I�u�W�F�N�g�̃A�h���X
	GameObject* FindObject(const std::string& name) { return GetRootJob()->FindChildObject(name); }

	//�I�u�W�F�N�g�̖��O���擾
	//�ߒl�F���O
	const std::string& GetObjectName(void) const;



	void AddCollider(Collider* pCollider);
	void ClearCollider();
	void Collision(GameObject* pTarget);
	//RootJob���擾
	GameObject* GetRootJob();
	//�����ƏՓ˂����ꍇ�ɌĂ΂��i�I�[�o�[���C�h�p�j
	//�����FpTarget	�Փ˂�������
	virtual void OnCollision(GameObject* pTarget) {};


private:

	//�I�u�W�F�N�g�폜�i�ċA�j
	//�����Fobj�@�폜����I�u�W�F�N�g
	void KillObjectSub(GameObject* obj);


};

//�e���v���[�g�̒�`
template <class T>
T* Instantiate(GameObject* pParent)
{
	T* pNewObject = new T(pParent);
	if (pParent != nullptr)
	{
		pParent->PushBackChild(pNewObject);
	}
	pNewObject->Initialize();
	return pNewObject;
}