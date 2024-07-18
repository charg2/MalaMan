export module GameObject;

import EnginePch;

export
{

class Component;

class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject() = default;

    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void LateUpdate() = 0;
    virtual void Render( HDC hdc );

	void SetPosition( f32 x, f32 y );

    template< typename T >
    T* GetComponent()
    {
        T* component = nullptr;
        for ( Component* comp : _components )
        {
            component = dynamic_cast< T* >( comp );
            if ( component )
                break;
        }

        return component;
    }

    template< typename T >
    T* AddComponent()
    {
        T* comp = new T();
        comp->SetOwner( this );
        _components.emplace_back( comp );

        return comp;
    }


private:
	XMFLOAT2 _pos{};
	XMFLOAT2 _scale{};
	XMFLOAT2 _rotation{};

    std::vector< Component* > _components;
};

}

inline void GameObject::SetPosition( f32 x, f32 y )
{
	_pos.x = x;
	_pos.y = y;
}
