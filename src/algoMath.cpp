/*
** algoMath.cpp for 201yams_2019 in /home/eydou/2019/Math/201yams_2019/src
**
** Made by Edouard.touch
** Login   <edouard.touch@epitech.eu>
**
** Started on  Tue Feb 11 4:06:47 PM 2020 Edouard.touch
** Last update Thu Feb 12 02:31:32 2020 alexis lopes
*/

#include "math.hpp"
#include <iomanip>
#include <algorithm>

double factorial(double nb)
{
    if (nb > 1) return nb * factorial(nb - 1); else return 1;
}

double getBinom(double a, double b)
{
    return (factorial(a) / (factorial(b) * factorial(a - b))) * pow((1.0 / 6.0), b) * pow((5.0 / 6.0), (a - b)) * 100;
}

void math::algoStraight()
{
    int diceToReroll = 5;
    int diceValue[4];
    int index = 0;
    bool sameNumber = false;
    int factorial = 1;
    double P;

    if (number1 == 5) {
        for (int i = 0; i < 5; i++) {
            for (int y = 1; y < 6; y++) {
                if (nbs[i] == y) {
                    for (int x = 0; x < index; x++) {
                        if (nbs[i] == diceValue[x])
                            sameNumber = true;
                    }
                    if (sameNumber == false) {
                        diceValue[index] = y;
                        index++;
                    }
                    sameNumber = false;
                }
            }
        }
    }
    else if (number1 == 6) {
        for (int i = 0; i < 5; i++) {
            for (int y = 2; y < 7; y++) {
                if (nbs[i] == y) {
                    for (int x = 0; x < index; x++) {
                        if (nbs[i] == diceValue[x])
                            sameNumber = true;
                    }
                    if (sameNumber == false) {
                        diceValue[index] = y;
                        index++;
                    }
                    sameNumber = false;
                }
            }
        }
    } else {
        exit (84);
    }
    
    diceToReroll = 5 - index;
    for (int i = diceToReroll; i > 0; i--)
        factorial = factorial * i;
    P = factorial / pow(6, diceToReroll) * 100;
    std::cout << "Chances to get a " << number1 << " straight: " << std::fixed << std::setprecision(2) << P << "%" << std::endl;
}

void math::algoFull()
{
    int threeTimes = std::count(nbs.begin(), nbs.end(), number1);
    int twoTimes = std::count(nbs.begin(), nbs.end(), number2);
    double a(0.0), b(0.0), result(0.0);

    twoTimes > 2 ? twoTimes = 2 : 0;
    threeTimes > 3 ? threeTimes = 3 : 0;
    if (threeTimes == 3 && twoTimes == 2)
        std::cout << "Chances to get a " << number1 << " " << combinaison << " of " << number2 << ": 100.00%" << std::endl;
    else {
        a = 3 - threeTimes;
        b = 5 - (threeTimes + twoTimes);
        result = factorial(b) / (factorial(a) * factorial(b - a)) / pow(6, b) * 100;
        std::cout << "Chances to get a " << number1 << " " << combinaison << " of " << number2 << ": "
        << std::fixed << std::setprecision(2) <<  result << "%" << std::endl;
    }
}

void math::algoDices(int combin)
{
    int times = std::count(nbs.begin(), nbs.end(), number1);
    double result(0);

    if ((times >= combin && combin == 2) || (times >= combin && combin == 5))
        std::cout << "Chances to get a " << number1 << " " << combinaison << ": 100.00%" << std::endl;
    else if ((times >= combin && combin == 3) || (times >= combin && combin == 4))
        std::cout << "Chances to get a " << number1 << " " << combinaison << "-of-a-kind" <<": 100.00%" << std::endl;
    else {
        for (int n = (combin - times); n < (6 - times); n++)
            result += getBinom(5 - times, n);
        if (combin == 2 || combin == 5)
            std::cout << "Chances to get a " << number1 << " " << combinaison << ": " << std::fixed << std::setprecision(2) << result << "%" << std::endl;
        else
            std::cout << "Chances to get a " << number1 << " " << combinaison << "-of-a-kind" << ": " << std::fixed << std::setprecision(2) << result << "%" << std::endl;
    }
    return;
}