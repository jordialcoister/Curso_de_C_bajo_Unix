#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

#define WIDTH 30
#define HEIGHT 10

int startx=0, starty=0;

char *choices[] = {
	"Opció 1",
	"Opció 2",
	"Opció 3",
	"Opció 4",
	"Eixida",
};


static void finish(int sig);
void print_menu(WINDOW *menu_win,int highlight);
int n_choices = sizeof(choices)/sizeof(char *);
int report_choice(int mouse_y, int mouse_x);

int main()
{
	WINDOW *menu_win;
	MEVENT event;
	int mouse_x, mouse_y,highlight=1,choice=0,c,i=0;

	/* arrange interrupts to terminate */
	(void) signal(SIGINT, finish);
	
	initscr();
	/* clear(); */
	noecho();
	cbreak();

	/* Centrem el menú */
	startx = (COLS - WIDTH)/2;
	starty = (LINES - HEIGHT)/2;

	menu_win=newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win,TRUE);
	mvprintw(0,0,"starty: %i, startx: %i, n_choices=%i",starty,startx,n_choices);
	mvprintw(2,0,"Utilitza les fletxes amunt i avall per a navegar per les opcions.");
	refresh();
	print_menu(menu_win,1);
  
	/* Recollim tots els events del ratolí */
	mousemask(ALL_MOUSE_EVENTS, NULL);
  
	do{
		c=wgetch(menu_win);
		switch (c) {
		case KEY_MOUSE: {
			if (getmouse(&event) == OK) {
				if (event.bstate & BUTTON1_CLICKED){
					/* choice=report_choice(event.x, event.y); */
					for (c=0; c<n_choices;c++){
						if (event.y == starty+2+c  && event.x > startx+2 && event.x <= startx+2+strlen(choices[c] )){
							choice=++c;
							mvprintw(c,0,"Has triat la opció %i.",choice);
							highlight = choice;
						}
					}
				}
				i++;
			}
			refresh();
			break;
		}
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
	/* } while (!choice); */
	} while (choice != n_choices);
	delwin(menu_win);
	endwin();
	return 0;
}

void print_menu(WINDOW *menu_win, int highlight){
	int x=2,y=2,i=0;

	box(menu_win,0,0);
	for (i=0; i<n_choices; i++){
		if (highlight == i+1){ 	/* il·lumina aquesta opció */
			wattron(menu_win,A_REVERSE);
			mvwprintw(menu_win,y,x,"%s",choices[i]);
			wattroff(menu_win,A_REVERSE);
		} else {
			mvwprintw(menu_win,y,x,"%s",choices[i]);
		}
		y++;
	}
	wrefresh(menu_win);
}

int report_choice(int mouse_x, int mouse_y){
	int i,j,choice;

	i = startx+1;
	j = starty+1;

	for ( choice=0; choice<n_choices; choice++){
		mvprintw(LINES-choice,0,"Coordenades del clic: y=%i, x=%i, opció=%i",mouse_y,mouse_x,choice);
		/* if ( mouse_y >= j + choice && mouse_x >= i && mouse_x < i+strlen(choices[choice])){ */
		refresh();
		if (mouse_y > j && mouse_y <= j + n_choices){
			if (mouse_x> i && mouse_x <= i + strlen(choices[choice])){
				mvprintw(LINES-4,0,"S'ha premut el botó 1 del mouse dins del menú");
				if ( choice == (n_choices-1))
					return -1;
				else 
					return choice;
			}
		}
	}
}


static void finish(int sig)
{
    endwin();

    /* do your non-curses wrapup here; see Listing 2 */

    exit(0);
}
