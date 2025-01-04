#include "Hero.h"

Hero::Hero(sf::Texture* texture, int positionX, int positionY): heroTexture(texture),startPosition(positionX, positionY){
	loadAnimation();
	loadSound();
	activeSprite.setPosition(sf::Vector2f(positionX, positionY));
}

void Hero::loadAnimation(){
	float scaleX = 13.f / 192.0f; 
	float scaleY = 13.f / 192.0f; 

	if (maxCountFrameForDirection != nullptr) {
		delete[] maxCountFrameForDirection;
	}
	maxCountFrameForDirection = new int[CountDuraction] { 1, 3, 3, 3, 3 };

	if (spriteArray != nullptr) {
		for (int i = 0; i < CountDuraction; i++) {
			delete[] spriteArray[i];
		}
		delete[] spriteArray;
	}

	spriteArray = new sf::Sprite* [CountDuraction];
	for (int i = 0; i < CountDuraction; i++) {
		spriteArray[i] = new sf::Sprite[maxCountFrameForDirection[i]];
	}

	//Rigth
	for (int i = 0; i < maxCountFrameForDirection[RIGTH]; i++) {
		spriteArray[RIGTH][i].setTexture(*heroTexture);
		spriteArray[RIGTH][i].setTextureRect(sf::IntRect(12 + i * 192, 384, 150, 188));
		spriteArray[RIGTH][i].setScale(scaleX, scaleY);
	}
	//Left
	for (int i = 0; i < maxCountFrameForDirection[LEFT]; i++) {
		spriteArray[LEFT][i].setTexture(*heroTexture);
		spriteArray[LEFT][i].setTextureRect(sf::IntRect(28 + i * 192, 192, 150, 188));
		spriteArray[LEFT][i].setScale(scaleX, scaleY);
	}
	//up
	for (int i = 0; i < maxCountFrameForDirection[UP]; i++) {
		spriteArray[UP][i].setTexture(*heroTexture);
		spriteArray[UP][i].setTextureRect(sf::IntRect(18 + i * 192, 576, 150, 188));
		spriteArray[UP][i].setScale(scaleX, scaleY);
	}
	//down
	for (int i = 0; i < maxCountFrameForDirection[DOWN]; i++) {
		spriteArray[DOWN][i].setTexture(*heroTexture);
		spriteArray[DOWN][i].setTextureRect(sf::IntRect(18 + i * 192, 0, 150, 188));
		spriteArray[DOWN][i].setScale(scaleX, scaleY);
	}
	//stand
	for (int i = 0; i < maxCountFrameForDirection[STAND]; i++) {
		spriteArray[STAND][i].setTexture(*heroTexture);
		spriteArray[STAND][i].setTextureRect(sf::IntRect(216, 0, 150, 188));
		spriteArray[STAND][i].setScale(scaleX, scaleY);
	}
	activeSprite = spriteArray[STAND][0];	
}

void Hero::draw(sf::RenderWindow* window){
	if (window != nullptr) {
		window->draw(activeSprite);
	}
}
Hero::~Hero() {
	if (maxCountFrameForDirection != nullptr) {
		delete[] maxCountFrameForDirection;
		maxCountFrameForDirection = nullptr;
	}

	if (spriteArray != nullptr) {
		for (int i = 0; i < CountDuraction; i++) {
			if (spriteArray[i] != nullptr) {
				delete[] spriteArray[i];
			}
		}
		delete[] spriteArray;
		spriteArray = nullptr;
	}

	if (mainMap != nullptr) {
		delete mainMap;
		mainMap = nullptr;
	}
}

