#include "Avatar.h"

int main() {
  srand(time(NULL));
  SetConsoleCP(1251); 
  SetConsoleOutputCP(1251);
  // ����������� �����
  cout << "  ����� ����������!\n\t��������";
  for (int i = 0; i < 3; i++) {
    Sleep(1000);
    cout << " . ";
  }
  Sleep(500);
  int moves, choice, time_game;
  while (true) {
    // ��������� ����� 
    system("cls");
    Avatar pet;
    moves = 0;
    cout << "�� ������ �������! ������� ���: ";
    string name;
    cin >> name;
    CIN_CLEAR
    pet.set_name(name);
    // ����� ���� ��������� ���������
    pet.show_look();
    pet.set_look(2);
    pet.show_look();
    pet.set_look(3);
    pet.show_look();
    cout << endl;
    cout << "�������� ��� ������� (1, 2, 3): ";
    cin >> choice;
    CIN_CLEAR
    pet.set_look(choice);
    system("pause");
    time_t life_start = time(NULL);
    while (!pet.dead()) {
      // ������ ���������� ����� �����
      time_t start_time = time(NULL);
      system("cls");
      pet.show_look();
      pet.show();
      // ���������
      time_t now_time = time(NULL);
      time_game = now_time - start_time;
      pet.money(time_game);
      pet.show_gold();
      cout << endl << "\t(������� 1, ����� �����������)" << endl;
      cout << "������ ��������� " << pet.get_name() << "? ";
      cin >> choice;
      CIN_CLEAR
      if (choice == 1) {
        cout << "����� �����: 1) ������ ������ - (+10 ����: 10)\n\t     2) ������ ���� - (+20, ����: 20)\n\t     3) ����� - (+30, ����: 30)\t";
        cin >> choice;
        CIN_CLEAR
        pet.food(choice);
      }
      // �����������
      now_time = time(NULL);
      time_game = now_time - start_time;
      pet.money(time_game);
      pet.show_gold();
      cout << "������ �������� � " << pet.get_name() << "? ";
      cin >> choice;
      CIN_CLEAR
      int game = 0;
      if (choice == 1) {
        time_t game_start = time(NULL);
        pet.game();
        time_t game_end = time(NULL);
        game = game_end - game_start;
      }
      // �������
      now_time = time(NULL);
      time_game = now_time - start_time - game;
      pet.money(time_game);
      pet.show_gold();
      cout << "������ �������� " << pet.get_name() << "? ";
      cin >> choice;
      CIN_CLEAR
      if (choice == 1) {
        cout << "����� ��������: 1) ���� - (+15 ����: 10)\n\t\t2) ���� - (+30 ����: 30)\n\t\t3) ������� - (+45 ����: 40)\t";
        cin >> choice;
        CIN_CLEAR
        pet.shower(choice);
      }
      // �������
      now_time = time(NULL);
      time_game = now_time - start_time - game;
      pet.money(time_game);
      pet.show_gold();
      cout << "������ �������� " << pet.get_name() << "? ";
      cin >> choice;
      CIN_CLEAR
      if (choice == 1) {
        cout << "����� ���������: 1) ����� - (����� 1 ������ ����: 10)\n\t\t 2) �������� - (����� �� 2 ������ ����: 30)\n\t\t 3) ���������� - (����� ��� ������ ����: 40)\t";
        cin >> choice;
        CIN_CLEAR
        pet.heal(choice);
      }
      // ������� ����������� �� ����� ������ ���������� ����� �����
      now_time = time(NULL);
      time_game = now_time - start_time - game / 3;
      Sleep(500); // 0,5 �������
      pet.hungry(time_game);
      pet.funny(time_game);
      pet.hygienic(time_game);
      pet.ill(time_game);
      moves++;
      if (pet.dead() == true) { // ������
        time_t life_end = time(NULL);
        cout << endl << " [ ������ ]" << endl;
        int life_time = life_end - life_start;
        cout << " [ ����� �����: " << life_time << " ���. ]" << endl;
        cout << " [ ���������� �����: " << moves << " ]" << endl;
        cout << "������ �����? ";
        cin >> choice;
        CIN_CLEAR
        if (choice == 1) {
          cout << "������� �� ����! ������������� :)" << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}