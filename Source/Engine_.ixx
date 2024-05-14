export module Engine:Impl;

import EnginePch;
import Engine;
import Graphics;

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Initialize( HWND hwnd )
{
	_graphics = std::make_shared< Graphics >( hwnd );
}

void Engine::Update()
{
}

void Engine::Render()
{
	_graphics->RenderBegin();

	_graphics->RenderEnd();
}

