// ChatGPT 5.6 - App shell implementation
#include "../include/App.h"
#include <fstream>

namespace ChatGPT {

bool App::Initialize(HINSTANCE hInst) {
    m_personas.LoadDefaults();
    WNDCLASS wc = {};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "ChatGPT56";
    wc.hbrBackground = CreateSolidBrush(RGB(24, 24, 27));
    RegisterClass(&wc);
    HWND hwnd = CreateWindowEx(0, "ChatGPT56", "ChatGPT 5.6 Sol Luna Terra",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 700,
        nullptr, nullptr, hInst, nullptr);
    ShowWindow(hwnd, SW_SHOW);
    return hwnd != nullptr;
}

int App::Run() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

} // namespace ChatGPT
