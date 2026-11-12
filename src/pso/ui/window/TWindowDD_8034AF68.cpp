#include "types.h"
#include "pso/ui/frontend/TAdFloorLoadPrtGC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80086E28.h"
#include "pso/unk/text_8034AD38.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowDD_8034AF68.h"
#include "pso/ui/window/TWindowDD.h"

struct Slot_8034AD38 { void *ctrl; u8 pad[0x18]; };

struct TAdFloorLoadPrtGC_8034AD38 {
    u8 pad0[0x18];
    void *vtable;
    u8 pad1c[0x34 - 0x1C];
    Slot_8034AD38 slots[32];
};

struct Vec_8034ADE0 { f32 x, y, z; };

struct Ang_8034ADE0 { s32 x, y, z; };

struct Slot_8034ADE0 { Vec_8034ADE0 pos; Ang_8034ADE0 ang; void *ctrl; };

struct Prt_8034ADE0 {
    const char *name;
    u8 pad4[0x18 - 4];
    void *vtable;
    Slot_8034ADE0 slots[32];
    void *bg;
};

extern "C" {
extern void *__vt__17TAdFloorLoadPrtGC[];
s32 __ct__7TObjectFP7TObject(void *);
void *memset(void *, int, u32);
extern const Vec_8034ADE0 floor_load_particle_positions[12] = {
    { 0.0f, 0.0f, 100.0f },
    { 0.0f, 49.0f, 86.2f },
    { 0.0f, 86.2f, 49.8f },
    { 0.0f, 100.0f, 0.0f },
    { 0.0f, 86.2f, -49.8f },
    { 0.0f, 49.8f, -86.2f },
    { 0.0f, 0.0f, -100.0f },
    { 0.0f, -49.0f, -86.2f },
    { 0.0f, -86.2f, -49.8f },
    { 0.0f, -100.0f, 0.0f },
    { 0.0f, -86.2f, 49.8f },
    { 0.0f, -49.8f, 86.2f },
};
extern const Ang_8034ADE0 TAdFloorLoadPrtGC__emitter_angles[12] = {
    { 0x0, 0x0, 0x0 },
    { 0x1555, 0x0, 0x0 },
    { 0x2AAA, 0x0, 0x0 },
    { 0x4000, 0x0, 0x0 },
    { 0x5555, 0x0, 0x0 },
    { 0x6AAA, 0x0, 0x0 },
    { 0x8000, 0x0, 0x0 },
    { 0x9555, 0x0, 0x0 },
    { 0xAAAA, 0x0, 0x0 },
    { 0xC000, 0x0, 0x0 },
    { 0xD555, 0x0, 0x0 },
    { 0xEAAA, 0x0, 0x0 },
};
extern const Vec_8034ADE0 lbl_80478B48[1] = { { 0.0f, 0.0f, 0.0f } };
extern const Ang_8034ADE0 lbl_80478B54[1] = { { 0x0, 0x0, 0x4000 } };
const char *TAdFloorLoadPrtGC__class_name = "TAdFloorLoadPrtGC";
Prt_8034ADE0 *TAdFloorLoadPrtGC__ct(Prt_8034ADE0 *arg0);
}
TAdFloorLoadPrtGC::~TAdFloorLoadPrtGC() {
    s32 i;
    if (*(void **)((u8 *)this + 0x39C)) {
        queue_destruction__7TObjectFv(*(void **)((u8 *)this + 0x39C));
        *(void **)((u8 *)this + 0x39C) = NULL;
    }
    for (i = 0; i < 32; i++) {
        if (((TAdFloorLoadPrtGC_8034AD38 *)this)->slots[i].ctrl) {
            queue_destruction__7TObjectFv(((TAdFloorLoadPrtGC_8034AD38 *)this)->slots[i].ctrl);
            ((TAdFloorLoadPrtGC_8034AD38 *)this)->slots[i].ctrl = NULL;
        }
    }
}


#pragma push
#pragma opt_common_subs off
Prt_8034ADE0 *TAdFloorLoadPrtGC__ct(Prt_8034ADE0 *arg0) {
    const Ang_8034ADE0 *a;
    const Vec_8034ADE0 *p;
    s32 i;
    __ct__7TObjectFP7TObject(arg0);
    arg0->vtable = __vt__17TAdFloorLoadPrtGC;
    arg0->name = TAdFloorLoadPrtGC__class_name;
    memset(arg0->slots, 0, sizeof(arg0->slots));
    arg0->bg = 0;
    for (i = 0; i < 12; i++) {
        VecCopy((Vec *)&arg0->slots[i].pos, (const Vec *)(p = &floor_load_particle_positions[i]));
        copy_xyz(&arg0->slots[i].ang, (void *)(a = &TAdFloorLoadPrtGC__emitter_angles[i]));
        arg0->slots[i].ctrl = create_particle_controller_with_angles((void *)p, (void *)a, 0x65, 1, 0x40);
    }
    arg0->bg = create_particle_controller_with_angles((void *)lbl_80478B48, (void *)lbl_80478B54, 0x2F, 1, 0x40);
    return arg0;
}
#pragma pop

