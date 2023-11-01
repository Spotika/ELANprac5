#include "src/Apps/Popups/RemoveLowerButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *RemoveLowerButtonPopupApp::Start(std::pair<std::string, void *> data) {
    RemoveLowerButtonPopupDesign::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &RemoveLowerButtonPopupApp::EnterButton);

    return Loop(data);
}

void *RemoveLowerButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        RemoveLowerButtonPopupApp::Update(this);
        RemoveLowerButtonPopupApp::Render(false);
    }

    return Stop();
}

void *RemoveLowerButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInput"))->front();
    int n;
    ss >> n;

    auto to_return = new ReturnType(n);
    return to_return;
}

void RemoveLowerButtonPopupApp::EnterButton() {
    is_running_ = false;
}