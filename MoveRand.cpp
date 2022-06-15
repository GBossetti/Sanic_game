#include "MoveRand.h"

MoveRand::MoveRand()
{
    _velocity = { 3,3 };
    _texture.loadFromFile("sanic2.png");
    _sprite.setTexture(_texture);
    
}

void MoveRand::update()
{
    _sprite.move(_velocity);

    if (_sprite.getPosition().x < 0) {
        //_sprite.setPosition(0, _sprite.getPosition().y);
        _velocity.x = -_velocity.x * 1.1;
    }
    if (_sprite.getPosition().y < 0) {
        //_sprite.setPosition(_sprite.getPosition().x, 0);
        _velocity.y = -_velocity.y * 1.1;
    }
    if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 800) {
        //_sprite.setPosition(800 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
        _velocity.x = -_velocity.x * 1.1;
    }
    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600) {
        //_sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
        _velocity.y = -_velocity.y * 1.1;
    }

    //Cambia el perfil segun para donde se dirija el personaje
    if (_velocity.x < 0) {
        _sprite.setScale(-1, 1);
    }
    else if (_velocity.x>0) {
        _sprite.setScale(1, 1);
    }
}

void MoveRand::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

