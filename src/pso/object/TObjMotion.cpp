#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/obj_band.h"
#include "pso/system/BmlResource.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/misc/TUnk_804A7478.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_80141D1C.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/memory.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/player/TObjPlayer.h"

// Still unowned (this unit's .sbss and the model draw module's).
extern s32 anim_model_matrix_array;
extern s32 player_joint_matrix_write_ptr;
extern s32 model_node_callback;
extern s32 chunk_model_node_callback;
extern "C" {
s32 draw_ginja_model_tree__10TObjPlayerFPv(s32, void *, f32);
s32 draw_ginja_model__10TObjPlayerFl(s32, s32, f32);
s32 render_model_tree__12TBoss8DragonFPv(u32, s32, f32);
}

const char *TObjMotion__class_name = "TObjMotion";

void restore_actor_draw_lighting(const char *) {
}

void setup_actor_draw_lighting() {
}

void TUnk_804A7478::draw_model() {
    draw_model_motion(get_model(), get_motion(), get_frame());
}

void TUnk_804A7478::play_backward() {
    f32 next;
    s32 cur_state;
    cur_state = state;
    next = frame - speed;
    switch (cur_state) {
    case 0:
        if (next < 0.0f) {
            next += frame_count;
        }
        frame = next;
        return;
    case 2:
        if (next <= 0.0f) {
            next = 0.0f;
            stop();
        }
        frame = next;
    case 1:
        return;
    }
}

void TUnk_804A7478::play_forward() {
    f32 count;
    f32 last;
    f32 next;
    s32 cur_state;
    cur_state = state;
    next = frame + speed;
    switch (cur_state) {
    case 0:
        count = frame_count;
        if (next >= count) {
            next -= count;
        }
        frame = next;
        return;
    case 2:
        last = frame_count - 1.0f;
        if (next >= last) {
            next = last;
            stop();
        }
        frame = next;
    case 1:
        return;
    }
}

void TUnk_804A7488::draw_model() {
    draw_chunk_object(get_model());
}

int TObjMotion::is_motion_held() {
    return (motion_flags >> 4) & 1;
}

f32 TObjMotion::get_root_motion_step(f32 *dx, f32 *dz) {
    f32 t;
    f32 dv;
    f32 t2;
    f32 span;
    f32 d;
    f32 end;
    f32 start;
    NJS_MDATA2 *root;
    NJS_MKEY_F *k;
    s32 n;
    s32 i;
    root = (NJS_MDATA2 *)current_motion->mdata;
    t = frame;
    i = 0;
    k = (NJS_MKEY_F *)root->p[0];
    n = root->nb[0] - 1;
    for (; i < n; i++) {
        if (k[1].keyframe > (s32)t) {
            break;
        }
        k++;
    }
    if (i >= n) {
        *dx = 0.0f;
        *dz = 0.0f;
        return 0.0f;
    }
    t2 = t + play_speed;
    span = (f32)(k[1].keyframe - k->keyframe);
    dv = k[1].key[2] - k->key[2];
    t = frame;
    start = k->key[2] + (dv * (t - (f32)k->keyframe)) / span;
    for (; i < n; i++) {
        if (k[1].keyframe >= (s32)t2) {
            break;
        }
        k++;
    }
    if (i >= n) {
        end = k->key[2];
    } else {
        span = (f32)(k[1].keyframe - k->keyframe);
        dv = k[1].key[2] - k->key[2];
        end = k->key[2] + (dv * (t2 - (f32)k->keyframe)) / span;
    }
    d = end - start;
    *dx = d * sin_table_lookup(rotation_y);
    *dz = d * cos_table_lookup(rotation_y);
    return d;
}

s32 TObjMotion::is_anim_finished() {
    u32 flags = motion_flags;
    if ((!(flags & MOTION_BLENDING) || (flags & MOTION_NO_BLEND)) && requested_action == current_action) {
        return 1;
    }
    return 0;
}

f32 TObjMotion::get_action_frame_count(s16 action) {
    return (f32)motion_list[action_table[action].motion].motion->frameCount;
}

void TObjMotion::set_action_motion(s32 action) {
    current_motion = (NJS_MOTION *)motion_list[action_table[action].motion].motion;
}

NJS_MOTION *TObjMotion::get_action_motion(s16 action) {
    return (NJS_MOTION *)motion_list[action_table[action].motion].motion;
}

