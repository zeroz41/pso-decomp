#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/TObject.h"
#include "pso/ui/TAdGameStartGC.h"
#include "pso/system/byteswap.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/system/ModelDrawContext.h"
class TAdGameStartGC : public TObject {
public:
    virtual void render();
    virtual ~TAdGameStartGC();
};
class TAdGameStartSubGC : public TObject {
public:
    virtual void render();
    virtual ~TAdGameStartSubGC();
    virtual void run_task();
};

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Ent_802E6750 { s32 idx; f32 x; f32 y; s32 c; };

struct Obj_802E6750 {
    s32 g; u8 pad0[0x14]; void *vt; Ent_802E6750 e[8];
    s32 f9C; s32 fA0; s32 z[8]; s32 fC4; s32 fC8; s32 fCC; s32 fD0;
};

struct Obj_802E6380 {
    u8 pad0[0x9C];
    s32 f9C;
    s32 fA0;
    void *list[8];
    void *fC4;
    void *fC8;
    void *fCC;
    void *fD0;
};

struct Obj_802E6380;
struct Slot_802E655C { u8 pad[0x10]; };

struct GS_802E655C { u8 pad0[0x1C]; Slot_802E655C slots[8]; s32 count; s32 active; s32 subs[8]; };

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
u32 __nw__7TObjectFUl(int);
u8 *__ct__18TAdGameStartBackGCFv(u8 *arg0, u8 *arg1);
u32 __ct__20TAdGameStartShadowGCFv(int, void *);
u32 __ct__18TAdGameStartLineGCFv(int, void *);
u32 __ct__19TAdGameStartShineGCFv(int, void *);
s32 __ct__7TObjectFP7TObject(void *);
extern s32 __vt__14TAdGameStartGC[];
extern void *ad_game_start_name_ptr[2];
Obj_802E6750 *__ct__14TAdGameStartGCFv(Obj_802E6750 *arg0);
void destroy_windows__14TAdGameStartGCFPv(Obj_802E6380 *o);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
extern u8 controller_physical_port_bank[];

void bswap_6x92__14TAdGameStartGCFPv(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_32((u32 *)((char*)p + 0x4)); bswap_32((u32 *)((char*)p + 0x8)); }
void send_6x92__14TAdGameStartGCFPv(void* p) { bswap_6x92__14TAdGameStartGCFPv(p); send_subcommand((u8 *)p); }
void TAdGameStartGC__sub_802E6368(void* p) { *(u8*)((char*)p + 0x0) = 146; *(u8*)((char*)p + 0x1) = 3; }

void render__14TAdGameStartGCFv(void) {  }

void destroy_windows__14TAdGameStartGCFPv(Obj_802E6380 *o) {
    u32 i;
    if (o->fC4 != NULL) {
        queue_destruction__7TObjectFv(o->fC4);
        o->fC4 = NULL;
    }
    if (o->fC8 != NULL) {
        queue_destruction__7TObjectFv(o->fC8);
        o->fC8 = NULL;
    }
    if (o->fCC != NULL) {
        queue_destruction__7TObjectFv(o->fCC);
        o->fCC = NULL;
    }
    if (o->fD0 != NULL) {
        queue_destruction__7TObjectFv(o->fD0);
        o->fD0 = NULL;
    }
    for (i = 0; i < 8; i++) {
        if (o->list[i] != NULL) {
            queue_destruction__7TObjectFv(o->list[i]);
            o->list[i] = NULL;
        }
    }
    o->fA0 = 0;
    o->f9C = -1;
}

