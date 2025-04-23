#include "component.hpp"

class GameObject
{
    public:
        GameObject()
        {
        };

        ~GameObject();

    private:
        int id;
        std::string name;
        std::vector<Component*> components;
        std::vector<GameObject*> children;
        GameObject* parent;
        bool active;
};