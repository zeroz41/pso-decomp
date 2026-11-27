#include "pso/system/memory.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_80202A68.h"
#include "pso/system/SubtractiveRng.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/ui/frontend/TAdPlayerLoadGCMemCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/main_loop.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include <string.h>

extern "C" {
void copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(void *, void *);
extern s32 chr_select_serial_seeds[];
}
s32 TWindowKeyBoardHard::is_card_flag_set(s32 client_id) { return test_card_flag(client_id, 1); }
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

void delete_character_save_file(void) {
    s32 r;
    if (TAdPlayerLoadGC::probe_and_check_card(0) != 0) {
        r = TAdPlayerLoadGC::find_card_file(0, pso_character_card_filename.filename);
        if (r == 0 || (u32)r == 0xFFFFFF41U) {
            TAdPlayerLoadGC::delete_memcard_file(0, pso_character_card_filename.filename);
        }
    }
}

void delete_guild_card_save_file(void) {
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

void decrypt_character_save(Pso3CharacterFile *save_data) {
    Pso3CharacterFile *plain;
    Pso3CharacterFile *unshuffled;
    plain = new Pso3CharacterFile;
    unshuffled = new Pso3CharacterFile;
    copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(plain, save_data);
    chr_select_rng_state.set_seed(chr_select_serial_seeds[1]);
    chr_select_rng_state.make_shuffle();
    chr_select_rng_state.unshuffle((const u8 *)plain, (u8 *)unshuffled, (u32)(0x194B0));
    copy_save_data__23TAdSinglePlyChrSelectGCFPvPv(save_data, unshuffled);
    delete unshuffled;
    delete plain;
    chr_select_rng_state.set_seed(chr_select_serial_seeds[0]);
    chr_select_rng_state.apply_rng_cipher(save_data, 0x194B0);
    chr_select_rng_state.set_seed(save_data->get_cipher_seed());
    chr_select_rng_state.xor_buffer(save_data, 0x194AC);
}

s32 TAdSinglePlyChrSelectGC::load_and_verify_character_save(char *desc) {
    s32 sum;
    u8 *buf;
    s32 res;
    Pso3CharacterFile *data;
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
    data = (Pso3CharacterFile *)TQuestVmDownLoadServer::alloc(0x194B0);
    memcpy(data, buf + 0x2048, 0x194B0);
    decrypt_character_save(data);
    saved = data->checksum;
    data->checksum = 0;
    res = calc_crc32_bitwise((u8 *)data, 0x194B0);
    strncpy(((char *)this), (char *)data + 0x193F0, 0x10);
    strncpy(desc, (char *)data + 0x19400, 0x10);
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
