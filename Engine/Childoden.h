#pragma once
#include "GameObject.h"


class Childoden :
    public GameObject
{
   
    int hModel_;
public:
    //�R���X�g���N�^
    Childoden(GameObject* parent);

    //�f�X�g���N�^
    ~Childoden();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};