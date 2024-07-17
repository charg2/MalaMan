export module GameObject;

import EnginePch;

export
{

class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject() = default;

	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;

	void SetPosition( f32 x, f32 y )
	{
		_pos.x = x;
		_pos.y = y;
	}

private:
	XMFLOAT2 _pos{};
	XMFLOAT2 _scale{};
	XMFLOAT2 _rotation{};
};

}