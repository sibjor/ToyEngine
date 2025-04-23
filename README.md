# ToyEngine
Raylib abstraction layer part of Forsbergs Game Programming education

´´´mermaid
flowchart TD
    A[central.h] --> B
    C[raylib] --> A
    A --> D[server.hpp]
    A --> E[profiler.hpp]
    A --> F[filesystem.hpp]
    A --> G[component.hpp]
    G --> H[gameobject.hpp]
    A --> H 
    D --> H
    H --> I[game.cpp]
´´´