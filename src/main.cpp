/*
** main.cpp for 201yams_2019 in /home/eydou/2019/Math/201yams_2019/src
**
** Made by Edouard.touch
** Login   <edouard.touch@epitech.eu>
**
** Started on  Mon Feb 10 2:49:21 PM 2020 Edouard.touch
** Last update Sun Feb 15 2:57:25 PM 2020 Edouard.touch
*/

#include "math.hpp"
#include "errors.hpp"

static void checkError(int ac, char *av[])
{
    int val(0), end(0);
    char *combination = NULL;
    std::string str;
    char combinaison[6][10] = { "pair", "three", "four", 
                           "full", "straight", "yams" };

    if (ac != 7)
        throw Error(1, "invalid arguments", 2);

    for (int i = 1; i < (ac - 1); i++)
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (isdigit(av[i][j]) == false)
                throw Error(1, "invalid number", 2);
            if (atoi(av[i]) > 6 || atoi(av[i]) < 0)
                throw Error(1, "invalid number", 2);
        }
    for (int j = 0; av[6][j] != '\0'; j++)
        if (av[6][j] == '_')
            val++;
    if (!val)
        throw Error(1, "invalid combination", 2);
    combination = av[6];
    end = std::string(combination).find("_");
    str = std::string(combination).substr(0, end);
    if (val > 1 && str.compare(combinaison[3]) != 0)
        throw Error(1, "invalid combination", 2);
    else if ((!str.compare(combinaison[3])) && (val == 1 || val > 2))
        throw Error(1, "invalid combination", 2);
    for (int i = 0; i < 6; i++) {
        if (!str.compare(combinaison[i]))
            val = 10;
    }
    if (val != 10)
        throw Error(1, "invalid combination", 2);
    return;
}

static void displayHelp()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "    ./201yams d1 d2 d3 d4 d5 c\n" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "    d1     value of the first die (0 if not thrown)" << std::endl;
    std::cout << "    d2     value of the second die (0 if not thrown)" << std::endl;
    std::cout << "    d3     value of the third die (0 if not thrown)" << std::endl;
    std::cout << "    d4     value of the fourth die (0 if not thrown)" << std::endl;
    std::cout << "    d5     value of the fifth die (0 if not thrown)" << std::endl;
    std::cout << "    c      expected combination" << std::endl;
    exit(0);
}

int main(int ac, char *av[])
{
    if (ac == 2)
        if (av[1] == std::string("-h") && ac == 2)
            displayHelp();
    checkError(ac, av);
    math math(av[6], av);
    math.checkAlgo();
    return (0);
}