// melgu374: Samarbetat med eliom790, Elias Omrane, samma program
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int fakultet(int n)
{
    int value{1};

    if (n == 0)
    {
        return 1;
    }

    for (int i{2}; i <= n; i++)
    {
        value *= i;
    }

    return value;
};

string multiple_words(string text, int multiplier)
{
    string return_val;
    for (int i = 0; i < multiplier; ++i)
    {
        return_val += text;
    }
    return return_val;
};

void swap(int &a, float &b)
{
    int storage{a};
    a = ceil(b);
    b = storage;

    cout << "Heltalets värde är nu " << a << endl;
    cout << "Flyttalets värde är nu " << fixed << setprecision(1) << b << endl;
}

void length(const string &text_1, const string &text_2, int &total_length, float &mean_length)
{
    total_length = text_1.size() + text_2.size();
    mean_length = static_cast<float>(total_length) / 2.0;
}

void automate_one()
{
    int n{};
    cout << "Mata in ett heltal: ";
    cin >> n;
    cout << "Fakulteten av " << n << " är " << fakultet(n) << endl;
}

void automate_two()
{
    int multiplier{};
    string text;
    cout << "Mata in en text och ett heltal: ";
    cin >> text;
    cin >> multiplier;
    cout << "Den multiplicerade texten är " << multiple_words(text, multiplier) << endl;
}

void automate_three()
{
    int a{};
    float b{};
    cout << "Mata in ett heltal och ett flyttal: ";
    cin >> a;
    cin >> b;
    swap(a, b);
}

void automate_four()
{
    string text_1;
    string text_2;
    int total_length{};
    float mean_length{};
    cout << "Mata in två ord: ";
    cin >> text_1;
    cin >> text_2;
    length(text_1, text_2, total_length, mean_length);

    cout << "Totallängd: " << total_length << endl;
    cout << "Medellängd: " << fixed << setprecision(1) << mean_length << endl;
}

int main()
{
    int num{};
    cout << "Välkommen till huvudmenyn!" << endl;
    while (num != 5)
    {
        cout << "1. Beräkna N-fakultet." << endl
             << "2. Multiplicera en sträng." << endl
             << "3. Byta värden på ett heltal och ett flyttal." << endl
             << "4. Beräkna totala längden samt medellängden på två strängar." << endl
             << "5. Avsluta programmet." << endl
             << "Val: ";
        cin >> num;
        if ((num < 1) or (num > 5))
        {
            cout << "Fel val!" << endl;
        }

        if (num == 1)
        {
            automate_one();
        }

        if (num == 2)
        {
            automate_two();
        }

        if (num == 3)
        {
            automate_three();
        }

        if (num == 4)
        {
            automate_four();
        }
    }

    cout << "Ha en bra dag!" << endl;
};
