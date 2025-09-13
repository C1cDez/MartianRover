#pragma once


struct Vec2i
{
	int x, y;

	Vec2i operator+(const Vec2i&) const;
	Vec2i operator-(const Vec2i&) const;
	Vec2i operator*(int) const;
	Vec2i operator/(int) const;
};
int dot(const Vec2i&, const Vec2i&);

struct Vec2f
{
	float x, y;

	Vec2f operator+(const Vec2f&) const;
	Vec2f operator-(const Vec2f&) const;
	Vec2f operator*(int) const;
	Vec2f operator/(int) const;
};
float dot(const Vec2f&, const Vec2f&);


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
