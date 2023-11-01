#include "../InsertSubstringButtonPopupDesign.h"
#include "ELANsfml/Sprites/Button.h"
#include "ELANsfml/Sprites/TextInput.h"
#include "ELANsfml/Sprites/PlainText.h"
#include "ELANsfml/Helpers/Config.h"

void InsertSubstringButtonPopupDesign::Init() {
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
                                         "Insert substring",
                                         config::color::white,
                                         50));
    SetSprite("PlainText1", new PlainText({}, {},
                                         ON_RESIZE {
                                             return {{}, {100, window_size.y * 0.15f}};
                                         },
                                         "Number N",
                                         config::color::white,
                                         20));
    SetSprite("PlainText2", new PlainText({}, {},
                                          ON_RESIZE {
                                              return {{}, {100, window_size.y * 0.25f}};
                                          },
                                          "Number M",
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
    SetSprite("NumberInputM", new TextInput({}, {},
                                           ON_RESIZE {
                                               return {{window_size.x - 200, 40}, {100, window_size.y * 0.3f}};
                                           },
                                           config::color::white,
                                           config::design::side_color,
                                           config::design::text_label_color,
                                           config::design::text_font_size));
    SetSprite("PlainText3", new PlainText({}, {},
                                          ON_RESIZE {
                                              return {{}, {100, window_size.y * 0.35f}};
                                          },
                                          "String",
                                          config::color::white,
                                          20));
    SetSprite("StringInput", new TextInput({}, {},
                                           ON_RESIZE {
                                               return {{window_size.x - 200, 40}, {100, window_size.y * 0.4f}};
                                           },
                                           config::color::white,
                                           config::design::side_color,
                                           config::design::text_label_color,
                                           config::design::text_font_size));
}

void InsertSubstringButtonPopupDesign::Render(bool do_clear) {
    AbstractDesign::Render(do_clear);
}