#include "BB_TestGame.h"
#include "BB_Core.h"

using namespace BB_Datatypes;

void BB_TestGame::Run()
{
    BB_Core::Init(CoreSettingsData());

    const int alf = BB_Core::CreateEntity();
    BB_Core::LoadAddSprite(alf, "alf.jpg", 300.f, 200.f);

    const int yoshi = BB_Core::CreateEntity();
    BB_Core::LoadAddSprite(yoshi, "yoshi.png", 1100.f, 600.f);
    
    while (BB_Core::mainWindow.isOpen())
    {
        BB_Core::ProcessInput();
        BB_Core::RenderMainWindow();
    }
}
