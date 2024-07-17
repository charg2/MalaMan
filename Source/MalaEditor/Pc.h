#pragma once

import GameObject;

class Pc final : public GameObject
{
	void Update() final;
	void LateUpdate() final;
	void Render() final;
};

