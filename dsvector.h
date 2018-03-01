#ifndef DSVECTOR_H
#define DSVECTOR_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;
    void resize();
public:
    int getSize();
    int getCapacity();
    Vector(int x = 10);
    Vector(const Vector&);
    Vector& operator = (const Vector&);
    ~Vector();
    T& operator[] (const int);
    void addToEnd(const T&);
};

template <typename T>
Vector<T>::Vector(int x)
{
    size = 0;
    capacity = x;
    data = new T[x];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& dsvector)
{
    size = dsvector.size;
    capacity = dsvector.capacity;
    data = dsvector.data;
}

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& dsvector)
{
    size = dsvector.size;
    capacity = dsvector.capacity;
    delete[] this->data;
    data = new T[dsvector.capacity];
    for (int i = 0; i < dsvector.size ; i++)
        this->data[i] = dsvector.data[i];
    return *this;
}

template <typename T>
T& Vector<T>::operator[] (const int i)
{
    return (data[i]);
}

template<typename T>
void Vector<T>::addToEnd(const T& parameter)
{
    if(size == capacity)
        this->resize();
    data[size++] = parameter;
}

template <typename T>
int Vector<T>::getSize()
{
    return size;
}

template <typename T>
int Vector<T>::getCapacity()
{
    return capacity;
}

template <typename T>
void Vector<T>::resize()
{
    capacity = 2*size; //doubles size
    T* temp = new T[capacity];
    for(int i = 0; i < size ; i++)
        temp[i] = this->data[i]; //saves data beofre deleting it
    delete[] this->data;
    data = temp;
}

template <typename T>
Vector<T>::~Vector(){
    delete[] data;

#endif // DSVECTOR_H
