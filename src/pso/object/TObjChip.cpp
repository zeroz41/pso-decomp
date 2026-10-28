#include "pso/system/ChunkMaterialState.h"
#include "pso/TObject.h"
#include "pso/object/TObjCamera_8017F80C.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/vector.h"
class TObjChip : public TObject {
public:
    virtual void render_shadows();
    virtual ~TObjChip();
};

#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Base_801809C4_801809B4 { char pad[0x18]; };
struct VObj_801809C4_801809B4 : Base_801809C4_801809B4 {
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
};

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
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
    virtual s32 m10();
    virtual s32 m11();
};
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct VBase_18_6eb662 { char pad[0x18]; };

struct VObj_18_6eb662 : VBase_18_6eb662 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5(void *, f32);
};

struct RecoveredGlobal_80180AA4___vt__8TObjChip {
    s32 value;
    u8 remaining[0x34];
};

struct VBase_18_2a3247 { char pad[0x18]; };

struct VObj_18_2a3247 : VBase_18_2a3247 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(f32);
};

struct RecoveredGlobal_80180BD4___vt__8TObjChip {
    s32 value;
    u8 remaining[0x34];
};

struct Vec_8018085C { f32 x, y, z; };

struct Out_8018085C { f32 x, y; };

struct Vec_801803C0 { f32 x, y, z; };

struct IVec_801803C0 { s32 x, y, z; };

struct Chip_801803C0 {
    Vec_801803C0 pos;
    Vec_801803C0 vel;
    IVec_801803C0 rot;
    IVec_801803C0 angvel;
    f32 alpha;
    s32 life;
};

struct Task_801803C0 {
    u8 pad0[0x30];
    Vec_801803C0 origin;
    Vec_801803C0 vel;
    IVec_801803C0 angvel;
    s32 count;
    s32 life;
    u8 pad5c[0x70 - 0x5C];
    Chip_801803C0 chips[8];
};

struct Vec_80180614 { f32 x, y, z; };

struct IVec_80180614 { s32 x, y, z; };

struct Chip_80180614 {
    Vec_80180614 pos;
    Vec_80180614 vel;
    IVec_80180614 rot;
    IVec_80180614 angvel;
    f32 alpha;
    s32 life;
};

struct Task_80180614 {
    u8 pad0[0x30];
    Vec_80180614 origin;
    Vec_80180614 vel;
    IVec_80180614 angvel;
    s32 count;
    s32 life;
    u8 pad5c[0x70 - 0x5C];
    Chip_80180614 chips[8];
};

struct Vec_8018019C { f32 x, y, z; };

struct IVec_8018019C { s32 x, y, z; };

struct Chip_8018019C {
    Vec_8018019C pos;
    Vec_8018019C vel;
    IVec_8018019C rot;
    IVec_8018019C angvel;
    f32 alpha;
    s32 life;
};

struct Task_8018019C {
    u8 pad0[0x24];
    f32 bounce;
    f32 drag;
    f32 gravity;
    u8 pad30[0x54 - 0x30];
    s32 count;
    u8 pad58[0x5C - 0x58];
    f32 floor;
    u8 pad60[0x6C - 0x60];
    u32 flags;
    Chip_8018019C chips[8];
    s32 active;
};

struct Color_8017FE58 { f32 a; s32 b; s32 c; s32 d; };

struct Chip_8017FE58 {
    f32 pos[3];
    u8 padC[0x18 - 0xC];
    s32 rx, ry, rz;
    u8 pad24[0x30 - 0x24];
    f32 alpha;
    u8 pad34[0x38 - 0x34];
};

struct Obj_8017FE58 {
    u8 pad0[0x54];
    s32 count;
    u8 pad58[0x60 - 0x58];
    f32 scale;
    s32 model;
    u8 pad68[0x6C - 0x68];
    s32 flags;
    Chip_8017FE58 chips[1];
};

