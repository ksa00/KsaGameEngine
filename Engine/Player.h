#pragma once
#include "GameObject.h"

class Player :
    public GameObject
{
    int hModel_;//モデル番号
public:
    Player(GameObject* parent);
    ~Player();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

