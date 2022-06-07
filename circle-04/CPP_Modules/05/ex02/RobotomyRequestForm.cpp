#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
	: Form(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &scf) 
	: Form(scf) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &scf) {
	return *(dynamic_cast<RobotomyRequestForm *>(&(Form::operator=(scf))));
}

void				RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	executable(executor);

	std::srand(time(NULL));
	std::cout << "some drilling noises..." << std::endl << std::endl;
	std::cout << "<" << executor.getName() << "> ";
	if (std::rand() % 2)
		std::cout << "has been robotomized successfully 50\% of the time" << std::endl;
	else
		std::cout << "failed to robotomize" << std::endl;
}
