#pragma once

#include "ELANsfml/Apps/AbstractApp.h"
#include "ELANsfml/Sprites/Functional/ButtonFunctional.h"
#include "ELANsfml/Sprites/Functional/TextInputFunctional.h"
#include "src/Designs/Popups/InsertButtonPopupDesign.h"

#ifndef CMAKESFMLPROJECT_INSERTBUTTONPOPUP_H
#define CMAKESFMLPROJECT_INSERTBUTTONPOPUP_H

class InsertButtonPopupApp : public AbstractApp, InsertButtonPopupDesign, ButtonFunctional, TextInputFunctional {
public:

    struct ReturnType {
        int n;
        std::vector<std::string*> text;

        ReturnType(int n, std::vector<std::string*> &&text) : n(n), text(std::move(text)) {}
    };

    void *Start(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Loop(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Stop() override;

private:

    void EnterButton();
};

#endif //CMAKESFMLPROJECT_INSERTBUTTONPOPUP_H
