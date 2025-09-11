#pragma once

#include "Math.h"

class Player {

public:
	Player(const Vec2f& _pos = { 0.f, 0.f }, short _tile_size = 30);

	Vec2f get_pos();

	Vec2f get_delta();

	void move();

	void set_delta(const Vec2f &value);

private:
	Vec2f pos;
	Vec2f start_pos;
	Vec2f delta;


	short hp;
	short power;
	double speed;
	bool moving;

};