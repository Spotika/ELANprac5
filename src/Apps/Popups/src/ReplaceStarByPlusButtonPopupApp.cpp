#include "src/Apps/Popups/ReplaceStarByPlusButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *ReplaceStarByPlusButtonPopupApp::Start(std::pair<std::string, void *> data) {
    ReplaceStarByPlusButtonPopupApp::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &ReplaceStarByPlusButtonPopupApp::EnterButton);

    return Loop(data);
}

void *ReplaceStarByPlusButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        ReplaceStarByPlusButtonPopupApp::Update(this);
        ReplaceStarByPlusButtonPopupApp::Render(false);
    }

    return Stop();
}

void *ReplaceStarByPlusButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputN"))->front();
    int n;
    ss >> n;

    auto to_return = new ReturnType(n);
    return to_return;
}

void ReplaceStarByPlusButtonPopupApp::EnterButton() {
    is_running_ = false;
}