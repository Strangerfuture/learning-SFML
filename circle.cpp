#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void borderCheck(sf::CircleShape & circle, float & radius, float & Vx, float & Vy)
{
    if (circle.getPosition().x >= (800.f - 2 * radius))
    {
        Vx = -6.f;
    }
    if (circle.getPosition().x <= 0.f)
    {
        Vx = 6.f;
    }

    if (circle.getPosition().y >= (600.f - 2 * radius))
    {
        Vy = -7.f;
    }
    if (circle.getPosition().y <= 0.f)
    {
        Vy = 7.f;
    }

    circle.setPosition({circle.getPosition().x + Vx, circle.getPosition().y + Vy});
}
int main()
{
    float Vx = 6.f;
    float Vy = 4.f;
    float radius = 50.f;
    float pX = 350.f, pY = 500.f;
    float rand = 0.34;
    // Create the main window screen
    sf::RenderWindow window(sf::VideoMode({800, 600}), "First SFML Program");
    window.setFramerateLimit(60);
    // Create a circle
    sf::CircleShape circle(radius);
    sf::CircleShape triangle(80.f, 3);
    triangle.setPosition({pX + 100, pY + 200});
    triangle.setFillColor(sf::Color(0, 255, 255));
    circle.setPosition({pX, pY});
    circle.setFillColor(sf::Color(25, 225, 195));
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        // Triagle Rotation
        borderCheck(circle, radius, Vx, Vy);
        window.clear();
        window.draw(circle);
        window.display();
    }
}
