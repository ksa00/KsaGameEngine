#pragma once
#include "GameObject.h"

class Player :
    public GameObject
{
    int hModel_;//���f���ԍ�
public:
    Player(GameObject* parent);
    ~Player();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

