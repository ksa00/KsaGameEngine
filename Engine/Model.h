#pragma once
//必要なインクルードを書く
#include <string>
#include <vector>
#include "Fbx.h"

namespace Model
{
	struct ModelData
	{
		Fbx* pfbx_;
		Transform transform_;//トランスフォーム
		std::string filename_;
		ModelData() :pfbx_(nullptr), filename_("") {}
	};
	int Load(std::string fileName);
	void SetTransform(int hModel, Transform& transform);
	void Draw(int hModel);
	void Release();
	void RayCast(int hModel, RayCastData& rayData);

}