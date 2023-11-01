#pragma once

#include "ELANsfml/Apps/AbstractApp.h"
#include "ELANsfml/Sprites/Functional/ButtonFunctional.h"
#include "ELANsfml/Sprites/Functional/TextInputFunctional.h"
#include "src/Designs/Popups/InsertSubstringButtonPopupDesign.h"

#ifndef CMAKESFMLPROJECT_INSERTSUBSTRINGBUTTONPOPUP_H
#define CMAKESFMLPROJECT_INSERTSUBSTRINGBUTTONPOPUP_H

class InsertSubstringButtonPopupApp : public AbstractApp, InsertSubstringButtonPopupDesign, ButtonFunctional, TextInputFunctional {
public:

    struct ReturnType {
        int n;
        int m;
        std::string* text;

        ReturnType(int n, int m, std::string* text) : n(n), m(m), text(text) {}
    };

    void *Start(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Loop(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Stop() override;

private:

    void EnterButton();
};

#endif //CMAKESFMLPROJECT_INSERTSUBSTRINGBUTTONPOPUP_H
