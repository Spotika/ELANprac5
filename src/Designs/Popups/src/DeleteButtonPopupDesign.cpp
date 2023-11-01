#include "../DeleteButtonPopupDesign.h"
#include "ELANsfml/Sprites/Button.h"
#include "ELANsfml/Sprites/TextInput.h"
#include "ELANsfml/Sprites/PlainText.h"
#include "ELANsfml/Helpers/Config.h"

void DeleteButtonPopupDesign::Init() {
    SetSprite("EnterButton", new Button({}, {},
                                        ON_RESIZE {
                                            return {{250, window_size.y * 0.05f}, {100, window_size.y * 0.9f}};
                                        },
                                        "Enter",
                                        config::design::text_color,
                                        config::design::btn_background_color,
                                        config::design::btn_font_size,
                                        10));
    SetSprite("Header", new PlainText({}, {},
                                         ON_RESIZE {
                                            return {{}, {100, window_size.y * 0.05f}};
                                         },
                                         "Delete string",
                                         config::color::white,
                                         50));
    SetSprite("PlainText1", new PlainText({}, {},
                                         ON_RESIZE {
                                             return {{}, {100, window_size.y * 0.15f}};
                                         },
                                         "String number",
                                         config::color::white,
                                         20));
    SetSprite("NumberInput", new TextInput({}, {},
                                           ON_RESIZE {
                                                return {{window_size.x - 200, 40}, {100, window_size.y * 0.2f}};
                                           },
                                           config::color::white,
                                           config::design::side_color,
                                           config::design::text_label_color,
                                           config::design::text_font_size));
}

void DeleteButtonPopupDesign::Render(bool do_clear) {
    AbstractDesign::Render(do_clear);
}