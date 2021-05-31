#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // start positions of the three disks
    sf::RectangleShape disks1(sf::Vector2f(25, 15));
    disks1.setPosition(sf::Vector2f(150-12.5, 355));
    sf::RectangleShape disks2(sf::Vector2f(45, 15));
    disks2.setPosition(sf::Vector2f(150-22.5, 370));
    sf::RectangleShape disks3(sf::Vector2f(65, 15));
    disks3.setPosition(sf::Vector2f(150-32.5, 385));

    // window size and name
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Tower of Hanoi");

    sf::Font font;
    if (!font.loadFromFile("BELL.ttf"))
    {
        cout << "Error" << endl;
    }

    sf::Text text;  // title
    text.setFont(font);
    text.setString("Press arrow right for next step\nPress R to reset\nMinimum number of moves: 7");
    text.setCharacterSize(22);

    // board consists of 4 rectangle
    sf::RectangleShape rectangle(sf::Vector2f(800, 5));  // horizontal rectangle
    sf::RectangleShape rectangle1(sf::Vector2f(5, 300)); // first column
    sf::RectangleShape rectangle2(sf::Vector2f(5, 300)); // second column
    sf::RectangleShape rectangle3(sf::Vector2f(5, 300)); // third column

    // board rectangles positions
    rectangle.setPosition(sf::Vector2f(50, 400));
    rectangle1.setPosition(sf::Vector2f(150, 100));
    rectangle2.setPosition(sf::Vector2f(450, 100));
    rectangle3.setPosition(sf::Vector2f(750, 100));

    // disks colors
    disks1.setFillColor(sf::Color(133, 193, 233 , 255));
    disks2.setFillColor(sf::Color(229, 147, 147, 255));
    disks3.setFillColor(sf::Color(187, 143, 206, 255));

    int i = 0;  // step number
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right){
                    if (i < 7)
                        i++;
                }
                if (event.key.code == sf::Keyboard::R){
                    disks1.setPosition(sf::Vector2f(150-12.5, 355));
                    disks2.setPosition(sf::Vector2f(150-22.5, 370));
                    disks3.setPosition(sf::Vector2f(150-32.5, 385));
                    i = 0;
                }

                string x = to_string(i);
                text.setString("Step number: " + x);

                if (i == 1)
                {
                    cout << "1" << endl;
                    disks1.setPosition(sf::Vector2f(750-12.5, 385));
                }
                else if (i == 2)
                {
                    cout << "2" << endl;
                    disks2.setPosition(sf::Vector2f(450-22.5, 385));
                }
                else if (i == 3)
                {
                    cout << "3" << endl;
                    disks1.setPosition(sf::Vector2f(450-12.5, 370));
                }
                else if (i == 4)
                {
                    cout << "4" << endl;
                    disks3.setPosition(sf::Vector2f(750-32.5, 385));
                }
                else if (i == 5)
                {
                    cout << "5" << endl;
                    disks1.setPosition(sf::Vector2f(150-12.5, 385));
                }
                else if (i == 6)
                {
                    cout << "6" << endl;
                    disks2.setPosition(sf::Vector2f(750-22.5, 370));
                }
                else if (i == 7)
                {
                    cout << "7" << endl;
                    disks1.setPosition(sf::Vector2f(750-12.5, 355));

                    text.setString("Step number: " + x + "\nPress R to reset");
                }
            }
        }

        window.clear();
        window.draw(text);

        window.draw(rectangle);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);

        window.draw(disks1);
        window.draw(disks2);
        window.draw(disks3);

        window.display();
    }

    return 0;
}
