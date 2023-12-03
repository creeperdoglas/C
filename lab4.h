#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

struct Deltagar_t
{
  std::string namn;
  std::string efternamn;
  std::string klubb;
  std::vector<double> tider;
} Deltagar;

void GetInfo(std::vector<Deltagar_t> &vec);
void GetTime(std::vector<Deltagar_t> &vec);
void SortTimes(std::vector<Deltagar_t> &vec);
bool CompareDeltagare(const Deltagar_t &a, const Deltagar_t &b);
void Print(const std::vector<Deltagar_t> &vec);

#endif