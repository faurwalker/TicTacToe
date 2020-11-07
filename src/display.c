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


void StartGame(){
	int board[9] = {[0 ... 8] = -1};
	int turn = 1;
	while(1){
		displayBoard(board);
		makemove(board, turn);
		if(checkBoard(board) == 1){
			printf("\n Game Over  !!!");
			break;	
		};
		turn++;
	}
			
}


int checkBoard(char *arr){
	int combs[][3] = {
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
		if(arr[combs[i][0]] == arr[combs[i][1]] && arr[combs[i][1]] == arr[combs[i][2]] && arr[combs[i][0]] != -1){
			return 1;
		}
	}	
	return 0;
}


int *makemove( int *arr, int turn){
	int a;
	while(1){
		printf("Please make your move ( 1 - 9 ) ! \n");
		scanf("%d",&a);
		if(a > 0 && a < 10 && arr[a-1] != 1 && arr[a-1] != 0){
			break;	
		}
		printf("Invalid Move! "); 

	}
	arr[a-1] = (turn % 2 == 0)? 1 : 0;
	
}

