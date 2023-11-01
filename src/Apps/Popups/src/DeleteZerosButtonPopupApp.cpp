#include "src/Apps/Popups/DeleteZerosButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *DeleteZerosButtonPopupApp::Start(std::pair<std::string, void *> data) {
    DeleteZerosButtonPopupDesign::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &DeleteZerosButtonPopupApp::EnterButton);

    return Loop(data);
}

void *DeleteZerosButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        DeleteZerosButtonPopupDesign::Update(this);
        DeleteZerosButtonPopupDesign::Render(false);
    }

    return Stop();
}

void *DeleteZerosButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputBegin"))->front();
    int begin;
    ss >> begin;
    ss.clear();
    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputEnd"))->front();
    int end;
    ss >> end;

    auto to_return = new ReturnType(begin, end);
    return to_return;
}

void DeleteZerosButtonPopupApp::EnterButton() {
    is_running_ = false;
}