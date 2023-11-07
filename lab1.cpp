#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int I;
	string S;
	double F;

	cout << "Mata in ett heltal" << endl;
	cin >> I;
	cout << "Du matade in hetalet" << I << endl;

	cout << "Mata in ett heltal och ett ord: " << endl;
	cin >> I;
	cin >> S;
	cout << "Du matade in talet |" << I << "| och ordet |" << S << "|." << endl;

	cout << "Mata in fem heltal: ";
	cin >> I;
	cout << "Du matade in: ";
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
	cout << I;
	cout << "." << endl;

	cout << "Mata in ett flyttal: ";
	cin >> F;
	cout << "Du skrev in talet " << F << "." << endl;

	cout << "Skriv in ett heltal och ett flyttal: ";
	cin >> I;
	cin >> F;
	cout << "Du skrev in heltalet ";
	cout << setw(9) << I << endl;
	cout << "Du skrev in flyttalet	";
	cout << setw(5) << F << endl;

	return 0;
}
