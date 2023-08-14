#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <cstdlib>

enum e_type { NONE, INT, FLOAT, CHAR, DOUBLE, LITERALS };

class ScalarConverter
{
    private:
        char        _c;
        int         _i;
        float       _f;
        double      _d;
        bool        _prob;
        e_type      _type;
        std::string _para;


    public :
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        ~ScalarConverter(void);
        ScalarConverter& operator=(const ScalarConverter& rhs);

        char        get_char(void) const;
        int         get_int(void) const;
        float       get_float(void) const;
        double      get_double(void) const;
        std::string get_para(void) const;

        void        set_char(char c);
        void        set_int(char i);
        void        set_float(char f);
        void        set_double(char d);
        void        set_para(std::string para);
        void        set_type(void);

        void        print_char(void) const;
        void        print_int(void) const;
        void        print_float(void) const;
        void        print_double(void) const;

        bool        is_prob(void);
        void        convert(void);

};
std::ostream& operator<<(std::ostream& out, const ScalarConverter& rhs);

#endif

