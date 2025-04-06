import EnginePch;
import Time;


void Time::Initailize()
{
    // Cpu 고유 진동수
    QueryPerformanceFrequency( &CpuFrequency );

    // 프로그램이 시작 했을 때 현재 진동수
    QueryPerformanceCounter( &PrevFrequency );
}

void Time::Update()
{
    QueryPerformanceCounter( &CurrentFrequency );

    float differenceFrequency
        = static_cast< f32 >( CurrentFrequency.QuadPart - PrevFrequency.QuadPart );
    DeltaTimeValue = differenceFrequency / static_cast<float>( CpuFrequency.QuadPart );
    PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
}

void Time::Render( HDC hdc )
{
    static float time = 0.0f;

    time += DeltaTimeValue;
    float fps = 1.0f / DeltaTimeValue;

    wchar_t str[ 50 ] = L"";
    swprintf_s( str, 50, L"Time : %d", (int)fps );
    // int len = wcsnlen_s( str, 50 );

    // ::TextOut( hdc, 0, 0, str, len );
}
