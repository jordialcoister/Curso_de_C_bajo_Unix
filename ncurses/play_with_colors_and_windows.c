#include <ncurses.h>
#include <stdlib.h>

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
  WINDOW *corner_wins[4],*a_win;
    
  initscr();
  if (!has_colors() || !can_change_color()){
    printf("El teu terminal no admet colors o no permet canviar-los.\n");
    exit(1);
  }
  start_color();
  getmaxyx(stdscr,max_rows,max_columns);
  win_width=max_columns/2;
  win_height=max_rows/2;
  /* max_rows--; */
  /* max_columns--; */
  /* for(int i=0;i<4;i++){ */
  /*   int y,x; */
    
  /*   y=win_height*i+1; */
  /*   x=max_columns/2*i; */
  /*   corner_wins[i]=newwin(win_height,win_width,y,x); */
  /*   wprintw(corner_wins[i],"Hello from upper-left corner!"); */
  /*   /\* box(corner_wins[i],0,0); *\/ */
  /*   wrefresh(corner_wins[i]); */
  /* } */
  a_win=newwin(20,20,25,80);
  if(a_win){
    waddstr(a_win,"Hello, I'm a window!");
  }
  wrefresh(a_win);
  getch();
  init_color(COLOR_YELLOW,1000,1000,0);
  init_color(COLOR_PURPLE,500,0,1000);
  init_color(COLOR_ROSE,1000,0,500);
  init_color(COLOR_ORANGE,1000,500,0);
  init_color(COLOR_SKYBLUE,0,500,1000);
  init_color(COLOR_OCEANGREEN,0,1000,500);
  init_color(COLOR_LEAFGREEN,500,1000,0);
  init_color(COLOR_GRAY,500,500,500);
  init_color(COLOR_PUREWHITE,1000,1000,1000);
  /* init_pair(1,COLOR_OCEANGREEN,COLOR_BLACK); */
  for (int i=0; i<16; ++i){
    init_pair(i,i,COLOR_BLACK);
    attron(COLOR_PAIR(i));
    for (int j=0; j<max_columns; j+=10){
      mvprintw(i,j,"color i,j");
    }
    attroff(COLOR_PAIR(1));
  }
  /* init_pair(1,COLOR_OCEANGREEN,COLOR_SKYBLUE); */
  init_pair(16,COLOR_YELLOW,COLOR_PURPLE);
  attron(COLOR_PAIR(16));
  mvprintw(LINES-2,0,"Combine colors that are next to each other to get a pleasant view.\n");
  attroff(COLOR_PAIR(16));  
  getch();
  endwin();
  return 0;
}
