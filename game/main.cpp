#include "mainloop.hpp"

int main()
{
    MainLoop mainLoop;
    mainLoop.Init();
    mainLoop.ContinueLoop(true);

    return 0;
}
