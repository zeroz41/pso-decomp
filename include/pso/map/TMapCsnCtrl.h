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
typedef char TMapCsnCtrlExtent[sizeof(TMapCsnCtrl) == 0x81C ? 1 : -1];

// Defined by the map collision unit (TObjMapCsn.cpp), whose .sdata and .rodata it opens.
extern const char *TMapCsnCtrl__class_name;

typedef char TMapCsnCtrlGroupsOffset[offsetof(TMapCsnCtrl, groups) == 0x1C ? 1 : -1];

// TObjMapCsn adds and removes entries through these helpers.
extern "C" {
void fn_80140DFC(s32 arg0, s32 arg1);
void fn_80140EA8(s32 arg0, s32 arg1);
}
void remove_value_from_id_list(s32 arg0, u32 arg1);

#endif
