export module Math;


import EnginePch;

#define XM_CONSTEXPR

using namespace DirectX;
//using namespace DirectX::PackedVector;


export
{

// 2D vector
struct Vector2 : public XMFLOAT2
{
    Vector2() noexcept : XMFLOAT2( 0.f, 0.f ) {}
    constexpr explicit Vector2( float ix ) noexcept : XMFLOAT2( ix, ix ) {}
    constexpr Vector2( float ix, float iy ) noexcept : XMFLOAT2( ix, iy ) {}
    //explicit Vector2( _In_reads_( 2 ) const f32* pArray ) noexcept : XMFLOAT2( pArray ) {}
    Vector2( FXMVECTOR V ) noexcept { XMStoreFloat2( this, V ); }
    Vector2( const XMFLOAT2& V ) noexcept { this->x = V.x; this->y = V.y; }
    explicit Vector2( const XMVECTORF32& F ) noexcept { this->x = F.f[ 0 ]; this->y = F.f[ 1 ]; }

    Vector2( const Vector2& ) = default;
    Vector2& operator=( const Vector2& ) = default;

    Vector2( Vector2&& ) = default;
    Vector2& operator=( Vector2&& ) = default;

    operator XMVECTOR() const noexcept { return XMLoadFloat2( this ); }

    // Comparison operators
    bool operator == ( const Vector2& V ) const noexcept;
    bool operator != ( const Vector2& V ) const noexcept;

    // Assignment operators
    Vector2& operator= ( const XMVECTORF32& F ) noexcept { x = F.f[ 0 ]; y = F.f[ 1 ]; return *this; }
    Vector2& operator+= ( const Vector2& V ) noexcept;
    Vector2& operator-= ( const Vector2& V ) noexcept;
    Vector2& operator*= ( const Vector2& V ) noexcept;
    Vector2& operator*= ( float S ) noexcept;
    Vector2& operator/= ( float S ) noexcept;

    // Unary operators
    Vector2 operator+ () const noexcept { return *this; }
    Vector2 operator- () const noexcept { return Vector2( -x, -y ); }

    // Vector operations
    bool InBounds( const Vector2& Bounds ) const noexcept;

    float Length() const noexcept;
    float LengthSquared() const noexcept;

    float Dot( const Vector2& V ) const noexcept;
    void Cross( const Vector2& V, Vector2& result ) const noexcept;
    Vector2 Cross( const Vector2& V ) const noexcept;

    void Normalize() noexcept;
    void Normalize( Vector2& result ) const noexcept;

    void Clamp( const Vector2& vmin, const Vector2& vmax ) noexcept;
    void Clamp( const Vector2& vmin, const Vector2& vmax, Vector2& result ) const noexcept;

    // Static functions
    static float Distance( const Vector2& v1, const Vector2& v2 ) noexcept;
    static float DistanceSquared( const Vector2& v1, const Vector2& v2 ) noexcept;

    static void Min( const Vector2& v1, const Vector2& v2, Vector2& result ) noexcept;
    static Vector2 Min( const Vector2& v1, const Vector2& v2 ) noexcept;

    static void Max( const Vector2& v1, const Vector2& v2, Vector2& result ) noexcept;
    static Vector2 Max( const Vector2& v1, const Vector2& v2 ) noexcept;

    static void Lerp( const Vector2& v1, const Vector2& v2, float t, Vector2& result ) noexcept;
    static Vector2 Lerp( const Vector2& v1, const Vector2& v2, float t ) noexcept;

    static void SmoothStep( const Vector2& v1, const Vector2& v2, float t, Vector2& result ) noexcept;
    static Vector2 SmoothStep( const Vector2& v1, const Vector2& v2, float t ) noexcept;

    static void Barycentric( const Vector2& v1, const Vector2& v2, const Vector2& v3, float f, float g, Vector2& result ) noexcept;
    static Vector2 Barycentric( const Vector2& v1, const Vector2& v2, const Vector2& v3, float f, float g ) noexcept;

    static void CatmullRom( const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& v4, float t, Vector2& result ) noexcept;
    static Vector2 CatmullRom( const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& v4, float t ) noexcept;

    static void Hermite( const Vector2& v1, const Vector2& t1, const Vector2& v2, const Vector2& t2, float t, Vector2& result ) noexcept;
    static Vector2 Hermite( const Vector2& v1, const Vector2& t1, const Vector2& v2, const Vector2& t2, float t ) noexcept;

    static void Reflect( const Vector2& ivec, const Vector2& nvec, Vector2& result ) noexcept;
    static Vector2 Reflect( const Vector2& ivec, const Vector2& nvec ) noexcept;

    static void Refract( const Vector2& ivec, const Vector2& nvec, float refractionIndex, Vector2& result ) noexcept;
    static Vector2 Refract( const Vector2& ivec, const Vector2& nvec, float refractionIndex ) noexcept;

    //static void Transform( const Vector2& v, const Quaternion& quat, Vector2& result ) noexcept;
    //static Vector2 Transform( const Vector2& v, const Quaternion& quat ) noexcept;

    //static void Transform( const Vector2& v, const Matrix& m, Vector2& result ) noexcept;
    //static Vector2 Transform( const Vector2& v, const Matrix& m ) noexcept;
    //static void Transform( _In_reads_( count ) const Vector2* varray, size_t count, const Matrix& m, _Out_writes_( count ) Vector2* resultArray ) noexcept;

    //static void Transform( const Vector2& v, const Matrix& m, Vector4& result ) noexcept;
    //static void Transform( _In_reads_( count ) const Vector2* varray, size_t count, const Matrix& m, _Out_writes_( count ) Vector4* resultArray ) noexcept;

    //static void TransformNormal( const Vector2& v, const Matrix& m, Vector2& result ) noexcept;
    //static Vector2 TransformNormal( const Vector2& v, const Matrix& m ) noexcept;
    //static void TransformNormal( _In_reads_( count ) const Vector2* varray, size_t count, const Matrix& m, _Out_writes_( count ) Vector2* resultArray ) noexcept;

    // Constants
    static const Vector2 Zero;
    static const Vector2 One;
    static const Vector2 UnitX;
    static const Vector2 UnitY;
};

const Vector2 Vector2::Zero { 0.f, 0.f };
const Vector2 Vector2::One  { 1.f, 1.f };
const Vector2 Vector2::UnitX{ 1.f, 0.f };
const Vector2 Vector2::UnitY{ 0.f, 1.f };

// Binary operators
Vector2 operator+ ( const Vector2& V1, const Vector2& V2 ) noexcept;
Vector2 operator- ( const Vector2& V1, const Vector2& V2 ) noexcept;
Vector2 operator* ( const Vector2& V1, const Vector2& V2 ) noexcept;
Vector2 operator* ( const Vector2& V, float S ) noexcept;
Vector2 operator/ ( const Vector2& V1, const Vector2& V2 ) noexcept;
Vector2 operator/ ( const Vector2& V, float S ) noexcept;
Vector2 operator* ( float S, const Vector2& V ) noexcept;


//------------------------------------------------------------------------------
// 3D vector
struct Vector3 : public XMFLOAT3
{
    Vector3() noexcept : XMFLOAT3( 0.f, 0.f, 0.f ) {}
    constexpr explicit Vector3( float ix ) noexcept : XMFLOAT3( ix, ix, ix ) {}
    constexpr Vector3( float ix, float iy, float iz ) noexcept : XMFLOAT3( ix, iy, iz ) {}
    //explicit Vector3( _In_reads_( 3 ) const float* pArray ) noexcept : XMFLOAT3( pArray ) {}
    Vector3( FXMVECTOR V ) noexcept { XMStoreFloat3( this, V ); }
    Vector3( const XMFLOAT3& V ) noexcept { this->x = V.x; this->y = V.y; this->z = V.z; }
    explicit Vector3( const XMVECTORF32& F ) noexcept { this->x = F.f[ 0 ]; this->y = F.f[ 1 ]; this->z = F.f[ 2 ]; }

    Vector3( const Vector3& ) = default;
    Vector3& operator=( const Vector3& ) = default;

    Vector3( Vector3&& ) = default;
    Vector3& operator=( Vector3&& ) = default;

    operator XMVECTOR() const noexcept { return XMLoadFloat3( this ); }

    // Comparison operators
    bool operator == ( const Vector3& V ) const noexcept;
    bool operator != ( const Vector3& V ) const noexcept;

    // Assignment operators
    Vector3& operator= ( const XMVECTORF32& F ) noexcept { x = F.f[ 0 ]; y = F.f[ 1 ]; z = F.f[ 2 ]; return *this; }
    Vector3& operator+= ( const Vector3& V ) noexcept;
    Vector3& operator-= ( const Vector3& V ) noexcept;
    Vector3& operator*= ( const Vector3& V ) noexcept;
    Vector3& operator*= ( float S ) noexcept;
    Vector3& operator/= ( float S ) noexcept;

    // Unary operators
    Vector3 operator+ () const noexcept { return *this; }
    Vector3 operator- () const noexcept;

    // Vector operations
    bool InBounds( const Vector3& Bounds ) const noexcept;

    float Length() const noexcept;
    float LengthSquared() const noexcept;

    float Dot( const Vector3& V ) const noexcept;
    void Cross( const Vector3& V, Vector3& result ) const noexcept;
    Vector3 Cross( const Vector3& V ) const noexcept;

    void Normalize() noexcept;
    void Normalize( Vector3& result ) const noexcept;

    void Clamp( const Vector3& vmin, const Vector3& vmax ) noexcept;
    void Clamp( const Vector3& vmin, const Vector3& vmax, Vector3& result ) const noexcept;

    // Static functions
    static float Distance( const Vector3& v1, const Vector3& v2 ) noexcept;
    static float DistanceSquared( const Vector3& v1, const Vector3& v2 ) noexcept;

    static void Min( const Vector3& v1, const Vector3& v2, Vector3& result ) noexcept;
    static Vector3 Min( const Vector3& v1, const Vector3& v2 ) noexcept;

    static void Max( const Vector3& v1, const Vector3& v2, Vector3& result ) noexcept;
    static Vector3 Max( const Vector3& v1, const Vector3& v2 ) noexcept;

    static void Lerp( const Vector3& v1, const Vector3& v2, float t, Vector3& result ) noexcept;
    static Vector3 Lerp( const Vector3& v1, const Vector3& v2, float t ) noexcept;

    static void SmoothStep( const Vector3& v1, const Vector3& v2, float t, Vector3& result ) noexcept;
    static Vector3 SmoothStep( const Vector3& v1, const Vector3& v2, float t ) noexcept;

    static void Barycentric( const Vector3& v1, const Vector3& v2, const Vector3& v3, float f, float g, Vector3& result ) noexcept;
    static Vector3 Barycentric( const Vector3& v1, const Vector3& v2, const Vector3& v3, float f, float g ) noexcept;

    static void CatmullRom( const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float t, Vector3& result ) noexcept;
    static Vector3 CatmullRom( const Vector3& v1, const Vector3& v2, const Vector3& v3, const Vector3& v4, float t ) noexcept;

    static void Hermite( const Vector3& v1, const Vector3& t1, const Vector3& v2, const Vector3& t2, float t, Vector3& result ) noexcept;
    static Vector3 Hermite( const Vector3& v1, const Vector3& t1, const Vector3& v2, const Vector3& t2, float t ) noexcept;

    static void Reflect( const Vector3& ivec, const Vector3& nvec, Vector3& result ) noexcept;
    static Vector3 Reflect( const Vector3& ivec, const Vector3& nvec ) noexcept;

    static void Refract( const Vector3& ivec, const Vector3& nvec, float refractionIndex, Vector3& result ) noexcept;
    static Vector3 Refract( const Vector3& ivec, const Vector3& nvec, float refractionIndex ) noexcept;

    //static void Transform( const Vector3& v, const Quaternion& quat, Vector3& result ) noexcept;
    //static Vector3 Transform( const Vector3& v, const Quaternion& quat ) noexcept;

    //static void Transform( const Vector3& v, const Matrix& m, Vector3& result ) noexcept;
    //static Vector3 Transform( const Vector3& v, const Matrix& m ) noexcept;
    //static void Transform( _In_reads_( count ) const Vector3* varray, size_t count, const Matrix& m, _Out_writes_( count ) Vector3* resultArray ) noexcept;

    //static void Transform( const Vector3& v, const Matrix& m, Vector4& result ) noexcept;
    //static void Transform( _In_reads_( count ) const Vector3* varray, size_t count, const Matrix& m, _Out_writes_( count ) Vector4* resultArray ) noexcept;

    //static void TransformNormal( const Vector3& v, const Matrix& m, Vector3& result ) noexcept;
    //static Vector3 TransformNormal( const Vector3& v, const Matrix& m ) noexcept;
    //static void TransformNormal( _In_reads_( count ) const Vector3* varray, size_t count, const Matrix& m, _Out_writes_( count ) Vector3* resultArray ) noexcept;

    // Constants
    static const Vector3 Zero;
    static const Vector3 One;
    static const Vector3 UnitX;
    static const Vector3 UnitY;
    static const Vector3 UnitZ;
    static const Vector3 Up;
    static const Vector3 Down;
    static const Vector3 Right;
    static const Vector3 Left;
    static const Vector3 Forward;
    static const Vector3 Backward;
};

const Vector3 Vector3::Zero = { 0.f, 0.f, 0.f };
const Vector3 Vector3::One = { 1.f, 1.f, 1.f };
const Vector3 Vector3::UnitX = { 1.f, 0.f, 0.f };
const Vector3 Vector3::UnitY = { 0.f, 1.f, 0.f };
const Vector3 Vector3::UnitZ = { 0.f, 0.f, 1.f };
const Vector3 Vector3::Up = { 0.f, 1.f, 0.f };
const Vector3 Vector3::Down = { 0.f, -1.f, 0.f };
const Vector3 Vector3::Right = { 1.f, 0.f, 0.f };
const Vector3 Vector3::Left = { -1.f, 0.f, 0.f };
const Vector3 Vector3::Forward = { 0.f, 0.f, 1.f };
const Vector3 Vector3::Backward = { 0.f, 0.f, -1.f };

// Binary operators
Vector3 operator+ ( const Vector3& V1, const Vector3& V2 ) noexcept;
Vector3 operator- ( const Vector3& V1, const Vector3& V2 ) noexcept;
Vector3 operator* ( const Vector3& V1, const Vector3& V2 ) noexcept;
Vector3 operator* ( const Vector3& V, float S ) noexcept;
Vector3 operator/ ( const Vector3& V1, const Vector3& V2 ) noexcept;
Vector3 operator/ ( const Vector3& V, float S ) noexcept;
Vector3 operator* ( float S, const Vector3& V ) noexcept;


}
