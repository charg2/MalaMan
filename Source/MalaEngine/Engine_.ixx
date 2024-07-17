export module Engine:Impl;

import EnginePch;
import Engine;
import Graphics;
import Input;
import <format>;


Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Initialize( HWND hwnd )
{
	_hwnd = hwnd;
	_hdc = ::GetDC( hwnd );

	_graphics = std::make_shared< Graphics >( hwnd );

	//Input::Initialize();
	CreateGeometry();
	CreateInputLayout();
}

void Engine::Run()
{
	Update();
	LateUpdate();
	Render();
}

void Engine::Update()
{
}

void Engine::LateUpdate()
{
}

void Engine::Render()
{

	Rectangle( _hdc, 0, 0, 100, 100 );
	//// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

	//_graphics->RenderBegin();

	//_graphics->RenderEnd();
}

void Engine::ShowFPS()
{
	u32 fps = 30;

	SetWindowTextW( _hwnd, std::format( L"FPS: {}", fps ).c_str() );
}

void Engine::CreateGeometry()
{
	_vertices.resize( 3 );

	_vertices[ 0 ].position = { 0.0f, 0.5f, 0.f };
	_vertices[ 1 ].position = { 0.0f, 0.5f, 0.f };
	_vertices[ 2 ].position = { 1.0f, 0.0f, 1.f };

	_vertices[ 0 ].color = { 1, 0, 0, 1 };
	_vertices[ 1 ].color = { 1, 0, 0, 1 };
	_vertices[ 2 ].color = { 1, 0, 0, 1 };


	D3D11_BUFFER_DESC desc
	{
		.ByteWidth           = sizeof( Vertex ) * (UINT)( _vertices.size() ),
		.Usage               = D3D11_USAGE_IMMUTABLE,
		.BindFlags           = D3D11_BIND_VERTEX_BUFFER,
		.CPUAccessFlags      = 0,
		.MiscFlags           = 0,
		.StructureByteStride = 0
	};


	D3D11_SUBRESOURCE_DATA data
	{
		.pSysMem          = _vertices.data(),
		.SysMemPitch      = 0,
		.SysMemSlicePitch = 0
	};

	_graphics->GetDevice()->CreateBuffer( &desc, &data, _vertexBuffer.GetAddressOf() );
}

void Engine::CreateInputLayout()
{
	/// Vertex의 구조에 대한 묘사
	D3D11_INPUT_ELEMENT_DESC layout[]
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }, // Color가 12바이트 위치
	};

	const i32 count = sizeof( layout ) / sizeof( D3D11_INPUT_ELEMENT_DESC );
	_graphics->GetDevice()->CreateInputLayout( layout, count, nullptr, 0, nullptr );// _inputLayout.GetAddressOf() );
}

void Engine::LoadShaderFromFile( const std::wstring& path, const std::string& name, const std::string& version, ComPtr<ID3DBlob>& blob )
{
	const u32 flags = ( 1 << 2 );

	::D3DCompileFromFile( path.c_str(), nullptr, nullptr, name.c_str(), version.c_str(), 0, 0, blob.GetAddressOf(), nullptr );

}
