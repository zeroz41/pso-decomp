#include "pso/map/TMapCsnCtrl.h"

#include "pso/map/TObjMapCsn.h"
#include "types.h"
#include "pso/unk/TLobby_80140FF4.h"

void TMapCsnCtrl::remove_object(TObjMapCsn *object) {
    remove_group(get_map_collision_group(object));
}

void TMapCsnCtrl::remove_group(CsnGroup *group) {
    s32 i;
    CsnGroup **p = groups;
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

void TMapCsnCtrl::add_object(TObjMapCsn *object) {
    add_group(get_map_collision_group(object));
}

void TMapCsnCtrl::add_group(CsnGroup *group) {
    s32 i;
    CsnGroup **slot = groups;
    for (i = 0; i < 0x200; i++, slot++) {
        if (*slot == NULL) {
            slot[0] = group;
            slot[1] = NULL;
            return;
        }
    }
}

void TMapCsnCtrl::set_groups(CsnGroup *source) {
    CsnGroup **slot = groups;
    while (source->model != NULL) {
        *slot++ = source++;
    }
    *slot = NULL;
}

// TObjMapCsn's name lives in this TU, as TMapCsnCtrl's lives in
// TObjMapCsn.cpp.
const char *TObjMapCsn::class_name = "TObjMapCsn";

void TMapCsnCtrl::clear_groups() {
    groups[0] = NULL;
}

TMapCsnCtrl::~TMapCsnCtrl() {}

TMapCsnCtrl::TMapCsnCtrl(TObject *parent) : TObject(parent) {
    m_name = TMapCsnCtrl::class_name;
    clear_groups();
}
