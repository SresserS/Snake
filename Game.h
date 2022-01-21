#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <memory>

#include "Screen.h"

namespace sfSnake
{
class Game
{
public:
	Game();

	void run();

	void handleInput();
	void update(sf::Time delta);
	void render();
	//void change();

	static const int Width = 640; //画面宽度
	static const int Height = 480; //画面高度

	static std::shared_ptr<Screen> Screen; 

private:
	sf::RenderWindow window_; //窗口界面？
	sf::Music bgMusic_;
	sf::Shader shader_;
	sf::RenderStates states;
	sf::Sprite sprite;
	sf::Texture texture1,texture2;
	sf::Image image1,image2;
	static const sf::Time TimePerFrame; //全局变量

	sf::Sprite grids_;

};
}


#endif