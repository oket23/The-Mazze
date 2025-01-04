#pragma once
#include "SFML/Graphics.hpp"

class Camera{
public:
	sf::View view;
	sf::Vector2f scenaSize;
	
	Camera(sf::Vector2f cameraSize, sf::Vector2f scenaSize);
	sf::Vector2f cameraCorrection(sf::Vector2f centerCameraPosition);
	void setZoom(float scale);
	void setCenter(sf::Vector2f centerCameraPositionxy);
	void setScenaSize(sf::Vector2f scenaSize);
};

