#pragma once
#include <SFML\Graphics.hpp>

class MoveRand : public sf::Drawable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;
public:
	MoveRand();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

