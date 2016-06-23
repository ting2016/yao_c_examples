#pragma once
#include <string>
#include <vector>

namespace yao{
    namespace graph{
        class Graphic;
        class Point;
        class Circle;
        class Rectangle;
        void testGragh();
    }
}
/*!
 * \brief Graphic is an abstract class for other graphical classes
 */
class yao::graph::Graphic{
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
class yao::graph::Point: public yao::graph::Graphic{
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

    /*!
     * \brief getX
     * \return int
     */
    int getX() const;

    /*!
     * \brief getY
     * \return int
     */
    int getY() const;

    /*!
     * \brief setX
     * \param int x
     */
    void setX(int x);

    /*!
     * \brief setY
     * \param int y
     */
    void setY(int y);

    ~Point();
protected:
    std::ostream& stream_write(std::ostream&) const;
private:
    int x;
    int y;
};

class yao::graph::Circle : public yao::graph::Graphic{
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

class yao::graph::Rectangle: public yao::graph::Graphic{
public:
    /*!
     * \brief Rectangle, default CTOR
     */
    Rectangle();

    /*!
     * \brief Rectangle, CTOR
     * \param const Point& top_left
     * \param const Point& bottom_right
     */
    Rectangle(const Point& top_left, const Point& bottom_right);

    /*!
     * \brief Rectangle, CTOR
     * \param int left
     * \param int top
     * \param int width
     * \param int height
     */
    Rectangle(int left, int top, int width, int height);

    /*!
     * \brief Rectangle, CTOR
     * \param const Rectangle& other
     */
    Rectangle(const Rectangle& other);

    /*!
     * \brief operator =, asign CTOR
     * \param const Rectangle& other
     * \return
     */
    Rectangle& operator =(const Rectangle& other);

    /*!
     * \brief topLeft
     * \return const Point&
     */
    const Point& topLeft() const;

    /*!
     * \brief bottomRight
     * \return const Point&
     */
    const Point& bottomRight() const;

    /*!
     * \brief getWidth
     * \return int
     */
    int getWidth() const;

    /*!
     * \brief getHeight
     * \return int
     */
    int getHeight() const;

    /*!
     * \brief set
     * \param const Point& top_left
     * \param const Point& bottom_right
     */
    void set(const Point& top_left, const Point& bottom_right);

    /*!
     * \brief set
     * \param int left
     * \param int top
     * \param int width
     * \param int height
     */
    void set(int left, int top, int width, int height);

    /*!
     * \brief setWidth
     * \param int width
     */
    void setWidth(int width);

    /*!
     * \brief setHeight
     * \param int height
     */
    void setHeight(int height);

    /*!
     * \brief move
     * \param int left
     * \param int top
     */
    void move(int left, int top);

    /*!
     * \brief isValid
     * \return bool
     */
    bool isValid() const;

    /*!
     * \brief intersects
     * \param const Rectangle& other
     * \return bool
     */
    bool intersects(const Rectangle& other) const;

    /*!
     * \brief intersected
     * \param const Rectangle& other
     * \return Rectangle&
     */
    const Rectangle intersected(const Rectangle& other) const;

protected:
    std::ostream& stream_write(std::ostream&) const;
private:
    Point top_left;
    Point bottom_right;
};




