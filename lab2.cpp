// melgu374: Arbetat enskilt
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <string>
#include <limits>
using namespace std;

int main()
{
  // del 1
  cout << "Del 1: Temperaturtabell" << endl;

  double start, stop;
  do
  {
    cout << "Ange startvärde: ";
    cin >> start;
    if (start < -273.15)
    {
      cout << "Felaktigt startvärde!" << endl;
    }
  } while (start < -273.15);

  do
  {
    cout << "Ange slutvärde: ";
    cin >> stop;
    if (start > stop)
    {
      cout << "Felaktigt slutvärde!" << endl;
    }
  } while (start > stop);

  cout << setprecision(2) << setw(7) << "Celsius"
       << setw(9) << "Kelvin"
       << setw(13) << "Fahrenheit"
       << setw(10) << "Reaumur" << endl;

  for (int i = 0; i < 7 + 9 + 13 + 10; i++)
    cout << "-";
  cout << endl;

  for (int i = start; i <= stop; i++)
  {
    cout << setprecision(2) << fixed << setw(7) << right << (i)
         << setw(9) << (i + 273.15)
         << setw(13) << (i * 1.8 + 32)
         << setw(10) << (i * 0.8) << endl;
  }

  for (int i = 0; i < 7 + 9 + 13 + 10; i++)
    cout << "-";
  cout << endl
       << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // del 2
  cout << "Del 2: Teckenhantering" << endl;
  char buffer[11];
  int letterCount = 0, digitCount = 0, whitespaceCount = 0;

  for (int i = 0; i < 10; ++i)
  {
    buffer[i] = cin.get();
    if (buffer[i] == '\n')
    {
      buffer[i] = '\0';
      break;
    }
  }
  buffer[10] = '\0'; // Null-terminate string

  string word(buffer);
  for (char c : word)
  {
    if (isalpha(c))
      letterCount++;
    else if (isdigit(c))
      digitCount++;
    else if (isspace(c))
      whitespaceCount++;
  }

  cout << "Texten innehöll:" << endl
       << "Alfabetiska tecken:" << letterCount << endl
       << "Siffertecken......:" << digitCount << endl
       << "Vita tecken.......:" << whitespaceCount << endl
       << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // del 3
  cout << "Del 3: Ordhantering" << endl
       << "Mata in en text:" << endl
       << endl;

  int wordCount = 0, totalLength = 0;
  string shortestWord, longestWord;

  while (cin >> word)
  {
    wordCount++;
    totalLength += word.length();

    if (wordCount == 1 || word.length() < shortestWord.length())
      shortestWord = word;

    if (wordCount == 1 || word.length() > longestWord.length())
      longestWord = word;
  }

  if (wordCount == 0)
  {
    cout << "Inga ord matades in." << endl;
    return 1;
  }

  double averageLength = static_cast<double>(totalLength) / wordCount;
  cout << "Texten innehöll " << wordCount << " ord." << endl
       << "Det kortaste ordet var \"" << shortestWord << "\" med " << shortestWord.length() << " tecken." << endl
       << "Det längsta ordet var \"" << longestWord << "\" med " << longestWord.length() << " tecken." << endl
       << "Medelordlängden var " << setprecision(1) << fixed << averageLength << " tecken." << endl;

  return 0;
}
