#include "Game.h"

Game::Game(int mainWindowWidth, int mainWindowHigth, std::wstring mainWindowTitle){
	mainWindow.create(sf::VideoMode(mainWindowWidth, mainWindowHigth), mainWindowTitle);
	mainWindow.setFramerateLimit(60);
	loadTexture();
}

Game::~Game(){
	
}

void Game::run(){
	setDefaultSettings();
	gameIntro();
	while (mainWindow.isOpen()){
		mainTimer = mainClock.restart();
		inputCommand();
		updateGame();
		renderFrame();
	}
}
void Game::inputCommand() {
	sf::Event mainEvent;
	
	while (mainWindow.pollEvent(mainEvent)) {
		if (mainEvent.type == sf::Event::Closed) {
			mainWindow.close();
		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::Escape) {
			GameStuct.menuOpen = 1;
			mainMenu();
		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::F3) {
			if (GameStuct.showStats == 0) {
				GameStuct.showStats = 1;
			}
			else {
				GameStuct.showStats = 0;
			}	
		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::F4) {
			if (GameStuct.mainMusicNumber == 0) {
				GameStuct.mainMusicNumber = 1;
				mainMusic.stop();
				mainMusic.openFromFile("Resours/Texture/Music/main2.mp3");
				mainMusic.setLoop(true);
				mainMusic.setVolume(10.f);
				mainMusic.play();
			}
			else {
				GameStuct.mainMusicNumber = 0;
				mainMusic.openFromFile("Resours/Texture/Music/main1.ogg");
				mainMusic.setLoop(true);
				mainMusic.setVolume(10.f);
				mainMusic.play();
			}

		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::M) {
			if (GameStuct.miniMapOpen == 0) {
				miniMap->view.setViewport(sf::FloatRect(0, 0, 1, 1)); 
				GameStuct.miniMapOpen = 1;
			}
			else {
				miniMap->view.setViewport(sf::FloatRect(0, 0, 0, 0)); 
				GameStuct.miniMapOpen = 0;
			}
		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::V) {
			if (GameStuct.freeCamera == 0) {
				mainWindow.setView(freeCamera->view);
				freeCamera->setCenter(mainHero->activeSprite.getPosition());
				GameStuct.freeCamera = 1;
			}
			else {
				mainWindow.setView(mainCamera->view);
				GameStuct.freeCamera = 0;
			}
		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::D) {
			if (!GameStuct.miniMapOpen && !GameStuct.freeCamera) {
				if (walkClock.getElapsedTime() >= walkTime) {
					mainHero->playSound(0);
					walkClock.restart();
				}
			}
			
		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::A) {
			if (!GameStuct.miniMapOpen && !GameStuct.freeCamera) {
				if (walkClock.getElapsedTime() >= walkTime) {
					mainHero->playSound(0);
					walkClock.restart();
				}
			}
		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::S) {
			if (!GameStuct.miniMapOpen && !GameStuct.freeCamera) {
				if (walkClock.getElapsedTime() >= walkTime) {
					mainHero->playSound(0);
					walkClock.restart();
				}
			}
		}
		if (mainEvent.type == sf::Event::KeyPressed && mainEvent.key.code == sf::Keyboard::W) {
			if (!GameStuct.miniMapOpen && !GameStuct.freeCamera) {
				if (walkClock.getElapsedTime() >= walkTime) {
					mainHero->playSound(0);
					walkClock.restart();
				}
			}
		}

		if (mainEvent.type == sf::Event::KeyReleased) {
			mainHero->moveStand(mainTimer);
		}
	}

	if (!GameStuct.miniMapOpen&& !GameStuct.freeCamera && !GameStuct.menuOpen) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			mainHero->moveLeft(mainTimer);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			mainHero->moveRigth(mainTimer, &mainWindow);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			mainHero->moveUp(mainTimer);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			mainHero->moveDown(mainTimer, &mainWindow);
		}
	}
	if (GameStuct.freeCamera) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (freeCamera->view.getCenter().x  - freeCamera->view.getSize().x/2 -1< 0) {
				freeCamera->view.move(0, 0.f);
			}
			else {
				freeCamera->view.move(-1.f, 0.f);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (freeCamera->view.getCenter().x + freeCamera->view.getSize().x / 2 + 1 > mainWindow.getSize().x) {
				freeCamera->view.move(0, 0.f);
			}
			else {
				freeCamera->view.move(1.f, 0.f);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (freeCamera->view.getCenter().y - freeCamera->view.getSize().y / 2 + 1 < 0) {
				freeCamera->view.move(0, 0.f);
			}
			else {
				freeCamera->view.move(0.f, -1.f);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (freeCamera->view.getCenter().y + freeCamera->view.getSize().y / 2 + 8 > mainWindow.getSize().y) {
				freeCamera->view.move(0, 0.f);
			}
			else {
				freeCamera->view.move(0.f, 1.f);
			}
		}
	}
}
void Game::updateGame() {
	PlayersCoords.x = mainHero->activeSprite.getPosition().x / 16;
	PlayersCoords.y = mainHero->activeSprite.getPosition().y / 16;
	if (mainMap->CheckTable(PlayersCoords.x, PlayersCoords.y, mainMap->getLevelName(mainHero->mapNumber))) {
		mainHero->playSound(1);
		mainHero->speed -= 2.5f / 1000.f;
		tableCounter++;
	}
	if (tableCounter == 5) {
		mainMap->openSecondLevel(mainMap->getLevelName(mainHero->mapNumber));
	}
	if (tableCounter == 1 && mainHero->mapNumber == 2) {
		mainMap->openFinish(mainMap->getLevelName(mainHero->mapNumber));
	}
	if (mainMap->goNext(PlayersCoords.x, PlayersCoords.y, mainMap->getLevelName(mainHero->mapNumber))) {
		sf::Time introDuration = sf::seconds(5);
		sf::Time Level2IntroDuration = sf::seconds(10);
		sf::Clock introClock;
		sf::Clock Level2IntroClock;

		IntroText->setString("Level 2");
		IntroText->setTextCenter(&mainWindow);
		IntroText->setColor(sf::Color::White);
		IntroText->setTextSize(30);

		mainCamera->view.setSize(sf::Vector2f(mainWindow.getSize()));
		mainCamera->view.setCenter(sf::Vector2f(mainWindow.getSize().x / 2, mainWindow.getSize().y / 2));
		mainWindow.setView(mainCamera->view);

		sf::sleep(sf::seconds(0.5));

		while (Level2IntroDuration > Level2IntroClock.getElapsedTime()) {

			sf::Event event;
			while (mainWindow.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					mainWindow.close();
			}

			mainWindow.clear();

			introClock.restart();
			IntroText->Sin(introDuration, introClock, &mainWindow);
			introClock.restart();
			IntroText->Sout(introDuration, introClock, &mainWindow);

			mainWindow.display();
		}
		mainTimer = mainClock.restart();

		mainHero->mapNumber = 2;
		mainHero->activeSprite.setPosition(sf::Vector2f(16, 16));
		mainHero->moveStand(mainTimer);
		mainHero->speed = 75.f / 1000.f;
		
		mainCamera->setScenaSize(mainMap->getScenaSize());
		miniMap->view.reset(sf::FloatRect(0, 0, 300.f, 300.f));
		mainCamera->view.reset(sf::FloatRect(0, 0, 160.f, 152.f));
		mainWindow.setView(mainCamera->view);
		tableCounter = 0;
		mainMap->loadMap("level_2");
	}
	if (mainHero->mapNumber == 2 && !GameStuct.miniMapOpen && !GameStuct.menuOpen) {
		enemies[0]->myMoveX(mainTimer, 360.f, 720.f);
		enemies[1]->myMoveX(mainTimer, 64.f, 360.f);
		enemies[2]->myMoveX(mainTimer, 360.f, 720.f);
		enemies[3]->myMoveX(mainTimer, 64.f, 360.f);
		enemies[4]->myMoveY(mainTimer, 240.f, 400.f);
		enemies[5]->myMoveY(mainTimer, 240.f, 400.f);
		enemies[6]->myMoveY(mainTimer, 240.f, 400.f);
		enemies[7]->myMoveY(mainTimer, 240.f, 400.f);
		enemies[8]->myMoveY(mainTimer, 240.f, 400.f);
		enemies[9]->myMoveY(mainTimer, 240.f, 400.f);
		enemies[10]->myMoveY(mainTimer, 240.f, 400.f);
		enemies[11]->myMoveY(mainTimer, 240.f, 400.f);
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->speed = 80.f / 1000;
			if (mainHero->EnemyContact(*enemies[i])) {
				//sf::sleep(sf::milliseconds(1000));
				mainHero->activeSprite.setPosition(16.f, 16.f);
				mainCamera->view.reset(sf::FloatRect(0, 0, 160.f, 152.f));
			}
		}
	}
	if (mainMap->showEnds(PlayersCoords.x, PlayersCoords.y, mainMap->getLevelName(mainHero->mapNumber))) {
		sf::Time finalDuration = sf::seconds(15);
		sf::Clock finalClock;

		IntroText->setString("The End");
		IntroText->setTextCenter(&mainWindow);
		IntroText->setColor(sf::Color::White);
		IntroText->setTextSize(30);

		mainCamera->view.setSize(sf::Vector2f(mainWindow.getSize()));
		mainCamera->view.setCenter(sf::Vector2f(mainWindow.getSize().x / 2, mainWindow.getSize().y / 2));
		mainWindow.setView(mainCamera->view);

		sf::sleep(sf::seconds(1));

		while (finalDuration > finalClock.getElapsedTime()) {

			sf::Event event;
			while (mainWindow.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					mainWindow.close();
			}

			mainWindow.clear();

			finalClock.restart();
			IntroText->Sin(finalDuration, finalClock, &mainWindow);

			mainWindow.display();
		}
		mainWindow.close();
	}

}
void Game::renderFrame(){
	mainWindow.clear(); 

	if (GameStuct.freeCamera) {
		GameStuct.showStats = 0;
		mainWindow.setView(freeCamera->view);
	}
	else {
		mainCamera->setCenter(mainHero->activeSprite.getPosition());
		mainWindow.setView(mainCamera->view);
	}
	mainMap->draw(&mainWindow);
	mainHero->draw(&mainWindow);

	if (mainHero->mapNumber == 2) {
		for (auto enemy : enemies) {
			enemy->draw(&mainWindow);
		}
	}

	if (GameStuct.showStats) {
		SettingsText->setString("x " + std::to_string(int(PlayersCoords.x)));
		SettingsText->setTextSize(10);
		SettingsText->setPosition(sf::Vector2f(mainCamera->view.getCenter().x - 77, mainCamera->view.getCenter().y - 75));
		SettingsText->draw(&mainWindow);
		SettingsText->setString("y " + std::to_string(int(PlayersCoords.y)));
		SettingsText->setPosition(sf::Vector2f(mainCamera->view.getCenter().x - 77, mainCamera->view.getCenter().y - 63));
		SettingsText->draw(&mainWindow);
		if (mainHero->mapNumber == 1) {
			SettingsText->setString("table " + std::to_string(tableCounter) + " out of 5");
		}
		else {
			SettingsText->setString("table " + std::to_string(tableCounter) + " out of 1");
		}
		
		SettingsText->setPosition(sf::Vector2f(mainCamera->view.getCenter().x - 77, mainCamera->view.getCenter().y - 50));
		SettingsText->draw(&mainWindow);
	}

	miniMap->setCenter(mainHero->activeSprite.getPosition());
	mainWindow.setView(miniMap->view);
	mainMap->draw(&mainWindow);
	mainHero->draw(&mainWindow);
	if (mainHero->mapNumber == 2) {
		for (auto enemy : enemies) {
			enemy->draw(&mainWindow);
		}
	}

	mainWindow.setView(mainCamera->view);
	mainWindow.display(); 
}
void Game::setDefaultSettings() {
	GameStuct.mainMusicNumber = 0;
	GameStuct.miniMapOpen = 0;
	GameStuct.freeCamera = 0;
	GameStuct.showStats = 0;
	GameStuct.menuOpen = 0;
	tableCounter = 0;

	enemies.push_back(new Enemy(texture + 1, 64.f, 50.f));
	enemies.push_back(new Enemy(texture + 1, 360.f, 50.f));
	enemies.push_back(new Enemy(texture + 1, 64.f, 146.f));
	enemies.push_back(new Enemy(texture + 1, 360.f, 146.f));
	enemies.push_back(new Enemy(texture + 1, 66.f, 224.f));
	enemies.push_back(new Enemy(texture + 1, 132.f, 224.f));
	enemies.push_back(new Enemy(texture + 1, 162.f, 224.f));
	enemies.push_back(new Enemy(texture + 1, 228.f, 224.f));
	enemies.push_back(new Enemy(texture + 1, 562.f, 224.f));
	enemies.push_back(new Enemy(texture + 1, 628.f, 224.f));
	enemies.push_back(new Enemy(texture + 1, 658.f, 224.f));
	enemies.push_back(new Enemy(texture + 1, 724.f, 224.f));

	miniMap->view.setViewport(sf::FloatRect(0, 0, 0, 0));

	sf::Image logoImage;
	logoImage.loadFromFile("Resours/Texture/Logo/Logo.png");
	mainWindow.setIcon(logoImage.getSize().x, logoImage.getSize().y, logoImage.getPixelsPtr());

	mainMusic.openFromFile("Resours/Texture/Music/main1.ogg");
	mainMusic.setLoop(true);
	mainMusic.setVolume(10.f);
	mainMusic.play();
}
void Game::loadTexture(){
	image.loadFromFile("Resours/Texture/Hero/hero_1.png");
	texture[0].loadFromImage(image);
	
	image2.loadFromFile("Resours/Texture/Enemy/enemy.png");
	texture[1].loadFromImage(image2);
}
void Game::gameIntro(){
	sf::Time introDuration = sf::seconds(5);
	sf::Time guideDuration = sf::seconds(5);
	sf::Clock introClock;
	sf::Clock guideClock;

	IntroText->setString("The Mazze");
	IntroText->setTextSize(30);
	IntroText->setColor(sf::Color(255, 255, 255, 255));
	IntroText->setTextCenter(&mainWindow);

	IntroText->Sout(introDuration, introClock, &mainWindow);

	IntroText->text.setString("Collect 5 table and run");
	IntroText->setTextCenter(&mainWindow);

	guideClock.restart();
	IntroText->Sin(guideDuration, guideClock, &mainWindow);
	guideClock.restart();
	IntroText->Sout(guideDuration, guideClock, &mainWindow);
}
void Game::mainMenu(){
	sf::Event menuEvent;
	int currentMenuItem = 0;
	int maxMenuItem = 4;
	sf::Texture mainBackTexture;
	mainBackTexture.loadFromFile("Resours/Texture/MenuItem/123.png");

	sf::RectangleShape menuRectangleShape(sf::Vector2f(50, 60));
	menuRectangleShape.setPosition(sf::Vector2f(mainCamera->view.getCenter().x - 25, mainCamera->view.getCenter().y - 30));
	menuRectangleShape.setTexture(&mainBackTexture);

	sf::Texture menuButtonTexture1;
	menuButtonTexture1.loadFromFile("Resours/Texture/MenuItem/start.png");
	sf::Texture menuButtonTexture2;
	menuButtonTexture2.loadFromFile("Resours/Texture/MenuItem/volume1.png");
	sf::Texture menuButtonTexture3;
	menuButtonTexture3.loadFromFile("Resours/Texture/MenuItem/volume2.png");
	sf::Texture menuButtonTexture4;
	menuButtonTexture4.loadFromFile("Resours/Texture/MenuItem/quit.png");
	sf::RectangleShape menuButton[4];
	menuButton[0].setTexture(&menuButtonTexture1);
	menuButton[1].setTexture(&menuButtonTexture2);
	menuButton[2].setTexture(&menuButtonTexture3);
	menuButton[3].setTexture(&menuButtonTexture4);

	for (int i = 0; i < 4; i++) {
		menuButton[i].setSize(sf::Vector2f(40.f, 10.f));
		menuButton[i].setPosition(sf::Vector2f(menuRectangleShape.getPosition().x + 5 , menuRectangleShape.getPosition().y + 6.125 + 12.5 * i));
	}

	bool isMenu = true;
	while (isMenu) {
		while (mainWindow.pollEvent(menuEvent)) {
			if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::W) {
				currentMenuItem = (currentMenuItem - 1 >= 0) ? currentMenuItem - 1 : maxMenuItem - 1;
			}
			if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::S) {
				currentMenuItem = (currentMenuItem + 1 < maxMenuItem) ? currentMenuItem + 1 : 0;
			}
			if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Escape) {
				GameStuct.menuOpen = 0;
				mainClock.restart();
				isMenu = false;
				break;
			}
			if (menuEvent.type == sf::Event::KeyPressed && menuEvent.key.code == sf::Keyboard::Enter) {
				switch (currentMenuItem) {
				case 0: {
					GameStuct.menuOpen = 0;
					mainClock.restart();
					isMenu = false;
					break;
				}break;
				case 1: {
					int volume = mainMusic.getVolume();
					if (volume + 10 <= 100) {
						mainMusic.setVolume(volume + 10.f);
					}
					else {
						mainMusic.setVolume(100);
					}
				} break;

				case 2: {
					int volume = mainMusic.getVolume();
					if (volume - 10 >= 0) {
						mainMusic.setVolume(volume - 10.f);
					}
					else {
						mainMusic.setVolume(0);
					}
				} break;
				case 3: {
					GameStuct.menuOpen = 0;
					isMenu = false;
					mainWindow.close();
					break;
				}break;
				}
			}
			for (int i = 0; i < 4; i++) {
				if (currentMenuItem == i) {
					menuButton[i].setFillColor(sf::Color::Cyan);
				}
				else {
					menuButton[i].setFillColor(sf::Color::White);
				}
			}

			mainWindow.draw(menuRectangleShape);
			for (int i = 0; i < 4; i++) {
				mainWindow.draw(menuButton[i]);
			}
			mainWindow.display();
		}
	}
}
