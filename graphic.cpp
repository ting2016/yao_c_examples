#include "graphic.h"
#include <iostream>
#include <string>
using namespace yao::graph;

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

void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

std::ostream& Point::stream_write(std::ostream& os) const{
    return os << "x:" << x << ", y:" << y;
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
    return os << "Center" << center << ", Dimeter:" << dim;
}

Rectangle::Rectangle()
    : Rectangle(0, 0, 1, 1){
}

Rectangle::Rectangle(const Point& top_left, const Point& bottom_right)
    : top_left(top_left)
    , bottom_right(bottom_right){
}

Rectangle::Rectangle(int left, int top, int width, int height)
    : Rectangle(Point(left, top), Point(left + width - 1, top + height - 1)){
}

Rectangle::Rectangle(const Rectangle& other)
    : Rectangle(other.topLeft(), other.bottomRight()){
}

Rectangle& Rectangle::operator =(const Rectangle& other){
    if(this != &other){
        top_left = other.topLeft();
        bottom_right = other.bottomRight();
    }
    return *this;
}

const Point& Rectangle::topLeft() const{
    return top_left;
}

const Point& Rectangle::bottomRight() const{
    return bottom_right;
}

int Rectangle::getWidth() const{
    return bottom_right.getX() - top_left.getX() + 1;
}

int Rectangle::getHeight() const{
    return bottom_right.getY() - top_left.getY() + 1;
}

void Rectangle::set(const Point& top_left, const Point& bottom_right){
    this->top_left = top_left;
    this->bottom_right = bottom_right;
}

void Rectangle::set(int left, int top, int width, int height){
    this->top_left = Point(left, top);
    this->bottom_right = Point(left + width - 1, top + height - 1);
}

void Rectangle::setWidth(int width){
    bottom_right.setX(top_left.getX() + width - 1);
}

void Rectangle::setHeight(int height){
    bottom_right.setY(top_left.getY() + height - 1);
}

void Rectangle::move(int left, int top){
    int width = getWidth();
    int height = getHeight();
    top_left = Point(left, top);
    bottom_right = Point(left + width - 1, top + height - 1);
}

bool Rectangle::isValid() const{
    if(top_left.getX() > bottom_right.getX()){
        return false;
    }

    if(top_left.getY() > bottom_right.getY()){
        return false;
    }

    return true;
}

bool Rectangle::intersects(const Rectangle& other) const{
    if(top_left.getX() > other.bottom_right.getX()){
        return false;
    }

    if(top_left.getY() > other.bottom_right.getY()){
        return false;
    }

    if(bottom_right.getX() < other.top_left.getX()){
        return false;
    }

    if(bottom_right.getX() > other.top_left.getX()){
        return false;
    }

    return true;
}

const Rectangle Rectangle::intersected(const Rectangle& other) const{
    //TODO
    Rectangle r = other;
    return r;
}

std::ostream& Rectangle::stream_write(std::ostream& os) const{
    return os << "top_left:" << top_left << "; bootom_right:" << bottom_right;
}

void testGragh(){
    Graphic *g[3];
    g[0] = new Point(10, 10);
    g[1] = new Circle(Point(100, 100), 100);
    g[2] = new Rectangle(0, 0, 1000, 1000);

    for(auto i = 0; i < 3; i++){
        std::cout << *g[i] << std::endl;
    }
}
