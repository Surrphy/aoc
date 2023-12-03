#include <stdio.h>
#include <string.h>

const int INPUT_SIZE = 1000;
const int MAX_LINE_SIZE = 255;

void parse_input(FILE* input, int* val);
int parse_line(char line[]);
int check_for_string(char line[], int index);

int main() {
  FILE* input = fopen("/home/surrphy/projects/advent_of_code/trebuchet/input.txt", "r");

  int calibration_val[INPUT_SIZE], result = 0;

  parse_input(input, &calibration_val);

  for (int i = 0; i < INPUT_SIZE; i++) {
    result += calibration_val[i];
  }

  printf("%d\n", result);
}

void parse_input(FILE* input, int* val) {
  char line[MAX_LINE_SIZE];

  int eof;

  fseek(input, 0, SEEK_END);
  eof = ftell(input);
  rewind(input);

  for (int i = 0; ftell(input) < eof; i++) {
    fgets(line, MAX_LINE_SIZE, input);
    *(val + i) = parse_line(line);
  }
}

// one, two, three, four, five, six, seven, eight, nine
int parse_line(char line[]) {
  int last = 0, first = 0;

  for (int i = 0; line[i] != '\0'; i++) {
    if (line[i] >= '0' && line[i] <= '9') {
      first = first == 0 ? line[i] - '0' : first;
      last = line[i] - '0';
      continue;
    }

    int number = check_for_string(line, i);

    if (number != -1) {
      first = first == 0 ? number : first;
      last = number;
    }
  }

  return (first*10) + last;
}

int check_for_string(char line[], int index) {
  char number[100];

  for (int i = index; line[i] != '\0' && i - index < 5; i++) {
    number[i - index] = line[i];
    number[i - index + 1] = '\0';

    if (strcmp(number, "one") == 0) {
      return 1;
    } else if (strcmp(number, "two") == 0) {
      return 2;
    } else if (strcmp(number, "three") == 0) {
      return 3;
    } else if (strcmp(number, "four") == 0) {
      return 4;
    } else if (strcmp(number, "five") == 0) {
      return 5;
    } else if (strcmp(number, "six") == 0) {
      return 6;
    } else if (strcmp(number, "seven") == 0) {
      return 7;
    } else if (strcmp(number, "eight") == 0) {
      return 8;
    } else if (strcmp(number, "nine") == 0) {
      return 9;
    }
  }

  return -1;
}
