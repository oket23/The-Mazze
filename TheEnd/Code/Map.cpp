#include "Map.h"

Map::Map(std::string mapFileName){
	loadMap(mapFileName);
}
Map::~Map(){
	if (mapArray != nullptr) {
		for (int i = 0; i < mapSize.y; i++) {
			delete mapArray[i];
		}
		delete mapArray;
	}
}

void Map::loadMap(std::string mapFileName) {
	mapImage.loadFromFile("Resours/Texture/Map/Map.png");
	mapTexture.loadFromImage(mapImage);

	if (mapArray != nullptr) {
		for (int i = 0; i < mapSize.y; i++) {
			delete mapArray[i];
		}
		delete mapArray;
	}
	mapSize.x = 50;
	mapSize.y = 37;
	mapTailSize.x = 16;
	mapTailSize.y = 16;
	scenaSize.x = mapSize.x * mapTailSize.x;
	scenaSize.y = mapSize.y * mapTailSize.y;

	mapArray = new char* [mapSize.y];

	if (mapFileName == "level_1") {
		for (int i = 0; i < mapSize.y; i++) {
			mapArray[i] = new char[mapSize.x];
		}
		for (int i = 0; i < mapSize.y; i++) {
			for (int j = 0; j < mapSize.x; j++) {
				mapArray[i][j] = level_1[i][j];
			}
		}
	}
	else if (mapFileName == "level_2") {
		for (int i = 0; i < mapSize.y; i++) {
			mapArray[i] = new char[mapSize.x];
		}
		for (int i = 0; i < mapSize.y; i++) {
			for (int j = 0; j < mapSize.x; j++) {
				mapArray[i][j] = level_2[i][j];
			}
		}
	}
	
}

void Map::draw(sf::RenderWindow* window){
	mapSprite.setTexture(mapTexture);
	for (int y = 0; y < mapSize.y; y++) {
		for (int x = 0; x < mapSize.x; x++) {
			switch (mapArray[y][x]) {
			case '1': {
				mapSprite.setTextureRect(sf::IntRect(0, 48, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 96, mapTailSize.x, mapTailSize.y));

			}break;
			case '2': {
				mapSprite.setTextureRect(sf::IntRect(32, 48, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 96, mapTailSize.x, mapTailSize.y));

			}break;
			case '3': {
				mapSprite.setTextureRect(sf::IntRect(0, 80, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 112, mapTailSize.x, mapTailSize.y));
			}break;
			case '4': {
				mapSprite.setTextureRect(sf::IntRect(32, 80, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 112, mapTailSize.x, mapTailSize.y));
			}break;
			case '5': {
				mapSprite.setTextureRect(sf::IntRect(32, 48, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 96, mapTailSize.x, mapTailSize.y));
			}break;
			case '6': {
				mapSprite.setTextureRect(sf::IntRect(16, 48, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 96, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 96, mapTailSize.x, mapTailSize.y));
			}break;
			case '7': {
				mapSprite.setTextureRect(sf::IntRect(0, 64, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 112, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 96, mapTailSize.x, mapTailSize.y));
			}break;
			case '8': {
				mapSprite.setTextureRect(sf::IntRect(0, 80, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 112, mapTailSize.x, mapTailSize.y));
			}break;
			case '9': {
				mapSprite.setTextureRect(sf::IntRect(32, 48, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 96, mapTailSize.x, mapTailSize.y));
			}break;
			case '0': {
				mapSprite.setTextureRect(sf::IntRect(32, 80, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 112, mapTailSize.x, mapTailSize.y));
			}break;
			case '`': {
				mapSprite.setTextureRect(sf::IntRect(16, 64, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 96, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 112, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 96, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 112, mapTailSize.x, mapTailSize.y));
			}break;
			case ':': {
				mapSprite.setTextureRect(sf::IntRect(32, 64, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 96, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 112, mapTailSize.x, mapTailSize.y));
			}break;
			case 'L': {
				mapSprite.setTextureRect(sf::IntRect(16, 80, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 112, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 112, mapTailSize.x, mapTailSize.y));
			}break;
			case 'K': {
				mapSprite.setTextureRect(sf::IntRect(0, 64, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 112, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 96, mapTailSize.x, mapTailSize.y));
			}break;

			case 'f': { mapSprite.setTextureRect(sf::IntRect(16, 64, mapTailSize.x, mapTailSize.y)); }break; //144, 96 трава
			case 'n': { mapSprite.setTextureRect(sf::IntRect(112, 96, mapTailSize.x, mapTailSize.y)); }break;

			case 'q': { mapSprite.setTextureRect(sf::IntRect(80, 32, mapTailSize.x, mapTailSize.y)); }break;
			case 'w': { mapSprite.setTextureRect(sf::IntRect(96, 32, mapTailSize.x, mapTailSize.y)); }break;
			case 'e': { mapSprite.setTextureRect(sf::IntRect(112, 32, mapTailSize.x, mapTailSize.y)); }break;

			case 'z': { mapSprite.setTextureRect(sf::IntRect(96, 48, mapTailSize.x, mapTailSize.y)); }break;
			case 'x': { mapSprite.setTextureRect(sf::IntRect(96, 64, mapTailSize.x, mapTailSize.y)); }break;
			case 'c': { mapSprite.setTextureRect(sf::IntRect(96, 80, mapTailSize.x, mapTailSize.y)); }break;

			case ' ': mapSprite.setTextureRect(sf::IntRect(16, 16, mapTailSize.x, mapTailSize.y)); break;

			case '[': {
				mapSprite.setTextureRect(sf::IntRect(16, 64, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(112, 155, mapTailSize.x, mapTailSize.y));
			}break;
			case ']': {
				mapSprite.setTextureRect(sf::IntRect(16, 64, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(96, 160, mapTailSize.x, mapTailSize.y));
			}break;

			case 'v': mapSprite.setTextureRect(sf::IntRect(0, 0, mapTailSize.x, mapTailSize.y)); break;
			case 'o': mapSprite.setTextureRect(sf::IntRect(32, 0, mapTailSize.x, mapTailSize.y)); break;
			case 'i': mapSprite.setTextureRect(sf::IntRect(0, 32, mapTailSize.x, mapTailSize.y)); break;
			case 'd': mapSprite.setTextureRect(sf::IntRect(32, 32, mapTailSize.x, mapTailSize.y)); break;
			case 'V':{ mapSprite.setTextureRect(sf::IntRect(0, 0, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 160, mapTailSize.x, mapTailSize.y));
			}break;
			case 'O': { mapSprite.setTextureRect(sf::IntRect(32, 0, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 160, mapTailSize.x, mapTailSize.y));
			}break;
			case 'I': { mapSprite.setTextureRect(sf::IntRect(0, 32, mapTailSize.x, mapTailSize.y)); 
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 160, mapTailSize.x, mapTailSize.y));
			}break;
			case 'D': { mapSprite.setTextureRect(sf::IntRect(32, 32, mapTailSize.x, mapTailSize.y)); 
				mapSprite.setPosition(x* mapTailSize.x, y* mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 160, mapTailSize.x, mapTailSize.y));
			}break;
			case 'S': {
				mapSprite.setTextureRect(sf::IntRect(0, 0, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 160, mapTailSize.x, mapTailSize.y));
			}break;
			case 'T': {
				mapSprite.setTextureRect(sf::IntRect(32, 0, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 160, mapTailSize.x, mapTailSize.y));
			}break;
			case 'A': {
				mapSprite.setTextureRect(sf::IntRect(0, 32, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 160, mapTailSize.x, mapTailSize.y));
			}break;
			case 'R': {
				mapSprite.setTextureRect(sf::IntRect(32, 32, mapTailSize.x, mapTailSize.y));
				mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
				window->draw(mapSprite);
				mapSprite.setTextureRect(sf::IntRect(80, 160, mapTailSize.x, mapTailSize.y));
			}break;
			case 'E':

			case 'm': mapSprite.setTextureRect(sf::IntRect(0, 0, mapTailSize.x, mapTailSize.y)); break;
			case ',': mapSprite.setTextureRect(sf::IntRect(32, 0, mapTailSize.x, mapTailSize.y)); break;
			case '.': mapSprite.setTextureRect(sf::IntRect(0, 32, mapTailSize.x, mapTailSize.y)); break;
			case '/': mapSprite.setTextureRect(sf::IntRect(32, 32, mapTailSize.x, mapTailSize.y)); break;
			}
			mapSprite.setPosition(x * mapTailSize.x, y * mapTailSize.y);
			window->draw(mapSprite);
		}
	}
}

