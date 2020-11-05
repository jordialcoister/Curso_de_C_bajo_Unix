# Makefile
LDFLAGS=-lpanel -lmenu -lncurses
CC=gcc

all: simple_keyuse_example.c
	$(CC) -o simple_keyuse_example simple_keyuse_example.c $(LDFLAGS)

panel1: panel_basics.c
	$(CC) -o panel1 panel_basics.c $(LDFLAGS)

panel2: panel_window_browsing.c
	$(CC) -o panel2 panel_window_browsing.c $(LDFLAGS)

colors: play_with_colors.c
	$(CC) -o colors play_with_colors.c $(LDFLAGS)

colors_and_wins: play_with_colors_and_windows.c
	$(CC) -o colors_and_wins play_with_colors_and_windows.c -lncurses

windows: play_with_windows.c
	$(CC) -o windows play_with_windows.c -lncurses

menu: play_with_keys.c
	$(CC) -o menu play_with_keys.c -lncurses

menu_mouse: play_with_mouse.c
	$(CC) -o menu_mouse play_with_mouse.c -lncurses

nifty_chars: ACS_chars_example.c
	$(CC) -o nifty_chars ACS_chars_example.c -lncurses

temp_living: temporary_leaving_curses.c
	$(CC) -o temporary_leaving_curses temporary_leaving_curses.c $(LDFLAGS)

play_with_menus: play_with_menus.c
	$(CC) -o play_with_menus play_with_menus.c -lmenu -lncurses

menu_with_window: menu_with_window.c
	$(CC) -o menu_with_window menu_with_window.c -lmenu -lncurses

scrolling_menu: scrolling_menus.c
	$(CC) -o scrolling_menus scrolling_menus.c -lmenu -lncurses

multicol_menu_win: multicol_menu_win.c
	$(CC) -o multicol_menu_win multicol_menu_win.c  -lmenu -lncurses
