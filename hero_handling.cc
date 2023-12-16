// melgu374: Samarbetat med eliom790, Elias Omrane, samma program
#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include "hero_handling.h"

using namespace std;

void findmatching(vector<hero_handling> &matchingHeroes, vector<int> interests, register_type &reg)
{
  for (auto &hero : reg.list_heroes)
  {
    for (int heroInterest : hero.interests)
    {
      if (find(interests.begin(), interests.end(), heroInterest) != interests.end())
      {
        matchingHeroes.push_back(hero);
        break;
      }
    }
  }
}

void findAndPrintMatchingHeroes(register_type &reg)
{
  cout << "Enter your interests (at least one between 1 and 15): ";
  while (true)
  {
    string inputLine;
    getline(cin, inputLine);
    vector<int> interests;
    istringstream iss(inputLine);
    int interest;
    bool validInput = true;

    while (iss >> interest)
    {
      if (interest < 1 || interest > 15)
      {
        validInput = false;
        break;
      }
      interests.push_back(interest);
    }

    if (!validInput || interests.empty())
      continue;

    vector<hero_handling> matchingHeroes;
    findmatching(matchingHeroes, interests, reg);

    cout << "There are " << matchingHeroes.size() << " matching heroes." << endl;
    print(matchingHeroes, interests);
    break;
  }
}

void menuChoice(int choice, register_type &reg, const std::string &filePath)
{
  switch (choice)
  {
  case 1:
    addNewHero(reg, filePath);
    break;
  case 2:
    findAndPrintMatchingHeroes(reg);
    break;
  case 3:
    cout << "Terminating Hero Matchmaker 3000!" << endl;
    break;
  }
}

void showMenu(register_type &reg, const std::string &filePath)
{
  cout << "Welcome to Hero Matchmaker 3000!" << endl;
  int choice{};
  do
  {
    cout << "1) Add new hero to register file\n";
    cout << "2) Find matching heroes\n";
    cout << "3) Quit program\n";
    do
    {
      cout << "Select: ";
      if (!(cin >> choice))
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      menuChoice(choice, reg, filePath);
    } while (choice < 1 or choice > 3);
  } while (choice != 3);
}

set<int> findInterestIntersection(const set<int> &heroInterests, const vector<int> &matchingInterests)
{
  set<int> interests(matchingInterests.begin(), matchingInterests.end());
  set<int> intersection;
  set_intersection(heroInterests.begin(), heroInterests.end(), interests.begin(), interests.end(), inserter(intersection, intersection.begin()));
  return intersection;
}
void printHero(const hero_handling &hero, const set<int> &intersection)
{
  cout << left << setw(11) << hero.name
       << setw(12) << hero.birthyear
       << setw(8) << fixed << setprecision(2) << hero.weight;

  if (!hero.interests.empty() && hero.interests[0] < 10)
  {
    cout << left << setw(14) << hero.hairC;
  }
  else
  {
    cout << left << setw(13) << hero.hairC;
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
void printHeroes(const vector<hero_handling> &heroes, const vector<int> &matchingInterests)
{
  for (auto &hero : heroes)
  {
    set<int> heroInterests(hero.interests.begin(), hero.interests.end());
    set<int> intersection = findInterestIntersection(heroInterests, matchingInterests);
    if (!intersection.empty())
    {
      printHero(hero, intersection);
    }
  }
}

void print(const vector<hero_handling> &heroes, const vector<int> &matchingInterests)
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
  printHeroes(heroes, matchingInterests);
}
