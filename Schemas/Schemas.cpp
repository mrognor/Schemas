﻿// Schemas.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <SFML/Graphics.hpp>

#include "SchemasFunctions.h"
#include "DropDownListWidget.h"
#include "DropDownListElementWidget.h"
#include "DragAndDropWidget.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML Works!");
	window.setFramerateLimit(60);

	DragAndDropWidget d(&window);
	DropDownListWidget f(&window, &d, 400, 800);
	d.setWindowDropDownList(&f);

	while (window.isOpen())
	{
		window.clear(sf::Color(128, 128, 128));
		sf::Event event;

		while (window.pollEvent(event))
		{
			f.InputHandler(event);
			d.InputHandler(event);

			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		f.Tick();
		d.Tick();
		window.display();
	}


	return 0;
}


