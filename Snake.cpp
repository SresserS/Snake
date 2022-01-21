#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>
#include <cmath>

#include "Snake.h"
#include "Game.h"
#include "Fruit.h"
#include "SnakeNode.h"
#include "GameOverScreen.h"
#include "GameScreen.h"

using namespace sfSnake;

const int Snake::InitialSize = 5;

Snake::Snake() : direction_(Direction::Up), hitSelf_(false)
{
	initNodes();

	pickupBuffer_.loadFromFile("Sounds/pickup.aiff");
	pickupSound_.setBuffer(pickupBuffer_);
	pickupSound_.setVolume(30);

	dieBuffer_.loadFromFile("Sounds/die.wav");
	dieSound_.setBuffer(dieBuffer_);
	dieSound_.setVolume(50);
}

void Snake::initNodes()
{
	bool ishead;
	for (int i = 0; i < Snake::InitialSize; ++i)
	{
		if(i==0){ishead = true;}
		else {ishead = false;}
		/*if(i==0){
			//nodes_[0].spritesetPosition(pos);
			//sf::Texture tex;tex.loadFromFile("pictures/head.png");
			nodes_[0].createshape();
		}*/
		nodes_.push_back(SnakeNode(ishead,sf::Vector2f(
		Game::Width / 2 - SnakeNode::Width / 2,
		Game::Height / 2 - (SnakeNode::Height / 2) + (SnakeNode::Height * i))));
	}
}

void Snake::handleInput(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		direction_ = Direction::Up;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		direction_ = Direction::Down;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		direction_ = Direction::Left;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		direction_ = Direction::Right;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		position = sf::Mouse::getPosition(window);
		float x=position.x - nodes_[0].getPosition().x;
		float y=position.y - nodes_[0].getPosition().y;
		vec.x=SnakeNode::Width * x / sqrt(x*x+y*y);
		vec.y=SnakeNode::Height * y / sqrt(x*x+y*y);
		direction_ = Direction::Vector;
		/*if((sf::Mouse::getPosition().y-nodes_[0].getPosition().y) / (sf::Mouse::getPosition().x-nodes_[0].getPosition().x)<=1
			&& (sf::Mouse::getPosition().y-nodes_[0].getPosition().y) / (sf::Mouse::getPosition().x-nodes_[0].getPosition().x)>=-1)
		{
			if(sf::Mouse::getPosition().x-nodes_[0].getPosition().x > 0)
				vec = sf::Vector2f(5, 5 * (sf::Mouse::getPosition().y-nodes_[0].getPosition().y) / (sf::Mouse::getPosition().x-nodes_[0].getPosition().x));
			else
				vec = sf::Vector2f(-5, -5 * (sf::Mouse::getPosition().y-nodes_[0].getPosition().y) / (sf::Mouse::getPosition().x-nodes_[0].getPosition().x));
		}
		else
		{
			if(sf::Mouse::getPosition().y-nodes_[0].getPosition().y > 0)
				vec = sf::Vector2f(5 * (sf::Mouse::getPosition().x-nodes_[0].getPosition().x) / (sf::Mouse::getPosition().y-nodes_[0].getPosition().y), 5);
			else
				vec = sf::Vector2f(-5 * (sf::Mouse::getPosition().x-nodes_[0].getPosition().x) / (sf::Mouse::getPosition().y-nodes_[0].getPosition().y), -5);
		 
		}
		direction_ = Direction::Vector;*/
	}

}

void Snake::update(sf::Time delta)
{
	move();
	checkEdgeCollisions();
	checkSelfCollisions();
}

void Snake::checkFruitCollisions(std::vector<Fruit>& fruits)
{
	decltype(fruits.begin()) toRemove = fruits.end();
	auto it = fruits.begin();
	for (int i=0; it != fruits.end(); ++it) //auto& it =  
	{
		if (it->getBounds().intersects(nodes_[0].getBounds()))
			break;
			//toRemove = it;
	}

	if (/*toRemove != fruits.end()*/ it !=fruits.end())
	{
		pickupSound_.play();
		int x = it->color_;
		if(x==0||x==1);
		else if(x==2||x==3){
			grow();grow();grow();
		}
		else if(x==4||x==5){
			grow();grow();
		}
		else if(x==6||x==7){
			grow();
		}
		else if(x==8){
			dieSound_.play();
			sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
			hitSelf_ = true;
		}
		/*switch (x)
		{
			case 0:;break;
			case 1:;break;
			case 2:{grow();grow();grow();}break;
			case 3:{grow();grow();}break;
			case 4:{grow();}break;
		default:
			break;
		} */
		//grow();
		fruits.erase(it);
	}
}

