#include "graphic.h"
#include <iostream>
using namespace yao_graph;

Graphic::Graphic(){

}

Graphic::~Graphic(){
}

Point::Point()
    : Point(0, 0){
}

Point::Point(int x, int y)
    : x(x)
    , y(y){
}

Point::Point(const Point& other)
    : Point(other.x, other.y){
}

Point& Point::operator=(const Point& other){
    if(this != &other){
        this->x = x;
        this->y = y;
    }
    return *this;
}

std::ostream& Point::stream_write(std::ostream& os) const{
    return os;
}

Point::~Point(){

}

Circle::Circle()
    : Circle(Point(0, 0), 0){
}

Circle::Circle(const Point& point, int dim)
    : center(point)
    , dim(dim){
}

Circle& Circle::operator=(const Circle& other){
    if(this != &other){
        this->center = other.center;
        this->dim = other.dim;
    }
    return *this;
}

Circle::Circle(const Circle& other)
    : Circle(other.center, other.dim){
}

Circle::~Circle(){

}


std::ostream& Circle::stream_write(std::ostream& os) const{
    return os;
}
