#include "../MainApp.h"
#include <iostream>
#include "src/Apps/Popups/InsertButtonPopupApp.h"
#include <utility>
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include "ELANsfml/Singletons/AppManager.h"
#include "src/Apps/Popups/DeleteButtonPopupApp.h"
#include "src/Apps/Popups/InsertSubstringButtonPopupApp.h"
#include "src/Apps/Popups/ReplaceAllButtonPopupApp.h"
#include "src/Apps/Popups/ReplaceCharacterButtonPopupApp.h"
#include "src/Apps/Popups/RemoveLowerButtonPopupApp.h"
#include "src/Apps/Popups/DeleteZerosButtonPopupApp.h"
#include "src/Apps/Popups/ReplaceStarByPlusButtonPopupApp.h"
#include "src/Apps/Popups/RemoveInBraceButtonPopupApp.h"
#include "src/Engine/TextLabelAdapter.h"

bool is_digit(const char& c) {
    return (c >= '0' && c <= '9') || c == '\r';
}

void removeLeadingZeros(std::vector<std::string*>& text, int begin, int end) {
    for (int i = begin; i <= end; ++i) {
        std::string* str_ptr = text[i];

        bool flag = false;
        if (str_ptr->back() == '\r') {
            flag = true;
            str_ptr->pop_back();
            str_ptr->push_back('B');
        }

        bool isd = false;

        int j = 0;

        while (j < str_ptr->size() - 1) {
            if (!isd && is_digit(str_ptr->at(j))) {
                isd = true;

                if (str_ptr->at(j) == '0') {
                    if (is_digit(str_ptr->at(j + 1))) {
                        isd = false;
                        str_ptr->erase(str_ptr->begin() + j);
                        --j;
                    }
                }
            } else if (!is_digit(str_ptr->at(j))) {
                isd = false;
            }
            ++j;
        }

        if (flag) {
            str_ptr->pop_back();
            str_ptr->push_back('\r');
        }
    }
}


