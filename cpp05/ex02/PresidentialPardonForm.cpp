#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target):Form(target, 25, 5){
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):Form(copy){
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	if (&copy != this)
	{
		this->~PresidentialPardonForm();
		new(this) PresidentialPardonForm(copy.getName());
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getSigned() == false || executor.getGrade() > this->getGradeExe())
		throw (PresidentialPardonForm::ExecutionException());
	std::cout << this->getName() << " was forgiven by Zaphod Beeblebrox!" << std::endl;
}
