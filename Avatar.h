#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <Windows.h>
#define CIN_CLEAR cin.clear(); cin.ignore(255, '\n');
using namespace std;

class Avatar {
  string name;
  int look_ind = 1;
  int life = 100;
  int hunger = 100;
  int fun = 100;
  int hygiene = 100;
  int illness_ind = 0;
  int gold = 0;
public:
  void set_name(string name);
  string get_name();
  void money(int time);
  void show();
  void show_gold();
  void show_look();
  void set_look(int ind);
  void hungry(int time);
  void funny(int time);
  void hygienic(int time);
  void ill(int time);
  bool dead();
  void food(int choice);
  void heal(int choice);
  void shower(int choice);
  int random_number();
  void game();
};