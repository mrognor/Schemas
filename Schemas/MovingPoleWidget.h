#pragma once

#include "SchemasClasses.h"
#include "MovingPoleNodeWidget.h"
#include "DropDownListWidget.h"
#include "MovingPoleNodeWidget.h"
#include "DragAndDropWidget.h"
#include "MovingPoleConnectionWidget.h"

class MovingPoleWidget
{
private:
	/// ���� ����
	sf::RenderWindow* MovingPoleWidgetWindow;

	/// ��������� �� DropDown ������
	DropDownListWidget* MovingPoleDropDownListWidget;

	/// ��������� �� ���� � ���� ������
	DragAndDropWidget* MovingPoleDragAndDropWidget;

	/// ������ ��� ����
	std::vector<MovingPoleNodeWidget*> MovingPoleNodeVector;

	/// ������ ���������� ����
	std::vector<MovingPoleConnectionWidget*> MovingPoleConnectionVector;

	/// ���������� ��� ��������� ��������� ����
	sf::Vector2f LastMouseCoords;

	/// �������� ��� ��������� ���� ��������� ����
	sf::RenderTexture* MovingPoleWidgetTexture;

	/// ������ ��� ��������� ���� ��������� ����
	sf::Sprite* MovingPoleWidgetSprite;

	/// ���������� ��� �������� ������ ��������������
	bool IsDragStarted = false;

	MovingPoleConnectionWidget* CurrentConnectionWidget = nullptr;

public:
	MovingPoleWidget(sf::RenderWindow* movingPoleWidgetWindow, DropDownListWidget* movingPoleDropDownListWidget, DragAndDropWidget* movingPoleDragAndDropWidget);

	void Tick();

	void InputHandler(sf::Event event);

	/// ������� ��� �������� ������� ���������� ��� �� ����
	template <class T>
	void CreateConnection(T* outputNode);

	void DeleteConnection(MovingPoleConnectionWidget* widgetToRemove);

	/// ������� ���������� ������� ������ ���������� 
	MovingPoleConnectionWidget* getCurrentConnectionWidget() { return CurrentConnectionWidget; }

	/// ������� ���������� ������� ������ ����������. ������ ����������� � ������ �������� ����������
	void ResetCurrentConnectionWidget() { CurrentConnectionWidget = nullptr; }

	sf::RenderTexture* GetMovingPoleWidgetTexture() { return MovingPoleWidgetTexture; }

	sf::Sprite* GetMovingPoleWidgetSprite() { return MovingPoleWidgetSprite; }

	~MovingPoleWidget();
};


template <class T>
void MovingPoleWidget::CreateConnection(T* outputNode)
{
	MovingPoleConnectionWidget* widget = new MovingPoleConnectionWidget(MovingPoleWidgetWindow, this, outputNode);
	CurrentConnectionWidget = widget;
	MovingPoleConnectionVector.push_back(widget);
}
