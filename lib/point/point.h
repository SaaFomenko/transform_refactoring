#ifndef POINT_H
#define POINT_H

#include <vector>

enum ord
{
	x,
	y,
	z,
};

class Point
{
	private:
		double x_;
		double y_;
		double z_;
	public:
		Point(const double x = 0, const double y = 0, const double z = 0);
		Point(std::vector<double> p);
		Point(Point& other);
		Point& operator=(Point& other);
		Point(Point&& other) noexcept;
		Point operator=(Point&& other) noexcept;
		virtual ~Point();

		void set(const double x = 0, const double y = 0, const double z = 0, const bool to_null = false);
		std::vector<double> get();
};

#endif