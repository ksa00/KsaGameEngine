#include "Childoden.h"
#include"Model.h"
Childoden::Childoden(GameObject* parent)
	:GameObject(parent, "Childoden"),hModel_(-1)
{
}

Childoden::~Childoden()
{
}

void Childoden::Initialize()
{
hModel_=Model::Load("Asset//oden.fbx");
	
}

void Childoden::Update()  
{
	transform_.rotate_.y += 1.0f;
	transform_.position_.z += 0.05f;
	transform_.position_.y += 0.05f;
	if (transform_.position_.y > 4.0f)KillMe();
}

void Childoden::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

}

void Childoden::Release()
{
	

}
