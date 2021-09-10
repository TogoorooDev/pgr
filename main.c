/*
  This file is part of pgr
  Copyright (c) 2021 Luna Hensley

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation; either version 2 of the License, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc., 675
  Mass Ave, Cambridge, MA 02139, USA.
 */
#include <stdio.h>
#include <string.h> 
#include <curses.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>

#define CHUNK_SIZE 8

void screen_init(void){
  initscr(); // init
  cbreak(); // program can read keys without needing a newline
  noecho(); // do not echo characters
  nonl(); // not sure what this one does, but manpage told me to use it
  intrflush(stdscr, FALSE); //
  keypad(stdscr, TRUE); // allow special keys (such as arrows)  
}

void escape_strat(void){

}

void color_init(void){
  if (start_color() != OK) puts("Color got borked");
  init_pair(0, COLOR_WHITE, COLOR_BLACK); // Black background, white text
  init_pair(1, COLOR_BLACK, COLOR_WHITE); // White background, black text
}

ssize_t read_stdin_wrapper(char *line, unsigned int size){
  ssize_t read_count = read(0, line, --size);
  line[read_count] = '\0';
  return read_count;
}

void read_stdin_full(char **stdin_buf){
  int rc_call_count = 0;
  char *mini_buf = calloc(1, CHUNK_SIZE);
  while (1){
    if (read_stdin_wrapper(mini_buf, CHUNK_SIZE) <= 0) break;
    *stdin_buf = realloc(*stdin_buf, (sizeof(char) * CHUNK_SIZE) * ++rc_call_count);
    strcat(*stdin_buf, mini_buf);
  }
}

void main_loop(char *stdin){
  while (1){
    char ch = getch();
    //printf("%d\n", ch);
  }
}

int main(){
  //screen_init();
  //color_init();

  char *stdin = (char *) calloc(1, sizeof(char) * CHUNK_SIZE);
  read_stdin_full(&stdin);

  main_loop(stdin);
  
  //printw("%s", line);
  //refresh();

  //getch();
  //endwin();
  free(stdin);
  return 0;
}
