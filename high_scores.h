#pragma once
#include <iostream>
#include <fstream>
#include <string>

std::string ask_name();

int get_score (std::string file_name) ; 

int write_score (std::string file_name, std::string user_name, int score)  ; 

int print_score (std::string file_name);