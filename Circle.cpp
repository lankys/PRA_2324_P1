#include "Circle.h"
#include <ostream>
#include <iostream>
#include <cmath>

Circle::Circle() :Shape() {
    center.x = 0;
    center.y = 0;
    radius = 1;
}

Circle::Circle(std::string color, Point2D center, double radius) :Shape(color) {
    this->center = center;
    this->radius = radius;
}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}


double Circle::perimeter() const {
    return 2 * 3.14 * radius;
}

double Circle::area() const {
    return pow(radius, 2) * 3.14;
    }


void Circle::translate(double X, double Y) {
    center.x += X;
    center.y += Y;
}

std::ostream& operator<<(std::ostream& out, const Circle& ci) {
    return out << "color: " << ci.color << "\n" << "centro: " << ci.center << "\n" << "radio: " << ci.radius << "\n";
}

void Circle::print() const {
    std::cout << *this;
}
