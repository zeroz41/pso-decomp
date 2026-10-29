#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"
#include "pso/render/depth_buffer.h"
#include "pso/player/TUnk_804F2A10.h"
#include "pso/player/TUnk_804F29F8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TItemLoad.h"
#include "pso/player/TObjPlayer_80141D1C.h"

extern "C" {
void* init_vtable_804F2A10__13TUnk_804F2A10Fv(void*);
extern s32 lbl_804F29F8[];
extern s32 lbl_804F2A10[];
extern u8 model_material_color[];
extern u8 * lbl_805D6FB8;
extern int player_item_id_list;
#define reset_id_array__10TObjPlayerFPv ((int (*)(void*))reset_id_array__10TObjPlayerFPv)
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void TUnk_804F29F8::run_task() { reset_id_array__10TObjPlayerFPv((void*)player_item_id_list); }

void *__dt__13TUnk_804F29F8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F29F8;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#undef reset_id_array__10TObjPlayerFPv

#define lbl_804F29F8 ((unsigned char *)lbl_804F29F8)
#define reset_id_array__10TObjPlayerFPv ((int (*)(void*))reset_id_array__10TObjPlayerFPv)
int __ct__7TObjectFP7TObject(void);

void* TObjPlayer__sub_80363C5C(void* a0) { __ct__7TObjectFP7TObject(); *(int*)((char*)a0 + 0x18) = (int)lbl_804F29F8; reset_id_array__10TObjPlayerFPv((void*)player_item_id_list); return a0; }

#undef lbl_804F29F8
#undef reset_id_array__10TObjPlayerFPv

#define TObjPlayer__sub_80363C5C ((void * (*)(void *, void *))TObjPlayer__sub_80363C5C)
void *__nw__7TObjectFUl(int);

void TObjPlayer::create_cleanup_object(void *arg0) {
    void *o;
    o = __nw__7TObjectFUl(0x1C);
    if (o != NULL) {
        TObjPlayer__sub_80363C5C(o, arg0);
    }
}

#undef TObjPlayer__sub_80363C5C

void TObjPlayer::free_static_buffer() {
    if ((u32) (*(u32 *)&player_item_id_list) != 0U) {
        ::operator delete((void *)(*(u32 *)&player_item_id_list));
        (*(u32 *)&player_item_id_list) = 0U;
    }
}

}

struct VBase_18_1419ea { char pad[0x18]; };

struct VObj_18_1419ea : VBase_18_1419ea {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual s32 m26();
};

