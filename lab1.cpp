#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int I;
	string S;
	double F;
	char T;

	// cout << "Skriv in ett heltal: ";
	// cin >> I;
	// cout << "Du skrev in heltalet " << I << endl;

	// cout << "skriv in fem heltal: ";
	// cin >> I;
	// cout << "Du skrev in: ";
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
	// cout << I;
	// cout << "." << endl;

	// cout << "Skriv in ett flyttal: ";
	// cin >> F;
	// cout << "Du skrev in flyttalet " << F << endl;

	// cout << "Skriv in ett heltal och ett flyttal: ";
	// cin >> I;
	// cin >> F;
	// cout << "Du skrev in heltalet ";
	// cout << setw(9) << I << endl;
	// cout << "Du skrev in flyttalet	";
	// cout << setw(9) << F << endl;

	// cout << "Skriv in ett flyttal och ett heltal: ";
	// cin >> F;
	// cin >> I;
	// cout << "Du skrev in heltalet";
	// cout << setfill('-') << setw(9) << I << setfill(' ') << endl;
	// cout << "Du skrev in flyttalet	";
	// cout << setfill('-') << setw(9) << F << setfill(' ') << endl;

	// cout << "Skriv in ett tecken: ";
	// cin >> T;
	// cout << "Du skev in tecknet " << T << endl;

	// cout << "Skriv in ett ord: ";
	// cin >> S;
	// cout << "Du skrev in ordet " << S << endl;

	// cout << "Skriv in ett heltal och ett ord: ";
	// cin >> I;
	// cin >> S;
	// cout << "Du matade in talet |" << I << "| och ordet |" << S << "|." << endl;

	// cout << "Skriv in ett tecken och ett ord: ";
	// cin >> T;
	// cin >> S;
	// cout << "Du skrev in \"" << S << "\" och \"" << T << "\"." << endl;

	// cout << "Skriv in ett ord och ett tecken: ";
	// cin >> S;
	// cin >> T;
	// cout << "Du skrev in \"" << S << "\" och \"" << T << "\"." << endl;

	cout << "Skriv in en textrad: ";
	cin >> S;
	cout << "Du skrev in \"" << S << "\"." << endl;

	cout << "Skriv in en till rad text: ";
	cin >> S;
	cout << "Du skrev in \"" << S << "\"." << endl;

	cout << "skriv in en rad med tre ord";
	cin >> S;
	cout << "Du skrev in \"" << S << "\",";
	cin >> S;
	cout << " \"" << S << "\" och ";
	cin >> S;
	cout << ", \"" << S << "\"." << endl;

	return 0;
}
