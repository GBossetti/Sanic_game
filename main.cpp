#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "MoveRand.h"
#include "Carpincho.h"
#include "CarpinchoCopado.h"
#include "InputManager.h"

int main()
{
    std::srand((unsigned)std::time(0)); //Planto la semilla para poder usar random con ctime

    InputManager inputManager;

    //Inicialización de la ventana:
    sf::RenderWindow window(sf::VideoMode(800, 600), "Carpincho's Attack"); //Píxeles tamaño de ventana + nombre
    window.setFramerateLimit(60); //Forzamos a que corra a 60 frames per second

    //Fuente
    sf::Font font;
    sf::Text text;
    font.loadFromFile("8bit.ttf");
    text.setFont(font);

    Personaje repartidor;
    int time_inmunidad = 0;
    MoveRand sanic;
        
    Carpincho carpincho;
    carpincho.respawn();

    CarpinchoCopado camarada;
    camarada.respawn();
    int timer = 60 * 10; //Tiempo que tarda en volver a aparecer

    //Points
    int points = 0;

    //Fondo
    sf::Sprite image;
    sf::Texture texture_fondo;
    texture_fondo.loadFromFile("ruta.png");
    image.setTexture(texture_fondo);


   //GameLoop
    while (window.isOpen())
    {
        //ReadInput
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        inputManager.reset();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            inputManager.setButtonPress(InputManager::Buttons::Up);
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            inputManager.setButtonPress(InputManager::Buttons::Left);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            inputManager.setButtonPress(InputManager::Buttons::Down);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            inputManager.setButtonPress(InputManager::Buttons::Right);
        }

        //CMD - Joy
        //Cuando se ejecuta el personaje, lo que se ejecuta es el comando -cmd-
        


        //Update 
        //image.move(0, 4); //Mueve para abajo - Necesito un segundo fondo que inicialmente empezará en el -600 //Otra forma sería el método Paralax

        float velocidad = repartidor.getAceleracion();
        image.move(0, velocidad);
        if (image.getPosition().y > 0) {
            image.setPosition(image.getPosition().x, -600);
        }



        if (timer > 0) {
            timer--;
        }
        
        repartidor.update();
        sanic.update();


        if (repartidor.getInmunidad()) {
            time_inmunidad++;
        }

        if (repartidor.getInmunidad() && time_inmunidad == 60 * 5) {
            repartidor.setInmunidad(false);
        }

        if (repartidor.isCollision(carpincho)) {
            carpincho.respawn();
            if (!repartidor.getInmunidad()) {
                points -= 50;
            }
        }

        /*
        if (repartidor.isCollision(sanic)) {
            sanic.respawn();
            points -= 50;
        }
        */

        if (timer == 0 && repartidor.isCollision(camarada)) {
            // Repartidor.GetInmunidad() - Agregar condicion de que si choco obst�culos no pase nada.
            repartidor.setInmunidad(true);
            time_inmunidad = 0;
            timer = 60 * 5;
            camarada.respawn();
            points += 100;
        }

        
        

        text.setPosition(602, 0);
        text.setString("PUNTOS: " + std::to_string(points));
        
        window.clear();

        //Draw
        window.draw(image);
        window.draw(repartidor);
        window.draw(carpincho);
        //window.draw(sanic);
        window.draw(text);

        if (timer == 0) {
            window.draw(camarada);
        }

        //Display - Fli
        window.display();
    }
       
    //Liberación del juego
    return 0;
}