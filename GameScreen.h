#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"
#include "Snake.h"
#include "Fruit.h"

namespace sfSnake
{
class GameScreen : public Screen
{
public:
	GameScreen();

	void handleInput(sf::RenderWindow& window) override; //重写函数
	void update(sf::Time delta) override; //重写函数
	void render(sf::RenderWindow& window) override; //重写函数

	int generateFruit();
private:
	Snake snake_;
	std::vector<Fruit> fruit_;
};
}

#endif