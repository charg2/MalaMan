export module SceneManager;

import EnginePch;

import Scene;

export
{

class SceneManager
{
public:
	template< typename T >
	static Scene* CreateScene( const std::wstring& name )
	{
		T* scene = new T();
		_scenes.emplace( std::make_pair( name, scene ) );
		scene->SetName( name );
		scene->Initialize();
		return scene;
	}
	template< typename T >
	static Scene* LoadScene( const std::wstring& name )
	{
		return {};
	}
public:
	SceneManager() = default;
	virtual ~SceneManager() = default;

	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render( HDC hdec );

private:
	static std::map< std::wstring, Scene* > _scenes;
	inline static Scene* _activeScene{};
	inline static Scene* _dontDestroyOnLoad{};
};

}

void SceneManager::Initialize()
{
}

void SceneManager::Update()
{
}

void SceneManager::LateUpdate()
{
}

void SceneManager::Render( HDC hdec )
{
}
