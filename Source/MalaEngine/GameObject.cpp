import EnginePch;
import GameObject;
import Component;
import Transform;



GameObject::GameObject()
{
    _components.resize( static_cast< u32 >( EComponentType::Max ) );
    AddComponent< Transform >();
}

void GameObject::Initialize()
{
    for ( Component* comp : _components )
    {
        if ( !comp )
            continue;

        comp->Initialize();
    }
}

void GameObject::Update()
{
    for ( Component* comp : _components )
    {
        if ( !comp )
            continue;

        comp->Update();
    }
}

void GameObject::LateUpdate()
{
    for ( Component* comp : _components )
    {
        if ( !comp )
            continue;

        comp->LateUpdate();
    }
}

void GameObject::Render()
{
    for ( Component* comp : _components )
    {
        if ( !comp )
            continue;

        comp->Render();
    }
}
