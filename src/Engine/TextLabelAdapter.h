#pragma once
#include "ELANsfml/Sprites/TextLabel.h"

class TextLabelAdapter {
public:

    TextLabelAdapter(AbstractSprite* text_label);

    void Update();

    std::vector<std::string*> GetText();

private:

    sf::Text text_;
    TextLabel* text_label_;
};