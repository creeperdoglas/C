// melgu374: Samarbetat med eliom790, Elias Omrane, samma program
#include <iostream>
#include <fstream>
#include "hero_handling.h"
#include "register_handling.h"

using namespace std;

int main(int argc, char *argv[])
{
  std::ifstream infile(argv[1]);

  if (!infile or argc > 1)
  {
    std::string fullPath(argv[0]);
    size_t lastSlash = fullPath.find_last_of("\\/");
    std::string filename = fullPath.substr(lastSlash + 1);
    std::cerr << "Incorrect number of arguments!" << std::endl
              << "Usage: ./" << filename << " REGISTERFILE" << std::endl;
    return 1;
  }

  register_type reg;
  read(infile, reg);
  infile.close();

  std::string filePath = argv[1];
  showMenu(reg, filePath);

  return 0;
}