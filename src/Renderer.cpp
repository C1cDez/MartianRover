#include "Renderer.h"

#include "Player.h"


sf::Vector2f Renderer::project(const Vec2i& pVec) const
{
	Vec2i screen = mProjectionMatrix * pVec;
	return { static_cast<float>(screen.x), static_cast<float>(screen.y) };
}


PlayerRenderer::PlayerRenderer(const Player* const pPlayer)
{
	mPlayer = pPlayer;
	mPlayerShape.setRadius(15);
}
const sf::CircleShape& PlayerRenderer::get() const
{
	return mPlayerShape;
}
void PlayerRenderer::link(const Renderer& pRenderer)
{
	mPlayerShape.setPosition(pRenderer.project(mPlayer->getPos()));
}
