#include<iostream>
#define EMPTYCELL ' '
using namespace std;

char player_turn='A';
//0,0 | 0,1 | 0,2
//1,0 | 1,1 | 1,2
//2,0 | 2,1 | 2,2	
void initialize(char b[][3]){
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			b[i][j]=EMPTYCELL;
}
void printBoard(char b[][3]){
	for (int i=0;i<3;i++){	
		for (int j=0;j<3;j++)
			cout << b[i][j] << "|";
	cout << endl;}	
}
int checkFirstDiagonal(char b[][3], char ch){
	if(b[0][0]==ch && b[1][1]==ch && b[2][2]==ch)	return 1;
	else 							return 0;
}
int checkSecondDiagonal(char b[][3], char ch){
	if(b[0][2]==ch && b[1][1]==ch && b[2][0]==ch)	return 1;
	else 							return 0;
}
int checkFirstRow(char b[][3], char ch){
	if(b[0][0]==ch && b[0][1]==ch && b[0][2]==ch)	return 1;
	else 							return 0;
}
int checkSecondRow(char b[][3], char ch){
	if(b[1][0]==ch && b[1][1]==ch && b[1][2]==ch)	return 1;
	else 							return 0;
}
int checkThirdRow(char b[][3], char ch){
	if(b[2][0]==ch && b[2][1]==ch && b[2][2]==ch)	return 1;
	else 							return 0;
}
int checkFirstColumn(char b[][3], char ch){
	if(b[0][0]==ch && b[1][0]==ch && b[2][0]==ch)	return 1;
	else 							return 0;
}
int checkSecondColumn(char b[][3], char ch){
	if(b[0][1]==ch && b[1][1]==ch && b[2][1]==ch)	return 1;
	else 							return 0;
}
int checkThirdColumn(char b[][3], char ch){
	if(b[0][2]==ch && b[1][2]==ch && b[2][2]==ch)	return 1;
	else 							return 0;
}

int getValidInput (char b[][3], char player){
	int i,j;
	cout << "Player " << player << " Enter Row and Column range(0-2) at which you want to give Input( ): ";
	cin >> i >> j;
	if( i<3 && j<3 && b[i][j]==' ') {
		b[i][j] = player;
		return 1;
	}
	else 							return 0;
}

int play (char board[][3]){
	start:
		if( getValidInput(board, player_turn)==1)
			printBoard(board);	
		else							goto start;					
		if ( checkFirstDiagonal(board,player_turn)==1 || checkSecondDiagonal(board,player_turn)==1 ||  
		checkFirstRow(board,player_turn)==1 || checkSecondRow(board,player_turn)==1 ||
		checkThirdRow(board,player_turn)==1 || checkFirstColumn(board,player_turn)==1 ||
		checkSecondColumn(board,player_turn)==1 || checkThirdColumn(board,player_turn)==1 ) {
			cout << "Player " << player_turn << " Won the Game" << endl;
			return 0; }
		else if( player_turn=='A' )	player_turn='B';
		else 	player_turn='A';
}

int main(){
	char board[3][3];
	initialize(board);
	printBoard(board);
	for(int i=0; i<9; i++){
		if (play(board)==0) goto finish;
	}
	cout << "Match Draw" << endl;
	finish:
	return 0;
}
