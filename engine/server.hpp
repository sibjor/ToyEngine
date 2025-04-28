#include "central.h"

enum class Protocol
{
    DeliverToRoot,
    DeliverToSibling,
    DeliverToParent,
    DeliverToChildren,
    DeliverToAll,
    DeliverToSingular,
};
class Server
{
public:
    Server() { 
        HandleEvents(Protocol::DeliverToRoot);
        
    }          // Tom konstruktor
    virtual ~Server() {} // Virtuell destruktor för polymorfism

    /* This function
    - can return or handle incoming events 
    - thus, messages can go either up or downwards */
    Protocol HandleEvents(Protocol eventType)
    {
        switch (eventType)
        {
            // Run in the constructor by default
        case Protocol::DeliverToRoot:
            std::cout << "Delivering event to root." << std::endl;
            std::cout << "Server initialized." << std::endl;
            // Hantera händelse för root
            break;

        break;

        default:
            std::cout << "Unhandled event type!" << std::endl;
            break;
        }
    }
};