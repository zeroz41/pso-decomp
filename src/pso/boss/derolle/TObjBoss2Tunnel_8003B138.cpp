#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2RaftSplash.h"
#include "pso/boss/derolle/TObjBoss2Dust.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/TFogCtrl.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TUnk_804835D8.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/player/TObjPlayer_8002E784.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/GinjaMaterial.h"
#include "pso/ui/frontend/TAdLoadQuestPrtTxtGC.h"
#pragma defer_codegen on

u32 TObjBoss2Tunnel__global_flags;
// Two sibling nodes of common model 10 (clear_target_flags); TUnk_804835D8 slides them apart
// along x after 30 frames, a to +70 and b to -70.
NJS_OBJECT *boss2_tunnel_slide_node_b;
NJS_OBJECT *boss2_tunnel_slide_node_a;

static const Vec boss2_tunnel_raft_splash_offsets[2] = {{3.0f, 0.0f, -5.0f}, {-3.0f, 0.0f, -5.0f}};
const char *TObjBoss2Tunnel__name = "TObjBoss2Tunnel";

// An RGB fog colour; `a` is not read.
struct Boss2TunnelColor {
    f32 a;
    f32 r;
    f32 g;
    f32 b;
};

s32 boss2_tunnel_model_index_table[6] = {
    0x14, 0xe, 0xf, 0x10,
    0x11, 0x13,
};
s32 boss2_tunnel_model_order_table[12] = {
    0xc, 0x6, 0x7, 0x8,
    0x9, 0xb, 0x5, 0x0,
    0x1, 0x2, 0x3, 0x4,
};
Boss2TunnelColor boss2_tunnel_color_table[7] = {
    {1.0f, 1.0f, 0.6f, 0.4f},
    {1.0f, 1.0f, 0.8f, 0.5f},
    {1.0f, 0.8f, 0.6f, 0.3f},
    {1.0f, 0.6f, 1.0f, 0.4f},
    {1.0f, 1.0f, 0.8f, 0.4f},
    {1.0f, 1.0f, 0.6f, 0.4f},
    {1.0f, 1.0f, 0.6f, 0.4f},
};
Boss2TunnelColor boss2_tunnel_color = {1.0f, 0.8f, 0.8f, 0.8f};
// Frames each fog step of the flicker lasts; -1 ends the flicker.
s32 boss2_tunnel_fog_flicker_frames[15] = {
    1, 10, 1, 5, 1, 2, 2, 20, 2, 20, 4, 5, 4, 2, -1,
};
static s32 boss2_tunnel_queue_table[6] = {
    2, 2, 3, 1, 2, 4,
};
static s32 boss2_tunnel_ring_queue_table[31] = {
    1, 3, 3, 1, 2, 2, 4, 3,
    3, 1, 1, 2, 3, 3, 1, 4,
    3, 2, 2, 2, 1, 4, 3, 3,
    1, 3, 1, 2, 1, 2, 4,
};
static s32 boss2_tunnel_shift_queue_table[10] = {
    6, 5, 5, 0, 5, 5, 5, 5, 5, 0,
};
static Vec boss2_tunnel_raft_splash_positions[2] = {
    {78.0f, boss2_tunnel_splash_y, 83.0f},
    {-78.0f, boss2_tunnel_splash_y, 83.0f},
};
static Vec boss2_tunnel_particle_pos_table[4] = {
    {26.0f, -19.0f, 62.0f},
    {-26.0f, -19.0f, 62.0f},
    {26.0f, -19.0f, 0.0f},
    {-26.0f, -19.0f, 0.0f},
};

TUnk_804835D8::TUnk_804835D8(TObject *parent) : TObject(parent) {
    frame = 0;
    slide = 0.0f;
}

TUnk_804835D8::~TUnk_804835D8() {}

#pragma push
#pragma opt_common_subs off
void TUnk_804835D8::run_task() {
    f32 offset;
    frame = frame + 1;
    if (frame > 30) {
        slide += 1.0f;
        offset = slide;
        if (offset > 70.0f) {
            slide = 70.0f;
            queue_destruction();
            return;
        }
        boss2_tunnel_slide_node_b->pos[0] = -offset;
        boss2_tunnel_slide_node_a->pos[0] = slide;
    }
}

#pragma pop
void TObjBoss2Tunnel::clear_target_flags() {
    NJS_OBJECT *first;
    NJS_OBJECT *second;

    TObjBoss2Tunnel__global_flags = 0;
    first = boss2_common_resource->models[10].model->child->sibling;
    boss2_tunnel_slide_node_a = first;
    second = first->sibling;
    boss2_tunnel_slide_node_b = second;
    second->evalflags &= ~1;
    boss2_tunnel_slide_node_a->evalflags &= ~1;
}

