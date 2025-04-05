export module Entity;

import EnginePch;

export class Entity
{
public:
    Entity() = default;
    virtual ~Entity() = default;

    void SetName( const std::wstring& name ) { _name = name; }
    std::wstring& GetName() { return _name; }

private:
    std::wstring _name;
};
