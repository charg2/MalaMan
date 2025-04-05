export module DontDestoryOnLoad;

import Scene;

export class DontDestroyOnLoad final : public Scene
{
public:
	DontDestroyOnLoad() = default;
	virtual ~DontDestroyOnLoad() = default;

	void Initialize() final;
	void Update() final;
	void LateUpdate() final;
	void Render( HDC hdc ) final;

	/*void OnEnter() final
	void OnExit() override;*/
};

