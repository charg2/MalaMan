export module Game;

import EnginePch;
import EngineTypes;

export class Game
{
public:
	Game();
	~Game();

public:
	void Initialize( HWND hwnd );
	void Update();
	void Render();
	void Release();

private:
	HWND _hwnd{};
	u32 _width{};
	u32 _height{};
};
