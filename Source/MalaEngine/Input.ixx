export module Input;

import EnginePch;

export
{

enum class EKeyState
{
	Down,
	Pressed,
	Up,
	None,
};

enum class EKeyCode
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	End,
};

class Input
{
public:
	struct Key
	{
		EKeyCode  keyCode;
		EKeyState state;
		bool      pressed;
	};

	static void Initialize();
	static void Update();

	static bool GetKeyDown( EKeyCode code ) { return _keys[ (UINT)code ].state == EKeyState::Down; }
	static bool GetKeyUp( EKeyCode code ) { return _keys[ (UINT)code ].state == EKeyState::Up; }
	static bool GetKey( EKeyCode code ) { return _keys[ (UINT)code ].state == EKeyState::Pressed; }

public:
	inline static std::vector< Key > _keys;
};

};

int ASCII[ (UINT)EKeyCode::End ] =
{
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M',
};


void Input::Initialize()
{
	_keys.reserve( (UINT)EKeyCode::End );

	for ( size_t i = 0; i < (UINT)EKeyCode::End; i++ )
	{
		auto& key = _keys.emplace_back();
		key.pressed = false;
		key.state   = EKeyState::None;
		key.keyCode = (EKeyCode)i;
	}
}




void Input::Update()
{
	for ( size_t i = 0; i < _keys.size(); i++ )
	{
		//Ű�� ���ȴ�
		if ( ::GetAsyncKeyState( ASCII[ i ] ) & 0x8000 )
		{
			if ( _keys[ i ].pressed )
				_keys[ i ].state = EKeyState::Pressed;
			else
				_keys[ i ].state = EKeyState::Down;

			_keys[ i ].pressed = true;
		}
		else // Ű�� �ȴ��ȴ�.
		{
			if ( _keys[ i ].pressed )
				_keys[ i ].state = EKeyState::Up;
			else
				_keys[ i ].state = EKeyState::None;

			_keys[ i ].pressed = false;
		}
	}
}
