// melgu374: Samarbetat med eliom790, Elias Omrane, samma program
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "lab4.h"
using namespace std;

void get_info(vector<Deltagar_Type> &vec)
{
  Deltagar_Type deltagar{};
  string rad;
  cout << "Mata in deltagare:" << endl;
  while (true)
  {
    // Läs in förnamn
    cin >> deltagar.namn;
    if (deltagar.namn == "KLAR")
    {
      break;
    }

    // Läs in efternamn
    cin >> deltagar.efternamn;

    // // Rensa inmatningsbufferten
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Läs in resten av raden som klubb
    getline(cin, deltagar.klubb);

    vec.push_back(deltagar);
  }
}
void get_time(vector<Deltagar_Type> &vec)
{
  for (size_t i = 0; i < vec.size(); ++i)
  {
    cout << "Tider " << vec[i].namn << ": ";

    double times{};
    while (cin >> times && times != -1.00)
    {
      vec[i].tider.push_back(times);
    }
  }
}
void sort_times(vector<Deltagar_Type> &vec)
{
  for (size_t i = 0; i < vec.size(); ++i)
  {
    sort(vec[i].tider.begin(), vec[i].tider.end());
  }
}
void print(const vector<Deltagar_Type> &vec)
{
  // Headers
  cout << setw(1) << right << "Efternamn"
       << setw(11) << right << "Förnamn"
       << setw(23) << right << "Klubb: Tider" << endl;
  cout << string(42, '=') << endl;

  for (size_t i = 0; i < vec.size(); ++i)
  {
    const Deltagar_Type &deltagare = vec.at(i);
    cout << setw(9) << right << deltagare.efternamn
         << setw(10) << right << deltagare.namn
         << setw(16) << right << deltagare.klubb << ":";

    for (size_t j = 0; j < deltagare.tider.size(); ++j)
    {
      cout << " " << fixed << setprecision(2) << deltagare.tider.at(j);
    }
    cout << endl;
  }
}

int main()
{
  vector<Deltagar_Type> deltagare;
  get_info(deltagare);
  get_time(deltagare);
  sort_times(deltagare);
  sort(deltagare.begin(), deltagare.end());
  print(deltagare);

  return 0;
}