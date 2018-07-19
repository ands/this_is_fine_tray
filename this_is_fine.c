#define TRAY_WINAPI 1
#include "tray.h"
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shell32.lib")

struct tray tray;

#define ENTRY(text, cb, hotkey_mod, hotkey)
#define SEPARATOR
#define CALLBACKS
#include "this_is_fine_menu.h"
#undef CALLBACKS
#undef ENTRY
#undef SEPARATOR

struct tray_menu menu[] =
{
	#define ENTRY(text, cb, hotkey_mod, hotkey) {text, 0, 0, cb, NULL},
	#define SEPARATOR {"-", 0, 0, NULL, NULL},
	#include "this_is_fine_menu.h"
	#undef ENTRY
	#undef SEPARATOR
	{NULL, 0, 0, NULL, NULL}
};

struct tray tray = { "this_is_fine_icon.ico", menu };

int main(int argc, char **argv)
{
	int i = 1;
	#define ENTRY(text, cb, hotkey_mod, hotkey) RegisterHotKey(NULL, i++, hotkey_mod, hotkey);
	#define SEPARATOR i++;
	#include "this_is_fine_menu.h"
	#undef ENTRY
	#undef SEPARATOR
	tray_init(&tray);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) != 0)
	{
		if (msg.message == WM_QUIT) break;
		if (msg.message != WM_HOTKEY) { TranslateMessage(&msg); DispatchMessage(&msg); continue; }
		i = 1;
		#define ENTRY(text, cb, hotkey_mod, hotkey) if (msg.wParam == i++) cb(&menu[i - 1]);
		#define SEPARATOR i++;
		#include "this_is_fine_menu.h"
		#undef ENTRY
		#undef SEPARATOR
	}
	tray_exit();
}
