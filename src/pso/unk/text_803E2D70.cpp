#include "types.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2008.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/player/TObjPlayer.h"

#pragma scheduling off
#pragma scheduling off

struct FloatColor { f32 a, r, g, b; };

struct ByteColor { u8 r, g, b, a; };

typedef s32 (*RecoveredCallback_92513335c3ed)(void *);
typedef void (*RecoveredCallback_2be3cacebb2e)(void);
struct RecoveredGlobal_803DCBD8_lbl_8058D380 {
    s32 value;
    u8 remaining[0xEC];
};

struct Mtx_803DC994 { f32 m[3][4]; };
struct ChunkNode_803E2F78 {
    u32 flags;
    s32 obj;
    f32 pos[3];
    s32 ang[3];
    f32 scl[3];
    ChunkNode_803E2F78 *child;
    ChunkNode_803E2F78 *sibling;
    f32 f34;
};

struct Hdr_803E34B0 { u8 *dst; u8 *src; s32 count; };

typedef struct Vtx_803E2D70 { f32 x, y, w, u, v; u32 color; } Vtx_803E2D70;

typedef union WGPipe_803E2D70 {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe_803E2D70;

typedef struct Vtx_803E36C4 { f32 x, y, z, nx, ny, nz; u32 pad[2]; } Vtx_803E36C4;

typedef union WGPipe_803E36C4 {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe_803E36C4;

typedef struct Vtx_803E46FC { f32 x, y, z, nx, ny, nz; u32 pad[2]; } Vtx_803E46FC;

typedef union WGPipe_803E46FC {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe_803E46FC;

typedef struct Vtx_803E47E0 { f32 x, y, z, nx, ny, nz; u32 pad[2]; } Vtx_803E47E0;

typedef union WGPipe_803E47E0 {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe_803E47E0;

struct Sub_803E3B6C { u8 pad[0xC]; u8 *q; };

struct Rec_803E3B6C { u8 pad[8]; Sub_803E3B6C *p; };

struct Holder_803E3B6C { Rec_803E3B6C *recs; };

typedef struct Vtx_803E352C { f32 x, y, z, nx, ny, nz; u32 pad[2]; } Vtx_803E352C;

typedef union WGPipe_803E352C {
    u8 u8;
    u16 u16;
    s16 s16;
    u32 u32;
    f32 f32;
} WGPipe_803E352C;

typedef f32 Mtx_803E4354[3][4];
extern "C" {
void GXSetNumTexGens(u8);
s32 GXSetTevOp(int, int);
s32 GXSetTevOrder(int, int, int, int);
s32 GXSetNumTevStages(int);
extern s32 model_render_flags;
extern u8 lbl_805D77D8;
extern u8 lbl_805D77D9;
s32 GXSetZMode(int, int, int);
s32 GXSetZCompLoc(int);
extern s32 ginja_draw_flags;
extern s32 (*player_chunk_draw_end_callback)();
extern s32 chunk_texture_record_index;
void GXSetChanMatColor(s32, ByteColor);
void convert_color_f32_to_u8(const FloatColor*,ByteColor*);
void convert_color_u8_to_f32(const ByteColor*,FloatColor*);
extern FloatColor model_material_color;
extern const ByteColor lbl_805E1090;
extern s32 model_render_flags,ginja_draw_flags;
extern u32 chunk_blend_header_bits;
extern u32 chunk_strip_dirty_flags;
void GXSetAlphaCompare(int comp0, int ref0, int op, int comp1, int ref1);
extern s32 chunk_vertex_cache_buffer;
extern s32 lbl_805D77FC;
extern s32 chunk_render_flags;
void transform_chunk_object_tree(void *, void (*)(void *));
extern s32 current_matrix;
s32 __cvt_fp2unsigned(f32);
void apply_quat_rotation__10TObjPlayerFf(f32 *arg0, f32 farg0);
void rotate_matrix_by_node_angles(void *, int);
void push_matrix(void);
void scale_current_matrix(void *);
void post_translate_matrix(void *);
extern u8 chunk_object_current_matrix[];
void transform_point_by_current_matrix(u8 *, u8 *);
void rotate_vector_by_current_matrix(u8 *, u8 *);
void GXBegin(int, int, u16);
extern const f32 lbl_805E1088;
void draw_projected_textured_strip(Vtx_803E2D70 *v, s32 n);
void Dolphin_GXSetVtxDesc(int, int);
void GXClearVtxDesc(void);
void draw_strip_list_pos_nrm__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E36C4 *verts, u32 info);
void GXSetChanCtrl(s32 chan, u8 enable, s32 ambSrc, s32 matSrc, u32 lightMask, s32 diffFn, s32 attnFn);
extern u32 gx_chan_ctrl_light_mask;
extern u32 chunk_has_vertex_colors;
void draw_strip_pos_normal__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E46FC *verts, u32 info);
void draw_triangle_strips__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E47E0 *verts, u32 info);
s32 GXSetBlendMode(int, int, int, int);
extern s32 material_alpha_compare_reference;
extern u8 *current_render_context;
extern u32 lbl_805E1094;
extern const u32 lbl_805E1098;
extern const f32 lbl_805E109C;
extern const f32 lbl_805E10A0;
void GXSetVtxAttrFmt(int, int, int, int, u8);
void draw_chunk_textured_strips(s16 *list, Vtx_803E352C *verts, u32 info, s32 large);
struct ChunkModel_803E44D4 { u32 *vertices; u16 *polygons; };
struct ChunkBuffer_803E44D4 { void *vertices; s32 bytes; };
struct ChunkRecording_803E44D4 { ChunkBuffer_803E44D4 buffers[32]; s32 index; };
void OSReport(const char*, ...);
void* memmove(void*, const void*, unsigned long);
void dispatch_chunk_polygon_list(u16*, s32);
extern const char lbl_804FC810[];
extern u32 lbl_805D77E4;
extern ChunkRecording_803E44D4* chunk_vertex_cache_state;
void PSMTXConcat(const Mtx_803E4354, const Mtx_803E4354, Mtx_803E4354);
void PSMTXTrans(Mtx_803E4354, f32, f32, f32);
void PSMTXScale(Mtx_803E4354, f32, f32, f32);
s32 GXSetNumChans(int);
s32 GXLoadPosMtxImm(void *, int);
s32 GXLoadNrmMtxImm(void *, int);
s32 GXLoadTexMtxImm(void *, int, int);
extern Mtx_803E4354 identity_matrix;
extern s32 chunk_previous_strip_flags;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void GXPosition3f32_803E2D70(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = z;
}
static inline void GXColor1u32_803E2D70(u32 c) {
    (*(volatile WGPipe_803E2D70 *)0xCC008000).u32 = c;
}
static inline void GXTexCoord2f32_803E2D70(f32 s, f32 t) {
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = s;
    (*(volatile WGPipe_803E2D70 *)0xCC008000).f32 = t;
}
void draw_projected_textured_strip(Vtx_803E2D70 *v, s32 n) {
    f32 inv;
    u32 c;
    GXBegin(0x98, 4, n);
    for (; n > 0; n--) {
        inv = lbl_805E1088 / v->w;
        GXPosition3f32_803E2D70(v->x * inv, v->y * inv, inv);
        c = v->color;
        GXColor1u32_803E2D70(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        GXTexCoord2f32_803E2D70(v->u, v->v);
        v++;
    }
}
#pragma pop

void TLobby__sub_803E2EE4(s32 arg0) {
    TObjPlayer::load_screen_space_matrix();
    if (arg0 != 0) {
        setup_blended_textured_draw();
    } else {
        TObjPlayer::setup_render();
    }
    load_context_texture_obj();
}

#pragma push
#pragma peephole off
#pragma scheduling off
typedef char RecoveredGlobal_803DCBD8_lbl_8058D380_size[sizeof(RecoveredGlobal_803DCBD8_lbl_8058D380) == 0xF0 ? 1 : -1];
void TObjPlayer::copy_matrix3x3_for_chunk_tree() {
    struct Mtx_803DC994 *src = (struct Mtx_803DC994 *)this;
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
#pragma pop

#define node ((ChunkNode_803E2F78 *)arg0)
void transform_chunk_object_tree(void *arg0, void (*cb)(void *)) {
    u32 flags;
    s32 r;

    do {
        flags = node->flags;
        r = 0;
        if (flags & 0x800) {
            get_current_matrix(chunk_object_current_matrix);
        }
        if ((flags & 7) == 7) {
            if (!(flags & 8)) {
                r = ((s32 (*)(s32))cb)(node->obj);
            }
            if (!(flags & 0x10) && (!(flags & 0x100) || r == 0)) {
                transform_chunk_object_tree(node->child, cb);
            }
        } else {
            push_matrix();
            if (!(flags & 1)) {
                post_translate_matrix(node->pos);
            }
            if (!(flags & 2)) {
                if (flags & 0x1000) {
                    ((TObjPlayer *)chunk_object_current_matrix)->copy_matrix3x3_for_chunk_tree();
                } else if (flags & 0x400) {
                    ((void (*)(f32, f32 *))apply_quat_rotation__10TObjPlayerFf)(node->f34, (f32 *)node->ang);
                } else {
                    rotate_matrix_by_node_angles(node->ang, flags & 0x20);
                }
            }
            if (!(flags & 4)) {
                scale_current_matrix(node->scl);
            }
            if (!(flags & 8)) {
                r = ((s32 (*)(s32))cb)(node->obj);
            }
            if (!(flags & 0x10) && (!(flags & 0x100) || r == 0)) {
                transform_chunk_object_tree(node->child, cb);
            }
            pop_matrix();
        }
        arg0 = node->sibling;
    } while (arg0 != NULL);
}
#undef node

void TObjPlayer::transform_vertex_list() {
    Hdr_803E34B0 *arg0 = (Hdr_803E34B0 *)this;
    s32 n = arg0->count;
    u8 *src = arg0->src;
    u8 *dst = arg0->dst;
    while (n-- > 0) {
        transform_point_by_current_matrix(src, dst);
        rotate_vector_by_current_matrix(src + 0xC, dst + 0xC);
        f32 t = *(f32 *)(src + 0x18);
        src += 0x1C;
        *(s32 *)(dst + 0x18) = __cvt_fp2unsigned(t);
        dst += 0x20;
    }
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline off
#pragma inline_depth(4)
static inline void GXPosition3f32_803E36C4(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E36C4 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E36C4 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E36C4 *)0xCC008000).f32 = z;
}
static inline void GXNormal3f32_803E36C4(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E36C4 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E36C4 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E36C4 *)0xCC008000).f32 = z;
}

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline off
#pragma inline_depth(4)
static inline void GXPosition3f32_803E352C(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E352C *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E352C *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E352C *)0xCC008000).f32 = z;
}
static inline void GXNormal3f32_803E352C(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E352C *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E352C *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E352C *)0xCC008000).f32 = z;
}
static inline void GXTexCoord2s16_803E352C(s16 s, s16 t) {
    (*(volatile WGPipe_803E352C *)0xCC008000).s16 = s;
    (*(volatile WGPipe_803E352C *)0xCC008000).s16 = t;
}
void draw_chunk_textured_strips(s16 *list, Vtx_803E352C *verts, u32 info, s32 large) {
    s16 s;
    s16 t;
    Vtx_803E352C *v;
    s32 skip;
    s32 n;
    s32 draw;
    u32 count;
    draw = 1;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    if ((u32)chunk_render_flags != 0) {
        if ((u32)chunk_render_flags & 1) {
            if ((u32)chunk_render_flags & 0x200) {
                TObjPlayer::clear_move_state_bits();
                draw = 0;
            }
        } else if ((u32)chunk_render_flags & 2) {
            if ((u32)chunk_render_flags & 0x400) {
                TObjPlayer::clear_move_state_bits();
                draw = 0;
            }
        }
    }
    TObjPlayer::clear_move_state_bits();
    GXSetVtxAttrFmt(0, 0xD, 1, 3, large ? 0xC : 8);
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xA, 1);
    Dolphin_GXSetVtxDesc(0xD, 1);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        if (draw) {
            GXBegin(0x98, 0, n);
        }
        do {
            v = &verts[*list++];
            s = *list++;
            t = *list++;
            if (draw) {
                GXPosition3f32_803E352C(v->x, v->y, v->z);
                GXNormal3f32_803E352C(v->nx, v->ny, v->nz);
                GXTexCoord2s16_803E352C(s, t);
            }
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
#pragma pop

void draw_strip_list_pos_nrm__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E36C4 *verts, u32 info) {
    s32 skip;
    s32 n;
    u32 count;
    Vtx_803E36C4 *v;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xA, 1);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        GXBegin(0x98, 0, n);
        do {
            v = &verts[*list++];
            GXPosition3f32_803E36C4(v->x, v->y, v->z);
            GXNormal3f32_803E36C4(v->nx, v->ny, v->nz);
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
}
s32 dispatch_chunk_vertex_list(u32*, s32);
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void submit_chunk_material_color(u8 type, s16* data) {
    FloatColor add;
    ByteColor color;
    ByteColor fallback=lbl_805E1090;
    ByteColor converted;
    ByteColor convertedAdd;
    if ((u32)((type-0x10)&1)!=0U) {
        s16 gb=data[0],ar=data[1];
        color.a=(ar>>8)&255;
        color.r=(u8)ar;
        color.g=(gb>>8)&255;
        color.b=(u8)gb;
        if ((u32)(model_render_flags&0x10)!=0U) {
            convert_color_f32_to_u8(&model_material_color,&converted);
            GXSetChanMatColor(4,converted);
        } else if ((u32)(model_render_flags&0x20)!=0U) {
            convert_color_u8_to_f32(&color,&add);
            add.a+=model_material_color.a;
            add.r+=model_material_color.r;
            add.g+=model_material_color.g;
            add.b+=model_material_color.b;
            convert_color_f32_to_u8(&add,&convertedAdd);
            GXSetChanMatColor(4,convertedAdd);
        } else GXSetChanMatColor(4,color);
    }
    if ((u32)(ginja_draw_flags&2)!=0U) GXSetChanMatColor(4,fallback);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_chunk_blend(u32 x) {
    chunk_blend_header_bits = x & 0x3F00;
    chunk_strip_dirty_flags |= 8;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma scheduling off
#pragma peephole off
void apply_chunk_texture_command(s32 arg0, s32 arg1) {
    s32 var_r31;
    s32 idx;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    var_r5 = 1;
    var_r6 = 1;
    if ((u32) (arg0 & 0x2000) != 0) {
        var_r6 = 0;
    } else if ((u32) (arg0 & 0x8000) != 0) {
        var_r6 = 2;
    }
    if ((u32) (arg0 & 0x1000) != 0) {
        var_r5 = 0;
    } else if ((u32) (arg0 & 0x4000) != 0) {
        var_r5 = 2;
    }
    var_r31 = arg1 & 0x1FFF;
    idx = var_r31;
    var_r4 = var_r6;
    var_r6 = 0;
    load_list_texture((idx), (var_r4), (var_r5), 0);
    chunk_texture_record_index = var_r31;
}
#pragma pop

void TObjPlayer::setup_tev_passclr() {
    GXSetNumTevStages(1);
    GXSetNumTexGens(0U);
    GXSetTevOp(0, 4);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
}

#pragma push
#pragma peephole off
void setup_chunk_tev_stages(void) {
    if ((u32) (model_render_flags & 0x80000) != 0) {
        GXSetNumTevStages((int)((void *) ((u8)(lbl_805D77D8 + 1))));
        GXSetNumTexGens((u8)((void *) ((u8)(lbl_805D77D9 + 1))));
    } else {
        GXSetNumTevStages((int)((void *) (1U)));
        GXSetNumTexGens((u8)((void *) (1U)));
    }
    GXSetTevOp(0, 0);
    GXSetTevOrder(0, 0, 0, 4);
}
#pragma pop

void set_strip_lighting_chan_ctrl(u32 flags) {
    u8 enable;
    if (chunk_has_vertex_colors != 0) {
        enable = 0;
    } else if (flags & 1) {
        enable = 0;
    } else {
        enable = 1;
    }
    if (chunk_has_vertex_colors != 0) {
        GXSetChanCtrl(0, enable, 0, 1, gx_chan_ctrl_light_mask, 2, 2);
        GXSetChanCtrl(2, 0, 0, 1, gx_chan_ctrl_light_mask, 2, 2);
    } else {
        GXSetChanCtrl(0, enable, 0, 0, gx_chan_ctrl_light_mask, 2, 2);
        GXSetChanCtrl(2, 0, 0, 0, gx_chan_ctrl_light_mask, 2, 2);
    }
}

#pragma push
#pragma scheduling off
s32 set_chunk_alpha_compare_ref(int ref) {
    GXSetAlphaCompare(4, ref, 0, 7, 0);
}
#pragma pop

void set_chunk_blend_depth_mode(s32 arg0, s32 arg1) {
    s32 var_r31;
    s32 temp_r30;
    s32 temp_r29;
    u32 var_r28;
    u8 *temp_r4;
    u32 id;
    u8 *temp_r3;
    u32 var_r6;
    if ((u32) (arg0 & 8) != 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    temp_r30 = (u32) (chunk_blend_header_bits & 0x3800) >> 0xBU;
    temp_r29 = (u32) (chunk_blend_header_bits & 0x700) >> 8U;
    if ((u32) chunk_render_flags != 0) {
        TObjPlayer::clear_move_state_bits();
    }
    if (arg1 == 0) {
        GXSetBlendMode(var_r31, temp_r30, temp_r29, 0);
        GXSetZCompLoc(0);
        GXSetZMode(1, 3, 0);
    } else if (var_r31 != 0) {
        var_r6 = 0;
        var_r28 = 1U;
        temp_r4 = (u8 *)((*(Holder_803E3B6C **)(current_render_context + 0x20))->recs[chunk_texture_record_index].p->q);
        id = model_render_flags;
        if (((u32) (id & 0x10) != 0) && (lbl_805E109C != model_material_color.a)) {
            var_r28 = 0U;
        }
        if (((u32) (id & 0x20) != 0) && (lbl_805E10A0 != model_material_color.a)) {
            var_r28 = 0U;
        }
        if ((u32) *(u32 *)((s8 *)temp_r4 + 4) == 0xEU) {
            if ((u32) (id & 0x400000) != 0) {
                if ((u32) (*(s32 *)((s8 *)temp_r4 + 0x1C) & 0x40000000) != 0) {
                    var_r6 |= lbl_805E1094;
                }
            } else {
                var_r6 |= lbl_805E1094;
            }
        }
        if ((u32) (id & 1) != 0) {
            var_r6 |= lbl_805E1098;
        }
        if ((var_r28 != 0U) && (var_r6 != 0) && (temp_r30 == 4) && (temp_r29 == 5)) {
            if ((u32) chunk_render_flags != 0) {
                chunk_render_flags |= 0x200;
            }
            GXSetBlendMode(var_r31, temp_r30, temp_r29, 0);
            if ((u32) (model_render_flags & 0x200000) != 0) {
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 1);
                set_chunk_alpha_compare_ref(0);
            } else {
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 1);
                set_chunk_alpha_compare_ref((u8) material_alpha_compare_reference);
            }
        } else {
            if ((u32) chunk_render_flags != 0) {
                chunk_render_flags |= 0x200;
            }
            if (((u32) (id & 0x01000000) != 0) && ((u32) (ginja_draw_flags & 2) == 0)) {
                GXSetBlendMode(var_r31, temp_r30, temp_r29, 0);
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 1);
                set_chunk_alpha_compare_ref((u8) material_alpha_compare_reference);
            } else {
                GXSetBlendMode(var_r31, temp_r30, temp_r29, 0);
                GXSetZCompLoc(0);
                if (var_r28 != 0U) {
                    GXSetZMode(1, 3, 0);
                } else {
                    GXSetZMode(1, 3, 1);
                }
                set_chunk_alpha_compare_ref(0);
            }
        }
    } else {
        if ((u32) chunk_render_flags != 0) {
            chunk_render_flags |= 0x400;
        }
        temp_r3 = (u8 *)((*(Holder_803E3B6C **)(current_render_context + 0x20))->recs[chunk_texture_record_index].p->q);
        if (((u32) *(u32 *)((s8 *)temp_r3 + 4) == 0xEU) && ((u32) (*(s32 *)((s8 *)temp_r3 + 0x1C) & 0x40000000) != 0)) {
            set_chunk_alpha_compare_ref(0x1F);
            GXSetBlendMode(0, temp_r30, temp_r29, 0);
            GXSetZCompLoc(0);
            GXSetZMode(1, 3, 1);
        } else {
            GXSetBlendMode(0, temp_r30, temp_r29, 0);
            GXSetZCompLoc(1);
            GXSetZMode(1, 3, 1);
        }
    }
    if ((u32) (model_render_flags & 0x400) != 0) {
        GXSetZMode(1, 3, 0);
    }
}

