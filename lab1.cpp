#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int I;
	string S;
	double F;
	char T;

	// cout << "Skriv in ett heltal: ";
	// cin >> I;
	// fflush(stdin);
	// cout << "Du skrev in heltalet " << I << endl;

	// cout << "skriv in fem heltal: ";
	// cin >> I;
	// cout << "Du skrev in heltalen: ";
	// cout << I;
	// cout << " ";
	// cin >> I;
	// cout << I;
	// cout << " ";
	// cin >> I;
	// cout << I;
	// cout << " ";
	// cin >> I;
	// cout << I;
	// cout << " ";
	// cin >> I;
	// fflush(stdin);
	// cout << I;

	// cout << "Skriv in ett flyttal: ";
	// cin >> F;
	// fflush(stdin);
	// F = std::round(F * 1000.0) / 1000.0;
	// cout << "Du skrev in flyttalet " << F << endl;

	cout << "Skriv in ett heltal och ett flyttal: ";
	cin >> I;
	cin >> F;
	fflush(stdin);
	cout << "Du skrev in heltalet ";
	cout << right << setw(6) << I << endl;
	cout << "Du skrev in flyttalet	" << std::setprecision(4) << std::fixed;
	cout << right << setw(6) << F << endl;

	cout << "Skriv in ett flyttal och ett heltal: ";
	cin >> F;
	cin >> I;
	cout << "Du skrev in heltalet";
	cout << setfill('-') << setw(9) << I << setfill(' ') << endl;
	cout << "Du skrev in flyttalet	";
	cout << setfill('-') << setw(9) << F << setfill(' ') << endl;

	cout << "Skriv in ett tecken: ";
	cin >> T;
	cout << "Du skev in tecknet " << T << endl;

	cout << "Skriv in ett ord: ";
	cin >> S;
	cout << "Du skrev in ordet " << S << endl;

	cout << "Skriv in ett heltal och ett ord: ";
	cin >> I;
	cin >> S;
	cout << "Du matade in talet |" << I << "| och ordet |" << S << "|." << endl;

	cout << "Skriv in ett tecken och ett ord: ";
	cin >> T;
	cin >> S;
	cout << "Du skrev in \"" << S << "\" och \"" << T << "\"." << endl;

	cout << "Skriv in ett ord och ett tecken: ";
	cin >> S;
	cin >> T;
	cout << "Du skrev in \"" << S << "\" och \"" << T << "\"." << endl;

	cout << "Skriv in en textrad: ";
	getline(cin, S);
	cout << "Du skrev in \"" << S << "\"." << endl;

	cout << "Skriv in en till rad text: ";
	getline(cin, S);
	cout << "Du skrev in \"" << S << "\"." << endl;

	cout << "skriv in en rad med tre ord";
	cin >> S;
	cout << "Du skrev in \"" << S << "\",";
	cin >> S;
	cout << "\"" << S << "\" och ";
	cin >> S;
	cout << "\"" << S << "\"." << endl;

	return 0;
}
