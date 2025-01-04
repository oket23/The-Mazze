#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Map.h"
#include "Hero.h"
#include "Camera.h"
#include "Enemy.h"
#include "TextString.h"

class Game{
	struct GameStruct{
		char miniMapOpen : 1;
		char freeCamera : 1;
		char showStats : 1;
		char mainMusicNumber : 1;
		char menuOpen : 1;
	};
public:
	GameStruct GameStuct;
	sf::RenderWindow mainWindow;
	sf::Time mainTimer = sf::Time::Zero;
	sf::Clock mainClock;
	sf::Image image;
	sf::Image image2;
	sf::Texture texture[2];
	sf::Music mainMusic;
	sf::Vector2f PlayersCoords;

	sf::Clock walkClock;
	sf::Time walkTime = sf::seconds(0.3);
	int tableCounter = 0;
	
	Game(int mainWindowWidth,int mainWindowHigth, std::wstring mainWindowTitle);
	~Game();

	Map* mainMap = new Map("level_1");
	Hero* mainHero = new Hero(texture + 0,52,20);
	Camera* mainCamera = new Camera(sf::Vector2f(160,152), mainMap->getScenaSize());
	Camera* freeCamera = new Camera(sf::Vector2f(160,152), mainMap->getScenaSize());
	Camera* miniMap = new Camera(sf::Vector2f(300.f,300.f), mainMap->getScenaSize());
	TextString* IntroText = new TextString("");
	TextString* SettingsText = new TextString("");
	std::vector <Enemy*> enemies;

	void run();
	void renderFrame();
	void inputCommand();
	void updateGame();
	void setDefaultSettings();
	void loadTexture();
	void gameIntro();
	void mainMenu();
};

