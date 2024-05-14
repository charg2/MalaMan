export module Graphics;

import EnginePch;

export class Graphics
{
public:
	Graphics( HWND hwnd );
	~Graphics() = default;

	void RenderBegin();
	void RenderEnd();

	void CreateDeviceAndSwapChain();
	void CreateRenderTargetView();
	void SetViewport();

	ComPtr< ID3D11Device > GetDevice() { return _device; }
	ComPtr< ID3D11DeviceContext > GetDeviceContext() { return _deviceContext; }

private:
	/// ������ �ڵ�
	HWND _hwnd;

	/// Dx ����̽�
	ComPtr< ID3D11Device > _device{};

	/// Dx ����̽� ����
	ComPtr< ID3D11DeviceContext > _deviceContext{};


	ComPtr< IDXGISwapChain > _swapChain = nullptr;
	ComPtr< ID3D11RenderTargetView > _renderTargetView;
	D3D11_VIEWPORT _viewport{};
	float _clearColor[ 4 ]{};
};

