#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/system/save/CardFileInfo.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/render/TriangleFan3D.h"
#include "types.h"
#include <string.h>
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjSinBoard.h"
#include "pso/object/lobby/LobbyGoGoBall.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_802432F0.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby_803DE778.h"

// The lobby signboard: a textured quad showing the picture load_memcard_file reads from memory card file PSO______099.



extern "C" {
}

const char *TObjSinBoard__class_name = "TObjSinBoard";

void *TObjSinBoard__texture_buffer;
NJS_TEXNAME TObjSinBoard__texture_name;
__declspec(section ".data") NJS_TEXLIST signboard_texture_list;
GinjaTextureInput TObjSinBoard__texture_surface;
s32 gogo_ball_team_scores[2];
GoGoBallConfig gogo_ball_configuration;
GoGoBallSyncState gogo_ball_sync_state;

s32 is_signboard_texture_buffer_missing(void) {
    if (TObjSinBoard__texture_buffer == 0) {
        return 1;
    }
    return 0;
}

void load_memcard_file(void) {
    CardFileInfo stat;
    CardSaveDescriptor hdr;
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
        r = TAdPlayerLoadGC::get_card_file_info(slot, memcard_file_099_name, &stat);
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
    while (poll_memcard_result(slot) != 0) {
        TLobby::run_frame();
    }
    if (verify_card_save_header(&hdr, buf) != 0) {
        safe_free(buf);
        return;
    }
    fn_80197FD0(hdr.data, hdr.size);
    safe_free(buf);
}

void TLobby__sub_80197F74(void) {}

void TLobby::free_global_buffer() {
    if (TObjSinBoard__texture_buffer != 0) {
        safe_free(TObjSinBoard__texture_buffer);
        TObjSinBoard__texture_buffer = 0;
        if (signboard_texture_list.textures->texture != NULL) {
            release_texture_list(&signboard_texture_list);
        }
    }
}

void clear_signboard_texture_buffer_pointer(void) { TObjSinBoard__texture_buffer = 0; }

void fn_80197FD0(const void *image, u32 size) {
    void *buffer = TQuestVmDownLoadServer::alloc(size);
    TObjSinBoard__texture_buffer = buffer;
    if (buffer != NULL) {
        move_data(buffer, image, size);
        signboard_texture_list.textures = &TObjSinBoard__texture_name;
        signboard_texture_list.nbTexture = 1;
        TObjSinBoard__texture_surface.set_render_rect(TObjSinBoard__texture_buffer, 0, 0, 0);
        set_texture_name(&TObjSinBoard__texture_name, &TObjSinBoard__texture_surface, 0, 0x40000000);
        load_texture_if_valid(&signboard_texture_list);
    }
}

void TObjSinBoard::render() {
    if (TMainTask::get_render_pass() != 1 && TObjSinBoard__texture_buffer != 0) {
        Vec positions[4] = {
            -10.0f, -10.0f, 0.0f, 10.0f, -10.0f, 0.0f, 10.0f, 10.0f, 0.0f, -10.0f, 10.0f, 0.0f,
        };
        u32 colors[4] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
        NJS_POINT3COL fan;
        NJS_TEX uvs[4];
        uvs[0].u = 0;
        uvs[0].v = 0;
        uvs[1].u = 0;
        uvs[1].v = 0xFF;
        uvs[2].u = 0xFF;
        uvs[2].v = 0xFF;
        uvs[3].u = 0xFF;
        uvs[3].v = 0;
        fan.p = positions;
        fan.col = colors;
        fan.tex = uvs;
        fan.num = 4;
        set_default_alpha_blend();
        TObjFish::set_global_param(&signboard_texture_list);
        set_texture_num(0);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        translate_matrix(0, position.x, position.y, position.z);
        rotate_matrix_z(0, rotation_z);
        rotate_matrix_x(0, rotation_x);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, scale.x, scale.y, scale.z);
        draw_tri_fan_3d(&fan, 4, 0xE);
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

void *TObjSinBoard::create(void *set_data) {
    return new TObjSinBoard(tl_05, set_data);
}