void create_effects__14TAdGameStartGCFPv(u8 *parent) {
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 temp_r3_5;
    u32 object;
    u32 temp_r3_7;
    u32 temp_r3_8;
    u32 var_r0;
    u32 var_r0_2;
    u32 var_r0_3;
    u32 var_r0_4;
    *(s32 *)((s8 *)parent + 0xA0) = 1;
    temp_r3 = *(u32 *)((s8 *)parent + 0xC4);
    if (temp_r3 != 0U) {
        queue_destruction__7TObjectFv((void *)temp_r3);
        *(u32 *)((s8 *)parent + 0xC4) = 0U;
    }
    temp_r3_2 = *(u32 *)((s8 *)parent + 0xC8);
    if (temp_r3_2 != 0U) {
        queue_destruction__7TObjectFv((void *)temp_r3_2);
        *(u32 *)((s8 *)parent + 0xC8) = 0U;
    }
    temp_r3_3 = *(u32 *)((s8 *)parent + 0xCC);
    if (temp_r3_3 != 0U) {
        queue_destruction__7TObjectFv((void *)temp_r3_3);
        *(u32 *)((s8 *)parent + 0xCC) = 0U;
    }
    temp_r3_4 = *(u32 *)((s8 *)parent + 0xD0);
    if (temp_r3_4 != 0U) {
        queue_destruction__7TObjectFv((void *)temp_r3_4);
        *(u32 *)((s8 *)parent + 0xD0) = 0U;
    }
    temp_r3_5 = __nw__7TObjectFUl(0xC8);
    var_r0 = temp_r3_5;
    if (var_r0 != 0U) {
        var_r0 = __ct__20TAdGameStartShadowGCFv(temp_r3_5, parent);
    }
    *(u32 *)((s8 *)parent + 0xC4) = var_r0;
    object = __nw__7TObjectFUl(0x80);
    var_r0_2 = object;
    if (var_r0_2 != 0U) {
        var_r0_2 = (u32)__ct__18TAdGameStartBackGCFv((u8 *)object, (u8 *)parent);
    }
    *(u32 *)((s8 *)parent + 0xC8) = var_r0_2;
    temp_r3_7 = __nw__7TObjectFUl(0x160);
    var_r0_3 = temp_r3_7;
    if (var_r0_3 != 0U) {
        var_r0_3 = __ct__18TAdGameStartLineGCFv(temp_r3_7, parent);
    }
    *(u32 *)((s8 *)parent + 0xCC) = var_r0_3;
    temp_r3_8 = __nw__7TObjectFUl(0x80);
    var_r0_4 = temp_r3_8;
    if (var_r0_4 != 0U) {
        var_r0_4 = __ct__19TAdGameStartShineGCFv(temp_r3_8, parent);
    }
    *(u32 *)((s8 *)parent + 0xD0) = var_r0_4;
}

void run_task__14TAdGameStartGCFv(u8 *arg0) {
    GS_802E655C *gs = (GS_802E655C *) arg0;
    s32 sub;
    u8 *pad;
    if (gs->active != 0) {
        gs->count++;
        if (gs->count < 8) {
            sub = __nw__7TObjectFUl(0x88);
            if (sub != 0) {
                sub = ((s32 (*)(void *, void *, void *))__ct__17TAdGameStartSubGCFv)((void *) sub, arg0, &gs->slots[gs->count]);
            }
            gs->subs[gs->count] = sub;
        }
        if (gs->count > 0x3C) {
            destroy_windows__14TAdGameStartGCFPv((Obj_802E6380 *) arg0);
            return;
        }
        pad = controller_physical_port_bank + TAdMultiPlyChrSelectGC::get_clamped_cursor() * 0x50 + 0x20;
        if (TWindowShortListCtrl__check_controller_button(pad, 4) != 0) {
            destroy_windows__14TAdGameStartGCFPv((Obj_802E6380 *) arg0);
        }
        if (TWindowShortListCtrl__check_controller_button(pad, 2) != 0) {
            destroy_windows__14TAdGameStartGCFPv((Obj_802E6380 *) arg0);
        }
        if (TWindowShortListCtrl__check_controller_button(pad, 8) != 0) {
            destroy_windows__14TAdGameStartGCFPv((Obj_802E6380 *) arg0);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)pad, 0x10, 6, 1) != 0) {
            destroy_windows__14TAdGameStartGCFPv((Obj_802E6380 *) arg0);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)pad, 0x20, 6, 1) != 0) {
            destroy_windows__14TAdGameStartGCFPv((Obj_802E6380 *) arg0);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)pad, 0x40, 6, 1) != 0) {
            destroy_windows__14TAdGameStartGCFPv((Obj_802E6380 *) arg0);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)pad, 0x80, 6, 1) != 0) {
            destroy_windows__14TAdGameStartGCFPv((Obj_802E6380 *) arg0);
        }
    }
}

TAdGameStartGC::~TAdGameStartGC() {}

