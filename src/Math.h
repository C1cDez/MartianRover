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


struct Mat2i
{
	int m00, m01, m10, m11;
	Vec2i operator*(const Vec2i&) const;
};
struct Mat2f
{
	float m00, m01, m10, m11;
	Vec2f operator*(const Vec2f&) const;
};


float quadEaseIn(float a, float b, float t);
float quadEaseOut(float a, float b, float t);
float quadEaseInOut(float a, float b, float t);
