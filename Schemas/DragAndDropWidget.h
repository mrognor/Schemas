#pragma once

#include "SchemasClasses.h"
#include "DropDownListWidget.h"
#include "DropDownListElementWidget.h"

/// ������ ������ ������������ �� ����������. ��������� 
/// ��������� ������� setWindowDropDownList
class DragAndDropWidget
{
private:
	/// ���������� ��� ���� � ������� ����������� �������� DragAndDrop
	sf::RenderWindow* DragAndDropWidgetWindow;

	/// ����������-���������(RectangleShape) ��� ����������� ������� ��� �������������� �����
	sf::RectangleShape* DragAndDropWidgetShape;

	/// ����� 
	sf::Font font;

	/// ����������-���������(Text) ��� ����������� ������� ��� �������������� �����
	sf::Text* DragAndDropWidgetText;

	/// ���������� ������ �������������� 
	sf::Vector2f DragStartCoords;

	/// ���������� ���������� ��� ����������� ��������� �������(DropDownListElementWidget).
	/// ���������� ���������� ���� �� �������� �������������� 
	bool IsDragAndDropInProcess = false;

	
	/// ���������� ��� ������������ �������(DropDownListElementWidget)
	/// ��������� �� ������ ��� �������� � ������ ������ ����������� �������� DragAndDrop
	DropDownListElementWidget* CurrentDropDownListElement = nullptr;

	/// ���������� ��� ������������ �������(DropDownListWidget)
	/// ��������� �� ������ ������� �������� ������� ������� ���� � ������ ������ �������
	DropDownListWidget* WindowDropDownList;

public:
	/// ������ ������ ������������ �� ���������� ��� ������ ���������. ��������� ������������
	/// setWindowDropDownList ��� ���������� ������ ���������
	DragAndDropWidget(sf::RenderWindow* dragAndDropWidgetWindow);

	void Tick();

	/// ���������� ����� 
	void InputHandler(sf::Event event);

	/// ������� ��� ��������� WindowDropDownList
	void setWindowDropDownList(DropDownListWidget* windowDropDownList) { WindowDropDownList = windowDropDownList; }

	/// ������� ��� ������ DragAndDrop ��������. ��������� DropDownListElementWidget ��� �������� ���������� ��������
	void StartDragAndDropOperation(DropDownListElementWidget* currentDropDownListElement);
	
	/// ������� ��� ��������� ��������� ��������������
	bool getIsDragAndDropInProcess() { return IsDragAndDropInProcess; }

	/// ������� ��� ��������� ��������� ������ ��������������
	sf::Vector2f getDragStartCoords() { return DragStartCoords; }

	/// ������� ��� �������� DropDownListElementWidget ��� �������� ����������� �������� �������������� 
	DropDownListElementWidget* getCurrentDropDownListElement() { return CurrentDropDownListElement;}

	~DragAndDropWidget(); 
};

