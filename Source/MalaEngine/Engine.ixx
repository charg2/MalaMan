export module Engine;

import EnginePch;
import EngineTypes;

import <string>;

export class Graphics;

export class Engine
{
public:
	Engine();
	~Engine();

public:
	/// 초기화한다.
	void Initialize( HWND hwnd );

	void Run();
	void Update();
	void LateUpdate();
	void Render();
	void Destroy();
	void Release();

	void ShowFPS();
	void CreateGeometry();
	void CreateInputLayout();
	void LoadShaderFromFile(
		const std::wstring& path,
		const std::string& name,
		const std::string& version,
		ComPtr< ID3DBlob >& blob );

    bool IsRunning() { return _running; }

private:
	/// 윈도우의 핸들
	HWND _hwnd{};
	HDC _hdc;

	/// 윈도우 크기
	u32 _width{};
	u32 _height{};

	/// 그래픽스의 포인터
	std::shared_ptr< Graphics > _graphics{};
	std::vector< Vertex > _vertices{};
	ComPtr< ID3D11Buffer > _vertexBuffer{};

    ComPtr< ID3D11VertexShader > _vertexShader{};
	ComPtr< ID3DBlob > _vsBlob{};
    ComPtr< ID3D11PixelShader > _pixelShader{};
    ComPtr< ID3DBlob > _psBlob{};

    ComPtr< ID3D11InputLayout > _inputLayout;
    bool _running{ true };
};
