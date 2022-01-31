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
  cout << endl << "Жизни: " << life << endl;
  cout << "Настроение: ";
  if (life >= 90) cout << "счастливое" << endl;
  if (life >= 75 && life < 90) cout << "радостное" << endl;
  if (life >= 50 && life < 75) cout << "нейтральное" << endl;
  if (life >= 25 && life < 50) cout << "подавленное" << endl;
  if (life > 0 && life < 25) cout << "грустное" << endl;
  cout << "Голод: " << hunger << endl;
  cout << "Развлечения: " << fun << endl;
  cout << "Гигиена: " << hygiene << endl;
  cout << "Стадия болезни: " << illness_ind << endl;
}

void Avatar::show_gold() {
  cout << "Золото: " << gold << endl;
}

void Avatar::show_look() { // вывод внешности
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

void Avatar::set_look(int ind) { // установка внешности
  if (ind == 1)
    look_ind = 1;
  else if (ind == 2)
    look_ind = 2;
  else if (ind == 3)
    look_ind = 3;
  else {
    look_ind = 1;
    cout << "Такой опции нет. Автоматически установлен вид №1" << endl;
  }
}

void Avatar::hungry(int time) { // голод
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

void Avatar::funny(int time) { // потребность в развлечениях
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

void Avatar::hygienic(int time) { // загрязнение
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

void Avatar::ill(int time) { // болезнь
  if (illness_ind == 1) { life -= (time / 5) * 3; }
  if (illness_ind == 2) { life -= (time / 5) * 5; }
  if (illness_ind == 3) { life -= (time / 5) * 7; }
}

bool Avatar::dead() {
  if (life <= 0)
    return true;
  else return false;
}

void Avatar::food(int choice) { // кормление
  if (choice == 1) {
    if (gold >= 10) {
      hunger += 10;
      gold -= 10;
      cout << name << " съел лунный пряник" << endl;
      return;
    }
  }
  else if (choice == 2) {
    if (gold >= 20) {
      hunger += 20;
      gold -= 20;
      cout << name << " съел солёный тофу" << endl;
      return;
    }
  }
  else if (choice == 3) {
    if (gold >= 30) {
      hunger += 30;
      gold -= 30;
      cout << name << " съел клёцки" << endl;
      return;
    }
  }
  else {
    cout << "Такой опции нет" << endl;
    return;
  }
  cout << "У вас недостаточно золота" << endl;
}

void Avatar::heal(int choice) { // лечение
  if (!illness_ind) {
    cout << name << " здоров" << endl;
    return;
  }
  if (choice == 1) {
    if (gold >= 30) {
      if (illness_ind != 1) {
        cout << "Это лекарство не подходит для данной стадии болезни" << endl;
        return;
      }
      illness_ind = 0;
      gold -= 30;
      cout << "Вы вылечили " << name << " сиропом" << endl;
      return;
    }
  }
  else if (choice == 2) {
    if (gold >= 40) {
      if (illness_ind > 2) {
        cout << "Это лекарство не подходит для данной стадии болезни" << endl;
        return;
      }
      illness_ind = 0;
      gold -= 40;
      cout << "Вы вылечили " << name << " таблетками" << endl;
      return;
    }
  }
  else if (choice == 3) {
    if (gold >= 50) {
      illness_ind = 0;
      gold -= 50;
      cout << "Вы вылечили " << name << " антибиотиком" << endl;
      return;
    }
  }
  else {
    cout << "Такой опции нет" << endl;
    return;
  }
  cout << "У вас недостаточно золота" << endl;
}

void Avatar::shower(int choice) { // купание
  if (choice == 1) {
    if (gold >= 10) {
      hygiene += 15;
      gold -= 10;
      cout << "Вы покупали " << name << " с мылом" << endl;
      return;
    }
  }
  else if (choice == 2) {
    if (gold >= 30) {
      hygiene += 30;
      gold -= 30;
      cout << "Вы покупали " << name << " с гелем" << endl;
      return;
    }
  }
  else if (choice == 3) {
    if (gold >= 40) {
      hygiene += 45;
      gold -= 40;
      cout << "Вы покупали " << name << " с шампунем" << endl;
      return;
    }
  }
  else {
    cout << "Такой опции нет" << endl;
    return;
  }
  cout << "У вас недостаточно золота" << endl;
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

void Avatar::game() { // развлечения - мини-игра
  char mas[12], mas_p[12];
  int size, ind_mas;
  for (int x = 0; x < 3; x++) {
    size = rand() % 4 + 3;
    ind_mas = 0;
    for (int i = 0; i < size; i++)
      mas[i] = char(random_number());
    cout << "Введите заданное слово в обратном порядке: ";
    for (int c = 0; c < size; c++) 
      cout << mas[c];
    cout << endl;
    cin >> mas_p;
    for (int x = size - 1, c = 0; c < size; x--, c++) 
      if (mas[x] == mas_p[c]) 
        ind_mas++;
    if (ind_mas == size) {
      cout << "Правильно! Вы получили 5 монет" << endl;
      gold += 5;
      fun += 33;
    }
    else 
      cout << "Неверно!" << endl; 
  }
  cout << "Мини-игра закончена" << endl;
}