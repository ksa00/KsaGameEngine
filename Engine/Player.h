#pragma once
#include "GameObject.h"
#include"Fbx.h"
class Player :
    public GameObject
{
    Fbx* pFbx;
public:
    Player(GameObject* parent);
    ~Player();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

