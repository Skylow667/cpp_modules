#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
	 public:
		FragTrap(std::string Name);
		~FragTrap(void);
		FragTrap (const FragTrap &copy);
		FragTrap &operator=(const FragTrap&);
		void attack(const std::string &target);
		void highFivesGuys(void);
	 protected:
		FragTrap(void);
};



#endif
