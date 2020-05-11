#ifndef REPLACE_HPP
# define REPLACE_HPP
# include <iostream>

class Replace
{
    private:
        Replace(void);
    public:
        static void
    ft_replace(std::string filename, std::string to_find, std::string replacement);
    static std::string get_file_contents(const std::string filename);
};

#endif