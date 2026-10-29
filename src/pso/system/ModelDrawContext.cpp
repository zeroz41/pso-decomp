#include "types.h"
#include "pso/system/ModelDrawContext.h"

struct RecoveredGlobal_803DCBD8_lbl_8058D380 {
    s32 value;
    u8 remaining[0xEC];
};

typedef s32 (*RecoveredCallback_92513335c3ed)(void *);
typedef void (*RecoveredCallback_2be3cacebb2e)(void);
struct MotionCtx_803DC894 {
    u8 pad[0xC];
    void (*fn)(void);
};

struct Mtx_803DC994 { f32 m[3][4]; };

struct C_803DCBF0 { u32 a; u32 b; u32 c; u32 d; u32 e; u32 f; u32 g; u32 h; u32 i; };

typedef void (*RecoveredCallback_1268626c296b)(void *);
struct Node_803DCB40 {
    u32 flags;
    u32 f4;
    u8 pad8[0x2C - 0x8];
    struct Node_803DCB40 *child;
    struct Node_803DCB40 *next;
};

struct Tbl_803DCC34 { u32 v[12]; };

struct Reg_803DCC34 { u8 pad[0xC]; u32 mode; };

struct N_803DC9E4 {
    u32 flags;
    s32 m4;
    u8 m8[0xC];
    u8 m14[0xC];
    u8 m20[0xC];
    struct N_803DC9E4 *child;
    struct N_803DC9E4 *next;
    f32 f34;
};

extern RecoveredGlobal_803DCBD8_lbl_8058D380 render_contexts;
extern u8 *current_render_context;
extern "C" {
void select_render_context(s32 arg0);
void compose_motion_node_matrix(void *arg0);
s32 push_matrix();
s32 pop_matrix();
s32 queue_model_draw_matrix(int, void *);
void bind_motion_context(void *motion, f32 frame);
void init_model_draw_queue(void *);
}
extern s32 model_node_callback;
extern s32 current_matrix;
void draw_ginja_motion_node_tree(u8 *arg0);
void flush_model_draw_queue(void);
extern "C" {
void prepare_ginja_model(void *);
void draw_ginja_model_lists(void);
extern struct MotionCtx_803DC894 * const model_draw_context;
extern RecoveredCallback_2be3cacebb2e ginja_draw_end_callback;
void copy_rotation_to_current_matrix(struct Mtx_803DC994 *src);
void GXSetBlendMode(int, int, int, int);
__declspec(section ".rodata") extern const u32 cached_blend_factor_table[];
void apply_cached_blend_mode(s32 arg0);
void init_render_context(C_803DCBF0 *arg0);
extern RecoveredCallback_1268626c296b motion_node_draw_callback;
void draw_motion_node_tree_with_context(struct Node_803DCB40 *arg0);
__declspec(section ".rodata") extern const Tbl_803DCC34 gx_blend_mode_table;
s32 apply_quat_rotation__10TObjPlayerFf(void *, f32);
s32 rotate_matrix_by_node_angles(void *, void *);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern s32 node_saved_matrix[];
void traverse_model_node_tree(struct N_803DC9E4 *p, s32 (*cb)(s32));
void set_model_node_callback(s32 arg0) {
    model_node_callback = arg0;
}
typedef char RecoveredGlobal_803DCBD8_lbl_8058D380_size[sizeof(RecoveredGlobal_803DCBD8_lbl_8058D380) == 0xF0 ? 1 : -1];

void draw_ginja_model_with_motion(void *model, void *motion, f32 frame) {
    bind_motion_context(motion, frame);
    model_draw_context->fn = draw_ginja_model_lists;
    prepare_ginja_model(model_draw_context);
    init_model_draw_queue((void *) draw_ginja_model_lists);
    draw_ginja_motion_node_tree((u8 *)model);
    flush_model_draw_queue();
    if (ginja_draw_end_callback != NULL) {
        ginja_draw_end_callback();
    }
}
}
void get_current_matrix(void *m);
#pragma push
#pragma peephole off
#pragma scheduling off
void draw_ginja_motion_node_tree(u8 *arg0) {
    u32 model;
    u8 *temp_r3_2;
    u8 *child;
    child = arg0;
    do {
        push_matrix();
        compose_motion_node_matrix((child));
        if (((s32 (*)(void *)) (*(RecoveredCallback_92513335c3ed *)&model_node_callback)) != NULL) {
            (*(RecoveredCallback_92513335c3ed *)&model_node_callback)(child);
        }
        model = *(u32 *)((s8 *)child + 4);
        if ((model != 0U) && ((u32) (*(s32 *)((s8 *)child + 0) & 8) == 0)) {
            queue_model_draw_matrix((int)model, (void *)current_matrix);
        }
        temp_r3_2 = (u8 *)(*(u8 **)((s8 *)child + 0x2C));
        if (temp_r3_2 != NULL) {
            draw_ginja_motion_node_tree(temp_r3_2);
        }
        pop_matrix();
        child = (u8 *)(*(u8 **)((s8 *)child + 0x30));
    } while (child != NULL);
}
#pragma pop

