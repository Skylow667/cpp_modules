#include "Point.hpp"
#include <cmath>

bool bsp( Point const a, Point const b, Point const c, Point const point){
	float A = std::abs((a.getPointX().toFloat() * (b.getPointY().toFloat() - c.getPointY().toFloat()) 
				+ b.getPointX().toFloat() * (c.getPointY().toFloat() - a.getPointY().toFloat())
				+ c.getPointX().toFloat() * (a.getPointY().toFloat() - b.getPointY().toFloat())) / 2.0);

	float A1 = std::abs((point.getPointX().toFloat() * (b.getPointY().toFloat() - c.getPointY().toFloat()) 
				+ b.getPointX().toFloat() * (c.getPointY().toFloat() - point.getPointY().toFloat())
				+ c.getPointX().toFloat() * (point.getPointY().toFloat() - b.getPointY().toFloat())) / 2.0);

	float A2 = std::abs((a.getPointX().toFloat() * (point.getPointY().toFloat() - c.getPointY().toFloat()) 
				+ point.getPointX().toFloat() * (c.getPointY().toFloat() - a.getPointY().toFloat())
				+ c.getPointX().toFloat() * (a.getPointY().toFloat() - point.getPointY().toFloat())) / 2.0);

	float A3 = std::abs((a.getPointX().toFloat() * (b.getPointY().toFloat() - point.getPointY().toFloat()) 
				+ b.getPointX().toFloat() * (point.getPointY().toFloat() - a.getPointY().toFloat())
				+ point.getPointX().toFloat() * (a.getPointY().toFloat() - b.getPointY().toFloat())) / 2.0);

	if (!A1 || !A2 || !A3)
		return (false);
	return (A == A1 + A2 + A3);
}
