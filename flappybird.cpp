#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define wWidth 1280
#define wHeght 720

void wallTouch(sf::RectangleShape & bird, sf::RectangleShape wallU, sf::RectangleShape & wallD, sf::Text & text)
{
    if(bird.getPosition().y >= wallD.getPosition().y && bird.getPosition().x == wallD.getPosition().x)
    {
        text.setString("Game Over");
        bird.setPosition({bird.getPosition().x, bird.getPosition().y + 1000.0f});
    }
    if(bird.getPosition().y <= wallU.getPosition().y + 400.0f && bird.getPosition().x == wallU.getPosition().x)
    {
        text.setString("Game Over");
        bird.setPosition({bird.getPosition().x, bird.getPosition().y + 1000.0f});
    }
}
void Jump(sf::RectangleShape &bird)
{
    bird.setPosition({bird.getPosition().x, bird.getPosition().y - 12.0f});
}
void Gravity(sf::RectangleShape &bird)
{
    bird.setPosition({bird.getPosition().x, bird.getPosition().y + 4.0f});
}
void gameOver(sf::RectangleShape &bird, sf::Text &text)
{
    if (bird.getPosition().y >= 720.f)
    {
        text.setString("Game Over");
        bird.setPosition({bird.getPosition().x, bird.getPosition().y + 1000.0f});
    }
    if (bird.getPosition().y <= 0.f)
    {
        text.setString("Game Over");
        bird.setPosition({bird.getPosition().x, bird.getPosition().y + 1000.0f});
    }
}
void wallMotion(sf::RectangleShape &wallU, sf::RectangleShape &wallD, int randNum)
{
    wallD.setPosition({wallD.getPosition().x - 5.0f, wallD.getPosition().y});
    wallU.setPosition({wallU.getPosition().x - 5.0f, wallU.getPosition().y});
    if (wallD.getPosition().x <= 0.f || wallU.getPosition().x <= 0.f )
    {
        // wallD.setSize({wallD.getSize().x,wallD.getSize().y + randNum});
        // wallU.setSize({wallU.getSize().x,wallU.getSize().y + randNum});
        wallD.setPosition({wallD.getPosition().x + 1200.f, wallD.getPosition().y});
        wallU.setPosition({wallU.getPosition().x + 1200.0f, wallU.getPosition().y});
    }
}
int main()
{
    int randNum,randBool;
    // Create the main window screen
    sf::RenderWindow window(sf::VideoMode({wWidth, wHeght}), "Flappy Bird Implementation in C++");
    window.setFramerateLimit(60);
    sf::Font font("NotesDarling.otf");
    sf::Text text(font);
    text.setCharacterSize(80);
    text.setPosition({600, 350});
    sf::RectangleShape bird({20.f, 20.f});
    bird.setPosition({300.0f, 300.0f});
    bird.setFillColor(sf::Color(255,0,5));
    sf::RectangleShape wallU({50.0f, 400.0f});
    wallU.setPosition({1200.f, 0.f});
    sf::RectangleShape wallD({50.0f, 200.0f});
    wallD.setPosition({1200.f, 520.f});
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        srand(time(0));
        randNum = rand() % 101;
        randBool = rand() % 2;
        Gravity(bird);
        gameOver(bird, text);
        wallMotion(wallU, wallD, randNum);
        wallTouch(bird,wallU,wallD,text);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            Jump(bird);
        }
        window.clear();
        window.draw(wallU);
        window.draw(wallD);
        window.draw(bird);
        window.draw(text);
        window.display();
    }
}
