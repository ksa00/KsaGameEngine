#include "Childoden.h"
#include"Model.h"
Childoden::Childoden(GameObject* parent)
	:GameObject(parent, "Childoden"), pFbx(nullptr),hModel_(-1)
{
}

Childoden::~Childoden()
{
}

void Childoden::Initialize()
{
hModel_=Model::Load("Asset//oden.fbx");
	transform_.position_ = { 0,3.0,0 };
//transform_.scale_ = { 0.5,0.5,0.5 };
}

void Childoden::Update()
{
	transform_.rotate_.y += 1.0f;
	transform_.position_.z += 0.05f;
	transform_.position_.y += 0.05f;
	if (transform_.position_.y > 5.5f)KillMe();
}

void Childoden::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

void Childoden::Release()
{
	

}
