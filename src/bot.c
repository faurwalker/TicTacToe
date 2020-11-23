#include "../include/bot.h"
#include "../include/display.h"



void StartBotGame(GameSettingPtr game){
			
}

void BotMakeMove(int *arr, GameSettingPtr game){
	int best = 0, pos = 0;
	for(int i = 0; i < 9; i++){	
		int current = CheckPos(arr,i);
		if(current > best){
			best = current;	
			pos = i;
		}	
	}
	arr[pos] = 0;

	
}

// Check position of grid to get the prior value
int CheckPos(int *arr, int pos){
	int best = 0;
	int patterns[8][3] = {
		{0,1,2},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{3,4,5},
		{6,7,8},
		{2,4,6},
		{0,4,8}	
	};

	for(int i = 0; i < 8; i++){
		int count = 0;
		if(arr[pos] != 1 && arr[pos] != 0 && (patterns[i][0] == pos || patterns[i][1] == pos || patterns[i][2] == pos)){
			for(int k = 0; k < 3; k++){
				if(arr[patterns[i][k]] == 0 || arr[patterns[i][k]] == -1){
					count++;
				} else {
					count--;	
				}			
			}
			if(count > best){
				best = count;
			}	
		}
	}
	return best;	
}

