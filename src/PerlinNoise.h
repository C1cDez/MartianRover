#pragma once

#include "Math.h"

constexpr int G_PERMUTATION_AMOUNT = 1 << 8;

class PerlinNoise
{
public:
	PerlinNoise(unsigned int pSeed);
	PerlinNoise();

	double operator()(double x, double y);

	unsigned int getSeed() const;
	void updateSeed(unsigned int pSeed);

private:
	unsigned int mSeed;
	unsigned char mPermutations[G_PERMUTATION_AMOUNT];

	Vec2d genPRGradient(int x, int y);
};

class FractalPerlinNoise
{
public:
	FractalPerlinNoise(unsigned int pSeed, unsigned int pOctaves, double pLacunarity = 2.0, double pPersistence = 0.5);
	
	double operator()(double x, double y);

private:
	PerlinNoise mBase;
	unsigned int mOctaves;
	double mLacunarity;   // How much frequency increases with each octave
	double mPersistence;   // How much each successive octave influences the result
};
