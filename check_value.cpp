#include "check_value.h"
#include "random_value.h"   // (с ним не получилось сделать связь, перенесла rand функцию напрямую сюда)

#include <iostream>

#include <cstdlib>
#include <ctime>
int check_value (int max) {

	int target = 0;

	target = rand_value(max);  //  (max)

	int current_value = 0;

	int score = 0;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;
		score++;

		if (target < current_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (target > current_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);

	return score;
}