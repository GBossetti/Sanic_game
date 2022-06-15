#include <iostream>
#include "InputManager.h"

void InputManager::reset() //reinicio el valor de los botones
{
	std::fill(_buttons, _buttons + 6, false); //Pone en 0 el array _buttons[6]
}
void InputManager::setButtonPress(Buttons button) //se apreta un bot�n, lo recibe un boton como par�metro, lo setea en true (marca los botones presionados)
{
	_buttons[(int)button] = true;
}

bool InputManager::isButtonPress(Buttons button) //Chequeo si est�n presionados
{
	return _buttons[(int)button];
}