#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>
#include <iostream>

#include "CommandBox.h"
#include "CmdManager.h"
#include "Point.h"

class GWindow
{
public:
	GWindow();
	~GWindow();

	void windowStaff();
private:
	sf::RenderWindow* window;
	//Section "Managment functions"
	void input();
	void update();
	void draw();
	//End of section "Managment functions"

	// Section "show fps on screen"
	sf::Font font;
	sf::Text frameText;
	void loadFont();
	void setFrameText();
	void setFrameString();

	float fps;
	std::string fpsString;
	void floatToString();
	//End of section "show fps on screen"

	//Section "creating main objects"
	CmdManager cmdManager;
	Point point;
	//End of section "creating main objects"
};

