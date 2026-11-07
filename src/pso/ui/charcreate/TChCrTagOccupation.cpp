#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/charcreate/TChCrTagOccHeader.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrTagOccupation.h"
extern "C" void render__18TChCrTagOccupationFv();
#include "pso/ui/charcreate/TChCrCharSelect.h"

extern "C" {

int render__17TChCrTagOccHeaderFv(void* p);
int fn_802A2A00(void*);

void TChCrTagOccHeader::render() { fn_802A2A00(this); }

}

struct Hdr_802A2C30 {
    u8 pad[0x20];
    s32 f20;
};

extern "C" {
s32 get_selected_char__15TChCrCharSelectFv();
s32 TChCrTagOccHeader__vt4(Hdr_802A2C30 *arg0);
void run_task__17TChCrTagOccHeaderFv(u8 *arg0);

void TChCrTagOccHeader::run_task() {
    u8 *arg0 = (u8 *)this;
    update_fade__8TChCrTagFPv(arg0);
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) + 1);
}
s32 TChCrTagOccHeader__vt4(Hdr_802A2C30 *arg0) {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (arg0->f20 < 3 && arg0->f20 == get_selected_char__15TChCrCharSelectFv()) {
            return 1;
        }
        break;
    default:
        if (arg0->f20 >= 3 && arg0->f20 - 3 == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}

extern void *__vt__17TChCrTagOccHeader[];
void __dl__7TObjectFPv(void *);
void *__dt__17TChCrTagOccHeaderFv(void *self, s16 m) {
    if (self != NULL) {
        *(void ***)((s8 *)self + 0x18) = __vt__17TChCrTagOccHeader;
        __dt__8TChCrTagFv(self, 0);
        if (m > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

void render_shadows__7TObjectFv();
void *__vt__17TChCrTagOccHeader[] = {
    0, 0,
    (void *)__dt__17TChCrTagOccHeaderFv,
    (void *)run_task__17TChCrTagOccHeaderFv,
    (void *)render__17TChCrTagOccHeaderFv,
    (void *)render_shadows__7TObjectFv,
    (void *)TChCrTagOccHeader__vt4,
    0,
};

#define get_selected_char__15TChCrCharSelectFv (*(s32 (*)(void *))&get_selected_char__15TChCrCharSelectFv)


extern const f32 lbl_805DDECC;
extern const f32 lbl_805DDED0;
extern void *chcr_tag_occ_header_class_name;

void *__ct__17TChCrTagOccHeaderFv(void *ch_cr_tag_occ_header, TObject *parent, void *arg) {
    __ct__8TChCrTagFP7TObjectPv(ch_cr_tag_occ_header, parent, arg);
    *(void ***)((s8 *)ch_cr_tag_occ_header + 0x18) = __vt__17TChCrTagOccHeader;
    *(void * *)&((TChCrTagOccHeader *)ch_cr_tag_occ_header)->m_name = chcr_tag_occ_header_class_name;
    *(f32 *)((s8 *)ch_cr_tag_occ_header + 0x28) = lbl_805DDECC;
    *(f32 *)((s8 *)ch_cr_tag_occ_header + 0x2C) = lbl_805DDED0;
    *(f32 *)((s8 *)ch_cr_tag_occ_header + 0x34) = lbl_805DDECC;
    *(f32 *)((s8 *)ch_cr_tag_occ_header + 0x38) = lbl_805DDED0;
    return ch_cr_tag_occ_header;
}

void *__nw__7TObjectFUl(int);
}

void *create_ch_cr_tag_occ_header(void *arg0) {
    void *o = __nw__7TObjectFUl(0x40);
    if (o != NULL) {
        o = __ct__17TChCrTagOccHeaderFv(o, tl_03, arg0);
    }
    return o;
}

void create_all_ch_cr_tag_headers(void);

void create_all_ch_cr_tag_headers(void) { { int i; for (i = 0; i < 15; i++) { ((int (*)(void *))create_ch_cr_tag_occ_header)((void*)i); } } }

#include "pso/math/TMath.h"

struct RecoveredGlobal_802A300C___vt__18TChCrTagOccupation {
    s32 value;
    u8 remaining[0x1C];
};

struct VBase_802A2DF4 { char pad[0x18]; };
struct Tag_802A2DF4 : VBase_802A2DF4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    s32 f1c;
    s32 f20;
    f32 f24;
    u8 pad28[0x30 - 0x28];
    f32 f30;
    u8 pad34[0x3C - 0x34];
    f32 f3c;
    f32 f40;
};

struct Obj_802A2F78 { u8 pad[0x20]; s32 f20; };

extern "C" {
void draw_ui_sprite_shaded(s32 sprite_id, const vec2f *position, const vec2f *scale,
                           f32 depth, f32 alpha, f32 brightness);
extern const f32 lbl_805DDED8;
extern const f32 lbl_805DDEDC;
extern const f32 lbl_805DDEE0;
extern const f32 lbl_805DDEE4;
extern const f32 lbl_805DDEE8;
extern const f32 lbl_805DDEEC;
extern const f32 lbl_805DDEF0;
extern const f32 lbl_805DDEF4;
extern const f32 lbl_805DDEF8;
extern const f32 lbl_805DDEFC;
extern void *__vt__18TChCrTagOccupation[];
void *__dt__18TChCrTagOccupationFv(void *self, s16 m);
const char *chcr_tag_occupation_class_name = "TChCrTagOccupation";
extern const f32 lbl_805DDF00;
extern const f32 lbl_805DDF04;
extern const f32 lbl_805DDF08;
extern const f32 lbl_805DDF0C;
extern const f32 lbl_805DDF10;
extern const f32 lbl_805DDF14;
int TChCrTagOccupation__vt4(Obj_802A2F78 *self);
#pragma push
#pragma fp_contract on
void TChCrTagOccupation::sub_802A2DF4() {
    f32 t;
    f32 s;
    f32 depth;
    s32 id = ((Tag_802A2DF4 *)this)->f20 + 0x39;
    vec2f pos = {33.0f, 100.0f};
    vec2f scale = {1.0f, 1.0f};
    if (((Tag_802A2DF4 *)this)->f24 > ((Tag_802A2DF4 *)this)->f3c) {
        t = (((Tag_802A2DF4 *)this)->f24 - ((Tag_802A2DF4 *)this)->f3c) / (((Tag_802A2DF4 *)this)->f40 - ((Tag_802A2DF4 *)this)->f3c);
    } else {
        return;
    }
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        s = lbl_805DDEDC * ((Tag_802A2DF4 *)this)->f30 + lbl_805DDED8;
        break;
    default:
        s = ((Tag_802A2DF4 *)this)->f30;
        break;
    }
    if (((Tag_802A2DF4 *)this)->m4() != 0) {
        depth = lbl_805DDEE0;
    } else {
        depth = lbl_805DDEE8 * s + lbl_805DDEE4;
    }
    pos.x = lbl_805DDEEC * (lbl_805DDEF0 - t) + pos.x;
    pos.y = lbl_805DDEF4 * (f32)((Tag_802A2DF4 *)this)->f20 + pos.y;
    draw_ui_sprite_shaded(id, &pos, &scale, depth, lbl_805DDEF0, lbl_805DDEFC * (s * s) + lbl_805DDEF8);
}
#pragma pop

void TChCrTagOccupation::render() { sub_802A2DF4(); }

int TChCrTagOccupation__vt4(Obj_802A2F78 *self) {
    if (get_selected_char__15TChCrCharSelectFv(self) == self->f20) return 1;
    return 0;
}

void *__dt__18TChCrTagOccupationFv(void *self, s16 m) {
    if (self != NULL) {
        *(void ***)((s8 *)self + 0x18) = __vt__18TChCrTagOccupation;
        __dt__8TChCrTagFv(self, 0);
        if (m > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_802A300C___vt__18TChCrTagOccupation_size[sizeof(RecoveredGlobal_802A300C___vt__18TChCrTagOccupation) == 0x20 ? 1 : -1];

u8 *__ct__18TChCrTagOccupationFv(u8 *ch_cr_tag, TObject *parent, void *arg) {
    __ct__8TChCrTagFP7TObjectPv(ch_cr_tag, parent, arg);
    *(s32 **)((s8 *)ch_cr_tag + 0x18) = (s32 *)__vt__18TChCrTagOccupation;
    ((TObject *)ch_cr_tag)->m_name = chcr_tag_occupation_class_name;
    *(f32 *)((s8 *)ch_cr_tag + 0x28) = (f32) lbl_805DDF00;
    *(f32 *)((s8 *)ch_cr_tag + 0x2C) = (f32) lbl_805DDF04;
    *(f32 *)((s8 *)ch_cr_tag + 0x34) = (f32) lbl_805DDF08;
    *(f32 *)((s8 *)ch_cr_tag + 0x38) = (f32) lbl_805DDF0C;
    *(f32 *)((s8 *)ch_cr_tag + 0x3C) = (f32) ((lbl_805DDF14 * (f32) *(s32 *)((s8 *)ch_cr_tag + 0x20)) + lbl_805DDF10);
    *(f32 *)((s8 *)ch_cr_tag + 0x40) = (f32) lbl_805DDEF0;
    return ch_cr_tag;
}
#pragma pop

void *TChCrTagOccupation::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x44);
    if (o != NULL) {
        o = __ct__18TChCrTagOccupationFv((u8 *)o, tl_03, arg0);
    }
    return o;
}

void TChCrTagOccupation::create_all() { { int i; for (i = 0; i < 3; i++) { TChCrTagOccupation::create((void *)((void*)i)); } } }

void *__vt__18TChCrTagOccupation[8] = {
    0,
    0,
    (void *)__dt__18TChCrTagOccupationFv,
    (void *)update_fade__8TChCrTagFPv,
    (void *)&render__18TChCrTagOccupationFv,
    (void *)render_shadows__7TObjectFv,
    (void *)TChCrTagOccupation__vt4,
    0,
};
}

#undef get_selected_char__15TChCrCharSelectFv