Obj_802E6750 *__ct__14TAdGameStartGCFv(Obj_802E6750 *arg0) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0);
    arg0->vt = __vt__14TAdGameStartGC;
    arg0->g = (s32)ad_game_start_name_ptr[0];
    arg0->f9C = -1;
    arg0->fA0 = 0;
    arg0->fC4 = 0;
    arg0->fC8 = 0;
    arg0->fCC = 0;
    arg0->fD0 = 0;
    for (i = 0; i < 8; i++) {
        arg0->e[i].idx = i;
        arg0->e[i].x = (94.0f);
        arg0->e[i].y = (196.0f);
        arg0->e[i].c = -1;
        arg0->z[i] = 0;
    }
    return arg0;
}

void release_texture_list(void*);

extern int multiplay_texture_f512_handle;

void destroy_instance__17TAdGameStartSubGCFv(void) {
    if ((u32) multiplay_texture_f512_handle != 0U) {
        release_texture_list((void*)multiplay_texture_f512_handle);
        multiplay_texture_f512_handle = 0U;
    }
}

    s32 TLobby__sub_8023E4B4(s32 arg0, s32 arg1);
}
    extern const unsigned char lbl_80472C28[];
    extern void *texture_f512_multiplay_descriptor[];
void register_texture_f512_multiplay(void) { multiplay_texture_f512_handle = (int)texture_f512_multiplay_descriptor; TLobby__sub_8023E4B4((s32)lbl_80472C28, (s32)texture_f512_multiplay_descriptor); }
extern "C" {
__declspec(section ".rodata") extern const unsigned char lbl_80472C28[] = "f512_multiplay";
__declspec(section ".rodata") extern const char lbl_80472C38[] = "TAdGameStartGC";
__declspec(section ".rodata") extern const char lbl_80472C48[] = "TAdGameStartSubGC";

#pragma push
#pragma fp_contract on

void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(void *, int, f32);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern s32 game_start_player_instance;

void draw_background__17TAdGameStartSubGCFPv(u8 *arg0) {
    s32 temp_r4;

    begin_screen_draw(1);
    TObjFish::set_global_param(game_start_player_instance);
    set_draw_texture_and_color(0, ((*(s32 *)((s8 *)arg0 + 0x80) << 0x18) | 0xFF0000 | 0xFFFF));
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x1C);
    draw_textured_quad_at_depth(arg0 + 0x40, temp_r4, (f32) (((0.01f) * (f32) temp_r4) + (0.8f)));
    TWindowSubStatusDisp::get_player();
}
#pragma pop

extern s32 __vt__17TAdGameStartSubGC[];
extern void *lbl_805D3FB0[2];

void render__17TAdGameStartSubGCFv(void* p) { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); draw_background__17TAdGameStartSubGCFPv((u8 *)p); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }
#pragma push
#pragma fp_contract on
void run_task__17TAdGameStartSubGCFv(u8 *arg0) {
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    s32 temp_r4;
    s32 var_r0;
    *(s32 *)((s8 *)arg0 + 0x84) = (s32) (*(s32 *)((s8 *)arg0 + 0x84) + 1);
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x84);
    if (temp_r4 < 4) {
        *(f32 *)((s8 *)arg0 + 0x70) = (f32) ((3.0f) - ((0.6666667f) * (f32) temp_r4));
        *(f32 *)((s8 *)arg0 + 0x74) = (f32) ((3.0f) - ((0.6666667f) * (f32) *(s32 *)((s8 *)arg0 + 0x84)));
    } else if (temp_r4 > 0x1C) {
        *(f32 *)((s8 *)arg0 + 0x70) = (f32) ((1.0f) - ((-0.6666667f) * (temp_r4 - 0x1D)));
        *(f32 *)((s8 *)arg0 + 0x74) = (f32) ((1.0f) - ((-0.6666667f) * (f32) (*(s32 *)((s8 *)arg0 + 0x84) - 0x1D)));
        if ((s32) *(s32 *)((s8 *)arg0 + 0x84) > 0x1D) {
            *(s32 *)((s8 *)arg0 + 0x80) = (s32) (*(s32 *)((s8 *)arg0 + 0x80) - 0x55);
        }
        var_r0 = *(s32 *)((s8 *)arg0 + 0x80);
        if (var_r0 < 0) {
            var_r0 = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x80) = var_r0;
    }
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x68);
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) ((*(f32 *)((s8 *)arg0 + 0x70) * (*(f32 *)((s8 *)arg0 + 0x20) - temp_f2)) + temp_f2);
    temp_f2_2 = *(f32 *)((s8 *)arg0 + 0x6C);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) ((*(f32 *)((s8 *)arg0 + 0x74) * (*(f32 *)((s8 *)arg0 + 0x24) - temp_f2_2)) + temp_f2_2);
    temp_f2_3 = *(f32 *)((s8 *)arg0 + 0x68);
    *(f32 *)((s8 *)arg0 + 0x48) = (f32) ((*(f32 *)((s8 *)arg0 + 0x70) * (*(f32 *)((s8 *)arg0 + 0x28) - temp_f2_3)) + temp_f2_3);
    temp_f2_4 = *(f32 *)((s8 *)arg0 + 0x6C);
    *(f32 *)((s8 *)arg0 + 0x4C) = (f32) ((*(f32 *)((s8 *)arg0 + 0x74) * (*(f32 *)((s8 *)arg0 + 0x2C) - temp_f2_4)) + temp_f2_4);
}
#pragma pop

