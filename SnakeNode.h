#ifndef SNAKE_NODE_H
#define SNAKE_NODE_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
class SnakeNode
{
public:
	SnakeNode(bool ishead,sf::Vector2f position = sf::Vector2f(0, 0));

	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	void move(float xOffset, float yOffset);


	sf::Vector2f getPosition() const;
	sf::FloatRect getBounds() const;
	sf::FloatRect getInnerBounds() const;

	void createshape(/*sf::Vector2f position = sf::Vector2f(0, 0)*/);

	static const float Width;
	static const float Height;
	
	void rotate(float radian);
	void render(sf::RenderWindow&);

	float getRadian() const;
	void setRadian(float radian);
	void spritesetPosition(sf::Vector2f position);

private:
	sf::Sprite rectan;
	//sf::CircleShape shape_;
	sf::Vector2f position_;
	sf::Sprite head;
	float radian0_;
};
};

#endif