// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI
#include <stdio.h>

void ball_and_table(int cross_pos_x, int cross_pos_y, int racket_position_x,
                    int racket_position_y, int racket_position2_x,
                    int racket_position2_y, int first_player,
                    int second_player);
void lobby();
void congrats(int victory);
// void delay();

int main() {

  int cross_position_x = 39;
  int cross_position_y = 12;

  int vector_x = 1;
  int vector_y = 1;

  int racket_position_x = 1; //позиция первой ракетки
  int racket_position_y = 11;

  int racket_position2_x = 78; //позиция второй ракетки
  int racket_position2_y = 11;

  char upravl = 0;
  char err = 0;

  int first_player = 0;
  int second_player = 0;

  while (upravl != 's') {
    lobby();
    if (scanf("%c%c", &upravl, &err) == 2 && (err == '\n')) {
      if (upravl == 's' || upravl == 'S') {
        break;
      } else if (upravl == 'e' || upravl == 'E') {
        return 0;
      }
    }
  }

  ball_and_table(cross_position_x, cross_position_y, racket_position_x,
                 racket_position_y, racket_position2_x, racket_position2_y,
                 first_player, second_player); //вызов отрисовки поля

  while (first_player < 21 && second_player < 21) {
    if (scanf("%c%c", &upravl, &err) == 2 && (err == '\n')) {
      if (upravl == 'z' || upravl == 'a' || upravl == 'k' || upravl == 'm' ||
          upravl == ' ' || upravl == 'e' || upravl == 'Z' || upravl == 'A' ||
          upravl == 'K' || upravl == 'M' || upravl == 'E') {
        if (upravl == 'z' && racket_position_y <= 20) {
          racket_position_y =
              racket_position_y + 1; //Управление первой ракеткой (вниз)
        } else if ((upravl == 'a' || upravl == 'A') && racket_position_y >= 0) {
          racket_position_y =
              racket_position_y - 1; //Управление первой ракеткой (наверх)
        }

        if ((upravl == 'm' || upravl == 'M') && racket_position2_y <= 20) {
          racket_position2_y =
              racket_position2_y + 1; //Управление второй ракеткой (вниз)
        } else if ((upravl == 'k' || upravl == 'K') &&
                   racket_position2_y >= 0) {
          racket_position2_y =
              racket_position2_y - 1; //Управление второй ракеткой (наверх)
        } else if (upravl == 'e' || upravl == 'E') {
          printf("Enter E one more time for exit\n");
          if (scanf("%c%c", &upravl, &err) == 2 && (err == '\n') &&
              (upravl == 'e' || upravl == 'E')) {
            return 0;
          }
          //обработка корректного досрочного выхода из игры
        }

        if (cross_position_x == racket_position2_x - 1 &&
            (cross_position_y == racket_position2_y + 1 ||
             cross_position_y == racket_position2_y + 2 ||
             cross_position_y == racket_position2_y + 3)) {
          vector_x = vector_x * (-1);
        } //Обработка столкновения шарика с ракеткой 2
        if (cross_position_x == racket_position_x + 1 &&
            (cross_position_y == racket_position_y + 1 ||
             cross_position_y == racket_position_y + 2 ||
             cross_position_y == racket_position_y + 3)) {
          vector_x = vector_x * (-1);
        } //Обработка столкновения шарика с ракеткой 1

        if (cross_position_x >= 79) {
          first_player = first_player + 1;
          cross_position_x = 38;
          cross_position_y = 12;
        }
        if (cross_position_x < 1) {
          second_player = second_player + 1;
          cross_position_x = 40;
          cross_position_y = 12;
        }
        if (cross_position_y >= 24 || cross_position_y < 1) {
          vector_y = vector_y * (-1);
        }

        cross_position_x = cross_position_x + (1 * vector_x);
        cross_position_y = cross_position_y + (1 * vector_y);
      }
    }

    ball_and_table(cross_position_x, cross_position_y, racket_position_x,
                   racket_position_y, racket_position2_x, racket_position2_y,
                   first_player, second_player); //вызов отрисовки поля
  }

  if (first_player >= 21) {
    congrats(1);
  } else if (second_player >= 21) { //поздравления
    congrats(2);
  }
}

