export module EnginePch;

export import EngineTypes;

/// <summary>
/// STL
/// </summary>
export import <map>;
export import <memory>;
export import <string>;
export import <format>;

/// <summary>
/// 윈도우
/// </summary>
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
export import <Windows.h>;
export import <assert.h>;

/// <summary>
/// DirectX
/// </summary>
export import <d3d11.h>;
export import <d3dcompiler.h>;
export import <wrl.h>;
export import <DirectXMath.h>;
export import <DirectXTex/DirectXTex.h>;
//export import <DirectXTex/DirectXTex.inl>;

export constexpr auto D3D11_SDK_VERSION_               = D3D11_SDK_VERSION;
export constexpr auto DXGI_USAGE_RENDER_TARGET_OUTPUT_ = DXGI_USAGE_RENDER_TARGET_OUTPUT;
export void CHECK( auto p ) { assert( SUCCEEDED( p ) ); }


export using namespace DirectX;
export using namespace Microsoft::WRL;

#pragma comment( lib, "d3d11.lib" )
#pragma comment( lib, "d3dcompiler.lib" )

#ifdef _DEBUG
#pragma comment( lib, "DirectXTex\\DirectXTex_Debug.lib" )
#else
#pragma comment( lib, "DirectXTex\\DirectXTex.lib" )
#endif

//struct Vertex
//{
//    Vector3 pos;
//    Vector4 color;
//    Vector2 uv; //texture coordinate
//};

export enum class EComponentType
{
    Transform,
    RigidBody,

    Max
};

export enum class ELayerType
{
    Max
};


export enum class ECBType
{
    Transform,
    None,
    End,
};

export enum class ESamplerType
{
    Point,
    Linear,
    Anisotropic,
    PostProcess,
    End,
};

export enum class ERasterizerState
{
    SolidBack,
    SolidFront,
    SolidNone,
    Wireframe,
    End,
};

export enum class EBlendState
{
    AlphaBlend,
    OneOne,
    End,
};

export enum class ERenderingMode
{
    Opaque,
    CutOut,
    Transparent,
    PostProcess,
    End,
};

enum class ETextureType
{
    Albedo,
    Normal,
    Specular,
    Smoothness,
    Metallic,
    Sprite,
    End,
};

export enum class EDepthStencilState
{
    DepthNone,
    LessEqual,
    End,
};

export enum class EShaderStage
{
    VS,		// Vertex Shader
    HS,		// Hull Shader
    DS,		// Domain Shader
    GS,		// Geometry Shader
    PS,		// Pixel Shader
    CS,		// Compute Shader
    All,
    End,
};

export enum class EResourceType
{
    Shader,
    Texture,
};
