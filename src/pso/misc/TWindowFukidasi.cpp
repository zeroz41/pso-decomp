#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TUnk_804CF0B8.h"
#include "pso/misc/TWindowFukidasi.h"
#include "pso/TObjCMHairMenu.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChat.h"
#include "pso/object/TObjFish.h"

struct Pt_80250A24 { f32 x, y; };

struct Fuki_80250A24 {
    u8 pad0[0x38];
    f32 size[2];
    u8 pad40[0x48 - 0x40];
    f32 rsize[2];
    u8 pad50[0x90 - 0x50];
    f32 center[2];
};

struct Fuki_802506E8 {
    u8 pad0[0x38];
    f32 size[2];
    u8 pad40[0x48 - 0x40];
    f32 rsize[2];
    u8 pad50[0x90 - 0x50];
    f32 center[2];
};

extern "C" {
f32 fabs_float(f32);
f32 atan2_float(f32, f32);
f32 newton_sqrtf(f32);
s32 clamp_position__13TUnk_804CF0B8FPvf(void *arg0, void *arg1, f32 farg0);
int rand(void);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 xyz_distance(void *, void *);
extern const f64 TWindowFukidasi__data_8044ED70;
extern const f32 TWindowFukidasi__data_805DCCE8;
extern const f32 TWindowFukidasi__data_805DCD08;
extern const f32 TWindowFukidasi__data_805DCD0C;
extern const f32 TWindowFukidasi__data_805DCD14;
extern const f32 TWindowFukidasi__data_805DCD18;
extern const f32 TWindowFukidasi__data_805DCD1C;
extern const f32 lbl_805DCD20;
extern const f32 lbl_805DCD24;
extern const f32 TWindowFukidasi__data_805DCD28;
extern const f32 lbl_805DCD2C;
s32 rest_balloon__15TWindowFukidasiFv(Fuki_80250A24 *b, f32 *rect, f32 *arg2);
s32 try_place_bubble__15TWindowFukidasiFPvPvPv(Fuki_802506E8 *b, f32 *rect, f32 *o);
struct Entry_80250380 { u8 pad[0x10]; f32 w; f32 h; };

struct Fuki_80250380 { u8 pad[0x24]; u8 entries[0x4C]; u8 phase; u8 options; u8 kind; };

struct Fuki_80250314 { u8 pad[0x38]; f32 anchor[2]; };

struct Fuki_80250F70 {
    u8 pad0[0x38]; f32 anchor[2];
    u8 pad40[0x50];
    f32 head[2];
};

struct Fuki_802504C0 {
    u8 pad0[0x20]; s16 viewport; u8 pad22[0xE];
    f32 rect[2]; f32 anchor[2];
    u8 pad40[0x30];
    u8 phase; u8 options; u8 kind; u8 slot;
};

struct Fuki_8025181C { u8 pad0[0x38]; f32 w; f32 h; };

struct Fuki_80250F70;

struct Fuki_802504C0;

struct Fuki_80251028 {
    u8 pad0[0x20]; s16 viewport; u8 pad22[0xE];
    f32 rect[2]; f32 anchor[2];
    u8 pad40[0x30];
    u8 phase; u8 options; u8 kind; u8 slot;
};

struct Fuki_80251380 {
    u8 pad0[0x20];
    s16 viewport;
};

struct Vec_80251380 {
    f32 x, y, z;
};

struct Cam_80251380 {
    u8 pad0[0x178];
    f32 pos[3];
    u8 pad184[0x190 - 0x184];
    s32 rx;
    s32 ry;
    s32 rz;
};

struct RecoveredGlobal_80251BA0_lbl_804CF080
{
  s32 value;
  u8 remaining[0x20];
};

typedef struct RecoveredGlobal_80251BA0_lbl_804CF080 RecoveredGlobal_80251BA0_lbl_804CF080;

struct Fuki_802521E8;

struct Fuki_80252764 {
    u8 pad0[0x24];
    u8 f24[0x30 - 0x24];
    f32 rect[2];
    f32 anchor[2];
    u8 pad40[0x54 - 0x40];
    f32 f54;
    u8 pad58[0x70 - 0x58];
    u8 phase;
    u8 pad71[0x80 - 0x71];
    f32 tail;
    u32 color;
    f32 center[2];
    f32 head[2];
};

struct View_80252764 {
    u8 pad0[0x28];
    f32 sx;
    f32 sy;
};

struct Fuki_802521E8 {
    u8 pad0[0x54];
    f32 f54;
    u8 pad58[0x80 - 0x58];
    f32 tail;
    u8 pad84[4];
    f32 center[2];
};

struct Prim_802521E8 {
    f32 *verts;
    u32 *colors;
    s32 flags;
    s32 count;
};

struct Slice_80252558 { f32 x, y, z, width, f10, lean, rowHeight, f1c, u, v, uw, f2c, f30, vh, pad[4]; };

struct Fukidasi_80252558 { u8 pad[0x40]; f32 position[2]; f32 size[2]; };

struct DrawCtx_80252558 { u8 pad[0x20]; f32 pivot[2]; f32 scale[2]; };

struct Fuki_802511E4 {
    u8 pad0[0x76];
    u16 id;
    u8 pad78[4];
    f32 height;
};

struct Ent_802511E4 {
    u8 pad0[0x38];
    f32 pos[3];
};

struct Cam_802511E4 {
    u8 pad0[8];
    f32 x;
    f32 y;
};

struct Fuki_80251594 {
    u8 pad0[0x30];
    f32 rect[2];
    f32 anchor[2];
    f32 pos[2];
    f32 size[2];
    u32 steps;
    u8 pad54[0x71 - 0x54];
    u8 options;
    u8 pad72[0x80 - 0x72];
    f32 margin;
    u8 pad84[4];
    f32 center[2];
    f32 head[2];
};

struct Fuki_802523CC { u8 pad0[0x40]; f32 x; };

struct Slice_802523CC { f32 x; u8 pad4[8]; f32 width; u8 pad10[4]; f32 lean; u8 pad18[8]; f32 u; u8 pad24[4]; f32 uw; };

struct Ctx_802523CC { u8 pad0[0x20]; f32 pivot; u8 pad24[4]; f32 scale; };

s32 obj_isState3_324__9TObjCharaFv();
s32 is_split_screen();
void queue_destruction__7TObjectFv(void *);
s32 get_screen_width__11TCameraCtrlFv();
s32 get_screen_height__11TCameraCtrlFv();
void *mem_alloc(u32 size);
Ent_802511E4 * find_entity_by_id(u16);
u32 get_battle_ctrl_flag__10TObjPlayerFUs(u16);
u32 get_player_by_client_id(u32);
s32 get_array_entry__11TWindowBaseFi(void *, s32);
s32 play_sound_effect(int, int, int, int);
View_80252764 * get_draw_context__11TWindowBaseFPv(void *);
s32 get_field_20__17TWindowSubComCardFv();
s32 set_depth__11TWindowBaseFf(f32);
s32 sub_80246948__11TWindowBaseFv(void *);
s32 refresh_status_display__9TWindowDDFv(int);
void TWindowSubSymbolChat__sub_802483F0(int a0, void *a1);
void set_symbol_chat_parts__20TWindowSubSymbolChatFiPv(s32 arg0, void *arg1);
s32 draw_resolved_window__15TWindowFukidasiFllll(Fuki_80250F70 *, f32 *, f32 *, s32);
f32 * get_message_by_type__11TWindowCtrlFScl(u8, int);
void complete_speech_balloon(u8 *arg0);
s32 is_speech_balloon_ready(u8 *arg0);
void clamp_text_size__15TWindowFukidasiFPvPv(Fuki_80250314 *b, f32 *out);
s32 TWindowFukidasi__sub_802505C0(Fuki_80251028 *b, f32 *rect, f32 *out);
s32 shift_rect_with_head__15TWindowFukidasiFPvPvPv(Fuki_80250F70 *b, f32 *rect, f32 *out);
void refresh_rect_placement__15TWindowFukidasiFPv(Fuki_80251028 *b);
void TWindowFukidasi__sub_80251790(void *);
void set_color__13TUnk_804CF0B8FUs(void *arg0, u16 arg1);
void open__15TWindowFukidasiFPvPvi(u8 *arg0, u32 *arg1, s32 arg2);
void set_text__15TWindowFukidasiFPvii(u8 *arg0, s32 arg1, s32 arg2);
void init_flags__15TWindowFukidasiFPvi(void *arg0, s32 arg1);
void draw_name_plate__15TWindowFukidasiFv(void *, View_80252764 *, u32);
void TWindowFukidasi__sub_80252C38(void *p);
void clear_flag_20__13TUnk_804CF0B8Fv();
s32 fn_80252CBC(void);
void draw_visible_window_entries(void *, void *, View_80252764 *);
s32 init_window_layout_entries(void *, void *, int);
s32 reset_float_field__15TWindowHelpItemFv();
s32 measure_message_text_width(int, f32);
}
void set_text_entry_string(u8 *arg0, u32 str, s32 arg2);
extern "C" {
s32 strcmp(s32, s32);
s32 strncpy(s32, s32, s32);
f32 vec3_dot(void *, void *);
void project_world_to_screen(s32, f32 *, f32 *);
void rotate_vector_by_matrix(s32, void *, void *);
void rotate_matrix_y(s32, s32);
void rotate_matrix_z(s32, s32);
void rotate_matrix_x(s32, s32);
s32 push_matrix_from(void *src);
void push_matrix();
void pop_matrix();
void begin_screen_draw(s32 arg0);
void DVDConvertEntrynumToPath(f32 *q);
void set_draw_texture_and_color(s32 idx, s32 arg1);

extern Cam_802511E4 TCameraCtrl__data_804FF634;
extern const f32 TWindowFukidasi__data_805DCCF4;
extern const f32 TWindowFukidasi__data_805DCCFC;
extern const f32 TWindowFukidasi__data_805DCD30;
extern const f32 TWindowFukidasi__data_805DCD4C;
extern s32 TWindowFukidasi__balloon_color_table[];
extern Vec_80251380 fukidasi_forward_vec;
extern RecoveredGlobal_80251BA0_lbl_804CF080 window_fukidasi_layout_entries;
extern u8 identity_matrix[];
extern s32 window_fukidasi_class_name;
extern Cam_80251380 *camera_ctrl_instance;
extern void *lbl_805D63F0;
extern const f32 lbl_805DCCEC;
extern const f32 lbl_805DCCF0;
extern const f32 lbl_805DCCF8;
extern f32 lbl_805DCD00;
extern f32 lbl_805DCD04;
extern const f32 lbl_805DCD34;
extern const f32 lbl_805DCD38;
extern const f32 lbl_805DCD3C;
extern const f32 lbl_805DCD40;
extern const f32 lbl_805DCD44;
extern const f32 lbl_805DCD48;
extern const f32 lbl_805DCD50;
extern const f32 lbl_805DCD58;
extern const f32 lbl_805DCD78;
extern const f32 lbl_805DCD90;
extern const f32 lbl_805DCD94;
extern const f32 lbl_805DCD98;
extern const f32 lbl_805DCD9C;
extern const f32 lbl_805DCDA4;
extern const f32 lbl_805DCDB0;
extern const f32 lbl_805DCDB4;
extern const f32 lbl_805DCDB8;
extern const f32 lbl_805DCDBC;
extern const f32 lbl_805DCDC0;

void complete_speech_balloon(u8 *arg0) {
    s32 t;
    *(s8 *)(arg0 + 0x70) = 4;
    *(u8 *)(arg0 + 0x71) |= 0x40;
    ((TUnk_804CF0B8 *)arg0)->calc_text_size((f32 *)(arg0 + 0x38));
    ((s32 (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(arg0);
    TWindowFukidasi__sub_80252C38(arg0);
    ((TUnk_804CF0B8 *)arg0)->set_flag2c_bit100();
    ((TWindowBase *)arg0)->save_position();
    *(f32 *)(arg0 + 0x80) = TWindowFukidasi__data_805DCCE8;
    ((TWindowFukidasi *)arg0)->sync_display_pos();
    *(s32 *)(arg0 + 0x5C) = 0x186A0;
    t = *(u8 *)(arg0 + 0x72);
    switch (t) {
    case 0:
        get_array_entry__11TWindowBaseFi(arg0, 0);
        reset_float_field__15TWindowHelpItemFv();
        break;
    case 1:
    case 2:
        break;
    }
}

s32 is_speech_balloon_ready(u8 *arg0) {
    s32 t = *(arg0 + 0x72);
    switch (t) {
    case 0:
        get_array_entry__11TWindowBaseFi(arg0, 0);
        return fn_80252CBC();
    case 1:
    case 2:
        break;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::rearm_balloon(s32 arg1) {
    u32 n;

    if (((s32 (*)(void))sub_80246948__11TWindowBaseFv)() != 0) {
        *(s8 *)((s8 *)((u8 *)this) + 0x70) = 5;
    }
    ((s32 (*)(void *, void *))init_flags__15TWindowFukidasiFPvi)(this, (void *)arg1);
    switch ((s32) (*(u8 *)((s8 *)((u8 *)this) + 0x72))) {
    case 0:
        n = TWindowKeyBoardSoft::strnlen((s8 *)(((void * (*)(void *))get_field_20__17TWindowSubComCardFv)(((void * (*)(void *, int))get_array_entry__11TWindowBaseFi)(this, 0))), (u32)0x100);
        *(s16 *)((s8 *)((u8 *)this) + 0x74) = (s16) ((lbl_805DCCF0 * (f32) n) + lbl_805DCCEC);
        break;
    case 1:
        *(s16 *)((s8 *)((u8 *)this) + 0x74) = 0x5A;
        break;
    case 2:
        break;
    }
}
#pragma pop

s32 TWindowFukidasi::check_card_match_enabled(s32 arg1) {
    if ((u8) *(u8 *)((s8 *)this + 0x72) != 0) {
        return 0;
    }
    get_array_entry__11TWindowBaseFi(this, 0);
    return (u32) __cntlzw(strcmp(get_field_20__17TWindowSubComCardFv(), arg1)) >> 5;
}

void clamp_text_size__15TWindowFukidasiFPvPv(Fuki_80250314 *b, f32 *out) {
    f32 size[2];
    ((TUnk_804CF0B8 *)b)->calc_text_size((f32 *)size);
    if (b->anchor[0] > size[0]) {
        out[0] = size[0];
    } else {
        out[0] = b->anchor[0];
    }
    if (b->anchor[1] > size[1]) {
        out[1] = size[1];
    } else {
        out[1] = b->anchor[1];
    }
}

void TUnk_804CF0B8::calc_text_size(f32 *out) {
    Entry_80250380 *e;
    switch (((Fuki_80250380 *)this)->kind) {
    case 0:
        e = ((Entry_80250380 * (*)(void *, int))get_array_entry__11TWindowBaseFi)(this, 0);
        out[0] = TWindowFukidasi__data_805DCCF4 + (lbl_805DCCF8 + e->w);
        out[1] = TWindowFukidasi__data_805DCCF4 + (TWindowFukidasi__data_805DCCFC + e->h);
        break;
    case 1:
        TWindowSubSymbolChat__sub_802483F0((int)((Fuki_80250380 *)this)->entries, (void *)out);
        break;
    case 2:
        break;
    }
}

void TWindowFukidasi::sync_display_pos() { *(f32*)((char*)this + 0x60) = *(f32*)((char*)this + 0x80); *(f32*)((char*)this + 0x64) = *(f32*)((char*)this + 0x80); }

s32 TWindowFukidasi::approach(f32 farg0) {
    f32 temp_f31;

    temp_f31 = lbl_805DCD00 * (farg0 - *(f32 *)((s8 *)this + 0x80));
    if (fabs_float(temp_f31) < lbl_805DCD04) {
        *(f32 *)((s8 *)this + 0x80) = farg0;
        return 1;
    }
    *(f32 *)((s8 *)this + 0x80) = (f32) (*(f32 *)((s8 *)this + 0x80) + temp_f31);
    return 0;
}

void TUnk_804CF0B8::sub_802504A8() {
    if (!(this->m_71 & 0x10)) {
        this->m_70 = 7;
    }
}

#pragma push
#pragma fp_contract on
void TUnk_804CF0B8::place_rect_at_head_or_slot() {
    Fuki_802504C0 *b = (Fuki_802504C0 *)this;
    if (is_speaker_far_or_offscreen() != 0) {
        f32 *m;
        if ((s8)b->slot == -1) {
            ((TUnk_804CF0B8 *)b)->set_flag();
            ((TUnk_804CF0B8 *)b)->set_flag2c_bit200();
            b->slot = ((TUnk_804CF0B8 *)b)->alloc_nearest_free_slot();
        }
        m = get_message_by_type__11TWindowCtrlFScl(b->slot, b->viewport);
        b->rect[0] = m[0] - TWindowFukidasi__data_805DCD0C * b->anchor[0];
        b->rect[1] = m[1] - TWindowFukidasi__data_805DCD0C * b->anchor[1];
        ((TUnk_804CF0B8 *)b)->clamp_position(b->rect, TWindowFukidasi__data_805DCCE8);
    } else {
        f32 p[2];
        if ((s8)b->slot != -1) {
            ((TUnk_804CF0B8 *)b)->clear_visible_flag();
            ((TUnk_804CF0B8 *)b)->clear_flag2c_bit200();
            TWindowCtrl::release_slot((s8 *)&b->slot);
        }
        project_anchor((f32 *)(0), p);
        b->rect[0] = p[0] - TWindowFukidasi__data_805DCD0C * b->anchor[0];
        b->rect[1] = p[1] - TWindowFukidasi__data_805DCD0C * b->anchor[1];
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TWindowFukidasi__sub_802505C0(Fuki_80251028 *b, f32 *rect, f32 *out) {
    f32 x = ((TWindowCtrlMain *)b->viewport)->get_position_z();
    f32 w = (((TWindowCtrlMain *)b->viewport)->get_ctrl_field14() - ((TWindowCtrlMain *)b->viewport)->get_position_z()) - b->anchor[0];
    f32 y;
    f32 h;
    f32 t;
    t = TWindowFukidasi__data_805DCD14 * (f32) rand();
    out[0] = t * w + x;
    y = ((TWindowCtrlMain *)b->viewport)->get_field10();
    h = (((TWindowCtrlMain *)b->viewport)->get_field_18() - ((TWindowCtrlMain *)b->viewport)->get_field10()) - b->anchor[1];
    t = TWindowFukidasi__data_805DCD14 * (f32) rand();
    out[1] = t * h + y;
    return (u32) __cntlzw((u32) draw_resolved_window__15TWindowFukidasiFllll((Fuki_80250F70 *)b, out, b->anchor, 4)) >> 5;
}
#pragma pop

#pragma push
#pragma fp_contract on
struct Fuki_8025181C;
#define F70_80250A24 ((Fuki_80250F70 *)b)
#define CLAMP_80250A24 ((s32 (*)(Fuki_80250F70 *, f32 *, f32))clamp_position__13TUnk_804CF0B8FPvf)
#define DRAW_80250A24 ((void *(*)(Fuki_80250F70 *, f32 *, f32 *, s32))draw_resolved_window__15TWindowFukidasiFllll)

#pragma push
#pragma fp_contract on
struct Cam_80251380;
#define F70_802506E8 ((Fuki_80250F70 *)b)
#define CLAMP_802506E8 ((s32 (*)(Fuki_80250F70 *, f32 *, f32))clamp_position__13TUnk_804CF0B8FPvf)
#define DRAW_802506E8 ((void *(*)(Fuki_80250F70 *, f32 *, f32 *, s32))draw_resolved_window__15TWindowFukidasiFllll)
s32 try_place_bubble__15TWindowFukidasiFPvPvPv(Fuki_802506E8 *b, f32 *rect, f32 *o) {
    f32 world[3];
    f32 edge[2];
    f32 dx;
    f32 dy;
    f32 reach;
    s32 a;
    s32 angle;
    ((TUnk_804CF0B8 *)F70_802506E8)->project_anchor(world, NULL);
    reach = TWindowFukidasi__data_805DCD08 / xyz_distance((u8 *)camera_ctrl_instance + 0x178, world);
    dx = (TWindowFukidasi__data_805DCD0C * b->rsize[0] + rect[0]) - b->center[0];
    dy = (TWindowFukidasi__data_805DCD0C * b->rsize[1] + rect[1]) - b->center[1];
    a = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(dy, dx)));
    edge[0] = dx - reach * cos_table_lookup(a);
    edge[1] = dy - reach * sin_table_lookup(a);
    edge[0] /= TWindowFukidasi__data_805DCD18 + b->rsize[0];
    edge[1] /= TWindowFukidasi__data_805DCD1C + b->rsize[1];
    angle = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(edge[1], edge[0])));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle + 0x8000, edge);
    a = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o[0] = (b->center[0] + edge[0]) - TWindowFukidasi__data_805DCD0C * b->size[0];
    o[1] = (b->center[1] + edge[1]) - TWindowFukidasi__data_805DCD0C * b->size[1];
    if (CLAMP_802506E8(F70_802506E8, o, TWindowFukidasi__data_805DCCE8) != 0) {
        return 0;
    }
    if (DRAW_802506E8(F70_802506E8, o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) ((f32) a + (lbl_805DCD20 * (TWindowFukidasi__data_805DCD14 * (f32) rand()) - lbl_805DCD24));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o[0] = (b->center[0] + edge[0]) - TWindowFukidasi__data_805DCD0C * b->size[0];
    o[1] = (b->center[1] + edge[1]) - TWindowFukidasi__data_805DCD0C * b->size[1];
    if (CLAMP_802506E8(F70_802506E8, o, TWindowFukidasi__data_805DCCE8) != 0) {
        return 0;
    }
    return (u32) __cntlzw((u32) DRAW_802506E8(F70_802506E8, o, b->size, 4)) >> 5;
}
#pragma pop

s32 rest_balloon__15TWindowFukidasiFv(Fuki_80250A24 *b, f32 *rect, f32 *arg2) {
    Pt_80250A24 *o = (Pt_80250A24 *)arg2;
    f32 world[3];
    f32 edge[2];
    f32 dist;
    f32 dx;
    f32 dy;
    f32 reach;
    f32 t;
    s32 a;
    s32 angle;
    ((TUnk_804CF0B8 *)F70_80250A24)->project_anchor(world, NULL);
    reach = TWindowFukidasi__data_805DCD08 / xyz_distance(camera_ctrl_instance->pos, world);
    dx = (TWindowFukidasi__data_805DCD0C * b->rsize[0] + rect[0]) - b->center[0];
    dy = (TWindowFukidasi__data_805DCD0C * b->rsize[1] + rect[1]) - b->center[1];
    dist = newton_sqrtf(dx * dx + dy * dy);
    if (dist < TWindowFukidasi__data_805DCD28) {
        angle = 0xD400;
    } else {
        a = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(dy, dx)));
        edge[0] = dx - reach * cos_table_lookup(a);
        edge[1] = dy - reach * sin_table_lookup(a);
        edge[0] /= TWindowFukidasi__data_805DCD18 + b->rsize[0];
        edge[1] /= TWindowFukidasi__data_805DCD1C + b->rsize[1];
        angle = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(edge[1], edge[0])));
    }
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    if (fabs_float(dist - newton_sqrtf(edge[0] * edge[0] + edge[1] * edge[1])) < TWindowFukidasi__data_805DCD1C) {
        return 0;
    }
    o->x = (b->center[0] + edge[0]) - TWindowFukidasi__data_805DCD0C * b->size[0];
    o->y = (b->center[1] + edge[1]) - TWindowFukidasi__data_805DCD0C * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, TWindowFukidasi__data_805DCCE8) != 0) {
        return 0;
    }
    if (DRAW_80250A24(F70_80250A24, (f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    t = TWindowFukidasi__data_805DCD14 * (f32) rand();
    edge[0] += t * (dx - edge[0]);
    edge[1] += t * (dy - edge[1]);
    o->x = (b->center[0] + edge[0]) - TWindowFukidasi__data_805DCD0C * b->size[0];
    o->y = (b->center[1] + edge[1]) - TWindowFukidasi__data_805DCD0C * b->size[1];
    if (DRAW_80250A24(F70_80250A24, (f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) ((f32) a + (lbl_805DCD20 * (TWindowFukidasi__data_805DCD14 * (f32) rand()) - lbl_805DCD24));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o->x = (b->center[0] + edge[0]) - TWindowFukidasi__data_805DCD0C * b->size[0];
    o->y = (b->center[1] + edge[1]) - TWindowFukidasi__data_805DCD0C * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, TWindowFukidasi__data_805DCCE8) != 0) {
        return 0;
    }
    if (DRAW_80250A24(F70_80250A24, (f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) (lbl_805DCD2C * (TWindowFukidasi__data_805DCD14 * (f32) rand()));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (TWindowFukidasi__data_8044ED70 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o->x = (b->center[0] + edge[0]) - TWindowFukidasi__data_805DCD0C * b->size[0];
    o->y = (b->center[1] + edge[1]) - TWindowFukidasi__data_805DCD0C * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, TWindowFukidasi__data_805DCCE8) != 0) {
        return 0;
    }
    return (u32) __cntlzw((u32) DRAW_80250A24(F70_80250A24, (f32 *)o, b->size, 4)) >> 5;
}
#pragma pop

s32 shift_rect_with_head__15TWindowFukidasiFPvPvPv(Fuki_80250F70 *b, f32 *rect, f32 *out) {
    f32 x = b->head[0];
    f32 y = b->head[1];
    ((TUnk_804CF0B8 *)b)->project_anchor(0, b->head);
    out[0] = rect[0] + (b->head[0] - x);
    out[1] = rect[1] + (b->head[1] - y);
    ((TUnk_804CF0B8 *)b)->clamp_position(out, TWindowFukidasi__data_805DCCE8);
    if (draw_resolved_window__15TWindowFukidasiFllll(b, out, b->anchor, 4) == 0) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
void refresh_rect_placement__15TWindowFukidasiFPv(Fuki_80251028 *b) {
    if (((TUnk_804CF0B8 *)b)->is_speaker_far_or_offscreen() != 0) {
        f32 *m;
        if ((s8)b->slot == -1) {
            ((TUnk_804CF0B8 *)b)->set_flag();
            ((TUnk_804CF0B8 *)b)->set_flag2c_bit200();
            b->slot = ((TUnk_804CF0B8 *)b)->alloc_nearest_free_slot();
        }
        m = get_message_by_type__11TWindowCtrlFScl(b->slot, b->viewport);
        b->rect[0] = m[0] - TWindowFukidasi__data_805DCD0C * b->anchor[0];
        b->rect[1] = m[1] - TWindowFukidasi__data_805DCD0C * b->anchor[1];
        ((TUnk_804CF0B8 *)b)->clamp_position(b->rect, TWindowFukidasi__data_805DCCE8);
    } else {
        f32 a[2];
        f32 c[2];
        f32 d[2];
        f32 e[2];
        f32 *res;
        if ((s8)b->slot != -1) {
            ((TUnk_804CF0B8 *)b)->clear_visible_flag();
            ((TUnk_804CF0B8 *)b)->clear_flag2c_bit200();
            TWindowCtrl::release_slot((s8 *)&b->slot);
        }
        res = NULL;
        if (((TWindowFukidasi *)b)->is_bit10_set() == 0) {
            if (shift_rect_with_head__15TWindowFukidasiFPvPvPv((Fuki_80250F70 *)b, b->rect, a) != 0) {
                res = a;
            }
            if (rest_balloon__15TWindowFukidasiFv((Fuki_80250A24 *)(b), a, c) != 0) {
                res = c;
            }
        } else {
            ((TWindowFukidasi *)b)->hide();
            if (shift_rect_with_head__15TWindowFukidasiFPvPvPv((Fuki_80250F70 *)b, b->rect, a) != 0) {
                res = a;
            }
            if (try_place_bubble__15TWindowFukidasiFPvPvPv((Fuki_802506E8 *)(b), a, d) != 0) {
                res = d;
            }
            if (res != d && rest_balloon__15TWindowFukidasiFv((Fuki_80250A24 *)(b), d, c) != 0) {
                res = c;
            }
            if (res == NULL && TWindowFukidasi__sub_802505C0(b, b->rect, e) != 0) {
                res = e;
            }
        }
        if (res != NULL) {
            b->rect[0] = res[0];
            b->rect[1] = res[1];
        }
    }
}
#pragma pop

s32 TUnk_804CF0B8::project_anchor(f32 *pos, f32 *out) {
    Fuki_80250F70 *arg0 = (Fuki_80250F70 *)this;
    Fuki_802511E4 *b = (Fuki_802511E4 *)arg0;
    Ent_802511E4 *e;
    f32 tmp[3];

    if (b->id == 0xFFFF) {
        return 0;
    }
    e = find_entity_by_id(b->id);
    if (e == NULL) {
        return 0;
    }
    if (((u32 (*)(u16))get_player_by_client_id)(b->id) != 0 && get_battle_ctrl_flag__10TObjPlayerFUs(b->id) == 0) {
        return 0;
    }
    if (pos == NULL) {
        pos = tmp;
    }
    pos[0] = e->pos[0];
    pos[1] = e->pos[1] + b->height;
    pos[2] = e->pos[2];
    if (out == NULL) {
        return 1;
    }
    push_matrix();
    project_world_to_screen(0, pos, out);
    pop_matrix();
    if (is_split_screen() != 0) {
        out[0] -= (f32)get_screen_height__11TCameraCtrlFv();
        out[0] /= TCameraCtrl::get_view_scale();
        out[1] -= (f32)get_screen_width__11TCameraCtrlFv();
        out[1] /= TCameraCtrl::get_fov();
    }
    out[0] += TCameraCtrl__data_804FF634.x - lbl_805DCD34;
    out[1] += TCameraCtrl__data_804FF634.y - lbl_805DCD38;
    return 1;
}

#pragma push
#pragma fp_contract on
s32 TUnk_804CF0B8::is_speaker_far_or_offscreen() {
    Fuki_802504C0 *arg0 = (Fuki_802504C0 *)this;
    f32 pos[3];
    f32 scr[2];
    f32 m;
    f32 xx;
    f32 yy;
    f32 zz;
    clear_flag_20__13TUnk_804CF0B8Fv();
    if (project_anchor(pos, scr) == 0) {
        return 1;
    }
    if (((TUnk_804CF0B8 *)arg0)->is_flag_set() != 0) {
        m = lbl_805DCD3C;
    } else {
        m = TWindowFukidasi__data_805DCD30;
    }
    if (scr[0] < ((TWindowCtrlMain *)(((Fuki_80251380 *)arg0)->viewport))->get_position_z() - m) {
        return 1;
    }
    if (scr[1] < ((TWindowCtrlMain *)(((Fuki_80251380 *)arg0)->viewport))->get_field10() - m) {
        return 1;
    }
    if (scr[0] > m + ((TWindowCtrlMain *)(((Fuki_80251380 *)arg0)->viewport))->get_ctrl_field14()) {
        return 1;
    }
    if (scr[1] > m + ((TWindowCtrlMain *)(((Fuki_80251380 *)arg0)->viewport))->get_field_18()) {
        return 1;
    }
    Vec_80251380 v = fukidasi_forward_vec;
    f32 d[3];
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, camera_ctrl_instance->ry);
    rotate_matrix_x(0, camera_ctrl_instance->rx);
    rotate_matrix_z(0, camera_ctrl_instance->rz);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrix();
    d[0] = pos[0] - camera_ctrl_instance->pos[0];
    d[1] = pos[1] - camera_ctrl_instance->pos[1];
    d[2] = pos[2] - camera_ctrl_instance->pos[2];
    if (vec3_dot(&v, d) <= TWindowFukidasi__data_805DCD30) {
        return 1;
    }
    xx = d[0] * d[0];
    yy = d[1] * d[1];
    zz = d[2] * d[2];
    if (zz + (xx + yy) > lbl_805DCD44 * m + lbl_805DCD40) {
        return 1;
    }
    ((TUnk_804CF0B8 *)arg0)->sub_80252C68();
    return ((TUnk_804CF0B8 *)arg0)->get_flag_bit1() != 0 ? 1 : 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_804CF0B8::follow_anchor() {
    Fuki_80251594 *b = (Fuki_80251594 *)this;
    f32 cx;
    f32 cy;
    f32 dx;
    f32 dy;

    cx = TWindowFukidasi__data_805DCD0C * b->anchor[0] + b->rect[0];
    cy = TWindowFukidasi__data_805DCD0C * b->anchor[1] + b->rect[1];
    if (b->options & 0x40) {
        b->center[0] = cx;
        b->center[1] = cy;
    } else {
        dx = lbl_805DCD48 * (cx - b->center[0]);
        dy = lbl_805DCD48 * (cy - b->center[1]);
        if (fabs_float(dx) < TWindowFukidasi__data_805DCCF4) {
            b->center[0] = cx;
        } else {
            b->center[0] += dx;
        }
        if (fabs_float(dy) < TWindowFukidasi__data_805DCCF4) {
            b->center[1] = cy;
        } else {
            b->center[1] += dy;
        }
    }
    if (b->steps == 0) {
        b->size[0] = b->anchor[0];
        b->size[1] = b->anchor[1];
    } else {
        b->size[0] += (b->anchor[0] - b->size[0]) / (f32)b->steps;
        b->size[1] += (b->anchor[1] - b->size[1]) / (f32)b->steps;
        b->steps--;
    }
    b->pos[0] = b->center[0] - TWindowFukidasi__data_805DCD0C * b->size[0];
    b->pos[1] = b->center[1] - TWindowFukidasi__data_805DCD0C * b->size[1];
    ((TUnk_804CF0B8 *)b)->clamp_position(b->pos, b->margin);
    b->center[0] = TWindowFukidasi__data_805DCD0C * b->size[0] + b->pos[0];
    b->center[1] = TWindowFukidasi__data_805DCD0C * b->size[1] + b->pos[1];
    project_anchor(NULL, b->head);
}
#pragma pop

struct Fuki_80251790 {
    u8 pad0[0x20];
    s16 card_slot;
    u8 pad22[0x2C - 0x22];
    u32 flags;
    u8 pad30[0x5C - 0x30];
    s32 frame;
};

void TWindowFukidasi__sub_80251790(void *arg0) {
    Fuki_80251790 *b = (Fuki_80251790 *)arg0;
    u32 flags;

    if (((TUnk_804CF0B8 *)b)->is_active() != 0 && b->frame < 0x1000000) {
        b->frame += TWindowSubStatusDisp::get_card_window_flags(b->card_slot) + 1;
    }
    flags = b->flags;
    if ((flags & 2) && (!(flags & 1) || (flags & 4))) {
        b->flags &= ~4;
        ((TUnk_804CF0B8 *)b)->sub_802504A8();
    }
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::get_boundary_offset(s32 angle, f32 *out) {
    Fuki_8025181C *b = (Fuki_8025181C *)this;
    f32 ax;
    f32 ay;
    f32 kx;
    f32 ky;
    s32 neg;
    ax = TWindowFukidasi__data_805DCD0C * (TWindowFukidasi__data_805DCD0C * b->w + TWindowFukidasi__data_805DCD18);
    ay = TWindowFukidasi__data_805DCD0C * (TWindowFukidasi__data_805DCD0C * b->h + TWindowFukidasi__data_805DCD1C);
    out[0] = ax * cos_table_lookup(angle);
    out[1] = ay * sin_table_lookup(angle);
    if ((angle + 0x2000) & 0x4000) {
        kx = sin_table_lookup(angle - 0x4000) / cos_table_lookup(angle - 0x4000);
        if (!(angle & 0x8000)) {
            kx = -kx;
        }
        if (angle & 0x8000) {
            ky = TWindowFukidasi__data_805DCD4C;
        } else {
            ky = TWindowFukidasi__data_805DCCE8;
        }
    } else {
        neg = (angle + 0x2000) & 0x8000;
        if (neg) {
            kx = TWindowFukidasi__data_805DCD4C;
        } else {
            kx = TWindowFukidasi__data_805DCCE8;
        }
        ky = sin_table_lookup(angle) / cos_table_lookup(angle);
        if (neg) {
            ky = -ky;
        }
    }
    out[0] += ax * kx;
    out[1] += ay * ky;
}
#pragma pop

void TUnk_804CF0B8::set_color(u16 arg1) {
    this->m_84 = 0xFFF8F8F8;
    if (((u32)arg1 < 0xCU) && (get_player_by_client_id((u32)arg1) != 0U) && (obj_isState3_324__9TObjCharaFv() == 0)) {
        this->m_84 = (s32) TWindowFukidasi__balloon_color_table[(u16)arg1];
    }
}

#pragma push
#pragma fp_contract on
s32 TUnk_804CF0B8::clamp_position(void *arg1, f32 farg0) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    s32 var_r31;

    var_r31 = 0;
    temp_f1 = TWindowFukidasi__data_805DCCFC + ((TWindowCtrlMain *)(*(s16 *)&this->m_20))->get_position_z();
    if (*(f32 *)((s8 *)arg1 + 0) < temp_f1) {
        *(f32 *)((s8 *)arg1 + 0) = temp_f1;
        var_r31 = 1;
    }
    temp_f1_2 = (((TWindowCtrlMain *)(*(s16 *)&this->m_20))->get_ctrl_field14() - TWindowFukidasi__data_805DCCFC) - (this->m_48 * farg0);
    if (*(f32 *)((s8 *)arg1 + 0) > temp_f1_2) {
        *(f32 *)((s8 *)arg1 + 0) = temp_f1_2;
        var_r31 = 1;
    }
    temp_f1_3 = lbl_805DCD44 + ((TWindowCtrlMain *)(*(s16 *)&this->m_20))->get_field10();
    if (*(f32 *)((s8 *)arg1 + 4) < temp_f1_3) {
        *(f32 *)((s8 *)arg1 + 4) = temp_f1_3;
        var_r31 = 1;
    }
    temp_f1_4 = (((TWindowCtrlMain *)(*(s16 *)&this->m_20))->get_field_18() - lbl_805DCD44) - (*(f32 *)((s8 *)this + 0x4C) * farg0);
    if (*(f32 *)((s8 *)arg1 + 4) > temp_f1_4) {
        *(f32 *)((s8 *)arg1 + 4) = temp_f1_4;
        var_r31 = 1;
    }
    return var_r31;
}
#pragma pop

void open__15TWindowFukidasiFPvPvi(u8 *arg0, u32 *arg1, s32 arg2) {
    s32 var_r31;
    u8 temp_r0;

    var_r31 = 0;
    ((s32 (*)(void *, s32))init_flags__15TWindowFukidasiFPvi)(arg0, arg2);
    if ((u8) *(u8 *)((s8 *)arg0 + 0x72) != 1) {
        *(u8 *)((s8 *)arg0 + 0x72) = 1U;
        ((TWindowSubStatusDisp *)(arg0 + 0x24))->destroy_all_items();
        ((TWindowSubSymbolChat *)(arg0 + 0x24))->init_layout_entries(*(s16 *)((s8 *)arg0 + 0x20));
        if ((u8) *(u8 *)((s8 *)arg0 + 0x70) != 0) {
            var_r31 = 1;
        }
    } else {
        temp_r0 = *(u8 *)((s8 *)arg0 + 0x70);
        if ((temp_r0 != 0) && (temp_r0 != 4)) {
            var_r31 = 1;
        }
    }
    if (var_r31 != 0) {
        *(u8 *)((s8 *)arg0 + 0x70) = 5U;
        ((TUnk_804CF0B8 *)arg0)->clear_flag();
        if (TWindowSubStatusDisp::get_card_window_scale(*(s16 *)((s8 *)arg0 + 0x20)) > TWindowFukidasi__data_805DCD30) {
            *(s32 *)((s8 *)arg0 + 0x5C) = 0;
        }
    }
    set_symbol_chat_parts__20TWindowSubSymbolChatFiPv((s32)(arg0 + 0x24), (void *)arg1);
    TWindowSubSymbolChat::play_symbol_sound(((u32) *arg1 >> 5U) & 0xF);
    *(s16 *)((s8 *)arg0 + 0x74) = 0x5A;
}

#pragma push
#pragma fp_contract on
void set_text__15TWindowFukidasiFPvii(u8 *arg0, s32 str, s32 arg2) {
  u32 new_var;
  u8 *temp_r3;
  ((s32 (*)(void *, void *))init_flags__15TWindowFukidasiFPvi)((void *) arg0, (void *) arg2);
  ((TUnk_804CF0B8 *)arg0)->clear_flag();
  if (((u8) (*((u8 *) (((s8 *) arg0) + 0x72)))) != 0)
  {
    *((u8 *) (((s8 *) arg0) + 0x72)) = 0U;
    ((TWindowSubStatusDisp *)(arg0 + 0x24))->destroy_all_items();
    init_window_layout_entries(arg0 + 0x24, &window_fukidasi_layout_entries.value, (int) (*((s16 *) (((s8 *) arg0) + 0x20))));
  }
  temp_r3 = (u8 *) ((u8 * (*)(void *, s32))get_array_entry__11TWindowBaseFi)(arg0, 0);
  if (arg2 & 1)
  {
    set_text_entry_string(temp_r3, str, 0x20);
  }
  else
  {
    set_text_entry_string(temp_r3, str, 0);
  }
  if (arg2 & 4)
  {
    *((u16 *) (((s8 *) temp_r3) + 0)) = (u16) ((*((u16 *) (((s8 *) temp_r3) + 0))) | 0x40);
    refresh_status_display__9TWindowDDFv((int) temp_r3);
  }
  else
  {
    measure_message_text_width((int) temp_r3, (f32) lbl_805DCD50);
  }
  if (arg2 & 0x80)
  {
    *((u16 *) (((s8 *) temp_r3) + 0)) = (u16) ((*((u16 *) (((s8 *) temp_r3) + 0))) | 0x200);
  }
  else
  {
    *((u16 *) (((s8 *) temp_r3) + 0)) = (u16) ((*((u16 *) (((s8 *) temp_r3) + 0))) & 0xFFFFFDFF);
  }
  *((s32 *) (((s8 *) temp_r3) + 0x24)) = 0xFF000000;
  new_var = TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)(0x100));
  *((s16 *) (((s8 *) arg0) + 0x74)) = (s16) ((lbl_805DCCF0 * ((f32) new_var)) + lbl_805DCCEC);
  if (TWindowSubStatusDisp::get_card_window_scale((int) ((s32) (*((s16 *) (((s8 *) arg0) + 0x20))))) > TWindowFukidasi__data_805DCD30)
  {
    *((s32 *) (((s8 *) arg0) + 0x5C)) = 0;
  }
  play_sound_effect(0x53705, 0, 0, 0);
  if (((u8) (*((u8 *) (((s8 *) arg0) + 0x70)))) != 0)
  {
    *((u8 *) (((s8 *) arg0) + 0x70)) = 5U;
  }
}
#pragma pop

void init_flags__15TWindowFukidasiFPvi(void *arg0, s32 arg1) {
    ((TUnk_804CF0B8 *)arg0)->m_58 = (f32) TWindowFukidasi__data_805DCD30;
    set_depth__11TWindowBaseFf(lbl_805DCD58);
    if (sub_80246948__11TWindowBaseFv(arg0) != 0) {
        ((TUnk_804CF0B8 *)arg0)->m_2c = (s32) (((TUnk_804CF0B8 *)arg0)->m_2c | 1);
    }
    ((TUnk_804CF0B8 *)arg0)->m_71 = (u8) (((TUnk_804CF0B8 *)arg0)->m_71 & ~0x50);
    if (arg1 & 2) {
        ((TUnk_804CF0B8 *)arg0)->m_71 = (u8) (((TUnk_804CF0B8 *)arg0)->m_71 | 8);
    } else {
        ((TUnk_804CF0B8 *)arg0)->m_71 = (u8) (((TUnk_804CF0B8 *)arg0)->m_71 & 0xFFFFFFF7);
    }
    if (arg1 & 0x20) {
        ((TUnk_804CF0B8 *)arg0)->m_71 = (u8) (((TUnk_804CF0B8 *)arg0)->m_71 | 2);
        ((TUnk_804CF0B8 *)arg0)->set_flag();
        ((TUnk_804CF0B8 *)arg0)->set_flag2c_bit200();
        ((TUnk_804CF0B8 *)arg0)->m_73 = 4;
        return;
    }
    ((TUnk_804CF0B8 *)arg0)->m_71 = (u8) (((TUnk_804CF0B8 *)arg0)->m_71 & 0xFFFFFFFD);
}

void TUnk_804CF0B8::sub_80251DF0(s16 arg1, s32 str, s16 arg3, f32 farg0) {
    s32 temp_r3;

    *(s32 *)((s8 *)this + 0) = (s32) window_fukidasi_class_name;
    this->m_70 = 0;
    this->m_71 = 0;
    *(s8 *)&this->unk_72 = 2;
    this->m_73 = -1;
    this->m_76 = arg1;
    this->m_20 = arg3;
    if (str != 0) {
        temp_r3 = TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)0x18);
        *(s32 *)((s8 *)this + 0x78) = (s32)mem_alloc(temp_r3 + 1);
        strncpy(*(s32 *)((s8 *)this + 0x78), str, temp_r3 + 1);
    } else {
        *(s32 *)((s8 *)this + 0x78) = 0;
    }
    ((s32 (*)(void *, s16))set_color__13TUnk_804CF0B8FUs)(this, arg1);
    *(f32 *)((s8 *)this + 0x80) = (f32) TWindowFukidasi__data_805DCD30;
    this->m_7c = farg0;
    this->m_48 = (f32) TWindowFukidasi__data_805DCD30;
    *(f32 *)((s8 *)this + 0x4C) = (f32) TWindowFukidasi__data_805DCD30;
    this->clear_flag();
    this->clear_flag2c_bit100();
}

