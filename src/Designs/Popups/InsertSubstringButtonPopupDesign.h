#pragma once

#include "ELANsfml/Designs/AbstractDesign.h"

#ifndef CMAKESFMLPROJECT_INSERTSUBSTRINGBUTTONPOPUPDESIGN_H
#define CMAKESFMLPROJECT_INSERTSUBSTRINGBUTTONPOPUPDESIGN_H

class InsertSubstringButtonPopupDesign : public AbstractDesign {
public:

    void Init() override;

    void Render(bool do_clear) override;

private:
};

#endif //CMAKESFMLPROJECT_INSERTSUBSTRINGBUTTONPOPUPDESIGN_H
