#include<windows.h>
#include <shellapi.h>
#include<bits/stdc++.h>
#include<conio.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;

int main_module()
{
	HWND hwnd;
	bool f = 0;
	while(true)
	{
		if(KEY_DOWN(VK_MENU) && KEY_DOWN('P'))//获取要隐藏窗口的句柄
		{
			while (KEY_DOWN(VK_MENU) && KEY_DOWN('P'));
			//加这句的原因是防止按了太多次，导致一直隐藏/显示
			hwnd=GetForegroundWindow();
			Sleep(100);
		}
		if(KEY_DOWN(VK_MENU) && KEY_DOWN('F'))//隐藏
		{
			while (KEY_DOWN(VK_MENU) && KEY_DOWN('F'));
			ShowWindow(hwnd,f);
			f=1-f;
			Sleep(100);
		}
		if(KEY_DOWN(VK_MENU) && KEY_DOWN('O'))//退出
		{
			while (KEY_DOWN(VK_MENU) && KEY_DOWN('O'));
			ShowWindow(hwnd,1);
			Sleep(1000);
			return 0;
		}
		if(KEY_DOWN(VK_MENU) && KEY_DOWN('E'))//退出
		{
			while (KEY_DOWN(VK_MENU) && KEY_DOWN('E'));
			ShowWindow(hwnd,1);
			return 1;
		}
		Sleep(20);
	}
}

void user_module(HWND hwnd)
{
	ShowWindow(hwnd,1);
	system("cls");
	cout<<"DDDD  U   U CCCCC K  k  "<<endl;
	cout<<"D   D U   U C     K k   "<<endl;
	cout<<"D   D U   U C     Kk    "<<endl;
	cout<<"D   D U   U C     K k   "<<endl;
	cout<<"DDDD  UUUUU CCCCC K  k  "<<endl;
	cout<<"Assistant for fishcatchers"<<endl;
	cout<<"BetaVersion1.1.1"<<endl;
	cout<<endl;
	cout<<"press h to help"<<endl;
	cout<<"press x to exit"<<endl;
	cout<<"press d to start"<<endl;
	Sleep(1000);
	for(;kbhit()==0;);
	int c = getch();
	//ShowWindow(hwnd,0);
	if(c == 'h')
	{
		WinExec( "notepad.exe Duck_Help.txt", SW_SHOW );
	}
	else if(c == 'x')
	{
		return;
	}
	else if(c == 'd')
	{
		ShowWindow(hwnd,0);
		c = main_module();
		if(c == 1)
		{
			return;
		}
	}
	user_module(hwnd);
}

int main()
{
	HWND hwnd = GetForegroundWindow();
	user_module(hwnd);
	ShowWindow(hwnd,1);
	system("cls");
	cout<<"Exiting"<<endl;
	Sleep(1000);
	return 0;
}