#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Polygon.h>


class Rectangle : public Polygon
{
    public:
        Rectangle();
        virtual ~Rectangle();

        int area();
    protected:
    private:
};

#endif // RECTANGLE_H
