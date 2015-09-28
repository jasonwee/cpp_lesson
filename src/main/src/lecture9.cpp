#include "lecture9.h"
#include <iostream>

using namespace std;

template <class T>
lecture9<T>::lecture9(const T u, const T v) : x(u), y(v)
{
    //ctor
}

template <class T>
lecture9<T>::lecture9()
{

}


/*
template <class T>
lecture9<T>::~lecture9()
{
    //dtor
}
*/

template <class T>
T lecture9<T>::getX() {
    return x;
}

template <class T>
T lecture9<T>::getY() {
    return y;
}

template <class T>
void lecture9<T>::setValue(T value) {

}
