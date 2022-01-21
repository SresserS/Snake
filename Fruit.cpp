#include <SFML/Graphics.hpp>
#include <random>
#include "Fruit.h"

using namespace sfSnake;

sf::Texture BlackFruit;
sf::Texture BrownFruit;
sf::Texture RedFruit;
sf::Texture BlueFruit;
sf::Texture GreenFruit;
sf::Texture GEM;
sf::Texture BOMB;

const float Fruit::Radius = 5.f;//半径
Fruit::Fruit(sf::Vector2f position) //定义被吃的水果
{
	shape_.setPosition(position);
	/*shape_.setTexture(Fruit::Radius);
	shape_.setFillColor(sf::Color::Red);*/
	BlackFruit.loadFromFile("pictures/BlackFruit.png");
	BrownFruit.loadFromFile("pictures/BrownFruit.png");
	RedFruit.loadFromFile("pictures/RedFruit.png");
	BlueFruit.loadFromFile("pictures/BlueFruit.png");
	GreenFruit.loadFromFile("pictures/GreenFruit.png");
	BOMB.loadFromFile("pictures/BOMB.png");
	
}

int Fruit::getColor(){
	int x = rand()%9;
	//sf::Image image;
	//image.loadFromFile("pictures/BOMB.png");
	sf::Texture texture;
	texture.loadFromFile("pictures/BOMB.png");
	if(x==0) shape_.setTexture(BlackFruit);
	else if(x==1) shape_.setTexture(BrownFruit);
	else if(x==2||x==3) shape_.setTexture(RedFruit);
	else if(x==4||x==5) shape_.setTexture(BlueFruit);
	else if(x==6||x==7) shape_.setTexture(GreenFruit);
	else if(x==8) shape_.setTexture(BOMB);
	/*switch(x){
		case :shape_.setFillColor(sf::Color::Black);break;
		case :shape_.setFillColor(sf::Color::Yellow);break;//黄色代替棕色！！！
		case :shape_.setFillColor(sf::Color::Red);break;
		case :shape_.setFillColor(sf::Color::Blue);break;
		case :shape_.setFillColor(sf::Color::Green);break;
	};*/
	color_ = x;
	return x;
}

/*int Fruit::readColor()
{
	return color_;
}*/

void Fruit::render(sf::RenderWindow& window) //呈现水果
{
	window.draw(shape_);
}

sf::FloatRect Fruit::getBounds() const 
{
	return shape_.getGlobalBounds();
}