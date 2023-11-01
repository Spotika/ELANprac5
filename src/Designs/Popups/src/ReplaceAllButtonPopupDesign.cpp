#include "../ReplaceAllButtonPopupDesign.h"
#include "ELANsfml/Sprites/Button.h"
#include "ELANsfml/Sprites/TextInput.h"
#include "ELANsfml/Sprites/PlainText.h"
#include "ELANsfml/Helpers/Config.h"

void ReplaceAllButtonPopupDesign::Init() {
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
                                         "Replace all",
                                         config::color::white,
                                         50));
    SetSprite("PlainText1", new PlainText({}, {},
                                         ON_RESIZE {
                                             return {{}, {100, window_size.y * 0.15f}};
                                         },
                                         "Begin",
                                         config::color::white,
                                         20));
    SetSprite("PlainText2", new PlainText({}, {},
                                          ON_RESIZE {
                                              return {{}, {100, window_size.y * 0.25f}};
                                          },
                                          "End",
                                          config::color::white,
                                          20));
    SetSprite("NumberInputBegin", new TextInput({}, {},
                                           ON_RESIZE {
                                                return {{window_size.x - 200, 40}, {100, window_size.y * 0.2f}};
                                           },
                                           config::color::white,
                                           config::design::side_color,
                                           config::design::text_label_color,
                                           config::design::text_font_size));
    SetSprite("NumberInputEnd", new TextInput({}, {},
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
                                          "String from",
                                          config::color::white,
                                          20));
    SetSprite("StringInputFrom", new TextInput({}, {},
                                           ON_RESIZE {
                                               return {{window_size.x - 200, 40}, {100, window_size.y * 0.4f}};
                                           },
                                           config::color::white,
                                           config::design::side_color,
                                           config::design::text_label_color,
                                           config::design::text_font_size));
    SetSprite("PlainText4", new PlainText({}, {},
                                          ON_RESIZE {
                                              return {{}, {100, window_size.y * 0.45f}};
                                          },
                                          "String to",
                                          config::color::white,
                                          20));
    SetSprite("StringInputTo", new TextInput({}, {},
                                               ON_RESIZE {
                                                   return {{window_size.x - 200, 40}, {100, window_size.y * 0.5f}};
                                               },
                                               config::color::white,
                                               config::design::side_color,
                                               config::design::text_label_color,
                                               config::design::text_font_size));
}

void ReplaceAllButtonPopupDesign::Render(bool do_clear) {
    AbstractDesign::Render(do_clear);
}