// robotWars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>

#include "robot.h"
#include "commands.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// open stream for 'start.txt'.
ifstream infile("start.txt");

// initialise vector to store the robots in.
vector<robot> robots;

// print to the standard output the current positions of all the robots still in the system
void show() {
	sort(robots.begin(), robots.end(), compare_names);
	for (const auto& r : robots) {
		cout << r.name() << " " << r.teamNum() << " " << r.xCoord() << " " << r.yCoord() << " " << "\n";
	}
}

// list all the robots in the system, each with the total distance it has travelled. 
void travelled() {
	sort(robots.begin(), robots.end(), compare_travel);
	for (const auto& r : robots) {
		cout << r.name() << " " << r.travel() << "\n";
	}
}

int main()
{
	// initialise string to temporarily store robot data.
	string str;

	// read from 'start.txt' and initialise new robots using this information.
	while (getline(infile, str)) {
		auto v = split_csv(str);
		robots.emplace_back(robot(stod(v[0]), stod(v[1]), stod(v[2]), stod(v[3]), 0, 0));
	}

	// run command reader function.
	readCommands();

}
