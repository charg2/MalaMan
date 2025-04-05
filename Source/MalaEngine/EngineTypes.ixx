module;

import "DirectXMath.h";

export module EngineTypes;

export
{

/// <summary>
/// Default Types
/// </summary>
using i8  = __int8;
using i16 = __int16;
using i32 = __int32;
using i64 = __int64;
using u8  = unsigned __int8;
using u16 = unsigned __int16;
using u32 = unsigned __int32;
using u64 = unsigned __int64;
using f32 = float;
using f64 = double;

using Vec2  = DirectX::XMFLOAT2;
using Vec3  = DirectX::XMFLOAT3;
using Vec4  = DirectX::XMFLOAT4;
using Color = DirectX::XMFLOAT4;

struct Vertex
{
	Vec3 position;
	Color color;
};

};
