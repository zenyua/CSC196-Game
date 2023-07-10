#pragma once

namespace kiko {
	class Vector2 {
	public:
		float x, y;
	public:
		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float v) : x{ v }, y{ v } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}
		//Vector2(unsigned int x, unsigned int y) : x{ (float)x }, y {(float) y} {}
		// ^ not supposed to be commented? change from unsigned int to int
		//Vector2 Add(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
		Vector2 operator + (const Vector2& v) const { return Vector2(x + v.x, y + v.y); }		
		Vector2 operator - (const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
		Vector2 operator / (const Vector2& v) const { return Vector2(x / v.x, y / v.y); }
		Vector2 operator * (const Vector2& v) const { return Vector2(x * v.x, y * v.y); }
		
		Vector2 operator + (float s) const { return Vector2(x + s, y + 2); }
		Vector2 operator - (float s) const { return Vector2(x - s, y - 2); }
		Vector2 operator / (float s) const { return Vector2(x / s, y / 2); }
		Vector2 operator * (float s) const { return Vector2(x * s, y * 2); }

		Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; }
	};

	using vec2 = Vector2;
}