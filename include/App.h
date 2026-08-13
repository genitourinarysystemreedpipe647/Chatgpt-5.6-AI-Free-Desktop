// ChatGPT 5.6 - Core types and app shell
#pragma once
#include <string>
#include <vector>
#include <atomic>
#include <windows.h>

namespace ChatGPT {

struct Persona {
    std::string id;
    std::string name;
    float temperature;
    std::string accentColor;
    std::string hotkey;
};

struct ExecResult {
    std::string stdOut;
    std::string stdErr;
    int exitCode = 0;
};

class PersonaEngine {
public:
    void LoadDefaults();
    void SetActive(const std::string& id);
    const Persona& Active() const;
private:
    std::vector<Persona> m_personas;
    int m_active = 0;
};

class StreamClient {
public:
    void Send(const std::string& payload);
    void Cancel();
    bool IsStreaming() const { return m_streaming; }
private:
    std::atomic<bool> m_streaming{false};
};

class VoiceModule {
public:
    bool StartCapture();
    std::string StopAndTranscribe();
    bool Speak(const std::string& text);
private:
    std::atomic<bool> m_recording{false};
    std::vector<uint8_t> m_buffer;
};

class CodeRunner {
public:
    ExecResult Execute(const std::string& code, int timeoutMs = 30000);
};

class App {
public:
    bool Initialize(HINSTANCE hInst);
    int Run();
private:
    PersonaEngine m_personas;
    StreamClient m_client;
    VoiceModule m_voice;
    CodeRunner m_code;
};

} // namespace ChatGPT
