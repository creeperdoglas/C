#pragma once
#include <string>
#include <vector>
#include <set>
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

void findmatching(std::vector<hero_handling> &matchingHeroes, std::vector<int> interests, register_type &reg);
void matchingHeroes(register_type &reg);
void menuChoice(int choice, register_type &reg, const std::string &filePath);
void showMenu(register_type &reg, const std::string &filePath);
std::set<int> findInterestIntersection(const std::set<int> &heroInterests, const std::vector<int> &matchingInterests);
void printHero(const hero_handling &hero, const std::set<int> &intersection);
void printHeroes(const std::vector<hero_handling> &heroes, const std::vector<int> &matchingInterests);
void print(const std::vector<hero_handling> &heroes, const std::vector<int> &matchingInterests);