void Hero::moveLeft(sf::Time timeElapsed) {
	sf::Vector2f heroPosition = activeSprite.getPosition();
	sf::Vector2f spriteShift;
	if (HeroDirection != LEFT) {
		HeroDirection = LEFT;
		activeFrame = 0;
		animationTimer = sf::Time::Zero;
		if (spriteArray[LEFT] != nullptr) {
			activeSprite = spriteArray[LEFT][activeFrame];
		}
	}
	animationTimer += timeElapsed;
	if (animationTimer > animationLoopTime) {
		animationTimer = sf::Time::Zero;
	}
	sf::Time timeForOneFrame = sf::milliseconds(animationLoopTime.asMilliseconds() / maxCountFrameForDirection[LEFT]);
	if (activeFrame != animationTimer.asMilliseconds() / timeForOneFrame.asMilliseconds()) {
		activeFrame = animationTimer.asMilliseconds() / timeForOneFrame.asMilliseconds();
		if (activeFrame < maxCountFrameForDirection[LEFT] && spriteArray[LEFT] != nullptr) {
			activeSprite = spriteArray[LEFT][activeFrame];
		}
	}

	spriteShift.x = -speed * timeElapsed.asMilliseconds();
	spriteShift.y = 0.f;
	if (colision(*mainMap, spriteShift)) {
		heroPosition.x += spriteShift.x;
	}
	else {
		heroPosition.x -= 0;
	}

	activeSprite.setPosition(heroPosition);
}
void Hero::moveRigth(sf::Time timeElapsed,sf::RenderWindow* window) {
	sf::Vector2f heroPosition = activeSprite.getPosition();
	sf::Vector2f spriteShift;
	if (HeroDirection != RIGTH) {
		HeroDirection = RIGTH;
		animationTimer = sf::Time::Zero;
		activeFrame = 0;
		if (spriteArray[RIGTH] != nullptr) {
			activeSprite = spriteArray[RIGTH][activeFrame];
		}
	}
	animationTimer += timeElapsed;
	if (animationTimer > animationLoopTime) {
		animationTimer = sf::Time::Zero;
	}
	sf::Time timeForOneFrame = sf::milliseconds(animationLoopTime.asMilliseconds() / maxCountFrameForDirection[RIGTH]);
	if (activeFrame != animationTimer.asMilliseconds() / timeForOneFrame.asMilliseconds()) {
		activeFrame = animationTimer.asMilliseconds() / timeForOneFrame.asMilliseconds();
		if (activeFrame < maxCountFrameForDirection[RIGTH] && spriteArray[RIGTH] != nullptr) {
			activeSprite = spriteArray[RIGTH][activeFrame];
		}
	}

	spriteShift.x = speed * timeElapsed.asMilliseconds();
	spriteShift.y = 0.f;
	if (colision(*mainMap, spriteShift)) {
		heroPosition.x += spriteShift.x;
	}
	else {
		heroPosition.x -= 0;
	}

	activeSprite.setPosition(heroPosition);
}
void Hero::moveDown(sf::Time timeElapsed, sf::RenderWindow* window) {
	sf::Vector2f heroPosition = activeSprite.getPosition();
	sf::Vector2f spriteShift;
	if (HeroDirection != DOWN) {
		HeroDirection = DOWN;
		animationTimer = sf::Time::Zero;
		activeFrame = 0;
		if (spriteArray[DOWN] != nullptr) {
			activeSprite = spriteArray[DOWN][activeFrame];
		}
	}
	animationTimer += timeElapsed;
	if (animationTimer > animationLoopTime) {
		animationTimer = sf::Time::Zero;
	}
	sf::Time timeForOneFrame = sf::milliseconds(animationLoopTime.asMilliseconds() / maxCountFrameForDirection[DOWN]);
	if (activeFrame != animationTimer.asMilliseconds() / timeForOneFrame.asMilliseconds()) {
		activeFrame = animationTimer.asMilliseconds() / timeForOneFrame.asMilliseconds();
		if (activeFrame < maxCountFrameForDirection[DOWN] && spriteArray[DOWN] != nullptr) {
			activeSprite = spriteArray[DOWN][activeFrame];
		}
	}

	spriteShift.x = 0.f;
	spriteShift.y = speed * timeElapsed.asMilliseconds();

	if (colision(*mainMap, spriteShift)) {
		heroPosition.y += spriteShift.y;
	}
	else {
		heroPosition.y -= 0;
	}

	activeSprite.setPosition(heroPosition);
}
void Hero::moveUp(sf::Time timeElapsed) {
	sf::Vector2f heroPosition = activeSprite.getPosition();
	sf::Vector2f spriteShift;
	if (HeroDirection != UP) {
		HeroDirection = UP;
		animationTimer = sf::Time::Zero;
		activeFrame = 0;
		if (spriteArray[UP] != nullptr) {
			activeSprite = spriteArray[UP][activeFrame];
		}
	}
	animationTimer += timeElapsed;
	if (animationTimer > animationLoopTime) {
		animationTimer = sf::Time::Zero;
	}
	sf::Time timeForOneFrame = sf::milliseconds(animationLoopTime.asMilliseconds() / maxCountFrameForDirection[UP]);
	if (activeFrame != animationTimer.asMilliseconds() / timeForOneFrame.asMilliseconds()) {
		activeFrame = animationTimer.asMilliseconds() / timeForOneFrame.asMilliseconds();
		if (activeFrame < maxCountFrameForDirection[UP] && spriteArray[UP] != nullptr) {
			activeSprite = spriteArray[UP][activeFrame];
		}
	}

	spriteShift.x = 0.f;
	spriteShift.y = -speed * timeElapsed.asMilliseconds();
	if (colision(*mainMap, spriteShift)) {
		heroPosition.y += spriteShift.y;
	}
	else {
		heroPosition.y -= 0;
	}

	activeSprite.setPosition(heroPosition);
}
void Hero::moveStand(sf::Time timeElapsed) {
	sf::Vector2f heroPosition = activeSprite.getPosition();
	if (HeroDirection != STAND) {
		HeroDirection = STAND;
		activeFrame = 0;
		animationTimer = sf::Time::Zero;
		activeSprite = spriteArray[STAND][activeFrame];
	}
	activeSprite.setPosition(heroPosition);
}

