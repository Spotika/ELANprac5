#include "src/Apps/Popups/ReplaceCharacterButtonPopupApp.h"
#include "ELANsfml/Singletons/EventHandler.h"
#include "ELANsfml/Singletons/Screen.h"
#include <sstream>

void *ReplaceCharacterButtonPopupApp::Start(std::pair<std::string, void *> data) {
    ReplaceCharacterButtonPopupDesign::Init();

    LinkFunctionToButton(GetSpriteByName("EnterButton"), this, &ReplaceCharacterButtonPopupApp::EnterButton);

    return Loop(data);
}

void *ReplaceCharacterButtonPopupApp::Loop(std::pair<std::string, void *> data) {

    auto sprite = reinterpret_cast<sf::Sprite *>(data.second);

    sprite->setColor({100, 100, 100});

    Screen::GetInstance()->SetResizable(false);

    while (is_running_) {
        EventHandler::GetInstance()->Update();

        Screen::GetInstance()->GetRenderWindow()->draw(*sprite);

        ReplaceCharacterButtonPopupApp::Update(this);
        ReplaceCharacterButtonPopupApp::Render(false);
    }

    return Stop();
}

void *ReplaceCharacterButtonPopupApp::Stop() {
    Screen::GetInstance()->SetResizable(true);

    std::stringstream ss;

    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputN"))->front();
    int n;
    ss >> n;
    ss.clear();
    ss << "0" << *GetContainedText(GetSpriteByName("NumberInputM"))->front();
    int m;
    ss >> m;

    auto to_return = new ReturnType(GetContainedText(GetSpriteByName("CharacterInput"))->front(),
                                    n, m);
    return to_return;
}

void ReplaceCharacterButtonPopupApp::EnterButton() {
    is_running_ = false;
}