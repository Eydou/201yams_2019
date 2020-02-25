/*
** errors.hpp for Untitled (Workspace) in /home/xelium/2019/cpp/cpp_nanotekspice
**
** Made by alexis lopes
** Login   <alexis.lopes@epitech.eu>
**
** Started on  Sat Feb 1 15:52:56 2020 alexis lopes
** Last update Tue Feb 10 7:22:15 PM 2020 Edouard.touch
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <string>
#include <iostream>
#include <fstream>

class Error : public std::exception
{
public:
    Error(int numero = 0, std::string const &phrase = "", int niveau = 0) throw()
        : m_numero(numero), m_phrase(phrase), m_niveau(niveau)
    {
        std::cerr << "\033[1;31m" << m_phrase << "\033[0m" << std::endl;
        exit(84);
    }
    virtual const char *what() const throw()
    {
        return m_phrase.c_str();
    }
    int getNiveau() const throw()
    {
        return m_niveau;
    }
    virtual ~Error() throw()
    {
    }

private:
    int m_numero;
    std::string m_phrase;
    int m_niveau;
};

void check_errors(int, char **);

#endif /* !ERRORS_HPP_ */
