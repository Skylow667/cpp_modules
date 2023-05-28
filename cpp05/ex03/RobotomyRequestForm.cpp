#include "RobotomyRequestForm.hpp"
#include "Form.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form(target, 72, 45){
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):Form(copy){
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	if (&copy != this)
	{
		this->~RobotomyRequestForm();
		new (this) RobotomyRequestForm(copy.getName());
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	static int rand = 0;

	if (this->getSigned() == false || executor.getGrade() > this->getGradeExe()) 
		throw (RobotomyRequestForm::ExecutionException());
	if (rand % 2 == 0)
		std::cout << this->getName() << " has been robotomized!" << std::endl;
	else
		std::cout << this->getName() << ": the robotization operation failed!" << std::endl;
	rand++;
}
