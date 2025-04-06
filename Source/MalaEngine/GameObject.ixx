export module GameObject;

import EnginePch;

export
{

class Component;

class GameObject
{
    enum class EState
    {
        Created,
        Active,
        Paused,
        Destroyed,
        End
    };

public:
	GameObject();
	virtual ~GameObject() = default;

    virtual void Initialize();
    virtual void Update();
    virtual void LateUpdate();
    virtual void Render();

    template< std::derived_from< Component > TComponent >
    TComponent* GetComponent()
    {
        TComponent* component{};
        for ( Component* comp : _components )
        {
            component = dynamic_cast< TComponent* >( comp );
            if ( component )
                break;
        }

        return component;
    }

    template< std::derived_from< Component > TComponent >
    TComponent* AddComponent()
    {
        auto* comp{ new TComponent() };
        comp->Initialize();
        comp->SetOwner( this );

        _components[ static_cast< u32 >( comp->GetType() ) ] = comp;

        return comp;
    }

private:
	//XMFLOAT2 _pos{};
	//XMFLOAT2 _scale{};
	//XMFLOAT2 _rotation{};

    EState _state{};
    std::vector< Component* > _components;
};

}
