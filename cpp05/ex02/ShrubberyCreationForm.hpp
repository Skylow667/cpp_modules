#ifndef SRHUBBERYCREATIONFORM_HPP
# define SRHUBBERYCREATIONFORM_HPP
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	 public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm (const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
		void execute(Bureaucrat const & executor) const ;
		class FileError : public std::exception {
				const char* what() const throw();
		};
	private:
		ShrubberyCreationForm();
};

#endif
