#include "TextString.h"

TextString::TextString(std::string textText){
	font.loadFromFile(fontPass);
	text.setFont(font);
	setString(textText);
}

void TextString::draw(sf::RenderWindow* window){
	window->draw(text);
}

void TextString::setPosition(sf::Vector2f textPosition){
	text.setPosition(textPosition);
}
void TextString::setString(std::string textText){
	text.setString(textText);
}
void TextString::setColor(sf::Color color){
	text.setFillColor(color);
}
void TextString::setTextSize(int size){
	text.setCharacterSize(size);
}
void TextString::setTextCenter(sf::RenderWindow* window){
	sf::FloatRect textRect2 = text.getLocalBounds();
	text.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);
	text.setPosition(window->getSize().x / 2, window->getSize().y / 2);
}
void TextString::Sout(sf::Time Duration, sf::Clock clock, sf::RenderWindow* window){
	sf::Time elapsed;
	float visible = 255;

	while (elapsed < Duration) {
		elapsed = clock.getElapsedTime();
		window->clear();
		window->draw(text);

		if (visible > 0 && elapsed.asSeconds() > 3) {
			visible -= 2.5;
			setColor(sf::Color(255, 255, 255, visible));
		}

		window->display();
	}
}
void TextString::Sin(sf::Time Duration, sf::Clock clock, sf::RenderWindow* window){
	sf::Time elapsed;
	float visible = 0;

	while (elapsed < Duration) {
		elapsed = clock.getElapsedTime();
		window->clear();
		window->draw(text);

		if (visible < 255) {
			visible += 2.5f; 
			setColor(sf::Color(255, 255, 255, visible));
		}

		window->display();
	}
}
