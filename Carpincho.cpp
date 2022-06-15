#include <stdlib.h>
#include "Carpincho.h"

Carpincho::Carpincho()
{
	_textura.loadFromFile("carpincho.png"); // asigno imagen a textura
	_sprite.setTexture(_textura); // asigno textura a personaje
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void Carpincho::update()
{

}

void Carpincho::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void Carpincho::respawn()
{
	//Acá se tiene que llamar al objeto para modificar la posicion, no a la propiedad. La clase tiene que ser transformable.
	_sprite.setPosition((std::rand() % 250) + 150 + _sprite.getLocalBounds().width, std::rand() % 500 + _sprite.getLocalBounds().height);
}

sf::FloatRect Carpincho::getBounds() const
{
	return _sprite.getGlobalBounds();
}