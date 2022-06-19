/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 02:04:51 by lprates           #+#    #+#             */
/*   Updated: 2022/06/19 18:54:12 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &rhs);
		~Fixed(void);
		Fixed(int const nb);
		Fixed(float const nb);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool operator==(const Fixed& fpoint);
		bool operator!=(const Fixed& fpoint);
		bool operator<=(const Fixed& fpoint);
		bool operator>=(const Fixed& fpoint);
		bool operator<(const Fixed& fpoint);
		bool operator>(const Fixed& fpoint);

		Fixed operator+(const Fixed& fpoint);
		Fixed operator-(const Fixed& fpoint);
		Fixed operator*(const Fixed& fpoint);
		Fixed operator/(const Fixed& fpoint);
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits;
};

std::ostream& operator<<(std::ostream &stream, const Fixed& fp);

#endif
