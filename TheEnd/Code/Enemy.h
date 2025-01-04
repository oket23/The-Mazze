#pragma once
#include "SFML/Graphics.hpp"
#include "Map.h"

class Enemy{
	enum DIRECTION{RIGTH,LEFT,UP,DOWN};
public:
	float speed = 0 / 1000.f;
	sf::Vector2i startPosition;
	sf::Vector2f directionE;
	DIRECTION heroDir;

	sf::IntRect* spriteArrayCoords;
	sf::Texture* enemyTexture;
	sf::Sprite activeSprite;

	int currentFrame = 0;
	int maxFrameCount = 3;
	float maxAnimationTime = 1000.f;
	float oneFrameTime = maxAnimationTime / maxFrameCount;
	sf::Time animationTimer = sf::Time::Zero;


	Map* mainMap = new Map("level_1");

	Enemy(sf::Texture *texture,int x,int y);
	~Enemy();

	void draw(sf::RenderWindow* window);
	void myMoveY(sf::Time timeElapsed, float y1, float y2);
	void myMoveX(sf::Time timeElapsed, float x1, float x2);
	void animation(sf::Time timeElapsed, DIRECTION heroDir);
};
