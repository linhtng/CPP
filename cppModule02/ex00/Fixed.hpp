#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);

private:
    int rawBits;
    static const int fractionalBits = 8;
};

#endif
