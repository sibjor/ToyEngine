#include "component.hpp"

class GameObject
{
    public:
        GameObject();
        // Variant of a constructor
        GameObject(int id, const std::string& name){
            this->id = id;
            this->name = name;
            this->active = true;
            this->parent = nullptr;
        }
        // Another variant of a constructor
        GameObject(const std::string& name){
            this->name = name;
            this->active = true;
            this->parent = nullptr;
        }
        // Destructor
        ~GameObject();

        // Function to add a component
        template<typename T>
        T* AddComponent()
        {
            T* component = new T();
            components.push_back(component);
            return component;
        }
        // Function to remove a component
        template<typename T>
        void RemoveComponent()
        {
            for (auto it = components.begin(); it != components.end(); ++it)
            {
                if (dynamic_cast<T*>(*it))
                {
                    delete *it;
                    components.erase(it);
                    break;
                }
            }
        }
        // Function to get all children
        std::vector<GameObject*> GetChildren()
        {
            return children;
        }
        

    private:
        int id;
        std::string name;
        std::vector<Component*> components;
        std::vector<GameObject*> children;
        GameObject* parent;
        bool active;
};