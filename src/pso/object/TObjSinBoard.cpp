#include "types.h"
#include "pso/TMainTask.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjSinBoard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/render_util.h"
#include "pso/system/GinjaMaterialState.h"
#include "pso/system/GinjaTexture.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_802432F0.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803DA798.h"

// The lobby signboard: a textured quad showing the picture load_memcard_file reads from memory card file PSO______099.

struct Stat_80197E64 { u8 pad0[4]; u16 blocks; u8 pad6[0xE]; };

struct Hdr_80197E64 { u8 pad0[0x58]; s32 f58; s32 f5C; u8 pad60[0xC]; };

struct Pos_8019806C { f32 w[12]; };
struct Uv_8019806C { u32 w[4]; };
struct Desc_8019806C { Pos_8019806C *pos; Uv_8019806C *uv; s16 *col; s32 count; };

extern "C" {
s32 TAdPlayerLoadGC__sub_801E1538(Hdr_80197E64 *, void *);
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 get_card_file_info__15TAdPlayerLoadGCFiPvPv(s32, const char *, Stat_80197E64 *);
void memset(void *, int, int);
void set_texture_name(void *, void *, int, int);
}

const char *TObjSinBoard__class_name = "TObjSinBoard";

u32 TObjSinBoard__texture_buffer;
GinjaTextureEntry TObjSinBoard__texture_name;
__declspec(section ".data") GinjaTextureList signboard_texture_list;
u8 TObjSinBoard__texture_surface[0x24];

s32 is_signboard_texture_buffer_missing(void) {
    if (TObjSinBoard__texture_buffer == 0) {
        return 1;
    }
    return 0;
}

void load_memcard_file(void) {
    Stat_80197E64 stat;
    Hdr_80197E64 hdr;
    s32 slot;
    void *buf;
    s32 r;
    if (get_current_floor_area() != AREA_PIONEER2_EP1 && get_current_floor_area() != AREA_PIONEER2_EP2) {
        return;
    }
    if (is_signboard_texture_buffer_missing() == 0) {
        return;
    }
    while (1) {
        slot = fn_802432F0((void *)memcard_file_099_name);
        if (slot != -2) {
            break;
        }
        TLobby::run_frame();
    }
    if (slot == -1) {
        return;
    }
    do {
        r = get_card_file_info__15TAdPlayerLoadGCFiPvPv(slot, memcard_file_099_name, &stat);
    } while ((u32)r == 0xFFFFFFFF);
    if (r != 0) {
        return;
    }
    buf = TQuestVmDownLoadServer::alloc(stat.blocks << 13);
    if (buf == 0) {
        return;
    }
    memset(buf, 0, stat.blocks << 13);
    TAdSinglePlyChrSelectGC::load_player_slot(slot, memcard_file_099_name, buf);
    while (TAdPlayerLoadGC__sub_801E1B50(slot) != 0) {
        TLobby::run_frame();
    }
    if (TAdPlayerLoadGC__sub_801E1538(&hdr, buf) != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)buf);
        return;
    }
    fn_80197FD0((void *)hdr.f58, hdr.f5C);
    TAdSinglePlyChrSelectGC::safe_free((u32)buf);
}

void TLobby__sub_80197F74(void) {}

void TLobby::free_global_buffer() {
    if (TObjSinBoard__texture_buffer != 0) {
        TAdSinglePlyChrSelectGC::safe_free(TObjSinBoard__texture_buffer);
        TObjSinBoard__texture_buffer = 0;
        if (signboard_texture_list.entries->texture != NULL) {
            release_texture_list(&signboard_texture_list);
        }
    }
}

void clear_signboard_texture_buffer_pointer(void) { TObjSinBoard__texture_buffer = 0; }

void fn_80197FD0(const void *image, u32 size) {
    u32 t = (u32)TQuestVmDownLoadServer::alloc(size);
    TObjSinBoard__texture_buffer = t;
    if (t != 0) {
        ((TLobby *)t)->move_data(image, size);
        signboard_texture_list.entries = &TObjSinBoard__texture_name;
        signboard_texture_list.count = 1;
        ((TObjPlayer *)TObjSinBoard__texture_surface)->set_render_rect(TObjSinBoard__texture_buffer, 0, 0, 0);
        set_texture_name(&TObjSinBoard__texture_name, TObjSinBoard__texture_surface, 0, 0x40000000);
        fn_8023E734((u32)&signboard_texture_list);
    }
}

void TObjSinBoard::render() {
    if (TMainTask::get_render_pass() != 1 && TObjSinBoard__texture_buffer != 0) {
        Pos_8019806C pos = {
            -10.0f, -10.0f, 0.0f, 10.0f, -10.0f, 0.0f, 10.0f, 10.0f, 0.0f, -10.0f, 10.0f, 0.0f,
        };
        Uv_8019806C uv = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
        Desc_8019806C d;
        s16 col[8];
        col[0] = 0;
        col[1] = 0;
        col[2] = 0;
        col[3] = 0xFF;
        col[4] = 0xFF;
        col[5] = 0xFF;
        col[6] = 0xFF;
        col[7] = 0;
        d.pos = &pos;
        d.uv = &uv;
        d.col = col;
        d.count = 4;
        set_default_alpha_blend();
        TObjFish::set_global_param((s32)&signboard_texture_list);
        set_texture_num(0);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        translate_matrix(0, position.x, position.y, position.z);
        rotate_matrix_z(0, rotation_z);
        rotate_matrix_x(0, rotation_x);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, scale.x, scale.y, scale.z);
        ((TObjPlayer *)(&d))->draw_tri_fan_3d(4, 0xE);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void TObjSinBoard::run_task() {}

const char *memcard_file_099_name = "PSO______099";

TObjSinBoard::~TObjSinBoard() {}

TObjSinBoard::TObjSinBoard(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjSinBoard__class_name;
    apply_object_set_data(set_data);
}

void *TObjSinBoard__create(void *set_data) {
    return new TObjSinBoard(tl_05, set_data);
}
