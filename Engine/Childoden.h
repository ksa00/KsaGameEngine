#pragma once
#include "GameObject.h"
#include"Fbx.h"

class Childoden :
    public GameObject
{
    Fbx* pFbx;
  
public:
    //コンストラクタ
    Childoden(GameObject* parent);

    //デストラクタ
    ~Childoden();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};