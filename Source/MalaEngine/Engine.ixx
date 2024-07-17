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
	/// �ʱ�ȭ�Ѵ�.
	void Initialize( HWND hwnd );

	void Run();
	void Update();
	void LateUpdate();
	void Render();

	void ShowFPS();
	void CreateGeometry();
	void CreateInputLayout();
	void LoadShaderFromFile(
		const std::wstring& path,
		const std::string& name,
		const std::string& version,
		ComPtr< ID3DBlob >& blob );

private:
	/// �������� �ڵ�
	HWND _hwnd{};
	HDC _hdc;

	/// ������ ũ��
	u32 _width{};
	u32 _height{};

	/// �׷��Ƚ��� ������
	std::shared_ptr< Graphics > _graphics{};
	std::vector< Vertex > _vertices{};
	ComPtr< ID3D11Buffer > _vertexBuffer{};

	ComPtr< ID3D11VertexShader > _vertexShader{};
	ComPtr< ID3DBlob > _vsBlob{};


};

inline extern std::unique_ptr< Engine > GEngine{};