#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    // CONSTANTS
    static const float THICKNESS = 1.0f;
    static const float RADIUS = 150.0f;

    // window
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Fourier Series");

    // circle
    sf::CircleShape circle(RADIUS);
    // set origin
    // move by aribitrary amount
    circle.setOrigin(sf::Vector2f(-THICKNESS - 100, -THICKNESS - 100));
    // set fill
    circle.setFillColor(sf::Color::Transparent);
    // set outline
    circle.setOutlineThickness(THICKNESS);
    circle.setOutlineColor(sf::Color(255, 255, 255));

    // get what origin should be
    // must be from center of circleand add on the x and y
    static const float CENTER_CIRCLE_OFFSET = -THICKNESS - 100 - RADIUS;

    // keep track of current angle (time)
    float t = 0.0f;

    // loop
    while (window.isOpen())
    {
        // event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            // closing
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear window
        window.clear();

        // draw circle
        window.draw(circle);

        // get x and y position of dot based on radius and time
        float x = RADIUS * cos(t);
        float y = RADIUS * sin(t);

        // dot
        sf::CircleShape dot(RADIUS / 25);
        // set origin
        // must account for size of dot
        dot.setOrigin(sf::Vector2f(CENTER_CIRCLE_OFFSET + RADIUS/25 - x, CENTER_CIRCLE_OFFSET + RADIUS/25 - y));
        // set fill
        dot.setFillColor(sf::Color(255, 255, 255));

        // draw the dot
        window.draw(dot);

        // update time
        t += 0.001f;

        // display window
        window.display();
    }

    return 0;
}