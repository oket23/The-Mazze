#pragma once
#include "SFML/Graphics.hpp"
class TextString{
public:
	sf::Font font;
	sf::Text text;
	std::string fontPass = "Resours/Texture/Font/font.ttf";

	TextString(std::string textText = "");
	void draw(sf::RenderWindow* window);
	void setPosition(sf::Vector2f textPosition);
	void setString(std::string textText);
	void setColor(sf::Color color);
	void setTextSize(int size);
	void setTextCenter(sf::RenderWindow* window);
	void Sout(sf::Time Duration,sf::Clock clock,sf::RenderWindow* window);
	void Sin(sf::Time Duration, sf::Clock clock, sf::RenderWindow* window);

};
