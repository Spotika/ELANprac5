#pragma once

#include "ELANsfml/Apps/AbstractApp.h"
#include "ELANsfml/Sprites/Functional/ButtonFunctional.h"
#include "ELANsfml/Sprites/Functional/TextInputFunctional.h"
#include "src/Designs/Popups/DeleteButtonPopupDesign.h"

#ifndef CMAKESFMLPROJECT_DELETEBUTTONPOPUP_H
#define CMAKESFMLPROJECT_DELETEBUTTONPOPUP_H

class DeleteButtonPopupApp : public AbstractApp, DeleteButtonPopupDesign, ButtonFunctional, TextInputFunctional {
public:

    struct ReturnType {
        int n;

        ReturnType(int n) : n(n) {}
    };

    void *Start(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Loop(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Stop() override;

private:

    void EnterButton();
};

#endif //CMAKESFMLPROJECT_INSERTBUTTONPOPUP_H
