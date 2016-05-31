#pragma once
#include <string>
#include <vector>
//in this example, we will focus on the following skills
//1. comments
//2. class design(encapsulation, inheritance, polymorphism)
//3. enum
//4. namespace


namespace yao_graph{

/*!
 * \brief Graphic is an abstract class for other graphical classes
 */
class Graphic{
public:
    /*!
     * \brief Graphic, default CTOR
     */
    Graphic();

    /*!
     * \brief operator=, assign CTOR deleted
     * \return Graphic
     */
    Graphic& operator=(const Graphic&) = delete;


    /*!
     * \brief Graphic, copy CTOR deleted
     */
    Graphic(const Graphic&) = delete;

    /*!
     * pure virtual DTOR
     */
    virtual ~Graphic();

    /*!
     * \brief operator <<
     * \param std::ostream
     * \param Graphic&
     * \return std::ostream&
     */
    friend inline std::ostream& operator<<(std::ostream& os, const Graphic& obj){
        return obj.stream_write(os);
    }

protected:
    /*!
     * \brief stream_write: write this object to stream
     * \param std::ostream&
     * \return std::ostream&
     */
    virtual std::ostream& stream_write(std::ostream&) const = 0;
};

/*!
 * \brief The Point class
 * contains int x and int y
 */
class Point: public Graphic{
public:
    /*!
     * \brief Point, default CTOR
     */
    Point();

    /*!
     * \brief Point, CTOR
     * \param int x
     * \param int y
     */
    Point(int x, int y);

    /*!
     * \brief Point, copy CTOR
     * \param const Point&
     */
    Point(const Point& other);

    /*!
     * \brief operator =, copy CTOR
     * \param const Point&
     * \return Point&
     */
    Point& operator=(const Point& other);

    ~Point();
protected:
    std::ostream& stream_write(std::ostream&) const;
private:
    int x;
    int y;
};

class Circle : public Graphic{
public:
    /*!
     * \brief Circle, default CTOR
     */
    Circle();

    /*!
     * \brief Circle, CTOR
     * \param const Point& center
     * \param int dim
     */
    Circle(const Point& point, int dim);

    /*!
     * \brief operator =, assign CTOR
     * \param const Circle& other circle
     * \return const Circle&
     */
    Circle& operator=(const Circle& other);

    /*!
     * \brief Circle, copy CTOR
     * \param const Circle& other circle
     */
    Circle(const Circle& other);

    ~Circle();
protected:
    std::ostream& stream_write(std::ostream&) const;

private:
    Point center;
    int dim;
};

class Rectangle: public Graphic{
public:
    /*!
     * \brief Rectangle, default CTOR
     */
    Rectangle();
    Rectangle(const Point& top_left, const Point& bottom_right);
    Rectangle(int x, int y, int w, int h);

    Rectangle(const Rectangle& other);
    Rectangle& operator =(const Rectangle& other);

    const Point& topLeft() const;
    const Point& bottomRight() const;
    int getWidth() const;
    int getHeight() const;

    void set(const Point& top_left, const Point& bottom_right);
    void set(int x, int y, int w, int h);
    void setWidth(int w);
    void setHeight(int h);

    void move(int x, int y);
    bool isValid() const;

    bool intersects(const Rectangle& other) const;

    Rectangle& intersected(const Rectangle& other);

protected:
    std::ostream& stream_write(std::ostream&) const;
private:
    Point top_left;
    Point bottom_right;
};
}
