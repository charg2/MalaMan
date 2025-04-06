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
	/// 윈도우 핸들
	HWND _hwnd;

    /// <summary>
    /// Dx 디바이스
    /// </summary>
	ComPtr< ID3D11Device > _device{};

	/// <summary>
	/// Dx 디바이스 문맥
	/// </summary>
	ComPtr< ID3D11DeviceContext > _deviceContext{};

    /// <summary>
    /// 스왑체인
    /// </summary>
    ComPtr< IDXGISwapChain > _swapChain{};

    /// <summary>
    /// 스왑체인
    /// </summary>
	ComPtr< ID3D11RenderTargetView > _renderTargetView;

    /// <summary>
    /// 스왑체인
    /// </summary>
    ComPtr< ID3D11DepthStencilView > _depthStencilView;
	D3D11_VIEWPORT _viewport{};
	float _clearColor[ 4 ]{};

};

