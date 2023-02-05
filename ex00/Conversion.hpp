#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <limits>

#define TYPE_INT		0;
#define TYPE_CHAR		1;
#define TYPE_FLOAT		2;
#define TYPE_DOUBLE		3;
#define TYPE_INVALID	4;

class Conversion {
	private:
		int			type;
		std::string	arg;
		bool		pseudo;
		long		convertedInt;
		char		convertedChar;
		double		convertedDouble;
		float		convertedFloat;

	public:
		Conversion();
		~Conversion();
		Conversion(std::string arg);
		Conversion(Conversion const &src);
		Conversion &operator=(Conversion const &src);

		int			getType() const;
		std::string	getArg() const;
		bool		getPseudo() const;
		long		getConvertedInt() const;
		char		getConvertedChar() const;
		double		getConvertedDouble() const;
		float		getConvertedFloat() const;

		void	detectType(std::string arg);
		bool	isInt(std::string arg);
		bool	isChar(std::string arg);
		bool	isDouble(std::string arg);
		bool	isFloat(std::string arg);
		bool	isPseudo(std::string arg);
		void	toInt(char *str);
		void	toChar(char *str);
		void	toDouble(char *str);
		void	toFloat(char *str);
};

std::ostream &operator<<(std::ostream &o, Conversion const &i);

#endif
