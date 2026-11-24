#include "pso/system/memory.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/object/TObjHMS_EZRope_Player_800FEFCC.h"
#include "types.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/object/TObjEZRopeBase.h"
#include "pso/object/TObjHMS_EZRope_Player.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjEZBoneRotPlayer.h"
#include "pso/math/InverseTrig.h"
#include "pso/unk/text_803D96A8.h"

#pragma push
#pragma readonly_strings on

const char *TObjEZRopeBase__name = "TObjEZRopeBase";
const char *TObjHMS_EZRope_Player__name = "TObjHMS_EZRope_Player";
#pragma pop
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

// The colour the debug spheres of the colliders are drawn with.
NJS_ARGB ezrope_chunk_material_color_table = {0.5f, 1.0f, 1.0f, 0.5f};
// inferred: the zeroed end and collider each new rope starts from.
TObjEZRopeEnd ezrope_default_end = {0, {0.0f, 0.0f, 0.0f}};
TObjEZRopeCollider ezrope_default_collider = {0.0f, {0.0f, 0.0f, 0.0f}};
Vec TObjEZBoneRotPlayer__chain_gravity = {0.0f, -0.75f, 0.0f};

extern "C" {
extern u8 debug_chunk_b_object[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
}


// Built with -inline off,deferred: functions are emitted last to first, so they are written in reverse.

TObjEZRopeBase::TObjEZRopeBase(TObject *parent) : TObject(parent) {
    m_name = TObjEZRopeBase__name;
    segment_count = 0;
    segments = 0;
    ends = 0;
    colliders = 0;
    points = 0;
}

TObjEZRopeBase::~TObjEZRopeBase() {
    if (points != nullptr) { safe_free(points); points = nullptr; }
}

void TObjEZRopeBase::init_ropes(TObjEZRopeSegment *segment_list, TObjEZRopeEnd *end_list,
                                  TObjEZRopeCollider *collider_list) {
    s32 total;
    TObjEZRopeSegment *s;
    TObjEZRopeEnd *p;
    Vec *out;
    s32 n;
    total = 0;
    segments = segment_list;
    ends = end_list;
    colliders = collider_list;
    segment_count = 0;
    for (s = segment_list; s->count >= 2; s++) {
        total += s->count;
        segment_count++;
    }
    points = (Vec *)TQuestVmDownLoadServer::alloc(total * sizeof(Vec));
    s = segments;
    p = ends;
    out = points;
    for (; s->count >= 2; s++, p++) {
        Vec v = p->pos;
        for (n = s->count; n > 0; n--, out++) {
            VecCopy(out, &v);
            vec3_add_to(&v, &s->step);
        }
    }
}

void TObjEZRopeBase::update_ropes(Vec *gravity) {
    TObjEZRopeSegment *seg;
    TObjEZRopeEnd *end;
    Vec *p;
    s32 n;
    f32 zero;
    f32 len;
    zero = 0.0f;
    seg = segments;
    end = ends;
    p = points;
    while (seg->count >= 2) {
        len = vector_length(&seg->step);
        VecCopy(p, &end->pos);
        p++;
        n = seg->count - 1;
        while (n > 0) {
            vec3_add_to(p, gravity);
            subtract_vector(p, p - 1);
            if (zero == vector_length(p)) {
                p->x = zero;
                p->y = -1.0f;
                p->z = zero;
            } else {
                normalize_vector(p);
            }
            p->x *= len;
            p->y *= len;
            p->z *= len;
            vec3_add_to(p, p - 1);
            if (colliders != NULL) {
                resolve_collisions(p, len);
            }
            n--;
            p++;
        }
        seg++;
        end++;
    }
}

void TObjEZRopeBase::resolve_collisions(Vec *p, f32 len) {
    Vec v = *p;
    Vec hit;
    s32 iter;
    TObjEZRopeCollider *c;
    f32 push;
    f32 d;
    f32 best;
    f32 reach;

    iter = 16;
    while (1) {
        best = 0.0f;
        for (c = colliders; c->radius >= 0.0f; c++) {
            reach = 0.5f * len + c->radius;
            d = xyz_distance(&v, &c->center);
            if (d < reach && reach - d > best) {
                best = reach - d;
                push = reach;
                VecCopy(&hit, &c->center);
            }
        }
        if (iter <= 0 || 0.0f == best) {
            VecCopy(p, &v);
            return;
        }
        subtract_vector(&v, &hit);
        if (0.0f == vector_length(&v)) {
            v.x = 0.0f;
            v.y = -1.0f;
            v.z = 0.0f;
        } else {
            normalize_vector(&v);
        }
        v.x *= push;
        v.y *= push;
        v.z *= push;
        vec3_add_to(&v, &hit);
        subtract_vector(&v, p - 1);
        if (0.0f == vector_length(&v)) {
            v.x = 0.0f;
            v.y = -1.0f;
            v.z = 0.0f;
        } else {
            normalize_vector(&v);
        }
        v.x *= len;
        v.y *= len;
        v.z *= len;
        vec3_add_to(&v, p - 1);
        iter--;
    }
}

void TObjHMS_EZRope_Player::sub_800FF2D0() {
    Vec d;
    TObjEZRopeSegment *rec;
    TObjEZRopeEnd *ang;
    Vec *pt;
    s32 n;
    s32 yaw;
    TObjEZRopeCollider *b;
    if (segment_count == 0 || segments == NULL || ends == NULL || points == NULL) {
        return;
    }
    rec = segments;
    ang = ends;
    pt = points;
    for (; rec->count >= 2; rec++, ang++) {
        for (n = rec->count - 1; n > 0; n--, pt++) {
            push_matrix();
            translate_matrix_vec3((u8 *)(0), (u8 *)pt);
            VecCopy(&d, &pt[1]);
            subtract_vector(&d, pt);
            if (0.0f == vector_length(&d)) {
                d.x = 0.0f;
                d.y = -1.0f;
                d.z = 0.0f;
            } else {
                normalize_vector(&d);
            }
            yaw = 0;
            if (0.0f != fabs_float(d.x) + fabs_float(d.z)) {
                yaw = (s32)(10430.38043493439 * atan2_float(-d.x, -d.z));
                rotate_matrix_y(0, yaw);
            }
            rotate_matrix_x(0, (s32)(10430.38043493439 * acosf(-d.y)));
            rotate_matrix_y(0, ang->twist - yaw);
            if (n == 1) {
                if (rec->tip_model != NULL) {
                    draw_chunk_object(rec->tip_model);
                }
            } else if (rec->body_model != NULL) {
                draw_chunk_object(rec->body_model);
            }
            pop_matrix();
        }
        pt++;
    }
    if (colliders != NULL) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x10;
        set_chunk_material_override_pair(0, 0x800);
        set_constant_material(&ezrope_chunk_material_color_table);
        for (b = colliders; b->radius >= 0.0f; b++) {
            f32 s;
            push_matrix();
            translate_matrix_vec3((u8 *)(0), (u8 *)&b->center);
            s = 0.2f * b->radius;
            scale_matrix(0, s, s, s);
            draw_chunk_object(debug_chunk_b_object);
            pop_matrix();
        }
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    }
}

