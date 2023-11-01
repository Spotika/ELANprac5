#include "src/Apps/Popups/ReplaceAllButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *ReplaceAllButtonPopupApp::Start(std::pair<std::string, void *> data) {
    ReplaceAllButtonPopupDesign::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &ReplaceAllButtonPopupApp::EnterButton);

    return Loop(data);
}

void *ReplaceAllButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        ReplaceAllButtonPopupDesign::Update(this);
        ReplaceAllButtonPopupDesign::Render(false);
    }

    return Stop();
}

void *ReplaceAllButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputBegin"))->front();
    int number_begin;
    ss >> number_begin;
    ss.clear();
    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputEnd"))->front();
    int number_end;
    ss >> number_end;

    auto to_return = new ReturnType(*GetContainedText(GetSpriteByName("StringInputFrom"))->front(),
                                    *GetContainedText(GetSpriteByName("StringInputTo"))->front(),
                                    number_begin,
                                    number_end);
    return to_return;
}

void ReplaceAllButtonPopupApp::EnterButton() {
    is_running_ = false;
}