#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed &copy);
		Fixed &operator= (Fixed &copy);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int	Fixed_point;
		static const int bits = 8;
};
#endif
