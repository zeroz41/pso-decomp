#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/math/AngleLookup.h"


struct BalClawPartEntry {
    s16 *plist;
    s16 model_index;
    s16 part_index;
    s16 uv_scroll_u;  // added to the u of the texture_id strips once a frame
    s16 uv_scroll_v;
    s16 texture_id;
    s16 pad_e;
};

static const char balclaw_body_model[] = "re6_b_bal_body.nj";
static const char balclaw_bcbody_model[] = "re6_b_bcbody.nj";
static const char balclaw_claw_body_model[] = "re6_b_claw_body.nj";
static const char balclaw_bal_attack_motion[] = "balattack_re6_b_bal_body.njm";
static const char balclaw_bal_comb_motion[] = "balcomb_re6_b_bal_body.njm";
static const char balclaw_bal_damage_motion[] = "baldamage_re6_b_bal_body.njm";
static const char balclaw_bal_die_motion[] = "baldie_re6_b_bal_body.njm";
static const char balclaw_bal_shout_motion[] = "balshout_re6_b_bal_body.njm";
static const char balclaw_bal_wait_motion[] = "balwait_re6_b_bal_body.njm";
static const char balclaw_bc_attack_motion[] = "bcattack_re6_b_bcbody.njm";
static const char balclaw_bc_damage_motion[] = "bcdamage_re6_b_bcbody.njm";
static const char balclaw_bc_die_motion[] = "bcdie_re6_b_bcbody.njm";
static const char balclaw_bc_wait_motion[] = "bcwait_re6_b_bcbody.njm";
static const char balclaw_cl_attack_motion[] = "clattack_re6_b_claw_body.njm";
static const char balclaw_cl_damage_motion[] = "cldamage_re6_b_claw_body.njm";
static const char balclaw_cl_die_motion[] = "cldie_re6_b_claw_body.njm";
static const char balclaw_cl_lturn_motion[] = "cllturn_re6_b_claw_body.njm";
static const char balclaw_cl_rturn_motion[] = "clrturn_re6_b_claw_body.njm";
static const char balclaw_cl_wait_motion[] = "clwait_re6_b_claw_body.njm";
static const char balclaw_bml[] = "bm_ene_balclaw.bml";
static const char balclaw_class_name_text[] = "TObjEneBalClaw";

static const char *balclaw_model_names[] = {
    balclaw_body_model, balclaw_bcbody_model, balclaw_claw_body_model, NULL,
};
static const char *balclaw_motion_names[] = {
    balclaw_bal_attack_motion, balclaw_bal_comb_motion, balclaw_bal_damage_motion, balclaw_bal_die_motion,
    balclaw_bal_shout_motion, balclaw_bal_wait_motion, balclaw_bc_attack_motion, balclaw_bc_damage_motion,
    balclaw_bc_die_motion, balclaw_bc_wait_motion, balclaw_cl_attack_motion, balclaw_cl_damage_motion,
    balclaw_cl_die_motion, balclaw_cl_lturn_motion, balclaw_cl_rturn_motion, balclaw_cl_wait_motion,
    NULL,
};
static BmlResourceDescriptor balclaw_resource_descriptor = {
    balclaw_bml, balclaw_model_names, balclaw_motion_names, 3, 16,
};
s32 balclaw_motion_model_index[16] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2 };
static BalClawPartEntry balclaw_parts[7] = {
    { NULL, 0, 1, 8, 0, 1, 0 },
    { NULL, 1, 1, 8, 0, 2, 0 },
    { NULL, 1, 0x1D, 8, 0, 2, 0 },
    { NULL, 1, 0x27, 8, 0, 2, 0 },
    { NULL, 1, 0x31, 8, 0, 2, 0 },
    { NULL, 1, 0x3B, 8, 0, 2, 0 },
    { NULL, 2, 1, 8, 0, 1, 0 },
};
static s32 balclaw_part_base[4] = { 0x1C, 0x26, 0x30, 0x3A };
const char *balclaw_class_name = balclaw_class_name_text;
// inferred: per arm, the visible model nodes (NULL-terminated), filled by the loader
NJS_OBJECT *balclaw_arm_part_models[4][11];


BmlResource *balclaw_bml_resource;
s32 balclaw_last_shared_update_frame;
extern s32 actor_frame_tick;



void TObjEneBalClaw::scroll_part_uvs() {
    s32 i;
    if (balclaw_last_shared_update_frame != actor_frame_tick) {
        balclaw_last_shared_update_frame = actor_frame_tick;
        for (i = 0; i < 7; i++) {
            BalClawPartEntry *e = &balclaw_parts[i];
            TObjPlayer__sub_8023DEE0(e->plist, e->uv_scroll_u, e->uv_scroll_v, e->texture_id);
        }
    }
}

