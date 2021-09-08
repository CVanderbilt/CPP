#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <set>
# include <cmath>
# include <algorithm>

class Span
{
    private:
        std::multiset<int> m_set;
        size_t m_max_size;
    public:
        Span(void);
        Span(unsigned int);
        Span(const Span&);
        virtual ~Span(void);
        
        Span& operator=(const Span&);

        class SpanFullException: public std::exception{
            const char* what(void) const throw();
        };
        class SpanEmptyException: public std::exception{
            const char* what(void) const throw();
        };
        class WrongIteratorsException: public std::exception{
            const char* what(void) const throw();
        };

        void addNumber(int);


		template<typename InputIterator>
		void addNumber(InputIterator begin, InputIterator end)
		{
			if (this->m_set.size() + std::distance(begin, end) > this->m_max_size)
				throw Span::SpanFullException();
			this->m_set.insert(begin, end);
		}

        int shortestSpan(void) const;
        int longestSpan(void) const;

        size_t getMaxSize(void) const;
        const std::multiset<int> getSet(void) const;
		int getOcupiedSize(void) const;
};

#endif