#include "src/Designs/MainDesign.h"
#include "ELANsfml/Sprites/Button.h"
#include "ELANsfml/Sprites/BackgroundColor.h"
#include "ELANsfml/Helpers/Config.h"
#include "ELANsfml/Sprites/TextInput.h"
#include <iostream>
#include "ELANsfml/Sprites/TextLabel.h"
#include "ELANsfml/Sprites/PlainText.h"


void MainDesign::Init() {
    SetSprite("InsertButton", new Button({}, {},
                                         ON_RESIZE {
                                            return {{250, window_size.y * 0.1f},
                                                    {window_size.x - 270, window_size.y * 0.f + 20}};
                                          },
                                         "Insert",
                                         config::design::text_color,
                                         config::design::btn_background_color,
                                         25));
    SetSprite("DeleteButton", new Button({}, {},
                                         ON_RESIZE {
                                             return {{250, window_size.y * 0.1f},
                                                     {window_size.x - 270, window_size.y * .1f + 20 + 5}};
                                         },
                                         "Delete",
                                         config::design::text_color,
                                         config::design::btn_background_color,
                                         25));
    SetSprite("InsertSubstringButton", new Button({}, {},
                                         ON_RESIZE {
                                             return {{250, window_size.y * 0.1f},
                                                     {window_size.x - 270, window_size.y * .2f + 20 + 5 * 2}};
                                         },
                                         "Insert substr",
                                         config::design::text_color,
                                         config::design::btn_background_color,
                                         25));
    SetSprite("ReplaceCharacterButton", new Button({}, {},
                                            ON_RESIZE {
                                                return {{250, window_size.y * 0.1f},
                                                        {window_size.x - 270, window_size.y * .3f + 20 + 5 * 3}};
                                            },
                                            "Replace char",
                                            config::design::text_color,
                                            config::design::btn_background_color,
                                            25));
    SetSprite("ReplaceAllButton", new Button({}, {},
                                            ON_RESIZE {
                                                return {{250, window_size.y * 0.1f},
                                                        {window_size.x - 270, window_size.y * .4f + 20 + 5 * 4}};
                                            },
                                            "Replace all",
                                            config::design::text_color,
                                            config::design::btn_background_color,
                                            25));
    SetSprite("DeleteZerosButton", new Button({}, {},
                                            ON_RESIZE {
                                                return {{250, window_size.y * 0.1f},
                                                        {window_size.x - 270, window_size.y * .5f + 20 + 5 * 5}};
                                            },
                                            "Delete zeros",
                                            config::design::text_color,
                                            config::design::btn_background_color,
                                            25));
    SetSprite("RemoveLowerButton", new Button({}, {},
                                            ON_RESIZE {
                                                return {{250, window_size.y * 0.1f},
                                                        {window_size.x - 270, window_size.y * .6f + 20 + 5 * 6}};
                                            },
                                            "Remove lowers",
                                            config::design::text_color,
                                            config::design::btn_background_color,
                                            25));
    SetSprite("ReplaceStarByPlusButton", new Button({}, {},
                                              ON_RESIZE {
                                                  return {{250, window_size.y * 0.1f},
                                                          {window_size.x - 270, window_size.y * .7f + 20 + 5 * 7}};
                                              },
                                              "Replace stars",
                                              config::design::text_color,
                                              config::design::btn_background_color,
                                              25));
    SetSprite("RemoveInBraceButton", new Button({}, {},
                                              ON_RESIZE {
                                                  return {{250, window_size.y * 0.1f},
                                                          {window_size.x - 270, window_size.y * .8f + 20 + 5 * 8}};
                                              },
                                              "Remove in braces",
                                              config::design::text_color,
                                              config::design::btn_background_color,
                                              25));
    SetSprite("BackgroundColor", new BackgroundColor(config::design::background_color, ON_RESIZE NORMAL_RESIZE));
    SetSprite("TextLabel", new TextLabel({20, 20}, {},
                                         ON_RESIZE {
                                             return {{window_size.x - 310, window_size.y - 40}, position};
                                         },
                                         true,
                                         config::design::text_label_color,
                                         config::color::white,
                                         config::design::side_color,
                                         config::design::side_text_color,
                                         config::design::text_font_size));
}

void MainDesign::Render(bool do_clear) {
    AbstractDesign::Render(true);
}