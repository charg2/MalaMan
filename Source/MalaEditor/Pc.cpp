#include "Pc.h"

import Transform;

void Pc::Initialize()
{
    GameObject::Initialize();
}

void Pc::Update()
{
    GameObject::Update();
}

void Pc::LateUpdate()
{
    GameObject::LateUpdate();
}

void Pc::Render()
{
    GameObject::Render();
}

void Triangle::Initialize()
{
    GameObject::Initialize();

    _vertices.resize( 3 );

    _vertices[ 0 ].position = {  0.0f,  0.5f, 0.f };
    _vertices[ 1 ].position = {  0.5f, -0.5f, 0.f };
    _vertices[ 2 ].position = { -0.5f, -0.5f, 0.f };

    _vertices[ 0 ].color = { 0, 1, 0, 1 };
    _vertices[ 1 ].color = { 1, 0, 0, 1 };
    _vertices[ 2 ].color = { 0, 0, 1, 1 };
}

void Triangle::Update()
{
    GameObject::Update();
}

void Triangle::LateUpdate()
{
    GameObject::LateUpdate();
}

void Triangle::Render()
{
    GameObject::Render();
}
