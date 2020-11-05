#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 10

int print_menu(WINDOW *menu_win,int highlight);

char *opcions[] = {
  "Opció 1",
  "Opció 2",
  "Opció 3",
  "Opció 4",
  "Eixida",
};

int main()
{
  WINDOW *menu_win;
  int startx, starty, highlight=1,choice=0,c;

  initscr();
  clear();
  noecho();
  cbreak();

  /* Centrem el menú */
  startx = (COLS - WIDTH)/2;
  starty = (LINES - HEIGHT)/2;

  menu_win=newwin(HEIGHT, WIDTH, starty, startx);
  keypad(menu_win,TRUE);
  mvprintw(0,0,"Utilitza les fletxes amunt i avall per a navegar per les opcions.");
  refresh();
  print_menu(menu_win,1);
  do{
    c=wgetch(menu_win);
    switch (c) {
    case KEY_UP: {
      if (highlight == 1)
	highlight = 5;
      else
	--highlight;
      mvprintw(1,0,"Has pres FLETXA AMUNT, enllumenat: %i.",highlight);
      refresh();
      break;
    }
    case KEY_DOWN: {
      if (highlight == 5)
	highlight=1;
      else
	++highlight;
      break;
    }
    case 10:{
      choice = highlight;
      break;
    }
    /* default: */
    /*   break; */
    }
    print_menu(menu_win, highlight);
  } while (!choice);
  delwin(menu_win);
  endwin();
  return 0;
}

int print_menu(WINDOW *menu_win,int highlight){
  int x=2,y=2,i=0;

  box(menu_win,0,0);
  for (i=0; i<sizeof(opcions)/sizeof(char *); i++){
    if (highlight == i+1){ 	/* il·lumina aquesta opció */
      wattron(menu_win,A_REVERSE);
      mvwprintw(menu_win,y,x,"%s",opcions[i]);
      wattroff(menu_win,A_REVERSE);
    } else {
      mvwprintw(menu_win,y,x,"%s",opcions[i]);
    }
    y++;
  }
  wrefresh(menu_win);
  
  return x;
}
