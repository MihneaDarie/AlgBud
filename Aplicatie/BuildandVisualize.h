#pragma once
#include "SmartButton.h"

class BuildandVisualize: public SmartButton
{

public:
	BuildandVisualize() = default;
	BuildandVisualize(const char*, sf::Vector2f, sf::Vector2f);

	void draw(sf::RenderWindow&) override;

};

