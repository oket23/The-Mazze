#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Map.h"
#include "Enemy.h"

class Hero {
	
public:
	enum DIRECTION { STAND, RIGTH, LEFT, UP, DOWN };
	std::string name = "Player";
	float speed = 85.f /*200.f*/ / 1000.f;
	sf::Vector2i startPosition;
	DIRECTION HeroDirection = STAND;

	sf::Texture* heroTexture;
	sf::Sprite** spriteArray = nullptr;
	sf::Sprite activeSprite;
	int* maxCountFrameForDirection = nullptr;
	int CountDuraction = 5;

	sf::Time animationTimer = sf::Time::Zero;
	sf::Time animationLoopTime = sf::milliseconds(500);
	int activeFrame = 0;

	sf::Sound sound;
	sf::SoundBuffer soundBuffer[3];
	
	int mapNumber = 1;
	Map* mainMap = new Map("level_1");

	Hero(sf::Texture* texture, int positionX, int positionY);
	~Hero();
	
	void loadAnimation();
	void draw(sf::RenderWindow* window);
	void moveLeft(sf::Time timeElapsed);
	void moveRigth(sf::Time timeElapsed, sf::RenderWindow* window);
	void moveUp(sf::Time timeElapsed);
	void moveDown(sf::Time timeElapsed, sf::RenderWindow* window);
	void moveStand(sf::Time timeElapsed);
	void playSound(int number);
	void loadSound();
	bool colision(Map& activeLevel,sf::Vector2f shiftmove);

	bool EnemyContact(Enemy& enemy);
};

