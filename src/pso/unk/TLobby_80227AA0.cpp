#include "pso/network/protocol/GameplaySoundPacket.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/audio/AdxManager.h"
#include "pso/unk/TLobby_80227AA0.h"
#include "pso/unk/text_8023F660.h"
#include "pso/unk/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/TLobby_8023F734.h"
#include "pso/player/TObjPlayer_80011014.h"

    extern int music_stream_base_gain;
int get_music_base_gain(void) {  return music_stream_base_gain; }
void TLobby__sub_80227AA8(s32 tracks) {
    fn_8023F660((&sound_control_state), (tracks), (((s32 (*)())get_menu_field_280__6TLobbyFv)() + 0x55), 0x40, 0x40, 0);
}


#include <stddef.h>
#include "pso/system/scene/TScene.h"
#include "pso/system/main_loop.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
void TLobby__sub_80227AF8(s32 arg0, s32 arg1) { TLobby__sub_8023F754(arg0, arg1); }
}

extern s32 local_client_id;

s32 is_special_sound_id(u32 x) {
    s32 lo = x & 0xffff;
    s32 hi = x >> 16;
    if (hi == 2 && (lo == 0x27 || lo == 0x2f)) {
        return 1;
    }
    return 0;
}


void apply_clamped_field_27c__6TLobbyFv(f32 value) {
    ((TLobby *)(&sound_control_state))->set_clamped_field27c(value);
}

void handle_6xB2_play_sound_from_player(game_command_header *header) {
    G_PlaySound_6xB2 *command = reinterpret_cast<G_PlaySound_6xB2 *>(header);
    bswap_6xB2_play_sound(command);
    if (command->floor == get_current_floor_area()) {
        if (reinterpret_cast<const s16 &>(command->client_id) == 0xFFFF) {
            play_sound_effect(command->sound_id, 0, 0, 0);
            return;
        }
        TObjPlayer *player = get_player_by_client_id(local_client_id);
        if (player != NULL) {
            play_sound_effect(command->sound_id, &player->position, 0, 0);
        }
    }
}

s32 TLobby::is_camera_state_active() {
    if ((TCameraCtrl::get_active_controller() == 5) || (TCameraCtrl::get_active_controller() == 9)) {
        return 1;
    }
    return 0;
}

void TLobby::set_mode(s32 mode) {
    switch (mode) {
    case 0:
        TLobby::on_set_mode(1);
        break;
    case 1:
        TLobby::on_set_mode(0);
        break;
    case 2:
        TLobby::on_set_mode(0);
        break;
    }
    sound_control_state.set_output_mode(mode);
}


void get_menu_field_280__6TLobbyFv(void) {
    ((TLobby *)&sound_control_state)->get_field_0x280();
}

void TLobby::set_menu_index_main(u8 *arg0) {
    ((TLobby *)&sound_control_state)->set_menu_index((saddr)arg0);
}

void release_sound_with_fade(s32 slot) { fade_out_sound_slot(slot, 64); }

void TLobby__sub_80227D38(void) { TLobby::fade_voice_channels(0); }

s32 normalize_sound_request(u32 id, const void *actor, const Vec *position, s32 arg3, s32 arg4) {
    s32 r;
    s32 m;
    s32 flags;
    s32 v;
    s32 h;
    flags = 0;
    if (position == 0) {
        flags |= 0xE;
    }
    if (arg4 & 1) {
        flags |= 0xC;
    }
    if (arg4 & 2) {
        v = -(s32)((id >> 8U) & 0x7F);
        if (arg3 >= 0) {
            arg3 = 0;
        }
        v += arg3;
    } else {
        v = -(s32)((id >> 8U) & 0x7F);
    }
    if (v < -0x7F) {
        r = -0x7F;
    } else {
        r = v < 0 ? v : 0;
    }
    if (!((id >> 0xFU) & 1)) {
        flags |= 8;
    }
    if (!(id & 0x40000000)) {
        flags |= 0x10;
    }
    m = id & 0xBFFF00FF;
    if (((s32 (*)(void))is_sound_enabled)() == 1) {
        h = alloc_looping_sound_slot(m, actor, position, r, flags);
        if (is_special_sound_id(m) != 0) {
            set_sound_slot_special_scale(h, 1.0f);
        }
        return h;
    }
    return -1;
}