#pragma push
#pragma fp_contract on
void TUnk_804CF0B8::draw_tail(void *view, u32 color, f32 *off, f32 depth) {
    f32 verts[6];
    f32 pos[3];
    Prim_802521E8 prim;
    u32 colors[3];
    f32 scr[2];
    f32 cx;
    f32 cy;
    f32 x0;
    f32 s;
    f32 y0;
    s32 angle;
    if (this->is_balloon_visible() != 0) {
        this->project_anchor(pos, scr);
        cx = ((Fuki_802521E8 *)this)->center[0];
        cy = ((Fuki_802521E8 *)this)->center[1];
        angle = TWindowFukidasi__data_8044ED70 * atan2_float(cy - scr[1], cx - scr[0]);
        s = TWindowFukidasi__data_805DCD08 / xyz_distance((*(u8 * *)&camera_ctrl_instance) + 0x178, pos);
        x0 = s * cos_table_lookup(angle) + scr[0];
        y0 = s * sin_table_lookup(angle) + scr[1];
        prim.verts = verts;
        prim.flags = 0;
        prim.colors = colors;
        prim.count = 3;
        colors[2] = colors[1] = colors[0] = (color << 8) | (color >> 24);
        verts[0] = x0;
        verts[1] = y0;
        verts[2] = off[0] + (((Fuki_802521E8 *)this)->tail * (lbl_805DCD78 * cos_table_lookup(angle + 0x4000)) + cx);
        verts[3] = off[1] + (((Fuki_802521E8 *)this)->tail * (lbl_805DCD78 * sin_table_lookup(angle + 0x4000)) + cy);
        verts[4] = off[0] + (((Fuki_802521E8 *)this)->tail * (lbl_805DCD78 * cos_table_lookup(angle - 0x4000)) + cx);
        verts[5] = off[1] + (((Fuki_802521E8 *)this)->tail * (lbl_805DCD78 * sin_table_lookup(angle - 0x4000)) + cy);
        ((TObjCMHairMenu *)(&prim))->draw_tri_fan_2d(3, 2, lbl_805DCD90 + ((Fuki_802521E8 *)this)->f54);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_804CF0B8::draw_body_row(void *s, void *ctx, f32 offsetX, f32 rowTop, f32 fullWidth, f32 rowHeight) {
    f32 left;
    f32 cap;
    f32 w;

    if (fullWidth < 64.0f) {
        cap = 0.5f * fullWidth;
    } else {
        cap = 32.0f;
    }
    left = offsetX + (((Fuki_802523CC *)this)->x - 0.342f * rowTop);

    ((Slice_802523CC *)s)->x = left;
    ((Slice_802523CC *)s)->width = cap;
    ((Slice_802523CC *)s)->lean = 0.342f * -rowHeight;
    ((Slice_802523CC *)s)->u = 0.3828125f;
    ((Slice_802523CC *)s)->uw = cap / 256.0f;
    ((Slice_802523CC *)s)->x = ((Ctx_802523CC *)ctx)->pivot + ((Ctx_802523CC *)ctx)->scale * (((Slice_802523CC *)s)->x - ((Ctx_802523CC *)ctx)->pivot);
    ((Slice_802523CC *)s)->width *= ((Ctx_802523CC *)ctx)->scale;
    ((Slice_802523CC *)s)->lean *= ((Ctx_802523CC *)ctx)->scale;
    DVDConvertEntrynumToPath((f32 *)((Slice_802523CC *)s));
    ((Slice_802523CC *)s)->x = left + fullWidth - cap;
    ((Slice_802523CC *)s)->x = ((Ctx_802523CC *)ctx)->pivot + ((Ctx_802523CC *)ctx)->scale * (((Slice_802523CC *)s)->x - ((Ctx_802523CC *)ctx)->pivot);
    ((Slice_802523CC *)s)->u = (194.0f - cap) / 256.0f;
    DVDConvertEntrynumToPath((f32 *)((Slice_802523CC *)s));
    w = (fullWidth - 64.0f) * ((Ctx_802523CC *)ctx)->scale;
    if (w >= 0.0f) {
        ((Slice_802523CC *)s)->x = 32.0f + left;
        ((Slice_802523CC *)s)->x = ((Ctx_802523CC *)ctx)->pivot + ((Ctx_802523CC *)ctx)->scale * (((Slice_802523CC *)s)->x - ((Ctx_802523CC *)ctx)->pivot);
        ((Slice_802523CC *)s)->width = w;
        ((Slice_802523CC *)s)->u = 0.5078125f;
        DVDConvertEntrynumToPath((f32 *)((Slice_802523CC *)s));
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_804CF0B8::draw_body(void *ctx, u32 argb, f32 *offset, f32 depth) {
    struct Slice_80252558 s;
    f32 width;
    f32 capY;
    f32 mid;
    f32 d;
    f32 t;
    width = ((struct Fukidasi_80252558 *)this)->size[0] + lbl_805DCD9C * ((struct Fukidasi_80252558 *)this)->size[1];
    s.f10 = 0.0f;
    s.f2c = 0.0f;
    s.f30 = 0.0f;
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)lbl_805D63F0);
    set_draw_texture_and_color(1, argb);
    if (((struct Fukidasi_80252558 *)this)->size[1] < lbl_805DCD98) {
        capY = TWindowFukidasi__data_805DCD0C * ((struct Fukidasi_80252558 *)this)->size[1];
    } else {
        capY = lbl_805DCD94;
    }
    s.z = TWindowFukidasi__data_805DCD4C / depth;
    s.y = ((struct Fukidasi_80252558 *)this)->position[1] + offset[1];
    s.rowHeight = capY;
    s.v = 0.0f;
    s.vh = capY * lbl_805DCDA4;
    s.y = ((struct DrawCtx_80252558 *)ctx)->pivot[1] + ((struct DrawCtx_80252558 *)ctx)->scale[1] * (s.y - ((struct DrawCtx_80252558 *)ctx)->pivot[1]);
    s.rowHeight *= ((struct DrawCtx_80252558 *)ctx)->scale[1];
    draw_body_row(&s, ((struct DrawCtx_80252558 *)ctx), offset[0], 0.0f, width, capY);
    s.y = (((struct Fukidasi_80252558 *)this)->size[1] + (((struct Fukidasi_80252558 *)this)->position[1] + offset[1])) - capY;
    s.y = ((struct DrawCtx_80252558 *)ctx)->pivot[1] + ((struct DrawCtx_80252558 *)ctx)->scale[1] * (s.y - ((struct DrawCtx_80252558 *)ctx)->pivot[1]);
    t = lbl_805DCDB0 - capY;
    s.v = t * lbl_805DCDA4;
    draw_body_row(&s, ((struct DrawCtx_80252558 *)ctx), offset[0], ((struct Fukidasi_80252558 *)this)->size[1] - capY, width, capY);
    d = ((struct Fukidasi_80252558 *)this)->size[1] - lbl_805DCD98;
    mid = d * ((struct DrawCtx_80252558 *)ctx)->scale[1];
    if (mid >= TWindowFukidasi__data_805DCD30) {
        f32 y = lbl_805DCD94 + ((struct Fukidasi_80252558 *)this)->position[1];
        s.y = y + offset[1];
        s.y = ((struct DrawCtx_80252558 *)ctx)->pivot[1] + ((struct DrawCtx_80252558 *)ctx)->scale[1] * (s.y - ((struct DrawCtx_80252558 *)ctx)->pivot[1]);
        s.v = lbl_805DCDB4;
        s.rowHeight = mid;
        draw_body_row(&s, ((struct DrawCtx_80252558 *)ctx), offset[0], lbl_805DCD94, width, d);
    }
    TWindowSubStatusDisp::get_player();
}
#pragma pop

#pragma push
#pragma fp_contract on
void TUnk_804CF0B8::render() {
    f32 off[2];
    View_80252764 *v;
    switch (((Fuki_80252764 *)this)->phase) {
    case 0:
        ((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->project_anchor(NULL, ((Fuki_80252764 *)this)->head);
        this->place_rect_at_head_or_slot();
        ((Fuki_80252764 *)this)->center[0] = TWindowFukidasi__data_805DCD0C * ((Fuki_80252764 *)this)->anchor[0] + ((Fuki_80252764 *)this)->rect[0];
        ((Fuki_80252764 *)this)->center[1] = TWindowFukidasi__data_805DCD0C * ((Fuki_80252764 *)this)->anchor[1] + ((Fuki_80252764 *)this)->rect[1];
        ((Fuki_80252764 *)this)->phase = 1;
        break;
    case 2:
        ((void (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(this);
        break;
    case 4:
        ((void (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(this);
        break;
    case 6:
        ((void (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(this);
        break;
    case 8:
        this->place_rect_at_head_or_slot();
        break;
    case 9:
        break;
    }
    ((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->follow_anchor();
    v = get_draw_context__11TWindowBaseFPv(((Fuki_80252764 *)this));
    v->sx /= TCameraCtrl::get_view_scale();
    v->sy /= TCameraCtrl::get_fov();
    off[0] = TWindowFukidasi__data_805DCD28 * ((Fuki_80252764 *)this)->tail;
    off[1] = lbl_805DCDB8 * ((Fuki_80252764 *)this)->tail;
    draw_body((struct DrawCtx_80252558 *)(v), (u32)(0xFF000000), off, lbl_805DCDBC + ((Fuki_80252764 *)this)->f54);
    ((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->draw_tail(v, (u32)(0xFF000000), off, lbl_805DCDC0 + ((Fuki_80252764 *)this)->f54);
    off[0] = TWindowFukidasi__data_805DCD30;
    off[1] = TWindowFukidasi__data_805DCD30;
    draw_body((struct DrawCtx_80252558 *)(v), ((Fuki_80252764 *)this)->color, off, lbl_805DCDC0 + ((Fuki_80252764 *)this)->f54);
    ((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->draw_tail(v, ((Fuki_80252764 *)this)->color, off, lbl_805DCD90 + ((Fuki_80252764 *)this)->f54);
    if (((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->is_active() != 0) {
        draw_visible_window_entries(((Fuki_80252764 *)this), ((Fuki_80252764 *)this)->f24, v);
        draw_name_plate__15TWindowFukidasiFv(((Fuki_80252764 *)this), v, ((Fuki_80252764 *)this)->color);
    }
}
#pragma pop

void TWindowFukidasi::run_task() {
    u8 *arg0 = (u8 *)this;
  switch (*((u8 *) (((s8 *) arg0) + 0x70)))
  {
    case 1:
      ((TUnk_804CF0B8 *)arg0)->calc_text_size((f32 *)(((u8 *) arg0) + 0x38));
      *((s32 *) (((s8 *) arg0) + 0x50)) = 6;
      ((TUnk_804CF0B8 *)arg0)->clear_flag();
      ((TUnk_804CF0B8 *)arg0)->set_flag2c_bit100();
      *((u8 *) (((s8 *) arg0) + 0x70)) = 2U;
    case 2:
      if (approach(TWindowFukidasi__data_805DCCE8) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 3U;
    }
      sync_display_pos();
      break;
    case 3:
      TWindowFukidasi__sub_80252C38(arg0);
      ((TUnk_804CF0B8 *)arg0)->set_flag2c_bit100();
      *((u8 *) (((s8 *) arg0) + 0x70)) = 4U;
    case 4:
      if ((*((u8 *) (((s8 *) arg0) + 0x71))) & 8)
    {
      *((s16 *) (((s8 *) arg0) + 0x74)) = (s16) ((*((s16 *) (((s8 *) arg0) + 0x74))) - 1);
      *((f32 *) (((s8 *) arg0) + 0x58)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x58))) + TWindowFukidasi__data_805DCCF4);
      *((f32 *) (((s8 *) arg0) + 0x1C)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x1C))) + TWindowFukidasi__data_805DCCF4);
      if ((*((s16 *) (((s8 *) arg0) + 0x74))) < 0)
      {
        *((u8 *) (((s8 *) arg0) + 0x70)) = 7U;
      }
    }
      break;
    case 5:
      ((void (*)(void *, void *))clamp_text_size__15TWindowFukidasiFPvPv)(arg0, ((u8 *) arg0) + 0x38);
      *((s32 *) (((s8 *) arg0) + 0x50)) = 6;
      ((TUnk_804CF0B8 *)arg0)->clear_flag();
      ((TUnk_804CF0B8 *)arg0)->set_flag2c_bit100();
      *((u8 *) (((s8 *) arg0) + 0x70)) = 6U;
    case 6:
      if (approach(TWindowFukidasi__data_805DCD0C) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 1U;
    }
      sync_display_pos();
      break;
    case 7:
      ((TUnk_804CF0B8 *)arg0)->clear_flag();
      ((TUnk_804CF0B8 *)arg0)->clear_flag2c_bit100();
      *((s32 *) (((s8 *) arg0) + 0x2C)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x2C))) & 0xFFFFFFFE);
      *((u8 *) (((s8 *) arg0) + 0x71)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x71))) | 0x10);
      *((u8 *) (((s8 *) arg0) + 0x70)) = 8U;
    case 8:
      if (approach(TWindowFukidasi__data_805DCD30) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 9U;
    }
      sync_display_pos();
      break;
    case 9:
      queue_destruction__7TObjectFv(arg0);
      break;
  }
  TWindowFukidasi__sub_80251790(arg0);
  if (((TUnk_804CF0B8 *)arg0)->is_active() != 0)
  {
    ((TWindowBase *)arg0)->update_window_entry_list(((u8 *) arg0) + 0x24);
  }
}
}
