#include "random_value.h"
#include <iostream>

#include <cstdlib>
#include <ctime>

int rand_value(int max) {

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max;
//	std::cout << random_value << std::endl;

	return random_value;
}