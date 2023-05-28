#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->Fixed_point = 0;
	return ;
}

Fixed::Fixed(Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->Fixed_point = copy.Fixed_point;
	return ;
}

Fixed &Fixed::operator= (Fixed &copy) {
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
