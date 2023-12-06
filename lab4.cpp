// melgu374: Samarbetat med eliom790, Elias Omrane, samma program
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "lab4.h"
using namespace std;

void GetInfo(vector<Deltagar_t> &vec)
{
  Deltagar_t Deltagar{};
  string rad;
  cout << "Mata in deltagare:" << endl;
  while (true)
  {
    // Läs in förnamn
    cin >> Deltagar.namn;
    if (Deltagar.namn == "KLAR")
    {
      break;
    }

    // Läs in efternamn
    cin >> Deltagar.efternamn;

    // // Rensa inmatningsbufferten
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Läs in resten av raden som klubb
    getline(cin, Deltagar.klubb);

    vec.push_back(Deltagar);
  }
}
void GetTime(vector<Deltagar_t> &vec)
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
void SortTimes(vector<Deltagar_t> &vec)
{
  for (size_t i = 0; i < vec.size(); ++i)
  {
    std::sort(vec[i].tider.begin(), vec[i].tider.end());
  }
}
bool CompareDeltagare(const Deltagar_t &a, const Deltagar_t &b)
{
  return a.tider.front() < b.tider.front();
}
void Print(const vector<Deltagar_t> &vec)
{

  // Headers
  cout << setw(1) << right << "Efternamn"
       << setw(10) << right << "Förnamn"
       << setw(23) << right << "Klubb: Tider" << endl;
  cout << string(42, '=') << endl;

  for (const auto &deltagare : vec)
  {
    cout << setw(9) << right << deltagare.efternamn
         << setw(10) << right << deltagare.namn
         << setw(16) << right << deltagare.klubb << ":";

    for (const auto &tid : deltagare.tider)
    {
      cout << " " << fixed << setprecision(2) << tid;
    }
    cout << endl;
  }
}

int main()
{
  vector<Deltagar_t> deltagare;
  GetInfo(deltagare);
  GetTime(deltagare);
  SortTimes(deltagare);
  sort(deltagare.begin(), deltagare.end(), CompareDeltagare);
  Print(deltagare);

  return 0;
}