void *TObjBoss2Tunnel::create() {
    return new TObjBoss2Tunnel(tl_02);
}

void TObjBoss2Tunnel::sub_8003C648() {}

void TObjBoss2Tunnel::set_global_flag_400() {
    TObjBoss2Tunnel__global_flags |= 0x400;
}

void TObjBoss2Tunnel::set_global_flag_800() {
    TObjBoss2Tunnel__global_flags |= 0x800;
}

void TObjBoss2Tunnel::start_sway_negative_x() {
    TObjBoss2Tunnel__global_flags |= 0x1000;
    TObjBoss2Tunnel__global_flags &= ~0x2000;
}

void TObjBoss2Tunnel::start_sway_positive_x() {
    TObjBoss2Tunnel__global_flags |= 0x2000;
    TObjBoss2Tunnel__global_flags &= ~0x1000;
}

void TObjBoss2Tunnel::clear_global_flag_3000() {
    TObjBoss2Tunnel__global_flags &= 0xFFFFCFFF;
}

s32 TObjBoss2Tunnel::is_active() {
    return TObjBoss2Tunnel__global_flags & 1;
}

void TObjBoss2Tunnel::set_global_flag_100() {
    TObjBoss2Tunnel__global_flags |= 0x100;
}

void TObjBoss2Tunnel::set_global_flag_200() {
    TObjBoss2Tunnel__global_flags |= 0x200;
}

TObjBoss2Tunnel::TObjBoss2Tunnel(TObject *parent) : TObject(parent) {
    s32 i;
    s32 j;
    m_name = TObjBoss2Tunnel__name;
    state = 0;
    TObjBoss2Tunnel__global_flags = 0;
    segment_pos = 0.0f;
    scroll_speed = 0.0f;
    queue_pos = 0;
    init_queue_from_start();
    texture_frame = 0;
    start_offset = 0.0f;
    shift_index = 0;
    brake_pos = 0.0f;
    brake_end = 0.0f;
    brake_speed = 0.0f;
    pad_58 = 0;
    sway_state = 0;
    sway_curve.reset_floats();
    sway_dir = 1.0f;
    sway_offset = 0.0f;
    saved_fog = 0x21;
    fog_state = 0;
    fog_timer = 0;
    fog_step = 0;
    bob_angle = 0;
    roll_phase = 0;
    roll_angle = 0;
    inner_roll_angle = 0;
    bob_height = 0.0f;
    for (i = 0; i < 2; i++) {
        raft_splashes[i] = new TObjBoss2RaftSplash(this, &boss2_tunnel_raft_splash_positions[i], &boss2_tunnel_raft_splash_offsets[i], &scroll_speed);
    }
    for (j = 0; j < 4; j++) {
        particles[j] = 0;
    }
    dust_timer = 0xA;
}

TObjBoss2Tunnel::~TObjBoss2Tunnel() {}

void TObjBoss2Tunnel::init_queue_from_start() {
    s32 k = queue_pos;
    s32 n = 6 - k;
    s32 i;
    s32 j;
    for (i = 0; i < n; i++) {
        segment_queue[i] = boss2_tunnel_queue_table[k++];
    }
    for (j = 0; i < 6; i++, j++) {
        segment_queue[i] = boss2_tunnel_ring_queue_table[j];
    }
}

void TObjBoss2Tunnel::copy_ring_buffer_window() {
    s32 idx = queue_pos;
    s32 n = 6;
    s32 i;
    s32 j;
    if (idx + 6 > 0x1F) {
        n = 0x1F - idx;
    }
    s32 k = idx;
    for (i = 0; i < n; i++, k++) {
        segment_queue[i] = boss2_tunnel_ring_queue_table[k];
    }
    for (j = 0; i < 6; i++, j++) {
        segment_queue[i] = boss2_tunnel_ring_queue_table[j];
    }
}

void TObjBoss2Tunnel::shift_queue_push_next() {
    s32 i;
    for (i = 0; i < 5; i++) {
        segment_queue[i] = segment_queue[i + 1];
    }
    segment_queue[5] = boss2_tunnel_shift_queue_table[shift_index++];
}

void TObjBoss2Tunnel::enable_fog() {
    TFogCtrl::update_all(0xB, 1);
    TObjBoss2Tunnel__global_flags |= 2;
}

