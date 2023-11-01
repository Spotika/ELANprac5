#pragma once

#include "ELANsfml/Designs/AbstractDesign.h"

#ifndef CMAKESFMLPROJECT_DELETEBUTTONPOPUPDESIGN_H
#define CMAKESFMLPROJECT_DELETEBUTTONPOPUPDESIGN_H

class DeleteButtonPopupDesign : public AbstractDesign {
public:

    void Init() override;

    void Render(bool do_clear) override;

private:
};

#endif //CMAKESFMLPROJECT_DELETEBUTTONPOPUPDESIGN_H
