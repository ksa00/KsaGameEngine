#include "PlayScene.h"
#include"Player.h"
#include"Enemy.h"

PlayScene::PlayScene(GameObject* parent)
{
}

void PlayScene::Initialize()
{
	/*Player* pPlayer;
	pPlayer = new Player(this);
	pPlayer->Initialize();
	childList_.push_back(pPlayer);*/
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
