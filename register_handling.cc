#include <sstream>
#include "register_handling.h"
void read(std::ifstream &infile, register_type &reg)
{
  // register handling

  std::string line;
  while (std::getline(infile, line))
  {
    std::istringstream iss(line);
    hero_handling hero;
    iss >> hero.name >> hero.birthyear >> hero.weight >> hero.hairC;

    int interest;
    while (iss >> interest)
    {
      hero.interests.push_back(interest);
    }

    reg.list_heroes.push_back(hero);
  }
}