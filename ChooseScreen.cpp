#include <SFML/Graphics.hpp>

#include <memory>

#include "GameScreen.h"
#include "ChooseScreen.h"
#include "Game.h"

using namespace sfSnake;

int ChooseScreen::flag = 0;
int ChooseScreen::flag2 = 0;
int ChooseScreen::flag3 = 0;

ChooseScreen::ChooseScreen()
{
	font_.loadFromFile("Fonts/game_over.ttf");
	backgtext.setFont(font_);
	backgtext.setString(
		"\n\nChoose the color of background\n\tA.White B.Black C.Brown");
	backgtext.setColor(sf::Color::Blue);
	backgtext.setCharacterSize(20);
	//backgtext.setStyle(sf::Text::Bold);

	gridtext.setFont(font_);
	gridtext.setString("\n\tWhether to use grid or not?\nY.use N.not use(Directly Into Game)");
	gridtext.setColor(sf::Color::Green);
	gridtext.setCharacterSize(20);
	//gridtext.setStyle(sf::Text::Bold);

	gridcolor.setFont(font_);
	gridcolor.setString("\nChoose the color of grid\nQ.White W.Black E.Brown");
	gridcolor.setColor(sf::Color::Green);
	gridcolor.setCharacterSize(20);
	//gridcolor.setStyle(sf::Text::Bold);

	text_.setFont(font_);
	text_.setString(
		"\nPress [SPACE] to play"
		"\nPress [ESC] to quit");
	text_.setColor(sf::Color::Green);
	text_.setCharacterSize(20);
	//text_.setStyle(sf::Text::Bold);

	sf::FloatRect textBounds = backgtext.getLocalBounds();
	backgtext.setOrigin(textBounds.left + textBounds.width / 2,
		textBounds.top + textBounds.height / 2);
	backgtext.setPosition(Game::Width/2, 50);

	sf::FloatRect gridTextBounds = gridtext.getLocalBounds();
	gridtext.setOrigin(gridTextBounds.left + gridTextBounds.width / 2,
		gridTextBounds.top + gridTextBounds.height / 2);
	gridtext.setPosition(Game::Width/2, 150);

	sf::FloatRect gridColorBounds = gridcolor.getLocalBounds();
	gridcolor.setOrigin(gridColorBounds.left + gridColorBounds.width / 2,
		gridColorBounds.top + gridColorBounds.height / 2);
	gridcolor.setPosition(Game::Width/2,250);

	sf::FloatRect textBounds2 = text_.getLocalBounds();
	text_.setOrigin(textBounds2.left + textBounds2.width / 2,
		textBounds2.top + textBounds2.height / 2);
	text_.setPosition(Game::Width / 2, 350);

}

/*int ChooseScreen::getflag(int x){
	return x;
}*/

void ChooseScreen::handleInput(sf::RenderWindow& window)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		//Game::Screen = std::make_shared<GameScreen>();
		flag=1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		flag=2;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		flag=3;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		flag2=5;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{flag2=6;Game::Screen = std::make_shared<GameScreen>();}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		flag3=7;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		flag3=8;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		flag3=9;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Game::Screen = std::make_shared<GameScreen>();

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
}

void ChooseScreen::update(sf::Time delta)
{
}

void ChooseScreen::render(sf::RenderWindow& window)
{
	window.draw(backgtext);
	window.draw(gridtext);
	window.draw(gridcolor);
	window.draw(text_);
}