void copy_rotation_to_current_matrix(struct Mtx_803DC994 *src) {
    struct Mtx_803DC994 *dst = (struct Mtx_803DC994 *)current_matrix;
    dst->m[0][0] = src->m[0][0];
    dst->m[0][1] = src->m[0][1];
    dst->m[0][2] = src->m[0][2];
    dst->m[1][0] = src->m[1][0];
    dst->m[1][1] = src->m[1][1];
    dst->m[1][2] = src->m[1][2];
    dst->m[2][0] = src->m[2][0];
    dst->m[2][1] = src->m[2][1];
    dst->m[2][2] = src->m[2][2];
}

struct Mtx_803DC994;
void traverse_model_node_tree(struct N_803DC9E4 *p, s32 (*cb)(s32)) {
    do {
        u32 f = p->flags;
        if (f & 0x800) {
            get_current_matrix((node_saved_matrix));
        }
        if ((f & 7) == 7) {
            if (!(f & 8)) {
                cb(p->m4);
            }
            if (!(f & 0x10)) {
                traverse_model_node_tree(p->child, cb);
            }
        } else {
            push_matrix();
            if (!(f & 1)) {
                post_translate_matrix(p->m8);
            }
            if (!(f & 2)) {
                if (f & 0x1000) {
                    copy_rotation_to_current_matrix((struct Mtx_803DC994 *) (node_saved_matrix));
                } else if (f & 0x400) {
                    ((s32 (*)(f32, void *))apply_quat_rotation__10TObjPlayerFf)(p->f34, p->m14);
                } else {
                    rotate_matrix_by_node_angles(p->m14, (void *) (f & 0x20));
                }
            }
            if (!(f & 4)) {
                scale_current_matrix(p->m20);
            }
            if (!(f & 8)) {
                cb(p->m4);
            }
            if (!(f & 0x10)) {
                traverse_model_node_tree(p->child, cb);
            }
            pop_matrix();
        }
        p = p->next;
    } while (p != NULL);
}

void draw_motion_node_tree_with_context(struct Node_803DCB40 *arg0) {
    u32 t;
    do {
        push_matrix();
        compose_motion_node_matrix(arg0);
        if (motion_node_draw_callback != NULL) {
            motion_node_draw_callback(arg0);
        }
        t = arg0->f4;
        if (t != 0 && (arg0->flags & 8) == 0) {
            ((void (*)(u32, struct MotionCtx_803DC894 *))model_draw_context->fn)(t, model_draw_context);
        }
        if (arg0->child != NULL) {
            draw_motion_node_tree_with_context(arg0->child);
        }
        pop_matrix();
        arg0 = arg0->next;
    } while (arg0 != NULL);
}

void select_render_context(s32 arg0) {
    current_render_context = (u8 *)&render_contexts.value + (arg0 * 0x28);
}

void init_render_context(C_803DCBF0 *arg0) {
    arg0->a = 0x808C0000;
    arg0->c = 0;
    arg0->d = 0x949004C0;
    arg0->e = 0x80012;
    arg0->f = -1;
    arg0->g = -1;
    arg0->h = 0x20000000;
    arg0->i = 0;
}

#define REG_803DCC34 ((Reg_803DCC34 *) current_render_context)
void set_color_blending_mode(s32 target, s32 mode) {
    Tbl_803DCC34 tbl = gx_blend_mode_table;
    if (mode == 0) {
        REG_803DCC34->mode = (REG_803DCC34->mode & 0x03FFFFFF) | 0xB0000000;
    } else if (mode == 0) {
        REG_803DCC34->mode = (REG_803DCC34->mode & 0x03FFFFFF) | 0x94000000;
    } else if (target == 0) {
        REG_803DCC34->mode = (REG_803DCC34->mode & 0x1FFFFFFF) | (tbl.v[mode] << 29);
    } else {
        REG_803DCC34->mode = (REG_803DCC34->mode & 0xE3FFFFFF) | (tbl.v[mode] << 26);
    }
}

void apply_cached_blend_mode(s32 arg0) {
    u32 v = *(u32 *)((s8 *)current_render_context + 0xC);
    int src = cached_blend_factor_table[(v & 0xE0000000) >> 29];
    int dst = cached_blend_factor_table[(v & 0x1C000000) >> 26];
    if (arg0 != 0) {
        GXSetBlendMode(1, src, dst, 0);
    } else {
        GXSetBlendMode(0, src, dst, 0);
    }
}

__declspec(section ".rodata") extern const Tbl_803DCC34 gx_blend_mode_table = {{255, 255, 6, 2, 7, 3, 5, 3, 4, 2, 1, 0}};
__declspec(section ".rodata") extern const u32 cached_blend_factor_table[8] = {0, 1, 2, 3, 4, 5, 6, 7};

extern "C" {
s32 node_saved_matrix[12];
}

