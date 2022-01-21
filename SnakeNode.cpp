#include <SFML/Graphics.hpp>

#include "SnakeNode.h"

using namespace sfSnake;

const float SnakeNode::Width = 20.f;//20.f
const float SnakeNode::Height = 20.f;//20.f
sf::Texture texture1;
sf::Texture texture2;

SnakeNode::SnakeNode(bool ishead,sf::Vector2f position)
: position_(position)
{
	texture1.loadFromFile("pictures/head.png");
	texture2.loadFromFile("pictures/body.png");
	//head.setPosition(position);
	rectan.setPosition(position);
	if(ishead)
	{
		//head.setTexture(texture1);		
		rectan.setTexture(texture1);
		//head.setOrigin(15, 10.5);
		//rectan.setOrigin(3, 3);
	}
	/*texture2.loadFromImage();
	/*rectan.setTexture(texture1);
	rectan.setPosition(position_);
	rectan.setColor(sf::Color::Green);
	shape_.setPosition(position_);
	shape_.setFillColor(sf::Color::White);
	shape_.setRadius(3);
	shape_.setOutlineColor(sf::Color::White);
	shape_.setOutlineThickness(-1.f);*/
	else{
		rectan.setTexture(texture2);
	}
}

void SnakeNode::setPosition(sf::Vector2f position)
{
	position_ = position;
	//shape_.setPosition(position_);
	rectan.setPosition(position_);
}

void SnakeNode::spritesetPosition(sf::Vector2f position)
{
	position_ = position;
	//shape_.setPosition(position_);
	head.setPosition(position);
}

void SnakeNode::setPosition(float x, float y)
{
	position_.x = x;
	position_.y = y;
	//shape_.setPosition(position_);
	rectan.setPosition(position_);
}

void SnakeNode::move(float xOffset, float yOffset)
{
	position_.x += xOffset;
	position_.y += yOffset;
	//shape_.setPosition(position_);
	rectan.setPosition(position_);
	
}

sf::FloatRect SnakeNode::getBounds() const
{
	return	rectan.getGlobalBounds();
}

sf::Vector2f SnakeNode::getPosition() const
{
	return position_;
}

void SnakeNode::render(sf::RenderWindow& window)
{
	//window.draw(shape_);
	window.draw(rectan);
}

void SnakeNode::rotate(float radian)
{
	rectan.rotate(radian);
}

float SnakeNode::getRadian() const
{
	return radian0_;
}

void SnakeNode::setRadian(float radian)
{
	radian0_ = radian;
}


void SnakeNode::createshape()
{
	sf::Image image;
	image.loadFromFile("pictures/head.png");
	//tex_.loadFromImage(image);
	//head.setTexture(tex_);
}