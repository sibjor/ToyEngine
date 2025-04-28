# Notes from class! 
- When a function is "static" it means - you can call it without needing an instance of an object! Object object = new Object(); - not being necessary!
- Rendering is a mathematical heavy process, might not be your part of programming!
- Smaller companies are typically more generalist. In AAA it's important to find your niche!
- In your future internship you might get a feel of where you fit in?
- Auxilliary layers = Audio, Networking, Collision & Phyisics, AI... Typically runs on separate threads
- Foundation layer = (What were gonna focus on) - High Level Game Flow / States, Events, Game objects management, scripting system, world loading / streaming
- RAII - resource acquisition is initialization. Constructors new. Destructors delete. Then you have symmetry. 
- Not following RAII, would be assymetrical. That said - not implementing self destructs or allocating by new.
- Assymetrical classes is useful while resources are allocated from elsewhere.
- Virtual structs, functions, classes etc can't be instanced by themselfes. See them as placeholders of whats gonna happen when called. Using pointers, you can mix them, calling the apropritate method each time. A virtual function is like a contract.
- Constructors and destructors of inherited objects are called first at base class, and finishing with the destructor of the base class.
- ECS - entity component system.
- DOTS - a type of ECS, "Data Oriented ...", non object oriented approach.
- Reference - a different kind of pointer, a raw pointer that cant be null, which destination cant be changed.
- Symmetrical/Asymmetrical ownership - which owner is new:ing and deleting the object?
- A pointer points to somewhere on the heap
- auto - like "var" in C#
- unique_ptr can be moved to another allocated unique_ptr but never copied. std::move(a_ptr)...
## State pattern
- Instead of a swtich statement, write polymorphic c++ classes for each state, switching between objects in a controller class.
- A holder of a single changing pointer to an object for each state.
- The holder was allocated as a std::stack
- unique_ptr can be moved between owners, making sure the owner is solo. They are deallocated automatically when they go out of scope.
- 
## Game Object Management
- Inheritance based? Actor->Mario
- Component based? Actors have lists of components
- Not Object Oriented? Entity component systems / ECS

## Scripting system
- Look into LUA to integreate an existing scripting language
- Compilation or JIT can be leverages for speeds
- Visual Representations of scripting systems (like blueprint)
- Bespoke scripting languages (GDScript etc..)

## What you ar eto do:
- Copy some concepts or ideas from large modern game engines, into your "toy engine"!