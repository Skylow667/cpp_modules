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
