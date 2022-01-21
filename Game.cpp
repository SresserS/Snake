#include <SFML/Graphics.hpp>

#include <memory>

#include "MenuScreen.h"
#include "Game.h"
#include "ChooseScreen.h"
#include "GameScreen.h"

using namespace sfSnake;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 10.f); //一帧时间为0.1s

std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();


Game::Game()
: window_(sf::VideoMode(Game::Width, Game::Height), "sfSnake") 
{
	bgMusic_.openFromFile("Music/bg_music.wav"); //导入BGM文件
	bgMusic_.setLoop(true); //循环模式
	bgMusic_.play(); //播放
}

void Game::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}

	Game::Screen->handleInput(window_);
}

void Game::update(sf::Time delta)
{
	Game::Screen->update(delta);
}

void Game::render() //游戏呈现函数
{
	int usegrid=0;
	window_.clear();
	//shader_.setUniform("color",sf::Glsl::Vec4(sf::Color::White));
	states.shader =  &shader_;
	if(ChooseScreen::flag==1){
		image1.create(640.f, 480.f, sf::Color::White);	texture1.loadFromImage(image1);
	sprite.setTexture(texture1);window_.draw(sprite,states);}
	else if(ChooseScreen::flag==2){
		image1.create(640.f, 480.f, sf::Color::Black);	texture1.loadFromImage(image1);
	sprite.setTexture(texture1);window_.draw(sprite,states);}	
	else if(ChooseScreen::flag==3){
		image1.create(640.f, 480.f, sf::Color(128,64,0,255));	texture1.loadFromImage(image1);
	sprite.setTexture(texture1);window_.draw(sprite,states);}
	else {image1.create(640.f, 480.f, sf::Color::Black);	texture1.loadFromImage(image1);
	sprite.setTexture(texture1);window_.draw(sprite,states);}

	switch (ChooseScreen::flag2)
	{
	case 5:usegrid=1;break;
	case 6:usegrid=0;break;
	}

	if(usegrid==1&&(ChooseScreen::flag==1||ChooseScreen::flag==2||ChooseScreen::flag==3)){
		switch (ChooseScreen::flag3)
		{
		case 7:image2.loadFromFile("pictures/WhiteGrid.png");	texture2.loadFromImage(image2);
		sprite.setTexture(texture2);window_.draw(sprite,states);break;
		case 8:image2.loadFromFile("pictures/BlackGrid.png");	texture2.loadFromImage(image2);
		sprite.setTexture(texture2);window_.draw(sprite,states);break;
		case 9:image2.loadFromFile("pictures/BrownGrid.png");	texture2.loadFromImage(image2);
		sprite.setTexture(texture2);window_.draw(sprite,states);break;
		}
	}




	//texture.loadFromImage(image);
	//sprite.setTexture(texture);
	//window_.draw(sprite,states);
	Game::Screen->render(window_);
	window_.display();
}



void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero; 

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}