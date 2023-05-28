#ifndef BRAIN_HPP
#define BRAIN_HPP
# include <string>

class Brain
{
	 public:
		Brain();
		~Brain();
		Brain (const Brain &copy);
		Brain &operator=(const Brain&);
		void setIdeas(std::string ideas);
		void printIdeas(void);
	 private:
		std::string _ideas[100];
};

#endif