bool Map::isValidMove(int x, int y, char level[37][51]) {
	if (x < 0 || x >= 51 || y < 0 || y >= 37) {
		return false;
	}
	char symbol = level[y][x];

	return (symbol == 'f' || symbol == 'n' || symbol == '[' || symbol == ']' || symbol == 'S' || symbol == 'T' || symbol == 'A' || symbol == 'R' || symbol == 'v' || symbol == 'o' || symbol == 'i' || symbol == 'd' || symbol == 'V' || symbol == 'O' || symbol == 'I' || symbol == 'D');
}
bool Map::CheckTable(int x, int y, char level[37][51]){
	if (level[y][x] == '[' || level[y][x] == ']') {
		level[y][x] = 'f';
		mapArray[y][x] = 'f';
		return true;
	}
	return false;
}
void Map::openSecondLevel(char level[37][51]) {
	for (int y = 0; y < mapSize.y; y++) {
		for (int x = 0; x < mapSize.x; x++) {
			switch (mapArray[y][x]){
			case 'V': {
				mapArray[y][x] = 'v';
				level[y][x] = 'v';
			}  break;
			case 'O': {
				mapArray[y][x] = 'o';
				level[y][x] = 'o';
			}  break;
			case 'I': {
				mapArray[y][x] = 'i';
				level[y][x] = 'i';
			}  break;
			case 'D': {
				mapArray[y][x] = 'd';
				level[y][x] = 'd';
			}  break;
			}
		}
	}
}
void Map::openFinish(char level[37][51]){
	for (int y = 0; y < mapSize.y; y++) {
		for (int x = 0; x < mapSize.x; x++) {
			switch (mapArray[y][x]) {
			case 'V': {
				mapArray[y][x] = 'm';
				level[y][x] = 'm';
			}  break;
			case 'O': {
				mapArray[y][x] = ',';
				level[y][x] = ',';
			}  break;
			case 'I': {
				mapArray[y][x] = '.';
				level[y][x] = '.';
			}  break;
			case 'D': {
				mapArray[y][x] = '/';
				level[y][x] = '/';
			}  break;
			}
		}
	}
}
bool Map::goNext(int x, int y, char level[37][51]) {
	if (level[y][x] == 'v' || level[y][x] == 'o' || level[y][x] == 'i' || level[y][x] == 'd') {
		return true;
	}
	return false;
}
bool Map::showEnds(int x, int y, char level[37][51]){
	if (level[y][x] == 'm' || level[y][x] == ',' || level[y][x] == '.' || level[y][x] == '/') {
		return true;
	}
	return false;
}
char (*Map::getLevelName(int mapNumber))[51]{
	switch (mapNumber){
	case 1: {
		return level_1;
	}break;
	case 2: {
		return level_2;
	}break;
	}
}
sf::Vector2f Map::getScenaSize(){
	return sf::Vector2f(scenaSize);
}
