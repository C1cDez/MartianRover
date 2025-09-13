#pragma once

#include <SFML/Graphics.hpp>

#include "Math.h"


struct Renderer
{
	unsigned int mScreenWidth, mScreenHeight;
	unsigned int mFPS;
	Mat2i mProjectionMatrix;

	sf::Vector2f project(const Vec2i&) const;
};


class Player;

class PlayerRenderer
{
public:
	PlayerRenderer(const Player* const pPlayer);

	void link(const Renderer& pRenderer);
	const sf::CircleShape& get() const;

private:
	Player const* mPlayer;
	sf::CircleShape mPlayerShape;   // Temporary till we get texture
};
