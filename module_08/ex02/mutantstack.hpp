#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>       // std::cout
# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{   
    public:
        MutantStack(void);
        MutantStack(const Container& c);
        ~MutantStack(void);

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack& operator=(const MutantStack&);

        iterator begin(void) ;
        const_iterator begin(void) const ;
        reverse_iterator rbegin(void) ;
        const_reverse_iterator rbegin(void) const ;
        iterator end(void) ;
        const_iterator end(void) const ;
        reverse_iterator rend(void) ;
        const_reverse_iterator rend(void) const ;
};

//Constructors & destructor
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(): std::stack<T, Container>(){}
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const Container& cntr): std::stack<T, Container>(cntr){}
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(){}

//Operators
template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack<T, Container>& ms){
    this->c = ms.c;
    return (*this);
}

//Others
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {return (this->c.begin());}
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const {return (this->c.begin());}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() {return (this->c.rbegin());}
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const {return (this->c.rbegin());}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {return (this->c.end());}
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const {return (this->c.end());}
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() {return (this->c.rend());}
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const {return (this->c.rend());}

#endif