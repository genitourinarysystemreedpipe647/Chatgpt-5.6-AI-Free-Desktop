// ChatGPT 5.6 - Voice chat (Whisper STT + TTS)
#include "../include/App.h"

namespace ChatGPT {

bool VoiceModule::StartCapture() {
    m_recording = true;
    m_buffer.clear();
    return true;
}

std::string VoiceModule::StopAndTranscribe() {
    m_recording = false;
    // POST /v1/audio/transcriptions (whisper-1)
    return "";
}

bool VoiceModule::Speak(const std::string& text) {
    // POST /v1/audio/speech (tts-1), voice alloy
    return !text.empty();
}

} // namespace ChatGPT
