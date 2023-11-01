#include "src/Apps/Popups/InsertSubstringButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *InsertSubstringButtonPopupApp::Start(std::pair<std::string, void *> data) {
    InsertSubstringButtonPopupDesign::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &InsertSubstringButtonPopupApp::EnterButton);

    return Loop(data);
}

void *InsertSubstringButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        InsertSubstringButtonPopupDesign::Update(this);
        InsertSubstringButtonPopupDesign::Render(false);
    }

    return Stop();
}

void *InsertSubstringButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputN"))->front();
    int numberN;
    ss >> numberN;
    ss.clear();
    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputM"))->front();
    int numberM;
    ss >> numberM;

    auto to_return = new ReturnType(numberN, numberM, GetContainedText(GetSpriteByName("StringInput"))->front());
    return to_return;
}

void InsertSubstringButtonPopupApp::EnterButton() {
    is_running_ = false;
}