#include <stdio.h>
#include <windows.h>

void main() {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  SetConsoleTextAttribute(hConsole,
    FOREGROUND_RED);
  printf("red text\n");

//   SetConsoleTextAttribute(hConsole,
//     FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE);
//   printf("yellow on blue\n");
}