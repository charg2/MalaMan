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
	/// 초기화한다.
	void Initialize( HWND hwnd );

	/// 갱신한다.
	void Update();
	void Render();

private:
	/// 윈도우의 핸들
	HWND _hwnd{};

	/// 윈도우 크기
	u32 _width{};
	u32 _height{};

	/// 그래픽스의 포인터
	std::shared_ptr< Graphics > _graphics{};
};

inline extern std::unique_ptr< Engine > GEngine{};