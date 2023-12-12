#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "hero_handling.h"
#include "register_handling.cc"
using namespace std;

void print(hero_saved &hero)
{
  for (auto &a : hero)
  {
    cout << "Hero name"
         << "   "
         << "Birth year"
         << "   "
         << "Weight"
         << "   "
         << "Hair color"
         << "   "
         << "Interests"
         << endl;

    cout << hero.name
         << setw(12) << right
         << hero.birthyear
         << setw(25) << right
         << hero.weight
         << setw(36) << right
         << hero.hairC;

    // Handle the printing of the interests vector
    cout << setw(47) << right;
    for (int interest : hero.interests)
    {
      cout << interest << " ";
    }
    cout << endl;
  }
}