extern "C" {
void push_reordered_matrix_ps(void);
void transform_chunk_vertices_pos_normal(Hdr_803E34B0 *job, s32 matrix);
void GXSetVtxAttrFmtv(Hdr_803E34B0 *job, s32 matrix, u32 format);
void cache_chunk_vertex_colors(Hdr_803E34B0 *job, s32 matrix);
void transform_vertex_list__10TObjPlayerFv(Hdr_803E34B0 *job, s32 matrix);
}

s32 dispatch_chunk_vertex_list(u32 *list, s32 buffer) {
    u32 info;
    u32 length;
    s32 total;
    u16 type;
    Hdr_803E34B0 job;
    total = 0;
    push_reordered_matrix_ps();
    while ((*list & 0xFF) != 0xFF) {
        type = *list;
        length = (*list & 0xFFFF0000) >> 16;
        info = list[1];
        list += 2;
        job.count = (info & 0xFFFF0000) >> 16;
        job.src = (u8 *)list;
        job.dst = (u8 *)(buffer + (info & 0xFFFF) * 32);
        total += job.count;
        if ((type & 0xFF) == 0x29) {
            transform_chunk_vertices_pos_normal(&job, current_matrix);
        } else if ((type & 0xFF) == 0x2C) {
            GXSetVtxAttrFmtv(&job, current_matrix, ((type & ~0x8000) >> 8) & 0xFF);
        } else if ((type & 0xFF) == 0x2A) {
            transform_vertex_list__10TObjPlayerFv(&job, current_matrix);
        } else if ((type & 0xFF) == 0x23) {
            pop_matrix();
            chunk_has_vertex_colors = 1;
            cache_chunk_vertex_colors(&job, current_matrix);
            push_matrix();
        }
        list += length - 1;
    }
    pop_matrix();
    return total;
}

