#pragma once

import GameObject;

class Pc final : public GameObject
{
	void Initialize() final;
	void Update() final;
	void LateUpdate() final;
	void Render() final;
};

class Triangle final : public GameObject
{
    void Initialize() final;
    void Update() final;
    void LateUpdate() final;
    void Render() final;
};

