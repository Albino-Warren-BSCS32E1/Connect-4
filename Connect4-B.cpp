using namespace std;
#define LEFT 75
#define RIGHT 77
#define ROW 7
#define COLUMN 6

int table[ROW][COLUMN];
void game();
int p1 = 1, p2 =2;
int x, y; //graphics board
int row,col; //progView
int input;
int player;
int winp1, winp2;
int xmax, ymax;

void initG(){
	//initialize window
	int gd=DETECT, gm;
	initgraph(&gd, &gm, "");
	
	while(1)
	{
	setcolor(11);
	settextstyle(10,0,5);
	outtextxy(190, 199.5, "Connect 4");
	setcolor(4);
	settextstyle(3, 0, 1);
	outtextxy(225, 265, "Press spacebar to play!");
	
	
	setcolor(5);
	setlinestyle(3,0, 15);
    rectangle(0,479,639,1);
	setlinestyle(0,0,0);
	
	setcolor(YELLOW);
	line(300,100,200,200);
	line(300,100,400,200);
	line(200,200,400,200);
	
	setcolor(RED);
	line(0,0,200,200);
	setcolor(YELLOW);
	line(0,0,220,180);
	setcolor(GREEN);
	line(0,0,240,160);
	setcolor(CYAN);
	line(0,0,260,140);
	setcolor(BLUE);
	line(0,0,280,120);
	setcolor(MAGENTA);
	line(0,0,300,100);
	
	setcolor(WHITE);
	settextstyle(3,0,1);
	outtextxy(20,360, "Created by: ");
	outtextxy(20,380, "John Leenard Zarate");
	outtextxy(20,400, "Warren Albino");
	outtextxy(20,420, "Lanz Manuel Mirabueno");
	outtextxy(20,440, "Jose Manuel Penaflor");
	char ch=getch();
	if(ch==' ') break;
 	getch();
	}
	cleardevice();
	game();
	
}

void game(){
	//Captions
	setcolor(WHITE);
	settextstyle(3, 0, 1);
	outtextxy(70, 450, " Press ESC to Quit game | Use Left & Right arrow keys for movement ");
	
	setcolor(getmaxcolor());
	xmax = getmaxx();
    ymax = getmaxy();
	
	
	int i,j;
	//board
	setcolor(WHITE);
	setfillstyle(1,BLUE);
	bar(50,100,100+4*50+50,100+4*50+100);
	for(i=0; i < COLUMN; i++)
		for(j=0; j < ROW; j++)
			rectangle(50+i*50, 50+j*50, 50+i*50+50, 50+j*50+50);
				
	//programmers
	for(i=0; i<ROW; i++)
		for(j=0; j<COLUMN; j++)
			table[i][j]=0;	
			
		
    
}

void progView(){
	system("cls");
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COLUMN; j++) {
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
}

void turnCaption(){	
	if(player==1){
		outtextxy(490, 120, "Player 1 Turn");
		setcolor(WHITE);
		circle(460,130,20);
		setfillstyle(1, RED);
		floodfill(460, 130, WHITE);
		
		}
	else {
		outtextxy(490, 120, "Player 2 Turn");
		setcolor(WHITE);
		circle(460,130,20);
		setfillstyle(1, YELLOW);
		floodfill(460, 130, WHITE);
	}
	
}

void player1(int row){  //RED
	setcolor(WHITE);
	circle(x + 25, y + 25 + (row * 50), 20);
	setfillstyle(1, RED);
	floodfill(x + 25, y + 25 + (row * 50), WHITE);
}

void player2(int row){  //YELLOW
	setcolor(WHITE);
	circle(x + 25, y + 25 + (row * 50), 20);
	setfillstyle(1, YELLOW);
	floodfill(x + 25, y + 25 + (row * 50), WHITE);
}

void winner(){
	if(player==1){
		setcolor(RED);
		settextstyle(9, 0, 3);
		outtextxy(400,350,"Player 1 wins!");
		getch();exit(1);
	}
	else{
		setcolor(YELLOW);
		settextstyle(9, 0, 3);
		outtextxy(400,350,"Player 2 wins!");
		getch();exit(1);
	}
}

