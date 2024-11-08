#include "SceneManager.h"
#include "Model.h"
#include "TestScene.h"
#include "PlayScene.h"
#include "GameOver.h"

SceneManager::SceneManager(GameObject* parent)
	:GameObject(parent, "SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TEST;
	nextSceneID_ = currentSceneID_;
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
	//���̃V�[�������݂̃V�[���ƈႤ�@���@�V�[����؂�ւ��Ȃ���΂Ȃ�Ȃ�
	if (currentSceneID_ != nextSceneID_)
	{
		//���̃V�[���̃I�u�W�F�N�g��S�폜
		KillAllChildren();

	

		//���̃V�[�����쐬
		switch (nextSceneID_)
		{
		case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
		case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
		case SCENE_ID_GAMEOVER: Instantiate<GameOver>(this); break;
		}
	
		currentSceneID_ = nextSceneID_;
	}

}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}

/// <summary>
/// �w�肵���V�[����nextSceneID_�ɐݒ肷��i������Update�ŃV�[�����ς��j
/// </summary>
/// <param name="_next">���Ɉڍs����V�[��ID(���̃t���[���ōX�V�j</param>
void SceneManager::ChangeScene(SCENE_ID _next)
{
	nextSceneID_ = _next;
}