void write_node_flags(NJS_OBJECT *object) {
    NJS_CNK_MODEL *model;
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;

    node_flag_cursor->object = object;
    node_flag_cursor->flags = 0;
    if (!(object->evalflags & NJD_EVAL_UNIT_POS)) {
        node_flag_cursor->flags |= NODE_HAS_POS;
    }
    if (!(object->evalflags & NJD_EVAL_UNIT_ANG)) {
        node_flag_cursor->flags |= NODE_HAS_ANG;
    }
    if (!(object->evalflags & NJD_EVAL_UNIT_SCL)) {
        node_flag_cursor->flags |= NODE_HAS_SCL;
    }
    model = (NJS_CNK_MODEL *)object->model;
    if (model != NULL) {
        node_flag_cursor->flags |= NODE_HAS_MODEL;
        if (model->vertex_list != NULL) {
            node_flag_cursor->flags |= NODE_HAS_VERTICES;
        }
        if (model->polygon_list != NULL) {
            node_flag_cursor->flags |= NODE_HAS_POLYGONS;
        }
    }
    child = object->child;
    if (child != NULL) {
        node_flag_cursor->flags |= NODE_HAS_CHILD;
        node_flag_cursor++;
        write_node_flags(child);
    }
    sibling = object->sibling;
    if (sibling != NULL) {
        node_flag_cursor->flags |= NODE_HAS_SIBLING;
        node_flag_cursor++;
        write_node_flags(sibling);
    }
}

void make_node_flag_table(NJS_OBJECT *object, NodeFlagEntry *table) {
    node_flag_cursor = table;
    write_node_flags(object);
    node_flag_cursor++;
    node_flag_cursor->object = NULL;
}

s32 TObjMotion::calc_joint_matrices(NJS_MOTION *with, f32 at_frame, s32 matrices) {
    if (with == NULL || model == NULL) {
        return 0;
    }
    TObjPlayer::set_global_flag();
    player_joint_matrix_write_ptr = matrices;
    TObjEneRe7Berura::set_global_state((s32)save_joint_matrix_callback);
    render_model_tree__12TBoss8DragonFPv((u32)model, (s32)with, at_frame);
    TObjEneRe7Berura::set_global_state(0);
    TObjPlayer::clear_global_state();
    return 1;
}

s32 TObjMotion::calc_joint_matrices(f32 at_frame) {
    if (current_motion == NULL || model == NULL) {
        return 0;
    }
    TObjPlayer::set_global_flag();
    player_joint_matrix_write_ptr = anim_model_matrix_array;
    TObjEneRe7Berura::set_global_state((s32)save_joint_matrix_callback);
    render_model_tree__12TBoss8DragonFPv((u32)model, (s32)current_motion, at_frame);
    TObjEneRe7Berura::set_global_state(0);
    TObjPlayer::clear_global_state();
    return 1;
}

f32 TObjMotion::get_motion_frame() {
    if (motion_flags & MOTION_BLENDING) {
        return 0.0f;
    }
    return get_frame();
}

int objInBand(GameObj *obj, f32 v) {
    TObjMotion *self = (TObjMotion *)obj;
    u32 flags = self->motion_flags;
    if (!((flags & MOTION_BLENDING) && !(flags & MOTION_NO_BLEND)) &&
        self->requested_action == self->current_action &&
        v < self->frame &&
        self->frame <= v + self->play_speed)
        return 1;
    return 0;
}

void save_joint_matrix_callback() {
    get_current_matrix((void *)player_joint_matrix_write_ptr);
    player_joint_matrix_write_ptr = player_joint_matrix_write_ptr + 0x30;
}

void TObjMotion::draw_saving_joints() {
    u32 flags;
    player_joint_matrix_write_ptr = (s32)joint_matrices;
    TObjEneRe7Berura::set_global_state((s32)save_joint_matrix_callback);
    flags = motion_flags;
    if ((flags & MOTION_BLENDING) && !(flags & MOTION_DRAW_UNBLENDED)) {
        draw_model_blend_motion(model, &blend, frame);
    } else {
        draw_model_motion(model, current_motion, frame);
    }
    TObjEneRe7Berura::set_global_state(0);
    set_default_alpha_blend();
}

void TObjMotion::draw_saving_joints_checked() {
    u32 flags;
    u32 matrices;

    matrices = (u32)joint_matrices;
    if (matrices != 0) {
        player_joint_matrix_write_ptr = matrices;
        TObjEneRe7Berura::set_global_state((s32)save_joint_matrix_callback);
        flags = motion_flags;
        if ((flags & MOTION_BLENDING) && !(flags & MOTION_DRAW_UNBLENDED)) {
            draw_model_blend_motion(model, &blend, frame);
        } else {
            draw_model_motion(model, current_motion, frame);
        }
        TObjEneRe7Berura::set_global_state(0);
        set_default_alpha_blend();
    }
}

