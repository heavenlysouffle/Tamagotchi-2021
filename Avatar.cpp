#include "Avatar.h"

void Avatar::set_name(string name) {
  this->name = name;
}
string Avatar::get_name() {
  return name;
}
void Avatar::money(int time) {
  gold += 2 * time;
}

void Avatar::show() {
  cout << endl << "�����: " << life << endl;
  cout << "����������: ";
  if (life >= 90) cout << "����������" << endl;
  if (life >= 75 && life < 90) cout << "���������" << endl;
  if (life >= 50 && life < 75) cout << "�����������" << endl;
  if (life >= 25 && life < 50) cout << "�����������" << endl;
  if (life > 0 && life < 25) cout << "��������" << endl;
  cout << "�����: " << hunger << endl;
  cout << "�����������: " << fun << endl;
  cout << "�������: " << hygiene << endl;
  cout << "������ �������: " << illness_ind << endl;
}

void Avatar::show_gold() {
  cout << "������: " << gold << endl;
}

void Avatar::show_look() { // ����� ���������
  cout << endl;
  if (look_ind == 1) {
    cout << " ()()\n (..)\n (` `)\n ` `" << endl;
    return;
  }
  else if (look_ind == 2) {
    cout << "  /)__/)\n (='.'=)\n (`)_(`)" << endl;
    return;
  }
  else if (look_ind == 3) {
    cout << "  <' )\n      //\n  (___ >" << endl;
    return;
  }
}

void Avatar::set_look(int ind) { // ��������� ���������
  if (ind == 1)
    look_ind = 1;
  else if (ind == 2)
    look_ind = 2;
  else if (ind == 3)
    look_ind = 3;
  else {
    look_ind = 1;
    cout << "����� ����� ���. ������������� ���������� ��� �1" << endl;
  }
}

void Avatar::hungry(int time) { // �����
  if (life > 100) { life = 100; }
  hunger -= (time / 3) * 5;
  if (hunger > 100) { hunger = 100; }
  if (hunger < 0) { hunger = 0; }
  if (hunger >= 90) { life += time * 2; }
  if (hunger >= 75 && hunger < 90) { life += time; }
  if (hunger >= 50 && hunger < 75) { life -= 3 * time; }
  if (hunger >= 25 && hunger < 50) { life -= 4 * time; }
  if (hunger > 0 && hunger < 25) { life -= 5 * time; }
  if (hunger == 0) { life -= 6 * time; }
  if (life > 100) { life = 100; }
}

void Avatar::funny(int time) { // ����������� � ������������
  if (life > 100) { life = 100; }
  fun -= (time / 3) * 3;
  if (fun > 100) { fun = 100; }
  if (fun < 0) { fun = 0; }
  if (fun >= 90) { life += time * 2; }
  if (fun >= 75 && fun < 90) { life += time; }
  if (fun >= 50 && fun < 75) { life -= 2 * time; }
  if (fun >= 25 && fun < 50) { life -= 3 * time; }
  if (fun > 0 && fun < 25) { life -= 4 * time; }
  if (fun == 0) { life -= 5 * time; }
  if (life > 100) { life = 100; }
}

void Avatar::hygienic(int time) { // �����������
  if (life > 100) { life = 100; }
  int illness = 0;
  hygiene -= (time / 3) * 4;
  if (hygiene > 100) { hygiene = 100; }
  if (hygiene < 0) { hygiene = 0; }
  if (hygiene >= 90) { life += time * 3; }
  if (hygiene >= 75 && hygiene < 90) {
    illness = rand() % 10;
    if (illness == 5) { if (!(illness_ind)) illness_ind = 1; }
  }
  if (hygiene >= 50 && hygiene < 75) {
    illness = rand() % 10;
    if (illness == 3 || illness == 6) {
      if (!(illness_ind)) illness_ind = 1;
      if (illness == 6) { if (illness_ind < 2) illness_ind = 2; }
    }
  }
  if (hygiene >= 25 && hygiene < 50) {
    illness = rand() % 10;
    if (illness == 3 || illness == 6 || illness == 9) {
      if (!(illness_ind)) illness_ind = 1;
      if (illness == 3 || illness == 6) { if (illness_ind < 2) illness_ind = 2; }
      if (illness == 9) { if (illness_ind < 3) illness_ind = 3; }
    }
  }
  if (hygiene >= 0 && hygiene < 25) {
    illness = rand() % 10;
    if (illness == 2 || illness == 4 || illness == 6 || illness == 8 || illness == 10) {
      if (!(illness_ind)) illness_ind = 1;
      if (illness == 2 || illness == 4 || illness == 6) { if (illness_ind < 2) illness_ind = 2; }
      if (illness == 8 || illness == 10) { if (illness_ind < 3) illness_ind = 3; }
    }
  }
  if (life > 100) { life = 100; }
}

