#pragma once
#include <wincodec.h>
#include <d3d11.h>
#include <string>
// DirectXTexのライブラリをリンク
#pragma comment(lib, "DirectXTex.lib")
#include <DirectXTex.h>

//#include <wrl.h>
//using namespace Microsoft::WRL;
using std::string;


class Texture
{
	ID3D11SamplerState* pSampler_;
	ID3D11ShaderResourceView* pSRV_;
public:
	Texture();
	~Texture();
	HRESULT Load(string fileName);
	void Release();
	ID3D11SamplerState* GetSampler() { return pSampler_; }
	ID3D11ShaderResourceView* GetSRV() { return pSRV_; }
};