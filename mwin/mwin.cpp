#include <Windows.h>
#include <iostream>
using namespace std;

#define	VK_S	83
#define	VK_H	72

HWND hWnd = GetConsoleWindow();

void hide() {
	ShowWindow(hWnd, SW_HIDE);
}

void show() {
	ShowWindow(hWnd, SW_SHOW);
}

void init() {
	cout << "mwindow registering hotkeys..." << endl;

	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN, VK_UP))						cout << "error registering hotkey win+alt+up" << endl;
	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN, VK_DOWN))					cout << "error registering hotkey win+alt+down" << endl;
	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN | MOD_NOREPEAT, VK_F8))		cout << "error registering hotkey win+alt+f8" << endl;
	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN | MOD_NOREPEAT, VK_LEFT))		cout << "error registering hotkey win+alt+left" << endl;
	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN | MOD_NOREPEAT, VK_RIGHT))	cout << "error registering hotkey win+alt+right" << endl;
	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN | MOD_NOREPEAT, VK_SPACE))	cout << "error registering hotkey win+alt+space" << endl;
	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN | MOD_NOREPEAT, VK_F6))		cout << "error registering hotkey win+alt+f6" << endl;
	
	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN | MOD_NOREPEAT, VK_H))		cout << "error registering hotkey win+alt+h" << endl;
	if (!RegisterHotKey(NULL, NULL, MOD_ALT | MOD_WIN | MOD_NOREPEAT, VK_S))		cout << "error registering hotkey win+alt+s" << endl;
	
}

void loop() {
	cout << "mwindow starts the cycle..." << endl;
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0) != 0) {
		if (msg.message == WM_HOTKEY) {
			switch (msg.lParam)
			{
			case MOD_ALT | MOD_WIN | VK_UP << 16:
				keybd_event(VK_VOLUME_UP, NULL, NULL, NULL);
				cout << "up" << endl;
				break;
			case MOD_ALT | MOD_WIN | VK_DOWN << 16:
				keybd_event(VK_VOLUME_DOWN, NULL, NULL, NULL);
				cout << "down" << endl;
				break;
			case MOD_ALT | MOD_WIN | VK_F8 << 16:
				keybd_event(VK_VOLUME_MUTE, NULL, NULL, NULL);
				cout << "mute" << endl;
				break;
			case MOD_ALT | MOD_WIN | VK_LEFT << 16:
				keybd_event(VK_MEDIA_PREV_TRACK, NULL, NULL, NULL);
				cout << "prev" << endl;
				break;
			case MOD_ALT | MOD_WIN | VK_RIGHT << 16:
				keybd_event(VK_MEDIA_NEXT_TRACK, NULL, NULL, NULL);
				cout << "next" << endl;
				break;
			case MOD_ALT | MOD_WIN | VK_SPACE << 16:
				keybd_event(VK_MEDIA_PLAY_PAUSE, NULL, NULL, NULL);
				cout << "pause" << endl;
				break;
			case MOD_ALT | MOD_WIN | VK_F6 << 16: 
				SendMessage(FindWindow(NULL, NULL), WM_SYSCOMMAND, SC_MONITORPOWER, 2);
				break;
			case MOD_ALT | MOD_WIN | VK_H << 16:
				hide();
				break;
			case MOD_ALT | MOD_WIN | VK_S << 16:
				show();
				break;
			default:
				printf("default %x\n", msg.lParam);
				break;
			}
		}
	}
}

int main() {
	cout << "mwindow starting..." << endl;
	init();
	loop();
}