export module Transform;

import EnginePch;
import Component;

export
{

struct Pos
{
	int mX;
	int mY;
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

	void SetPos( int x, int y ) { mX = x; mY = y; }
	int GetX() { return mX; }
	int GetY() { return mY; }

private:
	int mX;
	int mY;
};

}
