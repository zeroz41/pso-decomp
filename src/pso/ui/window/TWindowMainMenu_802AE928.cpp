#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TWindowMenuMainMenu__ct(void *, void *, void *);

void *TWindowMainMenu::create_menu(void *arg0, void *arg1) {
    void *o;
    o = TObject::operator new(0x144);
    if (o != NULL) {
        o = TWindowMenuMainMenu__ct(o, arg0, arg1);
    }
    return o;
}

}
