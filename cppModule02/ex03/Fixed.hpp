#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    Fixed(int const integer);
    Fixed(float const floatNumber);
    Fixed(const Fixed &rhs);
    Fixed &operator=(const Fixed &rhs);
    ~Fixed();

    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    Fixed &operator++();   // Pre-increment
    Fixed operator++(int); // Post-increment (int parameter is the distinguishing factor)
    Fixed &operator--();   // Pre-decrement
    Fixed operator--(int); // Post-decrement (int parameter is the distinguishing factor)

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;

private:
    int rawBits;
    static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &rhs);

#endif