void Snake::grow()
{
	bool ishead = false;
	switch (direction_)
	{
	case Direction::Up:
		nodes_.push_back(SnakeNode(ishead,sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x,
			nodes_[nodes_.size() - 1].getPosition().y + SnakeNode::Height)));
		break;
	case Direction::Down:
		nodes_.push_back(SnakeNode(ishead,sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x,
			nodes_[nodes_.size() - 1].getPosition().y - SnakeNode::Height)));
		break;
	case Direction::Left:
		nodes_.push_back(SnakeNode(ishead,sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x + SnakeNode::Width,
			nodes_[nodes_.size() - 1].getPosition().y)));
		break;
	case Direction::Right:
		nodes_.push_back(SnakeNode(ishead,sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x - SnakeNode::Width,
			nodes_[nodes_.size() - 1].getPosition().y)));
		break;
	case Direction::Vector:
		nodes_.push_back(SnakeNode(ishead,sf::Vector2f(nodes_[nodes_.size() - 1].getPosition().x + vec.x,
			nodes_[nodes_.size() - 1].getPosition().y + vec.y)));
			break;
	}
}

unsigned Snake::getSize() const
{
	return nodes_.size();
}

bool Snake::hitSelf() const
{
	return hitSelf_;
}

void Snake::checkSelfCollisions()
{
	SnakeNode& headNode = nodes_[0];

	for (decltype(nodes_.size()) i = 1; i < nodes_.size(); ++i)
	{
		if (headNode.getBounds().intersects(nodes_[i].getBounds()))
		{
			dieSound_.play();
			sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
			hitSelf_ = true;
		}
	}
}

/*void Snake::checkEdgeCollisions()
{
	SnakeNode& headNode = nodes_[0];

	if (headNode.getPosition().x <= 0)
		headNode.setPosition(Game::Width, headNode.getPosition().y);
	else if (headNode.getPosition().x >= Game::Width)
		headNode.setPosition(0, headNode.getPosition().y);
	else if (headNode.getPosition().y <= 0)
		headNode.setPosition(headNode.getPosition().x, Game::Height);
	else if (headNode.getPosition().y >= Game::Height)
		headNode.setPosition(headNode.getPosition().x, 0);
}*/
void Snake::checkEdgeCollisions()
{
	SnakeNode& headNode = nodes_[0];
	if (headNode.getPosition().x <= 0 || headNode.getPosition().x >= Game::Width || headNode.getPosition().y <= 0 || headNode.getPosition().y >= Game::Height)
	{
		std::cout << headNode.getPosition().x << ", " << headNode.getPosition().y << std::endl;
		dieSound_.play();
		sf::sleep(sf::seconds(dieBuffer_.getDuration().asSeconds()));
		hitSelf_ = true;
	}
}

void Snake::move()
{
	for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
	{
		nodes_[i].setPosition(nodes_.at(i - 1).getPosition());
	}

	switch (direction_)
	{
	case Direction::Up:
		nodes_[0].move(0, -SnakeNode::Height);
		break;
	case Direction::Down:
		nodes_[0].move(0, SnakeNode::Height);
		break;
	case Direction::Left:
		nodes_[0].move(-SnakeNode::Width, 0);
		break;
	case Direction::Right:
		nodes_[0].move(SnakeNode::Width, 0);
		break;
	case Direction::Vector:
		nodes_[0].move(vec.x,vec.y);
	}

}


/*void Snake::vec_move(sf::Vector2f& vec_){
	float radian = std::atan2(vec_.y, vec_.x) / acos(-1) * 180;
	/*if(nodes_[0].getRadian() != radian)
	{
		nodes_[0].rotate(radian - nodes_[0].getRadian());
		nodes_[0].setRadian(radian);
	}
	for (decltype(nodes_.size()) i = nodes_.size() - 1; i > 0; --i)
	{
		nodes_[i].setPosition(nodes_.at(i - 1).getPosition());
		
		if(nodes_[i].getRadian() != nodes_[i-1].getRadian())
		{
			nodes_[i].rotate(nodes_[i-1].getRadian() - nodes_[i].getRadian());
			nodes_[i].setRadian(nodes_[i-1].getRadian());
		}
	}
}*/

void Snake::render(sf::RenderWindow& window)
{
	for (auto node : nodes_) //auto node
		node.render(window);
}