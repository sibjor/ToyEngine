#include "central.h"

enum class GameState
{
    MainMenu,
    Playing,
    Paused,
    GameOver,
    Settings,
    Credits
};
class Program
{
public:
    std::vector<std::unique_ptr<GameState>> *gameStates;

    Program()
    {
        gameStates = new std::vector<std::unique_ptr<GameState>>();
        gameStates->push_back(std::make_unique<GameState>(GameState::MainMenu));
        switch (*gameStates->at(0))
        {
            case GameState::MainMenu:
            // Handle MainMenu state
            gameStates->emplace_back(std::make_unique<GameState>(GameState::Playing));
            break;
            case GameState::Playing:
            // Handle Playing state
            gameStates->emplace_back(std::make_unique<GameState>(GameState::Paused));
            break;
            case GameState::Paused:
            // Handle Paused state
            gameStates->emplace_back(std::make_unique<GameState>(GameState::GameOver));
            break;
            case GameState::GameOver:
            // Handle GameOver state
            gameStates->emplace_back(std::make_unique<GameState>(GameState::Settings));
            break;
            case GameState::Settings:
            // Handle Settings state
            gameStates->emplace_back(std::make_unique<GameState>(GameState::Credits));
            break;
            case GameState::Credits:
            // Handle Credits state
            gameStates->emplace_back(std::make_unique<GameState>(GameState::MainMenu));
            break;
            default:
            // Handle unexpected state
            break;
        }
    }
    ~Program() {
        delete gameStates;
    }
};