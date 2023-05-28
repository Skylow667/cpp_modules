#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	 public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point (const Point &copy);
		Point &operator=(const Point&);
		Fixed getPointX(void) const;
		Fixed getPointY(void) const;

	 private:
		const Fixed x;
		const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif
