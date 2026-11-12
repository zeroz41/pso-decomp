#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/unk/text_80365348.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct VBase_18_1a504b { char pad[0x18]; };

struct VObj_18_1a504b : VBase_18_1a504b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(s32);
};

struct ByteBlock_3C { u8 bytes[0x3C]; };

struct VBase_80365040 { char pad[0x18]; };
struct TObjLaboDesignBase : VBase_80365040 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
    u8 pad1C[0xB0 - 0x1C];
    s32 state;
    f32 xB4;
    f32 xB8;
    void render();
    void render(void *);
};

struct RecoveredGlobal_80365210___vt__18TObjLaboDesignBase {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
s16 TObjLaboDesignBase__vt8(u8 *arg0, f32 farg0, f32 farg1);
f32 xz_distance_squared(void *, s32);
s16 update_object_view_visibility__8TObjBaseFff(void *, f32, f32);
extern s32 camera_ctrl_instance;
f32 rotate_matrix_by_node_angles(void *, void *);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
void draw_node_tree__18TObjLaboDesignBaseFiPv(s32 arg0, u8 *arg1);
s32 init_collision_body_parts(void *, int, int);
s32 __ct__14TObjCollidableFP7TObject();
s32 create__10TObjMapCsnFl(void *, f32, f32);
u8 *TObjLaboDesignBase__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void *TObjLaboDesignBase__create(void *arg0);
void *TObjLaboDesignBase__sub_80364D38(void *arg0);
void *__dt__18TObjLaboDesignBaseFv(void *arg0, s16 arg1);
void *alloc_and_construct__18TObjLaboDesignBaseFPv(void *arg0);
void *create_instance__18TObjLaboDesignBaseFPv(void *arg0);
void render__18TObjLaboDesignBaseFPv(u8 *arg0);
void run_task__18TObjLaboDesignBaseFv(void);
void free_collision_body_parts(void *);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
s32 rotate_matrix_y(int, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void queue_destruction__7TObjectFv(void *);
s32 set_global_param__8TObjFishFl();


extern "C" const char lbl_8047A0A8[];
extern "C" const char lbl_8047A0C4[];
extern "C" const char lbl_8047A0DC[];
extern "C" const char lbl_8047A0F8[];
extern "C" const char lbl_8047A110[];
extern "C" const char lbl_8047A124[];
extern "C" const char lbl_8047A134[];
extern "C" const char lbl_8047A150[];
extern "C" const char lbl_8047A16C[];
extern "C" const char lbl_8047A188[];
extern "C" const char lbl_8047A1A4[];
extern "C" const char lbl_8047A1B8[];
extern "C" const char *lbl_805D4488[];
extern "C" const char *lbl_805D448C[];
extern "C" const char *lbl_805D4490[];
extern "C" const char *lbl_805D4494[];
extern "C" const char *lbl_805D4498[];
extern "C" const char *lbl_805D449C[];
extern const char *lbl_804F2B78[2];
extern BmlResourceDescriptor lbl_804F2B80;
extern const char *lbl_804F2B90[2];
extern BmlResourceDescriptor lbl_804F2B98;
extern const char *lbl_804F2BA8[2];
extern BmlResourceDescriptor lbl_804F2BB0;
extern const char *lbl_804F2BC0[2];
extern BmlResourceDescriptor lbl_804F2BC8;
extern const char *lbl_804F2BD8[2];
extern BmlResourceDescriptor lbl_804F2BE0;
extern const char *lbl_804F2BF0[2];
extern BmlResourceDescriptor lbl_804F2BF8;
__declspec(section ".data") const char *lbl_804F2B78[2] = {
    lbl_8047A0A8, NULL,
};
BmlResourceDescriptor lbl_804F2B80 = {
    lbl_8047A0C4, lbl_804F2B78, lbl_805D4488, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2B90[2] = {
    lbl_8047A0DC, NULL,
};
BmlResourceDescriptor lbl_804F2B98 = {
    lbl_8047A0F8, lbl_804F2B90, lbl_805D448C, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2BA8[2] = {
    lbl_8047A110, NULL,
};
BmlResourceDescriptor lbl_804F2BB0 = {
    lbl_8047A124, lbl_804F2BA8, lbl_805D4490, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2BC0[2] = {
    lbl_8047A134, NULL,
};
BmlResourceDescriptor lbl_804F2BC8 = {
    lbl_8047A150, lbl_804F2BC0, lbl_805D4494, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2BD8[2] = {
    lbl_8047A16C, NULL,
};
BmlResourceDescriptor lbl_804F2BE0 = {
    lbl_8047A188, lbl_804F2BD8, lbl_805D4498, 1, 0,
};
__declspec(section ".data") const char *lbl_804F2BF0[2] = {
    lbl_8047A1A4, NULL,
};
BmlResourceDescriptor lbl_804F2BF8 = {
    lbl_8047A1B8, lbl_804F2BF0, lbl_805D449C, 1, 0,
};
// Archive descriptors of the six laboratory design objects, by object id.
struct LaboDesignObjectEntry {
    s32 id;
    BmlResourceDescriptor *descriptor;
};

LaboDesignObjectEntry lbl_804F2C08[7] = {
    {0, &lbl_804F2B80},
    {1, &lbl_804F2B98},
    {2, &lbl_804F2BB0},
    {3, &lbl_804F2BC8},
    {4, &lbl_804F2BE0},
    {5, &lbl_804F2BF8},
    {-1, NULL},
};
void *labo_design_entry_table[66] = {
    (void *)0x0, (void *)0x41a00000, (void *)0x0, (void *)0x40a00000,
    (void *)0x41200000, (void *)0x1, (void *)0x10003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41a00000, (void *)0x0, (void *)0x40a00000, (void *)0x41200000,
    (void *)0x1, (void *)0x10003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41a00000,
    (void *)0x0, (void *)0x40a00000, (void *)0x41200000, (void *)0x1,
    (void *)0x10003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41a00000, (void *)0x0,
    (void *)0x40a00000, (void *)0x41a00000, (void *)0x1, (void *)0x10003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41a00000, (void *)0x0, (void *)0x40a00000,
    (void *)0x41a00000, (void *)0x1, (void *)0x10003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41a00000, (void *)0x0, (void *)0x41200000, (void *)0x42200000,
    (void *)0x1, (void *)0x10003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
#define labo_design_entry_table ((unsigned char *)labo_design_entry_table)

void *create_instance__18TObjLaboDesignBaseFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC0);
    if (o != NULL) {
        o = TObjLaboDesignBase__ct((u8 *)o, (s32)tl_05, (s32)arg0, 5);
    }
    return o;
}
}
void* get_labo_design_entry(int a0);
extern "C" u32 labo_design_object_table[];

int get_labo_design_object(int a0);
extern s32 __vt__18TObjLaboDesignBase[];
extern s32 TObjLaboDesignBase_class_name;
void *create_labo_design_base(void *arg0);
void *create_obj_labo_design_base(void *arg0);
void *create_obj_labo_design_base(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC0);
    if (o != NULL) {
        o = TObjLaboDesignBase__ct((u8 *)o, (s32)tl_05, (s32)arg0, 4);
    }
    return o;
}

void *TObjLaboDesignBase__sub_80364D38(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC0);
    if (o != NULL) {
        o = TObjLaboDesignBase__ct((u8 *)o, (s32)tl_05, (s32)arg0, 3);
    }
    return o;
}

void *create_labo_design_base(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC0);
    if (o != NULL) {
        o = TObjLaboDesignBase__ct((u8 *)o, (s32)tl_05, (s32)arg0, 2);
    }
    return o;
}

void *alloc_and_construct__18TObjLaboDesignBaseFPv(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC0);
    if (o != NULL) {
        o = TObjLaboDesignBase__ct((u8 *)o, (s32)tl_05, (s32)arg0, 1);
    }
    return o;
}

void *TObjLaboDesignBase__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC0);
    if (o != NULL) {
        o = TObjLaboDesignBase__ct((u8 *)o, (s32)tl_05, (s32)arg0, 0);
    }
    return o;
}

s16 TObjLaboDesignBase__vt8(u8 *arg0, f32 farg0, f32 farg1) {
    if (TMainTask::get_render_pass() == 1) {
        return *(s16 *)((s8 *)arg0 + 0x1E);
    }
    if (xz_distance_squared(arg0 + 0x38, camera_ctrl_instance + 0x178) < (farg1 * farg1)) {
        *(s16 *)((s8 *)arg0 + 0x1E) = 1;
        return *(s16 *)((s8 *)arg0 + 0x1E);
    }
    return update_object_view_visibility__8TObjBaseFff(arg0, farg0, farg1);
}

void draw_node_tree__18TObjLaboDesignBaseFiPv(s32 arg0, u8 *arg1) {
    s32 temp_r31;
    u8 *temp_r4;
    u8 *var_r30;
    var_r30 = arg1;
    do {
        temp_r31 = *(s32 *)((s8 *)var_r30 + 0);
        if (temp_r31 & 0x100000) {
            TParticleCtrl::begin_effect_render();
        } else {
            TParticleCtrl::end_effect_render();
        }
        push_matrix();
        if (!(temp_r31 & 1)) {
            post_translate_matrix(var_r30 + 8);
        }
        if (!(temp_r31 & 2)) {
            rotate_matrix_by_node_angles(var_r30 + 0x14, (void *) (temp_r31 & 0x20));
        }
        if (!(temp_r31 & 4)) {
            scale_current_matrix(var_r30 + 0x20);
        }
        if (!(temp_r31 & 8)) {
            draw_ginja_model((*(s32 *)((s8 *)var_r30 + 4)));
        }
        if (!(temp_r31 & 0x10)) {
            temp_r4 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x2C));
            if (temp_r4 != NULL) {
                draw_node_tree__18TObjLaboDesignBaseFiPv(arg0, temp_r4);
            }
        }
        pop_matrix();
        var_r30 = (u8 *)(*(u8 **)((s8 *)var_r30 + 0x30));
    } while (var_r30 != NULL);
}

void render__18TObjLaboDesignBaseFPv(u8 *arg0) {
    TObjFish__sub_8001EDB0((int) (*(s32 *)((s8 *)arg0 + 0xAC)), 0);
    set_global_param__8TObjFishFl();
    push_matrix();
    post_translate_matrix(arg0 + 0x38);
    rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x60)));
    draw_node_tree__18TObjLaboDesignBaseFiPv((s32)arg0, (u8 *)((int) (get_bml_model((int) (*(s32 *)((s8 *)arg0 + 0xAC)), 0))));
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

typedef void (TObjLaboDesignBase::*Action_80365040)();
typedef void (TObjLaboDesignBase::*RenderPv_80365040)(void *);

void TObjLaboDesignBase::render() {
    static Action_80365040 tbl[8] = {
        (Action_80365040)(RenderPv_80365040)&TObjLaboDesignBase::render,
        (Action_80365040)(RenderPv_80365040)&TObjLaboDesignBase::render,
        (Action_80365040)(RenderPv_80365040)&TObjLaboDesignBase::render,
        (Action_80365040)(RenderPv_80365040)&TObjLaboDesignBase::render,
        (Action_80365040)(RenderPv_80365040)&TObjLaboDesignBase::render,
        (Action_80365040)(RenderPv_80365040)&TObjLaboDesignBase::render,
        (Action_80365040)(RenderPv_80365040)&TObjLaboDesignBase::render,
        (Action_80365040)(RenderPv_80365040)&TObjLaboDesignBase::render,
    };
    if (m8(xB4, xB8) == 1) {
        (this->*(tbl[state]))();
    }
}

void run_task__18TObjLaboDesignBaseFv(void) {  }

void *__dt__18TObjLaboDesignBaseFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjLaboDesignBase;
        if (*(void **)((s8 *)arg0 + 0xBC) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xBC)); *(s32 *)((s8 *)arg0 + 0xBC) = 0; }
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_80365210___vt__18TObjLaboDesignBase_size[sizeof(RecoveredGlobal_80365210___vt__18TObjLaboDesignBase) == 0x38 ? 1 : -1];
u8 *TObjLaboDesignBase__ct(u8 *player, s32 arg1, s32 arg2, s32 arg3) {
    struct CopyStack_80365210 { u8 bytes[0x3C]; };
    CopyStack_80365210 copy_storage_80365210;
    s32 temp_r0;
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_80365210___vt__18TObjLaboDesignBase *)&__vt__18TObjLaboDesignBase).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjLaboDesignBase_class_name;
    ((VObj_18_1a504b *)(player))->m5(arg2);
    *(s32 *)((s8 *)player + 0xB0) = arg3;
    *(s32 *)((s8 *)player + 0xAC) = ((s32)get_labo_design_object((int) (*(s32 *)((s8 *)player + 0xB0))));
    init_collision_body_parts(player, (int) (((s32)get_labo_design_entry((int) (*(s32 *)((s8 *)player + 0xB0))))), 1);
    ((TObjPlayer *)player)->register_object_by_id();
    *(f32 *)((s8 *)player + 0xB4) = 400.0f;
    *(f32 *)((s8 *)player + 0xB8) = 50.0f;
    *(s32 *)((s8 *)player + 0xBC) = 0;
    temp_r0 = *(s32 *)((s8 *)player + 0xB0);
    if ((temp_r0 == 3) || (temp_r0 == 4)) {
        *(ByteBlock_3C *)(copy_storage_80365210.bytes) = *(const ByteBlock_3C *)((arg2 - 4) + 4);
        (*(f32 *)(copy_storage_80365210.bytes + 0x24)) = 40.0f;
        (*(f32 *)(copy_storage_80365210.bytes + 0x28)) = 20.0f;
        (*(f32 *)(copy_storage_80365210.bytes + 0x2C)) = 10.0f;
        *(s32 *)((s8 *)player + 0xBC) = create__10TObjMapCsnFl((void *) ((copy_storage_80365210.bytes)), 20.0f, 40.0f);
    }
    return player;
}

void* get_labo_design_entry(int a0) {  return (char*)labo_design_entry_table + a0 * 44; }

extern "C" u32 labo_design_object_table[];

int get_labo_design_object(int a0) {  return labo_design_object_table[a0]; }

void free_object_table(void) {
    s32 i;
    for (i = 5; i >= 0; i--) {
        if (labo_design_object_table[i] != 0) {
            free_bin_model_request((void *)labo_design_object_table[i], 1);
            labo_design_object_table[i] = 0;
        }
    }
}

void load_labo_design_object_table(void) {
    s32 i;
    LaboDesignObjectEntry *e;
    void *p;
    for (i = 0; i < 6; i++) {
        labo_design_object_table[i] = 0;
    }
    e = lbl_804F2C08;
    if (e != NULL) {
        while (e->id != -1) {
            p = ::operator new(0x440);
            if (p != NULL) {
                p = load_resource_from_descriptor(p, 5, e->descriptor, 0, 0, 0);
            }
            labo_design_object_table[e->id] = (u32)p;
            e++;
        }
    }
}
