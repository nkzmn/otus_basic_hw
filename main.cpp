#include "check_value.h"
#include "high_scores.h"

#include <iostream>

int main()
{
    const std::string file_name = "high_scores.txt";
    int max{100};
    
    auto user_name = ask_name();
    int score = check_value(max);  //   check_value(max)

    write_score(file_name, user_name, score);
    print_score(file_name);
    
    return 0;
}