void TObjEneBalClaw::render_scaled(s32 shadow) {
    f32 a;
    f32 t;
    if (!(actorFlags & 0x800) && shadow != 0) {
        a = hover_height_min;
        t = 1.0f - (0.5f * ((hover_height + wobble_offset) - a)) * (1.0f / (hover_height_max - a));
        Vec v = { 0.0f, 0.0f, 0.0f };
        v.x = t;
        v.y = t;
        v.z = t;
        draw_ground_shadow(&v, 0);
    }
}

void TObjEneBalClaw::update_wobble() {
    if (behavior_flags & 0x20000) {
        wobble_angle = wobble_angle + 0x200;
        wobble_offset = 5.0f * sin_table_lookup(wobble_angle);
        return;
    }
    wobble_offset = (wobble_offset - 0.2f > 0.0f) ? wobble_offset - 0.2f : 0.0f;
}

void TObjEneBalClaw::update_claw_angle() {
    f32 height;
    f32 low;

    if (!(actorFlags & 0x800)) {
        bodies->flags &= ~6;
        if (behavior_flags & 0x10000) {
            if (hover_height < hover_height_max) {
                hover_height += 1.0f;
                return;
            }
            hover_height = hover_height_max;
            bodies->flags |= 4;
            return;
        }
        height = hover_height;
        low = hover_height_min;
        if (height > low) {
            hover_height = height - 1.0f;
            return;
        }
        hover_height = low;
        bodies->flags |= 2;
    }
}

void TObjEneBalClaw::run_hit_reaction() {
    set_state(4);
    behavior_flags |= 1;
}

void TObjEneBalClaw::free_resources() {
    if (balclaw_bml_resource != NULL) {
        delete (BmlResource *)balclaw_bml_resource;
        balclaw_bml_resource = NULL;
    }
}

void TObjEneBalClaw::load_resources() {
    BalClawPartEntry *e;
    NJS_OBJECT *part;
    NJS_OBJECT *model;
    s32 k;
    s32 base;
    s32 count;
    BmlResource *p;
    s32 j;
    s32 m;
    s32 n;
    p = new BmlResource(1, &balclaw_resource_descriptor, 0, 0, NULL);
    balclaw_bml_resource = p;
    model = p->models[1].model;
    for (k = 0; k < 4; k++) {
        base = balclaw_part_base[k];
        count = 0;
        for (j = 0; j < 10; j++) {
            part = find_model_node(model, base + j);
            if (part != NULL && !(part->evalflags & NJD_EVAL_HIDE)) {
                balclaw_arm_part_models[k][count] = part;
                count++;
            }
        }
        balclaw_arm_part_models[k][count] = NULL;
    }
    for (m = 0; m < 7; m++) {
        e = &balclaw_parts[m];
        e->plist = ((NJS_CNK_MODEL *)(find_model_node(get_bml_model((BmlResource *)balclaw_bml_resource, e->model_index), e->part_index))->model)->polygon_list;
    }
    for (n = 0; n < 2; n++) {
        balclaw_body_base_params[n] = TLobby::register_boss(31);
        balclaw_body_attack_params[n] = TLobby::dispatch_shared_handler_b(31);
        balclaw_body_resistance_params[n] = TLobby::register_object(31);
        balclaw_body_behavior_params[n] = (BalClawBehaviorParams *)TLobby::dispatch_shared_handler_a(31);
    }
    for (n = 0; n < 1; n++) {
        balclaw_claw_base_params[n] = TLobby::register_boss(32);
        balclaw_claw_attack_params[n] = TLobby::dispatch_shared_handler_b(32);
        balclaw_claw_resistance_params[n] = TLobby::register_object(32);
        balclaw_claw_behavior_params[n] = (BalClawBehaviorParams *)TLobby::dispatch_shared_handler_a(32);
    }
}


TObjEneBalClaw::~TObjEneBalClaw() {
}

TObjEneBalClaw::TObjEneBalClaw(TObject *parent) : TObjEnemyCustom(parent) {
    m_name = balclaw_class_name;
    add_flags_2e4(8);
    actorFlags |= 0x40000;
    wobble_angle = 0;
    wobble_offset = 0.0f;
    clear_attack_flag();
    behavior_flags |= 0x20000;
}

void TObjEneBalClaw::run_miss_reaction() {
}

void TObjEneBalClaw::run_move_action() {
}

s32 TObjEneBalClaw::is_target_in_attack_range() {
    return 0;
}

void TObjEneBalClaw::clear_attack_flag() {
    behavior_flags &= ~0x10000;
}
