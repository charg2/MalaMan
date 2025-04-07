export module Shader;


import EnginePch;
import Entity;

export
{

class Shader// : public Resource
{
public:
    Shader();
    virtual ~Shader();

    //HRESULT Save( const std::wstring& path ) override;
    //HRESULT Load( const std::wstring& path ) override;

    bool Create( EShaderStage stage, const std::wstring& fileName );
    bool CreateVertexShader( const std::wstring& fileName );
    bool CreatePixelShader( const std::wstring& fileName );

    void Bind();

    ComPtr< ID3DBlob > GetVSBlob() const { return mVSBlob; }
    ComPtr< ID3DBlob > GetHSBlob() const { return mHSBlob; }
    ComPtr< ID3DBlob > GetDSBlob() const { return mDSBlob; }
    ComPtr< ID3DBlob > GetGSBlob() const { return mGSBlob; }
    ComPtr< ID3DBlob > GetPSBlob() const { return mPSBlob; }

    ComPtr< ID3D11VertexShader >   GetVS() const { return mVS; }
    ComPtr< ID3D11HullShader >     GetHS() const { return mHS; }
    ComPtr< ID3D11DomainShader >   GetDS() const { return mDS; }
    ComPtr< ID3D11GeometryShader > GetGS() const { return mGS; }
    ComPtr< ID3D11PixelShader >    GetPS() const { return mPS; }

    void SetRasterizerState( const ERasterizerState state ) { mRasterizerState = state; }
    void SetBlendState( const EBlendState state ) { mBlendState = state; }
    void SetDepthStencilState( const EDepthStencilState state ) { mDepthStencilState = state; }

private:
    inline static bool bWireframe{};

    ComPtr< ID3DBlob > mVSBlob;
    ComPtr< ID3DBlob > mHSBlob;
    ComPtr< ID3DBlob > mDSBlob;
    ComPtr< ID3DBlob > mGSBlob;
    ComPtr< ID3DBlob > mPSBlob;

    ComPtr< ID3D11VertexShader >   mVS;
    ComPtr< ID3D11HullShader >     mHS;
    ComPtr< ID3D11DomainShader >   mDS;
    ComPtr< ID3D11GeometryShader > mGS;
    ComPtr< ID3D11PixelShader >    mPS;

    ERasterizerState   mRasterizerState;
    EBlendState        mBlendState;
    EDepthStencilState mDepthStencilState;
};

}
