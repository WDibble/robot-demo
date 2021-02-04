#ifndef ROBOT_H
#define ROBOT_H

// record of a robots name, team number, x coordinate and y coordinate
class robot {
	double num; // robot number
	double team; // robot team
	double xValue; // robot x coordinate
	double yValue; // robot y coordinate
	double dir; // direction robot is facing (north, east, south and west = 0, 1, 2, 3 respectively)
	double steps; // number of steps robot has taken
	
public:
	// Initialize robot
	robot(const double& n, double t, double x, double y, double d, double s);

	// The name of the student
	double name() const { return num; }

	// The team number of the robot
	double teamNum() const { return team; }

	// The x coordinate of the robot
	double xCoord() const { return xValue; }

	// The y coordinate of the robot
	double yCoord() const { return yValue; }

	// The direction the robot is facing
	double direction() const { return dir; }

	// show how many steps a robot has taken
	double travel() const { return steps; }

	// move robot forward 1 step
	void forward();

	// move robot backward 1 step
	void backward();

	// turn robot direction left
	void turn_left();

	// turn robot direction right
	void turn_right();

	// destroy robot
	void destroy() const;
};

// Less-than comparison of student names
bool compare_names(const robot& x, const robot& y);

// Less-than comparison of student names
bool compare_travel(const robot& x, const robot& y);

#endif