void TObjMotion::draw_motion_model() {
    TObjPlayer::set_global_flag();
    if (motion_flags & MOTION_BLENDING) {
        draw_model_blend_motion(model, &blend, frame);
    } else {
        TObjEneRe7Berura::set_global_state(chunk_model_node_callback);
        draw_model_motion(model, current_motion, frame);
        TObjEneRe7Berura::set_global_state(0);
    }
    set_default_alpha_blend();
    TObjPlayer::clear_global_state();
}

void TObjMotion::draw() {
    TObjPlayer::set_global_flag();
    setup_actor_draw_lighting();
    if (motion_flags & MOTION_BLENDING) {
        draw_model_blend_motion(model, &blend, frame);
    } else {
        TObjEneRe7Berura::set_global_state(chunk_model_node_callback);
        draw_model_motion(model, current_motion, frame);
        TObjEneRe7Berura::set_global_state(0);
    }
    set_default_alpha_blend();
    restore_actor_draw_lighting(m_name);
    TObjPlayer::clear_global_state();
}

void TObjMotion::draw_ginja_motion_model() {
    TObjPlayer::set_global_flag();
    setup_actor_draw_lighting();
    if (motion_flags & MOTION_BLENDING) {
        draw_ginja_model_tree__10TObjPlayerFPv((s32)model, &blend, frame);
    } else {
        set_model_node_callback(model_node_callback);
        draw_ginja_model__10TObjPlayerFl((s32)model, (s32)current_motion, frame);
        set_model_node_callback(0);
    }
    set_default_alpha_blend();
    restore_actor_draw_lighting(m_name);
    TObjPlayer::clear_global_state();
}

void TObjMotion::change_action(s16 action) {
    TObjMotionAction *entry = action_table + action;

    motion_flags &= ~MOTION_HELD;
    action_flags = entry->flags;
    if ((motion_flags & MOTION_NO_BLEND) || (motion_flags & MOTION_KEEP_FRAME) ||
        (action_flags & ACTION_NO_BLEND_IN) || (action_table[current_action].flags & ACTION_NO_BLEND_OUT)) {
        motion_flags &= ~MOTION_BLENDING;
        set_action_motion(action);
        if (test_motion_flags(MOTION_OVERRIDE_SPEED) != 0) {
            clear_motion_flags(MOTION_OVERRIDE_SPEED);
            play_speed = override_speed;
        } else {
            play_speed = entry->speed;
        }
        play_mode = entry->mode;
        frame_count = current_motion->nbFrame;
        if (action_flags & ACTION_INTERPOLATE) {
            set_motion_interpolation_flag();
        }
        if (motion_flags & MOTION_KEEP_FRAME) {
            motion_flags &= ~MOTION_KEEP_FRAME;
            frame = blend.frame[0];
            {
                f32 fr = frame;
                f32 n = frame_count;
                if (1.0f + fr >= n) {
                    frame = fr - n;
                }
            }
        } else {
            frame = 0.0f;
        }
    } else {
        if (frame >= frame_count - 1.0f) {
            frame = frame - 1.0f;
        }
        play_mode = MOTION_MODE_BLEND;
        motion_flags |= MOTION_BLENDING | MOTION_STARTED_BLEND;
        blend.motion[0] = current_motion;
        blend.frame[0] = frame;
        previous_action = current_action;
        set_action_motion(action);
        blend.motion[1] = current_motion;
        blend.frame[1] = 0.0f;
        next_play_mode = entry->mode;
        frame = 0.0f;
        frame_count = current_motion->nbFrame;
        if (test_motion_flags(MOTION_OVERRIDE_BLEND_SPEED) != 0) {
            clear_motion_flags(MOTION_OVERRIDE_BLEND_SPEED);
            play_speed = override_blend_speed;
        } else {
            play_speed = blend_speed;
        }
        if (action_flags & ACTION_INTERPOLATE) {
            set_motion_interpolation_flag();
        }
    }
    current_action = action;
}

void TObjMotion::init_motion(TObjMotionAction *actions, BmlMotionEntry *motions, s16 action) {
    set_field_d8((s32)actions);
    set_field_dc((s32)motions);
    set_animation(action);
}

void TObjMotion::set_animation(s16 action) {
    TObjMotionAction *entry;

    requested_action = action;
    current_action = requested_action;
    set_action_motion(requested_action);
    entry = get_anim_entry(requested_action);
    play_speed = entry->speed;
    play_mode = entry->mode;
    frame_count = current_motion->nbFrame;
    frame = 0.0f;
    motion_flags = motion_flags & ~MOTION_BLENDING;
    action_flags = entry->flags;
    blend.motion[0] = current_motion;
    blend.frame[0] = 0.0f;
    blend.motion[1] = current_motion;
    blend.frame[1] = 0.0f;
    previous_action = requested_action;
    if (action_flags & ACTION_INTERPOLATE) {
        set_motion_interpolation_flag();
    }
}

