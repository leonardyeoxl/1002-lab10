#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define EMPTY 2
#define X_VALUE 3
#define O_VALUE 5
#define BOARD_SIZE 10
#define GAME_SIZE 3
#define MAX_PLAYERS 10

void menu();
void move_to(int n);
void start_game();
void check_draw();
void draw_board();
void player_turn();
void put_X_O(char, int , int );
void initialize_screen();
int isWinning(int);
int getPossibleWinningPos();
int getWinningPos(int);
int convert_pos_to_row(int);
int convert_pos_to_col(int);
int convert_row_col_to_pos(int, int);
void initialize_game_board();



