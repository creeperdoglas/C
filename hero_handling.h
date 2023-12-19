#pragma once
#include <string>
#include <vector>
#include <set>

struct Hero_Type
{
  std::string name;
  int birthyear;
  float weight;
  std::string hair_colour;
  std::vector<int> interests;
};

std::set<int> find_interest_intersection(const std::set<int> &hero_interests, const std::vector<int> &matching_interests);
void print_hero(const Hero_Type &hero, const std::set<int> &intersection);
void print_heroes(const std::vector<Hero_Type> &heroes, const std::vector<int> &matching_interests);
void print(const std::vector<Hero_Type> &heroes, const std::vector<int> &matching_interests);