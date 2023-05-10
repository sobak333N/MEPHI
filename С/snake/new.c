#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

#define arrow(x) k>0?printf("c\n", x):(0);k=-1
#define clear() write(STDIN_FILENO , "\033[H\033[2J" , 7)
#define up() write(STDIN_FILENO , "\033[A", 3)
#define down() write(STDIN_FILENO , "\033[B", 3)
#define right() write(STDIN_FILENO , "\033[C", 3)
#define left() write(STDIN_FILENO , "\033[D", 3)
#define save() write(STDIN_FILENO , "\033[s", 3)
#define nocursor() write(STDIN_FILENO , "\033[?25l" , 6)
#define cursor() write(STDIN_FILENO , "\033[?25h" , 6)


struct termios orig_termios;


void OnCanon(){
  struct termios raw;
  raw.c_lflag |= (ECHO| ICANON);
  tcsetattr(STDIN_FILENO , TCSAFLUSH , &raw);
  printf("\x1b[?25h");
}

void OffCanon(){
  struct termios raw;
  tcgetattr(STDIN_FILENO , &orig_termios);
  raw = orig_termios;
  raw.c_lflag &= ~(ECHO| ICANON);

  tcsetattr(STDIN_FILENO , TCSAFLUSH ,&raw);
  atexit(OnCanon);
}

void printbuf(char *b , char c){
  char j ;
  for( j = 0 ;j < c ; j++){
    printf("%x ", b[j]);
  }
  printf("read %d chars \n", c);
}

int main(void){
  int i = 0;
  char c , j ,b[5];
  OffCanon();
  while(c = read(STDIN_FILENO , b ,4) ){
    switch(c){
      case 1: switch(b[0]){
          case 'Q': OnCanon(); return 2;
          case 'W': nocursor();break;
          case 'E': cursor();break;
          case 0x08: clear(); break;
          case 'a' ...'z': printf("%c[%d]\n" , b[0] , i++); break;
          default: printbuf(b , c); break;
        }
        break;

      case 2: printbuf(b,c);
        break;
      case 3: if( (b[0] == 0x1b) && (b[1] == 0x5b))
        switch (b[2]) {
          case 0x41: up();break;
          case 0x42: down();break;
          case 0x43: right();break;
          case 0x44: left();break;
          default: printbuf(b,c);
          break;
        }
        break;

      case 4: printbuf(b,c);
              break;
    }
  }
  return 0;
}
