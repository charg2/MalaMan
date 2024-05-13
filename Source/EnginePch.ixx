export module EnginePch;



/// <summary>
/// STL
/// </summary>
export import <memory>;

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

export using namespace DirectX;
export using namespace Microsoft::WRL;

#pragma comment( lib, "d3d11.lib" )
#pragma comment( lib, "d3dcompiler.lib" )

#ifdef _DEBUG
#pragma comment( lib, "DirectXTex\\DirectXTex_Debug.lib" )
#else
#pragma comment( lib, "DirectXTex\\DirectXTex.lib" )
#endif