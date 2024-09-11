#include "Player.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),pOden(nullptr)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	pOden = new Fbx;
	pOden->Load("Asset//oden.fbx");
	transform_.position_ = { 0,-3,0 };
	transform_.scale_ = { 3,3,3 };
}

void Player::Update()
{
	transform_.rotate_ .y+= 1.0f;
}

void Player::Draw()
{
	pOden->Draw(transform_);
}

void Player::Release()
{
	pOden->Release();
}
