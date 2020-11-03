#include <stdio.h>
#include "../include/display.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
	SettingsPtr my_settings = (SettingsPtr)(malloc(sizeof(Settings)));
	my_settings->mode = 0;
	enum { SINGLE_PLAYER, TWO_PLAYERS } mode = TWO_PLAYERS;
	int opt;
	opterr = 0;
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
	printf("my settings mode = %d", my_settings->mode);	
	return 0;
}





