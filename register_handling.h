#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include "hero_handling.h"

// Forward declaration of structures
struct Hero_Type;

using Register_Type = std::vector<Hero_Type>;
void read(std::ifstream &infile, Register_Type &reg);
void find_matching(vector<Hero_Type> &matching_heroes, const vector<int> &interests, Register_Type &reg);
void find_and_print_matching_heroes(Register_Type &reg);
// void matching_heroes(Register_Type &reg);
void menu_choice(int choice, Register_Type &reg, const std::string &file_path);
void show_menu(Register_Type &reg, const std::string &file_path);

std::vector<Hero_Type> read_heroes_from_file(const std::string &file_path);
void write_sorted_heroes_to_file(const std::string &file_path, const std::vector<Hero_Type> &heroes);
void print_clean_file_path(const std::string &file_path);

std::string remove_dot_slash(const std::string &file_path);
void add_new_hero(Register_Type &reg, const std::string &file_path);

Hero_Type prompt_for_hero_information();
bool is_hero_in_register(const Register_Type &reg, const Hero_Type &hero);
void append_hero_to_file(const std::string &file_path, const Hero_Type &hero);
void update_register_from_file(Register_Type &reg, const std::string &file_path);