void Avatar::ill(int time) { // �������
  if (illness_ind == 1) { life -= (time / 5) * 3; }
  if (illness_ind == 2) { life -= (time / 5) * 5; }
  if (illness_ind == 3) { life -= (time / 5) * 7; }
}

bool Avatar::dead() {
  if (life <= 0)
    return true;
  else return false;
}

void Avatar::food(int choice) { // ���������
  if (choice == 1) {
    if (gold >= 10) {
      hunger += 10;
      gold -= 10;
      cout << name << " ���� ������ ������" << endl;
      return;
    }
  }
  else if (choice == 2) {
    if (gold >= 20) {
      hunger += 20;
      gold -= 20;
      cout << name << " ���� ������ ����" << endl;
      return;
    }
  }
  else if (choice == 3) {
    if (gold >= 30) {
      hunger += 30;
      gold -= 30;
      cout << name << " ���� �����" << endl;
      return;
    }
  }
  else {
    cout << "����� ����� ���" << endl;
    return;
  }
  cout << "� ��� ������������ ������" << endl;
}

void Avatar::heal(int choice) { // �������
  if (!illness_ind) {
    cout << name << " ������" << endl;
    return;
  }
  if (choice == 1) {
    if (gold >= 30) {
      if (illness_ind != 1) {
        cout << "��� ��������� �� �������� ��� ������ ������ �������" << endl;
        return;
      }
      illness_ind = 0;
      gold -= 30;
      cout << "�� �������� " << name << " �������" << endl;
      return;
    }
  }
  else if (choice == 2) {
    if (gold >= 40) {
      if (illness_ind > 2) {
        cout << "��� ��������� �� �������� ��� ������ ������ �������" << endl;
        return;
      }
      illness_ind = 0;
      gold -= 40;
      cout << "�� �������� " << name << " ����������" << endl;
      return;
    }
  }
  else if (choice == 3) {
    if (gold >= 50) {
      illness_ind = 0;
      gold -= 50;
      cout << "�� �������� " << name << " ������������" << endl;
      return;
    }
  }
  else {
    cout << "����� ����� ���" << endl;
    return;
  }
  cout << "� ��� ������������ ������" << endl;
}

void Avatar::shower(int choice) { // �������
  if (choice == 1) {
    if (gold >= 10) {
      hygiene += 15;
      gold -= 10;
      cout << "�� �������� " << name << " � �����" << endl;
      return;
    }
  }
  else if (choice == 2) {
    if (gold >= 30) {
      hygiene += 30;
      gold -= 30;
      cout << "�� �������� " << name << " � �����" << endl;
      return;
    }
  }
  else if (choice == 3) {
    if (gold >= 40) {
      hygiene += 45;
      gold -= 40;
      cout << "�� �������� " << name << " � ��������" << endl;
      return;
    }
  }
  else {
    cout << "����� ����� ���" << endl;
    return;
  }
  cout << "� ��� ������������ ������" << endl;
}

int Avatar::random_number() {
  int number;
  for (;;) {
    number = rand() % 123;
    if (number < 97)
      continue;
    else
      break;
  }
  return number;
}

void Avatar::game() { // ����������� - ����-����
  char mas[12], mas_p[12];
  int size, ind_mas;
  for (int x = 0; x < 3; x++) {
    size = rand() % 4 + 3;
    ind_mas = 0;
    for (int i = 0; i < size; i++)
      mas[i] = char(random_number());
    cout << "������� �������� ����� � �������� �������: ";
    for (int c = 0; c < size; c++) 
      cout << mas[c];
    cout << endl;
    cin >> mas_p;
    for (int x = size - 1, c = 0; c < size; x--, c++) 
      if (mas[x] == mas_p[c]) 
        ind_mas++;
    if (ind_mas == size) {
      cout << "���������! �� �������� 5 �����" << endl;
      gold += 5;
      fun += 33;
    }
    else 
      cout << "�������!" << endl; 
  }
  cout << "����-���� ���������" << endl;
}