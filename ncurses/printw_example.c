#include <ncurses.h>
#include <string.h>

int main()
{
  char msg[]="Tan sols una cadena";
  int row,col;

  initscr();
  getmaxyx(stdscr,row,col);
  mvprintw(row/2,(col-strlen(msg))/2,"%s",msg);
  mvprintw(row-2,0,r"Esta pantalla té %d files i %d columnes\n",row,col);
  printw("Prova a canviar la mida de la finestra (sí és possible) i torna a executar el programa.");
  refresh();
  getch();
  endwin();
  
  return 0;
}
