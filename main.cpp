#include <iostream>
#include <string>
#include <Windows.h>

#define CLIENT_NAME "Fio"
#define CLIENT_VERSION "1.0.0"

void SetConsole()
{
    SetConsoleTitleA(CLIENT_NAME " | Minecraft Bedrock Client");
}

void PrintBanner()
{
    std::cout << R"(

███████╗██╗ ██████╗
██╔════╝██║██╔═══██╗
█████╗  ██║██║   ██║
██╔══╝  ██║██║   ██║
██║     ██║╚██████╔╝
╚═╝     ╚═╝ ╚═════╝

)" << std::endl;

    std::cout << CLIENT_NAME << " Client"
              << " v" << CLIENT_VERSION << "\n\n";
}

void Initialize()
{
    std::cout << "[+] Initialisation...\n";

    // Initialisation des modules
    std::cout << "[+] ModuleManager chargé\n";
    std::cout << "[+] Render chargé\n";
    std::cout << "[+] ClickGUI chargé\n";
    std::cout << "[+] HookManager chargé\n";

    std::cout << "\nLe client est prêt !\n";
}

int main()
{
    SetConsole();

    PrintBanner();

    Initialize();

    std::cout << "\nAppuyez sur Entrée pour quitter...";
    std::cin.get();

    return 0;
}
