cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories("./")

add_executable(CMakeSFMLProject src/main.cpp
        ELANsfml/Helpers/Singleton.h
        ELANsfml/Singletons/Screen.h
        ELANsfml/Singletons/EventHandler.h
        ELANsfml/Singletons/AppManager.h
        ELANsfml/Apps/AbstractApp.h
        ELANsfml/Singletons/ELANsfml.h
        ELANsfml/Singletons/src/ELANsfml.cpp
        ELANsfml/Singletons/src/AppManager.cpp
        ELANsfml/Singletons/src/EventHandler.cpp
        ELANsfml/Helpers/Config.h
        ELANsfml/Helpers/MonoFactory.h
        ELANsfml/Singletons/src/Screen.cpp
        src/Apps/MainApp.h
        src/Apps/src/MainApp.cpp
        ELANsfml/Sprites/AbstractSprite.h
        ELANsfml/Designs/AbstractDesign.h
        src/Designs/MainDesign.h
        src/Designs/src/MainDesign.cpp
        ELANsfml/Sprites/Button.h
        ELANsfml/Sprites/Functional/ButtonFunctional.h
        ELANsfml/Sprites/src/Button.cpp
        ELANsfml/Sprites/BackgroundColor.h
        ELANsfml/Sprites/src/Background.cpp
        ELANsfml/Sprites/TextInput.h
        ELANsfml/Sprites/src/TextInput.cpp
        ELANsfml/Sprites/src/TextInput.cpp
        ELANsfml/Sprites/src/TextInput.cpp
        ELANsfml/Sprites/src/TextInput.cpp
        ELANsfml/Sprites/Functional/TextInputFunctional.h
        ELANsfml/Sprites/TextLabel.h
        ELANsfml/Sprites/src/TextLabel.cpp
        ELANsfml/Sprites/Functional/TextLabelFunctional.h
        ELANsfml/Sprites/Functional/TextLabelFunctional.h
        ELANsfml/Sprites/Functional/TextLabelFunctional.h
        ELANsfml/Sprites/Functional/TextLabelFunctional.h
        ELANsfml/Sprites/Inheritance/Activatable.h
        src/Apps/Popups/InsertButtonPopupApp.h
        ELANsfml/Sprites/PlainText.h
        ELANsfml/Sprites/src/PlainText.cpp
        ELANsfml/Sprites/src/PlainText.cpp
        ELANsfml/Sprites/src/PlainText.cpp
        src/Apps/Popups/src/InsertButtonPopupApp.cpp
        src/Designs/Popups/InsertButtonPopupDesign.h
        src/Designs/Popups/src/InsertButtonPopupDesign.cpp
        src/Apps/Popups/DeleteButtonPopupApp.h
        src/Apps/Popups/src/DeleteButtonPopupApp.cpp
        src/Designs/Popups/src/DeleteButtonPopupDesign.cpp
        src/Apps/Popups/src/InsertSubstringButtonPopupApp.cpp
        src/Designs/Popups/InsertSubstringButtonPopupDesign.h
        src/Designs/Popups/src/InsertSubstringButtonPopupDesign.cpp
        src/Apps/Popups/ReplaceAllButtonPopupApp.h
        src/Apps/Popups/src/ReplaceAllButtonPopupApp.cpp
        src/Designs/Popups/src/ReplaceAllButtonPopupDesign.cpp
        src/Apps/Popups/src/ReplaceCharacterButtonPopupApp.cpp
        src/Designs/Popups/ReplaceCharacterButtonPopupDesign.h
        src/Designs/Popups/src/ReplaceCharacterButtonPopupDesign.cpp
        src/Apps/Popups/ReplaceCharacterButtonPopupApp.h
        src/Apps/Popups/ReplaceCharacterButtonPopupApp.h
        src/Apps/Popups/ReplaceCharacterButtonPopupApp.h
        src/Designs/Popups/DeleteZerosButtonPopupDesign.h
        src/Designs/Popups/src/DeleteZerosButtonPopupDesign.cpp
        src/Apps/Popups/DeleteZerosButtonPopupApp.h
        src/Apps/Popups/src/DeleteZerosButtonPopupApp.cpp
        src/Apps/Popups/src/DeleteZerosButtonPopupApp.cpp
        src/Apps/Popups/src/DeleteZerosButtonPopupApp.cpp
        src/Designs/Popups/RemoveLowerButtonPopupDesign.h
        src/Designs/Popups/src/RemoveLowerButtonPopupDesign.cpp
        src/Apps/Popups/RemoveLowerButtonPopupApp.h
        src/Apps/Popups/src/RemoveLowerButtonPopupApp.cpp
        src/Designs/Popups/ReplaceStarByPlusButtonPopupDesign.h
        src/Designs/Popups/src/ReplaceStarByPlusButtonPopupDesign.cpp
        src/Apps/Popups/ReplaceStarByPlusButtonPopupApp.h
        src/Apps/Popups/src/ReplaceStarByPlusButtonPopupApp.cpp
        src/Designs/Popups/RemoveInBraceButtonPopupDesign.h
        src/Designs/Popups/src/RemoveInBraceButtonPopupDesign.cpp
        src/Apps/Popups/RemoveInBraceButtonPopupApp.h
        src/Apps/Popups/src/RemoveInBraceButtonPopupApp.cpp
        src/Engine/TextLabelAdapter.h
        src/Engine/src/TextLabelAdapter.cpp
)


target_link_libraries(CMakeSFMLProject PRIVATE sfml-graphics sfml-audio)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_20)

if (WIN32)
    add_custom_command(
            TARGET CMakeSFMLProject
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
            VERBATIM)
endif ()

install(TARGETS CMakeSFMLProject)
