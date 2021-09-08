#include "span.hpp"
#include <iostream>
#include <vector>

Span::Span(void): m_max_size(0){}
Span::Span(unsigned int num): m_max_size(num){}
Span::Span(const Span& s){*this = s;}
Span::~Span(void){}

Span& Span::operator=(const Span& s){
    this->m_max_size = s.getMaxSize();
    this->m_set.clear();
    this->m_set = s.getSet();
    return (*this);
}

const char* Span::SpanFullException::what(void) const throw()
{
    return ("Span is full now, or wrong parameters");
}
const char* Span::SpanEmptyException::what(void) const throw()
{
    return ("Span is empty or only contains one element");
}
const char* Span::WrongIteratorsException::what(void) const throw()
{
    return ("Wrong combination of iterators");
}

void Span::addNumber(int n)
{
    if (!(this->m_max_size > this->m_set.size()))
        throw Span::SpanFullException();
	std::cout << "added: " << n << std::endl;
    this->m_set.insert(n);
}

int Span::shortestSpan(void) const
{
    if (this->m_set.size() <= 1)
        throw Span::SpanEmptyException();
    return (*this->m_set.begin());
}

int Span::longestSpan(void) const
{
    if (this->m_set.size() <= 1)
        throw Span::SpanEmptyException();
    return (*std::prev(this->m_set.end()));
}

size_t Span::getMaxSize(void) const{return (this->m_max_size);}
const std::multiset<int> Span::getSet(void) const{return (this->m_set);}
int	Span::getOcupiedSize(void) const{return (this->m_set.size());}
