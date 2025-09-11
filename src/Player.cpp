#include "Player.h"

#include <cmath>	


Player::Player()
{
	mPos = { .0f, .0f };
	mHealth = 100;
	mPower = 100;
	mSpeed = 2.5f;
}

Vec2f Player::getPos() const
{
	return mPos;
}
void Player::setPos(const Vec2f& pPos)
{
	mPos = pPos;
}
void Player::move(const Vec2f& pDiff)
{
	mPos.x += pDiff.x;
	mPos.y += pDiff.y;
}
int Player::getHealth() const
{
	return mHealth;
}
void Player::setHealth(int pHealth)
{
	mHealth = pHealth;
}
int Player::getPower() const
{
	return mPower;
}
void Player::setPower(int pPower)
{
	mPower = pPower;
}

/*
void Player::move() {
	if (delta.y < 0.f && pos.y + speed <= start_pos.y + delta.y) { 
		pos.y = start_pos.y + delta.y; 
		start_pos = pos; delta = { 0.f, 0.f }; 
		moving = false;
	}

	if (delta.y > 0.f && pos.y + speed >= start_pos.y + delta.y) {
		pos.y = start_pos.y + delta.y;
		start_pos = pos; delta = { 0.f, 0.f };
		moving = false;
	}

	if (delta.x > 0.f && pos.x + speed >= start_pos.x + delta.x) {
		pos.x = start_pos.x + delta.x;
		start_pos = pos; delta = { 0.f, 0.f };
		moving = false;
	}

	if (delta.x < 0.f && pos.x + speed <= start_pos.x + delta.x) {
		pos.x = start_pos.x + delta.x;
		start_pos = pos; delta = { 0.f, 0.f };
		moving = false;
	}

	if (moving) { 
		if (delta.y != 0.f) { pos.y += speed * (std::abs(delta.y) / delta.y); }
		if (delta.x != 0.f) { pos.x += speed * (std::abs(delta.x) / delta.x); }
	}
}
*/
