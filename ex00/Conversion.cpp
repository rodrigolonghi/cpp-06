#include "Conversion.hpp"

Conversion::Conversion() : pseudo(false) {}

Conversion::~Conversion() {}

Conversion::Conversion(std::string arg) {
	char *str;

	this->arg = arg;
	detectType(arg);
	if (this->getType() != 4) {
		str = const_cast<char *>(this->getArg().c_str());
		toInt(str);
		toChar(str);
		toFloat(str);
		toDouble(str);
	}
}

Conversion::Conversion(Conversion const &src) {
	*this = src;
}

Conversion &Conversion::operator=(Conversion const &src) {
	this->type = src.getType();
	return (*this);
}

int	Conversion::getType() const {
	return (this->type);
}

std::string	Conversion::getArg() const {
	return (this->arg);
}

bool	Conversion::getPseudo() const {
	return (this->pseudo);
}

long	Conversion::getConvertedInt() const {
	return (this->convertedInt);
}

char	Conversion::getConvertedChar() const {
	return (this->convertedChar);
}

double	Conversion::getConvertedDouble() const {
	return (this->convertedDouble);
}

float	Conversion::getConvertedFloat() const {
	return (this->convertedFloat);
}

void Conversion::detectType(std::string arg) {
	if (isPseudo(arg)) {
		return ;
	} else if (isInt(arg)) {
		this->type = TYPE_INT;
	} else if (isChar(arg)) {
		this->type = TYPE_CHAR;
	} else if (isFloat(arg)) {
		this->type = TYPE_FLOAT;
	} else if (isDouble(arg)) {
		this->type = TYPE_DOUBLE;
	} else {
		this->type = TYPE_INVALID;
	}
}

bool Conversion::isInt(std::string arg) {
	if (arg.length() == 1 && !std::isdigit(arg[0]))
		return (false);
	for (int i = (arg[0] == '-') ? 1 : 0; i < (int) arg.length(); i++) {
		if (!std::isdigit(arg[i]))
			return false;
	}
	return (true);
}

bool Conversion::isChar(std::string arg) {
	return (arg.length() == 1 && std::isprint(arg[0]) && !std::isdigit(arg[0]));
}

bool Conversion::isDouble(std::string arg) {
	bool point = false;

	for (int i = (arg[0] == '-') ? 1 : 0; i < (int) arg.length(); i++) {
		if (arg[i] != '.' && !std::isdigit(arg[0]))
			return (false);
		if (arg[i] == '.') {
			if (point)
				return (false);
			point = (true);
		}
	}
	return (true);
}

bool Conversion::isFloat(std::string arg) {
	bool point = false;
	bool f = false;

	for (int i = (arg[0] == '-') ? 1 : 0; i < (int) arg.length(); i++) {
		if (arg[i] != '.' && !std::isdigit(arg[0]) && arg[i] != 'f')
			return (false);
		if (arg[i] == '.') {
			if (point)
				return (false);
			point = (true);
		} if (arg[i] == 'f') {
			if (f)
				return (false);
			f = (true);
		}
	}
	if (!f)
		return (false);
	return (true);
}

bool Conversion::isPseudo(std::string arg) {
	this->pseudo = false;
	if (arg.length() < 3)
		return (false);
	if (arg == "nan" || arg == "-inf" || arg == "+inf")
	{
		this->type = TYPE_DOUBLE;
		this->pseudo = true;
		return (true);
	}
	if (arg == "nanf" || arg == "-inff" || arg == "+inff")
	{
		this->type = TYPE_FLOAT;
		this->pseudo = true;
		return (true);
	}
	return (false);
}

void	Conversion::toInt(char *str) {
	long	result;

	if (this->getType() == 0) {
		result = std::atol(str);
	} else if (this->getType() == 1) {
		result = str[0];
	} else if (this->getType() == 2) {
		result = (long) std::atof(str);
	} else {
		result = (long) std::strtod(str, NULL);
	}
	this->convertedInt = result;
}

void	Conversion::toChar(char *str) {
	char	result;

	if (this->getType() == 0 || this->getType() == 2 || this->getType() == 3) {
		if (this->getConvertedInt() < 32 || this->getConvertedInt() > 126)
			result = 0;
		else
			result = this->getConvertedInt();
	} else {
		result = str[0];
	}
	this->convertedChar = result;
}

void	Conversion::toFloat(char *str) {
	float	result;

	if (this->getType() == 0 || this->getType() == 1) {
		result = (float) this->getConvertedInt();
	} else if (this->getType() == 2) {
		result = std::atof(str);
	} else {
		result = (float) std::strtod(str, NULL);
	}
	this->convertedFloat = result;
}

void	Conversion::toDouble(char *str) {
	double	result;

	if (this->getType() == 0 || this->getType() == 1) {
		result = (double) this->getConvertedInt();
	} else if (this->getType() == 2) {
		result = (double) std::atof(str);
	} else {
		result = std::strtod(str, NULL);
	}
	this->convertedDouble = result;
}

std::ostream &operator<<(std::ostream &o, Conversion const &i) {
	if (i.getType() == 4) {
		o << i.getArg() << " isn't a valid value to convert.\n";
		return (o);
	}
	if (i.getPseudo()) {
		o << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: " << (i.getType() == 2 ? i.getArg() : i.getArg() + "f") << std::endl
		<< "double: " << (i.getType() == 2 ? i.getArg().substr(0, i.getArg().length() - 1) : i.getArg()) << std::endl;
		return (o);
	}
	// std::cout << "type: " << i.getType() << std::endl;
	// std::cout << "double: " << std::stod(i.getArg()) << std::endl;
	// std::cout << "float: " << std::stof(i.getArg()) << std::endl << std::endl;
	o << "char: ";
	if (i.getConvertedChar() == 0)
		o << "Non displayable\n";
	else
		o << "\'" << i.getConvertedChar() << "\'" << std::endl;
	o << "int: ";
	if (i.getConvertedInt() >  std::numeric_limits<int>::max() || i.getConvertedInt() <  std::numeric_limits<int>::min())
		o << "Number overflow\n";
	else
		o << i.getConvertedInt() << std::endl;
	o << "float: " << i.getConvertedFloat() << "f" << std::endl;
	o << "double: " << i.getConvertedDouble() << std::endl;
	return (o);
}
