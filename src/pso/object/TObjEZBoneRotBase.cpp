#include "types.h"
#include "pso/object/TObjEZBoneRotPlayer.h"
#include "pso/object/TObjEZBoneRotBase.h"
#include "pso/object/TObjHMS_EZRope_Player.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjEZRopeBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"

#pragma readonly_strings on

const char *ez_bone_rot_base_name = "TObjEZBoneRotBase";
const char *ez_bone_rot_player_name = "TObjEZBoneRotPlayer";

void TObjEZBoneRotPlayer::run_task() {
    f32 cur_scale;
    s32 state_bits;
    TObjPlayer *p;

    p = player;
    state_bits = *(s32 *)((s8 *)p + 0x320) & 0xDF7FF;
    if (state_bits & 0x99003) {
        scale += -0.016666668f;
    } else if ((state_bits & 0x1E0) || (last_rotation_y != p->rotation_y)) {
        scale += 0.13333334f;
    } else if (state_bits & 0x4661C) {
        scale += 0.016666668f;
    } else {
        scale += -0.016666668f;
    }
    cur_scale = scale;
    if (cur_scale < 0.0f) {
        scale = 0.0f;
    } else if (cur_scale > 1.0f) {
        scale = 1.0f;
    }
    advance_bone_rotation();
    last_rotation_y = player->rotation_y;
}

TObjEZBoneRotPlayer::TObjEZBoneRotPlayer(TObjPlayer *parent, NJS_OBJECT *root, EZBoneRotDesc *desc) : TObjEZBoneRotBase(parent, root, desc) {
    m_name = ez_bone_rot_player_name;
    player = parent;
    last_rotation_y = player->rotation_y;
}

TObjEZBoneRotPlayer *TObjEZBoneRotPlayer::create(TObjPlayer *player, NJS_OBJECT *root, EZBoneRotDesc *desc) {
    return new TObjEZBoneRotPlayer(player, root, desc);
}

void TObjEZBoneRotPlayer::advance_bone_rotation() {
    start_bone_rotation_sequence(phase);
    if (scale > 0.0f) {
        phase = phase + desc->phase_step;
    }
}

void TObjEZBoneRotPlayer::calc_bone_offsets_recursive(NJS_OBJECT *bone, s32 angle, s32 amplitude) {
    s32 k;
    f32 t;
    do {
        k = key->bone;
        if (k < 0) {
            return;
        }
        if (k == bone_index) {
            t = (f32) amplitude * sin_table_lookup(angle);
            bone->ang[0] = (*saved_cursor)[0] + (s32) (key->axis[0] * t);
            bone->ang[1] = (*saved_cursor)[1] + (s32) (key->axis[1] * t);
            bone->ang[2] = (*saved_cursor)[2] + (s32) (key->axis[2] * t);
            saved_cursor++;
            key++;
            if (key->bone < 0) {
                return;
            }
        }
        bone_index = bone_index + 1;
        if (bone->child != NULL) {
            calc_bone_offsets_recursive(bone->child, angle + desc->child_phase_offset, (s32) (desc->child_amplitude_scale * (f32) amplitude));
        }
        bone = bone->sibling;
    } while (bone != NULL);
}

void TObjEZBoneRotPlayer::start_bone_rotation_sequence(s32 angle) {
    bone_index = 0;
    key = desc->keys;
    saved_cursor = saved_angles;
    calc_bone_offsets_recursive(root, angle, (s32)((f32) desc->amplitude * scale));
}

void TObjEZBoneRotBase::save_bone_angles_recursive(NJS_OBJECT *bone) {
    s32 k;
    do {
        k = key->bone;
        if (k < 0) {
            return;
        }
        if (k == bone_index) {
            bone->evalflags = bone->evalflags & 0xFFFFFFFD;
            (*saved_cursor)[0] = bone->ang[0];
            (*saved_cursor)[1] = bone->ang[1];
            (*saved_cursor)[2] = bone->ang[2];
            saved_cursor++;
            key++;
            if (key->bone < 0) {
                return;
            }
        }
        bone_index = bone_index + 1;
        if (bone->child != NULL) {
            save_bone_angles_recursive(bone->child);
        }
        bone = bone->sibling;
    } while (bone != NULL);
}

void TObjEZBoneRotBase::save_bone_angles() {
    bone_index = 0;
    key = desc->keys;
    saved_cursor = saved_angles;
    save_bone_angles_recursive(root);
}

TObjEZBoneRotBase::~TObjEZBoneRotBase() {}


TObjEZBoneRotBase::TObjEZBoneRotBase(TObject *parent, NJS_OBJECT *root, EZBoneRotDesc *desc) : TObject(parent) {
    EZBoneRotKey *k;

    m_name = ez_bone_rot_base_name;
    this->root = root;
    this->desc = desc;
    k = this->desc->keys;
    while (k->bone >= 0) {
        k++;
    }
    save_bone_angles();
    phase = 0;
    scale = 0.0f;
}
TObjEZBoneRotPlayer::~TObjEZBoneRotPlayer() {}

extern "C" {
extern Vec ez_bone_rot_player_chain_gravity;

void TObjHMS_EZRope_Player::render() { draw_rope(); }
void TObjHMS_EZRope_Player::run_task() {
    TObjHMSColliderSpec *rs;
    TObjEZRopeCollider *rd;
    TObjHMSRopeSpec *ps;
    TObjEZRopeEnd *pd;
    if (collider_buffer != NULL) {
        push_matrix();
        invert_matrix_in_place(0);
        rs = collider_specs;
        rd = collider_buffer;
        while (rs->bone >= 0) {
            rd->radius = rs->radius;
            push_matrix();
            concat_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(((TObjMotion *)owner)->get_joint_matrix(rs->bone)));
            matrix_mult_vec(NULL, &rs->center, &rd->center);
            pop_matrix();
            rs++;
            rd++;
        }
        pop_matrix();
    }
    push_matrix();
    invert_matrix_in_place(0);
    ps = rope_specs;
    pd = end_buffer;
    while (ps->bone >= 0) {
        pd->twist = ((TObjBase *)owner)->rotation_y + ps->twist_offset;
        push_matrix();
        concat_matrix(NULL, reinterpret_cast<const f32 (*)[4]>(((TObjMotion *)owner)->get_joint_matrix(ps->bone)));
        matrix_mult_vec(NULL, &ps->pos, &pd->pos);
        pop_matrix();
        ps++;
        pd++;
    }
    pop_matrix();
    update_ropes(&ez_bone_rot_player_chain_gravity);
}

}
