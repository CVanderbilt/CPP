#include "Squad.hpp"
#include <iostream>

Squad::Squad(void): size(0), arr(0){}
Squad::Squad(const Squad& s){
    *this = s;
}
Squad::~Squad(void){
    for (int i = 0; i < this->size; i++){
        delete this->arr[i];
    }
    delete[] this->arr;
}

Squad& Squad::operator=(const Squad& s){
    int i, j;
    ISpaceMarine **list;

    j = -1;
    i = s.getCount();
    list = new ISpaceMarine*[i];
    while (++j < i)
        list[j] = s.getUnit(j);
    j = -1;
    delete[] this->arr;
    this->arr = list;
    return (*this);
}

//others
int Squad::push(ISpaceMarine* m_ptr){
    ISpaceMarine **list;

    list = new ISpaceMarine*[this->size + 1];
    for (int i = 0; i < this->size; i++)
        list[i] = this->arr[i];
    list[this->size] = m_ptr;
    if (this->arr)
        delete[] this->arr;
    this->arr = list;
    this->size += 1;
    return (this->size);
}

//get & set
int Squad::getCount(void) const{return (this->size);}
ISpaceMarine* Squad::getUnit(int index) const{
    if (this->size > index && index >= 0)
        return (this->arr[index]);
    return (0);
}