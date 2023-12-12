#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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
    std::cerr << "Could not open file" << std::endl;
    return 1;
  }

  std::vector<hero_handling> hero_saved; // register handling

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