#include "commands.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

// open stream for 'commands.txt'.
ifstream commandFile("commands.txt");

// split the robot information from a string into space separated values.
// and store these values as separate elements in a vector.
vector<string> split_csv(const string& s) {
	vector<string> v;
	auto space = find(s.cbegin(), s.cend(), ' ');
	v.emplace_back(string(s.cbegin(), space));
	while (space != s.cend()) {
		auto const start = ++space;
		space = find(start, s.cend(), ' ');
		v.emplace_back(string(start, space));
	}
	return v;
}
// read all commands from 'commands.txt' and run the appropriate functions.
void readCommands() {
	// initialise string to temporarily store command data.
	string str;
	while (getline(commandFile, str)) {
		auto v = split_csv(str);
		// if the command is 'show' run show().
		if (v[0] == "show")
			show();
		// if the command is 'travelled' run travelled().
		if (v[0] == "travelled")
			travelled();
		// if the command is 'within', out the number of robots that have
		// moved within the specified number range.
		if (v[0] == "within") {
			auto x = 0;
			for (auto& r : robots)
				if (r.travel() <= stod(v[1])) 
					x++;
			cout << x << "\n";
		}
		// if the command is 'turnleft' run turn_left() on the specified robot.
		if (v[0] == "turnleft")
			for (auto& r : robots) 
				if (r.name() == stod(v[1])) 
					r.turn_left();
		
		// if the command is 'turnright' run turn_right() on the specified robot.
		if (v[0] == "turnright")
			for (auto& r : robots)
				if (r.name() == stod(v[1]))
					r.turn_right();
		
		// if the command is 'move' run forward() on the specified robot.
		if (v[0] == "move") {
			for (auto& r : robots) {
				if (r.name() == stod(v[1])) {
					r.forward();
					for (auto& n : robots) {
						// if the robot has been moved into a space occupied by an enemy robot, destroy the enemy.
						if (r.xCoord() == n.xCoord() && r.yCoord() == n.yCoord() && r.name() != n.name()) {
							if (n.teamNum() != r.teamNum()) {
								int x;
								for (auto i = 0; i < robots.size(); i++) {
									if (n.name() == robots[i].name()) {
										robots.erase(robots.begin() + i);
									}
								}
							}
							// if the robot moves to a space occupied by a member of the same team, move backward.
							else {
								r.backward();
							}
						}
					}
				}
			}
		}
	}
}