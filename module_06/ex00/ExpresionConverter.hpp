#ifndef CONVERSOR_HPP
# define CONVERSOR_HPP
# include <ostream>

class ExpresionConverter
{
    private:
		ExpresionConverter(void);
		ExpresionConverter(ExpresionConverter &);
		ExpresionConverter& operator=(const ExpresionConverter&);

        static const std::string a_list[8];
        static double asciiConversion(const std::string&);
        static double numConversion(const std::string&);
        static int checkType(std::string&);
    public:
        virtual ~ExpresionConverter(void);

        static double convert(const std::string&);
};

#endif