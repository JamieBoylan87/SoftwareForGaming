#pragma once

#include <iostream>

class Point {

private:
	int x, y;

public:
	Point();
	Point(int x, int y);
	int getX();
	int getY();
	void setPoint(int x, int y);
};

Point::Point(int pos_x, int pos_y)
{
	x = pos_x;
	y = pos_y;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}