#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->Fixed_point = 0;
	return ;
}

Fixed::Fixed(const int nb) {
	std::cout << "Int constructor called" << std::endl;
	this->Fixed_point = nb << this->bits;
	return ;
}

Fixed::Fixed(const float nb) {
	std::cout << "Float constructor called" << std::endl;
	this->Fixed_point = roundf(nb * std::pow(2.0, this->bits));
	return ;
}

float Fixed::toFloat(void) const {
	return (this->Fixed_point / std::pow(2.0, this->bits));
}

int Fixed::toInt(void) const {
	return (this->Fixed_point >> this->bits);
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->Fixed_point = copy.Fixed_point;
	return ;
}

std::ostream &operator<< (std::ostream &out, const Fixed &FP) {
	out << FP.toFloat();
	return (out);
}

Fixed &Fixed::operator= (const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->Fixed_point = copy.Fixed_point;
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->Fixed_point);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits function called" << std::endl;
	this->Fixed_point = raw;
	return ;
}
