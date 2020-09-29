//
// Created by Hanry Ham on 11/26/18.
//
//	William Gunawan   <2201765183>
//	Andre Hendratanto <2201763871>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char player[5][5];
const char map[30][30]=
{
	{'=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','='},
	{'|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|','|',' ','_','|'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	{'=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','=','='},
};
int len=5;              // Init size of grid. Ex: 5x5 grid/table
int ctrPl1=0, ctrPl2=0; // Variable to track the marker counter
int flagWin=0;          // Flag for track who is the winner.
// 0: Nobody win yet;
// 1: Player 1 win;
// 2: Player 2 win;

int checkDiagonalLeft(){
    // A function to check the markers starts from upper left to lower right
    if(player[0][0] == 'X' && player[1][1] == 'X' && player[2][2] == 'X' && player[3][3] == 'X' && player[4][4] == 'X')
    {
    	flagWin = 1;
	}
	if(player[0][0] == 'O' && player[1][1] == 'O' && player[2][2] == 'O' && player[3][3] == 'O' && player[4][4] == 'O')
    {
    	flagWin = 2;
	}
    return flagWin;
}

int checkDiagonalRight(){
    // A function to check the markers starts from upper right to lower left
     if(player[4][0] == 'X' && player[3][1] == 'X' && player[2][2] == 'X' && player[1][3] == 'X' && player[0][4] == 'X')
    {
    	flagWin = 1;
	}
	if(player[4][0] == 'O' && player[3][1] == 'O' && player[2][2] == 'O' && player[1][3] == 'O' && player[0][4] == 'O')
    {
    	flagWin = 2;
	}
    return flagWin;
}

int checkHorizontal(){
	for(int a=0;a<5;a++)
	{
		if(player[a][0] == 'X' && player[a][1] == 'X' && player[a][2] == 'X' && player[a][3] == 'X' && player[a][4] == 'X')
		{
			flagWin = 1;
			break;
		}
		else if(player[a][0] == 'O' && player[a][1] == 'O' && player[a][2] == 'O' && player[a][3] == 'O' && player[a][4] == 'O')
		{
			flagWin = 2;
			break;
		}
	}
    // A function to check the markers in horizontal way
    return flagWin;
}

int checkVertical(){
    // A function to check the markers in vertical way
    for(int a=0;a<5;a++)
	{
		if(player[0][a] == 'X' && player[1][a] == 'X' && player[2][a] == 'X' && player[3][a] == 'X' && player[4][a] == 'X')
		{
			flagWin = 1;
			break;
		}
		else if(player[0][a] == 'O' && player[1][a] == 'O' && player[2][a] == 'O' && player[3][a] == 'O' && player[4][a] == 'O')
		{
			flagWin = 2;
			break;
		}
	}
    return flagWin;
}

int win(){
    // A main function to check the markers in all conditions
    if(checkDiagonalLeft()!=0) return flagWin;
    else if(checkDiagonalRight()!=0) return flagWin;
    else if(checkHorizontal()!=0) return flagWin;
    else if(checkVertical()!=0) return flagWin;
    return flagWin;
}

int checkDiagonalLeftDraw(){
	char temp = '\0';
	for(int a=0; a<5; a++)
	{
		if(player[a][a] == 'X' || player[a][a] == 'O')
		{
			if(temp == '\0')
				temp = player[a][a];
			else
			{
				if(temp != player[a][a])
					return 1;
			}
		}
	}
	return 0;
}

int checkDiagonalRightDraw(){
	char temp = '\0';
	for(int a=0; a<5; a++)
	{
		if(player[4-a][a] == 'X' || player[4-a][a] == 'O')
		{
			if(temp == '\0')
				temp = player[4-a][a];
			else
			{
				if(temp != player[4-a][a])
					return 1;
			}
		}
	}
	return 0;
}

int checkHorizontalDraw(){
	int total = 0;
	char temp;
	for(int a=0; a<5; a++)
	{
		temp = '\0';
		for(int b=0; b<5; b++)
		{
			if(player[a][b] == 'X' || player[a][b] == 'O')
			{
				if(temp == '\0')
					temp = player[a][b];
				else
				{
					if(temp != player[a][b])
						{
							total += 1;
							break;
						}
				}
			}
		}
	}
	return total;
}

int checkVerticalDraw(){
	int total = 0;
	char temp;
	for(int a=0; a<5; a++)
	{
		temp = '\0';
		for(int b=0; b<5; b++)
		{
			if(player[b][a] == 'X' || player[b][a] == 'O')
			{
				if(temp == '\0')
					temp = player[b][a];
				else
				{
					if(temp != player[b][a])
					{
						total += 1;
						break;
					}
				}
			}
		}
	}
	return total;
}

int draw(){
	if((checkDiagonalLeftDraw() + checkDiagonalRightDraw() + checkHorizontalDraw() + checkVerticalDraw()) >= 12) return 1;
	return 0;
}

void clrscr(){
    //Function to execute clear screen
    for(int i=0;i<25;i++){
        printf("\n");
    }
}

void movePlayer1(){
	int X,Y,flag;
	do
	{
		flag=0;
		printf("Player 1' turn (X)\nX coordinate: ");
		scanf("%d",&X); getchar();
		printf("Y coordinate: ");
		scanf("%d",&Y); getchar();
		if(player[Y-1][X-1] !='X' && player[Y-1][X-1] !='O' && X >= 1 && X <= 5 && Y >= 1 && Y <= 5)
		{
			player[Y-1][X-1] = 'X';
		}
		else
		{
			flag = 1;
			printf("The coordinate is filled. Try another coordinate!\n");
			getchar();
		}
	} while(flag==1);
    // Action to perform Player 1's turn
}

void movePlayer2(){
	int X,Y,flag;
	do
	{
		flag = 0;
		printf("Player 2' turn (O)\nX coordinate: ");
		scanf("%d",&X); getchar();
		printf("Y coordinate: ");
		scanf("%d",&Y); getchar();
		if(player[Y-1][X-1] !='X' && player[Y-1][X-1] !='O' && X >= 1 && X <= 5 && Y >= 1 && Y <= 5)
		{
			player[Y-1][X-1] = 'O';
		}
		else
		{
			flag = 1;
			printf("The coordinate is filled. Try another coordinate!\n");
			getchar();
		}
	} while(flag==1);
    // Action to perform Player 2's turn
}

bool validateMap(){
	if(checkDiagonalLeft() || checkDiagonalRight() || checkHorizontal() || checkVertical())
		return false;
	for (int a=0; a<5; a++)
	{
		for (int b=0; b<5; b++)
		{
			if (player[a][b] ==' ')
			{
				return true;
			}
		}
	}
	return false;
    // A function to validate whether the map is still has empty coordinate or not
}

void clearMap(){
	for (int a=0; a<5; a++)
	{
		for (int b=0; b<5; b++)
		{
			player[a][b]=' ';
		}
	}
    // A function is used to clear all the grid
}

void printMap(){
	int X=0,Y=0;
	for (int a=0; a<12; a++)
	{
		for (int b=0; b<21; b++)
		{
			if (map[a][b]=='_')
			{
				printf("%c",player[Y][X]);
				X++;
				if(X>4)
				{
					X=0;
					Y++;
				}
				
			}
			else
			{
				printf("%c",map[a][b]);
			}
		}
		printf("\n");
	}
    // A function to print all the grid
}

int main()
{
    int checkWin = 0; // A Variable to track who is the winner
    int checkMap = 0; // A variable to track the maps is still empty
    char retry[10]; //User input for retry
    bool player1; //Flag to track the player's turn
    do
	{
		retry[0] = '\0';
		player1 = true;
		flagWin=0;
		clrscr();
		clearMap();
        do
		{
			// Code to run player's turn
			clrscr();
			printf("TIC TAC TOE\n");
			printMap();
			printf("\n");
			if(player1)
			{
            	movePlayer1();
            	player1 = false;
            }
            else
            {
            	movePlayer2();
            	player1 = true;
            }
            if(win())
            	break;
		} while (validateMap() && !win() && !draw()); //validate if someone win or map is full
    	clrscr();
    	printf("TIC TAC TOE\n");
		printMap();
		if(win())
    		printf("Player %d Win!\n", flagWin);
    	else
    		printf("Draw!\n");
    	getchar();
    	do
    	{
    		printf("\nDo you want to retry[Yes|No]: ");
    		scanf("%s", retry);
    		getchar();
    	} while(strcmp(retry, "Yes") != 0 && strcmp(retry, "No") != 0);
	    if(strcmp(retry, "Yes") == 0)
	    	getchar();
    } while(strcmp(retry, "Yes") == 0); //validate retry
    getchar();
    return 0;
}
