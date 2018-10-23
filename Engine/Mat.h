#pragma once

#include <cmath>
#include "Vec2.h"

// 2x2 matrix to rotate stuff or whatever.
template<typename T>
class Mat_
{
public:
	// Gives a rotation matrix based on the given angle.
	static Mat_ Rotation( float angle )
	{
		// [ cos,-sin ]  [ a,b ]
		// [ sin, cos ]  [ c,d ]
		return( Mat_( cos( angle ),-sin( angle ),
			sin( angle ),cos( angle ) ) );
	}
	Vec2_<T> operator*( const Vec2_<T> rhs ) const
	{
		Vec2_<T> start = { T( 0 ),T( 0 ) };
		start.x = data[0][0] * rhs.x + data[0][1] * rhs.y;
		start.y = data[1][0] * rhs.x + data[1][1] * rhs.y;
		// start.x = std::abs( start.x );
		// start.y = std::abs( start.y );
		return( start );
	}
private:
	Mat_( T a,T b,T c,T d )
	{
		data[0][0] = a;
		data[0][1] = b;
		data[1][0] = c;
		data[1][1] = d;
	}
private:
	static constexpr int size = 2;
	float data[size][size];
};

typedef Mat_<float> Mat;
typedef Mat_<int> MatI;