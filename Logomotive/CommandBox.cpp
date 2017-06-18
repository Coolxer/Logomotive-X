#include "stdafx.h"
#include "CommandBox.h"

CommandBox::CommandBox()
{
	rectangle = new sf::RectangleShape;
	smallRectangle = new sf::RectangleShape;
	setRectangle();
	setSmallRectangle();
	setText();
}

CommandBox::~CommandBox()
{
	delete rectangle;
	delete smallRectangle;
}

void CommandBox::setRectangle()
{
	rectangle->setPosition(2,2);
	rectangle->setSize(sf::Vector2f(200, 396));
	rectangle->setFillColor(sf::Color::Black);
	rectangle->setOutlineThickness(2);
	rectangle->setOutlineColor(sf::Color::White);
}

void CommandBox::setSmallRectangle()
{
	smallRectangle->setPosition(4, 370);
	smallRectangle->setSize(sf::Vector2f(196, 26));
	smallRectangle->setFillColor(sf::Color::Black);
	smallRectangle->setOutlineThickness(2);
	smallRectangle->setOutlineColor(sf::Color::Red);
}

void CommandBox::loadFont()
{
	if (!font.loadFromFile("BERNHC.TTF")) { ; }
}

void CommandBox::setText()
{
	loadFont();
	commandText.setFont(font);
	commandText.setCharacterSize(20);
	commandText.setPosition(6, 375);
}

void CommandBox::updateText()
{
	commandText.setString(commandString);
}

sf::String CommandBox::getString()
{
	return commandText.getString();
}

void CommandBox::setString(std::string a)
{
	commandText.setString(a);
}

void CommandBox::writeIn(char unicode)
{
	commandString.insert(commandString.getSize(), unicode);
	updateText();
}

void CommandBox::writeBack()
{
	if (commandString.getSize() >= 1)
		commandString.erase(commandString.getSize() - 1);
	updateText();
}

void CommandBox::clearAll()
{
	commandString.clear();
	updateText();
}

void CommandBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*rectangle, states);
	target.draw(*smallRectangle, states);
	target.draw(commandText, states);
}
