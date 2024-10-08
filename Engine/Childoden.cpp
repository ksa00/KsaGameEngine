#include "Childoden.h"

Childoden::Childoden(GameObject* parent)
	:GameObject(parent, "Player"), pFbx(nullptr)
{
}

Childoden::~Childoden()
{
}

void Childoden::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Asset//oden.fbx");
	transform_.position_ = { 0,1.60,0 };
	transform_.scale_ = { 0.25,0.25,0.25 };

}

void Childoden::Update()
{
	transform_.rotate_.y += 1.0f;
}

void Childoden::Draw()
{
	pFbx->Draw(transform_);

}

void Childoden::Release()
{
	pFbx->Release();

}
