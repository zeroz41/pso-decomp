#include "pso/system/memory.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_80202A68.h"
#include "pso/system/SubtractiveRng.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/main_loop.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include <string.h>

extern "C" {
void copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
extern SubtractiveRng chr_select_rng_state;
extern s32 chr_select_serial_seeds[];
extern char memory_card_character_dir_name[];
extern s32 memcard_access_active;
}
int TWindowKeyBoardHard::is_card_flag_set() { return TWindowKeyBoardHard::test_card_flag((saddr)this, 1); }
void draw_ginja_box_tree(NJS_OBJECT *node) {
    u32 flags;
    NJS_OBJECT *child;
    do {
        flags = node->evalflags;
        push_matrix();
        if (!(flags & 1)) {
            post_translate_matrix(node->pos);
        }
        if (!(flags & 2)) {
            rotate_matrix_by_node_angles(node->ang, flags & 0x20);
        }
        if (!(flags & 4)) {
            scale_current_matrix(node->scl);
        }
        if (!(flags & 0x100000)) {
            TParticleCtrl::end_effect_render();
        } else {
            TParticleCtrl::begin_effect_render();
        }
        if (!(flags & 8)) {
            draw_ginja_model(node->model);
        }
        if (!(flags & 0x10)) {
            child = node->child;
            if (child != NULL) {
                draw_ginja_box_tree(child);
            }
        }
        pop_matrix();
        node = node->sibling;
    } while (node != NULL);
}

void TAdSinglePlyChrSelectGC__sub_801FBB1C(void) {
    s32 r;
    if (TAdPlayerLoadGC::probe_and_check_card(0) != 0) {
        r = TAdPlayerLoadGC::find_card_file(0, pso_character_card_filename.filename);
        if (r == 0 || (u32)r == 0xFFFFFF41U) {
            TAdPlayerLoadGC::delete_memcard_file(0, pso_character_card_filename.filename);
        }
    }
}

void TAdSinglePlyChrSelectGC__sub_801FBB7C(void) {
    s32 r;
    if (TAdPlayerLoadGC::probe_and_check_card(0) != 0) {
        r = TAdPlayerLoadGC::find_card_file(0, pso_guildcard_card_filename.filename);
        if (r == 0 || (u32)r == 0xFFFFFF41U) {
            TAdPlayerLoadGC::delete_memcard_file(0, pso_guildcard_card_filename.filename);
        }
    }
}

void TAdSinglePlyChrSelectGC::try_load_system_file() {
    s32 r;
    if (TAdPlayerLoadGC::probe_and_check_card(0) != 0) {
        r = TAdPlayerLoadGC::find_card_file(0, pso_system_card_filename);
        if (r == 0 || (u32)r == 0xFFFFFF41U) {
            TAdPlayerLoadGC::delete_memcard_file(0, (const char *)(pso_system_card_filename));
        }
    }
}

void TAdSinglePlyChrSelectGC__sub_801FBC3C(void *save_data) {
    Pso3CharacterFile *a;
    Pso3CharacterFile *b;
    a = new Pso3CharacterFile;
    b = new Pso3CharacterFile;
    copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(a, save_data);
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[1]);
    subtractive_rng_make_shuffle(&chr_select_rng_state);
    subtractive_rng_unshuffle(&chr_select_rng_state, (const u8 *)a, (u8 *)b, (u32)(0x194B0));
    copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(save_data, b);
    delete b;
    delete a;
    subtractive_rng_seed(&chr_select_rng_state, chr_select_serial_seeds[0]);
    chr_select_rng_state.apply_rng_cipher((u32 *)save_data, 0x194B0);
    subtractive_rng_seed(&chr_select_rng_state, TAdSinglePlyChrSelectGC__sub_80202A68((u8 *)save_data));
    subtractive_rng_xor_buffer(&chr_select_rng_state, (u32 *)save_data, 0x194AC);
}

s32 TAdSinglePlyChrSelectGC::load_and_verify_character_save(char *desc) {
    s32 sum;
    u8 *buf;
    s32 res;
    u8 *data;
    s32 saved;
    buf = (u8 *)TQuestVmDownLoadServer::alloc(0x214B0);
    res = TAdPlayerLoadGC::find_card_file(0, memory_card_character_dir_name);
    if (res == 0) {
        memcard_access_active = 1;
        TAdSinglePlyChrSelectGC::set_card_disk_id(0);
        res = TAdSinglePlyChrSelectGC::load_player_slot(0, memory_card_character_dir_name, buf);
        TAdSinglePlyChrSelectGC::wait_for_card_load(0);
        TAdSinglePlyChrSelectGC::copy_name(0);
    }
    if (res != 0) {
        memcard_access_active = 0;
        safe_free(buf);
        return (u8)(0);
    }
    if (TAdSinglePlyChrSelectGC::load_system_file(0, &sum) == 0) {
        memcard_access_active = 0;
        safe_free(buf);
        return (u8)(0);
    }
    memcard_access_active = 0;
    chr_select_serial_seeds[0] = chr_select_serial_seeds[1] = sum;
    data = (u8 *)TQuestVmDownLoadServer::alloc(0x194B0);
    memcpy(data, buf + 0x2048, 0x194B0);
    TAdSinglePlyChrSelectGC__sub_801FBC3C(data);
    saved = *(s32 *)data;
    *(s32 *)data = 0;
    res = calc_crc32_bitwise(data, 0x194B0);
    strncpy(((char *)this), (char *)(data + 0x193F0), 0x10);
    strncpy(desc, (char *)(data + 0x19400), 0x10);
    safe_free(data);
    safe_free(buf);
    return (u8)(saved == res);
}

s32 TAdSinglePlyChrSelectGC::wait_for_card_load(s32 chan) {
    while (poll_memcard_result(chan) != 0) {
        if (TAdPlayerLoadGC::probe_card_slot(chan) != 1) {
            return 0;
        }
        TAdSinglePlyChrSelectGC::render_frame();
        render_tick();
    }
    return 1;
}
