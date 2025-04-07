export module RigidBody;

import EnginePch;
import Component;
import Math;

export
{

class RigidBody final : public Component
{
public:
    RigidBody();
    ~RigidBody() final{};

    void Initialize() final;
    void Update() final;
    void LateUpdate() final;
    void Render() final;

    Vector2 GetVelocity() const { return _velocity; }
    void SetMass( float mass ) { _mass = mass; }
    void AddForce( Vector2 force ) { _force = force; }
    void SetGround( bool ground ) { _ground = ground; }
    void SetVelocity( Vector2 velocity ) { _velocity = velocity; }

private:
    bool _ground;
    float _mass;
    float _friction;

    Vector2 _force;
    Vector2 _accelation;
    Vector2 _velocity;
    Vector2 _limitedVelocity;
    Vector2 _gravity;
};

}
