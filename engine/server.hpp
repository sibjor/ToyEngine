#include "central.h"

enum class EventType
{
    EVENT_NONE,
    EVENT_KEY_PRESSED,
    EVENT_KEY_RELEASED,
    EVENT_MOUSE_CLICKED,
    EVENT_MOUSE_MOVED,
    EVENT_WINDOW_RESIZED,
};
class Server
{
public:
    Server();
    ~Server();

    void ListenToEvents(EventType eventType)
    {
        switch (eventType)
        {
        case EventType::EVENT_KEY_PRESSED:
            if (IsKeyPressed(KEY_SPACE)) // Exempel: Kontrollera om mellanslagstangenten trycks ned
            {
                std::cout << "Space key pressed!" << std::endl;
            }
            break;

        case EventType::EVENT_KEY_RELEASED:
            if (IsKeyReleased(KEY_SPACE)) // Exempel: Kontrollera om mellanslagstangenten släpps
            {
                std::cout << "Space key released!" << std::endl;
            }
            break;

        case EventType::EVENT_MOUSE_CLICKED:
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) // Kontrollera om vänster musknapp trycks ned
            {
                std::cout << "Mouse left button clicked!" << std::endl;
            }
            break;

        case EventType::EVENT_MOUSE_MOVED:
        {
            Vector2 mousePosition = GetMousePosition(); // Hämta musens position
            std::cout << "Mouse moved to: (" << mousePosition.x << ", " << mousePosition.y << ")" << std::endl;
            break;
        }

        case EventType::EVENT_WINDOW_RESIZED:
            // Raylib hanterar inte fönsterstorleksändringar direkt, men du kan använda en anpassad lösning
            std::cout << "Window resized (custom handling required)" << std::endl;
            break;

        default:
            std::cout << "Unhandled event type!" << std::endl;
            break;
        }
    }
};