#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "Game.h"
#include "GameScreen.h"
#include "GameOverScreen.h"

using namespace sfSnake;

GameOverScreen::GameOverScreen(std::size_t score) : score_(score)
{
	font_.loadFromFile("Fonts/game_over.ttf"); //字体文件
	text_.setFont(font_);//设置字体
	text_.setString("Your score: " + std::to_string(score) + "!"
		"\n\nPress [SPACE] to retry"
		"\n\nPress [ESC] to quit");//文本内容
	text_.setColor(sf::Color::Red); //文本颜色

	sf::FloatRect textBounds = text_.getLocalBounds(); ////文本边界
	text_.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2); //设置原点
	text_.setPosition(Game::Width / 2, Game::Height / 2); //文字坐标位置
}

void GameOverScreen::handleInput(sf::RenderWindow& window) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) //按照要求按键盘 空格
		Game::Screen = std::make_shared<GameScreen>();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //其他键窗口关闭
		window.close();
}

void GameOverScreen::update(sf::Time delta) 
{

}

void GameOverScreen::render(sf::RenderWindow& window)//呈现
{
	window.draw(text_);
}