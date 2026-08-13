// ChatGPT 5.6 - Streaming chat client
#include "../include/App.h"
#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")

namespace ChatGPT {

void StreamClient::Send(const std::string& payload) {
    m_streaming = true;
    // POST /v1/chat/completions with SSE parsing
}

void StreamClient::Cancel() {
    m_streaming = false;
}

} // namespace ChatGPT
