#include <iostream>
#include <fstream>
#include "hero_handling.h"
#include "register_handling.h"

using namespace std;

int main(int argc, char *argv[])
{
  //   if (argc != 2)
  //   {
  //     std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
  //     return 1;
  //   }
  std::ifstream infile(argv[1]);
  if (!infile)
  {
    // Extract the filename from argv[0]
    std::string fullPath(argv[0]);
    size_t lastSlash = fullPath.find_last_of("\\/");
    std::string filename = fullPath.substr(lastSlash + 1);
    std::cerr << "Incorrect number of arguments!" << std::endl
              << "Usage: " << filename << " REGISTERFILE" << std::endl;

    return 1;
  }
  register_type reg;
  read(infile, reg);
  print(reg);

  // for (const auto &hero : hero_saved)
  // {
  //   std::cout << hero.name << hero.birthyear << hero.weight << hero.hairC;
  //   for (const auto &interest : hero.interests)
  //   {
  //     std::cout << interest << " ";
  //   }
  //   std::cout << std::endl;
  // }

  return 0;
}