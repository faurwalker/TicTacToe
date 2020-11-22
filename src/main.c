#include <stdio.h>
#include "../include/display.h"
#include "../include/bot.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
	SettingsPtr my_settings = (SettingsPtr)(malloc(sizeof(Settings)));
	enum { SINGLE_PLAYER, TWO_PLAYERS } mode = TWO_PLAYERS;
	int opt;
	opterr = 0;
	char player1[] = "Player1";
	char player2[] = "Player2";
	my_settings->mode = 0;
	my_settings->pl2 = player1;
	my_settings->pl2 = player2;

	while((opt = getopt(argc, argv, "hb")) != -1){
		switch(opt){
			case 'h':
				displayHelp();
				break;
			case 'b':
				my_settings->mode = 1;
				mode = SINGLE_PLAYER;
				break;
			default:
				printf("Your flag option '-%c' is incorrect!  \n", optopt);	
		}	
	}	
	StartSession(my_settings);
	return 0;
}





