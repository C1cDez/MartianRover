#include "World.h"

static bool isValidInChunkPos(const Vec2i& p)
{
	return (p.x >= 0 && p.x < G_CHUNK_SIZE) && (p.y >= 0 && p.y < G_CHUNK_SIZE);
}

Chunk::Chunk()
{
	mPos = { 0, 0 };
}
void Chunk::setPos(const Vec2i& pPos)
{
	mPos = pPos;
}
Vec2i Chunk::getPos() const
{
	return mPos;
}
Vec2i Chunk::getAbsolutTilePos(const Vec2i& pInChunkPos) const
{
	return { mPos.x * G_CHUNK_SIZE + pInChunkPos.x, mPos.y * G_CHUNK_SIZE + pInChunkPos.y };
}
tiletype Chunk::getTile(const Vec2i& pPos) const
{
	if (isValidInChunkPos(pPos)) return mTiles[pPos.y * G_CHUNK_SIZE + pPos.x];
	else return { ~0 };
}
void Chunk::setTile(const Vec2i& pPos, tiletype pTile)
{
	if (isValidInChunkPos(pPos)) mTiles[pPos.y * G_CHUNK_SIZE + pPos.x] = pTile;
}
