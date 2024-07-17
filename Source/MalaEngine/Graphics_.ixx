export module Graphics:Impl;

import EnginePch;
import EngineGlobal;
import Graphics;

/// <summary>
/// 생성자
/// </summary>
Graphics::Graphics( HWND hwnd )
: _hwnd{ hwnd }
{
	// 생성과 동시에 Device, DeviceContext, Viewport를 생성해줍니다.
	CreateDeviceAndSwapChain();
	CreateRenderTargetView();
	SetViewport();
}

void Graphics::RenderBegin()
{
	_deviceContext->OMSetRenderTargets( 1, _renderTargetView.GetAddressOf(), nullptr );
	_deviceContext->ClearRenderTargetView( _renderTargetView.Get(), _clearColor );
	_deviceContext->RSSetViewports( 1, &_viewport );
}

void Graphics::RenderEnd()
{
	HRESULT hr = _swapChain->Present( 1, 0 );
	CHECK( hr );
}

/// <summary>
/// 디바이스와 스왑체인을 생성한다.
/// </summary>
void Graphics::CreateDeviceAndSwapChain()
{
	// desc의 내용을 다시 채워줍니다.
	/// 더블 버퍼링
	auto desc = DXGI_SWAP_CHAIN_DESC
	{
		.BufferDesc =
		{ 
			.Width  = GWindowWidth, 
			.Height = GWindowHeight,

			.RefreshRate{ .Numerator = 60, .Denominator = 1 },

			.Format           = DXGI_FORMAT_R8G8B8A8_UNORM,
			.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED,
			.Scaling          = DXGI_MODE_SCALING_UNSPECIFIED
		},

		.SampleDesc{ .Count = 1, .Quality = 0 },

		.BufferUsage  = DXGI_USAGE_RENDER_TARGET_OUTPUT_,
		.BufferCount  = 1,
		.OutputWindow = _hwnd,
		.Windowed     = true,
		.SwapEffect   = DXGI_SWAP_EFFECT_DISCARD,
		.Flags        = 0
	};

	// Device와 SwapChain을 생성
	HRESULT hr = ::D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION_,
		&desc,
		_swapChain.GetAddressOf(),
		_device.GetAddressOf(),
		nullptr,
		_deviceContext.GetAddressOf()
	);

	CHECK( hr );
}

void Graphics::CreateRenderTargetView()
{
	ComPtr< ID3D11Texture2D > backBuffer{};
	HRESULT hr = _swapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)backBuffer.GetAddressOf() );

	CHECK( hr );
	_device->CreateRenderTargetView( backBuffer.Get(), nullptr, _renderTargetView.GetAddressOf() );
	CHECK( hr );
}

void Graphics::SetViewport()
{
	_viewport.TopLeftX = 0.0f;
	_viewport.TopLeftY = 0.0f;
	_viewport.Width = static_cast< float >( GWindowWidth );
	_viewport.Height = static_cast< float >( GWindowHeight );
	_viewport.MinDepth = 0.0f;
	_viewport.MaxDepth = 1.0f;
}
