#ifndef CHOOSE_SCREEN_H
#define CHOOSE_SCREEN_H

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace sfSnake
{
class ChooseScreen : public Screen
{
public:
	ChooseScreen();

	void handleInput(sf::RenderWindow& window) override; //重写函数
	void update(sf::Time delta) override; //重写函数
	void render(sf::RenderWindow& window) override; //重写函数
	//int getflag(int x);
	static int flag,flag2,flag3;

private:
    sf::Font font_;
	sf::Text backgtext,gridtext,gridcolor;
	sf::Text text_;
};
}

#endif