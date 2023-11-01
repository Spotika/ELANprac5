#pragma once

#include "ELANsfml/Apps/AbstractApp.h"
#include "ELANsfml/Sprites/Functional/ButtonFunctional.h"
#include "ELANsfml/Sprites/Functional/TextInputFunctional.h"
#include "src/Designs/Popups/ReplaceAllButtonPopupDesign.h"

class ReplaceAllButtonPopupApp : public AbstractApp, ReplaceAllButtonPopupDesign, ButtonFunctional, TextInputFunctional {
public:

    struct ReturnType {
        int begin;
        int end;

        std::string from, to;

        ReturnType(std::string& str1, std::string& str2, int begin = -1, int end = -1) :
                begin(begin), end(end), from(str1), to(str2) {}
    };

    void *Start(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Loop(std::pair<std::string, void *> data = {"", nullptr}) override;

    void *Stop() override;

private:

    void EnterButton();
};