void *MainApp::Start(std::pair<std::string, void *> data) {
    std::cout << "Starting MainApp\n";

    MainDesign::Init();

    LinkFunctionToButton(GetSpriteByName("InsertButton"), this, &MainApp::InsertButton);
    LinkFunctionToButton(GetSpriteByName("DeleteButton"), this, &MainApp::DeleteButton);
    LinkFunctionToButton(GetSpriteByName("InsertSubstringButton"), this, &MainApp::InsertSubstringButton);
    LinkFunctionToButton(GetSpriteByName("ReplaceAllButton"), this, &MainApp::ReplaceAllButton);
    LinkFunctionToButton(GetSpriteByName("ReplaceCharacterButton"), this, &MainApp::ReplaceCharacterButton);
    LinkFunctionToButton(GetSpriteByName("DeleteZerosButton"), this, &MainApp::DeleteZerosButton);
    LinkFunctionToButton(GetSpriteByName("RemoveLowerButton"), this, &MainApp::RemoveLowerButton);
    LinkFunctionToButton(GetSpriteByName("ReplaceStarByPlusButton"), this, &MainApp::ReplaceStarByPlusButton);
    LinkFunctionToButton(GetSpriteByName("RemoveInBraceButton"), this, &MainApp::RemoveInBraceButton);

    text_label_adapter_ = new TextLabelAdapter(GetSpriteByName("TextLabel"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    text_label_adapter_->Update();

    return Loop(data);
}

void *MainApp::Loop(std::pair<std::string, void *>) {
    while (is_running_) {

        MainDesign::Update(this);
        text_label_adapter_->Update();
        MainDesign::Render(true);
    }

    return Stop();
}

void *MainApp::Stop() {
    is_running_ = false;
    std::cout << "Stopping MainApp\n";
    delete text_label_adapter_;
    return nullptr;
}

void * MainApp::ShowPopup(std::string popup_name) {
    auto window = Screen::GetInstance()->GetRenderWindow();

    sf::Texture texture;
    texture.create(window->getSize().x, window->getSize().y);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    texture.update(*window);

    return AppManager::GetInstance()->StartApp( std::move(popup_name),{"background", &sprite});
}


// Buttons
void MainApp::InsertButton() {
    auto result = reinterpret_cast<InsertButtonPopupApp::ReturnType*> (ShowPopup("InsertButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    while (text->size() < result->n - 1) {
        text->emplace_back(new std::string("\r"));
    }

    for (int i = 0; i < result->text.size(); ++i) {
        text->insert(text->begin() + result->n - 1 + i, new std::string(*result->text.at(i) + "\r"));
    }

    std::cout << "InsertButton:\n";

    std::cout << "number: " << result->n << "\n";

    std::cout << "text:\n";

    for (auto i : result->text) {
        std::cout << *i << "\n";
    }

    std::cout << "OK\n---------------------\n";

    delete result;
}

void MainApp::DeleteButton() {
    auto result = reinterpret_cast<DeleteButtonPopupApp::ReturnType*> (ShowPopup("DeleteButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    text->erase(text->begin() + result->n - 1);

    std::cout << "DeleteButton:\n";

    std::cout << "number: " << result->n << "\n";

    std::cout << "OK\n---------------------\n";

    delete result;
}

void MainApp::InsertSubstringButton() {
    auto result = reinterpret_cast<InsertSubstringButtonPopupApp::ReturnType*> (ShowPopup("InsertSubstringButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    for (int i = 0; i < result->text->size(); ++i) {
        text->at(result->n - 1)->insert(text->at(result->n - 1)->begin() + result->m - 1 + i, result->text->at(i));
    }

    std::cout << "InsertSubstringButton:\n";

    std::cout << "number N: " << result->n << " number M:" << result->m << "\n";

    std::cout << "text:\n";

    std::cout << *result->text << "\n";

    std::cout << "OK\n---------------------\n";

    delete result;
}

void MainApp::ReplaceAllButton() {
    auto result = reinterpret_cast<ReplaceAllButtonPopupApp::ReturnType*> (ShowPopup("ReplaceAllButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    std::string to = result->to;
    std::string from = result->from;
    int begin = result->begin - 1;
    int end = result->end - 1;
    for (int i = begin; i <= end; ++i) {
        std::string* str_ptr = (*text)[i];


        size_t pos = 0;

        while ((pos = str_ptr->find(from, pos)) != std::string::npos) {
            str_ptr->replace(pos, from.length(), to);
            pos += to.length();
        }
    }

    std::cout << "ReplaceAllButton:\n";

    std::cout << "number begin: " << result->begin << " number end:" << result->end << "\n";

    std::cout << "text from:\n";

    std::cout << from << "\n";

    std::cout << "text to:\n";

    std::cout << to << "\n";

    std::cout << "OK\n---------------------\n";

    delete result;
}


void MainApp::ReplaceCharacterButton() {
    auto result = reinterpret_cast<ReplaceCharacterButtonPopupApp::ReturnType*> (ShowPopup("ReplaceCharacterButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    text->at(result->n - 1)->at(result->m - 1) = (*result->char1)[0];

    text_label_adapter_->Update();

    std::cout << "ReplaceCharacterButton:\n";

    std::cout << "number n: " << result->n << " number m:" << result->m << "\n";

    std::cout << "character:\n";

    std::cout << *result->char1 << "\n";

    std::cout << "OK\n---------------------\n";

    delete result;
}

bool isIncreasingDigits(const std::string& str) {
    if (str.length() < 2) {
        return false; // Группа цифр не может иметь менее двух цифр
    }

    for (size_t i = 1; i < str.length(); ++i) {
        if (str[i] != str[i - 1] + 1) {
            return false; // Цифры не увеличиваются на 1
        }
    }

    return true;
}

void removeNonIncreasingDigitGroups(std::vector<std::string*>& text, int begin, int end) {
    for (int i = begin; i <= end; ++i) {
        std::string* str_ptr = text[i];
        std::string result;

        size_t j = 0;
        while (j < str_ptr->length()) {
            if (isdigit((*str_ptr)[j])) {
                size_t groupStart = j;
                while (j < str_ptr->length() && isdigit((*str_ptr)[j])) {
                    ++j;
                }
                std::string group = str_ptr->substr(groupStart, j - groupStart);
                if (isIncreasingDigits(group)) {
                    result += group;
                }
            } else {
                result += (*str_ptr)[j];
                ++j;
            }
        }

        *str_ptr = result;
    }
}

void MainApp::RemoveLowerButton() {
    auto result = reinterpret_cast<RemoveLowerButtonPopupApp::ReturnType*> (ShowPopup("RemoveLowerButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    removeNonIncreasingDigitGroups(*text, result->n - 1, result->n-1);

    text_label_adapter_->Update();

    std::cout << "RemoveLowerButton:\n";

    std::cout << "number n: " << result->n << "\n";

    std::cout << "OK\n---------------------\n";

    delete result;
}

void MainApp::DeleteZerosButton() {
    auto result = reinterpret_cast<DeleteZerosButtonPopupApp::ReturnType*> (ShowPopup("DeleteZerosButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    int begin = result->begin - 1; // Начальный индекс строки
    int end = result->end - 1; // Конечный индекс строки

    removeLeadingZeros(*text, begin, end);

    std::cout << "DeleteZerosButton:\n";

    std::cout << "begin: " << result->begin << " number m: " << result->end << "\n";

    std::cout << "OK\n---------------------\n";

    delete result;
}

void replaceGroups(std::vector<std::string*>& text, int begin, int end) {
    for (int i = begin; i <= end; ++i) {
        std::string* str_ptr = text[i];
        std::string result;

        int count = 0;
        char prevChar = '\0';

        for (char c : *str_ptr) {
            if (c == '*') {
                if (prevChar == '*') {
                    count++;
                } else {
                    count = 1;
                }
            } else {
                if (count > 0) {
                    if (count % 2 == 0) {
                        result.append(count / 2, '+');
                    } else {
                        result.append(count / 2, '+');
                        result.append(1, '*');
                    }
                    count = 0;
                }
                result.append(1, c);
            }
            prevChar = c;
        }

        if (count > 0) {
            if (count % 2 == 0) {
                result.append(count / 2, '+');
            } else {
                result.append(count / 2, '+');
                result.append(1, '*');
            }
        }

        *str_ptr = result;
    }
}

void MainApp::ReplaceStarByPlusButton() {
    auto result = reinterpret_cast<ReplaceStarByPlusButtonPopupApp::ReturnType*> (ShowPopup("ReplaceStarByPlusButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    replaceGroups(*text, result->n - 1, result->n - 1);

    std::cout << "ReplaceStarByPlusButton:\n";

    std::cout << "N: " << result->n << "\n";

    std::cout << "OK\n---------------------\n";

    delete result;
}

void removeBraceGroups(std::vector<std::string*>& text, int begin, int end) {
    for (int i = begin; i <= end; ++i) {
        std::string* str_ptr = text[i];
        std::string result;
        bool insideBraces = false;

        for (char c : *str_ptr) {
            if (c != '\r') { // Игнорировать символ '\r'
                if (c == '{') {
                    insideBraces = true;
                } else if (c == '}') {
                    insideBraces = false;
                } else if (!insideBraces) {
                    result += c;
                }
            }
        }

        *str_ptr = result;
    }
}

void MainApp::RemoveInBraceButton() {
    auto result = reinterpret_cast<RemoveInBraceButtonPopupApp::ReturnType*> (ShowPopup("RemoveInBraceButtonPopupApp"));

    auto text = GetText(GetSpriteByName("TextLabel"));

    removeBraceGroups(*text, result->n - 1, result->n - 1);

    std::cout << "ReplaceStarByPlusButton:\n";

    std::cout << "N: " << result->n << "\n";

    std::cout << "OK\n---------------------\n";

    delete result;
}
