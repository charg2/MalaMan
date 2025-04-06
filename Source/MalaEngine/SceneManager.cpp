import EnginePch;
import SceneManager;
import DontDestoryOnLoad;

void SceneManager::Initialize()
{
	_dontDestroyOnLoad = CreateScene< DontDestroyOnLoad >( L"DontDestroyOnLoad" );
}

void SceneManager::Update()
{
	_activeScene->Update();
	_dontDestroyOnLoad->Update();
}

void SceneManager::LateUpdate()
{
	_activeScene->LateUpdate();
	_dontDestroyOnLoad->LateUpdate();
}

void SceneManager::Render()
{
    _activeScene->Render();
    _dontDestroyOnLoad->Render();
}
