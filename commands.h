#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <vector>

#include "robot.h"

// read all commands from 'commands.txt' and run the appropriate functions.
void readCommands();
// print to the standard output the current positions of all the robots still in the system
void show();
// list all the robots in the system, each with the total distance it has travelled. 
void travelled();
// share split_csv vector over project.
std::vector<std::string> split_csv(const std::string& s);
// share robot vector over project.
extern std::vector<robot> robots;

#endif