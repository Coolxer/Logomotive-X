#pragma once
#include <SFML\Graphics.hpp>
#include "MemoryManager.h"

class CommandBox: public sf::Drawable, public: MemoryManager
{
public:
	CommandBox();
	~CommandBox();

	void writeIn(char unicode);
	void writeBack();
	void clearAll();
	sf::String getString();
	void setString(std::string a);

private:
	sf::RectangleShape* rectangle;
	sf::RectangleShape* smallRectangle;
	void setRectangle();
	void setSmallRectangle();

	sf::Font font;
	sf::Text commandText;
	sf::String commandString;
	void loadFont();
	void setText();
	void updateText();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
};

