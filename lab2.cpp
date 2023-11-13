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
  //del 1
  double start;
  double stop;
  string ord;
  int letterCount = 0, digitCount = 0, whitespaceCount = 0;
  string word, shortestWord, longestWord;
  int wordCount = 0;
  int totalLength = 0;

  cout << "Del 1: Tempraturtabell" << endl;
  cout << "Ange startvärde: ";
  cin >> start;

  do
  {
    cout << "Ange slutvärde: ";
    cin >> stop;

    if (start > stop)
    {
      cout << "Felaktigt värde!" << endl;
    }
  } while (start > stop);

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

  for (int i = start; i <= stop; i++)
  {
    cout << setprecision(2) << fixed << setw(7) << (i);
    cout << setprecision(2) << fixed << setw(I) << (i + 273.15);
    cout << setprecision(2) << fixed << setw(I) << (i * 1.8 + 32);
    cout << setprecision(2) << fixed << setw(I) << (i * 0.8) << endl;
  }
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
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  // del 2
  cout << "Del 2: Teckenhantering" <<endl;
  char buffer[11];      
  cin.read(buffer, 10); // läs bara 10 characters
  buffer[10] = '\0';    
  ord = string(buffer);

  for (char c : ord)
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
  cout << "Alfabetiska tecken: " << letterCount << endl;
  cout << "Siffertecken......: " << digitCount << endl;
  cout << "Vita tecken.......: " << whitespaceCount << endl;
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
//del 3
cout<< "Del 3: Ordhantering " << endl << "Mata in en text: "<< endl;
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
    cerr << "Inga ord matades in." << endl; //cerr = standard error stream istället för standard output stream, mindre delay
    return 1; // Error exit
}

double averageLength = static_cast<double>(totalLength) / wordCount;

cout << "Texten innehöll " << wordCount << " ord." << endl;
cout << "Det kortaste order var \"" << shortestWord << "\"  med " << shortestWord.length() << " tecken." << endl;
cout << "Det längsta order var \"" << longestWord << "\"  med " << longestWord.length() << " tecken." << endl;
cout << "Medelordlängden var  " << std::setprecision(1) << std::fixed << averageLength <<" tecken." << endl;

return 0;
} 