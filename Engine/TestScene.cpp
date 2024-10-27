#include "TestScene.h"
#include "PlayScene.h"
#include "SceneManager.h"
#include "Input.h"





TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

void TestScene::Initialize()
{
	Title_spr.Load("Asset/TITLE.png");

}

void TestScene::Update()
{
	if (Input::IsKey(DIK_SPACE)) {
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
		Instantiate<PlayScene>(this);
		

	}
}

void TestScene::Draw()
{
	Title_spr.Draw(transform_);
}

void TestScene::Release()
{
	//Title_spr->Release();
}
