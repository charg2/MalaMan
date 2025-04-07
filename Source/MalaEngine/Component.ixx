export module Component;

import EnginePch;
import Entity;

export
{

class GameObject;

class Component : public Entity
{
public:
    Component( EComponentType type );
    virtual ~Component() = default;

    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void LateUpdate() = 0;
    virtual void Render() = 0;

    void SetOwner( GameObject* owner ) { _owner = owner; };
    GameObject* GetOwner() { return _owner; }
    EComponentType GetType() const { return _type; }

private: 
    GameObject* _owner;
    EComponentType _type;
};

}
