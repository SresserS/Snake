#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
class Fruit //水果类
{
public:
	Fruit(sf::Vector2f position = sf::Vector2f(0, 0)); //水果位置 

	void render(sf::RenderWindow& window); //呈现水果

	sf::FloatRect getBounds() const; //边界函数
	int getColor();
	int readColor();
	int color_;
private:
	//sf::CircleShape shape_; //水果形状
	sf::Sprite shape_;
	static const float Radius;  //水果半径
};
}

#endif