// melgu374: Samarbetat med eliom790, Elias Omrane, samma program
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "register_handling.h"

using namespace std;

void read(ifstream &infile, Register_Type &reg)
{
  string line{};
  while (getline(infile, line))
  {
    istringstream iss(line);
    Hero_Type hero;
    iss >> hero.name >> hero.birthyear >> hero.weight >> hero.hair_colour;

    int interest{};
    while (iss >> interest)
    {
      hero.interests.push_back(interest);
    }
    sort(hero.interests.begin(), hero.interests.end());
    reg.push_back(hero);
  }
}
void find_matching(vector<Hero_Type> &matching_heroes, const vector<int> &interests, Register_Type &reg)
{
  for (auto &hero : reg)
  {
    for (int hero_interest : hero.interests)
    {
      if (find(interests.begin(), interests.end(), hero_interest) != interests.end())
      {
        matching_heroes.push_back(hero);
        break;
      }
    }
  }
}

void find_and_print_matching_heroes(Register_Type &reg)
{
  cout << "Enter your interests (at least one between 1 and 15): ";
  while (true)
  {
    string input_line{};
    getline(cin, input_line);
    vector<int> interests;
    istringstream iss(input_line);
    int interest{};
    bool valid_input = true;
    while (iss >> interest)
    {
      if (interest < 1 || interest > 15)
      {
        valid_input = false;
        break;
      }
      interests.push_back(interest);
    }
    if (!valid_input || interests.empty())
      continue;
    vector<Hero_Type> matching_heroes;
    find_matching(matching_heroes, interests, reg);
    cout << "There are " << matching_heroes.size() << " matching heroes." << endl;
    print(matching_heroes, interests);
    break;
  }
}

void menu_choice(int choice, Register_Type &reg, const string &file_path)
{
  switch (choice)
  {
  case 1:
    add_new_hero(reg, file_path);
    break;
  case 2:
    find_and_print_matching_heroes(reg);
    break;
  case 3:
    cout << "Terminating Hero Matchmaker 3000!" << endl;
    break;
  }
}

void show_menu(Register_Type &reg, const string &file_path)
{
  cout << "Welcome to Hero Matchmaker 3000!" << endl;
  int choice{};
  do
  {
    cout << "1) Add new hero to register file\n";
    cout << "2) Find matching heroes\n";
    cout << "3) Quit program\n";
    do
    {
      cout << "Select: ";
      if (!(cin >> choice))
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      menu_choice(choice, reg, file_path);
    } while (choice < 1 or choice > 3);
  } while (choice != 3);
}

vector<Hero_Type> read_heroes_from_file(const string &file_path)
{
  ifstream infile(file_path);
  vector<Hero_Type> heroes;
  string line{};

  while (getline(infile, line))
  {
    istringstream iss(line);
    Hero_Type hero;
    iss >> hero.name >> hero.birthyear >> hero.weight >> hero.hair_colour;
    int interest{};
    while (iss >> interest)
    {
      hero.interests.push_back(interest);
    }
    heroes.push_back(hero);
  }

  infile.close();
  write_sorted_heroes_to_file(file_path, heroes);
  return heroes;
}
void write_sorted_heroes_to_file(const string &file_path, const vector<Hero_Type> &heroes)
{
  vector<Hero_Type> sorted_heroes = heroes;
  sort(sorted_heroes.begin(), sorted_heroes.end(),
       [](const Hero_Type &a, const Hero_Type &b)
       {
         return a.name < b.name;
       });

  ofstream outfile(file_path);
  for (const auto &hero : sorted_heroes)
  {
    outfile << hero.name << " " << hero.birthyear << " " << hero.weight << " " << hero.hair_colour;
    for (int interest : hero.interests)
    {
      outfile << " " << interest;
    }
    outfile << endl;
  }
  outfile.close();
}

string remove_dot_slash(const string &file_path)
{
  if (file_path.size() >= 2 && file_path[0] == '.' && file_path[1] == '/')
  {
    return file_path.substr(2);
  }
  return file_path;
}
void print_clean_file_path(const string &file_path)
{
  string cleanfile_path = remove_dot_slash(file_path);
  cout << "The hero was added to the register on file " << cleanfile_path << endl;
}

void add_new_hero(Register_Type &reg, const string &file_path)
{
  while (true)
  {
    cout << "Enter hero information:\n";
    Hero_Type new_hero = prompt_for_hero_information();

    if (!is_hero_in_register(reg, new_hero))
    {
      append_hero_to_file(file_path, new_hero);
      read_heroes_from_file(file_path);
      update_register_from_file(reg, file_path);
      print_clean_file_path(file_path);
      break;
    }
    else
    {
      cout << "Hero already in register. ";
    }
  }
}

Hero_Type prompt_for_hero_information()
{
  string input_line{};

  getline(cin, input_line);
  istringstream iss(input_line);
  Hero_Type new_hero;
  iss >> new_hero.name >> new_hero.birthyear >> new_hero.weight >> new_hero.hair_colour;
  int interest{};
  while (iss >> interest)
  {
    new_hero.interests.push_back(interest);
  }
  return new_hero;
}

bool is_hero_in_register(const Register_Type &reg, const Hero_Type &hero)
{
  for (const auto &existing_hero : reg)
  {
    if (existing_hero.name == hero.name)
    {
      return true;
    }
  }
  return false;
}

void append_hero_to_file(const string &file_path, const Hero_Type &hero)
{
  ofstream outfile(file_path.c_str(), ios::app);
  outfile << hero.name << " " << hero.birthyear << " " << hero.weight << " " << hero.hair_colour;
  for (int interest : hero.interests)
  {
    outfile << " " << interest;
  }
  outfile << endl;
  outfile.close();
}

void update_register_from_file(Register_Type &reg, const string &file_path)
{
  ifstream infile(file_path);
  reg.clear();
  read(infile, reg);
  infile.close();
}
