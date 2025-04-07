import EnginePch;
import Scene;
import Layer;
import GameObject;


void Scene::Update()
{
	for ( auto* layer : _layers )
	{
        layer->Update();
	}
}

void Scene::LateUpdate()
{
	for ( auto* layer : _layers )
	{
        layer->LateUpdate();
	}
}

void Scene::Render()
{
    for ( auto* layer : _layers )
    {
        layer->Render();
    }
}

void Scene::Destroy()
{
}

void Scene::Release()
{
}

void Scene::AddGameObject( GameObject* gameObj, const ELayerType type )
{
    _layers[ static_cast< u32 >( type ) ]->AddGameObject( gameObj );
}

void Scene::EraseGameObject( GameObject* gameObj )
{
    if ( !gameObj )
        return;

    ELayerType layerType = gameObj->GetLayerType();
    _layers[ static_cast< u32 >( layerType ) ]->EraseGameObject( gameObj );
}

void Scene::createLayers()
{
    _layers.resize( static_cast< u32 >( ELayerType::Max ) );
    for ( size_t i = 0; i < static_cast< u32 >( ELayerType::Max ); i++ )
    {
        _layers[ i ] = new Layer();
    }
}
