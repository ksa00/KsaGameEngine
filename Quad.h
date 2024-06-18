#pragma once
#include "Direct3D.h"
#include "Texture.h"
#include <DirectXMath.h>

using namespace DirectX;
//�R���X�^���g�o�b�t�@�[

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
	XMMATRIX	matW;
};
//XMFLOAT3�ł��悢�B
//���_���
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal;

};
class Quad
{protected:
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;   //�C���f�N�X�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@
	Texture* pTexture_;
public:
	Quad();
virtual ~Quad();
	HRESULT Initialize();
	void Draw();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();
};