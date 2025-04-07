export module Renderer;

import EnginePch;


class Camera;
class GameObject;
class ConstantBuffer;
class RenderTarget;

export namespace Renderer
{
    inline extern Camera*         mainCamera{};
    inline extern GameObject*     selectedObject{};
    inline extern ConstantBuffer* constantBuffers[ static_cast< u32 >( ECBType::End ) ]{};

    inline extern ComPtr< ID3D11SamplerState >      samplerStates[ static_cast< u32 >( ESamplerType::End ) ]{};
    inline extern ComPtr< ID3D11RasterizerState >   rasterizerStates[ static_cast< u32 >( ERasterizerState::End ) ]{};
    inline extern ComPtr< ID3D11BlendState >        blendStates[ static_cast< u32 >( EBlendState::End ) ]{};
    inline extern ComPtr< ID3D11DepthStencilState > depthStencilStates[ static_cast< u32 >( EDepthStencilState::End ) ]{};

    inline extern RenderTarget* FrameBuffer{};

    void Initialize();
    void Release();
}
