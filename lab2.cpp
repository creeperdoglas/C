// melgu374: Arbetat enskilt
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  double start;
  double slut;

  cout << "Ange startvärde: ";
  cin >> start;

  do
  {
    cout << "Ange slutvärde: ";
    cin >> slut;
  } while (start > slut);

  int I = 12;
  cout << setprecision(2) << setw(7) << "Celsius";
  cout << setprecision(2) << fixed << setw(I) << "Kelvin";
  cout << setprecision(2) << fixed << setw(I) << "Farenheit";
  cout << setprecision(2) << fixed << setw(I) << "Réaumur" << endl;
  for (int i = 0; i < (I * 3 + 7); i++)
  {
    if (i < ((I * 3 + 7) - 1))
    {
      cout << "-";
    }
    else
    {
      cout << "-" << endl;
    }
  }

  for (int i = start; i <= slut; i++)
  {
    cout << setprecision(2) << fixed << setw(7) << (i);
    cout << setprecision(2) << fixed << setw(I) << (i + 273.15);
    cout << setprecision(2) << fixed << setw(I) << (i * 1.8 + 32);
    cout << setprecision(2) << fixed << setw(I) << (i * 0.8) << endl;
  }

  return 0;
}