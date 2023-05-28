#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"
#include <fstream>

const char *ShrubberyCreationForm::FileError::what() const throw() {
	return ("The file cannot be create or open.");
}

ShrubberyCreationForm::ShrubberyCreationForm():Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form(target, 145, 137){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):Form(copy){
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	if (&copy != this)
	{
		this->~ShrubberyCreationForm();
		new (this)ShrubberyCreationForm(copy.getName());
	}
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == false || executor.getGrade() > this->getGradeExe())
		throw (ShrubberyCreationForm::ExecutionException());
	std::fstream out;

	out.open((this->getName() + "_shrubbery").c_str(), std::ios::out);
	if (!out)
		throw (ShrubberyCreationForm::FileError());
	out << "   ,@@@@@@@, \
       ,,,.   ,@@@@@@/@@,  .oo8888o. \
    ,&\%\%&%&&%,@@@@@/@@@@@@,8888\\88/8o \
   ,%&\%&&%&&%,@@@\\@@@/@@@88\\88888/88' \
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' \
   %&&%/ %&\%\%&&@@\\ V /@@' `88\\8 `/88' \
   `&%\\ ` /%&'    |.|        \\ '|8' \
       |o|        | |         | | \
       |.|        | |         | | \
    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/";
}
