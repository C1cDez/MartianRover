#include "Math.h"

Vec2i Vec2i::operator+(const Vec2i& vec) const
{
	return { x + vec.x, y + vec.y };
}
Vec2i Vec2i::operator-(const Vec2i& vec) const
{
	return { x - vec.x, y - vec.y };
}
Vec2i Vec2i::operator*(int scale) const
{
	return { x * scale, y * scale };
}
Vec2i Vec2i::operator/(int scale) const
{
	return { x / scale, y / scale };
}
int dot(const Vec2i& a, const Vec2i& b)
{
	return a.x * b.x + a.y * b.y;
}

Vec2f Vec2f::operator+(const Vec2f& vec) const
{
	return { x + vec.x, y + vec.y };
}
Vec2f Vec2f::operator-(const Vec2f& vec) const
{
	return { x - vec.x, y - vec.y };
}
Vec2f Vec2f::operator*(int scale) const
{
	return { x * scale, y * scale };
}
Vec2f Vec2f::operator/(int scale) const
{
	return { x / scale, y / scale };
}
float dot(const Vec2f& a, const Vec2f& b)
{
	return a.x * b.x + a.y * b.y;
}


Vec2i Mat2i::operator*(const Vec2i& pVec) const
{
	return { m00 * pVec.x + m01 * pVec.y, m10 * pVec.x + m11 * pVec.y };
}
Vec2f Mat2f::operator*(const Vec2f& pVec) const
{
	return { m00 * pVec.x + m01 * pVec.y, m10 * pVec.x + m11 * pVec.y };
}


float quadEaseIn(float a, float b, float t)
{
	return (b - a) * t * t + a;
}
float quadEaseOut(float a, float b, float t)
{
	return (a - b) * (1 - t) * (1 - t) + b;
}
float quadEaseInOut(float a, float b, float t)
{
	if (t <= 0.5) return 2 * quadEaseIn(a, b, t) - a;
	else return 2 * quadEaseOut(a, b, t) - b;
}
