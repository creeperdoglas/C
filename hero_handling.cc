// melgu374: Samarbetat med eliom790, Elias Omrane, samma programRegister_Type
#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include "hero_handling.h"

using namespace std;

set<int> find_interest_intersection(const set<int> &hero_interests, const vector<int> &matching_interests)
{
  set<int> interests(matching_interests.begin(), matching_interests.end());
  set<int> intersection;
  set_intersection(hero_interests.begin(), hero_interests.end(), interests.begin(), interests.end(), inserter(intersection, intersection.begin()));
  return intersection;
}
void print_hero(const Hero_Type &hero, const set<int> &intersection)
{
  cout << left << setw(11) << hero.name << setw(12) << hero.birthyear
       << setw(8) << fixed << setprecision(2) << hero.weight;
  if (!hero.interests.empty() && hero.interests[0] < 10)
  {
    cout << left << setw(14) << hero.hair_colour;
  }
  else
  {
    cout << left << setw(13) << hero.hair_colour;
  }
  for (size_t i = 0; i < hero.interests.size(); ++i)
  {
    if (hero.interests[i] < 10 && (i + 1 < hero.interests.size() && hero.interests[i + 1] < 10))
    {
      cout << hero.interests[i] << "  ";
    }
    else if (i == hero.interests.size() - 1)
    {
      cout << hero.interests[i];
    }
    else
    {
      cout << hero.interests[i] << " ";
    }
  }
  cout << endl;
}
void print_heroes(const vector<Hero_Type> &heroes, const vector<int> &matching_interests)
{
  for (auto &hero : heroes)
  {
    set<int> hero_interests(hero.interests.begin(), hero.interests.end());
    set<int> intersection = find_interest_intersection(hero_interests, matching_interests);
    if (!intersection.empty())
    {
      print_hero(hero, intersection);
    }
  }
}

void print(const vector<Hero_Type> &heroes, const vector<int> &matching_interests)
{
  cout << "Hero name"
       << "  "
       << "Birth year"
       << "  "
       << "Weight"
       << "  "
       << "Hair color"
       << "  "
       << "Interests" << endl;
  cout << "====================================================" << endl;
  print_heroes(heroes, matching_interests);
}
