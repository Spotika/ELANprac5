#pragma once

#include "ELANsfml/Apps/AbstractApp.h"
#include "src/Designs/MainDesign.h"
#include "ELANsfml/Sprites/Functional/ButtonFunctional.h"
#include <iostream>
#include "ELANsfml/Sprites/Functional/TextLabelFunctional.h"
#include "src/Engine/TextLabelAdapter.h"

#ifndef CMAKESFMLPROJECT_MAINAPP_H
#define CMAKESFMLPROJECT_MAINAPP_H


class MainApp : public AbstractApp,
                MainDesign,
                ButtonFunctional,
                TextLabelFunctional {
private:
    void *Start(std::pair<std::string, void *> data) override;

    void *Loop(std::pair<std::string, void *> data) override;

    void *Stop() override;

    static void *ShowPopup(std::string popup_name);

    TextLabelAdapter* text_label_adapter_;

public:

    void InsertButton();

    void InsertSubstringButton();

    void DeleteButton();

    void ReplaceAllButton();

    void ReplaceCharacterButton();

    void DeleteZerosButton();

    void RemoveLowerButton();

    void ReplaceStarByPlusButton();

    void RemoveInBraceButton();
};


#endif //CMAKESFMLPROJECT_MAINAPP_H
