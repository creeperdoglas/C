// melgu374: Samarbetat med eliom790, Elias Omrane, samma program
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "register_handling.h"

using namespace std;

void read(std::ifstream &infile, register_type &reg)
{
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

void sortFileContents(const std::string &filePath)
{
  std::ifstream infile(filePath);
  std::vector<hero_handling> heroes;
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
    heroes.push_back(hero);
  }
  infile.close();
  std::sort(heroes.begin(), heroes.end(),
            [](const hero_handling &a, const hero_handling &b)
            {
              return a.name < b.name;
            });
  std::ofstream outfile(filePath);
  for (const auto &hero : heroes)
  {
    outfile << hero.name << " " << hero.birthyear << " " << hero.weight << " " << hero.hairC;
    for (int interest : hero.interests)
    {
      outfile << " " << interest;
    }
    outfile << std::endl;
  }
  outfile.close();
}

std::string removeDotSlash(const std::string &filePath)
{
  if (filePath.size() >= 2 && filePath[0] == '.' && filePath[1] == '/')
  {
    return filePath.substr(2);
  }
  return filePath;
}
void printCleanFilePath(const std::string &filePath)
{
  std::string cleanFilePath = removeDotSlash(filePath);
  std::cout << "The hero was added to the register on file " << cleanFilePath << std::endl;
}

void addNewHero(register_type &reg, const std::string &filePath)
{
  while (true)
  {
    cout << "Enter hero information:\n";
    hero_handling newHero = promptForHeroInformation();

    if (!isHeroInRegister(reg, newHero))
    {
      appendHeroToFile(filePath, newHero);
      sortFileContents(filePath);
      updateRegisterFromFile(reg, filePath);
      printCleanFilePath(filePath);
      break;
    }
    else
    {
      cout << "Hero already in register. Enter hero information:\n";
      newHero = promptForHeroInformation();
    }
  }
}
hero_handling promptForHeroInformation()
{
  string inputLine{};

  getline(cin, inputLine);
  istringstream iss(inputLine);
  hero_handling newHero;
  iss >> newHero.name >> newHero.birthyear >> newHero.weight >> newHero.hairC;
  int interest{};
  while (iss >> interest)
  {
    newHero.interests.push_back(interest);
  }
  return newHero;
}

bool isHeroInRegister(const register_type &reg, const hero_handling &hero)
{
  for (const auto &existingHero : reg.list_heroes)
  {
    if (existingHero.name == hero.name)
    {
      return true;
    }
  }
  return false;
}

void appendHeroToFile(const std::string &filePath, const hero_handling &hero)
{
  ofstream outfile(filePath.c_str(), ios::app);
  outfile << hero.name << " " << hero.birthyear << " " << hero.weight << " " << hero.hairC;
  for (int interest : hero.interests)
  {
    outfile << " " << interest;
  }
  outfile << endl;
  outfile.close();
}

void updateRegisterFromFile(register_type &reg, const std::string &filePath)
{
  std::ifstream infile(filePath);
  reg.list_heroes.clear();
  read(infile, reg);
  infile.close();
}
