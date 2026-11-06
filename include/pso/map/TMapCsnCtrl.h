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
typedef char TMapCsnCtrlExtent[sizeof(TMapCsnCtrl) == 0x81C ? 1 : -1];

#endif
