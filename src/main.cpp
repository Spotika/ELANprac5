#include "../ELANsfml/Singletons/ELANsfml.h"
#include "../src/Apps/MainApp.h"
#include "ELANsfml/Singletons/ELANsfml.h"
#include "src/Apps/MainApp.h"
#include "src/Apps/Popups/DeleteButtonPopupApp.h"
#include "src/Apps/Popups/DeleteZerosButtonPopupApp.h"
#include "src/Apps/Popups/InsertButtonPopupApp.h"
#include "src/Apps/Popups/InsertSubstringButtonPopupApp.h"
#include "src/Apps/Popups/RemoveInBraceButtonPopupApp.h"
#include "src/Apps/Popups/RemoveLowerButtonPopupApp.h"
#include "src/Apps/Popups/ReplaceAllButtonPopupApp.h"
#include "src/Apps/Popups/ReplaceCharacterButtonPopupApp.h"
#include "src/Apps/Popups/ReplaceStarByPlusButtonPopupApp.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
  ELANsfml::LinkApp<MainApp>("MainApp");
  ELANsfml::LinkApp<InsertButtonPopupApp>("InsertButtonPopupApp");
  ELANsfml::LinkApp<DeleteButtonPopupApp>("DeleteButtonPopupApp");
  ELANsfml::LinkApp<InsertSubstringButtonPopupApp>(
      "InsertSubstringButtonPopupApp");
  ELANsfml::LinkApp<ReplaceCharacterButtonPopupApp>(
      "ReplaceCharacterButtonPopupApp");
  ELANsfml::LinkApp<ReplaceAllButtonPopupApp>("ReplaceAllButtonPopupApp");
  ELANsfml::LinkApp<DeleteZerosButtonPopupApp>("DeleteZerosButtonPopupApp");
  ELANsfml::LinkApp<RemoveLowerButtonPopupApp>("RemoveLowerButtonPopupApp");
  ELANsfml::LinkApp<ReplaceStarByPlusButtonPopupApp>(
      "ReplaceStarByPlusButtonPopupApp");
  ELANsfml::LinkApp<RemoveInBraceButtonPopupApp>("RemoveInBraceButtonPopupApp");

  ELANsfml::Start("MainApp");

  return 0;
}
