#pragma once
#include <SFML\Graphics.hpp>
#include "Collisionable.h"
enum class PersonajeState {
	Idle = 0,   //Cuando el personaje está quieto
	Move        //El estado es solamente Moverse
};

class Personaje: public sf::Drawable, public Collisionable
{
private: 
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;
	bool _inmunidad;
	int _aceleracion;

	sf::Vector2f _movePosition = { 0,0 }; //Para que el _state sepa a dónde se está moviendo

	PersonajeState _state = PersonajeState::Idle;
public: 
	Personaje();
	void cmd(); //verifica lo que sucede con el teclado, para cambiar el estado del personaje
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
	void setInmunidad(bool inmunidad);
	bool getInmunidad();
	void setAceleracion(int aceleracion);
	int getAceleracion();

};

