#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_80071820_lbl_804FF820 {
    s32 value;
    u8 remaining[0x8];
};

struct E_80071868 { s32 a; s32 b; };

struct W_80071868 { u8 pad[0x2288]; E_80071868 e[3]; u8 pad2[0xc]; s32 def; };

struct G_800718D0 { u8 pad[0xC]; s32 fc; u8 rest[0x100]; };

extern "C" {
s32 get_layout_id__20TWindowSubStatusDispFv(void *);
s32 TWindowSubStatusDisp__sub_8006F0D8(void *, void *);
u32 get_character_save_record(u32);
extern RecoveredGlobal_80071820_lbl_804FF820 lbl_804FF820;
extern s32 lbl_805D2858;
s32 get_slot_clamped__6TLobbyFv(s32);
s32 calc_layout_hash__20TWindowSubStatusDispFv(int);
s32 is_flag_set__6TLobbyFv();
extern G_800718D0 challenge_mode_state;
s32 TLobby__sub_80071654(u16);

s32 TWindowSubStatusDisp::get_status_index(int arg0) {
    u32 character_save_record;

    character_save_record = get_character_save_record((u16)arg0);
    if (character_save_record == 0U) {
        return -1;
    }
    return TWindowSubStatusDisp::get_status_index_or_default((u16 *)(character_save_record + 0x21C4));
}

s32 TWindowSubStatusDisp::get_status_index_or_default(u16 *arg0) {
    if (arg0 == NULL) {
        return -1;
    }
    return TLobby__sub_80071654(*arg0);
}

extern s32 lbl_805D285C;

s32 *TWindowSubStatusDisp::get_status_window(int arg0) {
    u32 character_save_record;

    character_save_record = get_character_save_record((u16)arg0);
    if (character_save_record == 0U) {
        return &lbl_805D285C;
    }
    return TWindowSubStatusDisp__sub_80071820(character_save_record + 0x21C4);
}

typedef char RecoveredGlobal_80071820_lbl_804FF820_size[sizeof(RecoveredGlobal_80071820_lbl_804FF820) == 0xC ? 1 : -1];
s32 *TWindowSubStatusDisp__sub_80071820(u32 arg0) {
    if (arg0 == 0U) {
        return &lbl_805D2858;
    }
    ((TLobby *)(&lbl_804FF820.value))->decode_obfuscated_string((void *)(arg0 + 0xD8), 0xC);
    return &lbl_804FF820.value;
}

s32 TWindowSubStatusDisp__sub_80071868(u16 id, s32 slot) {
    W_80071868 *w = (W_80071868 *)get_character_save_record(id);
    s32 idx;
    s32 v;
    if (w == 0) {
        return 0;
    }
    idx = TWindowSubStatusDisp::resolve_player_slot(slot);
    if (idx < 3) {
        v = w->e[idx].a;
    } else {
        v = w->def;
    }
    return get_slot_clamped__6TLobbyFv(v);
}

s32 TWindowSubStatusDisp__sub_800718D0(void) {
    s32 last;
    s32 hash;
    s32 sum;
    s32 i;
    s32 r;
    hash = calc_layout_hash__20TWindowSubStatusDispFv(-1);
    if (is_flag_set__6TLobbyFv() == 0 || get_character_save_record(0xFFFF) == 0) {
        return hash;
    }
    sum = 0;
    last = get_layout_id__20TWindowSubStatusDispFv((void *)-1);
    for (i = 0; i <= last - 2; i++) {
        r = TWindowSubStatusDisp__sub_80071A24(i, 0xFFFF, -1);
        if (r == 0) {
            return hash;
        }
        sum += r;
    }
    sum += challenge_mode_state.fc;
    return sum;
}

s32 TWindowSubStatusDisp__sub_80071988(s32 arg0, s32 slot) {
    s32 *p;
    s32 n;
    s32 r;
    s32 sum;
    s32 i;
    u32 w;
    w = get_character_save_record((u16)arg0);
    if (w == 0U) {
        return 0;
    }
    p = (s32 *)TWindowSubStatusDisp__sub_8006F0D8((void *)(w + 0x21C4), (void *)slot);
    sum = 0;
    n = get_layout_id__20TWindowSubStatusDispFv((void *)slot);
    for (i = 0; i < n; i++, p++) {
        r = TLobby::get_valid_slot(*p);
        if (r == 0) {
            return 0;
        }
        sum += r;
    }
    return sum;
}

s32 TWindowSubStatusDisp__sub_80071A24(s32 arg0, u16 arg1, s32 slot) {
    s32 temp_r3;
    u32 character_save_record;
    character_save_record = get_character_save_record((u32)arg1);
    temp_r3 = get_layout_id__20TWindowSubStatusDispFv((void *)slot);
    if ((arg0 < 0) || (arg0 >= temp_r3) || (character_save_record == 0U)) {
        return 0;
    }
    return TLobby::get_valid_slot((int) (*(s32 *)((s8 *)(TWindowSubStatusDisp__sub_8006F0D8((void *)(character_save_record + 0x21C4), (void *)slot)) + (arg0 * 4))));
}

}
