#include<iostream>
#define EMPTYCELL ' '
using namespace std;

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

int main(){
	char board[3][3];
	int a,b;
	char player_turn='1';
	initialize(board);
	printBoard(board);
	
	for(int i=0; i<9; i++){
		cout << "Player " << player_turn << " Enter Row and Column range(0-2) at which you want to give Input( ): ";
		cin >> a >> b;
		board[a][b] = player_turn;
		printBoard(board);
		if (checkFirstDiagonal(board,player_turn)==1)		goto finish;
		else if (checkSecondDiagonal(board,player_turn)==1) goto finish;
		else if (checkFirstRow(board,player_turn)==1) 		goto finish;
		else if (checkSecondRow(board,player_turn)==1) 		goto finish;
		else if (checkThirdRow(board,player_turn)==1) 		goto finish;
		else if (checkFirstColumn(board,player_turn)==1) 	goto finish;
		else if (checkSecondColumn(board,player_turn)==1) 	goto finish;
		else if (checkThirdColumn(board,player_turn)==1) 	goto finish;
		else if( player_turn=='1' )	player_turn='2';
		else	player_turn='1';
	}
	cout << "Match Draw" << endl;
	return 0;
	finish:
	cout << "Player " << player_turn << " Won the Game" << endl;
	return 0;
}
