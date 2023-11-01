#include "../ReplaceCharacterButtonPopupDesign.h"
#include "ELANsfml/Sprites/Button.h"
#include "ELANsfml/Sprites/TextInput.h"
#include "ELANsfml/Sprites/PlainText.h"
#include "ELANsfml/Helpers/Config.h"

void ReplaceCharacterButtonPopupDesign::Init() {
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
                                         "Replace character",
                                         config::color::white,
                                         50));
    SetSprite("PlainText1", new PlainText({}, {},
                                         ON_RESIZE {
                                             return {{}, {100, window_size.y * 0.15f}};
                                         },
                                         "N",
                                         config::color::white,
                                         20));
    SetSprite("NumberInputN", new TextInput({}, {},
                                           ON_RESIZE {
                                                return {{window_size.x - 200, 40}, {100, window_size.y * 0.2f}};
                                           },
                                           config::color::white,
                                           config::design::side_color,
                                           config::design::text_label_color,
                                           config::design::text_font_size));
    SetSprite("PlainText3", new PlainText({}, {},
                                          ON_RESIZE {
                                              return {{}, {100, window_size.y * 0.25f}};
                                          },
                                          "M",
                                          config::color::white,
                                          20));
    SetSprite("NumberInputM", new TextInput({}, {},
                                            ON_RESIZE {
                                                return {{window_size.x - 200, 40}, {100, window_size.y * 0.3f}};
                                            },
                                            config::color::white,
                                            config::design::side_color,
                                            config::design::text_label_color,
                                            config::design::text_font_size));
    SetSprite("PlainText4", new PlainText({}, {},
                                          ON_RESIZE {
                                              return {{}, {100, window_size.y * 0.35f}};
                                          },
                                          "Input character",
                                          config::color::white,
                                          20));
    SetSprite("CharacterInput", new TextInput({}, {},
                                           ON_RESIZE {
                                               return {{window_size.x - 200, 40}, {100, window_size.y * 0.4f}};
                                           },
                                           config::color::white,
                                           config::design::side_color,
                                           config::design::text_label_color,
                                           config::design::text_font_size));
}

void ReplaceCharacterButtonPopupDesign::Render(bool do_clear) {
    AbstractDesign::Render(do_clear);
}