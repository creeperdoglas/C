// melgu374: Arbetat enskilt
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
	int I;
	string S;
	double F;
	char T;

	cout << "Skriv in ett heltal: ";
	cin >> I;
	cout << "Du skrev in heltalet: " << I << endl;
	cout << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in fem heltal: ";
	cin >> I;
	cout << "Du skrev in heltalen: ";
	cout << I;
	cout << " ";
	cin >> I;
	cout << I;
	cout << " ";
	cin >> I;
	cout << I;
	cout << " ";
	cin >> I;
	cout << I;
	cout << " ";
	cin >> I;
	cout << I << endl;
	cout << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in ett flyttal: ";
	cin >> F;
	// F = std::round(F * 1000.0) / 1000.0;
	cout << "Du skrev in flyttalet: " << std::setprecision(3) << std::fixed << F << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in ett heltal och ett flyttal: ";
	cin >> I;
	cin >> F;
	cout << "Du skrev in heltalet:";
	cout << setw(10) << I << endl;
	cout << "Du skrev in flyttalet:";
	cout << setw(9) << std::setprecision(4) << std::fixed << F << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in ett flyttal och ett heltal: ";
	cin >> F;
	cin >> I;
	cout << "Du skrev in heltalet:";
	cout << setfill('-') << setw(10) << I << setfill(' ') << endl;
	cout << "Du skrev in flyttalet:";
	cout << setfill('-') << setw(9) << std::setprecision(4) << std::fixed << F << setfill(' ') << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in ett tecken: ";
	cin >> T;
	cout << "Du skrev in tecknet: " << T << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in ett ord: ";
	cin >> S;
	cout << "Du skrev in ordet: " << S << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in ett heltal och ett ord: ";
	cin >> I;
	cin >> S;
	cout << "Du skrev in heltalet |" << I << "| och ordet |" << S << "|." << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in ett tecken och ett ord: ";
	cin >> T;
	cin >> S;
	cout << "Du skrev in \"" << S << "\" och \"" << T << "\"." << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in ett ord och ett tecken: ";
	cin >> S;
	cin >> T;
	cout << "Du skrev in \"" << S << "\" och \"" << T << "\"." << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in en textrad: ";
	getline(cin, S);
	cout << "Du skrev in \"" << S << "\"." << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in en till rad text: ";
	getline(cin, S);
	cout << "Du skrev in \"" << S << "\"." << endl;
	cout << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Skriv in en rad med tre ord: ";
	cin >> S;
	cout << "Du skrev in: \"" << S << "\",";
	cin >> S;
	cout << " \"" << S << "\" och ";
	cin >> S;
	cout << "\"" << S << "\"." << endl;

	return 0;
}
