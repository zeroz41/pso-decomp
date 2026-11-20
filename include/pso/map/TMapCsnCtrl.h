#ifndef PSO_MAP_TMAPCSNCTRL_H
#define PSO_MAP_TMAPCSNCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TMapCsnCtrl : public TObject {
public:
    TMapCsnCtrl(TObject *parent);
    virtual ~TMapCsnCtrl();
    void sub_80140F44();

    s32 unk_1C;
    u8 pad_20[0x7FC];
};
LAYOUT_ASSERT(TMapCsnCtrlExtent, sizeof(TMapCsnCtrl) == 0x81C);

// Defined by the map collision unit (TObjMapCsn.cpp), whose .sdata and .rodata it opens.
extern const char *TMapCsnCtrl__class_name;

// Helpers on a TMapCsnCtrl's zero-terminated list of 0x200 entries at +0x1C (unk_1C is its first
// entry); TObjMapCsn adds and removes itself through them.
extern "C" {
void fn_80140DFC(saddr arg0, saddr arg1);
void fn_80140EA8(saddr arg0, saddr arg1);
}
void remove_value_from_id_list(saddr arg0, uaddr arg1);

#endif
