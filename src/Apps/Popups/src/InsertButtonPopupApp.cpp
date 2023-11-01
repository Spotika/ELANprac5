#include "src/Apps/Popups/InsertButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *InsertButtonPopupApp::Start(std::pair<std::string, void *> data) {
    InsertButtonPopupDesign::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &InsertButtonPopupApp::EnterButton);

    return Loop(data);
}

void *InsertButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        InsertButtonPopupDesign::Update(this);
        InsertButtonPopupDesign::Render(false);
    }

    //delete sprite;

    return Stop();
}

void *InsertButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInput"))->front();
    int number;
    ss >> number;
//    delete GetSpriteByName("NumberInput");

    auto to_return = new ReturnType(number, std::move(*GetContainedText(GetSpriteByName("StringInput"))));
//    delete GetSpriteByName("StringInput");
    return to_return;
}

void InsertButtonPopupApp::EnterButton() {
    is_running_ = false;
}