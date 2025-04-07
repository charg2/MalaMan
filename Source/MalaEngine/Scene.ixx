export module Scene;


import EnginePch;
import Entity;

export
{

class GameObject;
class Layer;

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

    void AddGameObject( GameObject* gameObj, const ELayerType type );
    void EraseGameObject( GameObject* gameObj );

    Layer* GetLayer( const ELayerType type ) const { return _layers[ static_cast<UINT>( type ) ]; }

private:
	std::vector< GameObject* > _objects{};

    void createLayers();

    std::vector<Layer*> _layers;
};

}
