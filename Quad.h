#pragma once
#include "Direct3D.h"
#include "Texture.h"
#include <DirectXMath.h>

using namespace DirectX;
//コンスタントバッファー

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
	XMMATRIX	matW;
};
//XMFLOAT3でもよい。
//頂点情報
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal;

};
class Quad
{protected:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;   //インデクスバッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ
	Texture* pTexture_;
public:
	Quad();
virtual ~Quad();
	HRESULT Initialize();
	void Draw();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();
};