#pragma push
#pragma fp_contract on
#define F(o) (*(f32 *)(arg0 + (o)))
#define I(o) (*(s32 *)(arg0 + (o)))
TAdGameStartSubGC::~TAdGameStartSubGC() {}
u8 *__ct__17TAdGameStartSubGCFv(u8 *arg0, void *arg1, u8 *arg2) {
    s32 t;
    ((void (*)(void *, void *))__ct__7TObjectFP7TObject)(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TAdGameStartSubGC;
    I(0) = (s32)lbl_805D3FB0[0];
    I(0x1C) = *(s32 *)((s8 *)arg2 + 0);
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 0x60))->copy_vec2(arg2 + 4);
    t = *(s32 *)((s8 *)arg2 + 0xC);
    I(0x7C) = t;
    I(0x84) = -1;
    F(0x70) = (3.0f);
    F(0x74) = (3.0f);
    I(0x80) = 0xFF;
    game_start_player_instance = TObjPlayer::get_instance();
    F(0x20) = (64.0f) * (f32)I(0x1C) + F(0x60);
    F(0x24) = F(0x64);
    F(0x28) = (64.0f) * (f32)(I(0x1C) + 1) + F(0x60);
    F(0x2C) = (128.0f) + F(0x64);
    F(0x68) = (0.5f) * (F(0x28) - F(0x20)) + F(0x20);
    F(0x6C) = (0.5f) * (F(0x2C) - F(0x24)) + F(0x24);
    F(0x50) = (64.0f) * (f32)I(0x1C) / 512.0f;
    F(0x54) = (0.0f);
    F(0x58) = ((64.0f) * (f32)(I(0x1C) + 1) - (1.0f)) / 512.0f;
    F(0x5C) = (0.25f);
    return arg0;
}
#undef F
#undef I
#pragma pop

void __dt__14TAdGameStartGCFv();
void __dt__17TAdGameStartSubGCFv();
void render_shadows__7TObjectFv();
void *lbl_804E3B60[3] = {(void *)lbl_80472C28, 0, 0};
__declspec(section ".data") void *texture_f512_multiplay_descriptor[2] = {(void *)lbl_804E3B60, (void *)1};
}
s32 __vt__14TAdGameStartGC[] = {
    0, 0,
    (s32)__dt__14TAdGameStartGCFv,
    (s32)run_task__14TAdGameStartGCFv,
    (s32)render__14TAdGameStartGCFv,
    (s32)render_shadows__7TObjectFv,
    0,
};
s32 __vt__17TAdGameStartSubGC[] = {
    0, 0,
    (s32)__dt__17TAdGameStartSubGCFv,
    (s32)run_task__17TAdGameStartSubGCFv,
    (s32)render__17TAdGameStartSubGCFv,
    (s32)render_shadows__7TObjectFv,
};
void *ad_game_start_name_ptr[2] = {(void *)lbl_80472C38, 0};
void *lbl_805D3FB0[2] = {(void *)lbl_80472C48, 0};
