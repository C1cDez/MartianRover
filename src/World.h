#pragma once

#include "Math.h"

constexpr int G_CHUNK_SIZE = 16;

typedef char tiletype;

class Chunk
{
public:
	Chunk();

	void setPos(const Vec2i& pPos);
	Vec2i getPos() const;

	Vec2i getAbsolutTilePos(const Vec2i& pInChunkPos) const;

	tiletype getTile(const Vec2i& pPos) const;
	void setTile(const Vec2i& pPos, tiletype pTile);

private:
	Vec2i mPos;
	tiletype mTiles[G_CHUNK_SIZE * G_CHUNK_SIZE];
};
