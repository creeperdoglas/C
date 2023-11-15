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
  double start;
  double stop;
  string word;
  int letterCount = 0, digitCount = 0, whitespaceCount = 0;
  string shortestWord, longestWord;
  int wordCount = 0;
  int totalLength = 0;

  cout << "Del 1: Temperaturtabell" << endl;
  cout << "Ange startvärde: ";
  cin >> start;

  do
  {
    cout << "Ange slutvärde: ";
    cin >> stop;

    if (start > stop)
    {
      cout << "Felaktigt slutvärde!" << endl;
    }
  } while (start > stop);

  int I = 9;
  cout << setprecision(2) << setw(7) << "Celsius";
  cout << setprecision(2) << setw(9) << "Kelvin";          
  cout << setprecision(2) << setw(13) << "Fahrenheit";      
  cout << setprecision(2) << setw(11) << "Réaumur" << endl; 
  for (int i = 0; i < 7 + 9 + 13 + 11; i++)                
  {
    cout << "-";
  }
  cout << endl;

  for (int i = start; i <= stop; i++)
  {
    cout << setprecision(2) << fixed << setw(7) << right << (i);            
    cout << setprecision(2) << fixed << setw(9) << right << (i + 273.15);   
    cout << setprecision(2) << fixed << setw(13) << right << (i * 1.8 + 32); 
    cout << setprecision(2) << fixed << setw(11) << right << (i * 0.8) << endl;
  }
  for (int i = 0; i < 7 + 9 + 13 + 11; i++)
  {
    cout << "-";
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;
  // del 2
  cout << "Del 2: Teckenhantering" << endl;
  char buffer[11];
  cin.read(buffer, 10); // läs bara 10 characters
  buffer[10] = '\0';
  word = string(buffer);

  for (char c : word)
  {
    if (isalpha(c))
    {
      letterCount++;
    }
    else if (isdigit(c))
    {
      digitCount++;
    }
    else if (isspace(c))
    {
      whitespaceCount++;
    }
  }
  cout << "Texten innehöll:" << endl;
  cout << "Alfabetiska tecken:" << letterCount << endl;
  cout << "Siffertecken......:" << digitCount << endl;
  cout << "Vita tecken.......:" << whitespaceCount << endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;
  // del 3
  cout << "Del 3: Ordhantering" << endl
       << "Mata in en text:" << endl;
  cout << endl;
  while (cin >> word)
  {
    wordCount++;
    totalLength += word.length();

    if (wordCount == 1 || word.length() < shortestWord.length())
    {
      shortestWord = word;
    }

    if (wordCount == 1 || word.length() > longestWord.length())
    {
      longestWord = word;
    }
  }

  if (wordCount == 0)
  {
    cerr << "Inga ord matades in." << endl; // cerr = standard error stream istället för standard output stream, mindre delay
    return 1;                               // Error exit
  }

  double averageLength = static_cast<double>(totalLength) / wordCount;

  cout << "Texten innehöll " << wordCount << " ord." << endl;
  cout << "Det kortaste ordet var \"" << shortestWord << "\"  med " << shortestWord.length() << "tecken." << endl;
  cout << "Det längsta ordet var \"" << longestWord << "\"  med " << longestWord.length() << "tecken." << endl;
  cout << "Medelordlängden var  " << std::setprecision(1) << std::fixed << averageLength << " tecken." << endl;

  return 0;
}