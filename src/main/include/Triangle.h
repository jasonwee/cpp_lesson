#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Polygon.h>

class Triangle : public Polygon
{
    public:
        Triangle();
        ~Triangle();

        int area();
    protected:
    private:
};

#endif // TRIANGLE_H
