/*
** permut_nbr.cpp for Untitled (Workspace) in /home/xelium/2019/math/201yams_2019/src
**
** Made by alexis lopes
** Login   <alexis.lopes@epitech.eu>
**
** Started on  Mon Feb 10 16:06:52 2020 alexis lopes
** Last update Thu Feb 12 1:20:42 AM 2020 Edouard.touch
*/

#include <string>
#include <vector>
#include <iostream>

#include "math.hpp"
#include "errors.hpp"

void math::checkAlgo()
{
    if (!this->combinaison.compare("pair"))
        algoDices(2);
    else if (!this->combinaison.compare("three"))
        algoDices(3);
    else if (!this->combinaison.compare("four"))
        algoDices(4);
    else if (!this->combinaison.compare("full"))
        algoFull();
    else if (!this->combinaison.compare("straight"))
        algoStraight();
    else if (!this->combinaison.compare("yams"))
        algoDices(5);
    return;
}

math::math(char *str, char **av)
{
    int end = 0;
    std::string combination(str);
    std::string str1;
    std::string str2 = combination;
    std::vector<std::string>tab;

    while (1)
    {
        end = str2.find("_");
        if (end == -1) {
            tab.push_back(str2);
            break;
        }
        str1 = str2.substr(0, end);
        str2 = str2.substr(end + 1);
        tab.push_back(str1);
    }
    math::combinaison = tab[0];
    if (!isdigit(tab[1].c_str()[0]))
        throw Error(1, "invalid arguments", 2);
    if (tab[1].size() > 1)
        throw Error(1, "too much characters", 2);
    math::number1 = std::stoi(tab[1]);
    if (this->number1 <= 0 || this->number1 > 6)
        throw Error(1, "invalid number", 2);
    if (tab.size() > 2) {
        if (!isdigit(tab[1].c_str()[0])) {
            throw Error(1, "invalid arguments", 2);
        } if (tab[2].size() > 1)
                throw Error(1, "too much characters", 2);
        math::number2 = std::stoi(tab[2]);
        if (this->number2 <= 0 || this->number2 > 6 || (this->number1 == this->number2))
            throw Error(1, "invalid number", 2);
    }
    for (int i = 1; i < 6; i++)
        nbs.push_back(atoi(av[i]));
}