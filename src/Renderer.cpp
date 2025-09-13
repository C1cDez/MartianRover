#include "Renderer.h"

#include "Player.h"


sf::Vector2f Renderer::project(const Vec2f& pVec) const
{
	Vec2f screen = mProjectionMatrix * pVec;
	return { screen.x, screen.y };
}
sf::Vector2f Renderer::project(const Vec2i& pVec) const
{
	return project(Vec2f{ static_cast<float>(pVec.x), static_cast<float>(pVec.y) });
}


PlayerRenderer::PlayerRenderer(const Player* const pPlayer, unsigned int pMoveAnimMaxTime)
{
	mPlayer = pPlayer;
	mPlayerShape.setRadius(15);
	mMoveAnimMaxTime = pMoveAnimMaxTime;
	mMoveAnimTimer = 0;
	mLastPlayerPosition = mPlayer->getPos();
}
const sf::CircleShape& PlayerRenderer::get() const
{
	return mPlayerShape;
}
void PlayerRenderer::link(const Renderer& pRenderer)
{
	mPlayerShape.setPosition(pRenderer.project(mPlayer->getPos()));
}
void PlayerRenderer::updateAnimation(const Renderer& pRenderer)
{
	mMoveAnimTimer--;
	float t = 1.0f - (float)mMoveAnimTimer / (float)mMoveAnimMaxTime;
	Vec2f v = { 
		quadEaseOut((float)mLastPlayerPosition.x, (float)mPlayer->getPos().x, t),
		quadEaseOut((float)mLastPlayerPosition.y, (float)mPlayer->getPos().y, t) 
	};
	mPlayerShape.setPosition(pRenderer.project(v));
}
void PlayerRenderer::triggerMoveAnimation()
{
	mMoveAnimTimer = mMoveAnimMaxTime;
	mLastPlayerPosition = mPlayer->getPos();
}
bool PlayerRenderer::doesMoveAnimPlay() const
{
	return mMoveAnimTimer > 0;
}
