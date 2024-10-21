#pragma once
#include "GameObject.h"


class TestScene :
    public GameObject
{
    int hTitle;
public:
    TestScene(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

