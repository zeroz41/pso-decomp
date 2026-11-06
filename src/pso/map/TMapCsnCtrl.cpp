#include "pso/TMapCsnCtrl.h"
#include "pso/misc/TMapCsnCtrl.h"

#include "types.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

void TMapCsnCtrl::sub_80140F44() {
    *(s32 *)((s8 *)this + 0x1C) = 0;
}

extern s32 __vt__11TMapCsnCtrl[];
extern void *TMapCsnCtrl__class_name;

TMapCsnCtrl::~TMapCsnCtrl() {}
void *TMapCsnCtrl__ct(void *map_csn_ctrl) {
    __ct__7TObjectFP7TObject(map_csn_ctrl);
    *(s32 **)((s8 *)map_csn_ctrl + 0x18) = __vt__11TMapCsnCtrl;
    *(void * *)&((TMapCsnCtrl *)map_csn_ctrl)->m_name = TMapCsnCtrl__class_name;
    ((TMapCsnCtrl *)map_csn_ctrl)->sub_80140F44();
    return map_csn_ctrl;
}

}
