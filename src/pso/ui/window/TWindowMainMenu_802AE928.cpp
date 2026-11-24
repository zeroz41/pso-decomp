#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMenuMainMenu.h"

TWindowMenuMainMenu *TWindowMainMenu::create_menu(const NJS_POINT2 *position, s32 client) {
    return new TWindowMenuMainMenu(position, client);
}
