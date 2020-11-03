#ifndef _display_h
#define _display_h

#include <stdio.h>
#include <stdlib.h>

#define clear() system("clear")

typedef struct Settings{
	int mode; // 0 - single player, 1 - twoplayers

}Settings;
typedef Settings* SettingsPtr;


void displayMenu();
void displayHelp();

#endif
