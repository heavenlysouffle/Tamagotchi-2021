#include "Avatar.h"

int main() {
  srand(time(NULL));
  SetConsoleCP(1251); 
  SetConsoleOutputCP(1251);
  // загрузочный экран
  cout << "  Добро пожаловать!\n\tЗагрузка";
  for (int i = 0; i < 3; i++) {
    Sleep(1000);
    cout << " . ";
  }
  Sleep(500);
  int moves, choice, time_game;
  while (true) {
    // начальный экран 
    system("cls");
    Avatar pet;
    moves = 0;
    cout << "Вы завели питомца! Введите имя: ";
    string name;
    cin >> name;
    CIN_CLEAR
    pet.set_name(name);
    // вывод всех вариантов внешности
    pet.show_look();
    pet.set_look(2);
    pet.show_look();
    pet.set_look(3);
    pet.show_look();
    cout << endl;
    cout << "Выберете вид питомца (1, 2, 3): ";
    cin >> choice;
    CIN_CLEAR
    pet.set_look(choice);
    system("pause");
    time_t life_start = time(NULL);
    while (!pet.dead()) {
      // начало отдельного цикла жизни
      time_t start_time = time(NULL);
      system("cls");
      pet.show_look();
      pet.show();
      // кормление
      time_t now_time = time(NULL);
      time_game = now_time - start_time;
      pet.money(time_game);
      pet.show_gold();
      cout << endl << "\t(введите 1, чтобы согласиться)" << endl;
      cout << "Хотите покормить " << pet.get_name() << "? ";
      cin >> choice;
      CIN_CLEAR
      if (choice == 1) {
        cout << "Выбор блюда: 1) Лунный пряник - (+10 Цена: 10)\n\t     2) Солёный тофу - (+20, Цена: 20)\n\t     3) Клёцки - (+30, Цена: 30)\t";
        cin >> choice;
        CIN_CLEAR
        pet.food(choice);
      }
      // развлечения
      now_time = time(NULL);
      time_game = now_time - start_time;
      pet.money(time_game);
      pet.show_gold();
      cout << "Хотите поиграть с " << pet.get_name() << "? ";
      cin >> choice;
      CIN_CLEAR
      int game = 0;
      if (choice == 1) {
        time_t game_start = time(NULL);
        pet.game();
        time_t game_end = time(NULL);
        game = game_end - game_start;
      }
      // купание
      now_time = time(NULL);
      time_game = now_time - start_time - game;
      pet.money(time_game);
      pet.show_gold();
      cout << "Хотите покупать " << pet.get_name() << "? ";
      cin >> choice;
      CIN_CLEAR
      if (choice == 1) {
        cout << "Выбор средства: 1) Мыло - (+15 Цена: 10)\n\t\t2) Гель - (+30 Цена: 30)\n\t\t3) Шампунь - (+45 Цена: 40)\t";
        cin >> choice;
        CIN_CLEAR
        pet.shower(choice);
      }
      // лечение
      now_time = time(NULL);
      time_game = now_time - start_time - game;
      pet.money(time_game);
      pet.show_gold();
      cout << "Хотите вылечить " << pet.get_name() << "? ";
      cin >> choice;
      CIN_CLEAR
      if (choice == 1) {
        cout << "Выбор лекарства: 1) Сироп - (Лечит 1 стадию Цена: 10)\n\t\t 2) Таблетки - (Лечит до 2 стадии Цена: 30)\n\t\t 3) Антибиотик - (Лечит все стадии Цена: 40)\t";
        cin >> choice;
        CIN_CLEAR
        pet.heal(choice);
      }
      // подсчёт показателей на конце одного отдельного цикла жизни
      now_time = time(NULL);
      time_game = now_time - start_time - game / 3;
      Sleep(500); // 0,5 секунды
      pet.hungry(time_game);
      pet.funny(time_game);
      pet.hygienic(time_game);
      pet.ill(time_game);
      moves++;
      if (pet.dead() == true) { // смерть
        time_t life_end = time(NULL);
        cout << endl << " [ Смерть ]" << endl;
        int life_time = life_end - life_start;
        cout << " [ Время жизни: " << life_time << " сек. ]" << endl;
        cout << " [ Количество ходов: " << moves << " ]" << endl;
        cout << "Хотите выйти? ";
        cin >> choice;
        CIN_CLEAR
        if (choice == 1) {
          cout << "Спасибо за игру! Возвращайтесь :)" << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}