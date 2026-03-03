#ifndef _POINT_H
#define _POINT_H
class Point
{
public:
	Point(double x, double y);
	double getX() const;
	double getY() const;

private:
	double x;
	double y;
};
#endif

