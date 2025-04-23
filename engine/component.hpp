#include "central.h"

enum class ComponentType
{
    Transform,
    Sprite,
    Animation,
    Collider,
    Script,
    Camera,
    Light,
    ParticleSystem,
    AudioSource,
    UIElement
};

class GameObject
{
public:
    GameObject(){
        InitGameObject("Default", 0, "default_path");
    };

    ~GameObject();

    void InitGameObject(std::string name, int id, std::string path)
    {
        this->name = name;
        this->id = id;
        this->path = path;
    }

    std::pair<Component *, GameObject>  ReturnComponents(){
        return components;
    }

private:
    std::pair<Component *, GameObject> components;
    std::string name;
    int id;
    std::string path;
};

class Component
{
    public:
        ComponentType Component::GetType(){
            return type;
        }
    private:
        ComponentType type;
        GameObject *parent;

        void SetType(ComponentType type){
            this->type = type;
        }
};