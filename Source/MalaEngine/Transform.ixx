export module Transform;

import EnginePch;
import Component;

export
{

struct Pos
{
	int x;
	int y;
};

class Transform : public Component
{
public:
	Transform() = default;
	virtual ~Transform() = default;

	void Initialize() final;
	void Update() final;
	void LateUpdate() final;
	void Render( HDC hdc ) final;

	void SetPos( int x, int y ) { x = x; y = y; }
	int GetX() { return _pos.x; }
	int GetY() { return _pos.y; }

private:
	Pos _pos;
};

}
