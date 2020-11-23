#ifndef _bot_h
#define _bot_h
#include <stdio.h>


typedef struct Settings {
	int mode;  // 0 - single players, 1 - two players 
	char *pl1;
	char *pl2;
}Settings;

typedef Settings* SettingsPtr;

void StartBotGame();
void BotMakeMove();
int CheckPos();
#endif
