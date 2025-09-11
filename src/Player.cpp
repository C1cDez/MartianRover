#include "Player.h"
#include <cmath>	


Player::Player(const Vec2f& _pos, short _tile_size) {
	pos = _pos;

	start_pos = _pos;

	hp = 100;
	power = 100;
	speed = 2.5;
	moving = false;
}

Vec2f Player::get_pos() { return pos; }

Vec2f Player::get_delta() { return delta; }

void Player::set_delta(const Vec2f& value) { if (!moving) { delta = value; moving = true; } }

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