extern "C" void advance_animation_playback(TObjMotion *self) {
    f32 last;
    if (self->motion_flags & MOTION_PAUSED) {
        return;
    }
    self->frame += self->play_speed;
    last = self->frame_count - 1.0f;
    self->motion_flags &= ~(MOTION_CHAINED | MOTION_ENDED | MOTION_BLEND_DONE | MOTION_STARTED_BLEND);
    if (self->requested_action != self->current_action) {
        if (self->frame >= self->frame_count) {
            self->frame -= self->play_speed;
        }
        self->change_action(self->requested_action);
    }
    switch (self->play_mode) {
    case MOTION_MODE_LOOP:
        if (self->frame >= self->frame_count) {
            self->frame -= self->frame_count;
            if (self->test_motion_flags(MOTION_OVERRIDE_SPEED) != 0) {
                self->play_speed = self->override_speed;
            }
        }
        break;
    case MOTION_MODE_CHAIN:
        if (self->frame >= last) {
            if (self->get_action_motion(self->action_table[self->requested_action].next) == NULL) {
                self->frame -= self->frame_count;
            } else {
                self->requested_action = self->action_table[self->requested_action].next;
                self->change_action(self->requested_action);
                self->motion_flags |= MOTION_CHAINED;
            }
        }
        break;
    case MOTION_MODE_ONCE:
        if (self->frame >= last) {
            self->play_mode = MOTION_MODE_STOPPED;
            self->frame -= self->play_speed;
            self->play_speed = 0.0f;
            self->motion_flags |= MOTION_HELD | MOTION_ENDED;
        }
        break;
    case MOTION_MODE_BLEND:
        if (self->frame >= 1.0f) {
            self->frame = 0.0f;
            if (self->test_motion_flags(MOTION_OVERRIDE_SPEED) != 0) {
                self->clear_motion_flags(MOTION_OVERRIDE_SPEED);
                self->play_speed = self->override_speed;
            } else {
                self->play_speed = self->action_table[self->requested_action].speed;
            }
            self->play_mode = self->next_play_mode;
            self->motion_flags &= ~MOTION_BLENDING;
            self->motion_flags |= MOTION_BLEND_DONE;
        }
        break;
    case MOTION_MODE_STOPPED:
        self->frame -= self->play_speed;
        break;
    }
}

void TObjMotion::reset_motion_fields() {
    motion_flags = 0;
    action_flags = 0;
    current_action = 0;
    requested_action = 0;
    previous_action = 0;
    frame_count = 0.0f;
    play_speed = 0.0f;
    frame = 0.0f;
    blend_speed = 0.2f;
    override_speed = 0.0f;
    override_blend_speed = 0.0f;
    blend.motion[0] = NULL;
    blend.motion[1] = NULL;
    blend.frame[0] = 0.0f;
    blend.frame[1] = 0.0f;
    next_play_mode = 0;
    play_mode = 0;
}

TObjMotion::~TObjMotion() {
}

TObjMotion::TObjMotion(TObject *parent) : TObjCollidable(parent) {
    m_name = TObjMotion__class_name;
    reset_motion_fields();
    action_table = NULL;
    current_motion = NULL;
    motion_list = NULL;
    joint_matrices = NULL;
    extra = 0;
}

// The two part destructors are still written out by hand: their vtables
// come out ahead of TObjMotion's in the original, which the compiler only
// gives these classes when their destructors are inline.
extern "C" {
void *__dt__13TUnk_804A7478Fv(TUnk_804A7478 *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 4) = __vt__13TUnk_804A7478;
        __dt__13TUnk_804A7488Fv(self, 0);
        if (del > 0) {
            ::operator delete(self);
        }
    }
    return self;
}

void *__dt__13TUnk_804A7488Fv(TUnk_804A7488 *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 4) = __vt__13TUnk_804A7488;
        if (del > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
}

f32 TUnk_804A7478::get_frame() {
    return frame;
}

NJS_MOTION *TUnk_804A7478::get_motion() {
    return motion;
}

void *TUnk_804A7488::get_model() {
    return model;
}

void TUnk_804A7478::stop() {
    state = 1;
}

void TObjMotion::set_motion_interpolation_flag() {
    current_motion->inp_fn |= 0x80;
}

int TObjMotion::test_motion_flags(s32 flags) {
    return (motion_flags & flags) != 0;
}

TObjMotionAction *TObjMotion::get_anim_entry(int action) {
    return action_table + action;
}
