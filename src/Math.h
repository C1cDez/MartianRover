#pragma once

struct Vec2i
{
	int x, y;
};
struct Vec3i
{
	int x, y, z;
};

struct Vec2d
{
	double x, y;
};
struct Vec3d
{
	double x, y, z;
};

struct Vec2f
{
	float x, y;
};
struct Vec3f
{
	float x, y, z;
};


static float quadEaseIn(float a, float b, float t)
{
	return (b - a) * t * t + a;
}
static float quadEaseOut(float a, float b, float t)
{
	return (a - b) * (1 - t) * (1 - t) + b;
}
static float quadEaseInOut(float a, float b, float t)
{
	if (t <= 0.5) return quadEaseIn(a, b, t);
	else return quadEaseOut(a, b, t);
}
