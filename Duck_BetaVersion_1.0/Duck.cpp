#include<windows.h>
#include<bits/stdc++.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
int main()
{
	cout<<"starting"<<endl;
	Sleep(1000);
	bool f=false;
	HWND hwnd,fu;
	hwnd=GetForegroundWindow();//获取最前端的窗口的句柄
	fu=hwnd;
	ShowWindow(hwnd,0);
	while(1)
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
			ShowWindow(fu,1);
			cout<<"end of the process";
			Sleep(1000);
			return 0;
		}
		Sleep(20);
	}
	ShowWindow(hwnd,1);
	ShowWindow(fu,1);
	cout<<"end of the process";
	Sleep(1000);
	return 0;
}