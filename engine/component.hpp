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
class Component
{
public:
    ComponentType GetType()
    {
        return type;
    }

private:
    ComponentType type;

    // Transform
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

    // Sprite
    Texture2D texture;

    // Animation
    int animationFrame;
    float animationSpeed;

    // Collider
    Rectangle colliderBounds;

    // Camera
    Camera camera;

    // Light
    Color lightColor;

    // ParticleSystem
    int particleCount;

    // AudioSource
    Sound sound;

    // UIElement
    Rectangle uiBounds;

    void SetType(ComponentType type)
{
    this->type = type;

    switch (type)
    {
    case ComponentType::Transform:
        // Initialize Transform component
        std::cout << "Initializing Transform component" << std::endl;
        // Exempel: Ställ in en standardposition, rotation och skala
        position = {0.0f, 0.0f, 0.0f};
        rotation = {0.0f, 0.0f, 0.0f};
        scale = {1.0f, 1.0f, 1.0f};
        break;

    case ComponentType::Sprite:
        // Initialize Sprite component
        std::cout << "Initializing Sprite component" << std::endl;
        texture = LoadTexture("sprite.png"); // Ladda en sprite-textur
        break;

    case ComponentType::Animation:
        // Initialize Animation component
        std::cout << "Initializing Animation component" << std::endl;
        // Exempel: Ställ in en spritesheet och animationens parametrar
        animationFrame = 0;
        animationSpeed = 0.1f;
        break;

    case ComponentType::Collider:
        // Initialize Collider component
        std::cout << "Initializing Collider component" << std::endl;
        colliderBounds = {0.0f, 0.0f, 1.0f, 1.0f}; // Exempel: En rektangulär collider
        break;

    case ComponentType::Camera:
        // Initialize Camera component
        std::cout << "Initializing Camera component" << std::endl;
        camera.position = {0.0f, 0.0f, 10.0f};
        camera.target = {0.0f, 0.0f, 0.0f};
        camera.up = {0.0f, 1.0f, 0.0f};
        camera.fovy = 45.0f;
        break;

    case ComponentType::Light:
        // Initialize Light component
        std::cout << "Initializing Light component" << std::endl; // Removed invalid member assignment as Camera3D has no 'type' member
        lightColor = WHITE; // Exempel: Standardfärg för ljus
        break;

    case ComponentType::ParticleSystem:
        // Initialize ParticleSystem component
        std::cout << "Initializing ParticleSystem component" << std::endl;
        // Exempel: Initiera partiklar
        particleCount = 100;
        break;

    case ComponentType::AudioSource:
        // Initialize AudioSource component
        std::cout << "Initializing AudioSource component" << std::endl;
        sound = LoadSound(""); // Load from path or use a default sound
        break;

    case ComponentType::UIElement:
        // Initialize UIElement component
        std::cout << "Initializing UIElement component" << std::endl;
        uiBounds = {0.0f, 0.0f, 100.0f, 50.0f}; // Exempel: En rektangulär UI-element
        break;

    default:
        std::cerr << "Unknown component type!" << std::endl;
        break;
    }
}
};