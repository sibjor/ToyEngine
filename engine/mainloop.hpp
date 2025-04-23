#include "server.hpp"


class MainLoop : public Server
{
public:
    MainLoop() : isRunning(false) {}

    ~MainLoop() {}

    void Init()
    {
        InitWindow(800, 600, "ToyEngine");
        SetTargetFPS(60); // Sätt FPS
        isRunning = true;
        std::cout << "Initialization complete." << std::endl;
    }

    void Run()
    {
        while (isRunning && !WindowShouldClose())
        {
            ProcessEvents();
            Update();
            Render();
        }
        Cleanup();
        Shutdown();
    }

    void ProcessEvents()
    {
        // Hantera tangentbord och mus
        if (IsKeyPressed(KEY_ESCAPE))
        {
            isRunning = false; // Avsluta loopen om ESC trycks
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
    bool isRunning; // Flagga för att kontrollera om loopen körs
};