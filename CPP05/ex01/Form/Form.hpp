/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:35:58 by lprates           #+#    #+#             */
/*   Updated: 2022/06/25 22:57:24 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(Form const &src);
		Form &operator=(Form const &src);
		~Form();

		// getters
		const std::string	&getName();
		bool				&getIsSigned();
		const int			&getGradeToSign();
		const int			&getGradeToExecute();
		
		// member function
		void		beSigned(Bureaucrat &buro);

		class GradeTooLowException : virtual public std::exception
		{
			private:
				virtual const char* what() const throw ();
		};

	private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

};

std::ostream	&operator<<(std::ostream &stream, Form &form);

#endif
