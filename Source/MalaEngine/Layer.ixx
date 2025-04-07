export module Layer;


import EnginePch;
import Entity;

export
{

class GameObject;

class Layer final : public Entity
{
public:
    Layer() = default;
    ~Layer() final{};

    virtual void Initialize() final {};
    virtual void Update() final;
    virtual void LateUpdate() final;
    virtual void Render() final;
    //virtual void EndOfFrame() final;

    void AddGameObject( GameObject* gameObject );
    void EraseGameObject( GameObject* eraseGameObj );
    std::vector< GameObject* >& GetGameObjects() { return _gameObjects; }

private:
    void findDeadGameObjects( std::vector<GameObject*>& gameObjects );
    void deleteGameObjects( std::vector<GameObject*> gameObjects );
    void eraseDeadGameObject();

    std::vector< GameObject* > _gameObjects;
};

}
