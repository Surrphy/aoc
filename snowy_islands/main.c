#include <stdio.h>
#include <math.h>

const int INPUT_LENGTH = 100;
const int MAX_LINE_LENGTH = 255;
const int GAME_PRELUDE_LENGTH = 5;

const int COLORS_LENGTH = 3;
const int COLORS[3][2] = {
  {'b', 5},
  {'r', 4},
  {'g', 6}
};

typedef struct Game {
  unsigned int id;
  unsigned int max_red;
  unsigned int max_blue;
  unsigned int max_green;

} Game;

Game parse_line(char* line);
int parse_game_id(char* line);

int main () {
  FILE* input = fopen("/home/surrphy/projects/advent_of_code/snowy_islands/input.txt", "r");
  Game result[INPUT_LENGTH];

  int eof;

  fseek(input, 0, SEEK_END);
  eof = ftell(input);
  rewind(input);

  char line[MAX_LINE_LENGTH];

  for (int i = 0; ftell(input) < eof; i++) {
    fgets(line, MAX_LINE_LENGTH, input);

    int id_length = parse_game_id(&line[GAME_PRELUDE_LENGTH]);

    result[i] = parse_line(&line[GAME_PRELUDE_LENGTH + id_length + 2]);
    result[i].id = i+1;
  }

  int count = 0;

  for (int i = 0; i < INPUT_LENGTH; i++) {
    if (result[i].max_red <= 12 && result[i].max_green <= 13 && result[i].max_blue <= 14) {
      count += result[i].id;
    }
  }

  printf("PART ONE: %d\n", count);

  count = 0;

  for (int i = 0; i < INPUT_LENGTH; i++) {
    count += result[i].max_red * result[i].max_blue * result[i].max_green;
  }

  printf("PART TWO: %d\n", count);

  return 0;
}

Game parse_line(char* line) {
  Game result;

  result.max_red = 0;
  result.max_blue = 0;
  result.max_green = 0;

  for (char* p = line; *p; p++) {
    if (*p >= '0' && *p <= '9') {
      int number = (*(p+1) >= '0' && *(p+1) <= '9') ? ((*p - '0') * 10) + (*(p+1) - '0') : *p - '0';

      int jump = (*(p+1) >= '0' && *(p+1) <= '9') ? 3 : 2;

      for (int i = 0; i < COLORS_LENGTH; i++) {
        if (*(p+jump) == COLORS[i][0]) {
          switch (COLORS[i][0]) {
            case 'b':
              result.max_blue = result.max_blue < number ? number : result.max_blue;
              break;
            case 'r':
              result.max_red = result.max_red < number ? number : result.max_red;
              break;
            case 'g':
              result.max_green = result.max_green < number ? number : result.max_green;
              break;
          }

          p += COLORS[i][1];
        }
      }
    }
  }

  return result;
}

int parse_game_id(char* line) {
  int count = 0;

  for (char* p = line; *p != ':'; p++) {
    count++;
  }

  return count;
}
