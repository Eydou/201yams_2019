/*
** math.hpp for 201yams_2019 in /home/eydou/2019/Math/201yams_2019/include
**
** Made by Edouard.touch
** Login   <edouard.touch@epitech.eu>
**
** Started on  Mon Feb 10 2:49:07 PM 2020 Edouard.touch
** Last update Thu Feb 12 1:18:18 AM 2020 Edouard.touch
*/

#ifndef MATH_HPP_
# define MATH_HPP_

#include <iostream>
#include <string>
#include <math.h>
#include <bits/stdc++.h>

class math {
    public:
        void algoDices(int);
        void algoFull();
        void algoStraight();
        void checkAlgo();
        math(char *, char **);
        ~math() = default;
    protected:
        std::string combinaison;
        int number1;
        int number2;
        std::vector<int> nbs;
};

#endif /* !MATH_HPP_ */