#ifdef CALLBACKS
void explorer_tray(struct tray_menu *item) { system("explorer D:\\projects\\tray"); }
void build(struct tray_menu *item) { system("cd D:\\projects\\tray\\ && build.bat"); }
void toggle(struct tray_menu *item) { item->checked = !item->checked; tray_update(&tray); }
void quit(struct tray_menu *item) { tray_exit(); ExitProcess(0); }
#endif

ENTRY("Alt + E | Explorer: Tray", explorer_tray, MOD_ALT | MOD_NOREPEAT, 'E')
SEPARATOR
ENTRY("Alt + M | Build"         , build        , MOD_ALT | MOD_NOREPEAT, 'M')
ENTRY("Alt + T | Toggle Example", toggle       , MOD_ALT | MOD_NOREPEAT, 'T')
SEPARATOR
ENTRY("Alt + Q | Quit"          , quit         , MOD_ALT | MOD_NOREPEAT, 'Q')
