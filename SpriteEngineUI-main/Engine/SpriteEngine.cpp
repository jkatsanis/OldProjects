#include <SpriteEngine.h>   

int main()
{ 
    s2d::GameEngine engine;

    while (engine.ptr_renderWindow->isOpen())
    { 
        engine.update();
    }

    ImGui::SFML::Shutdown();
    return 0;
}