void TObjPlayer::setup_model_draw_state(void *) {
    Mtx_803E4354 scale;
    Mtx_803E4354 trans;
    Mtx_803E4354 m;
    if ((u32) (ginja_draw_flags & 2) != 0) {
        TObjPlayer::reset_particle_counter();
        apply_scene_fog();
    }
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
    GXSetVtxAttrFmt(0, 0xA, 0, 4, 0);
    GXSetNumChans(1);
    chunk_previous_strip_flags = 0;
    chunk_strip_dirty_flags = -1;
    GXLoadPosMtxImm(identity_matrix, 0);
    GXLoadNrmMtxImm(identity_matrix, 0);
    if ((u32) (model_render_flags & 0x100000) != 0) {
        PSMTXScale(scale, -0.5f, -0.5f, 0.0f);
        PSMTXTrans(trans, 0.5f, 0.5f, 1.0f);
        PSMTXConcat(scale, identity_matrix, m);
        PSMTXConcat(trans, m, m);
        GXLoadTexMtxImm(m, 0x2A, 0);
    }
    push_matrix();
    GXSetZCompLoc(0);
}

#pragma push
#pragma peephole off
void TObjPlayer::end_chunk_draw() {
    if ((u32) (ginja_draw_flags & 2) != 0) {
        TObjPlayer::set_effect_active();
        apply_scene_fog();
    }
    pop_matrix();
    GXSetZCompLoc(1);
    GXSetZMode(1, 1, 1);
    set_chunk_alpha_compare_ref(0);
    if (((s32 (*)()) player_chunk_draw_end_callback) != NULL) {
        player_chunk_draw_end_callback();
    }
}
#pragma pop

