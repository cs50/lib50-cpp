#include <climits>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

#include "cs50.h"

namespace cs50
{

/**
 * Reads a line of text from standard input and returns it as a std::string;
 * The function is used internally for reading input and handling console input
 * stream errors. If eof or input stream corrupt (failed to read into string).
 * The argument passed to bool *ok is used to check for eof or bad string input
 * so it's set to false when read fails or is in eof state, and set to true
 * otherwise.
 */


/**
 * TODO
 */
void eprintf()
{
    // TODO
}

/**
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If eof or input stream corrupt (failed to read into string) returns
 * CHAR_MAX.
 */
char get_char()
{
    while (true)
    {
        std::string str;

        // attempt to read string input, on bad input return CHAR_MAX
        // on other caught exceptions just rethrow
        try
        {
            str = get_string();
        }
        catch (const std::domain_error& e)
        {
            return CHAR_MAX;
        }

        // return 1st char of str only if single char of input
        if (str.size() == 1)
        {
            return str[0];
        }
        
        // we're here if input was not exactly one char + newline
        std::cout << "Retry: ";
    }
}

/**
 * TODO
 */
double get_double()
{
    /**
    * TODO
    */
    return 0.0;
}

/**
 * TODO
 */
float get_float(void)
{
    // TODO
    return 0.0;
}

/**
 * Reads a line of text from standard input and returns the int value of the
 * string. If text does not represent an int user is prompted to retry. If eof
 * or input stream corrupt (failed to read into string) or int is out of range
 * returns INT_MAX.
 */
int get_int()
{
    // attempt to take an int from the user
    while (true)
    {
        std::string str;

        // attempt to read string input, on bad input return INT_MAX
        // on other caught exceptions just rethrow
        try
        {
            str = get_string();
        }
        catch (const std::domain_error& e)
        {
            return INT_MAX;
        }

        // check if input has no whitespace at beginning
        if (str.length() > 0 && !isspace(str[0]))
        {
            std::istringstream iss(str);
            int ret;

            // return if iss successfully read into an int and iss exhausted
            if (iss >> ret && iss.eof())
            {
                return ret;
            }
        }

        // if we're here the input was not ok so reprompt
        std::cout << "Retry: ";
    }
}

/**
 * Reads a line of text from standard input and returns the equivalent long
 * long int; if string does not represent a long long int, user is prompted to
 * retry. If eof or input stream corrupt (failed to read into string) or out of
 * range returns LLONG_MAX.
 */
long long get_long_long()
{
    // attempt to take an int from the user
    while (true)
    {
        std::string str;

        // attempt to read string input, on bad input return LLONG_MAX
        // on other caught exceptions rethrow exception as is
        try
        {
            str = get_string();
        }
        catch (const std::domain_error& e)
        {
            return LLONG_MAX;
        }

        // check if there's input with no whitespace at the beginning
        if (str.length() > 0 && !isspace(str[0]))
        {
            std::istringstream iss(str);
            long long ret;

            // return when iss successfully read into long long & iss exhausted
            if (iss >> ret && iss.eof())
            {
                return ret;
            }
        }

        // if we're here the input was not ok so reprompt
        std::cout << "Retry: ";
    }
}

/**
 * reads a line of text from standard input and returns it as std::string. If
 * input is invalid it returns an empty std::string.
 */
std::string get_string(void)
{
    // TODO: decide whether to return string or c_str
    std::string str;

    // attempt to read string input into str
    std::getline(std::cin, str);

    // check if input stream in bad state (hardware failure?)
    if (std::cin.bad())
    {
        // if we're here we can't recover the cin stream
        // we only get here in case of catastrophic error so throw
        throw (std::runtime_error("cs50::get_string: error reading input"));
    }

    if (std::cin.eof() || std::cin.fail())
    {
        // reset cin flags, enabling further input
        std::cin.clear();

        // throw exception on bad input
        throw std::domain_error("cs50::get_string: bad input");
    }

    // if we're here all is ok so we return the input
    return str;
}

}
