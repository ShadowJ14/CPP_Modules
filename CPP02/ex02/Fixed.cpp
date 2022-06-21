/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:04:44 by lprates           #+#    #+#             */
/*   Updated: 2022/06/20 11:07:43 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : _fixedPointValue(n << Fixed::_fractionalBits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _fixedPointValue(roundf(n * (1 << Fixed::_fractionalBits)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_fixedPointValue / (float)(1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

bool	Fixed::operator==(const Fixed& fpoint)
{
	return (this->getRawBits() == fpoint.getRawBits());
}

bool	Fixed::operator!=(const Fixed& fpoint)
{
	return (this->getRawBits() != fpoint.getRawBits());
}

bool	Fixed::operator<=(const Fixed& fpoint)
{
	return (this->getRawBits() <= fpoint.getRawBits());
}

bool	Fixed::operator>=(const Fixed& fpoint)
{
	return (this->getRawBits() >= fpoint.getRawBits());
}

bool	Fixed::operator<(const Fixed& fpoint)
{
	return (this->getRawBits() < fpoint.getRawBits());
}

bool	Fixed::operator>(const Fixed& fpoint)
{
	return (this->getRawBits() > fpoint.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& fpoint)
{
	Fixed	result;
	
	result.setRawBits(this->getRawBits() + fpoint.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& fpoint)
{
	Fixed	result;
	
	result.setRawBits(this->getRawBits() - fpoint.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& fpoint)
{
	Fixed	result(this->toFloat() * fpoint.toFloat());
	
	return (result);
}

Fixed	Fixed::operator/(const Fixed& fpoint)
{
	Fixed	result(this->toFloat() / fpoint.toFloat());
	
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result;

	result.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return (result);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result;

	result.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return (result);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if ((Fixed &)a < (Fixed &)b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if ((Fixed &)a > (Fixed &)b)
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &stream, const Fixed& fp)
{
	stream << fp.toFloat();
	return stream;
}

const int	Fixed::_fractionalBits = 8;
