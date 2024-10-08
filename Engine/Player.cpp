#include "Player.h"
#include"Childoden.h"
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),pFbx(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Asset//oden.fbx");
	
	this->transform_.position_ = { 0,-3,0 };
	
	Instantiate<Childoden>(this);
	transform_.scale_ = { 3,3,3 };
}

void Player::Update()
{
	transform_.rotate_.y += 1.0f;
	if (transform_.rotate_.y > 60 * 10) {
		KillMe();
	}
}

void Player::Draw()
{
	pFbx->Draw(transform_);

}

void Player::Release()
{
	pFbx->Release();

}
