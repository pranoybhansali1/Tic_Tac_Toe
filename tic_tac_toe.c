#include<stdio.h>
#include<windows.h>

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

char square[10]={'o','1','2','3','4','5','6','7','8','9'};

void intro(void)
{
	system("COLOR F0");
	gotoxy(70,5);
	printf("--------WELCOME--------\n\n\n");
	gotoxy(80,15); printf("TIC");
	gotoxy(77,17); printf("X-O-X-O-X");
	gotoxy(80,19); printf("TAC");
	gotoxy(77,21); printf("O-X-O-X-O");
	gotoxy(80,23); printf("TOE");
	getch();
}

void move(int x,int y)
{
	int i;
	gotoxy(x,y);
	printf("TIC----TAC----TOE\n\n");
	//printf("_________________");
	i=3;
	gotoxy(x,y+i);printf("     |     |     \n");i++;
	gotoxy(x,y+i);printf("  %c  |  %c  |  %c  \n",square[1],square[2],square[3]);i++;
	gotoxy(x,y+i);printf( "_____|_____|_____\n");i++;
	gotoxy(x,y+i);printf("     |     |     \n");i++;
	gotoxy(x,y+i);printf("  %c  |  %c  |  %c  \n",square[4],square[5],square[6]);i++;
	gotoxy(x,y+i);printf( "_____|_____|_____\n");i++;
	gotoxy(x,y+i);printf("     |     |     \n");i++;
	gotoxy(x,y+i);printf("  %c  |  %c  |  %c  \n",square[7],square[8],square[9]);i++;
	gotoxy(x,y+i);printf("     |     |     \n");
}

void board(void)
{
	system("cls");
	gotoxy(70,15);
	printf("TIC----TAC----TOE\n\n");
	//printf("_________________");
	gotoxy(70,18);printf("     |     |     \n");
	gotoxy(70,19);printf("  %c  |  %c  |  %c  \n",square[1],square[2],square[3]);
	gotoxy(70,20);printf( "_____|_____|_____\n");
	gotoxy(70,21);printf("     |     |     \n");
	gotoxy(70,22);printf("  %c  |  %c  |  %c  \n",square[4],square[5],square[6]);
	gotoxy(70,23);printf( "_____|_____|_____\n");
	gotoxy(70,24);printf("     |     |     \n");
	gotoxy(70,25);printf("  %c  |  %c  |  %c  \n",square[7],square[8],square[9]);	
	gotoxy(70,26);printf("     |     |     \n\n\n");
}

int checkwin(void)
{
	if(square[1]==square[2] && square[2]==square[3])return 1;
	else if(square[4]==square[5] && square[5]==square[6])return 1;
	else if(square[7]==square[8] && square[8]==square[9])return 1;
	else if(square[1]==square[4] && square[4]==square[7])return 1;
	else if(square[2]==square[5] && square[5]==square[8])return 1;
	else if(square[3]==square[6] && square[6]==square[9])return 1;
	else if(square[1]==square[5] && square[5]==square[9])return 1;
	else if(square[3]==square[5] && square[5]==square[7])return 1;
	else if(square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9')return 0;
	else return -1;
}

void game()
{
	int i,player=1,choice;
	char mark;
	char p1[10],p2[10];
	printf("\nEnter Player 1 Name: ");
	fflush(stdin);
	scanf("%s",p1);
	printf("\nEnter Player 2 Name: ");
	fflush(stdin);
	scanf("%s",p2);
	do{
		board();
		player=(player%2)?1:2;
		if(player==1)printf("%s",p1);
		else
		printf("%s",p2);
		printf(" Your Turn: ");
		scanf("%d",&choice);
		mark=(player==1)?'X':'O';
		
		if(choice==1 && square[1]=='1')square[1]=mark;
		else if(choice==2 && square[2]=='2')square[2]=mark;
		else if(choice==3 && square[3]=='3')square[3]=mark;
		else if(choice==4 && square[4]=='4')square[4]=mark;
		else if(choice==5 && square[5]=='5')square[5]=mark;
		else if(choice==6 && square[6]=='6')square[6]=mark;
		else if(choice==7 && square[7]=='7')square[7]=mark;
		else if(choice==8 && square[8]=='8')square[8]=mark;
		else if(choice==9 && square[9]=='9')square[9]=mark;
		else 
		{	
			printf("\nInvalid move. . .");
			player--;
			getch();
		}
		i=checkwin();
		player++;
	}while(i==-1);
	board();
	if(i==0){
		gotoxy(71,31);printf("Match Drawn....");
		gotoxy(0,45);
		//exit(1);
	}
	else 
	{
		if(player==2)
		{
			gotoxy(72,31);printf("%s Wins..!!",p1);
			gotoxy(0,45);
		}
		else
		{
			gotoxy(72,31);printf("%s Wins..!!",p2);
			gotoxy(0,45);
		}
		//printf(" Wins..!!");
		//exit(1);
	}
}

void main()
{
	//char c='y';
	intro();
	system("cls");
	game();
	//do
	//while(c=='Y' || c=='y')
	//{		
		//game();
		//printf("\n\nDo you want to play again(Y/N): ");
		//c=getchar();
		//getch();
	//}//while(c=='Y' || c=='y');
	getch();
}