s32 draw_chunk_vertices_cached__10TObjPlayerFPv(void* arg) {
    ChunkModel_803E44D4* model = (ChunkModel_803E44D4*)arg;
    s32 cache;
    s32 count = 0;
    if ((u32)chunk_render_flags & 4) return 0;
    chunk_has_vertex_colors = 0;
    cache = chunk_vertex_cache_buffer;
    if (lbl_805D77E4 & 4) {
        if (chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes != 0) {
            memmove((void*)chunk_vertex_cache_buffer, chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices, chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes);
        }
        chunk_vertex_cache_state->index++;
    } else if (model->vertices != 0) {
        count = dispatch_chunk_vertex_list(model->vertices, chunk_vertex_cache_buffer);
    }
    if (lbl_805D77E4 & 1) {
        if (chunk_vertex_cache_state) {
            if (chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices == 0) {
                if (count) {
                    chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices = xmalloc(count << 5);
                    chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].bytes = count << 5;
                }
            } else {
                OSReport(lbl_804FC810);
            }
            chunk_vertex_cache_state->index++;
        }
    } else {
        if (lbl_805D77E4 & 2) {
            if (count) memmove(chunk_vertex_cache_state->buffers[chunk_vertex_cache_state->index].vertices, (void*)chunk_vertex_cache_buffer, count << 5);
            chunk_vertex_cache_state->index++;
        }
        if (model->polygons) dispatch_chunk_polygon_list(model->polygons, cache);
        return 0;
    }
}

