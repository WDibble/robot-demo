#include "robot.h"
#include <algorithm>

using namespace std;

// initialize student info
robot::robot(const double& n, double const t, double const x , double const y, double const d, double const s) :
	num(n), team(t), xValue(x), yValue(y), dir(d), steps(s) {}

// compare robot numbers 
bool compare_names(const robot& x, const robot& y) {
	return x.name() < y.name();
}

// compare robot travel
bool compare_travel(const robot& x, const robot& y) {
	return x.travel() > y.travel();
}

// turn robot direction left
void robot::turn_left()
{
	if (dir == 0)
		dir = 3;
	else
		dir--;
}

// turn robot direction right
void robot::turn_right()
{
	if (dir == 3)
		dir = 0;
	else
		dir++;
}

// move robot forward 1 step
void robot::forward()
{
	if (dir == 0)
		yValue++;
	if (dir == 1)
		xValue++;
	if (dir == 2)
		yValue--;
	if (dir == 3)
		xValue--;
	steps++;
}

// move robot backward 1 step
void robot::backward()
{
	if (dir == 0)
		yValue--;
	if (dir == 1)
		xValue--;
	if (dir == 2)
		yValue++;
	if (dir == 3)
		xValue++;
	steps--;
}