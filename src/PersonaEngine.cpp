// ChatGPT 5.6 - Persona engine (Sol/Luna/Terra/Cyber)
#include "../include/App.h"

namespace ChatGPT {

void PersonaEngine::LoadDefaults() {
    m_personas = {
        {"sol",   "Sol",   0.85f, "#E8A33D", "Ctrl+Shift+S"},
        {"luna",  "Luna",  0.30f, "#5B8DEF", "Ctrl+Shift+L"},
        {"terra", "Terra", 0.50f, "#4ADE80", "Ctrl+Shift+T"},
        {"cyber", "Cyber", 0.20f, "#F87171", "Ctrl+Shift+C"}
    };
    m_active = 0;
}

void PersonaEngine::SetActive(const std::string& id) {
    for (size_t i = 0; i < m_personas.size(); ++i) {
        if (m_personas[i].id == id) { m_active = (int)i; return; }
    }
}

const Persona& PersonaEngine::Active() const {
    return m_personas[m_active];
}

} // namespace ChatGPT
