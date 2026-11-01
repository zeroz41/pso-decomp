#include "types.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_80202A68.h"
#include "pso/unk/text_8007C0CC.h"
#include "pso/misc/TWindowKeyBoardHard_801FBA48.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/ui/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/main_loop.h"
#include "pso/misc/TWindowKeyBoardHard.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TQuestVmDownLoadServer.h"

extern "C" {
f32 rotate_matrix_by_node_angles(void *, void *);
s32 push_matrix();
s32 scale_current_matrix(void *);
f32 post_translate_matrix(void *);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
void subtractive_rng_seed(void *, s32);
void copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
extern u8 chr_select_rng_state[];
extern s32 chr_select_serial_seeds[];
char *strncpy(char *, const char *, u32);
void *memcpy(void *, const void *, u32);
extern char lbl_804C8954[];
extern s32 lbl_805D49B4;
void poll_load_status__15TAdPlayerLoadGCFl(s32, void *);
extern char lbl_804C88C0[];
extern char lbl_804C89BC[];
extern char pso_system_card_filename[];
int TWindowKeyBoardHard::is_card_flag_set() { return TWindowKeyBoardHard::test_card_flag((s32)this, 1); }
void draw_ginja_box_tree(u8 *arg0) {
    s32 temp_r31;
    u8 *temp_r3;
    u8 *var_r30;
    var_r30 = arg0;
    do {
        temp_r31 = *(s32 *)((s8 *)var_r30 + 0);
        push_matrix();
        if (!(temp_r31 & 1)) {
            post_translate_matrix(var_r30 + 8);
        }
        if (!(temp_r31 & 2)) {
            rotate_matrix_by_node_angles(var_r30 + 0x14, (void *) (temp_r31 & 0x20));
        }
        if (!(temp_r31 & 4)) {
            scale_current_matrix(var_r30 + 0x20);
        }
        if (!(temp_r31 & 0x100000)) {
            TParticleCtrl::end_effect_render();
        } else {
            TParticleCtrl::begin_effect_render();
        }
        if (!(temp_r31 & 8)) {
            draw_ginja_model((*(s32 *)((s8 *)var_r30 + 4)));
        }
        if (!(temp_r31 & 0x10)) {
            temp_r3 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x2C));
            if (temp_r3 != NULL) {
                draw_ginja_box_tree(temp_r3);
            }
        }
        pop_matrix();
        var_r30 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x30));
    } while (var_r30 != NULL);
}

void TAdSinglePlyChrSelectGC__sub_801FBB1C(void) {
    s32 r;
    if (TAdPlayerLoadGC::probe_and_check_card(0) != 0) {
        r = TAdPlayerLoadGC::find_card_file(0, lbl_804C88C0);
        if (r == 0 || (u32)r == 0xFFFFFF41U) {
            poll_load_status__15TAdPlayerLoadGCFl(0, lbl_804C88C0);
        }
    }
}

void TAdSinglePlyChrSelectGC__sub_801FBB7C(void) {
    s32 r;
    if (TAdPlayerLoadGC::probe_and_check_card(0) != 0) {
        r = TAdPlayerLoadGC::find_card_file(0, lbl_804C89BC);
        if (r == 0 || (u32)r == 0xFFFFFF41U) {
            poll_load_status__15TAdPlayerLoadGCFl(0, lbl_804C89BC);
        }
    }
}

void TAdSinglePlyChrSelectGC::try_load_system_file() {
    s32 r;
    if (TAdPlayerLoadGC::probe_and_check_card(0) != 0) {
        r = TAdPlayerLoadGC::find_card_file(0, pso_system_card_filename);
        if (r == 0 || (u32)r == 0xFFFFFF41U) {
            poll_load_status__15TAdPlayerLoadGCFl(0, pso_system_card_filename);
        }
    }
}

void TAdSinglePlyChrSelectGC__sub_801FBC3C(void *arg0) {
    void *a;
    void *b;
    a = ::operator new(0x194B0);
    if (a != 0) {
        a = ((TAdSinglePlyChrSelectGC *)a)->construct_chardata_array();
    }
    b = ::operator new(0x194B0);
    if (b != 0) {
        b = ((TAdSinglePlyChrSelectGC *)b)->construct_chardata_array();
    }
    copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(a, arg0);
    subtractive_rng_seed(chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle((s32 *)chr_select_rng_state);
    subtractive_rng_unshuffle((void *)chr_select_rng_state, (const u8 *)a, (u8 *)b, (u32)(0x194B0));
    copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(arg0, b);
    destroy_chardata_array__23TAdSinglePlyChrSelectGCFis((s32)b, (s16)(1));
    destroy_chardata_array__23TAdSinglePlyChrSelectGCFis((s32)a, (s16)(1));
    subtractive_rng_seed(chr_select_rng_state, chr_select_serial_seeds[0]);
    ((TAdSinglePlyChrSelectGC *)chr_select_rng_state)->apply_rng_cipher((u32 *)arg0, 0x194B0);
    subtractive_rng_seed(chr_select_rng_state, TAdSinglePlyChrSelectGC__sub_80202A68((u8 *)arg0));
    subtractive_rng_xor_buffer((s32 *)chr_select_rng_state, (u32 *)arg0, 0x194AC);
}

u8 TAdSinglePlyChrSelectGC::load_and_verify_character_save(char *desc) {
    s32 sum;
    u8 *buf;
    s32 res;
    u8 *data;
    s32 saved;
    buf = (u8 *)((TQuestVmDownLoadServer *)0x214B0)->alloc();
    res = TAdPlayerLoadGC::find_card_file(0, lbl_804C8954);
    if (res == 0) {
        lbl_805D49B4 = 1;
        TAdSinglePlyChrSelectGC::set_card_disk_id(0);
        res = TAdSinglePlyChrSelectGC::load_player_slot(0, lbl_804C8954, buf);
        TAdSinglePlyChrSelectGC::wait_for_card_load(0);
        TAdSinglePlyChrSelectGC::copy_name(0);
    }
    if (res != 0) {
        lbl_805D49B4 = 0;
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        return 0;
    }
    if (load_system_file__23TAdSinglePlyChrSelectGCFiPv(0, &sum) == 0) {
        lbl_805D49B4 = 0;
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        return 0;
    }
    lbl_805D49B4 = 0;
    chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = sum;
    data = (u8 *)((TQuestVmDownLoadServer *)0x194B0)->alloc();
    memcpy(data, buf + 0x2048, 0x194B0);
    TAdSinglePlyChrSelectGC__sub_801FBC3C(data);
    saved = *(s32 *)data;
    *(s32 *)data = 0;
    res = TAdSinglePlyChrSelectGC__sub_80201204(data, 0x194B0);
    strncpy(((char *)this), (char *)(data + 0x193F0), 0x10);
    strncpy(desc, (char *)(data + 0x19400), 0x10);
    TAdSinglePlyChrSelectGC::safe_free((u32)data);
    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
    return saved == res;
}

s32 TAdSinglePlyChrSelectGC::wait_for_card_load(s32 arg0) {
    while (TAdPlayerLoadGC__sub_801E1B50(arg0) != 0) {
        if (TAdPlayerLoadGC::probe_card_slot(arg0) != 1) {
            return 0;
        }
        render_frame__23TAdSinglePlyChrSelectGCFv();
        render_tick();
    }
    return 1;
}

}
