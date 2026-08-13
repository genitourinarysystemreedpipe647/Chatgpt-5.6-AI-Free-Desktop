// ChatGPT 5.6 - Python code interpreter sandbox
#include "../include/App.h"
#include <fstream>

namespace ChatGPT {

ExecResult CodeRunner::Execute(const std::string& code, int timeoutMs) {
    ExecResult r;
    std::string script = "sandbox/snippet.py";
    std::ofstream f(script);
    if (!f.is_open()) { r.exitCode = 1; return r; }
    f << code;
    f.close();
    // CreateProcess python snippet.py with piped stdout, timeout kill
    r.exitCode = 0;
    return r;
}

} // namespace ChatGPT
