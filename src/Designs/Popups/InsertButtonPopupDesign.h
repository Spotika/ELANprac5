#pragma once

#include "ELANsfml/Designs/AbstractDesign.h"

#ifndef CMAKESFMLPROJECT_INSERTBUTTONPOPUPDESIGN_H
#define CMAKESFMLPROJECT_INSERTBUTTONPOPUPDESIGN_H

class InsertButtonPopupDesign : public AbstractDesign {
public:

    void Init() override;

    void Render(bool do_clear) override;

private:
};

#endif //CMAKESFMLPROJECT_INSERTBUTTONPOPUPDESIGN_H
