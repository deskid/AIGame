#pragma once
#include <math.h>
class Vector2D
{
private:
	float x,y;
public:
	Vector2D(float _x,float _y):x(_x),y(_y){};

	float getX(){return x;}
	float getY(){return y;}

	void setX(float _x){ x = _x;}
	void setY(float _y){ y = _y;}

	float length(){return sqrt( x*x + y*y );}

	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(x + v2.x,y + v2.y);
	}
	Vector2D& operator+=(const Vector2D v2)
	{
		x += v2.x;
		y += v2.y;

		return *this;
	}
	Vector2D operator*(float scalar)
	{
		return Vector2D(x*scalar,y*scalar);
	}
	Vector2D& operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2D operator-(const Vector2D& v2) const
	{
		return Vector2D(x - v2.x,y - v2.y);
	}
	Vector2D& operator-=(const Vector2D v2)
	{
		x -= v2.x;
		y -= v2.y;

		return *this;
	}
	Vector2D operator/(float scalar)
	{
		return Vector2D(x / scalar, y / scalar);
	}
	Vector2D& operator/=(float scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}
	void normalize()
	{
		float len = length();
		if ( len > 0)
		{
			(*this) *= 1 / len;
		}
	}




	~Vector2D(void){};
};

