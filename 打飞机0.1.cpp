#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
int px,py;//�ɻ���λ��
int bulletx,bullety;//�ӵ���λ��;
int high,width;//��Ϸ�ĳߴ�
int ex,ey;//�л���λ�� 
void setup()//���ݳ�ʼ�� 
{
	high=18,width=30;
	px=high/2;
	py=width/2;
	bulletx=-1;
	bullety=py;
	ex=0;
	ey=width/2; 
 }
 void show()
{
    system("cls");
	for(int i=0;i<high;++i)
	{
		for(int j=0;j<width;++j)
		{
			if(i==px&&j==py)
			{
				printf("*");
			}
			else if(i==bulletx&&j==bullety)
			{
				printf("|");
			}
			else if(i==ex&&j==ey)
			printf("@");
			else 
			{
				printf(" ");
			}
		}
		printf("\n");
	} 	
}
void updatano()
{
	if(bulletx==ex&&bullety==ey)
	{
		bulletx=-1;
		printf("\a");
		Sleep(10);
		ex=0;
		ey=rand()%width;
	}
	if(bulletx>=0)
	bulletx--;
	static int speed=0;//���ڿ��Ƶл������ٶ� 
	if(speed<20)
	speed++;
	if(speed==20)
	{
		if(ex>high)
		{
		ex=0;
		ey=rand()%width;
	    }
	    else 
	    {
			speed=0; 
			ex++;
	    } 
	    }
}
void updataok()
{
	if(kbhit())
	{
	char ch;
	ch=getch();
	if(ch=='w'||ch=='W')
		px--;
		if(ch=='s'||ch=='S')
		px++;
		if(ch=='a'||ch=='A')
		py--;
		if(ch=='d'||ch=='D')
		py++;
		else if(ch==' ')
		{
			bulletx=px;
			bullety=py;
		}
	}
 } 
int main(void)
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	setup();
	while(1)
	{
		show();
		updatano();
		updataok(); 
	}
	return 0;
 } 
