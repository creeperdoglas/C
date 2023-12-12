#include <string>
#include <vector>
#include "register_handling.cc"
struct hero_handling
{
  std::string name;
  int birthyear;
  float weight;
  std::string hairC;
  std::vector<int> interests;

} hero;

void print(hero_saved &hero);