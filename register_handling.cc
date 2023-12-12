#include "register_handling.h"
#include "hero_handling.h"
std::vector<hero_handling> read(std::ifstream &infile)
{
  std::vector<hero_handling> hero_saved; // register handling

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

    hero_saved.push_back(hero);
  }
  return hero_saved;
}