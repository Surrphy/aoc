#include <stdio.h>

const int INPUT_LENGTH = 10;
const int LINE_LENGTH = 140;  // doesn't include newline char

typedef struct Part {
  unsigned int number;
  char symbol;
} Part;

int main() {
  FILE* input = fopen("/home/surrphy/projects/advent_of_code/parts/input.txt", "r");
  char line[];
  int eof;

  Part result[];

  fseek(input, 0, SEEK_END);
  eof = ftell(input);
  rewind(input);

  for (int i = 0; ftell(input) < eof; i++) {
    fgets(line, LINE_LENGTH, input);

    result[i] = parse_line()
  }


  return 0;
}
