#pragma once
#include "GameObject.h"
#include"Fbx.h"
class Player :
    public GameObject
{
    Fbx* pFbx;
    int hModel_;//ƒ‚ƒfƒ‹”Ô†
public:
    Player(GameObject* parent);
    ~Player();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

