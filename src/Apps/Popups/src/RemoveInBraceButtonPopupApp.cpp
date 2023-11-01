#include "src/Apps/Popups/RemoveInBraceButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *RemoveInBraceButtonPopupApp::Start(std::pair<std::string, void *> data) {
    RemoveInBraceButtonPopupApp::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &RemoveInBraceButtonPopupApp::EnterButton);

    return Loop(data);
}

void *RemoveInBraceButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        RemoveInBraceButtonPopupApp::Update(this);
        RemoveInBraceButtonPopupApp::Render(false);
    }

    return Stop();
}

void *RemoveInBraceButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputN"))->front();
    int n;
    ss >> n;

    auto to_return = new ReturnType(n);
    return to_return;
}

void RemoveInBraceButtonPopupApp::EnterButton() {
    is_running_ = false;
}