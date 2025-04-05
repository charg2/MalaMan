export module Time;

import EnginePch;

export
{

class Time
{
public:
    static void Initailize();
    static void Update();
    static void Render( HDC hdc );

    static float DeltaTime() { return DeltaTimeValue; }

private:
    inline static LARGE_INTEGER CpuFrequency{};
    inline static LARGE_INTEGER PrevFrequency{};
    inline static LARGE_INTEGER CurrentFrequency{};

    inline static float DeltaTimeValue{};
};

}
