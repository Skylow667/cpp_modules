#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const int nb);
		Fixed(const float nb);
		Fixed(const Fixed &copy);
		~Fixed(void);
		Fixed &operator= (const Fixed &copy);
		bool	operator> (const Fixed &FP) const;
		bool	operator< (const Fixed &FP) const;
		bool	operator<= (const Fixed &FP) const;
		bool 	operator>= (const Fixed &FP) const;
		bool	operator== (const Fixed &FP) const;
		bool	operator!= (const Fixed &FP) const;
		Fixed operator+ (const Fixed &FP) const;
		Fixed operator- (const Fixed &FP) const;
		Fixed operator* (const Fixed &FP) const;
		Fixed operator/ (const Fixed &FP) const;
		static Fixed &min(Fixed &FP1, Fixed &FP2);
		const static Fixed &min(const Fixed &FP1, const Fixed &FP2);
		static Fixed &max(Fixed &FP1, Fixed &FP2);
		const static Fixed &max(const Fixed &FP1, const Fixed &FP2);
		Fixed &operator++ (void);
		Fixed &operator-- (void);
		Fixed operator-- (int none);
		Fixed operator++ (int none);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int	Fixed_point;
		static const int bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &FP);
#endif
