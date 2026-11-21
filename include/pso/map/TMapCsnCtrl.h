#ifndef PSO_MAP_TMAPCSNCTRL_H
#define PSO_MAP_TMAPCSNCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

struct CsnGroup;

class TMapCsnCtrl : public TObject {
public:
    TMapCsnCtrl(TObject *parent);
    virtual ~TMapCsnCtrl();
    void sub_80140F44();
    CsnGroup **get_collision_groups();

    CsnGroup *groups[0x200];
};
LAYOUT_ASSERT(TMapCsnCtrlExtent, sizeof(TMapCsnCtrl) == 0x81C);

// Defined by the map collision unit (TObjMapCsn.cpp), whose .sdata and .rodata it opens.
extern const char *TMapCsnCtrl__class_name;

LAYOUT_ASSERT(TMapCsnCtrlGroupsOffset, offsetof(TMapCsnCtrl, groups) == 0x1C);

struct TObjMapCsn;

extern "C" {
void fn_80140DFC(TMapCsnCtrl *controller, TObjMapCsn *object);
void remove_collision_group(TMapCsnCtrl *controller, CsnGroup *group);
void fn_80140EA8(TMapCsnCtrl *controller, TObjMapCsn *object);
void register_slot(TMapCsnCtrl *controller, CsnGroup *group);
void collect_collision_groups(TMapCsnCtrl *controller, CsnGroup *groups);
}

#endif
