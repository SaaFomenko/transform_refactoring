#ifndef LINE_H
#define LINE_H

class Line
{
	private:
		Point a_;
		Point b_;
	public:
		Line(Point a, Point b);
		Line(Line& other);
		Line& operator=(Line& other);
		Line(Line&& other) noexcept;
		Line operator=(Line&& other) noexcept;
        virtual ~Line();

        double size();
};

#endif