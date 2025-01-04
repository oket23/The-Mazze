#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, int x, int y) : enemyTexture(texture), startPosition(x, y) {
	activeSprite.setTexture(*enemyTexture);
	activeSprite.setPosition(sf::Vector2f(x, y));
	activeSprite.setScale(16.0f / 48.f, 16.0f / 48.f);

}

Enemy::~Enemy(){
	if (mainMap != nullptr) {
		delete mainMap;
		mainMap = nullptr;
	}
	if (spriteArrayCoords != nullptr) {
		delete[] spriteArrayCoords;
	}
}

void Enemy::draw(sf::RenderWindow* window){
	if (window != nullptr) {
		window->draw(activeSprite);
	}
}

void Enemy::myMoveY(sf::Time timeElapsed, float y1, float y2) {
	float way = speed * timeElapsed.asMilliseconds();
	sf::Vector2f currentPosition = activeSprite.getPosition();
	animation(timeElapsed, heroDir);

	if (currentPosition.y >= y2) {
		heroDir = UP;
		directionE = sf::Vector2f(0.f, -1.f);
	}
	else if (currentPosition.y <= y1) {
		heroDir = DOWN;
		directionE = sf::Vector2f(0.f, 1.f);
	}
	
	activeSprite.move(directionE.x * way, directionE.y * way);
}
void Enemy::myMoveX(sf::Time timeElapsed,float x1,float x2) {
	float way = speed * timeElapsed.asMilliseconds();
	sf::Vector2f currentPosition = activeSprite.getPosition();
	animation(timeElapsed, heroDir);

	if (currentPosition.x >= x2) {
		heroDir = LEFT;
		directionE = sf::Vector2f(-1.f, 0.f);
	}
	else if (currentPosition.x <= x1) {
		heroDir = RIGTH;
		directionE = sf::Vector2f(1.f, 0.f);
	}

	activeSprite.move(directionE.x * way, directionE.y * way);
}

void Enemy::animation(sf::Time timeElapsed,DIRECTION dir){
	spriteArrayCoords = new sf::IntRect[maxFrameCount];
	switch (dir){
	case LEFT: {
		for (int i = 0; i < maxFrameCount; i++) {
			spriteArrayCoords[i] = sf::IntRect(i * 28 + 8, 52, 21, 42);
		}
	}break;
	case RIGTH: {
		for (int i = 0; i < maxFrameCount; i++) {
			spriteArrayCoords[i] = sf::IntRect(i * 28 + 29, 52, -21, 42);
		}
	}break;
	case UP: {
		for (int i = 0; i < maxFrameCount; i++) {
			spriteArrayCoords[i] = sf::IntRect(i * 31 + 3, 148, 29, 42);
		}
	}break;
	case DOWN: {
		for (int i = 0; i < maxFrameCount; i++) {
			spriteArrayCoords[i] = sf::IntRect(i * 31 + 3, 5, 29, 42);
		}
	}break;
	}
	
	
	activeSprite.setTextureRect(spriteArrayCoords[0]);
	animationTimer += timeElapsed;
	if (animationTimer.asMilliseconds() / maxAnimationTime) {
		animationTimer = sf::Time::Zero;
	}
	int tempCurrentframe = (int)animationTimer.asMilliseconds() / oneFrameTime;
	if (currentFrame != tempCurrentframe) {
		currentFrame = tempCurrentframe;
		activeSprite.setTextureRect(spriteArrayCoords[currentFrame]);
	}
}

