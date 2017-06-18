#include "stdafx.h"
#include "GWindow.h"

GWindow::GWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(600, 400), "Logomotive");
	loadFont();
	floatToString();
	setFrameText();
}

GWindow::~GWindow()
{
	delete window;
}

void GWindow::loadFont()
{
	if (!font.loadFromFile("BERNHC.TTF")) { ; };
}

void GWindow::floatToString()
{
	std::stringstream ss;
	ss << fps;
	fpsString = ss.str();
}

void GWindow::setFrameText()
{
	frameText.setFont(font);
	frameText.setPosition(530, 5);
	frameText.setCharacterSize(20);
}

void GWindow::setFrameString()
{
	floatToString();
	frameText.setString(fpsString);
}

void GWindow::windowStaff()
{
	sf::Clock clock;
	sf::Time time;

	window->setFramerateLimit(60);

	while (window->isOpen())
	{
		input();
		time = clock.getElapsedTime();;
		if (time.asSeconds() >= 1.0f / 60)
		{
			update();
			draw();
			fps = 1.0f / time.asSeconds();
			clock.restart();
		}
	}
}

void GWindow::input()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode != 13 && event.text.unicode != 38 && event.text.unicode != 8 && event.text.unicode != 27)
				cmdManager.writeIn(event.text.unicode);
		}
				

		if (event.type == sf::Event::KeyPressed && event.key.code  == sf::Keyboard::Up)
		{ 
				//cmdManager.readFromTable();
				commandBox.setString(cmdManager.readFromTable());	
		}
				
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
		{
			cmdManager.command = commandBox.getString();
			cmdManager.checkCommand();

			if(cmdManager.isGood)
				cmdManager.writeInTable();
		}
			
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSpace)
			commandBox.writeBack();

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			commandBox.clearAll();
	}
}

void GWindow::update()
{
	setFrameString();
}

void GWindow::draw()
{
	window->clear(sf::Color::Black);
	window->draw(commandBox);
	window->draw(frameText);
	window->draw(point);
	window->display();
}