void ball_and_table(int cross_pos_x, int cross_pos_y, int racket_position_x,
                    int racket_position_y, int racket_position2_x,
                    int racket_position2_y, int first_player,
                    int second_player) {

  char cross = '*';
  char space = ' ';
  char border = 'X';
  char line = '|';
  char racket = ')';
  char racket2 = '(';

  int score_position_x = 37;
  int score_position_y = 1;

  for (int ix = 0; ix <= 81; ix++) {
    printf("%c", border); //рисуем верхнюю границу
  }

  printf("\n"); //перенос строки

  for (int y = 0; y <= 24;
       y++) { //рисуем огромную часть с пробелами (пуст поле)
    printf("%c", border); //рисуем границу в начале строки

    for (int x = 0; x <= 79; x++) {
      if (x == 39 &&
          (x != cross_pos_x || y != cross_pos_y)) { //рисуем линию по середине
        printf("%c", line);
        if (second_player > 9 && y == score_position_y) {
          x = x + 1;
        }
      } else if (y == score_position_y && x == score_position_x &&
                 (y != cross_pos_x || y != cross_pos_y)) {
        //рисуем счет игроков по середине
        if (first_player > 9) {
          x = x + 1;
        }
        printf("%d", first_player);
      } else if (y == score_position_y && x == score_position_x + 4 &&
                 (y != cross_pos_x || y != cross_pos_y)) {
        //рисуем счет игроков по середине
        printf("%d", second_player);
      }

      else if (x == racket_position_x && y > racket_position_y &&
               y <= racket_position_y + 3) {
        //рисуем первую ракетку
        printf("%c", racket);
      } else if (x == racket_position2_x && y > racket_position2_y &&
                 y <= racket_position2_y + 3) {
        //рисуем вторую ракетку
        printf("%c", racket2);
      } else if (x == cross_pos_x && y == cross_pos_y) {
        printf("%c", cross); //рисуем шарик на какой-то позиции внутри пуст поля
      } else {
        printf("%c", space); //рисуем пробелы на всех других позициях пуст поля
      }
    }

    printf("%c", border); //рисуем границу в конце строки

    printf("\n"); //перенос строки
  }

  for (int ix = 0; ix <= 81; ix++) {
    printf("%c", border); //рисуем нижнюю границу
  }

  printf("\n"); //перенос строки

  //  delay();             //задержка
}

void lobby() {
  char space = ' ';
  char border = 'X';

  int score_position_x = 30;
  int score_position_y = 12;

  int score_position2_x = 30;
  int score_position2_y = 13;

  int score_position3_x = 30;
  int score_position3_y = 14;

  int score_position4_x = 30;
  int score_position4_y = 15;

  for (int ix = 0; ix <= 80; ix++) {
    printf("%c", border); //рисуем верхнюю границу
  }

  printf("\n"); //перенос строки

  for (int y = 0; y <= 23;
       y++) { //рисуем огромную часть с пробелами (пуст поле)
    printf("%c", border); //рисуем границу в начале строки

    for (int x = 0; x <= 78; x++) {

      if (y == score_position_y && x == score_position_x) {
        //рисуем правила игры
        printf("Enter A/Z for First Player");
        x = x + 25;
      } else if (y == score_position2_y && x == score_position2_x) {
        //рисуем правила игры
        printf("Enter K/M for Second Player");
        x = x + 26;
      } else if (y == score_position3_y && x == score_position3_x) {
        //рисуем правила игры
        printf("Enter S for Start");
        x = x + 16;
      } else if (y == score_position4_y && x == score_position4_x) {
        //рисуем правила игры
        printf("Enter E for Exit");
        x = x + 15;
      } else {
        printf("%c", space); //рисуем пробелы на всех других позициях пуст поля
      }
    }

    printf("%c", border); //рисуем границу в конце строки

    printf("\n"); //перенос строки
  }

  for (int ix = 0; ix <= 80; ix++) {
    printf("%c", border); //рисуем нижнюю границу
  }

  printf("\n"); //перенос строки
}

void congrats(int victory) {

  char space = ' ';
  char border = 'X';

  int score_position_x = 30;
  int score_position_y = 12;

  for (int ix = 0; ix <= 80; ix++) {
    printf("%c", border); //рисуем верхнюю границу
  }

  printf("\n"); //перенос строки

  for (int y = 0; y <= 23;
       y++) { //рисуем огромную часть с пробелами (пуст поле)
    printf("%c", border); //рисуем границу в начале строки

    for (int x = 0; x <= 78; x++) {

      if (y == score_position_y && x == score_position_x) {
        //рисуем поздравления

        if (victory == 1) {
          printf("First Player Wins!");
          x = x + 17;
        } else {
          printf("Second Player Wins!");
          x = x + 19;
        }

      } else {
        printf("%c", space); //рисуем пробелы на всех других позициях пуст поля
      }
    }

    printf("%c", border); //рисуем границу в конце строки

    printf("\n"); //перенос строки
  }

  for (int ix = 0; ix <= 80; ix++) {
    printf("%c", border); //рисуем нижнюю границу
  }

  printf("\n"); //перенос строки
}

// void delay()
//{
//    int c, d;
//    for (c = 1; c <= 8000; c++)
//        for (d = 1; d <= 8000; d++)
//        {}
// }