void rules(){
	//Vertical Checking
	for(int ctr = 0; ctr < COLUMN; ctr++){			//p1
		winp1 = 0;
		for(int ctr2 = 0; ctr2 < ROW; ctr2++)
		{
			if(table[ctr2][ctr] == p1)
			{
				winp1++;
				if(winp1 == 4)
				{
					winner();
				}
			}
			else
			{
				winp1 = 0;
			}
		}
	}
	
	for(int ctr = 0; ctr < COLUMN; ctr++){			//p2
		winp2 = 0;
		for(int ctr2 = 0; ctr2 < ROW; ctr2++)
		{
			if(table[ctr2][ctr] == p2)
			{
				winp2++;
				if(winp2 == 4)
				{
					winner();
				}
			}
			else
			{
				winp2 = 0;
			}
		}
	}


	//HORIZONTAL
	for(int ctr = 0; ctr < ROW; ctr++)				//p1
	{
		winp1 = 0;
		for(int ctr2 = 0; ctr2 < COLUMN; ctr2++)
		{
			if(table[ctr][ctr2] == p1)
			{
				winp1++;
				if(winp1 == 4)
				{
					winner();
				}
			}
			else
			{
				winp1 = 0;
			}
		}
	}

	for(int ctr = 0; ctr < ROW; ctr++)				//p2
	{
		winp2 = 0;
		for(int ctr2 = 0; ctr2 < COLUMN; ctr2++)
		{
			if(table[ctr][ctr2] == p2)
			{
				winp2++;
				if(winp2 == 4)
				{
					winner();
				}
			}
			else
			{
				winp2 = 0;
			}
		}
	}




	//Diagonal
	for(int ctr = 0; ctr < ROW; ctr++)				//p1
	{
		winp1 = 0;
		for(int ctr2 = 0; ctr2 < COLUMN; ctr2++)
		{
			if(table[ctr][ctr2] == p1)
			{
				for(int ctr3 = 0; ctr3 < 4; ctr3++)
				{
					if(table[ctr+ctr3][ctr2+ctr3] == p1)
					{
						winp1++;
						if(winp1 == 4)
						{
							winner();
						}
					}
					else
					{
						winp1 = 0;
						break;
					}
				}
	
			}
		}
	}

	for(int ctr = 0; ctr < ROW; ctr++)				//p2
	{
		winp2 = 0;
		for(int ctr2 = 0; ctr2 < COLUMN; ctr2++)
		{
			if(table[ctr][ctr2] == p2)
			{
				for(int ctr3 = 0; ctr3 < 4; ctr3++)
				{
					if(table[ctr+ctr3][ctr2+ctr3] == p2)
					{
						winp2++;
						if(winp2 == 4)
						{
							winner();
						}
					}
					else
					{
						winp2 = 0;
						break;
					}
				}
	
			}
		}
	}


	for(int ctr = 0; ctr < ROW; ctr++)			//p1
	{
		winp1 = 0;
		for(int ctr2 = 0; ctr2 < COLUMN; ctr2++)
		{
			if(table[ctr][ctr2] == p1)
			{
				for(int ctr3 = 0; ctr3 < 4; ctr3++)
				{
					if(table[ctr+ctr3][ctr2-ctr3] == p1)
					{
						winp1++;
						if(winp1 == 4)
						{
							winner();
						}
					}
					else
					{
						winp1 = 0;
						break;
					}
				}
	
			}
		}
	}

	for(int ctr = 0; ctr < ROW; ctr++)			//p2
	{
		winp2 = 0;
		for(int ctr2 = 0; ctr2 < COLUMN; ctr2++)
		{
			if(table[ctr][ctr2] == p2)
			{
				for(int ctr3 = 0; ctr3 < 4; ctr3++)
				{
					if(table[ctr+ctr3][ctr2-ctr3] == p2)
					{
						winp2++;
						if(winp2 == 4)
						{
							winner();
						}
					}
					else
					{
						winp2 = 0;
						break;
					}
				}
	
			}
		}
	}
}

