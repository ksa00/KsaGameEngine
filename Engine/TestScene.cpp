#include "TestScene.h"
#include"Image.h"



TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene"),hTitle(-1)
{
}

void TestScene::Initialize()
{
	hTitle = Image::Load("TITLE.png");
}

void TestScene::Update()
{

}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
