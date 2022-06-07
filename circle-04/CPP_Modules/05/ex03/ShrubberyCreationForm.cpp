#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
	: Form(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) 
	: Form(scf) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf) {
	return *(dynamic_cast<ShrubberyCreationForm *>(&(Form::operator=(scf))));
}

void					ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	executable(executor);

	std::ofstream	out("<" + Form::getName() + ">_shrubbery");	
	std::string		shrubbery =	"                 .o00o\n"
								"               o000000oo\n"
								"              00000000000o\n"
								"             00000000000000\n"
								"          oooooo  00000000  o88o\n"
								"       ooOOOOOOOoo  ```''  888888\n"
								"     OOOOOOOOOOOO'.qQQQQq. `8888'\n"
								"    oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
								"    OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
								"     OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
								"       OOOOOOOOO `QQQQQQ/ /QQ'\n"
								"         OO:F_P:O `QQQ/  /Q'\n"
								"            \\. \\ |  // |\n"
								"            d\\ \\\\|_////\n"
								"            qP| \\ _' `|Ob\n"
								"               \\  / \\  \\Op\n"
								"               |  | O| |\n"
								"       _       /\\. \\_/ /\n"
								"        `---__/|_\\   //|  __\n"
								"              `-'  `-'`-'-'\n";
	out << shrubbery;
	std::cout << "Shrubbery created." << std::endl;
}
