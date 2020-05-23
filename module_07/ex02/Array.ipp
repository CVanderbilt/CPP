#include "Array.hpp"
#include <iostream>

//Constructors and destructor
template <typename T>
Array<T>::Array(void): m_size(0), m_arr(new T [0]){}
template <typename T>
Array<T>::Array(unsigned int n): m_size(n), m_arr(new T [n]){}
template <typename T>
Array<T>::Array(const Array& a): m_size(0), m_arr(new T [0]){*this = a;}
template <typename T>
Array<T>::~Array(void){}

//Operators
template <typename T>
Array<T>& Array<T>::operator=(const Array& a){
    delete [] this->m_arr;
    this->m_size = a.size;

    for (int i = 0; i < this->m_size; i++)
        this->m_arr[i] = a[i];
}

template <typename T>
T& Array<T>::operator[](int idx) const{
    if (idx < 0 || idx >= this->m_size)
        throw (Array::IndexOutOfBoundsException());
    return (this->m_arr[idx]);
}

//Others
template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
    return ("Index out of bounds\n");
}

template <typename T>
int Array<T>::size(void) const
{
    return (this->m_size);
}

