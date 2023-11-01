#include "src/Apps/Popups/DeleteButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *DeleteButtonPopupApp::Start(std::pair<std::string, void *> data) {
    DeleteButtonPopupDesign::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &DeleteButtonPopupApp::EnterButton);

    return Loop(data);
}

void *DeleteButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        DeleteButtonPopupDesign::Update(this);
        DeleteButtonPopupDesign::Render(false);
    }

    return Stop();
}

void *DeleteButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInput"))->front();
    int number;
    ss >> number;

    auto to_return = new ReturnType(number);
    return to_return;
}

void DeleteButtonPopupApp::EnterButton() {
    is_running_ = false;
}