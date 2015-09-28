#ifndef LECTURE9_H
#define LECTURE9_H

template <class T>
class lecture9
{
    public:
        lecture9(const T u, const T v);
        lecture9();
        //~lecture9();

        T getX();
        T getY();
        void setValue(T value);
    protected:
    private:
        T x, y;
};

#endif // LECTURE9_H
