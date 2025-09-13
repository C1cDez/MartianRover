#include "PerlinNoise.h"

#include <cmath>
#include <random>

static double cint(double a, double b, double t)
{
	return t * t * (b - a) * (3 - 2 * t) + a;
}

constexpr unsigned int S_UINT_SIZE_ = 8 * sizeof(unsigned int);
constexpr unsigned int S_UINT_SIZE_2 = S_UINT_SIZE_ / 2;
static unsigned int hash(int x, int y)
{
	unsigned int a = x, b = y;
	a *= 3284157443;
	b ^= a << S_UINT_SIZE_2 | a >> S_UINT_SIZE_ - S_UINT_SIZE_2;
	b *= 1911520717;
	a ^= b << S_UINT_SIZE_2 | b >> S_UINT_SIZE_ - S_UINT_SIZE_2;
	a *= 2048419325;
	return a;
}


PerlinNoise::PerlinNoise(unsigned int pSeed)
{
	updateSeed(pSeed);
}
PerlinNoise::PerlinNoise()
{
	mSeed = 0;
	memset(mPermutations, 0, G_PERMUTATION_AMOUNT);
}
unsigned int PerlinNoise::getSeed() const
{
	return mSeed;
}
void PerlinNoise::updateSeed(unsigned int pSeed)
{
	mSeed = pSeed;
	std::mt19937 rand{ mSeed };
	std::uniform_int_distribution<int> bytes{ 0, 0xff };
	for (int i = 0; i < G_PERMUTATION_AMOUNT; i++) mPermutations[i] = bytes(rand) & 0xff;
}

Vec2f PerlinNoise::genPRGradient(int x, int y)
{
	int h = hash(x, y) & 0xff;
	int v = mPermutations[mPermutations[h]];
	double t = (double)v / 128 * 3.14159265358;
	return { cosf(t), sinf(t) };
}

double PerlinNoise::operator()(double x, double y)
{
	int x0 = (int)x, y0 = (int)y;
	double lx = x - x0, ly = y - y0;

	Vec2f tlv = genPRGradient(x0, y0);
	Vec2f trv = genPRGradient(x0 + 1, y0);
	Vec2f blv = genPRGradient(x0, y0 + 1);
	Vec2f brv = genPRGradient(x0 + 1, y0 + 1);

	Vec2f tld{ lx, ly };
	Vec2f trd{ lx - 1, ly };
	Vec2f bld{ lx, ly - 1 };
	Vec2f brd{ lx - 1, ly - 1 };

	double tlg = dot(tlv, tld);
	double trg = dot(trv, trd);
	double blg = dot(blv, bld);
	double brg = dot(brv, brd);

	double ti = cint(tlg, trg, lx);
	double bi = cint(blg, brg, lx);

	double v = cint(ti, bi, ly);

	return v;
}


FractalPerlinNoise::FractalPerlinNoise(unsigned int pSeed, unsigned int pOctaves, double pLacunarity, double pPersistence)
{
	mBase.updateSeed(pSeed);
	mOctaves = pOctaves;
	mLacunarity = pLacunarity;
	mPersistence = pPersistence;
}
double FractalPerlinNoise::operator()(double x, double y)
{
	double value = 0.0;
	double scale = 1.0;
	for (int i = 0; i < (int)mOctaves; i++)
	{
		value += mBase(x, y) * scale;
		x *= mLacunarity;
		y *= mLacunarity;
		scale *= mPersistence;
	}
	return value;
}
