#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include "hero_handling.h"

// Forward declaration of structures
struct hero_handling;
struct register_type
{
  std::vector<hero_handling> list_heroes;
};

void read(std::ifstream &infile, register_type &reg);
std::vector<hero_handling> readHeroesFromFile(const std::string &filePath);
void writeSortedHeroesToFile(const std::string &filePath, const std::vector<hero_handling> &heroes);
void printCleanFilePath(const std::string &filePath);

std::string removeDotSlash(const std::string &filePath);
void addNewHero(register_type &reg, const std::string &filePath);

hero_handling promptForHeroInformation();
bool isHeroInRegister(const register_type &reg, const hero_handling &hero);
void appendHeroToFile(const std::string &filePath, const hero_handling &hero);
void updateRegisterFromFile(register_type &reg, const std::string &filePath);
