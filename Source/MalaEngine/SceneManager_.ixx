export module SceneManager:impl;

import EnginePch;
import SceneManager;


void SceneManager::Initialize()
{
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

void SceneManager::Render( HDC hdc )
{
	_activeScene->Render( hdc );
	_dontDestroyOnLoad->Render( hdc );
}