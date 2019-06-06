#include"menuGame.h";

void mau (int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void vehinh()
{
	fstream file;
	file.open("logo.txt");
	
	while(!file.eof())
	{
		mau(3);
		string temp;
		getline(file,temp);
		for(int i=0;i<temp.length();i++)
		{
			if(temp[i]!='1' && temp[i]!='6'&& temp[i]!='2' && temp[i]!='3' && temp[i]!='4' && temp[i]!='5' )
			{
				if(temp[i]=='0')
				{
					mau(1);
				}
				cout<<temp[i];
			}
			if(temp[i]=='6')
			{

				printf("%c",201);
			}
			if(temp[i]=='1')
			{
				printf("%c",205);
			}
			if(temp[i]=='2')
			{
				printf("%c",187);
			}
			if(temp[i]=='3')
			{
				printf("%c",186);
			}
			if(temp[i]=='4')
			{
				printf("%c",200);
			}
			if(temp[i]=='5')
			{
				printf("%c",188);
			}

		}
		cout<<endl;
	}
	file.close();

}
void play_sound()
{
	PlaySoundW(TEXT("menu_sound.wav"),NULL,  SND_FILENAME|SND_LOOP|SND_ASYNC);
}
int check=1;
void nhan_phim()
{
	int condition_key=1;
	while(condition_key==1)
	{
		if(kbhit());
		{
			char key=getch();
			check=0;
			break;
		}
	}
}
void tao_thread()
{
	while(check==1)
	{
	thread keyThread(nhan_phim);
	thread playsoundThread(play_sound);
	thread drawThread(vehinh);
	keyThread.join();
	playsoundThread.join();
	drawThread.join();
	}
}