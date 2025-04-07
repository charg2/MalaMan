import EnginePch;
import Scene;
import Layer;
import Shader;
import Renderer;
import RenderDevice_DX11;


Shader::Shader()
/*: Resource( EResourceType::Shader )
,*/
: mRasterizerState( ERasterizerState::SolidNone )
, mBlendState( EBlendState::AlphaBlend )
, mDepthStencilState( EDepthStencilState::LessEqual )
{
}

Shader::~Shader()
{
}

//HRESULT Shader::Save( const std::wstring& path )
//{
//    return E_NOTIMPL;
//}

//HRESULT Shader::Load( const std::wstring& path )
//{
//    size_t fineNameBeginOffset = path.rfind( L"\\" ) + 1;
//    size_t fineNameEndOffset = path.length() - fineNameBeginOffset;
//    const std::wstring fileName( path.substr( fineNameBeginOffset, fineNameEndOffset ) );
//
//    if ( !Create( EShaderStage::VS, fileName ) )
//        return S_FALSE;
//    if ( !Create( EShaderStage::PS, fileName ) )
//        return S_FALSE;
//
//    return S_OK;
//}

bool Shader::Create( const EShaderStage stage, const std::wstring& fileName )
{
    if ( stage == EShaderStage::VS )
        CreateVertexShader( fileName );
    if ( stage == EShaderStage::PS )
        CreatePixelShader( fileName );

    return true;
}

bool Shader::CreateVertexShader( const std::wstring& fileName )
{
    if ( !GetDevice()->CreateVertexShader( fileName, mVSBlob.GetAddressOf(), mVS.GetAddressOf() ) )
        return false;

    return true;
}

bool Shader::CreatePixelShader( const std::wstring& fileName )
{
    if ( !GetDevice()->CreatePixelShader( fileName, mPSBlob.GetAddressOf(), mPS.GetAddressOf() ) )
        return false;

    return true;
}

void Shader::Bind()
{
    if ( bWireframe )
    {
        //Shader* wireframeShader = Resources::Find<Shader>( L"WireframeShader" );
        //ComPtr< ID3D11VertexShader >    wireframeShaderVS = wireframeShader->GetVS();
        //ComPtr< ID3D11PixelShader >     wireframeShaderPS = wireframeShader->GetPS();
        //ComPtr< ID3D11RasterizerState > wireframeRasterizerState
        //    = Renderer::rasterizerStates[ static_cast< u32 >( ERasterizerState::Wireframe ) ];

        //Graphics::GetDevice()->BindVS( wireframeShaderVS.Get() );
        //Graphics::GetDevice()->BindPS( wireframeShaderPS.Get() );
        //Graphics::GetDevice()->BindRasterizerState( wireframeRasterizerState.Get() );
        //Graphics::GetDevice()->BindBlendState( Renderer::blendStates[ static_cast< u32 >( mBlendState ) ].Get(), nullptr, 0xffffff );
        //Graphics::GetDevice()->BindDepthStencilState( Renderer::depthStencilStates[ static_cast< u32 >( mDepthStencilState ) ].Get(), 0 );

        return;
    }

    if ( mVS )
        GetDevice()->BindVS( mVS.Get() );
    if ( mPS )
        GetDevice()->BindPS( mPS.Get() );

    //Graphics::GetDevice()->BindRasterizerState( Renderer::rasterizerStates[ static_cast< u32 >( mRasterizerState ) ].Get() );
    //Graphics::GetDevice()->BindBlendState( Renderer::blendStates[ static_cast< u32 >( mBlendState ) ].Get(), nullptr, 0xffffff );
    //Graphics::GetDevice()->BindDepthStencilState( Renderer::depthStencilStates[ static_cast< u32 >( mDepthStencilState ) ].Get(), 0 );
}
