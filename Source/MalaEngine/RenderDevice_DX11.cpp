#include <intsafe.h>
#include <assert.h>
#include <d3dcompiler.h>
#include <d3d11.h>

import EnginePch;
import EngineGlobal;
import RenderDevice_DX11;
import Engine;


RenderDevice_DX11::RenderDevice_DX11()
{
    GetDevice() = this;

    if ( !( CreateDevice() ) )
        assert( NULL && "Create Device Failed!" );
}

bool RenderDevice_DX11::CreateDevice()
{
    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };
    UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#if defined(DEBUG) || defined(_DEBUG)
    creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    if ( FAILED( D3D11CreateDevice( nullptr, D3D_DRIVER_TYPE_HARDWARE,
        nullptr, creationFlags,
        featureLevels, ARRAYSIZE( featureLevels ),
        D3D11_SDK_VERSION, _device.GetAddressOf(),
        nullptr, _context.GetAddressOf() ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateSwapchain( DXGI_SWAP_CHAIN_DESC desc )
{
    ComPtr<IDXGIDevice> pDXGIDevice = nullptr;
    ComPtr<IDXGIAdapter> pAdapter = nullptr;
    ComPtr<IDXGIFactory> pFactory = nullptr;

    if ( FAILED( _device->QueryInterface( __uuidof( IDXGIDevice ), (void**)pDXGIDevice.GetAddressOf() ) ) )
        return false;

    if ( FAILED( pDXGIDevice->GetParent( __uuidof( IDXGIAdapter ), (void**)pAdapter.GetAddressOf() ) ) )
        return false;

    if ( FAILED( pAdapter->GetParent( __uuidof( IDXGIFactory ), (void**)pFactory.GetAddressOf() ) ) )
        return false;

    if ( FAILED( pFactory->CreateSwapChain( _device.Get(), &desc, _swapChain.GetAddressOf() ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::GetBuffer( UINT Buffer, REFIID riid, void** ppSurface )
{
    if ( FAILED( _swapChain->GetBuffer( Buffer, riid, ppSurface ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateRenderTargetView( ID3D11Resource* pResource,
    const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
    ID3D11RenderTargetView** ppRTView )
{
    if ( FAILED( _device->CreateRenderTargetView( pResource, pDesc, ppRTView ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateDepthStencilView( ID3D11Resource* pResource,
    const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
    ID3D11DepthStencilView** ppDepthStencilView )
{
    if ( FAILED( _device->CreateDepthStencilView( pResource, pDesc, ppDepthStencilView ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateTexture2D( const D3D11_TEXTURE2D_DESC* pDesc,
    const D3D11_SUBRESOURCE_DATA* pInitialData, ID3D11Texture2D** ppTexture2D )
{
    if ( FAILED( _device->CreateTexture2D( pDesc, pInitialData, ppTexture2D ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateSamplerState( const D3D11_SAMPLER_DESC* pSamplerDesc,
    ID3D11SamplerState** ppSamplerState )
{
    if ( FAILED( _device->CreateSamplerState( pSamplerDesc, ppSamplerState ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateVertexShader( const std::wstring& fileName, ID3DBlob** ppCode,
    ID3D11VertexShader** ppVertexShader )
{
    DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
    shaderFlags |= D3DCOMPILE_DEBUG;
    shaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;

    ID3DBlob* errorBlob = nullptr;
    const std::wstring shaderFilePath = L"..\\Shaders_SOURCE\\";
    D3DCompileFromFile( ( shaderFilePath + fileName + L"VS.hlsl" ).c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE
        , "main", "vs_5_0", shaderFlags, 0, ppCode, &errorBlob );

    if ( errorBlob )
    {
        OutputDebugStringA( static_cast<char*>( errorBlob->GetBufferPointer() ) );
        errorBlob->Release();
        assert( NULL && "hlsl file have problem check message!" );
        return false;
    }

    if ( FAILED(
        _device->CreateVertexShader( ( *ppCode )->GetBufferPointer(), ( *ppCode )->GetBufferSize(), nullptr,
            ppVertexShader ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreatePixelShader( const std::wstring& fileName, ID3DBlob** ppCode,
    ID3D11PixelShader** ppPixelShader )
{
    DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
    shaderFlags |= D3DCOMPILE_DEBUG;
    shaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;

    ID3DBlob* errorBlob = nullptr;
    const std::wstring shaderFilePath = L"..\\Shaders_SOURCE\\";
    D3DCompileFromFile( ( shaderFilePath + fileName + L"PS.hlsl" ).c_str(), nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE
        , "main", "ps_5_0", shaderFlags, 0, ppCode, &errorBlob );

    if ( errorBlob )
    {
        OutputDebugStringA( static_cast<char*>( errorBlob->GetBufferPointer() ) );
        errorBlob->Release();
        assert( NULL && "hlsl file have problem check message!" );
        return false;
    }

    if ( FAILED(
        _device->CreatePixelShader( ( *ppCode )->GetBufferPointer(), ( *ppCode )->GetBufferSize(), nullptr, ppPixelShader
        ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateInputLayout( const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs, UINT NumElements
    , const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength,
    ID3D11InputLayout** ppInputLayout )
{
    if ( FAILED( _device->CreateInputLayout( pInputElementDescs, NumElements
        , pShaderBytecodeWithInputSignature
        , BytecodeLength
        , ppInputLayout ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateBuffer( const D3D11_BUFFER_DESC* pDesc, const D3D11_SUBRESOURCE_DATA* pInitialData,
    ID3D11Buffer** ppBuffer )
{
    if ( FAILED( _device->CreateBuffer( pDesc, pInitialData, ppBuffer ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateShaderResourceView( ID3D11Resource* pResource,
    const D3D11_SHADER_RESOURCE_VIEW_DESC* pDesc,
    ID3D11ShaderResourceView** ppSRView )
{
    if ( FAILED( _device->CreateShaderResourceView( pResource, pDesc, ppSRView ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateUnorderedAccessView( ID3D11Resource* pResource, const D3D11_UNORDERED_ACCESS_VIEW_DESC* pDesc, ID3D11UnorderedAccessView** ppUAView )
{
    if ( FAILED( _device->CreateUnorderedAccessView( pResource, pDesc, ppUAView ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateRasterizerState( const D3D11_RASTERIZER_DESC* pRasterizerDesc,
    ID3D11RasterizerState** ppRasterizerState )
{
    if ( FAILED( _device->CreateRasterizerState( pRasterizerDesc, ppRasterizerState ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateBlendState( const D3D11_BLEND_DESC* pBlendState, ID3D11BlendState** ppBlendState )
{
    if ( FAILED( _device->CreateBlendState( pBlendState, ppBlendState ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::CreateDepthStencilState( const D3D11_DEPTH_STENCIL_DESC* pDepthStencilDesc,
    ID3D11DepthStencilState** ppDepthStencilState )
{
    if ( FAILED( _device->CreateDepthStencilState( pDepthStencilDesc, ppDepthStencilState ) ) )
        return false;

    return true;
}

bool RenderDevice_DX11::Resize( D3D11_VIEWPORT viewport )
{
    _frameBufferView.Reset();
    _frameBuffer.Reset();

    _depthStencilView.Reset();
    _depthStencil.Reset();

    HRESULT hr = _swapChain->ResizeBuffers( 0, // 현재 개수 유지
        (UINT)viewport.Width, // 해상도 변경
        (UINT)viewport.Height,
        DXGI_FORMAT_UNKNOWN, // 현재 포맷 유지
        0 );

    // Get render target by Swapchain
    Microsoft::WRL::ComPtr<ID3D11Texture2D> renderTarget = nullptr;
    hr = _swapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)( renderTarget.GetAddressOf() ) );

    D3D11_TEXTURE2D_DESC desc = {};
    renderTarget->GetDesc( &desc );
    _frameBuffer = renderTarget;

    // Create RenderTargetView
    hr = _device->CreateRenderTargetView( _frameBuffer.Get(), nullptr, _frameBufferView.GetAddressOf() );

    // Create DepthStencil
    D3D11_TEXTURE2D_DESC depthStencilDesc = {};
    depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
    depthStencilDesc.Width = (UINT)viewport.Width;
    depthStencilDesc.Height = (UINT)viewport.Height;
    depthStencilDesc.ArraySize = 1;
    depthStencilDesc.SampleDesc.Count = 1;
    depthStencilDesc.SampleDesc.Quality = 0;
    depthStencilDesc.MipLevels = 1;
    depthStencilDesc.MiscFlags = 0;

    hr = _device->CreateTexture2D( &depthStencilDesc, nullptr, _depthStencil.GetAddressOf() );

    // Create DepthStencilView
    hr = _device->CreateDepthStencilView( _depthStencil.Get(), nullptr, _depthStencilView.GetAddressOf() );

    // Set Viewport
    BindViewPort();

    // Bind RenderTarget
    BindRenderTargets( 1, _frameBufferView.GetAddressOf(), _depthStencilView.Get() );

    return true;
}

void RenderDevice_DX11::SetDataGpuBuffer( ID3D11Buffer* buffer, void* data, UINT size )
{
    D3D11_MAPPED_SUBRESOURCE sub = {};
    _context->Map( buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &sub );
    memcpy( sub.pData, data, size );
    _context->Unmap( buffer, 0 );
}

void RenderDevice_DX11::SetShaderResource( EShaderStage stage, UINT startSlot, ID3D11ShaderResourceView** ppSRV )
{
    if ( static_cast<UINT>( EShaderStage::VS ) & static_cast<UINT>( stage ) )
        _context->VSSetShaderResources( startSlot, 1, ppSRV );

    if ( static_cast<UINT>( EShaderStage::HS ) & static_cast<UINT>( stage ) )
        _context->HSSetShaderResources( startSlot, 1, ppSRV );

    if ( static_cast<UINT>( EShaderStage::DS ) & static_cast<UINT>( stage ) )
        _context->DSSetShaderResources( startSlot, 1, ppSRV );

    if ( static_cast<UINT>( EShaderStage::GS ) & static_cast<UINT>( stage ) )
        _context->GSSetShaderResources( startSlot, 1, ppSRV );

    if ( static_cast<UINT>( EShaderStage::PS ) & static_cast<UINT>( stage ) )
        _context->PSSetShaderResources( startSlot, 1, ppSRV );

    if ( static_cast<UINT>( EShaderStage::CS ) & static_cast<UINT>( stage ) )
        _context->CSSetShaderResources( startSlot, 1, ppSRV );
}

void RenderDevice_DX11::BindInputLayout( ID3D11InputLayout* pInputLayout )
{
    _context->IASetInputLayout( pInputLayout );
}

void RenderDevice_DX11::BindPrimitiveTopology( const D3D11_PRIMITIVE_TOPOLOGY topology )
{
    _context->IASetPrimitiveTopology( topology );
}

void RenderDevice_DX11::BindVS( ID3D11VertexShader* pVertexShader )
{
    _context->VSSetShader( pVertexShader, nullptr, 0 );
}

void RenderDevice_DX11::BindPS( ID3D11PixelShader* pPixelShader )
{
    _context->PSSetShader( pPixelShader, nullptr, 0 );
}

void RenderDevice_DX11::BindVertexBuffer( UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppVertexBuffers,
    const UINT* pStrides, const UINT* pOffsets )
{
    _context->IASetVertexBuffers( StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets );
}

void RenderDevice_DX11::BindIndexBuffer( ID3D11Buffer* pIndexBuffer, DXGI_FORMAT Format, UINT Offset )
{
    _context->IASetIndexBuffer( pIndexBuffer, Format, Offset );
}

void RenderDevice_DX11::BindConstantBuffer( EShaderStage stage, ECBType type, ID3D11Buffer* buffer )
{
    UINT slot = static_cast<UINT>( type );
    switch ( stage )
    {
    case EShaderStage::VS:
        _context->VSSetConstantBuffers( slot, 1, &buffer );
        break;
    case EShaderStage::HS:
        _context->HSSetConstantBuffers( slot, 1, &buffer );
        break;
    case EShaderStage::DS:
        _context->DSSetConstantBuffers( slot, 1, &buffer );
        break;
    case EShaderStage::GS:
        _context->GSSetConstantBuffers( slot, 1, &buffer );
        break;
    case EShaderStage::PS:
        _context->PSSetConstantBuffers( slot, 1, &buffer );
        break;
    case EShaderStage::CS:
        _context->CSSetConstantBuffers( slot, 1, &buffer );
        break;
    case EShaderStage::All:
        _context->VSSetConstantBuffers( slot, 1, &buffer );
        _context->HSSetConstantBuffers( slot, 1, &buffer );
        _context->DSSetConstantBuffers( slot, 1, &buffer );
        _context->GSSetConstantBuffers( slot, 1, &buffer );
        _context->PSSetConstantBuffers( slot, 1, &buffer );
        _context->CSSetConstantBuffers( slot, 1, &buffer );
        break;
    default:
        break;
    }
}

void RenderDevice_DX11::BindSampler( EShaderStage stage, UINT StartSlot, UINT NumSamplers,
    ID3D11SamplerState* const* ppSamplers )
{
    if ( EShaderStage::VS == stage )
        _context->VSSetSamplers( StartSlot, NumSamplers, ppSamplers );

    if ( EShaderStage::HS == stage )
        _context->HSSetSamplers( StartSlot, NumSamplers, ppSamplers );

    if ( EShaderStage::DS == stage )
        _context->DSSetSamplers( StartSlot, NumSamplers, ppSamplers );

    if ( EShaderStage::GS == stage )
        _context->GSSetSamplers( StartSlot, NumSamplers, ppSamplers );

    if ( EShaderStage::PS == stage )
        _context->PSSetSamplers( StartSlot, NumSamplers, ppSamplers );
}

void RenderDevice_DX11::BindSamplers( UINT StartSlot, UINT NumSamplers, ID3D11SamplerState* const* ppSamplers )
{
    BindSampler( EShaderStage::VS, StartSlot, NumSamplers, ppSamplers );
    BindSampler( EShaderStage::HS, StartSlot, NumSamplers, ppSamplers );
    BindSampler( EShaderStage::DS, StartSlot, NumSamplers, ppSamplers );
    BindSampler( EShaderStage::GS, StartSlot, NumSamplers, ppSamplers );
    BindSampler( EShaderStage::PS, StartSlot, NumSamplers, ppSamplers );
}

void RenderDevice_DX11::BindRasterizerState( ID3D11RasterizerState* pRasterizerState )
{
    _context->RSSetState( pRasterizerState );
}

void RenderDevice_DX11::BindBlendState( ID3D11BlendState* pBlendState, const FLOAT BlendFactor[ 4 ], UINT SampleMask )
{
    _context->OMSetBlendState( pBlendState, BlendFactor, SampleMask );
}

void RenderDevice_DX11::BindDepthStencilState( ID3D11DepthStencilState* pDepthStencilState, UINT StencilRef )
{
    _context->OMSetDepthStencilState( pDepthStencilState, StencilRef );
}

void RenderDevice_DX11::BindViewPort()
{
    D3D11_VIEWPORT viewPort =
    {
        0, 0,
        800, 600,
        //static_cast<float>( application.GetWindow().GetWidth() ),
        //static_cast<float>( application.GetWindow().GetHeight() ),
        0.0f, 1.0f
    };

    _context->RSSetViewports( 1, &viewPort );
}

void RenderDevice_DX11::BindRenderTargets( UINT NumViews
    , ID3D11RenderTargetView* const* ppRenderTargetViews
    , ID3D11DepthStencilView* pDepthStencilView )
{
    _context->OMSetRenderTargets( NumViews, ppRenderTargetViews, pDepthStencilView );
}

void RenderDevice_DX11::BindDefaultRenderTarget()
{
    _context->OMSetRenderTargets( 1, _frameBufferView.GetAddressOf(), _depthStencilView.Get() );
}

void RenderDevice_DX11::CopyResource( ID3D11Resource* pDstResource, ID3D11Resource* pSrcResource )
{
    _context->CopyResource( pDstResource, pSrcResource );
}

void RenderDevice_DX11::ClearRenderTargetView()
{
    FLOAT backgroundColor[ 4 ] = { 0.2f, 0.2f, 0.2f, 1.0f };
    _context->ClearRenderTargetView( _frameBufferView.Get(), backgroundColor );
}

void RenderDevice_DX11::ClearDepthStencilView()
{
    _context->ClearDepthStencilView( _depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0 );
}

void RenderDevice_DX11::Initialize()
{
#pragma region swapchain desc
    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};

    //swapChainDesc.OutputWindow = GEngine->GetWindow().GetHwnd();
    swapChainDesc.OutputWindow = GEngine->GetHwnd();
    swapChainDesc.Windowed = true;
    swapChainDesc.BufferCount = 2;
    swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    //swapChainDesc.BufferDesc.Width = application.GetWindow().GetWidth();
    //swapChainDesc.BufferDesc.Height = application.GetWindow().GetHeight();
    swapChainDesc.BufferDesc.Width = 800;
    swapChainDesc.BufferDesc.Height = 600;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferDesc.RefreshRate.Numerator = 144;
    swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
    swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;

#pragma region 4X MSAA surported check
    // 4X MSAA surported check
    UINT quility = 0;
    _device->CheckMultisampleQualityLevels( DXGI_FORMAT_R8G8B8A8_UNORM, 4, &quility );
    //if (quility > 0)
    //{
    //	swapChainDesc.SampleDesc.Count = 4; // how many multisamples
    //	swapChainDesc.SampleDesc.Quality = quility - 1;
    //}
#pragma endregion

    swapChainDesc.SampleDesc.Count = 1; // how many multisamples
    swapChainDesc.SampleDesc.Quality = 0;
#pragma endregion
    if ( !( CreateSwapchain( swapChainDesc ) ) )
        assert( NULL && "Create Swapchain Failed!" );

    if ( !( GetBuffer( 0, __uuidof( ID3D11Texture2D ), reinterpret_cast<void**>( _frameBuffer.GetAddressOf() ) ) ) )
        assert( NULL && "Couldn't bring rendertarget!" );

    if ( !( CreateRenderTargetView( _frameBuffer.Get(), nullptr, _frameBufferView.GetAddressOf() ) ) )
        assert( NULL && "Create RenderTargetView Failed!" );

#pragma region depthstencil desc
    D3D11_TEXTURE2D_DESC depthStencilDesc = {};
    depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
    //depthStencilDesc.Width = application.GetWindow().GetWidth();
    //depthStencilDesc.Height = application.GetWindow().GetHeight();
    depthStencilDesc.Width = 800;
    depthStencilDesc.Height = 600;
    depthStencilDesc.ArraySize = 1;
    depthStencilDesc.SampleDesc.Count = 1;
    depthStencilDesc.SampleDesc.Quality = 0;
#pragma endregion
    if ( !( CreateTexture2D( &depthStencilDesc, nullptr, _depthStencil.GetAddressOf() ) ) )
        assert( NULL && "Create depthstencil texture failed!" );

    if ( !( CreateDepthStencilView( _depthStencil.Get(), nullptr, _depthStencilView.GetAddressOf() ) ) )
        assert( NULL && "Create depthstencilview failed!" );
}

void RenderDevice_DX11::Draw( UINT vertexCount, UINT startVertexLocation ) const
{
    _context->Draw( vertexCount, startVertexLocation );
}

void RenderDevice_DX11::DrawIndexed( UINT indexCount, UINT startIndexLocation, INT baseVertexLocation ) const
{
    _context->DrawIndexed( indexCount, startIndexLocation, baseVertexLocation );
}

void RenderDevice_DX11::Present() const
{
    _swapChain->Present( 1, 0 );
}
