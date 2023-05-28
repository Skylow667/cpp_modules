#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
	:x(0),
	y(0) {
}

Point::Point(const float x, const float y)
	:x(x),
	y(y) {

}

Point::~Point(){
}

Point::Point(const Point &copy){
	*this = copy;
}

Point & Point::operator=(const Point &copy){
	if (&copy != this) {
		this->~Point();
		new(this) Point(copy.getPointX().toFloat(), copy.getPointY().toFloat());
	}
	return (*this);
}

Fixed Point::getPointX(void) const {
	return (x);
}

Fixed Point::getPointY(void) const {
	return (y);
}
