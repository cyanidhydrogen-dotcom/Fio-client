#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <Windows.h>

constexpr auto CLIENT_NAME = "Fio";
constexpr auto CLIENT_VERSION = "1.0.0";

enum class LogType
{
    Info,
    Success,
    Warning,
    Error
};

void Log(LogType type, const std::string& text)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (type)
    {
    case LogType::Info:
        SetConsoleTextAttribute(console, 11);
        std::cout << "[INFO] ";
        break;

    case LogType::Success:
        SetConsoleTextAttribute(console, 10);
        std::cout << "[ OK ] ";
        break;

    case LogType::Warning:
        SetConsoleTextAttribute(console, 14);
        std::cout << "[WARN] ";
        break;

    case LogType::Error:
        SetConsoleTextAttribute(console, 12);
        std::cout << "[FAIL] ";
        break;
    }

    SetConsoleTextAttribute(console, 7);
    std::cout << text << '\n';
}

void Banner()
{
    std::cout << R"(

███████╗██╗ ██████╗
██╔════╝██║██╔═══██╗
█████╗  ██║██║   ██║
██╔══╝  ██║██║   ██║
██║     ██║╚██████╔╝
╚═╝     ╚═╝ ╚═════╝

)";
    std::cout << "\n";
    std::cout << "=====================================\n";
    std::cout << "            Fio Client\n";
    std::cout << "            Version " << CLIENT_VERSION << "\n";
    std::cout << "=====================================\n\n";
}

void Initialize()
{
    Log(LogType::Info, "Loading Renderer...");
    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    Log(LogType::Info, "Loading UI...");
    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    Log(LogType::Info, "Loading Config...");
    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    Log(LogType::Info, "Loading Assets...");
    std::this_thread::sleep_for(std::chrono::milliseconds(250));

    Log(LogType::Success, "Initialization complete.");
}

int main()
{
    SetConsoleTitleA("Fio Client");

    auto start = std::chrono::high_resolution_clock::now();

    Banner();

    Initialize();

    auto end = std::chrono::high_resolution_clock::now();

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "\n";
    Log(LogType::Success, "Fio started successfully.");
    Log(LogType::Info, "Startup time: " + std::to_string(ms.count()) + " ms");

    std::cout << "\nPress ENTER to exit...";
    std::cin.get();

    return 0;
}