void *TObjPlayer::create_hairmove(void *arg1, void *arg2) {
    return new TObjHMS_EZRope_Player(this, static_cast<TObjHMSRopeSpec *>(arg1), static_cast<TObjHMSColliderSpec *>(arg2));
}

void copy_ezrope_segment(TObjEZRopeSegment *dst, TObjEZRopeSegment *src) {
    *dst = *src;
}

void copy_ezrope_end(TObjEZRopeEnd *dst, TObjEZRopeEnd *src) {
    *dst = *src;
}

void copy_ezrope_collider(TObjEZRopeCollider *dst, TObjEZRopeCollider *src) {
    *dst = *src;
}

TObjHMS_EZRope_Player::TObjHMS_EZRope_Player(TObject *parent, TObjHMSRopeSpec *ropes, TObjHMSColliderSpec *colliders)
    : TObjEZRopeBase(parent) {
    s32 rope_count;
    s32 collider_count;
    TObjHMSColliderSpec *collider;
    TObjHMSRopeSpec *rope;
    rope_count = 0;
    collider_count = 0;
    m_name = TObjHMS_EZRope_Player__name;
    owner = parent;
    rope_specs = ropes;
    collider_specs = colliders;
    for (rope = rope_specs; rope->bone >= 0; rope++, rope_count++) {
    }
    if (collider_specs != NULL) {
        for (collider = collider_specs; collider->bone >= 0; collider++, collider_count++) {
        }
    }
    segment_buffer = (TObjEZRopeSegment *)TQuestVmDownLoadServer::alloc((rope_count + 1) * sizeof(TObjEZRopeSegment));
    end_buffer = (TObjEZRopeEnd *)TQuestVmDownLoadServer::alloc(rope_count * sizeof(TObjEZRopeEnd));
    if (collider_count == 0) {
        collider_buffer = NULL;
    } else {
        collider_buffer = (TObjEZRopeCollider *)TQuestVmDownLoadServer::alloc((collider_count + 1) * sizeof(TObjEZRopeCollider));
    }
    {
        TObjHMSRopeSpec *spec;
        TObjEZRopeSegment *segment;
        TObjEZRopeEnd *end;
        segment = segment_buffer;
        spec = rope_specs;
        end = end_buffer;
        for (; spec->bone >= 0; spec++, segment++, end++) {
            copy_ezrope_segment(segment, spec->segment);
            copy_ezrope_end(end, &ezrope_default_end);
        }
        segment->count = -1;
    }
    if (collider_buffer != NULL) {
        TObjHMSColliderSpec *spec = collider_specs;
        TObjEZRopeCollider *dst = collider_buffer;
        for (; spec->bone >= 0; spec++, dst++) {
            copy_ezrope_collider(dst, &ezrope_default_collider);
        }
        copy_ezrope_collider(dst, &ezrope_default_collider);
    }
    init_ropes(segment_buffer, end_buffer, collider_buffer);
}

TObjHMS_EZRope_Player::~TObjHMS_EZRope_Player() {
    if (segment_buffer != NULL) {
        safe_free(segment_buffer);
        segment_buffer = NULL;
    }
    if (end_buffer != NULL) {
        safe_free(end_buffer);
        end_buffer = NULL;
    }
    if (collider_buffer != NULL) {
        safe_free(collider_buffer);
        collider_buffer = NULL;
    }
}
