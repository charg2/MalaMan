export module Transform;

import EnginePch;
import Component;
import Math;

export
{

class Transform final : public Component
{
public:
	Transform();
	~Transform() final = default;

	void Initialize() final;
	void Update() final;
	void LateUpdate() final;
	void Render() final;

    Vector2 GetPos() const { return _pos; }
	void SetPos( f32 x, f32 y ) { _pos.x = x; _pos.y = y; }
	int GetX() { return _pos.x; }
	int GetY() { return _pos.y; }

private:
    Vector2 _pos{};
    Vector2 _scale{};
    Vector2 _rotation{};

    Transform* _parent{};
};

}
