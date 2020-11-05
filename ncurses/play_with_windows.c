#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_PURPLE 8
#define COLOR_ROSE 9
#define COLOR_ORANGE 10
#define COLOR_SKYBLUE 11
#define COLOR_OCEANGREEN 12
#define COLOR_LEAFGREEN 13
#define COLOR_GRAY 14
#define COLOR_PUREWHITE 15

int main()
{
  int max_rows, max_columns, win_width, win_height;
  int startx,starty,height,width,k=0;
  WINDOW *corner_wins[4],*a_win;
  static char str[]="Hello, I'm a Window!";
  
  initscr();
  height = 5;
  width = 30;
  starty = (LINES - height) / 2;	/* Calculating for a center placement */
  startx = (COLS - width) / 2;	/* of the window		*/
  printw("Press F1 to exit");
  refresh();
  a_win=newwin(height,width,starty,startx);
  if(a_win){
    box(a_win,0,0);
    mvwprintw(a_win,height/2,(width-strlen(str))/2,"Hello, I'm a window!");
  }
  wrefresh(a_win);
  wborder(a_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wrefresh(a_win);
  delwin(a_win);
  win_width=COLS/2;
  win_height=LINES/2;
  starty=0;
  for (int i=0; i<2; i++){
    for (int j=0; j<2; j++){
      starty=LINES/2*i;
      startx=COLS/2*j;
      corner_wins[k]=newwin(win_height,win_width,starty,startx);
      if(corner_wins[k]){
	box(corner_wins[k],0,0);
	/* wborder(a_win, '|', '|', '-', '-', '+', '+', '+', '+'); */
	mvwprintw(corner_wins[k],win_height/2,(win_width-strlen(str))/2,"Hello, I'm window #%i!",k);
      }
      wrefresh(corner_wins[k]);
      k++;
    }
  }
  getch();
  endwin();
  return 0;
}
