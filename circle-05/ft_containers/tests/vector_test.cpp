#include "./vector_test.hpp"

void	print_vec (Vector vec, std::string name) {
	std::cout << "[" << name << "]" << std::endl;
	std::cout << "  size: " << vec.size() << std::endl;
	std::cout << "  capacity: " << vec.capacity() << std::endl;
	std::cout << "  max_size: " << vec.max_size() << std::endl;
	if (vec.empty())
		std::cout << "  is empty!!!" << std::endl;
	else {
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << "  " << "[" << i << "] => " << vec[i] << std::endl;
	}
	std::cout << std::endl;
}

void	vector_test () {
	std::cout << "============= VECTOR =============" << std::endl << std::endl << std::endl;

	std::cout << "---------- CONSTRUCTORS ----------" << std::endl << std::endl;
	std::cout << "-- default constructor" << std::endl;
	Vector	vec;
	print_vec(vec, "vec");

	std::cout << " push back 1, 2, 3, 4, 5" << std::endl;
	for (T_VEC i = 1; i <= 5; i++)
	{
		vec.push_back(i);
		print_vec(vec, "vec");
	}
	print_vec(vec, "vec");

	std::cout << "-- fill constructor (10, 1)" << std::endl;
	Vector	vec2(10, 1);
	print_vec(vec2, "vec2");

	std::cout << "change the values of vec2[3] ~ vec2[5] to 3 ~ 5" << std::endl << std::endl;
	for (T_VEC i = 3; i < 6; i++)
		vec2[i] = i;
	std::cout << "-- range constructor (vec2.begin(), vec2.end() - 3)" << std::endl;
	Vector	vec3(vec2.begin(), vec2.end() - 3);
	print_vec(vec3, "vec3");

	std::cout << "-- copy constructor (copy of vec3)" << std::endl;
	Vector	vec4(vec3);
	print_vec(vec4, "vec4");

	std::cout << "-- assignment operator overload (copy of vec2)" << std::endl;
	Vector	vec5 = vec2;
	print_vec(vec5, "vec5");

	std::cout << "------------ CAPACITY ------------" << std::endl;
	print_vec(vec, "vec");
	std::cout << "-- resize to less than current size: " << std::endl;
	vec.resize(3);
	print_vec(vec, "vec");
	std::cout << "-- resize to greater than current size: " << std::endl;
	vec.resize(10);
	print_vec(vec, "vec");

	std::cout << "------------- ACCESS -------------" << std::endl;
	std::cout << "-- operator[] (invalid index): " << vec[17] << std::endl << std::endl;

	std::cout << "-- operator[] (valid index): " << vec[4] << std::endl << std::endl;

	std::cout << "-- at (invalid index): ";
	try {
		std::cout << vec.at(17) << std::endl << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "-- at (valid index): " << vec.at(4) << std::endl << std::endl;

	std::cout << "-- front(): " << vec.front() << std::endl;
	std::cout << "-- back():  " << vec.back() << std::endl;

	std::cout << "----------- MODIFIERS ------------" << std::endl;
	std::cout << "-- range assign (vec2.begin, vec2.end)" << std::endl;
	vec.assign(vec2.begin(), vec2.end());
	print_vec(vec, "vec");

	std::cout << "-- fill assign (5, 10)" << std::endl;
	vec.assign(5, 10);
	print_vec(vec, "vec");

	std::cout << "-- after pop_back" << std::endl;
	vec.pop_back();
	print_vec(vec, "vec");

	std::cout << "-- insert (one)" << std::endl;
	vec.insert(vec.begin(), 0);
	print_vec(vec, "vec");

	std::cout << "-- insert (many)" << std::endl;
	vec.insert(vec.begin() + 1, 5, 1);
	print_vec(vec, "vec");

	std::cout << "-- insert (range)" << std::endl;
	vec.insert(vec.begin(), vec4.begin(), vec4.begin() + 2);
	print_vec(vec, "vec");

	std::cout << "-- erase (one)" << std::endl;
	vec.erase(vec.begin() + 5);
	print_vec(vec, "vec");

	std::cout << "-- erase (range)" << std::endl;
	vec.erase(vec.begin(), vec.begin() + 4);
	print_vec(vec, "vec");

	std::cout << "-- vectors [vec] and [vec2] before swap:" << std::endl;
	print_vec(vec, "vec");
	print_vec(vec2, "vec2");
	vec.swap(vec2);
	std::cout << "-- vectors [vec] and [vec2] after swap:" << std::endl;
	print_vec(vec, "vec");
	print_vec(vec2, "vec2");

	std::cout << "-- clear" << std::endl;
	vec.clear();
	print_vec(vec, "vec");


	std::cout << "----- NON-MEMBER OVERLOADS ------" << std::endl;
	print_vec(vec, "vec");
	print_vec(vec2, "vec2");
	print_vec(vec3, "vec3");
	print_vec(vec4, "vec4");

	std::cout << "-- operator== (vec, vec2): " << (vec == vec2) << std::endl;
	std::cout << "-- operator!= (vec3, vec4): " << (vec3 != vec4) << std::endl;
	std::cout << "-- operator< (vec, vec2): " << (vec < vec2) << std::endl;
	std::cout << "-- operator> (vec2, vec3): " << (vec2 > vec3) << std::endl;

	NAMESPACE::swap(vec, vec2);
	print_vec(vec, "vec");
	print_vec(vec2, "vec2");
}
