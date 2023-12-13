#include <iostream>
#include <iomanip>
#include "hero_handling.h"

using namespace std;

void print(register_type &reg)
{
  // Print headers with fixed spaces
  cout << "Hero name"
       << "   " // 3 spaces
       << "Birth year"
       << "   "
       << "Weight"
       << "   "
       << "Hair color"
       << "   "
       << "Interests" << endl;

  // Column widths based on expected data length
  const int nameWidth = 20;
  const int yearWidth = 10;
  const int weightWidth = 10;
  const int hairColorWidth = 15;
  const int interestsWidth = 30;

  for (auto &a : reg.list_heroes)
  {
    // Print data with right alignment and specific width
    cout << left << setw(12) << a.name
         << setw(13) << a.birthyear // Add 3 to each width for the spaces
         << setw(9) << a.weight;

    // Handle the printing of the interests vector
    if (!a.interests.empty() && a.interests[0] < 10)
    {
      cout << left << setw(14) << a.hairC;
    }
    else
    {
      cout << left << setw(13) << a.hairC;
    }

    cout << setw(1) << left; // Additional 3 for the spaces
    for (int interest : a.interests)
    {
      cout << interest << " ";
    }
    cout << endl;
  }
}