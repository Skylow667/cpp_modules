#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) {
	this->Fixed_point = 0;
	return ;
}

Fixed::Fixed(const int nb) {
	this->Fixed_point = nb << this->bits;
	return ;
}

Fixed::Fixed(const float nb) {
	this->Fixed_point = roundf(nb * std::pow(2.0, this->bits));
	return ;
}

Fixed::~Fixed(void) {
	return ;
}

float Fixed::toFloat(void) const {
	return (this->Fixed_point / std::pow(2.0, this->bits));
}

int Fixed::toInt(void) const {
	return (this->Fixed_point >> this->bits);
}

Fixed::Fixed(const Fixed &copy) {
	this->Fixed_point = copy.Fixed_point;
	return ;
}

std::ostream &operator<< (std::ostream &out, const Fixed &FP) {
	out << FP.toFloat();
	return (out);
}

Fixed &Fixed::operator= (const Fixed &copy) {
	this->Fixed_point = copy.Fixed_point;
	return *this;
}

bool Fixed::operator> (const Fixed &FP) const {
	return (this->Fixed_point > FP.Fixed_point);
}

bool Fixed::operator< (const Fixed &FP) const {
	return (this->Fixed_point < FP.Fixed_point);
}

bool Fixed::operator<= (const Fixed &FP) const {
	return (this->Fixed_point <= FP.Fixed_point);
}

bool Fixed::operator>= (const Fixed &FP) const {
	return (this->Fixed_point >= FP.Fixed_point);
}

bool Fixed::operator== (const Fixed &FP) const {
	return (this->Fixed_point == FP.Fixed_point);
}

bool Fixed::operator!= (const Fixed &FP) const {
	return (this->Fixed_point != FP.Fixed_point);
}

Fixed Fixed::operator+ (const Fixed &FP) const {
	return (Fixed(toFloat() + FP.toFloat()));
}

Fixed Fixed::operator- (const Fixed &FP) const {
	return (Fixed(toFloat() - FP.toFloat()));
}

Fixed Fixed::operator* (const Fixed &FP) const {
	return (Fixed(toFloat() * FP.toFloat()));
}

Fixed Fixed::operator/ (const Fixed &FP) const {
	return (Fixed(toFloat() / FP.toFloat()));
}

Fixed &Fixed::operator++(void) {
	this->Fixed_point++;
	return (*this);
}

Fixed &Fixed::operator--(void) {
	this->Fixed_point--;
	return (*this);
}

Fixed Fixed::operator++(int none) {
	(void)none;
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(int none) {
	(void)none;
	Fixed tmp = *this;
	--(*this);
	return (tmp);
}

Fixed &Fixed::min(Fixed &FP1, Fixed &FP2) {
	if (FP1 > FP2)
		return (FP2);
	else
		return (FP1);
}

const Fixed &Fixed::min(const Fixed &FP1, const Fixed &FP2) {
	if (FP1 > FP2)
		return (FP2);
	else
		return (FP1);
}

Fixed &Fixed::max(Fixed &FP1, Fixed &FP2) {
	if (FP1 > FP2)
		return (FP1);
	else
		return (FP2);
}

const Fixed &Fixed::max(const Fixed &FP1, const Fixed &FP2) {
	if (FP1 > FP2)
		return (FP1);
	else
		return (FP2);
}

int	Fixed::getRawBits(void) const {
	return (this->Fixed_point);
}

void Fixed::setRawBits(int const raw) {
	this->Fixed_point = raw;
	return ;
}