extern "C" {
void render__8TObjChipFPv(u8 *arg0);
void copy_debris_params__8TObjChipFPvPv(u8 *arg0, u8 *arg1);
void __ct__7TObjectFP7TObject(void *, void *);
extern void *__vt__8TObjChip[];
u8 *__ct__8TObjChipFv(u8 *arg0, u8 *arg1, u8 *arg2);
u8 *construct_debris__8TObjChipFPvPvPv(u8 *arg0, u8 *arg1, u8 *arg2);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);
void matrix_mult_vec(int, Vec_8018085C *, Vec_8018085C *);
void project_world_to_screen(int, Vec_8018085C *, Out_8018085C *, Vec_8018085C *);
extern Vec_8018085C camera_right;
s32 TObjChip__vt8(s32 arg0, Vec_8018085C *arg1, f32 farg0, f32 farg1);
int rand(void);
s32 spawn_chips__8TObjChipFPvPv(u8 *arg0, u8 *arg1);
s32 init_chips__8TObjChipFPv(u8 *arg0);
void tick_chips__8TObjChipFPv(u8 *arg0);
}
void rotate_matrix_yxz(s32 matrix, s32 arg1, s32 arg2, s32 arg3);
extern "C" {
s32 scale_matrix(int, f32, f32, f32);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void draw_chips__8TObjChipFPv(Obj_8017FE58 *o);
struct Base_801809F0_801809B4 { char pad[0x18]; };
struct VObj_801809F0_801809B4 : Base_801809F0_801809B4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual int m6(); virtual void m7();
};

int TObjChip__vt6(void* p);
u8 *copy_transform__8TObjChipFPvPv(u8 *arg0, u8 *arg1);
void dispatch_vt9__8TObjChipFPv(void *arg0);
void update__8TObjChipFPv(void *arg0);
void queue_destruction__7TObjectFv(void *arg0);

#pragma readonly_strings on
const char *obj_chip_class_name_ptr = "TObjChip";

void draw_chips__8TObjChipFPv(Obj_8017FE58 *o) {
    Chip_8017FE58 *c = o->chips;
    if (o->flags & 8) {
        if (o->flags & 4) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            model_render_flags = model_render_flags | 0x810;
            set_chunk_material_override_pair(-1, 0x800);
            for (s32 i = 0; i < o->count; i++, c++) {
                Color_8017FE58 col = { 0.0f, 0x3F800000, 0x3F800000, 0x3F800000 };
                col.a = c->alpha;
                set_constant_material((const NJS_ARGB *)(((f32 *)&col)));
                push_matrix();
                post_translate_matrix(c);
                rotate_matrix_yxz(0, c->rx, c->ry, c->rz);
                scale_matrix(0, o->scale, o->scale, o->scale);
                draw_chunk_object((void *)o->model);
                pop_matrix();
                set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            }
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        } else {
            for (s32 i = 0; i < o->count; i++, c++) {
                push_matrix();
                post_translate_matrix(c);
                rotate_matrix_yxz(0, c->rx, c->ry, c->rz);
                scale_matrix(0, o->scale, o->scale, o->scale);
                draw_chunk_object((void *)o->model);
                pop_matrix();
            }
        }
    } else if (o->flags & 4) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags = model_render_flags | 0x810;
        set_chunk_material_override_pair(-1, 0x800);
        for (s32 i = 0; i < o->count; i++, c++) {
            Color_8017FE58 col = { 0.0f, 0x3F800000, 0x3F800000, 0x3F800000 };
            col.a = c->alpha;
            set_constant_material((const NJS_ARGB *)(((f32 *)&col)));
            push_matrix();
            post_translate_matrix(c);
            rotate_matrix_yxz(0, c->rx, c->ry, c->rz);
            scale_matrix(0, o->scale, o->scale, o->scale);
            draw_chunk_object((void *)o->model);
            pop_matrix();
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        }
        model_render_flags = saved_model_render_flags;
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    } else {
        for (s32 i = 0; i < o->count; i++, c++) {
            push_matrix();
            post_translate_matrix(c);
            rotate_matrix_yxz(0, c->rx, c->ry, c->rz);
            scale_matrix(0, o->scale, o->scale, o->scale);
            draw_chunk_object((void *)o->model);
            pop_matrix();
        }
    }
}

