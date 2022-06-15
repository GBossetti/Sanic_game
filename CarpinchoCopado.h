#pragma once
#include <SFML/Graphics.hpp>
#include "Collisionable.h"

class CarpinchoCopado : public sf::Drawable, public Collisionable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
public:
	CarpinchoCopado();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void respawn();
	sf::FloatRect getBounds() const override;
};

