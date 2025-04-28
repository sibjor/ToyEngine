#include "server.hpp"
#include "gamestate.hpp"

enum class State
{
    Running,
    Paused,
    Stopped,
    Exiting,
    Error,
    Uninitialized,
};

class MainLoop : public Server
{
public:
    bool continueLoop; // Flagga för att kontrollera om loopen körs

    MainLoop() : continueLoop(false) {}

    ~MainLoop() {}

    void Init()
    {
        InitWindow(800, 600, "ToyEngine");
        SetTargetFPS(60); // Sätt FPS
        if(continueLoop = true){
            InitProgramState(ProgramState::MainMenu);
        }
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

    /* This function*/
    ProgramState InitProgramState(ProgramState state){
        switch (state)
        {
        case ProgramState::MainMenu:
            std::cout << "Initializing Main Menu" << std::endl;
            break;
        case ProgramState::GameRunning:
            std::cout << "Initializing Game" << std::endl;
            break;
        case ProgramState::GameOver:
            std::cout << "Initializing  Game Over State" << std::endl;
            break;
        default:
            std::cout << "Unknown State" << std::endl;
            break;
        }
        return state;
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