void TObjBoss2Tunnel::restore_fog() {
    TFogCtrl::update_all(saved_fog, 1);
    TObjBoss2Tunnel__global_flags |= 4;
}


s32 TObjBoss2Tunnel::current_texture_index() {
    if (texture_frame == 0) {
        return 0;
    }
    return texture_frame + 31;
}

s32 TObjBoss2Tunnel::is_swaying() {
    s32 right;
    s32 left;
    right = is_swaying_positive_x();
    left = is_flag_set();
    return left | right;
}

s32 TObjBoss2Tunnel::is_flag_set() {
    return ((u32) TObjBoss2Tunnel__global_flags >> 0xCU) & 1;
}

s32 TObjBoss2Tunnel::is_swaying_positive_x() {
    return ((u32) TObjBoss2Tunnel__global_flags >> 0xDU) & 1;
}

void TObjBoss2Tunnel::update_particles() {
    f32 t;
    s32 i;
    TParticleCtrl *particle;
    if (scroll_speed < boss2_tunnel_max_scroll_speed) {
        t = -5.0f * (scroll_speed / boss2_tunnel_max_scroll_speed);
    } else {
        t = -5.0f;
    }
    for (i = 0; i < 4; i++) {
        particle = particles[i];
        if (particle == 0) {
            TParticleCtrl *created = (TParticleCtrl *)create_particle_controller(&boss2_tunnel_particle_pos_table[i], 0x171, 1);
            if (created != 0) {
                created->enable();
                particles[i] = created;
            }
        } else {
            release_children(particle, t);
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjBoss2Tunnel::run_task() {
    f32 tmp;
    s32 flag;
    f32 prev;
    texture_frame++;
    if (texture_frame >= 30) {
        texture_frame = 0;
    }
    f32 step = 512.0f;
    bob_angle = (s32)((f32)bob_angle + step);
    roll_phase = (s32)((f32)roll_phase + step);
    roll_angle = (s32)(546.0f * sin_table_lookup(roll_phase));
    bob_height = 3.0f * sin_table_lookup(bob_angle) + 2.0f;
    if (is_swaying() != 0) {
        inner_roll_angle = (roll_angle * 2) / 3;
    } else {
        inner_roll_angle = roll_angle / 2;
    }
    switch (sway_state) {
    case 0:
        if (is_swaying() != 0) {
            if (is_flag_set() != 0) {
                sway_dir = -1.0f;
            } else {
                sway_dir = 1.0f;
            }
            sway_state = 1;
            sway_curve.init(0.1f, -0.1f, 150.0f, 5.0f, 2.0f);
            sway_offset = 0.0f;
        }
        break;
    case 1:
        if (is_swaying() == 0) {
            sway_state = 3;
            tmp = fabs_float(sway_offset);
            sway_curve.init(0.1f, -0.1f, sway_offset, -sway_curve.current_speed(), 2.0f);
        } else {
            if (sway_curve.advance(&tmp) != 0) {
                sway_state = 2;
            }
            sway_offset = tmp * sway_dir;
        }
        break;
    case 2:
        if (is_swaying() == 0) {
            sway_state = 3;
            sway_curve.init(0.1f, -0.1f, 150.0f, 0.0f, 2.0f);
        }
        break;
    case 3:
        if (sway_curve.advance(&tmp) != 0) {
            sway_offset = 0.0f;
            sway_state = 0;
        } else {
            sway_offset = sway_dir * (150.0f - tmp);
        }
        break;
    }
    switch (state) {
    case 0:
        TObjBoss2Tunnel::set_global_flag_100();
        if (TObjBoss2Tunnel__global_flags & 0x100) {
            TObjBoss2Tunnel__global_flags &= ~0x100;
            state = 1;
        }
        break;
    case 1:
        scroll_speed += 0.05f;
        if (scroll_speed > boss2_tunnel_max_scroll_speed) {
            scroll_speed = boss2_tunnel_max_scroll_speed;
        }
        segment_pos += scroll_speed;
        start_offset += scroll_speed;
        if (segment_pos >= 600.0f) {
            segment_pos -= 600.0f;
            queue_pos++;
            if (queue_pos >= 6) {
                queue_pos = 0;
                copy_ring_buffer_window();
                state = 2;
                saved_fog = TFogCtrl::update_first_active_fog();
            } else {
                init_queue_from_start();
            }
        }
        break;
    case 2: {
        scroll_speed += 0.05f;
        if (scroll_speed > boss2_tunnel_max_scroll_speed) {
            scroll_speed = boss2_tunnel_max_scroll_speed;
        }
        segment_pos += scroll_speed;
        if (segment_pos >= 600.0f) {
            segment_pos -= 600.0f;
            queue_pos++;
            if (queue_pos >= 31) {
                queue_pos = 0;
            }
            copy_ring_buffer_window();
        }
        if (TObjBoss2Tunnel__global_flags & 0x200) {
            TObjBoss2Tunnel__global_flags &= ~0x200;
            state = 3;
            shift_index = 0;
            brake_end = 4400.0f - (0.5f * (scroll_speed * scroll_speed)) / 0.02f;
            brake_pos = segment_pos;
            brake_speed = scroll_speed;
            brake_frame = 0;
            new TUnk_804835D8(this);
        }
        dust_timer--;
        if (dust_timer <= 0) {
            Vec v;
            v.x = 200.0f * rand_signed_unit();
            v.y = 90.0f * (3.0517578e-05f * (f32)rand()) + 10.0f;
            v.z = 600.0f;
            new TObjBoss2Dust(tl_05, &v);
            dust_timer = 10;
        }
        break;
    }
    case 3:
        flag = 0;
        prev = brake_pos;
        if ((f32)brake_frame <= 0.0f) {
            brake_pos = prev + brake_speed;
            if (brake_pos > brake_end) {
                brake_frame = 1;
                brake_end = brake_pos;
                play_sound_effect(0x4003A80E, 0, 0, 0);
            } else {
                play_persistent_sound(0x4003B20C, this, NULL, 0, 0);
            }
        } else {
            f32 lim;
            brake_pos = (f32)brake_frame * (brake_speed - 0.01f * (f32)brake_frame) + brake_end;
            { f32 one = 1.0f; brake_frame = (s32)((f32)brake_frame + one); }
            lim = brake_speed / 0.02f;
            if ((f32)brake_frame >= lim) {
                brake_frame = (s32)lim;
                pad_58 = 0;
                state = 4;
            }
        }
        scroll_speed = brake_pos - prev;
        segment_pos += brake_pos - prev;
        if (segment_queue[2] == 6 || segment_queue[3] == 6) {
            if (segment_pos >= 700.0f) {
                segment_pos -= 700.0f;
                flag = 1;
            }
        } else if (segment_pos >= 600.0f) {
            segment_pos -= 600.0f;
            flag = 1;
        }
        if (flag) {
            shift_queue_push_next();
        }
        break;
    case 4:
        break;
    }
    if (state == 1 || state == 2) {
        play_persistent_sound(0x4003B20C, this, NULL, 0, 0);
    }
    update_particles();
    if (TObjBoss2Tunnel__global_flags & 2) {
        TObjBoss2Tunnel__global_flags &= ~2;
        TObjBoss2Tunnel__global_flags |= 1;
    } else if (TObjBoss2Tunnel__global_flags & 4) {
        TObjBoss2Tunnel__global_flags &= ~4;
        TObjBoss2Tunnel__global_flags &= ~1;
    }
    switch (fog_state) {
    case 0:
        if (TObjBoss2Tunnel__global_flags & 0x400) {
            TObjBoss2Tunnel__global_flags &= ~0x400;
            fog_state = 1;
            fog_timer = 0;
            fog_step = 0;
            enable_fog();
        }
        break;
    case 1:
        fog_timer++;
        if (boss2_tunnel_fog_flicker_frames[fog_step] <= fog_timer) {
            fog_timer = 0;
            fog_step++;
            if (fog_step & 1) {
                restore_fog();
            } else {
                enable_fog();
                play_sound_effect(0x4003A80B, 0, 0, 0);
                if (boss2_tunnel_fog_flicker_frames[fog_step] == -1) {
                    fog_state = 2;
                }
            }
        }
        break;
    case 2:
        if (TObjBoss2Tunnel__global_flags & 0x800) {
            TObjBoss2Tunnel__global_flags &= ~0x800;
            fog_state = 3;
            fog_timer = 0;
            fog_step = 0;
            restore_fog();
        }
        break;
    case 3:
        fog_timer++;
        if (boss2_tunnel_fog_flicker_frames[fog_step] <= fog_timer) {
            fog_step++;
            fog_timer = 0;
            if (fog_step & 1) {
                enable_fog();
            } else {
                restore_fog();
                play_sound_effect(0x4003A80B, 0, 0, 0);
                if (boss2_tunnel_fog_flicker_frames[fog_step] == -1) {
                    fog_state = 0;
                }
            }
        }
        break;
    }
    if (TObjBoss2Tunnel::is_active() == 0) {
        f32 d = segment_pos;
        Boss2TunnelColor *a = &boss2_tunnel_color_table[segment_queue[2]];
        Boss2TunnelColor *b = &boss2_tunnel_color_table[segment_queue[3]];
        if (d <= 200.0f) {
            set_scene_light_color(a->r, a->g, a->b);
        } else if (d <= 400.0f) {
            f32 u;
            f32 t;
            t = (d - 200.0f) / 200.0f;
            u = 1.0f - t;
            set_scene_light_color(a->r * u + b->r * t, a->g * u + b->g * t, a->b * u + b->b * t);
        } else {
            set_scene_light_color(b->r, b->g, b->b);
        }
    } else {
        set_scene_light_color(boss2_tunnel_color.r, boss2_tunnel_color.g, boss2_tunnel_color.b);
    }
}

#pragma pop
void TObjBoss2Tunnel::render() {
    GinjaTextureState *saved;
    s32 i;
    Vec v = {0.0f, 0.0f, 0.0f};
    if (TObjPlayer::is_any_teammate_in_state() == 0 && TMainTask::get_render_pass() == 0) {
    push_matrix();
    {
        NJS_TEXNAME *entries = boss2_common_texture_list->textures;
        saved = entries->texture;
        entries->texture = entries[current_texture_index()].texture;
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(boss2_common_texture_list));
    if (state == 0 || state == 1) {
        push_matrix();
        translate_matrix(0, 0.0f, 0.0f, -start_offset);
        draw_ginja_object(boss2_common_resource->models[13].model);
        pop_matrix();
    }
    if (state == 3) {
        v.z = -segment_pos;
        if (segment_queue[0] == 6) {
            v.z -= 400.0f;
        } else {
            v.z -= 300.0f;
        }
        if (segment_queue[1] == 6) {
            v.z -= 800.0f;
        } else {
            v.z -= 600.0f;
        }
        if (segment_queue[2] == 6) {
            v.z -= 400.0f;
        } else {
            v.z -= 300.0f;
        }
    } else {
        v.z = -(1200.0f + segment_pos);
    }
    post_translate_matrix(&v.x);
    v.z = 600.0f;
    for (i = 0; i < 6; i++) {
        s32 t = segment_queue[i];
        if (t == 6) {
            if (i != 0) {
                translate_matrix(0, 0.0f, 0.0f, 100.0f);
            }
            translate_matrix(0, 0.0f, 0.0f, -300.0f);
            push_matrix();
            translate_matrix(0, 0.0f, bob_height, 0.0f);
            rotate_matrix_z(0, roll_angle);
            translate_matrix(0, sway_offset, 0.0f, 0.0f);
            draw_ginja_object(boss2_common_resource->models[18].model);
            draw_ginja_object(boss2_common_resource->models[21].model);
            pop_matrix();
            push_matrix();
            rotate_matrix_z(0, inner_roll_angle);
            translate_matrix(0, sway_offset, 0.0f, 0.0f);
            draw_ginja_object(boss2_common_resource->models[10].model);
            pop_matrix();
            translate_matrix(0, 0.0f, 0.0f, 400.0f);
            push_matrix();
            translate_matrix(0, 0.0f, bob_height, 0.0f);
            rotate_matrix_z(0, roll_angle);
            translate_matrix(0, sway_offset, 0.0f, 0.0f);
            draw_ginja_object(boss2_common_resource->models[19].model);
            pop_matrix();
            push_matrix();
            rotate_matrix_z(0, inner_roll_angle);
            translate_matrix(0, sway_offset, 0.0f, 0.0f);
            draw_ginja_object(boss2_common_resource->models[11].model);
            pop_matrix();
            post_translate_matrix(&v.x);
        } else {
            push_matrix();
            translate_matrix(0, 0.0f, bob_height, 0.0f);
            rotate_matrix_z(0, roll_angle);
            translate_matrix(0, sway_offset, 0.0f, 0.0f);
            draw_ginja_object(boss2_common_resource->models[boss2_tunnel_model_index_table[t]].model);
            pop_matrix();
            push_matrix();
            rotate_matrix_z(0, inner_roll_angle);
            translate_matrix(0, sway_offset, 0.0f, 0.0f);
            draw_ginja_object(boss2_common_resource->models[boss2_tunnel_model_order_table[t]].model);
            pop_matrix();
            post_translate_matrix(&v.x);
        }
    }
    boss2_common_texture_list->textures->texture = saved;
    pop_matrix();
    }
}
