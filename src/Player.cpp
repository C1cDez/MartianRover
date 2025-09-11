#include "Player.h"

Player::Player()
{
	mPos = { 0, 0 };
	mHealth = 100;
	mPower = 100;
}
Vec2i Player::getPos() const
{
	return mPos;
}
void Player::setPos(const Vec2i& pPos)
{
	mPos = pPos;
}
void Player::move(const Vec2i& pDV)
{
	mPos.x += pDV.x;
	mPos.y += pDV.y;
}
