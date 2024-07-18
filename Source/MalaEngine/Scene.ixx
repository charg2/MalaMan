export module Scene;


import EnginePch;
import Entity;

export
{

class GameObject;

class Scene : public Entity
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual void Initialize(){};
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render( HDC hdc );
	virtual void Destroy();
	virtual void Release();


	std::vector< GameObject* > _objects;
};

}