extern const u32 chip_color_white_c[4] = { 0, 0x3F800000, 0x3F800000, 0x3F800000 };

void render__8TObjChipFPv(u8 *arg0) {
    TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x68)));
    if (*(s32 *)((s8 *)arg0 + 0x6C) & 0x10) {
        ((VObj_18 *)(arg0))->m10();
        return;
    }
    ((VObj_18 *)(arg0))->m11();
}

#pragma push
#pragma fp_contract on
void tick_chips__8TObjChipFPv(u8 *arg0) {
    Task_8018019C *t = (Task_8018019C *)arg0;
    s32 active;
    Chip_8018019C *c;
    s32 i;
    c = t->chips;
    active = 0;
    for (i = 0; i < t->count; i++, c++) {
        if (c->life == 0) {
            if (!(t->flags & 4)) {
                continue;
            }
            c->alpha -= (0.1f);
            if (c->alpha > (0.0f)) {
                active++;
            }
        } else {
            c->life--;
            active++;
        }
        c->vel.x = -c->vel.x * t->drag + c->vel.x;
        c->vel.y = c->vel.y + ((0.1f) * -c->vel.y - t->gravity);
        c->vel.z = -c->vel.z * t->drag + c->vel.z;
        c->pos.x += c->vel.x;
        c->pos.y += c->vel.y;
        c->pos.z += c->vel.z;
        c->rot.x += c->angvel.x;
        c->rot.y += c->angvel.y;
        c->rot.z += c->angvel.z;
        if ((t->flags & 2) && c->pos.y < t->floor && c->vel.y < (0.0f)) {
            c->pos.y = t->floor;
            c->vel.x *= (0.9f);
            c->vel.y *= -t->bounce;
            c->vel.z *= (0.9f);
            c->angvel.x = (s32)((0.5f) * (f32)c->angvel.x);
            c->angvel.y = (s32)((0.5f) * (f32)c->angvel.y);
            c->angvel.z = (s32)((0.5f) * (f32)c->angvel.z);
        }
    }
    if (active == 0) {
        t->active = 0;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 spawn_chips__8TObjChipFPvPv(u8 *arg0, u8 *arg1) {
    IVec_801803C0 *r = (IVec_801803C0 *)arg1;
    Task_801803C0 *t = (Task_801803C0 *)arg0;
    Chip_801803C0 *c;
    s32 i;
    f32 v;
    if (t->count > 8) {
        return 0;
    }
    c = t->chips;
    for (i = 0; i < t->count; i++, c++) {
        VecCopy((Vec *)&c->pos, (const Vec *)&t->origin);
        v = t->vel.x;
        c->vel.x = v * ((3.0517578e-05f) * (f32)rand()) - (0.5f) * v;
        c->vel.y = t->vel.y * ((3.0517578e-05f) * (f32)rand());
        v = t->vel.z;
        c->vel.z = v * ((3.0517578e-05f) * (f32)rand()) - (0.5f) * v;
        c->rot.x = r->x;
        c->rot.y = r->y;
        c->rot.z = r->z;
        c->angvel.x = (s32)((f32)t->angvel.x * ((3.0517578e-05f) * (f32)rand()));
        c->angvel.y = (s32)((f32)t->angvel.y * ((3.0517578e-05f) * (f32)rand()));
        c->angvel.z = (s32)((f32)t->angvel.z * ((3.0517578e-05f) * (f32)rand()));
        c->alpha = (1.0f);
        c->life = t->life;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 init_chips__8TObjChipFPv(u8 *arg0) {
    Task_80180614 *t = (Task_80180614 *)arg0;
    Chip_80180614 *c;
    s32 i;
    f32 v;
    if (t->count > 8) {
        return 0;
    }
    c = t->chips;
    for (i = 0; i < t->count; i++, c++) {
        VecCopy((Vec *)&c->pos, (const Vec *)&t->origin);
        v = t->vel.x;
        c->vel.x = v * ((3.0517578e-05f) * (f32)rand()) - (0.5f) * v;
        c->vel.y = t->vel.y * ((3.0517578e-05f) * (f32)rand());
        v = t->vel.z;
        c->vel.z = v * ((3.0517578e-05f) * (f32)rand()) - (0.5f) * v;
        c->rot.z = c->rot.y = c->rot.x = 0;
        c->angvel.x = (s32)((f32)t->angvel.x * ((3.0517578e-05f) * (f32)rand()));
        c->angvel.y = (s32)((f32)t->angvel.y * ((3.0517578e-05f) * (f32)rand()));
        c->angvel.z = (s32)((f32)t->angvel.z * ((3.0517578e-05f) * (f32)rand()));
        c->alpha = (1.0f);
        c->life = t->life;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjChip__vt8(s32 arg0, Vec_8018085C *arg1, f32 farg0, f32 farg1) {
    Vec_8018085C v;
    Out_8018085C o1;
    Out_8018085C o2;
    matrix_mult_vec(0, arg1, &v);
    if (v.z > 0.0f) {
        return 0;
    }
    if (v.z < -farg0) {
        return 0;
    }
    if (v.x < 0.0f) {
        v.x = arg1->x - camera_right.x * farg1;
        v.y = arg1->y + camera_right.y * farg1;
        v.z = arg1->z + camera_right.z * farg1;
        project_world_to_screen(0, &v, &o1, &camera_right);
        if (o1.x < 0.0f) {
            return 0;
        }
    } else {
        v.x = arg1->x + camera_right.x * farg1;
        v.y = arg1->y - camera_right.y * farg1;
        v.z = arg1->z - camera_right.z * farg1;
        project_world_to_screen(0, &v, &o2, &camera_right);
        if (o2.x > 640.0f) {
            return 0;
        }
    }
    return 1;
}
#pragma pop

int TObjChip__vt6(void* p) { return *(u32*)((char*)p + 0x230) == 0; }

void dispatch_vt9__8TObjChipFPv(void *arg0) {
    struct VObj_801809C4_801809B4 *o = (struct VObj_801809C4_801809B4 *)arg0;
    o->m9();
}

void update__8TObjChipFPv(void *object) {
    struct VObj_801809F0_801809B4 *o = (struct VObj_801809F0_801809B4 *)object;
    o->m7();
    if (o->m6() == 1) {
        queue_destruction__7TObjectFv(object);
    }
}
}

TObjChip::~TObjChip() {}

extern "C" {

typedef char RecoveredGlobal_80180AA4___vt__8TObjChip_size[sizeof(RecoveredGlobal_80180AA4___vt__8TObjChip) == 0x38 ? 1 : -1];
u8 *__ct__8TObjChipFv(u8 *object, u8 *arg1, u8 *arg2) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__8TObjChip;
    *(s32 *)((s8 *)object + 0) = (s32) obj_chip_class_name_ptr;
    copy_debris_params__8TObjChipFPvPv(object + 0x24, arg2);
    *(f32 *)((s8 *)object + 0x1C) = (f32) (2e+02f);
    *(f32 *)((s8 *)object + 0x20) = 40.0f;
    *(s32 *)((s8 *)object + 0x230) = 1;
    if (((VObj_18_6eb662 *)(object))->m5(arg2 + 0x4C, (2e+02f)) == 0) {
        *(s32 *)((s8 *)object + 0x230) = 0;
    }
    return object;
}

void copy_debris_params__8TObjChipFPvPv(u8 *arg0, u8 *arg1) {
    *(f32 *)((s8 *)arg0 + 0) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)arg0 + 4) = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(ByteBlock_C *)((s32) arg0 + 0xC) = *(const ByteBlock_C *)((s32) arg1 + 0xC);
    *(ByteBlock_C *)((s32) arg0 + 0x18) = *(const ByteBlock_C *)((s32) arg1 + 0x18);
    *(ByteBlock_C *)((s32) arg0 + 0x24) = *(const ByteBlock_C *)((s32) arg1 + 0x24);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg1 + 0x30);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)arg1 + 0x34);
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)arg1 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) *(f32 *)((s8 *)arg1 + 0x3C);
    *(s32 *)((s8 *)arg0 + 0x40) = (s32) *(s32 *)((s8 *)arg1 + 0x40);
    *(s32 *)((s8 *)arg0 + 0x44) = (s32) *(s32 *)((s8 *)arg1 + 0x44);
    *(s32 *)((s8 *)arg0 + 0x48) = (s32) *(s32 *)((s8 *)arg1 + 0x48);
}

