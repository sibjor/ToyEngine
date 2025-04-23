#include "central.h"

class Component
{
public:
    Component:Component(std::string name, int id, std::string path){
        this->name = name;
        this->id = id;
        this->path = path;
    }
    ~Component() {}
private:
    std::string name;
    int id;
    std::string path;
};