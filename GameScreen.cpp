#include <SFML/Graphics.hpp>
#include <time.h>
#include <random>
#include <memory>

#include "GameScreen.h"
#include "GameOverScreen.h"
#include "Game.h"

using namespace sfSnake;

GameScreen::GameScreen() : snake_()	//？
{

}

void GameScreen::handleInput(sf::RenderWindow& window) //处理窗口？
{
	snake_.handleInput(window);
}

void GameScreen::update(sf::Time delta) //画面更新
{
	if (fruit_.size() <= 5)
		generateFruit();//产生水果

	snake_.update(delta); //更新蛇
	snake_.checkFruitCollisions(fruit_); //水果是否重复在一个位置出现 是和前一个比吗？

	if (snake_.hitSelf()) //如果自我碰撞
		Game::Screen = std::make_shared<GameOverScreen>(snake_.getSize()); //make_shared创建动态内存初始化
		//并返回shared_ptr,多个指针可以指向同一块内存
}

void GameScreen::render(sf::RenderWindow& window)
{
	snake_.render(window);

	for (auto fruit : fruit_)
		fruit.render(window);
}

int GameScreen::generateFruit()
{
	static std::default_random_engine engine; 
	//engine.seed(time(NULL)); 
	//static std::uniform_int_distribution<int> xDistribution(0, Game::Width);
	static int xDistribution;
	static int yDistribution;
	yDistribution = rand()%(Game::Height);
	xDistribution = rand()%(Game::Height);
	fruit_.push_back(Fruit(sf::Vector2f(xDistribution, yDistribution)));
	int x = (fruit_.end()-1)->getColor();
	return x;
}

