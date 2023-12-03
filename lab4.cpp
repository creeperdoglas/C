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

void Print(const std::vector<Deltagar_t> &vec)
{
  int maxFirstNameLength = std::string("Förnamn").length();
  int maxLastNameLength = std::string("Efternamn").length();
  int maxClubLength = std::string("Klubb").length();

  for (const auto &deltagare : vec)
  {
    maxFirstNameLength = std::max(maxFirstNameLength, static_cast<int>(deltagare.namn.length()));
    maxLastNameLength = std::max(maxLastNameLength, static_cast<int>(deltagare.efternamn.length()));
    maxClubLength = std::max(maxClubLength, static_cast<int>(deltagare.klubb.length()));
  }

  std::cout << std::right << std::setw(maxLastNameLength) << "Efternamn"
            << std::setw(4) << ""
            << std::right << std::setw(maxFirstNameLength) << "Förnamn"
            << std::setw(10) << ""
            << std::right << std::setw(maxClubLength) << "Klubb"
            << ": Tider" << std::endl;
  std::cout << std::string(maxLastNameLength + 4 + maxFirstNameLength + 10 + maxClubLength + 7, '=') << std::endl;

  for (const auto &deltagare : vec)
  {
    std::cout << std::right << std::setw(maxLastNameLength) << deltagare.efternamn
              << std::setw(4) << ""
              << std::right << std::setw(maxFirstNameLength) << deltagare.namn
              << std::setw(10) << ""
              << std::right << std::setw(maxClubLength) << deltagare.klubb
              << ": ";
    for (const auto &tid : deltagare.tider)
    {
      std::cout << std::left << std::fixed << std::setprecision(2) << tid << " ";
    }
    std::cout << std::endl;
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