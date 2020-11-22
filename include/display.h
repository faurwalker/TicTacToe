#ifndef _display_h
#define _display_h

#include <stdio.h>
#include <stdlib.h>

#define clear() system("clear")


typedef struct GameSetting{
	char *pl1;
	char *pl2;

	int games_played;
	int pl1_win;
	int pl2_win;

}GameSetting;

typedef GameSetting* GameSettingPtr;



void displayMenu();
void displayHelp();
int StartGame();
void displayBoard();
int checkBoard();
int *makemove();
void StartSession();
void printStat();
char *playerByTurn();
int confirm();
#endif