s32 play_packed_sound_once(u32 id, saddr position, s32 arg2, s32 arg3) {
    s32 r;
    s32 m;
    s32 flags;
    s32 v;
    s32 h;
    flags = 0;
    if (position == 0) {
        flags |= 0xE;
    }
    if (arg3 & 1) {
        flags |= 0xC;
    }
    if (arg3 & 2) {
        v = -(s32)((id >> 8U) & 0x7F);
        if (arg2 >= 0) {
            arg2 = 0;
        }
        v += arg2;
    } else {
        v = -(s32)((id >> 8U) & 0x7F);
    }
    if (v < -0x7F) {
        r = -0x7F;
    } else {
        r = v < 0 ? v : 0;
    }
    if (!((id >> 0xFU) & 1)) {
        flags |= 8;
    }
    if (!(id & 0x40000000)) {
        flags |= 0x10;
    }
    m = id & 0xBFFF00FF;
    if (((s32 (*)(void))is_sound_enabled)() == 1) {
        h = alloc_one_shot_sound_slot(m, reinterpret_cast<const Vec *>(position), r, flags);
        if (is_special_sound_id(m) != 0) {
            set_sound_slot_special_scale(h, 1.0f);
        }
        return h;
    }
    return -1;
}


void is_sound_enabled(void) {
    sound_control_state.is_ready();
}


s32 update_sound_frame(SoundControlState *self);
s32 init_sound_aux_effects(SoundControlState *self);
extern "C" {
void TLobby__sub_803382E4(void);
s32 TLobby__sub_80226B64(int);
extern const s32 floor_sound_bank_table[36] = {
    1, 2, 2, 4, 4, 4, 6, 6, 8, 8, 8, 3,
    5, 7, 9, -1, 10, 11, 1, 14, 14, 15, 15, 12,
    12, 12, 12, 12, 16, 16, 13, 17, 18, 21, 19, 20,
};
extern const f32 floor_sound_bank_volume_table[36] = {
    0.0f, 0.0f, 0.0f, 0.5f, 0.4f, 0.3f, 0.2f, 0.2f, 0.35f, 0.35f, 0.35f, 0.1f,
    0.4f, 0.0f, 0.2f, 0.0f, 0.05f, 0.0f, 0.0f, 0.0f, 0.0f, 0.05f, 0.05f, 0.1f,
    0.1f, 0.1f, 0.1f, 0.1f, 0.5f, 0.5f, 0.1f, 0.5f, 0.0f, 0.1f, 0.1f, 0.2f,
};

void TLobby::refresh_render_state() { TLobby::pop_sound_groups((void *)&sound_control_state, (saddr)((void*)0)); ((int (*)(float))apply_clamped_field_27c__6TLobbyFv)(0.0f); render_tick(); }

void load_floor_sound_bank(s32 arg0) {
    s32 temp_r0;
    s32 temp_r31;

    if (arg0 >= 0) {
        temp_r0 = arg0 * 4;
        temp_r31 = *(s32 *)((s8 *)((u8 *)floor_sound_bank_table + temp_r0) + 0);
        if (temp_r31 >= 0) {
            if (arg0 < 0x24) {
                ((s32 (*)(void *, f32))apply_clamped_field_27c__6TLobbyFv)((void *)floor_sound_bank_volume_table, (f32) (*(f32 *)((s8 *)((u8 *)floor_sound_bank_volume_table + temp_r0) + 0)));
            }
            ((TLobby *)((void *)&sound_control_state))->validate_and_set_selection((int)temp_r31);
            do {
                TLobby::run_disk_error_check();
                exec_adx_server();
                TLobby::run_frame();
            } while (sound_control_state.is_ready() == 0);
            TLobby__sub_80226B64(0);
        }
    }
}

void TLobby__sub_8022804C(void) {
    TLobby__sub_802401C8(&sound_control_state);
}

void update_global_sound_frame(void) {
    update_sound_frame(&sound_control_state);
}

void TLobby__sub_8022809C(void) {
    ((TLobby *)&sound_control_state)->reset_sound_state();
}
}

void TLobby::wait_for_sound_init() {
    init_sound_aux_effects(&sound_control_state);
    ((TLobby *)&sound_control_state)->validate_and_set_selection(0);
    do {
        TLobby__sub_803382E4();
        TLobby::run_disk_error_check();
        exec_adx_server();
        render_tick();
    } while (((s32 (*)())is_sound_enabled)() == 0);
}

SoundControlState sound_control_state;