struct H_8034AF68 { u32 f0; s32 f4; };

struct G_8034AF68 {
    s16 ids[16];
    H_8034AF68 *a;
    H_8034AF68 *b;
    u32 a0;
    u32 b0;
    s32 n;
};

extern G_8034AF68 lbl_804F0070;

void push_recent_id(s16 arg0) {
    s32 i;
    if (arg0 != lbl_804F0070.ids[0]) {
        for (i = 15; i > 0; i--) {
            lbl_804F0070.ids[i] = lbl_804F0070.ids[i - 1];
        }
        lbl_804F0070.ids[0] = arg0;
    }
}
void clear_window_dd_nodes(void) {
    if (lbl_804F0070.a == NULL || lbl_804F0070.b == NULL) {
        return;
    }
    lbl_804F0070.a->f4 = lbl_804F0070.n;
    lbl_804F0070.b->f4 = lbl_804F0070.n;
    lbl_804F0070.a = NULL;
    lbl_804F0070.b = NULL;
    lbl_804F0070.a0 = 0;
    lbl_804F0070.b0 = 0;
}

struct RecoveredGlobal_8034B008_lbl_80478B78 {
    s32 value;
    u8 remaining[0x2C];
};

struct Ent_8034B050 { s32 *list; s32 count; s32 result; };

extern RecoveredGlobal_8034B008_lbl_80478B78 word_select_type_state_table;
extern H_8034AF68 *TWindowDD__ws_data_base;
extern H_8034AF68 *TWindowDD__ws_data_table;
extern Ent_8034B050 lbl_804F0040[4];
extern s32 TWindowDD__window_mode;
extern s8 lbl_805D6E90;
extern s32 lbl_805DFD84;
extern s32 lbl_805DFD88;
extern s32 lbl_805DFD8C;
extern s32 lbl_805DFD90;
typedef char RecoveredGlobal_8034B008_lbl_80478B78_size[sizeof(RecoveredGlobal_8034B008_lbl_80478B78) == 0x30 ? 1 : -1];

void TWindowDD::init_ws_data_tables() {
    H_8034AF68 *a = TWindowDD__ws_data_base;
    H_8034AF68 *b;
    s32 i;
    s32 x;
    s32 y;
    if (a == NULL || (b = TWindowDD__ws_data_table) == NULL) {
        return;
    }
    for (i = 0; i < 16; i++) {
        lbl_804F0070.ids[i] = -1;
    }
    lbl_804F0070.a = a;
    lbl_804F0070.b = b;
    lbl_804F0070.a0 = a->f0;
    lbl_804F0070.b0 = b->f0;
    if (lbl_804F0070.a0 == 0 || lbl_804F0070.b0 == 0) {
        return;
    }
    x = a->f4;
    y = b->f4;
    if (x < 1 || y < 1 || x != y) {
        return;
    }
    lbl_804F0070.n = x;
}

s32 TWindowDD__sub_8034B008(s32 arg0, s32 arg1) {
    return *(s32 *)((s8 *)((u8 *)(((u8 *)&word_select_type_state_table.value + (TWindowDD::lookup_item_category((s32)arg1) * 8))) + (arg0 * 4)) + 0);
}
s32 TWindowDD::lookup_item_category(s32 arg0) {
    s32 r;
    s32 i;
    s32 j;
    Ent_8034B050 *e;
    s32 *list;
    if (lbl_805D6E90 == 0) {
        lbl_804F0040[0].count = lbl_805DFD84;
        lbl_804F0040[1].count = lbl_805DFD88;
        lbl_804F0040[2].count = lbl_805DFD8C;
        lbl_804F0040[3].count = lbl_805DFD90;
        lbl_805D6E90 = 1;
    }
    r = 5;
    for (i = 0; i < 4; i++) {
        e = &lbl_804F0040[i];
        list = e->list;
        for (j = 0; j < e->count; j++) {
            if (arg0 == list[j]) {
                r = e->result;
                break;
            }
        }
        if (r != 5) {
            break;
        }
    }
    if (r == 2 && TWindowDD__window_mode == 0) {
        r = 1;
    }
    return r;
}
