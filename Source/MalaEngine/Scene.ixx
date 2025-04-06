export module Scene;


import EnginePch;
import Entity;

export
{

class GameObject;

class Scene : public Entity
{
public:
    using Super = Scene;

public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void Initialize(){};
	virtual void Update();
	virtual void LateUpdate();
    virtual void Render();
	virtual void Destroy();
	virtual void Release();

	void AddGameObject( GameObject* gameObject );

private:
	std::vector< GameObject* > _objects{};
};

}
