#include <iostream>
#include "InputManager.h"

void InputManager::reset() //reinicio el valor de los botones
{
	std::fill(_buttons, _buttons + 6, false); //Pone en 0 el array _buttons[6]
}
void InputManager::setButtonPress(Buttons button) //se apreta un botón, lo recibe un boton como parámetro, lo setea en true (marca los botones presionados)
{
	_buttons[(int)button] = true;
}

bool InputManager::isButtonPress(Buttons button) //Chequeo si están presionados
{
	return _buttons[(int)button];
}