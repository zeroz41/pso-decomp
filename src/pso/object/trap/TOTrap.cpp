#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/object/trap/TOMineTrap.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/render_util.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerCommands.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjBase.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/TLevelSelect.h"

const char *TOTrap::class_name = "TOTrap";


f32 TOTrap::scale_by_table_value(f32 table_value) {
    f32 scale[4] = {1.0f, 2.0f, 3.0f, 6.0f};
    return table_value * scale[game_difficulty_selection];
}

void TOTrap::vfunc_89() {  }

s32 TOTrap::is_any_player_matching_stat() {
    s32 i;
    TObjPlayer *p;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0) {
            if (((s16)p->get_room() == (s16)get_room()) && (can_see_traps(p) != 0)) {
                return 1;
            }
        }
    }
    return 0;
}

void TOTrap::update_holding() {
    TObjPlayer *pl;

    calc_attach_pos();
    refresh_collision_body_centers();
    if ((s32) this->set_params[0] < 0) {
        TObjChara *p;
        this->receive_physical_attack(this->target, 1.0f);
        p = (TObjChara *)this->target;
        if (p != NULL) {
            u32 v = p->get_entity_id();
            if (v < 0x1000U) {
                pl = get_player_by_client_id(v);
                if (pl->is_locally_controlled() != 0 && pl->check_player_flag1() != 0) {
                    send_release_hold(pl);
                }
            }
        }
    }
    submit_cursor_candidate(this, -1);
}

void TOTrap::update_springing() {
    TObjPlayer *pl;
    calc_attach_pos();
    this->player = find_nearest_visible_player(this, 0, this->range);
    if (this->player != 0xFFFF) {
        pl = get_player_by_client_id(this->player);
        this->target = pl;
        if (this->target != 0) {
            if (horizontal_distance_squared(&((TObjChara *)this->target)->position, &position) < this->dist * this->dist) {
                this->mode = 3;
                if (pl->is_locally_controlled() != 0) {
                    ((void (*)(f32, TObjPlayer *, Vec *, s32, s32))send_6x2C_impose_hold)(
                        this->dist, pl, &position, this->set_params[0], 0);
                }
            } else {
                this->player = 0xFFFF;
                this->target = 0;
            }
        }
    } else {
        this->target = 0;
    }
}

void TOTrap::submit_cursor_and_notify() {
    submit_cursor_candidate(this, -1);
    this->find_target_player();
}

void TOTrap::find_target_player() {
    calc_attach_pos();
    this->player = find_nearest_visible_player(this, 0, this->range);
    if (this->player != (u16)0xFFFF) {
        this->target = get_player_by_client_id(this->player);
        if (this->target != 0) {
            if (horizontal_distance_squared(&((TObjChara *)this->target)->position, &position) < this->range * this->range) {
                this->mode = 2;
            }
        } else {
            this->player = 0xFFFF;
            this->target = 0;
        }
    } else {
        this->target = 0;
    }
}

void TOTrap::play_sounds() {
    spawn_particle_effect(&body_center, 0x45);
    spawn_particle_effect(&body_center, 0x46);
}

void TOTrap::apply_saved_state(s16 *state, s32 live) {
    if ((s16) *state == 4) {
        if (live == 1) {
            play_sounds();
        }
        set_flag8();
        queue_destruction();
    }
}

f32 TOTrap::receive_physical_attack(TObjChara *source, f32) {
    s16 msg;
    TObjPlayer *pl;
    u16 id;
    if (this->entity_id >= 0x4000U && this->set_entry != NULL && access_object_saved_state(&msg, 1) != 0) {
        this->mode = 4;
        msg = this->mode;
        access_object_saved_state(&msg, 0);
        send_object_state_update(&msg);
        if (source != NULL) {
            id = ((TObjBase *)source)->get_entity_id();
            if (id < 0x1000U) {
                pl = get_player_by_client_id(id);
                if (pl != NULL && pl->is_locally_controlled() != 0 && pl->check_player_flag1() != 0) {
                    send_release_hold(pl);
                }
            }
        }
    }
    return 0.0f;
}

void TOTrap::run_task() {
    if (check_demo_mode() == 1) {
        this->run_demo();
        return;
    }
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        this->update_effects();
        switch (this->mode) {
        case 0:
            if (this->is_any_player_matching_stat() != 0) {
                this->mode = 1;
            }
            this->find_target_player();
            return;
        case 1:
            this->submit_cursor_and_notify();
            return;
        case 2:
            this->update_springing();
            return;
        case 3:
            this->update_holding();
            break;
        }
    }
}


#include "pso/render/ChunkModelDraw.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/render/ProjectedStripDraw.h"


#include "pso/render/TextureState.h"
#include "pso/player/PlayerSlots.h"


#pragma explicit_unused_unused_members on
void TOTrap::render() {
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        this->visible = this->update_object_view_visibility(4e+02f, 2e+01f);
        if (this->visible == 1) {
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation.y);
            set_texture_list(this->texlist);
            if (check_demo_mode() == 1) {
                draw_chunk_object(this->model);
            } else {
                draw_model_motion(this->model, this->current_motion, this->frame);
            }
            pop_matrix();
        }
    }
}


TOTrap::~TOTrap() {}

TOTrap::TOTrap(TObject *parent) : TObjChara(parent) {
    m_name = TOTrap::class_name;
    range = dist = 0.0f;
    player = 0xFFFF;
    visible = 1;
}

void TOTrap::update_effects() {}

void TOTrap::vfunc_86() {}

void TOTrap::run_demo() {}
