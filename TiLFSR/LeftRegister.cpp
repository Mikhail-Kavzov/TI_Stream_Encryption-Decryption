#include "LeftRegister.h"
#include <Windows.h>

using namespace TiLFSR;
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew LeftRegister);
    return 0;
}

