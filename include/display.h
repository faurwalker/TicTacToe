#ifndef _display_h
#define _display_h

#include <stdio.h>
#include <stdlib.h>

#define clear() system("clear")

typedef struct Settings{
	int mode; // 0 - single player, 1 - twoplayers

}Settings;
typedef Settings* SettingsPtr;


typedef struct User{
	char name[15];
	int games_played;
	int games_won;
}User;

typedef User* UserPtr;

typedef struct Game{
	char *fuser; 
}Game;


void displayMenu();
void displayHelp();
void StartGame();
void displayBoard();
int checkBoard();
int *makemove();
#endif
