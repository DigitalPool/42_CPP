/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:58:54 by mac               #+#    #+#             */
/*   Updated: 2025/02/24 22:37:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// class ShrubberyCreationForm : public AForm{
// 	private:
// 		const std::string _target;
// 		ShrubberyCreationForm();
// 	public:
// 		ShrubberyCreationForm(std::string target);
// 		ShrubberyCreationForm(const ShrubberyCreationForm &other);
// 		virtual ~ShrubberyCreationForm();

// 		ShrubberyCreationForm &operator=(ShrubberyCreationForm &ShrubberyCreationForm);

// 		std::string getTarget() const;
// 		void execute (Bureaucrat const & executor) const;
// };

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("ShrubberyCreationForm", false, 145, 137), _target("default") {
	std::cout << "default constructor for ShrubberyCreationForm called" << std::endl;
}
// AForm(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade);
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {
	std::cout << "default constructor for ShrubberyCreationForm called for target " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
		: AForm ("ShrubberyCreationForm", false, 145, 137), _target(other.getTarget()) {
	std::cout << "Constructor for ShrubberyCreationForm called for target " << other.getTarget() << std::endl;
	if (this != &other)
		*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Destructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &src) {
	//all the attributes of this class are constant so we cannot assign anything
	if (this == &src)
		return (*this);
	return (*this);
}

std::string ShrubberyCreationForm::getTarget () const {
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw (AForm::UnsignedFormException());
	else if ( executor.getGrade() > this->getToExecuteGrade())
		throw (AForm::GradeTooLowException());
	else
	{
		std::ofstream outfile (this->getTarget() + "_shrubbery");
		if (outfile.is_open())
		{
			outfile <<"											 ." << std::endl;
			outfile <<"										  .         ;" << std::endl;
			outfile <<"			 .              .              ;%     ;;" << std::endl;
			outfile <<"			   ,           ,                :;%  %;" << std::endl;
			outfile <<"				:         ;                   :;%;'     .," << std::endl;
			outfile <<"	   ,.        %;     %;            ;        %;'    ,;" << std::endl;
			outfile <<"		 ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
			outfile <<"		  %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
			outfile <<"		   ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
			outfile <<"			`%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
			outfile <<"			 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
			outfile <<"				`:%;.  :;bd%;          %;@%;'" << std::endl;
			outfile <<"				  `@%:.  :;%.         ;@@%;'" << std::endl;
			outfile <<"					`@%.  `;@%.      ;@@%;" << std::endl;
			outfile <<"					  `@%%. `@%%    ;@@%;" << std::endl;
			outfile <<"						;@%. :@%%  %@@%;" << std::endl;
			outfile <<"						  %@bd%%%bd%%:;" << std::endl;
			outfile <<"							#@%%%%%:;;" << std::endl;
			outfile <<"							%@@%%%::;" << std::endl;
			outfile <<"							%@@@%(o);  . '" << std::endl;
			outfile <<"							%@@@o%;:(.,'" << std::endl;
			outfile <<"						`.. %@@@o%::;" << std::endl;
			outfile <<"						   `)@@@o%::;" << std::endl;
			outfile <<"							%@@(o)::;" << std::endl;
			outfile <<"						   .%@@@@%::;" << std::endl;
			outfile <<"						   ;%@@@@%::;." << std::endl;
			outfile <<"						  ;%@@@@%%:;;;." << std::endl;
			outfile <<"					  ...;%@@@@@%%:;;;;,..    " << std::endl;
			outfile.close();
			std::cout << " File created successfully" <<std::endl;
		}
		else
			std::cout << "Failed to open file" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *shrubberyCreationForm){
	out << "ShrubberyCreationForm Target: "  << shrubberyCreationForm->getTarget() << std::endl;
	return out;
}
