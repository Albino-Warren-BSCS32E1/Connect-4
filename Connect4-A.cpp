//connect4 
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include "scratchc5A.cpp"

main(){
	initG();
	progView();
	
	player=1;
	x=50; y=50;
	row=1;col=1;
	setcolor(RED);
	setlinestyle(3,0, 15);
    rectangle(0,479,639,1);
    setcolor(CYAN);
    rectangle(20,430,619,21);
  	setlinestyle(0,0,0);
  	
	//marker
	setcolor(3);
	rectangle(x,y,x+50,y+50);
	
	//turnCaption
	setcolor(WHITE);
	outtextxy(490, 120, "Player 1 Turn");
	circle(460,130,20);
	setfillstyle(1, RED);
	floodfill(460, 130, WHITE);
	

	 	
	do{
		input=getch();
		setcolor(WHITE);
		rectangle(x,y,x+50,y+50);
		
		//navigation
		switch(input){
			case LEFT	: if(col>1) {x-=50; col--;} break;
			case RIGHT	: if(col<6) {x+=50; col++;} break;
		}
		
		//markings
		if(input==32)
			if(table[row][col]==0)
				if(player==1){ 
					for(int i = ROW - 1; i > -1; i--)
						if (table[i][col - 1] == 0) {
						table[i][col - 1] = p1;
						player1(i);
						rules(); 
						player=2;
						break;}}
				else 		 { 
				for(int i = ROW - 1; i > -1; i--)
						if (table[i][col - 1] == 0) {
						table[i][col - 1] = p2;
						player2(i);
						rules(); 
						player=1;
						break;}}
		
		progView();
		turnCaption();
		setcolor(3);
		rectangle(x,y,x+50,y+50);
		

	}while(input!=27);  
	
	
	getch();
	return 0;
}
