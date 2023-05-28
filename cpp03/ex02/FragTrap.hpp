#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap:public ClapTrap{
	 public:
		FragTrap(std::string Name);
		~FragTrap(void);
		FragTrap (const FragTrap &copy);
		FragTrap &operator=(const FragTrap&);
		void highFivesGuys(void);
	 private:
		FragTrap(void);
};



#endif
