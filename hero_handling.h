#pragma once
#include <string>
#include <vector>
#include "register_handling.h"

struct register_type;

struct hero_handling
{
  std::string name;
  int birthyear;
  float weight;
  std::string hairC;
  std::vector<int> interests;
};

void print(register_type &reg);