#include "server.hpp"
#include "gamestate.hpp"

class MainLoop : public Server
{
public:
    bool continueLoop; // Flagga för att kontrollera om loopen körs

    MainLoop() : continueLoop(true) {}

    ~MainLoop() {
        delete this;
        std::cout << "MainLoop destructor called." << std::endl;
    }

    void Init()
    {
        continueLoop = true;
        InitWindow(800, 600, "ToyEngine");
        SetTargetFPS(60); // Sätt FPS
        std::cout << "Initialization complete." << std::endl;
    }

    bool ContinueLoop(bool loopStatus)
    {
        this->continueLoop = loopStatus;
        std::cout << "ContinueLoop called with isRunning: " << continueLoop << std::endl;
        return continueLoop;

        {

            while (continueLoop && !WindowShouldClose())
            {
                ProcessEvents();
                Update();
                Render();
            }
            if (!continueLoop)
            {
                std::cout << "Exiting main loop." << std::endl;
                Cleanup();
                Shutdown();
                std::cout << "Engine exited successfully." << std::endl;
            }
        }
    }

    void ProcessEvents()
    {
        // Hantera tangentbord och mus
        if (IsKeyPressed(KEY_ESCAPE))
        {
            continueLoop = false; // Avsluta loopen om ESC trycks
        }
    }

    void Update()
    {
        // Uppdatera spelobjekt eller logik
        std::cout << "Updating game state..." << std::endl;
    }

    void Render()
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Rendera spelobjekt eller UI
        DrawText("Welcome to ToyEngine!", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    void Cleanup()
    {
        // Frigör resurser eller stäng öppna filer
        std::cout << "Cleaning up resources..." << std::endl;
    }

    void Shutdown()
    {
        CloseWindow(); // Stäng Raylib-fönstret
        std::cout << "Shutting down engine." << std::endl;
    }

private:
};