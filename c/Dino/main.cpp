#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main()
{
	int x=640,y=480,i=0,j=0,count=0,score=0;


	char ch;

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\Users\\Kowshique\\Desktop\\fly2.png");

	for(;;)
	{
		setfillstyle(1,GREEN);
		floodfill(10,10,WHITE);
		setlinestyle(0,1,1);
		line(x/2-320+i,y/2,x/2+10000+i,y/2);

		if(kbhit())
		{
			ch=getch();
				if(isspace(ch))
				{
					if(j<=0)
						j+=70;
				}
			}

		i-=5;

		//obstacles
		if(i<=-800)
		{
			i=0;
			count++;
			score+=10;
			system("CLS");
			printf("Your score : %d\n",score);
			//delay(1000);


			setfillstyle(1,RED);
		 	bar(x/2+213+i,y/2,x/2+233+i,y/2-20);
		 	bar(x/2+540+i,y/2,x/2+560+i,y/2-20);
		}
		setfillstyle(1,RED);
		bar(x/2+213+i,y/2,x/2+233+i,y/2-20);
		bar(x/2+540+i,y/2,x/2+560+i,y/2-20);

		if(j<=5 && i==-410 || j<=5 && i==-740)
		{
			settextstyle(2,HORIZ_DIR,7);
			outtextxy(x/2-80,y/2-150,"Game Over");
			break;
		}

		//jumper
		setfillstyle(1,BLUE);
		bar(x/2-180,y/2-25-j,x/2-200,y/2-5-j);

		if(j>=0)
			j-=5;

		if(count<=5)
			delay(10);
		else if(count>=10)
			delay(5);
		else
			delay(2);
	}

	printf("Game Over");

	getch();
	closegraph();
	return 0;
}
