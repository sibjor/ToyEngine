#include "central.h"

class State
{
public:
    

    State()
    {
        // Symmetrical allocation
        std::unique_ptr<State> currentState = std::make_unique<State>();
    }
    ~State() {
        
    }

    virtual void OnEnter();
    virtual void OnExit();
    virtual void OnEdit();
};