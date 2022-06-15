#pragma once
class InputManager //También puede ser Controller el nombre
{
	//estado de cada una de las cosas
	bool _buttons[6]; //cant botones
public:
	enum class Buttons {
		Up=0, 
		Down,
		Left,
		Right,

		Button1,
		Button2
	};

	void reset();

	void setButtonPress(Buttons button);
	bool isButtonPress(Buttons button);
	
};