extern "C" {
extern u8 saved_model_draw_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern u8 *lbl_805D6FB8;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

void TObjPlayer::alloc_and_run_object() {
    void *o;

    o = ::operator new(0xB4);
    if (o != NULL) {
        o = (void *)TObjPlayer::run_and_return_arg((s32)o);
    }
    (*(void **)&player_item_id_list) = o;
}
void TUnk_804F2A10::render() {
    s32 *p;
    s32 n;
    VObj_18_1419ea *obj;
    set_default_alpha_blend();
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
    n = *(s32 *)(lbl_805D6FB8 + 0xB0);
    p = (s32 *)(lbl_805D6FB8 + 0x30);
    while (n != 0) {
        obj = (VObj_18_1419ea *)find_equipped_item(*p++);
        if (obj != NULL) {
            set_depth_buffer_settings_id(1);
            obj->m26();
            set_default_alpha_blend();
            copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
            set_depth_buffer_settings_id(2);
            obj->m26();
            set_default_alpha_blend();
            copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
        n--;
    }
    restore_draw_list_mask();
    *(s32 *)(lbl_805D6FB8 + 0xB0) = 0;
}


void TUnk_804F2A10::run_task() {
    void *spC;
    s32 sp8;

    TItemLoad::get_model_ids((u8)5, (s32 *)&spC, (s32 *)&sp8);
    if (spC != NULL) {
        scroll_item_model_uvs(*(NJS_OBJECT **)((s8 *)spC + 0x2C), 2, 2, 0xB);
    }
}

void *__dt__13TUnk_804F2A10Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F2A10;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define lbl_804F2A10 ((unsigned char *)lbl_804F2A10)
#define reset_id_array__10TObjPlayerFPv ((int (*)(void*))reset_id_array__10TObjPlayerFPv)
void* init_vtable_804F2A10__13TUnk_804F2A10Fv(void* a0);

void*TUnk_804F2A10::init_vtable_804F2A10() { __ct__7TObjectFP7TObject(); *(int*)((char*)this + 0x18) = (int)lbl_804F2A10; reset_id_array__10TObjPlayerFPv((void*)((*(int *)&lbl_805D6FB8))); return this; }

#undef lbl_804F2A10
#undef reset_id_array__10TObjPlayerFPv

#define reset_id_array__10TObjPlayerFPv ((s32 (*)(void *))reset_id_array__10TObjPlayerFPv)
void TObjPlayer::push_id_to_list(s32 arg0) {
    if ((s32) *(s32 *)((s8 *)(*(void **)&lbl_805D6FB8) + 0xB0) == 0) {
        reset_id_array__10TObjPlayerFPv((*(void **)&lbl_805D6FB8));
    }
    ((TObjPlayer *)(*(void **)&lbl_805D6FB8))->push_to_list(arg0);
}

}
#undef reset_id_array__10TObjPlayerFPv

#define init_vtable_804F2A10__13TUnk_804F2A10Fv ((void * (*)(void *, void *))init_vtable_804F2A10__13TUnk_804F2A10Fv)

struct RecoveredGlobal_803640C8_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8036414C_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80364198_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_803640F8_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

struct Rec_80364028 { f32 a; s32 b; s32 c; s32 d; };

extern Rec_80364028 lbl_80479FF8;
extern const f32 lbl_805E0288;
void TObjPlayer::spawn_cleanup_helper(void *arg0) {
    void *o;
    o = __nw__7TObjectFUl(0x1C);
    if (o != NULL) {
        init_vtable_804F2A10__13TUnk_804F2A10Fv(o, arg0);
    }
}

void TObjPlayer::warn_if_gauge_low() {
    if (*(f32 *)((s8 *)(*(void **)&lbl_805D6FB8) + 0x2C) < lbl_805E0288) {
        set_chunk_blend(0x2500);
        TObjPlayer::copy_gauge_warn_vec();
    }
}
typedef char RecoveredGlobal_803640C8_lbl_8058D4C0_size[sizeof(RecoveredGlobal_803640C8_lbl_8058D4C0) == 0x10 ? 1 : -1];

void TObjPlayer::set_model_fade_alpha(f32 farg0) {
    if (farg0 < lbl_805E0288) {
        model_render_flags |= 0x24;
        set_chunk_material_override_pair(-1, 0x800);
        set_chunk_blend(0x2500);
        Rec_80364028 r = lbl_80479FF8;
        r.a = farg0 - lbl_805E0288;
        ((TObjPlayer *)((s32 *)&r))->push_model_fade_color();
    }
    *(f32 *)((u8 *)(*(void **)&lbl_805D6FB8) + 0x2C) = farg0;
}

void TObjPlayer::copy_gauge_warn_vec() {
    copy_argb((NJS_ARGB *)(&(*(RecoveredGlobal_803640C8_lbl_8058D4C0 *)&model_material_color).value), (NJS_ARGB *)((*(s32 *)&(*(void **)&lbl_805D6FB8)) + 0x1C));
}
typedef char RecoveredGlobal_8036414C_lbl_8058D4C0_size[sizeof(RecoveredGlobal_8036414C_lbl_8058D4C0) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_803640F8_lbl_8058D4C0_size[sizeof(RecoveredGlobal_803640F8_lbl_8058D4C0) == 0x10 ? 1 : -1];
void TObjPlayer::push_model_fade_color() {
    copy_argb((NJS_ARGB *)((*(s32 *)&(*(void **)&lbl_805D6FB8)) + 0x1C), (NJS_ARGB *)(&(*(RecoveredGlobal_803640F8_lbl_8058D4C0 *)&(*(RecoveredGlobal_803640C8_lbl_8058D4C0 *)&model_material_color)).value));
    if (this != NULL) {
        copy_argb((NJS_ARGB *)(&(*(RecoveredGlobal_803640F8_lbl_8058D4C0 *)&(*(RecoveredGlobal_803640C8_lbl_8058D4C0 *)&model_material_color)).value), (NJS_ARGB *)this);
    }
}

void TObjPlayer__sub_8036414C(void) {
    model_render_flags = *(s32 *)((s8 *)(*(u8 * *)&(*(void **)&lbl_805D6FB8)) + 0);
    copy_argb((NJS_ARGB *)(&(*(RecoveredGlobal_8036414C_lbl_8058D4C0 *)&(*(RecoveredGlobal_803640C8_lbl_8058D4C0 *)&model_material_color)).value), (NJS_ARGB *)((*(u8 * *)&(*(void **)&lbl_805D6FB8)) + 0xC));
    chunk_polygon_flags_and_mask = *(s32 *)((s8 *)(*(u8 * *)&(*(void **)&lbl_805D6FB8)) + 4);
    chunk_polygon_flags_or_mask = *(s32 *)((s8 *)(*(u8 * *)&(*(void **)&lbl_805D6FB8)) + 8);
}
typedef char RecoveredGlobal_80364198_lbl_8058D4C0_size[sizeof(RecoveredGlobal_80364198_lbl_8058D4C0) == 0x10 ? 1 : -1];
void TObjPlayer__sub_80364198(void) {
    *(s32 *)((s8 *)(*(u8 * *)&(*(void **)&lbl_805D6FB8)) + 0) = (s32) model_render_flags;
    copy_argb((NJS_ARGB *)((*(u8 * *)&(*(void **)&lbl_805D6FB8)) + 0xC), (NJS_ARGB *)(&(*(RecoveredGlobal_80364198_lbl_8058D4C0 *)&(*(RecoveredGlobal_803640C8_lbl_8058D4C0 *)&model_material_color)).value));
    *(s32 *)((s8 *)(*(u8 * *)&(*(void **)&lbl_805D6FB8)) + 4) = (s32) chunk_polygon_flags_and_mask;
    *(s32 *)((s8 *)(*(u8 * *)&(*(void **)&lbl_805D6FB8)) + 8) = (s32) chunk_polygon_flags_or_mask;
}

#undef init_vtable_804F2A10__13TUnk_804F2A10Fv

void TObjPlayer::free_global_805D6FB8() {
    if ((u32) (*(u32 *)&lbl_805D6FB8) != 0U) {
        ::operator delete((void *)(*(u32 *)&lbl_805D6FB8));
        (*(u32 *)&lbl_805D6FB8) = 0U;
    }
}

void TObjPlayer::alloc_and_init_object_b4() {
    void *o;

    o = ::operator new(0xB4);
    if (o != NULL) {
        o = (void *)TObjPlayer::run_and_return_arg((s32)o);
    }
    (*(void **)&lbl_805D6FB8) = o;
}

struct Elt80364258_80364258 { s32 f0; };

void TObjPlayer::push_to_list(s32 arg1) {
    s32 temp_r0;

    temp_r0 = this->motion_flags;
    if (temp_r0 < 0x20) {
        ((struct Elt80364258_80364258 *)(((u8 *)this) + 0x30))[temp_r0].f0 = arg1;
        this->motion_flags = (this->motion_flags + 1);
    }
}

void reset_id_array__10TObjPlayerFPv(void *arg0) {
    s32 *p = (s32 *)((u8 *)arg0 + 0x30);
    int i;
    for (i = 0; i < 32; i++) {
        *p++ = -1;
    }
    *(s32 *)((u8 *)arg0 + 0xB0) = 0;
}

#define reset_id_array__10TObjPlayerFPv ((s32 (*)(void))reset_id_array__10TObjPlayerFPv)

s32 TObjPlayer::run_and_return_arg(s32 arg0) {
    reset_id_array__10TObjPlayerFPv();
    return arg0;
}

#undef reset_id_array__10TObjPlayerFPv
