#include "types.h"
#include "pso/misc/TLobby_80227A2C.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/system/vector.h"
#include "pso/misc/TOTrapAncient01.h"

struct Vec_8022675C { f32 x, y, z; };

struct SndEnt_8022675C {
    s32 flags;
    s32 id;
    Vec_8022675C *src;
    Vec_8022675C pos;
    s16 prio;
    s16 x1a;
    s32 x1c;
    u8 pad[8];
};

extern "C" {
s32 fn_802264B8(int, int);
SndEnt_8022675C lbl_805145F0[40];
u8 lbl_80514C30[0x20];
f32 lbl_80514C50[4];
extern s32 last_sound_effect_slot;
extern s32 lbl_805D62B0;
extern s32 lbl_805DC748;
s32 play_sound_effect(s32 id, Vec_8022675C *src, s32 a2, s32 flags);
s32 check_sound_admission_range();

s32 TOTrapAncient01::check_trigger_flag(s32 arg0, s32 arg1) {
    s32 var_r3;

    if (arg1 & 0x2000) {
        var_r3 = 0;
    } else {
        var_r3 = check_sound_admission_range();
    }
    if (var_r3 == -0x100) {
        return 0;
    }
    return 1;
}
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags) {
    s32 idx = -1;
    s32 i;
    s32 ok;
    SndEnt_8022675C *e;

    last_sound_effect_slot = -1;
    if (lbl_805D62B0 == 0) {
        return -1;
    }
    if (id == 0xF0000) {
        return -1;
    }
    for (i = 0; i < 40; i++) {
        if ((lbl_805145F0[i].flags & 0x400) && id == lbl_805145F0[i].id) {
            idx = i;
            break;
        }
    }
    if (idx >= 0) {
        if (src != 0) {
            ok = TOTrapAncient01::check_trigger_flag(src, lbl_805145F0[idx].flags);
        } else {
            ok = fn_802264B8(idx, 1);
        }
        last_sound_effect_slot = idx;
        if (ok != 0) {
            e = &lbl_805145F0[idx];
            e->src = (Vec_8022675C *)src;
            e->x1a = a3;
            e->prio = 5;
            idx = normalize_sound_request(id, e->x1c, (s32)e->src, e->x1a, flags);
        }
        return idx;
    }
    if (TOTrapAncient01::check_trigger_flag(src, flags) != 0) {
        idx = normalize_sound_request(id, a1, src, a3, flags);
        last_sound_effect_slot = idx;
        if (idx >= 0) {
            lbl_805145F0[idx].flags &= lbl_805DC748;
            if (flags & 1) {
                lbl_805145F0[idx].flags |= 0x2000;
            }
            lbl_805145F0[idx].src = (Vec_8022675C *)src;
            lbl_805145F0[idx].x1a = a3;
            lbl_805145F0[idx].id = id;
            lbl_805145F0[idx].x1c = a1;
            lbl_805145F0[idx].prio = 5;
            lbl_805145F0[idx].flags |= 0x1600;
        } else {
            return -1;
        }
    }
    return idx;
}
s32 play_sound_effect(s32 id, Vec_8022675C *src, s32 a2, s32 flags) {
    s32 i;
    s32 idx;
    Vec_8022675C *pos;
    last_sound_effect_slot = -1;
    if (lbl_805D62B0 == 0) {
        return -1;
    }
    if (id == 0xF0000) {
        return -1;
    }
    idx = -1;
    for (i = 0; i < 40; i++) {
        if ((lbl_805145F0[i].flags & 0x400) && id == lbl_805145F0[i].id && lbl_805145F0[i].prio >= 0x94) {
            return -1;
        }
    }
    if (idx < 0) {
        idx = play_packed_sound_once(id, (s32)src, a2, flags);
    }
    if (idx >= 0) {
        if (src != NULL) {
            pos = &lbl_805145F0[idx].pos;
            VecCopy((Vec *)pos, (const Vec *)src);
            ((void (*)(s32, Vec_8022675C *))TLobby__sub_80227AF8)(idx, pos);
        }
        lbl_805145F0[idx].flags &= lbl_805DC748;
        if (flags & 1) {
            lbl_805145F0[idx].flags |= 0x2000;
        }
        lbl_805145F0[idx].src = src;
        lbl_805145F0[idx].prio = 0x96;
        lbl_805145F0[idx].x1a = a2;
        lbl_805145F0[idx].id = id;
        lbl_805145F0[idx].x1c = 0;
        if (fn_802264B8(idx, 0) == 1) {
            last_sound_effect_slot = idx;
            lbl_805145F0[idx].flags |= 0x600;
            return idx;
        }
    }
    return -1;
}

}
