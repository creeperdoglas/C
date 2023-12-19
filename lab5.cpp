// melgu374: Samarbetat med eliom790, Elias Omrane, samma program
#include <iostream>
#include <fstream>
#include "hero_handling.h"
#include "register_handling.h"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream infile(argv[1]);

  if (!infile or argc > 2)
  {
    string full_path(argv[0]);
    size_t last_slash = full_path.find_last_of("\\/");
    string filename = full_path.substr(last_slash + 1);
    cout << "Incorrect number of arguments!" << endl
         << "Usage: ./" << filename << " REGISTERFILE" << endl;
    return 1;
  }

  Register_Type reg;
  read(infile, reg);
  infile.close();

  string file_path = argv[1];
  show_menu(reg, file_path);

  return 0;
}