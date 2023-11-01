#pragma once

#include "ELANsfml/Designs/AbstractDesign.h"

class DeleteZerosButtonPopupDesign : public AbstractDesign {
public:

    void Init() override;

    void Render(bool do_clear) override;

private:
};

