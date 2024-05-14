export module Engine;

import EnginePch;
import EngineTypes;

export class Graphics;

export class Engine
{
public:
	Engine();
	~Engine();

public:
	/// �ʱ�ȭ�Ѵ�.
	void Initialize( HWND hwnd );

	/// �����Ѵ�.
	void Update();
	void Render();

private:
	/// �������� �ڵ�
	HWND _hwnd{};

	/// ������ ũ��
	u32 _width{};
	u32 _height{};

	/// �׷��Ƚ��� ������
	std::shared_ptr< Graphics > _graphics{};
};

inline extern std::unique_ptr< Engine > GEngine{};