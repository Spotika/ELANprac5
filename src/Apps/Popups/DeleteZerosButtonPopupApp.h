#pragma once

#include "ELANsfml/Apps/AbstractApp.h"
#include "ELANsfml/Sprites/Functional/ButtonFunctional.h"
#include "ELANsfml/Sprites/Functional/TextInputFunctional.h"
#include "src/Designs/Popups/DeleteZerosButtonPopupDesign.h"

class DeleteZerosButtonPopupApp : public AbstractApp, DeleteZerosButtonPopupDesign, ButtonFunctional, TextInputFunctional {
public:

    struct ReturnType {
        int begin;
        int end;
        ReturnType(int begin, int end) :
                begin(begin), end(end){}
    };

    void *Start(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Loop(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Stop() override;

private:

    void EnterButton();
};
