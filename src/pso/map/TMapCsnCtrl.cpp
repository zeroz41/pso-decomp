#include "pso/map/TMapCsnCtrl.h"

#include "pso/map/TObjMapCsn.h"
#include "types.h"
#include "pso/unk/TLobby_80140FF4.h"

void fn_80140DFC(TMapCsnCtrl *controller, TObjMapCsn *object) {
    remove_collision_group(controller, TLobby__sub_80141030(object));
}

void remove_collision_group(TMapCsnCtrl *controller, CsnGroup *group) {
    s32 i;
    CsnGroup **p = controller->groups;
    for (i = 0; i < 0x200; p++, i++) {
        if (*p == group) {
            CsnGroup **src;
            CsnGroup **dst = p;
            s32 k;
            src = ++p;
            for (k = i; k < 0x200; k++) {
                *dst = *src++;
                if (*++dst == NULL) {
                    return;
                }
            }
            *p = NULL;
            return;
        }
    }
}

void fn_80140EA8(TMapCsnCtrl *controller, TObjMapCsn *object) {
    register_slot(controller, TLobby__sub_80141030(object));
}

void register_slot(TMapCsnCtrl *controller, CsnGroup *group) {
    s32 i;
    CsnGroup **slot = controller->groups;
    for (i = 0; i < 0x200; i++, slot++) {
        if (*slot == NULL) {
            slot[0] = group;
            slot[1] = NULL;
            return;
        }
    }
}

void collect_collision_groups(TMapCsnCtrl *controller, CsnGroup *groups) {
    CsnGroup **slot = controller->groups;
    while (groups->model != NULL) {
        *slot++ = groups++;
    }
    *slot = NULL;
}

// TObjMapCsn's name lives in this TU (.sdata 0x805D2CD0, string 0x8043F268), as TMapCsnCtrl's lives in
// TObjMapCsn.cpp.
const char *TObjMapCsn__class_name = "TObjMapCsn";

void TMapCsnCtrl::sub_80140F44() {
    groups[0] = NULL;
}

TMapCsnCtrl::~TMapCsnCtrl() {}

TMapCsnCtrl::TMapCsnCtrl(TObject *parent) : TObject(parent) {
    m_name = TMapCsnCtrl__class_name;
    sub_80140F44();
}
