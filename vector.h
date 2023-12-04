#pragma once
#include "DataField.h"
template <typename T>

class Vector
{
private:
    int length;
    int capacity;
    T* array = nullptr;
    int expandSize = 20;
    void expandArray();
public:
    Vector();
    //~Vector();
    void removeElement(int indx);
    Vector(const Vector& vector);
    void pushBack(T element);
    void clear();
    int size();
    T& operator [] (int index);
    Vector <T>& operator = (const Vector* vector);
    class Iterator
    {
    private:
        T* ptr;

    public:
        Iterator(T* p) : ptr(p) {}

        T& operator*() const
        {
            return *ptr;
        }

        Iterator& operator++()
        {
            ++ptr;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++ptr;
            return temp;
        }

        bool operator==(const Iterator& other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const
        {
            return ptr != other.ptr;
        }
    };

};
template class Vector<DataField>;