void Hero::playSound(int number){
	sound.stop();
	sound.setBuffer(soundBuffer[number]);
	sound.setVolume(25);
	sound.play();
}
void Hero::loadSound(){
	std::string soundArray[] = { "walk1.mp3","tableCollect.mp3"};
	soundBuffer[0].loadFromFile("Resours/Texture/Music/" + soundArray[0]);
	soundBuffer[1].loadFromFile("Resours/Texture/Music/" + soundArray[1]);
}

bool Hero::colision(Map& activeLevel, sf::Vector2f shiftMove) {
	sf::Vector2f oldCoords = activeSprite.getGlobalBounds().getPosition();
	sf::Vector2f currentSize = activeSprite.getGlobalBounds().getSize();
	sf::Vector2f newCoords = oldCoords + shiftMove;

	char symbolL = activeLevel.getLevelName(mapNumber)[(int)(newCoords.y + 1)/ 16][(int)(newCoords.x + 0.5f) / 16]; //поставити 0 по дефолту
	char symbolR = activeLevel.getLevelName(mapNumber)[(int)(newCoords.y + 1)/ 16][(int)(newCoords.x + currentSize.x - 0.5f) / 16];
	char symbolDR = activeLevel.getLevelName(mapNumber)[int(newCoords.y + currentSize.y - 1) / 16][(int)(newCoords.x + 0.5f) / 16];
	char symbolDL = activeLevel.getLevelName(mapNumber)[int(newCoords.y + currentSize.y - 1) / 16][(int)(newCoords.x + currentSize.x - 0.5f) / 16];

	// up left
	if (symbolL != 'f' && symbolL != 'n' && symbolL != '[' && symbolL != ']' && symbolL != 'S' && symbolL != 'T' && symbolL != 'A' && symbolL != 'R' && symbolL != 'v' && symbolL != 'o' && symbolL != 'i' && symbolL != 'd' && symbolL != 'V' && symbolL != 'O' && symbolL != 'I' && symbolL != 'D' && symbolL != 'm' && symbolL != ',' && symbolL != '.' && symbolL != '/') {
		return false;
	}
	// up right
	if (symbolR != 'f' && symbolR != 'n' && symbolR != '[' && symbolR != ']' && symbolR != 'S' && symbolR != 'T' && symbolR != 'A' && symbolR != 'R' && symbolR != 'v' && symbolR != 'o' && symbolR != 'i' && symbolR != 'd' && symbolR != 'V' && symbolR != 'O' && symbolR != 'I' && symbolR != 'D' && symbolR != 'm' && symbolR != ',' && symbolR != '.' && symbolR != '/') {
		return false;
	}
	// down lef
	if (symbolDR != 'f' && symbolDR != 'n' && symbolDR != '[' && symbolDR != ']' && symbolDR != 'S' && symbolDR != 'T' && symbolDR != 'A' && symbolDR != 'R' && symbolDR != 'v' && symbolDR != 'o' && symbolDR != 'i' && symbolDR != 'd' && symbolDR != 'V' && symbolDR != 'O' && symbolDR != 'I' && symbolDR != 'D' && symbolDR != 'm' && symbolDR != ',' && symbolDR != '.' && symbolDR != '/') {
		return false;
	}
	// down right
	if (symbolDL != 'f' && symbolDL != 'n' && symbolDL != '[' && symbolDL != ']' && symbolDL != 'S' && symbolDL != 'T' && symbolDL != 'A' && symbolDL != 'R' && symbolDL != 'v' && symbolDL != 'o' && symbolDL != 'i' && symbolDL != 'd' && symbolDL != 'V' && symbolDL != 'O' && symbolDL != 'I' && symbolDL != 'D' && symbolDL != 'm' && symbolDL != ',' && symbolDL != '.' && symbolDL != '/') {
		return false;
	}

	return true;
}

bool Hero::EnemyContact(Enemy& enemy) {
	sf::FloatRect heroBox = activeSprite.getGlobalBounds();
	sf::FloatRect EnemyBox = enemy.activeSprite.getGlobalBounds();

	if (heroBox.intersects(EnemyBox)) {
		return true;
	} 
	return false;

}

