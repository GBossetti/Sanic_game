#include <stdlib.h>
#include "CarpinchoCopado.h"

CarpinchoCopado::CarpinchoCopado() 
{
	_texture.loadFromFile("carpinchocopado.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void CarpinchoCopado::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void CarpinchoCopado::respawn() 
{
	_sprite.setPosition((std::rand() % 250) + 150 + _sprite.getLocalBounds().width, std::rand() % 500 + _sprite.getLocalBounds().height);
}

sf::FloatRect CarpinchoCopado::getBounds() const
{
	return _sprite.getGlobalBounds();
}

