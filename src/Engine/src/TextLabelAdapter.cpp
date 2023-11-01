#include "../TextLabelAdapter.h"
#include "SFML/Graphics.hpp"
#include "ELANsfml/Singletons/Screen.h"
#include <stdexcept>
#include <iostream>

TextLabelAdapter::TextLabelAdapter(AbstractSprite *sprite) {
    auto text_label = dynamic_cast<TextLabel*>(sprite);

    if (text_label == nullptr) {
        throw std::invalid_argument("Sprite is not a TextLabel");
    }

    text_label_ = text_label;

    text_.setFont(*Screen::GetInstance()->GetFont());
    text_.setCharacterSize(text_label_->GetCharacterSize());
}


void TextLabelAdapter::Update() {

    auto width = text_label_->GetTextFieldWidth();

    auto text = text_label_->GetText();

    for (size_t i = 0; i < text->size(); ++i) {
        text_.setString(*text->at(i));
        
        while (text_.getLocalBounds().width + 30 > width) {
            if (i == text->size() - 1 && text->back()->size() > 1) {
                text->emplace_back(new std::string);
            }

            text->at(i + 1)->insert(text->at(i + 1)->begin(), text->at(i)->back());
            text->at(i)->pop_back();
            text_.setString(*text->at(i));
        }

        while (text_.getLocalBounds().width + 50 < width && text->at(i)->back() != '\r') {

            if (i == (int)text->size() - 1) {
//                text->at(i)->push_back('~');
                break;
            } else {
                if (text->at(i + 1)->empty()) {
                    text->erase(text->begin() + (int)i + 1);
                } else {
                    text->at(i)->push_back(text->at(i + 1)->front());
                    text->at(i + 1)->erase(text->at(i + 1)->begin());
                }
            }

            text_.setString(*text->at(i));
        }
    }

    text_label_->ReInit();
//    for (int i = 0; i < (int)text->size() - 1; ++i) {
//        text_.setString(*text->at(i));
//
//        std::cout << *text->at(i) << "\n";
//
//        while (text_.getLocalBounds().width + 40 <= width && text->at(i)->back() != '~') {
////            std::remove(text->at(i + 1)->begin(), text->at(i + 1)->end(), *text->at(i + 1)->begin());
//            text->at(i)->push_back(*text->at(i + 1)->begin());
//            if (text->at(i + 1)->size() != 0) {
//                text->at(i + 1)->erase(0);
//            } else {
//                text->erase(text->begin() + i + 1);
//            }
//            text_.setString(*text->at(i));
//  iiiiii      }
//    }
//
//    text_label_->ReInit();
}
