#pragma once

#include "Math.h"

class Player
{
public:
	Player();

	Vec2i getPos() const;
	void setPos(const Vec2i& pPos);

	void move(const Vec2i& pDV);

private:
	Vec2i mPos;
	unsigned int mHealth;
	unsigned int mPower;
};
