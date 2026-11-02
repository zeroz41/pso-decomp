#include "pso/system/ModelDrawCallback.h"
#include "pso/animation/MotionContext.h"
#include "types.h"
#include "pso/unk/text_803E4D8C.h"

struct RecoveredGlobal_803E5458_lbl_8058DC00 {
    s32 value;
    u8 remaining[0x44];
};

struct Ctx_803E53BC { s32 f0; s32 f4; s32 f8; s32 fc; s32 f10; s32 f14; s32 f18; s32 f1c; };

#include <stddef.h>
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_803D662C_lbl_8058D4D0 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_803D77C0_lbl_8047E3C8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_803D77C0_lbl_804FA500 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_803D77C0_lbl_804FA50C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_803D77C0_lbl_804FA51C {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_803D78A8_lbl_8058CAB8 {
    s32 value;
    u8 remaining[0x7C];
};

struct Node_803E4E20 {
    u32 flags;
    s32 *obj;
    u8 pad[0x2C - 0x8];
    Node_803E4E20 *child;
    Node_803E4E20 *next;
};


struct G_803E4F14 {
    s32 f0;
    s32 f4;
    s32 f8;
    void **keys;
    s32 *vals;
    f32 f14;
    s32 f18;
    s32 idx;
    u32 flags;
};
struct Key_803E500C { u32 frame; f32 *data; };

u8 *lbl_805D7818;
extern RecoveredGlobal_803E5458_lbl_8058DC00 lbl_8058DC00;
extern "C" {
void compose_motion_node_matrix(void *arg0);
void push_matrix(void);
s32 pop_matrix(void);
void update_render_state__10TObjPlayerFv(s32 *, s32 *);
}
void find_motion_key_interval(void *, s32, s32 count, f32 t, void *, void *, void *);
extern u32 *lbl_805D7778;

#pragma push
#pragma scheduling off
#pragma opt_common_subs off
#pragma peephole off
typedef char RecoveredGlobal_803D662C_lbl_8058D4D0_size[sizeof(RecoveredGlobal_803D662C_lbl_8058D4D0) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_803D77C0_lbl_8047E3C8_size[sizeof(RecoveredGlobal_803D77C0_lbl_8047E3C8) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_803D77C0_lbl_804FA500_size[sizeof(RecoveredGlobal_803D77C0_lbl_804FA500) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_803D77C0_lbl_804FA50C_size[sizeof(RecoveredGlobal_803D77C0_lbl_804FA50C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_803D77C0_lbl_804FA51C_size[sizeof(RecoveredGlobal_803D77C0_lbl_804FA51C) == 0x24 ? 1 : -1];

void draw_shape_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, NJS_MOTION *shape, f32 frame, ModelDrawCallback draw_model) {
    ModelDrawContext *p = model_draw_context;
    bind_motion_context(motion, frame);
    p->draw = draw_model;
    if (shape == NULL) {
        draw_motion_node_tree_with_context(model);
        return;
    }
    TObjPlayer__sub_803E5458(0);
    TObjPlayer__sub_803E53F8((u8 *)shape, frame);
    ((TObjPlayer *)model)->draw_motion_node_list();
}

void TObjPlayer::draw_motion_node_list() {
    s32 arg0 = (s32)this;
    s32 tmp;
    ModelDrawContext *ctx;
    s32 *obj;
    s32 save;
    Node_803E4E20 *n;
    n = (Node_803E4E20 *)arg0;
    ctx = model_draw_context;
    do {
        push_matrix();
        compose_motion_node_matrix(n);
        if (!(n->flags & 0x80)) {
            obj = n->obj;
            if (obj != NULL && !(n->flags & 8)) {
                update_render_state__10TObjPlayerFv(obj, &tmp);
                save = *obj;
                *obj = tmp;
                ctx->draw(obj);
                *obj = save;
            } else {
                TObjPlayer::advance_render_counters();
            }
        } else if (n->obj != NULL && !(n->flags & 8)) {
            ctx->draw(n->obj);
        }
        if (n->child != NULL) {
            ((TObjPlayer *)((s32)n->child))->draw_motion_node_list();
        }
        pop_matrix();
        n = n->next;
    } while (n != NULL);
}

#define G_4F14 ((G_803E4F14 *)lbl_805D7818)
#pragma push
#pragma optimize_for_size off
#pragma opt_common_subs on
void TObjPlayer::resolve_render_keys(u32 **src, u32 **dst) {
    s32 bi;
    s32 ai;
    void *a;
    void *b;

    if (*src == 0) {
        *dst = 0;
        return;
    }
    if (G_4F14->flags & 0x10) {
        a = G_4F14->keys[G_4F14->idx];
        if (a != 0) {
            ai = G_4F14->vals[G_4F14->idx];
        }
        G_4F14->idx++;
    } else {
        a = 0;
    }
    if (G_4F14->flags & 0x20) {
        b = G_4F14->keys[G_4F14->idx];
        if (b != 0) {
            bi = G_4F14->vals[G_4F14->idx];
        }
        G_4F14->idx++;
    } else {
        b = 0;
    }
    if (a != 0 || b != 0) {
        TObjPlayer__sub_803E500C(a, ai, b, bi, G_4F14->f14, *src, dst);
        return;
    }
    *dst = *src;
}

#pragma pop
#undef G_4F14

#pragma push
#pragma use_lmw_stmw off
void TObjPlayer__sub_803E500C(void *motA, s32 keyA, void *motB, s32 keyB, f32 t, u32 *src, u32 **out) {
    f32 *a0;
    f32 *a1;
    f32 *b0;
    f32 *b1;
    f32 wa;
    f32 wb;
    f32 fa;
    Key_803E500C *ka0;
    Key_803E500C *ka1;
    f32 fb;
    Key_803E500C *kb0;
    Key_803E500C *kb1;
    u32 *s;
    u32 hdr;
    u32 *p;
    u32 *d;
    u32 n;
    s32 count;
    s32 pos;
    s32 rot;
    s32 c0;
    s32 c1;
    s32 i;
    if (motA != 0) {
        find_motion_key_interval(motA, 8, keyA, t, &ka0, &ka1, &fa);
        wa = 1.0f - fa;
        a0 = ka0->data;
        b0 = ka1->data;
    }
    if (motB != 0) {
        find_motion_key_interval(motB, 8, keyB, t, &kb0, &kb1, &fb);
        wb = 1.0f - fb;
        a1 = kb0->data;
        b1 = kb1->data;
    }
    p = src;
    *out = d = lbl_805D7778;
    for (;;) {
        hdr = p[0];
        if ((u8)hdr == 0xFF) {
            *d = hdr;
            return;
        }
        n = hdr >> 16;
        count = p[1] >> 16;
        switch ((u8)hdr) {
        case 34:
            pos = 1; rot = 0; c0 = 0; c1 = 0;
            break;
        case 35:
            pos = 1; rot = 0; c0 = 1; c1 = 0;
            break;
        case 36:
            pos = 1; rot = 0; c0 = 0; c1 = 1;
            break;
        case 41:
            pos = 1; rot = 1; c0 = 0; c1 = 0;
            break;
        case 42:
            pos = 1; rot = 1; c0 = 1; c1 = 0;
            break;
        case 43:
            pos = 1; rot = 1; c0 = 0; c1 = 1;
            break;
        case 44:
            pos = 1; rot = 1; c0 = 0; c1 = 1;
            break;
        default:
            pos = 0; rot = 0; c0 = 0; c1 = 0;
            break;
        }
        d[0] = hdr;
        d[1] = p[1];
        s = p + 2;
        d += 2;
        for (i = 0; i < count; i++) {
            if (pos != 0) {
                if (motA != 0) {
                    ((f32 *)d)[0] = a0[0] * wa + b0[0] * fa;
                    ((f32 *)d)[1] = a0[1] * wa + b0[1] * fa;
                    ((f32 *)d)[2] = a0[2] * wa + b0[2] * fa;
                    a0 += 3;
                    b0 += 3;
                } else {
                    ((f32 *)d)[0] = ((f32 *)s)[0];
                    ((f32 *)d)[1] = ((f32 *)s)[1];
                    ((f32 *)d)[2] = ((f32 *)s)[2];
                }
                d += 3;
                s += 3;
            }
            if (rot != 0) {
                if (motB != 0) {
                    ((f32 *)d)[0] = a1[0] * wb + b1[0] * fb;
                    ((f32 *)d)[1] = a1[1] * wb + b1[1] * fb;
                    ((f32 *)d)[2] = a1[2] * wb + b1[2] * fb;
                    a1 += 3;
                    b1 += 3;
                } else {
                    ((f32 *)d)[0] = ((f32 *)s)[0];
                    ((f32 *)d)[1] = ((f32 *)s)[1];
                    ((f32 *)d)[2] = ((f32 *)s)[2];
                }
                d += 3;
                s += 3;
            }
            if (c0 != 0) {
                *d++ = *s++;
            }
            if (c1 != 0) {
                *d++ = *s++;
            }
        }
        p += n + 1;
    }
}
#pragma pop

void TObjPlayer__sub_803E5378(s32 n) {
    s32 w = n * 4;
    s32 a;
    *(s32 *)(lbl_805D7818 + 0x4) = w;
    *(s32 *)(lbl_805D7818 + 0x8) = w + w;
    a = *(s32 *)(lbl_805D7818 + 0x0);
    *(s32 *)(lbl_805D7818 + 0xc) = a;
    *(s32 *)(lbl_805D7818 + 0x10) = a + *(s32 *)(lbl_805D7818 + 0x4);
    *(s32 *)(lbl_805D7818 + 0x1c) = 0;
}
typedef char RecoveredGlobal_803D78A8_lbl_8058CAB8_size[sizeof(RecoveredGlobal_803D78A8_lbl_8058CAB8) == 0x80 ? 1 : -1];
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer::advance_render_counters() {
    s32 v = ((Ctx_803E53BC *)lbl_805D7818)->f0;
    v += ((Ctx_803E53BC *)lbl_805D7818)->f8;
    ((Ctx_803E53BC *)lbl_805D7818)->f0 = v;
    ((Ctx_803E53BC *)lbl_805D7818)->fc = v;
    ((Ctx_803E53BC *)lbl_805D7818)->f10 = v + ((Ctx_803E53BC *)lbl_805D7818)->f4;
    ((Ctx_803E53BC *)lbl_805D7818)->f1c = 0;
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer__sub_803E53F8(u8 *arg0, f32 farg0) {
    *(s32 *)((s8 *)lbl_805D7818 + 0) = (s32) *(s32 *)((s8 *)arg0 + 0);
    *(s32 *)((s8 *)lbl_805D7818 + 0x18) = (s32) *(s32 *)((s8 *)arg0 + 4);
    *(f32 *)((s8 *)lbl_805D7818 + 0x14) = farg0;
    *(s32 *)((s8 *)lbl_805D7818 + 0x1C) = 0;
    *(s32 *)((s8 *)lbl_805D7818 + 0x20) = (s32) *(u16 *)((s8 *)arg0 + 8);
    TObjPlayer__sub_803E5378((s32)(*(u16 *)((s8 *)arg0 + 0xA) & 0xFFFFFF3F));
}
#pragma pop

typedef char RecoveredGlobal_803E5458_lbl_8058DC00_size[sizeof(RecoveredGlobal_803E5458_lbl_8058DC00) == 0x48 ? 1 : -1];
void TObjPlayer__sub_803E5458(s32 arg0) {
    lbl_805D7818 = (u8 *)&lbl_8058DC00.value + (arg0 * 0x24);
}

RecoveredGlobal_803E5458_lbl_8058DC00 lbl_8058DC00;
