#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "hero_handling.h"
using namespace std;

void print(hero_handling &hero)
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
       << hero.hairC
       << setw(47) << right
       << hero.interests
       << endl;
}