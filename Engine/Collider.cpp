
#include "SphereCollider.h"
#include "GameObject.h"
#include "Model.h"
#include "Transform.h"
#include"Collider.h"
//�R���X�g���N�^
Collider::Collider() :
	pGameObject_(nullptr)
{
}

//�f�X�g���N�^
Collider::~Collider()
{
}



//���̓��m�̏Փ˔���
//�����FcircleA	�P�ڂ̋��̔���
//�����FcircleB	�Q�ڂ̋��̔���
//�ߒl�F�ڐG���Ă����true
bool Collider::IsHitCircleVsCircle(SphereCollider* circleA, SphereCollider* circleB)
{
	XMFLOAT3 centerA = circleA->center_;
	XMFLOAT3 positionA = circleA->pGameObject_->GetWorldPosition();
	XMFLOAT3 centerB = circleB->center_;
	XMFLOAT3 positionB = circleB->pGameObject_->GetWorldPosition();

	XMVECTOR v = (XMLoadFloat3(&centerA) + XMLoadFloat3(&positionA))
		- (XMLoadFloat3(&centerB) + XMLoadFloat3(&positionB));


	// Calculate the squared distance between the centers
	float distanceSquared = XMVector3LengthSq(v).m128_f32[0];

	// Compare squared distance to the sum of the radii squared
	float radiusSum = circleA->size_.x + circleB->size_.x;
	return distanceSquared <= (radiusSum * radiusSum);
}

//�e�X�g�\���p�̘g��`��
//�����Fposition	�I�u�W�F�N�g�̈ʒu
void Collider::Draw(XMFLOAT3 position)
{

}