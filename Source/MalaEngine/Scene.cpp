import EnginePch;
import Scene;
import GameObject;


void Scene::Update()
{
	for ( auto* object : _objects )
	{
		object->Update();
	}
}

void Scene::LateUpdate()
{
	for ( auto* object : _objects )
	{
		object->LateUpdate();
	}
}

void Scene::Render( HDC hdc )
{
	for ( auto* object : _objects )
	{
		object->Render( hdc );
	}
}

void Scene::Destroy()
{
}

void Scene::Release()
{
}
