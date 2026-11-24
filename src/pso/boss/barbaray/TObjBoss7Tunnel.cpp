#include "pso/math/ClampedStep.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/unk/text_803D853C.h"
#include "pso/boss/dragon/TBoss1DragonColli.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/TUnk_804E4B24.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/barbaray/TObjBoss7TunnelCol.h"
#include "pso/boss/barbaray/TObjBoss7RaftSplash.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_8020BFE4.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/boss/barbaray/TObjBoss7Dust.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/TUnk_804E4AD4.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"
#include <stddef.h>
#include "pso/unk/text_802F0E24.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/camera/TCameraCtrl.h"

// count + index list; the TUnk_804E4B24 constructor copies both into the segment it builds
struct Boss2TunnelEffectEntry {
    s32 count;
    const s32 *indices;
};
const s32 boss7_tunnel_kind0_model_indices[3] = {0, 1, 2};
const s32 boss7_tunnel_kind1_model_indices[4] = {3, 4, 5, 6};
const s32 boss7_tunnel_kind2_model_indices[3] = {7, 8, 9};
const s32 boss7_tunnel_kind3_model_indices[3] = {10, 11, 12};
const s32 boss7_tunnel_kind4_model_indices[4] = {13, 14, 15, 16};
// where TObjBoss2Tunnel__sub_802F2A2C places its two TObjBoss7RaftSplash
const Vec TObjBoss2Tunnel__raft_splash_offset_table[2] = {{3.0f, 0.0f, -5.0f}, {-3.0f, 0.0f, -5.0f}};
const char *TObjBoss7TunnelCol__name = "TObjBoss7TunnelCol";
const CollisionBody TObjBoss7TunnelCol__col_desc = {{0.0f, 0.0f, 0.0f}, 100.0f, 9.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
Boss2TunnelEffectEntry boss2_tunnel_effect_name_table[5] = {
    {3, boss7_tunnel_kind0_model_indices},
    {4, boss7_tunnel_kind1_model_indices},
    {3, boss7_tunnel_kind2_model_indices},
    {3, boss7_tunnel_kind3_model_indices},
    {4, boss7_tunnel_kind4_model_indices},
};
s32 boss2_tunnel_spawn_timer_table[0x1F] = {
    2, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 1, 1, 2,
    1, 2, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1,
};
s32 boss2_tunnel_spawn_timer_table_b[10] = {1, 1, 3, 4, 3, 3, 3, 3, 3, 3};
// y comes from a float constant of another file, so this file's static
// initializer (0x802F2CC4, .ctors 0x80433FDC) fills it in at startup.
extern const f32 boss7_tunnel_splash_y;
Vec boss7_tunnel_raft_splash_positions[2] = {
    {78.0f, boss7_tunnel_splash_y, 83.0f},
    {-78.0f, boss7_tunnel_splash_y, 83.0f},
};
u32 boss2_tunnel_state_flags;
s32 lbl_805D696C;
s8 lbl_805D6970;
// Written last-to-first: the TU was compiled with deferred codegen, which emits functions in reverse
// order of definition (and the vtables in .text order).
#pragma defer_codegen on

f32 TObjBoss7Tunnel::get_segment_x() {
    return segment_x;
}

f32 TObjBoss7Tunnel::get_scroll_speed() {
    return scroll_speed;
}

void TObjBoss7Tunnel::copy_position(const Vec *position) {
    VecCopy(&kind4_position, position);
}

void TObjBoss7Tunnel::clear_state_flags() { boss2_tunnel_state_flags = 0; }

void TObjBoss7Tunnel::create() {
    new TObjBoss7Tunnel(tl_04);
}

void TObjBoss7Tunnel::sub_802F2C4C() {  }

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
TObjBoss7Tunnel::TObjBoss7Tunnel(TObject *parent) : TObject(parent) {
    s32 i;
    render_nodes = new TObject(this);
    effect_nodes = new TObject(this);
    phase = 0;
    if (is_split_screen() == 0) {
        half_length = 8000.0f;
    } else {
        half_length = 2666.6667f;
    }
    curve.reset_floats();
    sway_state = 0;
    sway_sign = 1.0f;
    segment_x = 0.0f;
    scroll_speed = 0.0f;
    boss2_tunnel_state_flags = 0;
    scroll_offset = 0.0f;
    spawn_index = 0;
    kind4_position.x = 0.0f;
    kind4_position.y = 0.0f;
    kind4_position.z = 0.0f;
    dust_timer = 30;
    for (i = 0; i < 2; i++) {
        new TObjBoss7RaftSplash((TObject *)this, (const Vec *)&boss7_tunnel_raft_splash_positions[i], &TObjBoss2Tunnel__raft_splash_offset_table[i], &scroll_speed);
    }
    new TUnk_804E4AD4(render_nodes, 0);
    new TUnk_804E4AD4(render_nodes, 1);
    new TUnk_804E4AD4(render_nodes, 2);
    if (lbl_805D6970 == 0) {
        lbl_805D696C = 1;
        lbl_805D6970 = 1;
    }
    if (is_room_enemy_set_cleared(get_current_floor(), 1) == 0) {
        spawn_segment_row_b();
        tunnel_col = (TObject *)new TObjBoss7TunnelCol(this);
    } else {
        half_length = 8000.0f;
        spawn_segment_row_a();
        phase = 2;
        scroll_speed = 0.0f;
        segment_x = -50.0f;
        tunnel_col = NULL;
        boss2_tunnel_state_flags |= 0x8000;
    }
}
#pragma pop

TObjBoss7Tunnel::~TObjBoss7Tunnel() {
    if (tunnel_col != NULL) {
        tunnel_col->queue_destruction();
    }
}

void TObjBoss7Tunnel::run_task() {
    update_phase_motion();
    static void (TObjBoss7Tunnel::*phase_handlers[])() = {
        &TObjBoss7Tunnel::init_effect,
        &TObjBoss7Tunnel::update_arrival,
        &TObjBoss7Tunnel::update_stopped,
    };
    void (TObjBoss7Tunnel::*handler)() = phase_handlers[phase];
    (this->*handler)();
    sub_802F273C();
}

f32 boss7_tunnel_particle_pos_table[12] = {
    26.0f, -19.0f, 62.0f,
    -26.0f, -19.0f, 62.0f,
    26.0f, -19.0f, 0.0f,
    -26.0f, -19.0f, 0.0f,
};
void TObjBoss7Tunnel::update_phase_motion() {
    f32 distance;
    switch (sway_state) {
    case 0:
        if (check_both() != 0) {
            if (is_phase_active() != 0) {
                sway_sign = -1.0f;
            } else {
                sway_sign = 1.0f;
            }
            sway_state = 1;
            curve.init(0.1f, -0.1f, 150.0f, 5.0f, 2.0f);
            segment_x = 0.0f;
        }
        break;
    case 1:
        if (check_both() == 0) {
            sway_state = 3;
            distance = fabs_float(segment_x);
            curve.init(0.1f, -0.1f, segment_x, -curve.current_speed(), 2.0f);
            return;
        }
        if (curve.advance(&distance) != 0) {
            sway_state = 2;
        }
        segment_x = distance * sway_sign;
        return;
    case 2:
        if (check_both() == 0) {
            sway_state = 3;
            curve.init(0.1f, -0.1f, 150.0f, 0.0f, 2.0f);
            return;
        }
        break;
    case 3:
        if (curve.advance(&distance) != 0) {
            segment_x = 0.0f;
            sway_state = 0;
            return;
        }
        segment_x = sway_sign * (150.0f - distance);
        break;
    }
}

void TObjBoss7Tunnel::sub_802F273C() {  }

void TObjBoss7Tunnel::advance_effect_timer() {
    this->scroll_speed += 0.05f;
    if (this->scroll_speed > boss7_tunnel_max_scroll_speed) {
        this->scroll_speed = (f32) boss7_tunnel_max_scroll_speed;
    }
}

// Dead-stripped from the DOL: no code of it survives, only its literal 2.0f
// (.sdata2 0x805DECF8, pooled between update_dust_spawn's 600.0f and
// advance_effect_timer's 0.05f). It sits between the two scroll-speed helpers
// (update_spawn_timer, advance_effect_timer); body and name inferred from that role.
void TObjBoss7Tunnel::double_scroll_speed() {
    scroll_speed *= 2.0f;
}

#pragma push
#pragma opt_common_subs off
void TObjBoss7Tunnel::update_spawn_timer(const s32 *table, s32 count, s32 hold_last) {
    Vec position;
    scroll_offset += scroll_speed;
    if (scroll_offset >= 800.0f) {
        scroll_offset -= 800.0f;
        spawn_index++;
        if (spawn_index == count) {
            if (hold_last != 0) {
                spawn_index = count - 1;
            } else {
                spawn_index = 0;
            }
        }
        position.x = segment_x;
        position.y = 0.0f;
        position.z = half_length - scroll_offset;
        spawn(table[spawn_index], &position);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjBoss7Tunnel::update_dust_spawn() {
    Vec v;
    dust_timer--;
    if (dust_timer <= 0) {
        v.x = 200.0f * rand_signed_unit();
        v.y = 90.0f * (3.0517578125e-05f * (f32)rand()) + 10.0f;
        v.z = 600.0f;
        new TObjBoss7Dust(tl_05, &v);
        dust_timer = 30;
    }
}
#pragma pop

void TObjBoss7Tunnel::init_effect() {
    advance_effect_timer();
    update_spawn_timer(boss2_tunnel_spawn_timer_table, 0x1F, 0);
    if (boss2_tunnel_state_flags & 0x200) {
        boss2_tunnel_state_flags &= ~0x200;
        phase = 1;
        spawn_index = 0;
    }
    update_dust_spawn();
}

void TObjBoss7Tunnel::update_arrival() {
    f32 distance;
    TObject *object;
    update_spawn_timer(boss2_tunnel_spawn_timer_table_b, 0xA, 1);
    if (boss2_tunnel_state_flags & 8) {
        distance = kind4_position.z;
        if (distance < 1.0f) {
            phase = 2;
            this->scroll_speed = 0.0f;
            segment_x = -50.0f;
            object = tunnel_col;
            if (object != NULL) {
                object->queue_destruction();
                tunnel_col = NULL;
            }
            boss2_tunnel_state_flags |= 0x8000;
            return;
        }
        if (distance < 100.0f) {
            ::approach_value(&scroll_speed, 0.02f, 0.1f * boss7_tunnel_max_scroll_speed);
            ::approach_value(&segment_x, -1.0f, -50.0f);
            return;
        }
        if (distance < 200.0f) {
            ::approach_value(&scroll_speed, 0.04f, 0.2f * boss7_tunnel_max_scroll_speed);
            ::approach_value(&segment_x, -1.0f, -30.000002f);
            return;
        }
        if (distance < 300.0f) {
            ::approach_value(&scroll_speed, 0.06f, 0.3f * boss7_tunnel_max_scroll_speed);
            ::approach_value(&segment_x, -1.0f, -15.000001f);
        }
    }
}

void TObjBoss7Tunnel::update_stopped() {  }

void TObjBoss7Tunnel::render() {
    TObject *child;
    if (TObjEneDD::query_teammate_state() == 0) {
        for (child = render_nodes->m_down; child != NULL; child = child->m_next) {
            ((TUnk_804E4AD4 *)child)->draw_particle_effect();
        }
        for (child = effect_nodes->m_down; child != NULL; child = child->m_next) {
            ((TUnk_804E4B24 *)child)->draw_opaque_model();
        }
        for (child = effect_nodes->m_down; child != NULL; child = child->m_next) {
            ((TUnk_804E4B24 *)child)->draw_translucent_models();
        }
        for (child = effect_nodes->m_down; child != NULL; child = child->m_next) {
            ((TUnk_804E4B24 *)child)->draw_tunnel_segment();
        }
    }
}

s32 TObjBoss7Tunnel::check_both() {
    s32 positive = is_swaying_positive_x();
    s32 negative = is_phase_active();
    return negative | positive;
}

s32 TObjBoss7Tunnel::is_phase_active() {
    return (boss2_tunnel_state_flags >> 12) & 1;
}

s32 TObjBoss7Tunnel::is_swaying_positive_x() {
    return (boss2_tunnel_state_flags >> 13) & 1;
}

void TObjBoss7Tunnel::start_sway_negative_x() {
    boss2_tunnel_state_flags |= 0x1000;
    boss2_tunnel_state_flags &= ~0x2000;
}

void TObjBoss7Tunnel::start_sway_positive_x() {
    boss2_tunnel_state_flags |= 0x2000;
    boss2_tunnel_state_flags &= ~0x1000;
}

void TObjBoss7Tunnel::clear_flags_0x3000() { boss2_tunnel_state_flags &= ~0x3000; }

void TObjBoss7Tunnel::set_flag_0x200() {
    boss2_tunnel_state_flags |= 0x200;
    clear_flags_0x3000();
}

void TObjBoss7Tunnel::set_flag_0x8() { boss2_tunnel_state_flags |= 0x8; }

void TObjBoss7Tunnel::spawn(s32 kind, Vec *position) {
    new TUnk_804E4B24(effect_nodes, kind, position, half_length);
}

void TObjBoss7Tunnel::spawn_segment_row_b() {
    Vec position;
    position.x=segment_x;
    position.y=0.0f;
    for (position.z=half_length;position.z > -half_length;position.z-=800.0f) {
        if (799.0f > position.z && position.z > (-799.0f)) {
            spawn(0, &position);
        } else {
            spawn(2, &position);
        }
    }
}

void TObjBoss7Tunnel::spawn_segment_row_a() {
    Vec position;
    position.x=segment_x;
    position.y=0.0f;
    for (position.z=half_length;position.z > -half_length;position.z-=800.0f) {
        if (799.0f > position.z && position.z > (-799.0f)) {
            spawn(4, &position);
        } else {
            spawn(3, &position);
        }
    }
}

s32 TObjBoss7Tunnel::has_stopped() {
    return (boss2_tunnel_state_flags >> 15) & 1;
}

TUnk_804E4B24::TUnk_804E4B24(TObject *parent, s32 kind, Vec *pos, f32 half_length) : TObject(parent) {
    Boss2TunnelEffectEntry *entry;
    controller = (TObjBoss7Tunnel *)parent->m_up;
    entry = &boss2_tunnel_effect_name_table[kind];
    VecCopy(&position, pos);
    rotation_x = 0;
    rotation_y = 0;
    rotation_z = 0;
    model_indices = entry->indices;
    model_count = entry->count;
    this->kind = kind;
    this->half_length = half_length;
    if (kind == 4) {
        controller->copy_position(&position);
        TObjBoss7Tunnel::set_flag_0x8();
    }
    update_collision();
}

TUnk_804E4B24::~TUnk_804E4B24() {}

void TUnk_804E4B24::run_task() {
    position.x = controller->get_segment_x();
    position.z = position.z - controller->get_scroll_speed();
    if (kind == 4) {
        controller->copy_position(&position);
    }
    if (position.z <= -half_length) {
        queue_destruction();
    }
    update_collision();
}

void TUnk_804E4B24::draw_opaque_model() {
    if (is_in_camera_range() != 0) {
        set_draw_list_mask(1);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(boss7_common_texture_list));
        push_matrix();
        ::concat_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(matrix));
        draw_ginja_object(boss7_common_bml_resource->models[model_indices[0]].model);
        pop_matrix();
        restore_draw_list_mask();
    }
}

void TUnk_804E4B24::draw_translucent_models() {
    if (is_in_camera_range() != 0) {
        set_draw_list_mask(2);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(boss7_common_texture_list));
        push_matrix();
        ::concat_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(matrix));
        draw_ginja_object(boss7_common_bml_resource->models[model_indices[1]].model);
        if (model_count == 4) {
            draw_ginja_object(boss7_common_bml_resource->models[model_indices[2]].model);
        }
        pop_matrix();
        restore_draw_list_mask();
    }
}

