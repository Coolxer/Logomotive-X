#pragma once
#include <SFML\Graphics.hpp>
class Point: public sf::Drawable
{
public:
	Point();
	~Point();
private:
	sf::CircleShape* circle;
	void setCircle();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

