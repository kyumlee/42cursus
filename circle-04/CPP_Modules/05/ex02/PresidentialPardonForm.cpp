#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
	: Form(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &scf) 
	: Form(scf) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &scf) {
	return *(dynamic_cast<PresidentialPardonForm *>(&(Form::operator=(scf))));
}

void					PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	executable(executor);

	std::cout << "<" << executor.getName() << "> has been pardoned by Zafod Beeblebrox." << std::endl;
}
