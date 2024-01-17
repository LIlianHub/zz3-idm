/**
 * @file main.ccp
 * 
 * @brief This file contains the main function of the program.
 *
 * The main function reads the command-line arguments and calls the appropriate functions based on the provided arguments.
 * It expects the first argument to be the question number and, in the case of question 5, it also expects a second argument
 * which is the file input for question 5.
 *
 * Usage: ./TP5_BALLEJOS <question_number> <file_input_for_question_5>
 */

#include <iostream>
#include <string>

#include "questionN.hpp"

const std::string ERROR_MESSAGE = "Usage : ./TP5_BALLEJOS <question_number> <file_input_for_question_5>";

/**
 * The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * 
 * @return int The exit status of the program.
 */
int main(int argc, const char *argv[])
{

    if (argc < 2 || argc > 3)
    {
        std::cerr << ERROR_MESSAGE << std::endl;
    }
    else
    {
        switch (atoi(argv[1]))
        {
        case 2:
            question2();
            break;
        case 3:
            question3();
            break;
        case 4:
            question4();
            break;
        case 5:
            if (argc == 3)
                question5(argv[2]);
            else
                std::cerr << ERROR_MESSAGE << std::endl;
            break;
        case 6:
            question6();
            break;
        default:
            std::cerr << ERROR_MESSAGE << std::endl;
            break;
        }
    }

    return 0;
}