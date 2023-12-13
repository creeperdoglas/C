#pragma once
#include <fstream>
#include <vector>
#include "hero_handling.h"
struct hero_handling; // Forward declaration
struct register_type
{
  std::vector<hero_handling> list_heroes;
};
void read(std::ifstream &infile, register_type &reg);