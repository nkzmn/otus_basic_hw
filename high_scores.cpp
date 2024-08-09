
#include "high_scores.h"

#include <iostream>
#include <fstream>
#include <string>
;

using namespace std;

string ask_name() {

	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;
return user_name;
}

int get_score (std::string file_name) {

	// Get the last high score
	std::cout << "Enter your high score:" << std::endl;
	int attempts_count = 0;
	std::cin >> attempts_count;
	if (std::cin.fail()) {
		std::cout << "Bad value!" << std::endl;
		return -1;
	}
return attempts_count;
}

int write_score (std::string file_name,std::string user_name, int score) {

	// Write new high score to the records table
	{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{file_name, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << file_name << "!" << std::endl;
			return -1;
		}

		// Append new results to the table:
		out_file << user_name << ' ';
		out_file << score;
		out_file << std::endl;
	} // end of score here just to mark end of the logic block of code

	return 0;
}


int print_score (std::string file_name) {
	// Read the high score file and print all results
	{
		std::ifstream in_file{file_name};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << file_name << "!" << std::endl;
			return -1;
		}

		std::cout << "High scores table:" << std::endl;

		std::string user_name;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> user_name;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << user_name << '\t' << high_score << std::endl;
		}
	}

	return true;
}