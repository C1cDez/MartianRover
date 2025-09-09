#pragma once

#include "Math.h"

constexpr int G_CHUNK_SIZE = 16;

typedef char tiletype;
typedef char int8;

class Chunk
{
public:
	Chunk(const Vec2i& pPos);   // Only dynamically allocated object

	Vec2i getPos() const;
	Vec2i getAbsolutTilePos(const Vec2i& pInChunkPos) const;

	tiletype getTile(const Vec2i& pPos) const;
	void setTile(const Vec2i& pPos, tiletype pTile);

	int8 getHeight(const Vec2i& pPos) const;
	void setHeight(const Vec2i& pPos, int8 pHeight);

private:
	Vec2i mPos;
	tiletype mTiles[G_CHUNK_SIZE * G_CHUNK_SIZE];
	int8 mHeightMap[G_CHUNK_SIZE * G_CHUNK_SIZE];
};