void TUnk_804E4B24::draw_tunnel_segment() {
    s32 model_index;
    if (is_in_camera_range() != 0) {
        model_index = model_indices[model_count - 1];
        set_draw_list_mask(2);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(boss7_common_texture_list));
        TParticleCtrl::begin_effect_render();
        push_matrix();
        ::concat_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(matrix));
        draw_ginja_object(boss7_common_bml_resource->models[model_index].model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        restore_draw_list_mask();
    }
}

s32 TUnk_804E4B24::is_in_camera_range() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (position.z < -300.0f && 300.0f < position.z) {
            return 0;
        }
    }
    return 1;
}

void TUnk_804E4B24::update_collision() {
    set_matrix_identity((u8 *)matrix);
    translate_matrix_vec3((u8 *)matrix, (u8 *)&position);
    rotate_matrix_yxz(matrix, rotation_x, rotation_y, rotation_z);
}

TObjBoss7TunnelCol::TObjBoss7TunnelCol(TObject *parent) : TObjCollidable(parent) {
    m_name = TObjBoss7TunnelCol__name;
    copy_collision_body(&collision_body, &TObjBoss7TunnelCol__col_desc);
    position.x = 85.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    set_collision_body(&collision_body);
    register_object_by_id();
}

TObjBoss7TunnelCol::~TObjBoss7TunnelCol() {
    unregister_object_by_id();
    clear_collision_bodies();
}

void TObjBoss7TunnelCol::run_task() {  }

void TObjBoss7TunnelCol::render() {  }

TUnk_804E4AD4::TUnk_804E4AD4(TObject *parent, s32 kind) : TObject(parent) {
    model = get_bml_model(boss7_common_bml_resource, kind + 0x11);
    motion = get_bml_motion(boss7_common_bml_resource, kind);
    last_frame = (f32)motion->frameCount - 1.0f;
    frame = 0.0f;
}

TUnk_804E4AD4::~TUnk_804E4AD4() {}

void TUnk_804E4AD4::run_task() {
    frame += 1.0f;
    if (last_frame <= frame) {
        frame -= last_frame;
    }
}
