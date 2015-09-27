#ifndef LECTURE6_H
#define LECTURE6_H


// class default access modifier is private
class lecture6
{
    // private by default
    double x;
    double y;

    public:
        lecture6();
        ~lecture6();
        void printVector(double x0, double x1, double y0, double y1);
        void offsetVector(double &x0, double &x1, double &y0, double &y1, double offsetX, double offsetY);
    protected:
    private:
};

// carry over from c, same as cpp class. with struct, structs default access modifier is public.
struct Point {
    double x;
    double y;

};

#endif // LECTURE6_H