typedef char RecoveredGlobal_80180BD4___vt__8TObjChip_size[sizeof(RecoveredGlobal_80180BD4___vt__8TObjChip) == 0x38 ? 1 : -1];
u8 *construct_debris__8TObjChipFPvPvPv(u8 *object, u8 *arg1, u8 *arg2) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__8TObjChip;
    *(s32 *)((s8 *)object + 0) = (s32) obj_chip_class_name_ptr;
    copy_debris_params__8TObjChipFPvPv(object + 0x24, arg2);
    *(f32 *)((s8 *)object + 0x1C) = (f32) (2e+02f);
    *(f32 *)((s8 *)object + 0x20) = 40.0f;
    *(s32 *)((s8 *)object + 0x230) = 1;
    if (((VObj_18_2a3247 *)(object))->m4((2e+02f)) == 0) {
        *(s32 *)((s8 *)object + 0x230) = 0;
    }
    return object;
}

u8 *copy_transform__8TObjChipFPvPv(u8 *arg0, u8 *arg1) {
    *(f32 *)((s8 *)arg0 + 0) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)arg0 + 4) = (f32) *(f32 *)((s8 *)arg1 + 4);
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 8);
    VecCopy((Vec *)(arg0 + 0xC), (const Vec *)(arg1 + 0xC));
    VecCopy((Vec *)(arg0 + 0x18), (const Vec *)(arg1 + 0x18));
    ((TObjPlayer *)(arg0 + 0x24))->copy_xyz(arg1 + 0x24);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg1 + 0x30);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)arg1 + 0x34);
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)arg1 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) *(f32 *)((s8 *)arg1 + 0x3C);
    *(s32 *)((s8 *)arg0 + 0x40) = (s32) *(s32 *)((s8 *)arg1 + 0x40);
    *(s32 *)((s8 *)arg0 + 0x44) = (s32) *(s32 *)((s8 *)arg1 + 0x44);
    *(s32 *)((s8 *)arg0 + 0x48) = (s32) *(s32 *)((s8 *)arg1 + 0x48);
    *(s32 *)((s8 *)arg0 + 0x54) = 0;
    *(s32 *)((s8 *)arg0 + 0x50) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C) = 0;
    return arg0;
}

void __dt__8TObjChipFv();
void render_shadows__7TObjectFv();
void *__vt__8TObjChip[] = {
    0, 0,
    (void *)__dt__8TObjChipFv,
    (void *)update__8TObjChipFPv,
    (void *)dispatch_vt9__8TObjChipFPv,
    (void *)render_shadows__7TObjectFv,
    (void *)init_chips__8TObjChipFPv,
    (void *)spawn_chips__8TObjChipFPvPv,
    (void *)TObjChip__vt6,
    (void *)tick_chips__8TObjChipFPv,
    (void *)TObjChip__vt8,
    (void *)render__8TObjChipFPv,
    (void *)TObjChip__vt10,
    (void *)draw_chips__8TObjChipFPv,
};
}