void draw_chunk_model(void *arg0) {
    TObjPlayer::setup_model_draw_state(arg0);
    draw_chunk_vertices_cached__10TObjPlayerFPv(arg0);
    TObjPlayer::end_chunk_draw();
}

#pragma push
#pragma scheduling off
extern "C" {
void draw_chunk_object(void *child) {
    TObjPlayer::setup_model_draw_state(child);
    transform_chunk_object_tree(child, (void (*)(void *))draw_chunk_vertices_cached__10TObjPlayerFPv);
    TObjPlayer::end_chunk_draw();
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline off
#pragma inline_depth(4)
static inline void GXPosition3f32_803E46FC(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E46FC *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E46FC *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E46FC *)0xCC008000).f32 = z;
}
static inline void GXNormal3f32_803E46FC(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E46FC *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E46FC *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E46FC *)0xCC008000).f32 = z;
}
void draw_strip_pos_normal__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E46FC *verts, u32 info) {
    s32 skip;
    s32 n;
    u32 count;
    Vtx_803E46FC *v;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xA, 1);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        GXBegin(0x98, 0, n);
        do {
            v = &verts[*list++];
            GXPosition3f32_803E46FC(v->x, v->y, v->z);
            GXNormal3f32_803E46FC(v->nx, v->ny, v->nz);
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma optimization_level 4
static inline void GXPosition3f32_803E47E0(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E47E0 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E47E0 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E47E0 *)0xCC008000).f32 = z;
}
static inline void GXNormal3f32_803E47E0(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E47E0 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E47E0 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E47E0 *)0xCC008000).f32 = z;
}
void draw_triangle_strips__10TObjPlayerFPvPvUi(s16 *list, Vtx_803E47E0 *verts, u32 info) {
    s32 skip;
    s32 n;
    s32 draw;
    u32 count;
    Vtx_803E47E0 *v;
    draw = 1;
    skip = (info >> 14) & 3;
    count = info & 0x3FFF;
    if ((u32)chunk_render_flags != 0) {
        if ((u32)chunk_render_flags & 1) {
            if ((u32)chunk_render_flags & 0x200) {
                TObjPlayer::clear_move_state_bits();
                draw = 0;
            }
        } else if ((u32)chunk_render_flags & 2) {
            if ((u32)chunk_render_flags & 0x400) {
                TObjPlayer::clear_move_state_bits();
                draw = 0;
            }
        }
    }
    TObjPlayer::clear_move_state_bits();
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, 1);
    Dolphin_GXSetVtxDesc(0xA, 1);
    do {
        n = *list++;
        if (n < 0) {
            n = -n;
        }
        if (draw) {
            GXBegin(0x98, 0, n);
        }
        do {
            v = &verts[*list++];
            if (draw) {
                GXPosition3f32_803E47E0(v[2].x, v[2].y, v[2].z);
                GXNormal3f32_803E47E0(v[2].nx, v[2].ny, v[2].nz);
            }
            list += skip;
        } while (--n != 0);
    } while (--count != 0);
}
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer__sub_803E492C(s32 a, s32 b) {
    chunk_vertex_cache_buffer = a;
    lbl_805D77FC = b;
    chunk_render_flags = 0;
}
#pragma pop

}

void set_chunk_render_flags(u32 flags) {
    chunk_render_flags = flags;
}

void clear_chunk_render_flags() {
    chunk_render_flags = 0;
}

extern "C" {
u8 chunk_object_current_matrix[0x30];
}
