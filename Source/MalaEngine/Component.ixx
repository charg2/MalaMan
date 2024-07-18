export module Component;

import EnginePch;

export
{

class GameObject;

class Component 
{
public:
    Component() = default;
    virtual ~Component() = default;

    virtual void Initialize() = 0;
    virtual void Update() = 0; 
    virtual void LateUpdate() = 0;
    virtual void Render( HDC hdc ) = 0;

    void SetOwner( GameObject* owner ) { _owner = owner; };
    GameObject* GetOwner() { return _owner; }

private:
    GameObject* _owner;
};

}