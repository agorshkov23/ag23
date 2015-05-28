#include <windows.h>
#include <iostream>
using namespace std;

UINT SendKeyboardInput(WORD wVk) {
	INPUT input = { 0 };
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = wVk;

}

int main () {
	if (!RegisterHotKey(NULL, 1, MOD_ALT | MOD_WIN, VK_UP))
		printf("Error registering hotkey\n");

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0) != 0) {
		if (msg.message == WM_HOTKEY)
			keybd_event(VK_VOLUME_UP, NULL, NULL, NULL);
	}
}