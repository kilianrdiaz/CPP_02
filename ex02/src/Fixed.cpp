/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <kroyo-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:15:52 by kroyo-di          #+#    #+#             */
/*   Updated: 2025/11/20 20:56:26 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fpvalue = 0;
}

Fixed::Fixed(const int num) : _fpvalue(num << _fbits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _fpvalue(roundf(num * (1 << _fbits)))   
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : _fpvalue(copy._fpvalue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        _fpvalue = copy._fpvalue;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits ( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fpvalue;
}

void Fixed::setRawBits( int const raw )
{
    this->_fpvalue = raw;
}

float Fixed::toFloat(void) const {
    return _fpvalue / float(1 << _fbits);
}

int Fixed::toInt(void) const {
    return _fpvalue >> _fbits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const
{
    return _fpvalue > other._fpvalue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return _fpvalue < other._fpvalue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _fpvalue >= other._fpvalue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _fpvalue <= other._fpvalue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _fpvalue == other._fpvalue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _fpvalue != other._fpvalue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result._fpvalue = _fpvalue + other._fpvalue;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result._fpvalue = _fpvalue - other._fpvalue;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    long tmp = (long)_fpvalue * (long)other._fpvalue;
    result._fpvalue = tmp >> _fbits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    long tmp = ((long)_fpvalue << _fbits);
    result._fpvalue = tmp / other._fpvalue;
    return result;
}

Fixed &Fixed::operator++()
{
    _fpvalue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _fpvalue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    _fpvalue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _fpvalue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}