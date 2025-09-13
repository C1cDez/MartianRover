#pragma once

#include <SFML/Graphics.hpp>

#include "Math.h"


struct Renderer
{
	unsigned int mScreenWidth, mScreenHeight;
	unsigned int mFPS;
	Mat2f mProjectionMatrix;

	sf::Vector2f project(const Vec2f&) const;
	sf::Vector2f project(const Vec2i&) const;
};


class Player;

class PlayerRenderer
{
public:
	PlayerRenderer(const Player* const pPlayer, unsigned int pMoveAnimMaxTime);

	void link(const Renderer& pRenderer); 
	const sf::CircleShape& get() const;

	void updateAnimation(const Renderer& pRenderer);

	void triggerMoveAnimation();
	bool doesMoveAnimPlay() const;

private:
	Player const* mPlayer;
	sf::CircleShape mPlayerShape;   // Temporary till we get texture

	unsigned int mMoveAnimMaxTime;
	int mMoveAnimTimer;
	Vec2i mLastPlayerPosition;
};
