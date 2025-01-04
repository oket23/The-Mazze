#pragma once
#include "SFML/Graphics.hpp"

class Map {
public:
	sf::Vector2i mapSize;
	sf::Vector2i mapTailSize = { 16,16 };
	sf::Vector2f scenaSize;
	char** mapArray = nullptr;
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;

	char level_1[37][51] = {
		{"1wwww6w6wwwwwwwwwwwwwwwwwwwwww6wwwwwwwwwwwwwwwwww2"},
		{"xSTffx xffffffffffffffffffffffxffffffffffffffffffx"},
		{"xARffx xffffffffffffffffffffffxffffffffffffffffffx"},
		{"7w5ffx xff1wwwwww9ff1wwwwwwwww0ff1wwwwwwww6www9ffx"},
		{"x xnnx xffx      xffxffffffffffffxffffffffxfffxffx"},
		{"x xffx xffx      xffxffffffffffffxf1w9fzffxfzfxffx"},
		{"x xffx xffx      xffxff1wwwwwwwww0fxfxfxffxfxfxffx"},
		{"x xffx xffx      xffxffxfffffffffffxfxfxffxfxfcffx"},
		{"x xffx xffx      xffxffxf1www6www9fxfxfxffcfxffffx"},
		{"x xffx xffx      xffxffxfxfffxfffxfxfxfxffffxffffx"},
		{"x xffx xffx      xffxffxfxfzfxfzfxfxfxfxffqwLwwww:"},
		{"x xff8w0ffx      xffxffKw0fxfcfxfcfxfcfxfffffffffx"},
		{"x xfffffffx      xffxffx]ffxfffxfffxfffxff1wwww9fx"},
		{"x xfffffffx      xffxff8wwwLwwwLwwwLwww:ffxffffxfx"},
		{"7wLwwww9ffx      xffxffffffffffffffffffxffxffzfxfx"},
		{"xffffffxffx      xffxffffffffffffffffffxffxffxfxfx"},
		{"xffffffxffx      xffxff1w6wwwwwwwwwweffxffxffxfxfx"},
		{"xff1w9fxffx      xffxffx]xfffffffffffffxffKww0fxfx"},
		{"xffx[cfxffx      xffxffxfxf1wwwww6wwwww:ffxffffxfx"},
		{"xffxfffxffx      xffxffxfxfxfffffxfffffxffxffzfxfx"},
		{"xff8www0ff8wwwwww0ffcffxfxfxffzffxffzffcffxffxfxfx"},
		{"xffffffffffffffffffffffxf8w0ffxffcffxfffffxffxfxfx"},
		{"xffffffffffffffffffffffxffffffxfffffxfffffxffxfxfx"},
		{"xff1wwwwwww9fff1wwwwwwwLwwwwwwLwwww6Lwwwww:ffxfxfx"},
		{"xffxfffffffxfffxfffffffffffffffffffxffffffxffxfxfx"},
		{"xffxf1wwwefxfffxfffffffffffffffffffxff19ffxffxfxfx"},
		{"xffxfx[ffffxfffxff1wwww6www6wwww9ffxffxxff8ww0fxfx"},
		{"xffxf8wwwww0fffxffx]fffxfffcffffxffxffxxfffffffxfx"},
		{"xffxfffffffffffxffKwwefxfzfffzffxffxffxxfffffffxfx"},
		{"xff8wwwwwww9fffcffxffffxf8wwwLww0ffxff8Lww6wwww:fx"},
		{"xffffffffffxffffffxfqww:fffffffffffxffffffxffffxfx"},
		{"xffffffffffxffffffxffffxfffffffffffxff19ffKwwefcfx"},
		{"xff1wwwww6w`wwwwww`ww9fxf1wwwww6www0ffxxffxffffffx"},
		{"xffxfffffx xffffffx  xfxfxfffffxffffffxxff8wwwwww:"},
		{"xffcffzff8w0f1w9ff8ww0fxfcfzfffcfffzffxxfffffffVOx"},
		{"xfffffxffffffx xfffffffxfffxfffffffxffxxfffffffIDx"},
		{"3wwwwwLwwwwwwLwLwwwwwwwLwwwLwwwwwwwLwwLLwwwwwwwww4"},
	};
	char level_2[37][51] = {
		{"1ww6wwwwwwwwwwwwwwwwwwwwwww6ww6wwwwwwwwwwww6wwwww2"},
		{"xSTxfffffffffffffffffffffffxffxffffffffffffxfffffx"},
		{"xAR7wwwwwwwwwwwwwwwwwwwwwww0ff8wwwwwwwwwwww0ffzffx"},
		{"xffxffffffffffffffffffffffffffffffffffffffffffxffx"},
		{"xffcf1wwwwwwww9ff1wwwwwwwwwwwwwwwwwwwwwwwwwwww:ffx"},
		{"xffffxffffffffxffxffffffffffffffffffffffffffffxffx"},
		{"7wwww:ffffffff7ww:ffffffffffffffffffffffffffffxffx"},
		{"xffffxffffffffxffxffffffffffffffffffffffffffffxffx"},
		{"7wwwwLwwwwwwww0ff8wwwwwwwwwwwwwwwwwwwwwwwwwwww:ffx"},
		{"xfffffffffffffffffffffffffffffffffffffffffffffxffx"},
		{"xff1wwwwwwwwwwwwwwwwwwwwwww9ff1wwwwwwwwwwww9ffcffx"},
		{"xffxfffffffffffffffffffffffxffxffffffffffffxfffffx"},
		{"xffxfffffffffffffffffffffffxffxffffffffffffxfffffx"},
		{"xff7wwwww6wwwww6wwwwwwwwwwwLwwLwwwww6w6www6L6wwww:"},
		{"xffxfffffxfffffxffffffffffffffffffffxfxfffxfxffffx"},
		{"xffxf1w9fxf1w9fxffqwwwwwwwwwwwwwww9fxfxfzfxfxffffx"},
		{"xffxfxfxfxfxfxfxffffffffffffffffffxfxfxfxfxfxfzffx"},
		{"xffxfxfxfxfxfxf7wwwwwwwwwwwwwwweffxfxfxfxfxfxfxffx"},
		{"xffxfxfxfxfxfxfxffffffffffffffffffxfxfxfxfxfxfxffx"},
		{"xffxf860fxf860fxffqwwwwwwwwwwwwwww:f860fxf860fxffx"},
		{"xffxffxffxffxffxffffffffffffffffffxffxffxffxffxffx"},
		{"xffxffxffxffxff7wwwwwwwwwwwwwwweffxffxffxffxffxffx"},
		{"xffxf1L9fxf1L9fxffffffffffffffffffxf1L9fxf1L9fxffx"},
		{"xffxfxfxfxfxfxfxffqwwwwwwwwwwwwwww:fxfxfxfxfxfxffx"},
		{"xffxfxfxfxfxfxfxffffffffffffffffffxfxfxfxfxfxfxffx"},
		{"xffcfxfxfcfxfxf8wwwwwwwwwwwwwwweffxf8w0fxf8w0fxffx"},
		{"xffffxfxfffxfxffffffffffffffffffffxfffffxfffffxffx"},
		{"7wwwwLwLwwwLwL6wwww6www6www6www6wwL6www6Lww6ww0ffx"},
		{"xfffffffffffffxffffxfffxfffxfffxfffxfffxfffxfffffx"},
		{"xfffffffffffffxffzfxfzfxfzfxfzfxfzfxfzfxfzfxfffffx"},
		{"xffqwwwwwww9ffxffxfxfxfxfxfxfxfxfxfxfxfxfxfxffzffx"},
		{"xffffffffffxffxffxfcfxfcfxfcfxfcfxfcfxfcfxfcffxffx"},
		{"xffffffffffxffxffxfffxfffxfffxfffxfffxfffxffffxffx"},
		{"7wwwwwwweffxffcff7wwwLwwwLwwwLwwwLwwwLwwwLwwww0ffx"},
		{"xVOffffffffxfffffx[ffffffffffffffffffffffffffffffx"},
		{"xIDffffffffxfffffxfffffffffffffffffffffffffffffffx"},
		{"3wwwwwwwwwwLwwwwwLwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww4"},
	};

	Map(std::string mapFileName);
	~Map();
	
	void loadMap(std::string mapFileName);
	void draw(sf::RenderWindow* window);
	sf::Vector2f getScenaSize();

	bool isValidMove(int x, int y, char level[37][51]);
	bool CheckTable(int x, int y, char level[37][51]);
	void openSecondLevel(char level[37][51]);
	void openFinish(char level[37][51]);
	bool goNext(int x, int y, char level[37][51]);
	bool showEnds(int x, int y, char level[37][51]);
	char (*getLevelName(int mapNumber))[51];
};
