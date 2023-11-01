#pragma once

#include "ELANsfml/Apps/AbstractApp.h"
#include "ELANsfml/Sprites/Functional/ButtonFunctional.h"
#include "ELANsfml/Sprites/Functional/TextInputFunctional.h"
#include "src/Designs/Popups/ReplaceCharacterButtonPopupDesign.h"

class ReplaceCharacterButtonPopupApp : public AbstractApp, ReplaceCharacterButtonPopupDesign, ButtonFunctional, TextInputFunctional {
public:

    struct ReturnType {
        int n;
        int m;
        std::string *char1;

        ReturnType(std::string* char1, int n, int m) :
                n(n), m(m), char1(char1) {}
    };

    void *Start(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Loop(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Stop() override;

private:

    void EnterButton();
};