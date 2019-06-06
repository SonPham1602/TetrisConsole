// ngay viet 7/8/2017
// ngay 14/8/2017 them mau va chinh o lai 
//16/8/2017 sap hoan thanh game , da them xao dong

#include<iostream>

#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<console.h>
#include"menuGame.h"
#pragma comment (lib, "winmm.lib")


using namespace  std;
enum TrangThai{hinh1,hinh2,hinh3,hinh4,hinh5,hinh6,hinh7};
struct TOA_DO
{
	int x;
	int y;
};
struct KHOI
{
	TOA_DO toa_do[4];
	TrangThai tt;
	int color;
};
KHOI hinh;
int solanquay;
int map[22][12]={0};
int trai, phai;
int speed;
int mark=0;
void setCursorVisible(bool visible)// xoa con tro
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void draw_map()
{

	TextColor(17);
	printf("                                     \n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                    ");TextColor(17);printf("  ");TextColor(7);printf("           ");TextColor(17);printf("  ");printf("\n");
	printf("                                     \n");
	TextColor(7);									
}
void O_trai_phai()
{
	trai=10;
	phai=0;
	for(int i=0;i<4;i++)
	{
		if(trai>hinh.toa_do[i].x)
			trai=hinh.toa_do[i].x;
	}
	for(int i=0;i<4;i++)
	{
		if(phai<hinh.toa_do[i].x)
			phai=hinh.toa_do[i].x;
	}
}
bool trai_phai1()
{
	for(int i=0;i<4;i++)
	{
		if(map[hinh.toa_do[i].y][trai-1]!=0)
		{
			return false;
		}
	}
	return true;
}
bool trai_phai2()
{
	for(int i=0;i<4;i++)
	{
		if(map[hinh.toa_do[i].y][phai+1]!=0)
		{
			return false;
		}
	}
	return true;
}
void dieu_kien(int &iX, int &iY)
{
	if(kbhit())
	{
		O_trai_phai();
		char key=getch();
		if((key=='a' || key=='A')&& trai>1)
		{
			if(trai_phai1()==true)
			{
				iX--;
			}
		}
		if((key=='d' || key=='D')&& phai<10)
		{
			if(trai_phai2()==true)
				iX++;

		}
		if(key=='w' || key=='W')
		{
			if(solanquay==4)
			{
				solanquay=1;
			}
			else
				solanquay++;
		}
		if(key=='s' || key=='S')
		{
			speed=50;
			iY++;
		}
	}
	else
	{
		speed=150;
		iY++;
	}

}
//KHOI TAO HUONG QUAY TOA DO theo chieu nguoc kiem dong ho
//hinh1
int spinX1[5]={0,+1,0,+1,0};
int spinY1[5]={0,-1,0,-1,0};
//hinh2
int spinX21[5]={0,-1,-2,-1,0};
int spinY21[5]={0,-1,0,+1,0};
int spinX22[5]={0,-1,0,+1,0};//khoi1 va khoi 2
int spinY22[5]={0,+1,+2,+1,0};//khoi 1 va khoi 2
//hinh3
int spinX31[5]={0,-1,0,+1,0};
int spinY31[5]={0,+1,+2,+1,0};
int spinX32[5]={0,+1,+2,+1,0};
int spinY32[5]={0,+1,0,-1,0};
int spinX33[5]={0,-1,-2,-1,0};
int spinY33[5]={0,-1,0,+1,0};
//hinh 5
int spinX51[5]={0,+1,+2,+1,0};
int spinY51[5]={0,+1,0,-1,0};
int spinX52[5]={0,-1,0,+1,0};
int spinY52[5]={0,+1,+2,+1,0};
int spinX53[5]={0,-2,-2,0,0};
int spinY53[5]={0,0,+2,+2,0};
//hinh6
int spinX61[5]={0,+1,+2,+1,0};
int spinY61[5]={0,+1,0,-1,0};
//hinh 7
int spinX73[5]={0,-1,-2,-1,0};
int spinY73[5]={0,-1,0,+1,0};
int spinX72[5]={0,-1,0,+1,0};
int spinY72[5]={0,+1,+2,+1,0};
int spinX71[5]={0,0,+2,+2,0};
int spinY71[5]={0,2,2,0,0};
void khoi_tao_hinh(int x, int y)// khoi tao hinh va quay hinh
{
	if(hinh.tt==hinh1)//chu I
	{
		hinh.toa_do[0].x=x;
		hinh.toa_do[0].y=y;
		hinh.toa_do[1].x=hinh.toa_do[0].x+spinX1[solanquay];
		hinh.toa_do[1].y=hinh.toa_do[0].y+spinY1[solanquay]+1;
		hinh.toa_do[2].x=hinh.toa_do[0].x+spinX1[solanquay]*2;
		hinh.toa_do[2].y=hinh.toa_do[0].y+spinY1[solanquay]*2+2;
		hinh.toa_do[3].x=hinh.toa_do[0].x+spinX1[solanquay]*3;
		hinh.toa_do[3].y=hinh.toa_do[0].y+spinY1[solanquay]*3+3;
	}
	if(hinh.tt==hinh2)// chu L
	{
		hinh.toa_do[0].x=x;
		hinh.toa_do[0].y=y;
		hinh.toa_do[1].x=hinh.toa_do[0].x+spinX22[solanquay];
		hinh.toa_do[1].y=hinh.toa_do[0].y-1+spinY22[solanquay];
		hinh.toa_do[2].x=hinh.toa_do[0].x+spinX22[solanquay]*2;
		hinh.toa_do[2].y=hinh.toa_do[0].y-2+spinY22[solanquay]*2;
		hinh.toa_do[3].x=hinh.toa_do[0].x+1+spinX21[solanquay];
		hinh.toa_do[3].y=hinh.toa_do[0].y+spinY21[solanquay];
	}
	if(hinh.tt==hinh3)//chu T
	{
		hinh.toa_do[0].x=x;
		hinh.toa_do[0].y=y;
		hinh.toa_do[1].x=hinh.toa_do[0].x+spinX31[solanquay];
		hinh.toa_do[1].y=hinh.toa_do[0].y-1+spinY31[solanquay];
		hinh.toa_do[2].x=hinh.toa_do[0].x-1+spinX32[solanquay];
		hinh.toa_do[2].y=hinh.toa_do[0].y+spinY32[solanquay];
		hinh.toa_do[3].x=hinh.toa_do[0].x+1+spinX33[solanquay];
		hinh.toa_do[3].y=hinh.toa_do[0].y+spinY33[solanquay];
	}
	if(hinh.tt==hinh4)// chu O va khong quay
	{
		hinh.toa_do[0].x=x;
		hinh.toa_do[0].y=y;
		hinh.toa_do[1].x=hinh.toa_do[0].x+1;
		hinh.toa_do[1].y=hinh.toa_do[0].y;
		hinh.toa_do[2].x=hinh.toa_do[0].x+1;
		hinh.toa_do[2].y=hinh.toa_do[0].y+1;
		hinh.toa_do[3].x=hinh.toa_do[0].x;
		hinh.toa_do[3].y=hinh.toa_do[0].y+1;
	}
	if(hinh.tt==hinh5)// chu S
	{
		hinh.toa_do[0].x=x;
		hinh.toa_do[0].y=y;
		hinh.toa_do[1].x=hinh.toa_do[0].x-1+spinX51[solanquay];
		hinh.toa_do[1].y=hinh.toa_do[0].y+spinY51[solanquay];
		hinh.toa_do[2].x=hinh.toa_do[0].x+spinX52[solanquay];
		hinh.toa_do[2].y=hinh.toa_do[0].y-1+spinY52[solanquay];
		hinh.toa_do[3].x=hinh.toa_do[0].x+1+spinX53[solanquay];
		hinh.toa_do[3].y=hinh.toa_do[0].y-1+spinY53[solanquay];
	}
	if(hinh.tt==hinh6)// chu L nguoc
	{
		hinh.toa_do[0].x=x;
		hinh.toa_do[0].y=y;
		hinh.toa_do[1].x=hinh.toa_do[0].x+spinX22[solanquay];
		hinh.toa_do[1].y=hinh.toa_do[0].y-1+spinY22[solanquay];
		hinh.toa_do[2].x=hinh.toa_do[0].x+spinX22[solanquay]*2;
		hinh.toa_do[2].y=hinh.toa_do[0].y-2+spinY22[solanquay]*2;
		hinh.toa_do[3].x=hinh.toa_do[0].x-1+spinX61[solanquay];
		hinh.toa_do[3].y=hinh.toa_do[0].y+spinY61[solanquay];
	}	
	if(hinh.tt==hinh7)// chu Z 
	{
		hinh.toa_do[0].x=x;
		hinh.toa_do[0].y=y;
		hinh.toa_do[1].x=hinh.toa_do[0].x-1+spinX71[solanquay];
		hinh.toa_do[1].y=hinh.toa_do[0].y-1+spinY71[solanquay];
		hinh.toa_do[2].x=hinh.toa_do[0].x+spinX72[solanquay];
		hinh.toa_do[2].y=hinh.toa_do[0].y-1+spinY72[solanquay];
		hinh.toa_do[3].x=hinh.toa_do[0].x+1+spinX73[solanquay];
		hinh.toa_do[3].y=hinh.toa_do[0].y+spinY73[solanquay];
	}
}
void XOA_hinh()
{
	for(int i=0;i<4;i++)
	{
		gotoXY(hinh.toa_do[i].x*2,hinh.toa_do[i].y);
		cout<<" ";
		gotoXY(hinh.toa_do[i].x*2+1,hinh.toa_do[i].y);
		TextColor(hinh.color);
		cout<<" ";
	}
}
void drawTile()
{
	for(int i=0;i<4;i++)
	{
		gotoXY(hinh.toa_do[i].x*2,hinh.toa_do[i].y);
		TextColor(hinh.color);
		printf("%c",219);
		gotoXY(hinh.toa_do[i].x*2+1,hinh.toa_do[i].y);
		TextColor(hinh.color);
		printf("%c",219);
	}
}
void draw()
{
	draw_map();
	
	for(int i=0;i<22;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(map[i][j]!=0)
			{
				TextColor(map[i][j]);
				gotoXY(j*2,i);
				printf("%c",219);
				gotoXY(j*2+1,i);
				printf("%c",219);
			}
		}
	}
	gotoXY(25,1);
	TextColor(5);
	cout<<"Diem:"<<mark;
}
bool CHECK_DONG(int i)
{
	for(int j=1;j<11;j++)
	{
		if(map[i][j]==0)
			return false;
	}
	return true;
}
void CLEAR_MAP2(int n)
{
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<11;j++)
		{
			map[i][j]=map[i-1][j];
		}
	}
}
void CHECK()// kiem tra xem 1 dong day chua;
{
	for(int i=1;i<21;i++)
	{
		if(CHECK_DONG(i)==true)
		{
			mark=mark+10;
			CLEAR_MAP2(i);
		}
	}
}
bool logic_game1()// kiem tra dong cuoi cung
{
	for(int i=0;i<4;i++)
	{
		if(hinh.toa_do[i].y==20)
			return true;
	}
}
bool logic_game2()// kiem tra khoi chong len nhau
{
	for(int i=0;i<4;i++)
	{
		if(map[hinh.toa_do[i].y+1][hinh.toa_do[i].x]!=0)
		{
			return true;
		}

	}
}
bool tinh_gia_tri_map()// ghi diem toa do cac khoi vao map
{
	if(logic_game1()==true||logic_game2()==true)
	{
		for(int i=0;i<4;i++)
		{
			map[hinh.toa_do[i].y][hinh.toa_do[i].x]=hinh.color;
		}
		return true;
	}
}

