#include "./stack_test.hpp"

void	print_stack(Stack& st, std::string name) {
	std::cout << "[" << name << "]" << std::endl;
	std::cout << "  size: " << st.size() << std::endl;
	if (st.empty())
		std::cout << "  is empty!!!" << std::endl;
	else 
		std::cout << "  top of stack: " << st.top() << std::endl;
	std::cout << std::endl;
}

void	stack_test () {
	std::cout << "============= STACK =============" << std::endl << std::endl << std::endl;

	std::cout << "---------- CONSTRUCTOR ----------" << std::endl << std::endl;
	std::cout << "-- default constructor" << std::endl;
	Stack	stack;
	print_stack(stack, "stack");

	std::cout << "-- push (1,3,5,7,9)" << std::endl;
	for (int i = 1; i <= 9; i += 2) {
		stack.push(i);
		std::cout << "  " << i << " is added to stack." << std::endl;
	}
	print_stack(stack, "stack");

	std::cout << "-- operator=" << std::endl;
	Stack	stack2 = stack;
	print_stack(stack2, "stack2");

	std::cout << "-- operator== : " << (stack == stack2) << std::endl;
	std::cout << "-- operator!= : " << (stack != stack2) << std::endl;
	std::cout << "-- operator<  : " << (stack < stack2) << std::endl;
	std::cout << "-- operator<= : " << (stack <= stack2) << std::endl;
	std::cout << "-- operator>  : " << (stack > stack2) << std::endl;
	std::cout << "-- operator>= : " << (stack >= stack2) << std::endl;
	std::cout << std::endl;

	std::cout << "-- pop" << std::endl;
	std::cout << "  " << stack.top() << " is popped." << std::endl;
	stack.pop();
	print_stack(stack, "stack");

	std::cout << "-- operator== : " << (stack == stack2) << std::endl;
	std::cout << "-- operator!= : " << (stack != stack2) << std::endl;
	std::cout << "-- operator<  : " << (stack < stack2) << std::endl;
	std::cout << "-- operator<= : " << (stack <= stack2) << std::endl;
	std::cout << "-- operator>  : " << (stack > stack2) << std::endl;
	std::cout << "-- operator>= : " << (stack >= stack2) << std::endl;
}
