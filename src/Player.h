#pragma once

#include "Math.h"

class Player {
public:
	Player();

	Vec2f getPos() const;
	void setPos(const Vec2f& pPos);

	void move();

	int getHealth() const;
	void setHealth(int pHealth);

	int getPower() const;
	void setPower(int pPower);

private:
	Vec2f mPos;
	Vec2f mDisplacement;
	int mHealth;
	int mPower;
	float mSpeed;
	bool mMoving;
};
