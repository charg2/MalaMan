import EnginePch;
import Layer;
import GameObject;


void Layer::Update()
{
	for ( auto* object : _gameObjects )
	{
		object->Update();
	}
}

void Layer::LateUpdate()
{
	for ( auto* object : _gameObjects )
	{
		object->LateUpdate();
	}
}

void Layer::Render()
{
    for ( auto* object : _gameObjects )
    {
        object->Render();
    }
}

void Layer::AddGameObject( GameObject* gameObj )
{
    _gameObjects.push_back( gameObj );
    //gameObj->SetLayerType( _layerType );
}

void Layer::EraseGameObject( GameObject* gameObj )
{
    auto iter = std::find( _gameObjects.begin(), _gameObjects.end(), gameObj );
    if ( iter != _gameObjects.end() )
    {
        _gameObjects.erase( iter );
    }
}
