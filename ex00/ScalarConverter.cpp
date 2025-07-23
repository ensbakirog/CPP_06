#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <iomanip>

static bool isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

static bool isInt(const std::string& literal) {
    if (literal.empty())
        return false;
    // Check for leading whitespace
    if (std::isspace(literal[0]))
        return false;
    char* end;
    errno = 0;
    long val = std::strtol(literal.c_str(), &end, 10);
    return *end == '\0' && errno == 0 && val >= std::numeric_limits<int>::min() && 
           val <= std::numeric_limits<int>::max();
}

static bool isFloat(const std::string& literal) {
    if (literal.empty())
        return false;
    // Check for leading whitespace
    if (std::isspace(literal[0]))
        return false;
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    if (literal[literal.length() - 1] != 'f')
        return false;
    char* end;
    errno = 0;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0' && errno == 0;
}

static bool isDouble(const std::string& literal) {
    if (literal.empty())
        return false;
    // Check for leading whitespace
    if (std::isspace(literal[0]))
        return false;
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    char* end;
    errno = 0;
    std::strtod(literal.c_str(), &end);
    return *end == '\0' && errno == 0;
}

static void printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || 
        value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value, const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "nan")
        std::cout << "float: " << (literal == "nan" ? "nanf" : literal) << std::endl;
    else if (std::isnan(value) || std::isinf(value))
        std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << 
                     static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value, const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan" || literal == "nanf")
        std::cout << "double: " << (literal == "nanf" ? "nan" : literal) << std::endl;
    else if (std::isnan(value) || std::isinf(value))
        std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << 
                     value << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    double value = 0;
    if (isChar(literal)) {
        value = static_cast<double>(literal[0]);
    } else if (isInt(literal)) {
        value = std::atoi(literal.c_str());
    } else if (isFloat(literal)) {
        if (literal == "-inff" || literal == "+inff" || literal == "nanf")
            value = std::strtod(literal.c_str(), NULL);
        else
            value = std::strtof(literal.c_str(), NULL);
    } else if (isDouble(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value, literal);
    printDouble(value, literal);
}