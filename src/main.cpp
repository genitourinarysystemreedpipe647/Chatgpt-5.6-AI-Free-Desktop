// ChatGPT 5.6 Sol Luna Terra - Entry point
// Version: 5.6.3
#include "../include/App.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int show) {
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    ChatGPT::App app;
    if (!app.Initialize(hInst)) return 1;
    return app.Run();
}
