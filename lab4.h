#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

struct Deltagar_Type
{
  std::string namn;
  std::string efternamn;
  std::string klubb;
  std::vector<double> tider;

} Deltagar;

bool operator<(const Deltagar_Type &lhs, const Deltagar_Type &rhs)
{
  // Compare the first times in the tider vectors
  return lhs.tider.front() < rhs.tider.front();
}

void get_info(std::vector<Deltagar_Type> &vec);
void get_time(std::vector<Deltagar_Type> &vec);
void sort_times(std::vector<Deltagar_Type> &vec);
void print(const std::vector<Deltagar_Type> &vec);

#endif