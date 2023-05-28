#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	 public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm (const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm&);
		void execute(Bureaucrat const & executor) const ;
	private:
		RobotomyRequestForm();
};

#endif
