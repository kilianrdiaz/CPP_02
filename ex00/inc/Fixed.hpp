#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string.h>

class Fixed
{
    private:
        int _fpoint;
        static const int _fbits = 8;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif