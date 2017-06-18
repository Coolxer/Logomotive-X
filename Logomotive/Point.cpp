#include "stdafx.h"
#include "Point.h"

Point::Point()
{
	circle = new sf::CircleShape;
	setCircle();
}

Point::~Point()
{
	delete circle;
}

void Point::setCircle()
{
	circle->setFillColor(sf::Color::White);
	circle->setPosition(380, 180);
	circle->setRadius(20);
}

void Point::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*circle, states);
}
