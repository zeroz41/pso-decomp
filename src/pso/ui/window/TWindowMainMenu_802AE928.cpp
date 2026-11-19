#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *__ct__19TWindowMenuMainMenuFls(void *, void *, void *);

void *TWindowMainMenu::create_menu(void *arg0, void *arg1) {
    void *o;
    o = TObject::operator new(0x144);
    if (o != NULL) {
        o = __ct__19TWindowMenuMainMenuFls(o, arg0, arg1);
    }
    return o;
}

}