void RANDOM(int &iX, int &iY, TrangThai &tt, int &mau)
{
	srand(time(NULL));
	iY=1;
	iX=4;
	tt=TrangThai(rand()%7);
	mau=1+rand()%15;
}

void main()
{
	
	//
	
	// khoi tao console
	SetConsoleTitleW(L"Pham Ngoc Son_ Game Xep Hinh =))");// dat ten khung console
	system("mode 75, 35");// setup man hinh
	setCursorVisible(false);// xoa con tro trong console
	tao_thread();
	// khoi tao gia tri 
	mark=0;
	speed=1000;
	solanquay=0;
	int end;
	end =0;
	int iX,iY;

	// bat dau game
	//clrscr();
	PlaySound(L"Cheerful-marimba-music-melody-loop.wav", NULL,  SND_FILENAME|SND_LOOP|SND_ASYNC);
	vehinh();
	clrscr();
	RANDOM(iX,iY,hinh.tt, hinh.color);// random trang tai dau tien 
	draw();
	while(end!=1)
	{
		
		//system("cls");
		//clrscr();
		khoi_tao_hinh(iX,iY);
		dieu_kien(iX,iY);
		CHECK();
		if(tinh_gia_tri_map()==true)
		{
			RANDOM(iX,iY,hinh.tt, hinh.color);
		}
		
		drawTile();
		Sleep(speed);
		XOA_hinh();
	}
	system("pause");
}
