#include "Vector.h"

template <typename T>
Vector<T>::Vector()
{
    this->length = 0;
    this->capacity = this->expandSize;
    this->array = new T[expandSize];
}

template <typename T>
void Vector<T>::removeElement(int indx)
{

    for (int i = indx; i < this->length-1; i++)
    {
        this->array[i] = this->array[i + 1];
    }
    this->length--;
}
template <typename T>
void Vector<T>::clear()
{
    this->length = 0;
}

template <typename T>
void Vector<T>::expandArray()
{

    T* expandedArray = new T[this->capacity + this->expandSize];
    for (int i = 0; i < this->length; i++)
    {
        expandedArray[i] = this->array[i];
    }
    delete[] array;
    this->array = expandedArray;
    this->capacity += expandSize;
}

//template <typename T>
//Vector<T>::~Vector()
//{
//	if (sizeof(array) == 0) return;
//	delete[] this->array;
//	this->length = 0;
//	this->capacity = 0;
//	cout << "destructor" << endl;
//}

template <typename T>
Vector<T>::Vector(const Vector& vector)
{
    if (vector.array != nullptr)
    {
        this->array = vector.array;
        this->length = vector.length;
        this->capacity = vector.capacity;
    }
}
template <typename T>
void Vector<T>::pushBack(T element)
{
    if (this->length == this->capacity)
    {
        expandArray();
    }
    this->array[this->length] = element;
    length++;
}
template <typename T>
Vector<T>& Vector<T>::operator = (const Vector* vector)
{
    Vector<T> temp;
    memcpy(temp.array, vector->array, this->capacity * sizeof(T));
    temp.length = vector->length;
    temp.capacity = vector->capacity;
    return temp;
}

template <typename T>
int Vector<T>::size()
{
    return this->length;
}

template <typename T>
T& Vector<T>::operator[] (int index)
{
    return array[index];
}
