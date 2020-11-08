#include "../include/display.h"


void displayMenu(){
	clear();
	printf("\n===========================\n====== TIC TAC TOE GAME ========\n===========================\n");
}


void displayHelp(){
	displayMenu();
	printf("\n-h  get help on the game\n");
	printf("-b  to play with the bot \n");
}



void displayBoard(int *board){
	displayMenu();
	for(int i = 0; i < 3; i++){
		int arr[3] = {board[i*3], board[i*3 + 1], board[i*3+2]};
		for(int j = 0; j < 3; j++){
			if(arr[j] == -1){
				arr[j] = i*3 + j + 1;
			}
		}
			printf("\n\t %d  | %d  | %d  \n\t____|____|____",arr[0],arr[1],arr[2]);
		
	}

}



void StartSession(char *pl1, char *pl2){
	GameSettingPtr game = (GameSetting*)(malloc(sizeof(GameSetting)));
	game->pl1 = pl1;
	game->pl2 = pl2;
	while(confirm()){
		StartGame(game);
		printStat(game);	
	}

}


int StartGame(GameSettingPtr game){
	int board[9] = {[0 ... 8] = -1};
	int turn = 1;
	displayBoard(board);
	while(1){
		makemove(board, turn);
		displayBoard(board);
		if(checkBoard(board) == 1){
			printf("\n\n Game Over  !!! %s won the game \n", playerByTurn(turn, game));
			return 1;
		};
		turn++;
	}
	printf("\n\n TIE! Nobody wins!\n");
			
}


int checkBoard(int *arr){
	int combs[8][3] = {
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}	
	};
	for(int i = 0; i < 8; i++){
		if(arr[combs[i][0]] == arr[combs[i][1]]  &&  arr[combs[i][1]] == arr[combs[i][2]] && arr[combs[i][0]] != -1){
			return 1;
		}
	}	
	return 0;
}


int *makemove( int *arr, int turn){
	int a;
	while(1){
		printf("\n\nPlease make your move ( 1 - 9 ) ! \n");
		scanf("%d",&a);
		if(a > 0 && a < 10 && arr[a-1] != 1 && arr[a-1] != 0){
			break;	
		}
		printf("Invalid Move! "); 

	}
	arr[a-1] = (turn % 2 == 0)? 1 : 0;
	
}

char *playerByTurn(int num, GameSettingPtr game){
	if(num % 2 != 0){
		game->pl1_win++;
		return game->pl1;	
	}
	game->pl2_win++;
	return game->pl2;	
}


void printStat(GameSettingPtr game){
	printf("Name: %s , Score: %d \n\nName: %s , Score: %d\n\n",game->pl1, game->pl1_win, game->pl2, game->pl2_win);

}

int confirm(){
	printf("\nWant to play another game? (y/n)\n");
	int i;
	scanf("%d", &i);
		if(i == 1){
			return 1;
		}
	return 0;
}
