#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/base/TObjChara.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TUnk_804CF0B8.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowSubStatusDisp_800FBD74.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include <string.h>
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet_80247EFC.h"

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
f32 * get_message_by_type__11TWindowCtrlFScl(u8, int);
s32 clamp_position__13TUnk_804CF0B8FPvf(void *arg0, void *arg1, f32 farg0);
int rand(void);
f32 xyz_distance(void *, void *);
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

struct Cam_80251380 {
    u8 pad0[0x178];
    f32 pos[3];
    u8 pad184[0x190 - 0x184];
    s32 rx;
    s32 ry;
    s32 rz;
};

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
    f32 x;
    f32 y;
    u8 pad8[0x28 - 0x8];
    f32 sx;
    f32 sy;
    s32 fade_in;  // frame counter of the name plate fade (inferred)
    u8 pad34[0x38 - 0x34];
    f32 depth;
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
Ent_802511E4 * find_entity_by_id(u16);
s32 play_sound_effect(int, int, int, int);
s32 sub_80246948__11TWindowBaseFv(void *);
void TWindowSubSymbolChat__sub_802483F0(int a0, void *a1);
s32 draw_resolved_window__15TWindowFukidasiFllll(Fuki_80250F70 *, f32 *, f32 *, s32);
}

void complete_speech_balloon(u8 *arg0);
s32 is_speech_balloon_ready(u8 *arg0);
extern "C" {
void clamp_text_size__15TWindowFukidasiFPvPv(Fuki_80250314 *b, f32 *out);
s32 TWindowFukidasi__sub_802505C0(Fuki_80251028 *b, f32 *rect, f32 *out);
s32 shift_rect_with_head__15TWindowFukidasiFPvPvPv(Fuki_80250F70 *b, f32 *rect, f32 *out);
void refresh_rect_placement__15TWindowFukidasiFPv(Fuki_80251028 *b);
void set_color__13TUnk_804CF0B8FUs(void *arg0, u16 arg1);
void open__15TWindowFukidasiFPvPvi(u8 *arg0, u32 *arg1, s32 arg2);
void set_text__15TWindowFukidasiFPvii(u8 *arg0, saddr arg1, saddr arg2);
void init_flags__15TWindowFukidasiFPvi(void *arg0, s32 arg1);
void draw_name_plate__15TWindowFukidasiFv(TUnk_804CF0B8 *, View_80252764 *, u32);
void TWindowFukidasi__sub_80252C38(void *p);
s32 fn_80252CBC(void);
s32 reset_float_field__15TWindowHelpItemFv();
s32 measure_message_text_width(int, f32);
}

void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
extern "C" {
f32 vec3_dot(void *, void *);
void project_world_to_screen(s32, f32 *, f32 *);
void rotate_vector_by_matrix(saddr, void *, void *);
void rotate_matrix_y(s32, s32);
void rotate_matrix_z(s32, s32);
void rotate_matrix_x(s32, s32);
extern Cam_802511E4 TCameraCtrl__data_804FF634;
__declspec(section ".rodata") extern const char TWindowFukidasi__class_name_string[] = "TWindowFukidasi";
}

extern const u32 TWindowFukidasi__balloon_color_table[16] = {
    0xFFFFC8C8, 0xFFA2FF9D, 0xFFFBFFB5, 0xFFB0F8FF, 0xFFD1ADFF, 0xFFFFBF7C, 0xFFA5B6FB, 0xFFFFB99C,
    0xFF90D29B, 0xFF8BB5EE, 0xFFFFB5DA, 0xFFFFFF8C, 0xFFE6E8CA, 0xFFDEFFBD, 0xFFC6C2FF, 0xFFFFE1EB,
};

extern const Vec fukidasi_forward_vec = {0.0f, 0.0f, -1.0f};
struct WindowFukidasiLayoutEntries { s32 value; u32 remaining[8]; };
WindowFukidasiLayoutEntries window_fukidasi_layout_entries = {1, {1, 3, 0, 0, 0x3F000000, 0xFFFFFFFF, 0, 0}};
u32 window_fukidasi_addition_params[5] = {0, 0, 0x476A6000, 0, 0x7023};
extern u8 identity_matrix[];
const char *window_fukidasi_class_name = TWindowFukidasi__class_name_string;
extern Cam_80251380 *camera_ctrl_instance;
extern void *lbl_805D63F0;

#define F70_80250A24 ((Fuki_80250F70 *)b)
#define CLAMP_80250A24 ((s32 (*)(Fuki_80250F70 *, f32 *, f32))clamp_position__13TUnk_804CF0B8FPvf)
#define DRAW_80250A24 ((void *(*)(Fuki_80250F70 *, f32 *, f32 *, s32))draw_resolved_window__15TWindowFukidasiFllll)
#define F70_802506E8 ((Fuki_80250F70 *)b)
#define CLAMP_802506E8 ((s32 (*)(Fuki_80250F70 *, f32 *, f32))clamp_position__13TUnk_804CF0B8FPvf)
#define DRAW_802506E8 ((void *(*)(Fuki_80250F70 *, f32 *, f32 *, s32))draw_resolved_window__15TWindowFukidasiFllll)
extern "C" {
struct Fuki_80251790 {
    u8 pad0[0x20];
    s16 card_slot;
    u8 pad22[0x2C - 0x22];
    u32 flags;
    u8 pad30[0x5C - 0x30];
    s32 frame;
};

extern "C" s32 draw_small_font_string_clipped__FPfPCcUlf(f32 *pos, const char *s, u32 color, f32 width);
extern s32 __vt__13TUnk_804CF0B8[];
saddr get_zero_vec2();
}

void TUnk_804CF0B8::clear_flag2c_bit100() { this->window_flags &= 0xfffffeff; }

void TUnk_804CF0B8::set_flag2c_bit200() { this->window_flags |= 0x200; }

void TUnk_804CF0B8::clear_flag2c_bit200() { this->window_flags &= 0xfffffdff; }

void TUnk_804CF0B8::set_flag2c_bit100() { this->window_flags |= 0x100; }
extern "C" {
u8 *TWindowFukidasi__sub_80252B74(u8 *window_addition, s32 player, s32 str, s32 client, f32 farg0) {
    __ct__15TWindowAdditionFPUcsPUc(window_addition, (u8 *)window_fukidasi_addition_params, (s16)client, (u8 *)get_zero_vec2());
    *(void **)(window_addition + 0x18) = __vt__13TUnk_804CF0B8;
    sub_80251DF0__13TUnk_804CF0B8Fslsf(window_addition, player, str, client, farg0);
    return window_addition;
}
}

TUnk_804CF0B8::~TUnk_804CF0B8() {
    if (this->is_flag_set() != 0) {
        this->clear_visible_flag();
        TWindowCtrl::release_slot((s8 *)&this->m_73);
    }
    if ((uaddr)this->name != 0U) {
        mem_free(this->name);
        this->name = 0;
    }
}

void TUnk_804CF0B8::run_task() {
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
      if (((TWindowFukidasi *)arg0)->approach(1.0f) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 3U;
    }
      ((TWindowFukidasi *)arg0)->sync_display_pos();
      break;
    case 3:
      TWindowFukidasi__sub_80252C38(arg0);
      ((TUnk_804CF0B8 *)arg0)->set_flag2c_bit100();
      *((u8 *) (((s8 *) arg0) + 0x70)) = 4U;
    case 4:
      if ((*((u8 *) (((s8 *) arg0) + 0x71))) & 8)
    {
      *((s16 *) (((s8 *) arg0) + 0x74)) = (s16) ((*((s16 *) (((s8 *) arg0) + 0x74))) - 1);
      *((f32 *) (((s8 *) arg0) + 0x58)) += 0.1f;
      *((f32 *) (((s8 *) arg0) + 0x1C)) += 0.1f;
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
      if (((TWindowFukidasi *)arg0)->approach(0.5f) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 1U;
    }
      ((TWindowFukidasi *)arg0)->sync_display_pos();
      break;
    case 7:
      ((TUnk_804CF0B8 *)arg0)->clear_flag();
      ((TUnk_804CF0B8 *)arg0)->clear_flag2c_bit100();
      *((s32 *) (((s8 *) arg0) + 0x2C)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x2C))) & 0xFFFFFFFE);
      *((u8 *) (((s8 *) arg0) + 0x71)) = (u8) ((*((u8 *) (((s8 *) arg0) + 0x71))) | 0x10);
      *((u8 *) (((s8 *) arg0) + 0x70)) = 8U;
    case 8:
      if (((TWindowFukidasi *)arg0)->approach(0.0f) != 0)
    {
      *((u8 *) (((s8 *) arg0) + 0x70)) = 9U;
    }
      ((TWindowFukidasi *)arg0)->sync_display_pos();
      break;
    case 9:
      ((TObject *)arg0)->queue_destruction();
      break;
  }
  ((TUnk_804CF0B8 *)arg0)->sub_80251790();
  if (((TUnk_804CF0B8 *)arg0)->is_active() != 0)
  {
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(((u8 *) arg0) + 0x24));
  }
}

#pragma push
#pragma fp_contract on
void TUnk_804CF0B8::render() {
    f32 off[2];
    View_80252764 *v;
    switch (((Fuki_80252764 *)this)->phase) {
    case 0:
        ((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->project_anchor(NULL, ((Fuki_80252764 *)this)->head);
        this->place_rect_at_head_or_slot();
        ((Fuki_80252764 *)this)->center[0] = 0.5f * ((Fuki_80252764 *)this)->anchor[0] + ((Fuki_80252764 *)this)->rect[0];
        ((Fuki_80252764 *)this)->center[1] = 0.5f * ((Fuki_80252764 *)this)->anchor[1] + ((Fuki_80252764 *)this)->rect[1];
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
    v = reinterpret_cast<View_80252764 *>(get_draw_context());
    v->sx /= TCameraCtrl::get_view_scale();
    v->sy /= TCameraCtrl::get_fov();
    off[0] = 3.0f * ((Fuki_80252764 *)this)->tail;
    off[1] = 2.5f * ((Fuki_80252764 *)this)->tail;
    draw_body((struct DrawCtx_80252558 *)(v), (u32)(0xFF000000), off, 0.0299f + ((Fuki_80252764 *)this)->f54);
    ((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->draw_tail(v, (u32)(0xFF000000), off, 0.01495f + ((Fuki_80252764 *)this)->f54);
    off[0] = 0.0f;
    off[1] = 0.0f;
    draw_body((struct DrawCtx_80252558 *)(v), ((Fuki_80252764 *)this)->color, off, 0.01495f + ((Fuki_80252764 *)this)->f54);
    ((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->draw_tail(v, ((Fuki_80252764 *)this)->color, off, 0.04485f + ((Fuki_80252764 *)this)->f54);
    if (((TUnk_804CF0B8 *)((Fuki_80252764 *)this))->is_active() != 0) {
        draw_visible_window_entries(
            reinterpret_cast<const void *>(((Fuki_80252764 *)this)),
            reinterpret_cast<const WindowLayoutEntries *>(((Fuki_80252764 *)this)->f24),
            reinterpret_cast<WindowDrawContext *>(v));
        draw_name_plate__15TWindowFukidasiFv(this, v, ((Fuki_80252764 *)this)->color);
    }
}

void TUnk_804CF0B8::draw_body(void *ctx, u32 argb, f32 *offset, f32 depth) {
    struct Slice_80252558 s;
    f32 width;
    f32 capY;
    f32 mid;
    f32 d;
    f32 t;
    width = ((struct Fukidasi_80252558 *)this)->size[0] + 0.342f * ((struct Fukidasi_80252558 *)this)->size[1];
    s.f10 = 0.0f;
    s.f2c = 0.0f;
    s.f30 = 0.0f;
    begin_screen_draw(1);
    TObjFish::set_global_param((saddr)lbl_805D63F0);
    set_draw_texture_and_color(1, argb);
    if (((struct Fukidasi_80252558 *)this)->size[1] < 64.0f) {
        capY = 0.5f * ((struct Fukidasi_80252558 *)this)->size[1];
    } else {
        capY = 32.0f;
    }
    s.z = -1.0f / depth;
    s.y = ((struct Fukidasi_80252558 *)this)->position[1] + offset[1];
    s.rowHeight = capY;
    s.v = 0.0f;
    s.vh = capY / 256.0f;
    s.y = ((struct DrawCtx_80252558 *)ctx)->pivot[1] + ((struct DrawCtx_80252558 *)ctx)->scale[1] * (s.y - ((struct DrawCtx_80252558 *)ctx)->pivot[1]);
    s.rowHeight *= ((struct DrawCtx_80252558 *)ctx)->scale[1];
    draw_body_row(&s, ((struct DrawCtx_80252558 *)ctx), offset[0], 0.0f, width, capY);
    s.y = (((struct Fukidasi_80252558 *)this)->size[1] + (((struct Fukidasi_80252558 *)this)->position[1] + offset[1])) - capY;
    s.y = ((struct DrawCtx_80252558 *)ctx)->pivot[1] + ((struct DrawCtx_80252558 *)ctx)->scale[1] * (s.y - ((struct DrawCtx_80252558 *)ctx)->pivot[1]);
    t = 96.0f - capY;
    s.v = t / 256.0f;
    draw_body_row(&s, ((struct DrawCtx_80252558 *)ctx), offset[0], ((struct Fukidasi_80252558 *)this)->size[1] - capY, width, capY);
    d = ((struct Fukidasi_80252558 *)this)->size[1] - 64.0f;
    mid = d * ((struct DrawCtx_80252558 *)ctx)->scale[1];
    if (mid >= 0.0f) {
        f32 y = 32.0f + ((struct Fukidasi_80252558 *)this)->position[1];
        s.y = y + offset[1];
        s.y = ((struct DrawCtx_80252558 *)ctx)->pivot[1] + ((struct DrawCtx_80252558 *)ctx)->scale[1] * (s.y - ((struct DrawCtx_80252558 *)ctx)->pivot[1]);
        s.v = 0.125f;
        s.rowHeight = mid;
        draw_body_row(&s, ((struct DrawCtx_80252558 *)ctx), offset[0], 32.0f, width, d);
    }
    TWindowSubStatusDisp::get_player();
}

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
        angle = 10430.38043493439 * atan2_float(cy - scr[1], cx - scr[0]);
        s = 1000.0f / xyz_distance((*(u8 * *)&camera_ctrl_instance) + 0x178, pos);
        x0 = s * cos_table_lookup(angle) + scr[0];
        y0 = s * sin_table_lookup(angle) + scr[1];
        prim.verts = verts;
        prim.flags = 0;
        prim.colors = colors;
        prim.count = 3;
        colors[2] = colors[1] = colors[0] = (color << 8) | (color >> 24);
        verts[0] = x0;
        verts[1] = y0;
        verts[2] = off[0] + (((Fuki_802521E8 *)this)->tail * (12.0f * cos_table_lookup(angle + 0x4000)) + cx);
        verts[3] = off[1] + (((Fuki_802521E8 *)this)->tail * (12.0f * sin_table_lookup(angle + 0x4000)) + cy);
        verts[4] = off[0] + (((Fuki_802521E8 *)this)->tail * (12.0f * cos_table_lookup(angle - 0x4000)) + cx);
        verts[5] = off[1] + (((Fuki_802521E8 *)this)->tail * (12.0f * sin_table_lookup(angle - 0x4000)) + cy);
        draw_polygon_2d((NJS_POINT2COL *)&prim, 3, 2, 0.04485f + ((Fuki_802521E8 *)this)->f54);
    }
}

#pragma pop
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
extern "C" {
void draw_name_plate__15TWindowFukidasiFv(TUnk_804CF0B8 *self, View_80252764 *arg1, u32 arg2) {
  f32 pos[2];
  f32 q[8];
  f32 scale;
  f32 textW;
  s32 alpha;
  s32 alphaBits;
  s32 color;
  f32 new_var;
  void *name;
  name = self->name;
  if ((name != 0) && (arg1->fade_in >= 0))
  {
    textW = (f32) ((u32) get_name_text_width(name));
    if (arg1->fade_in < 6)
    {
      alpha = (s32) (0.16666667f * ((f32) ((s32) (arg1->fade_in * 0xFF))));
    }
    else
    {
      alpha = 0xFF;
    }
    alphaBits = alpha << 24;
    color = arg2 & 0xffffff;
    color |= alphaBits & 0xff000000;
    pos[0] = arg1->x - 11.0f;
    pos[1] = arg1->y - 10.0f;
    scale = -1.0f / (0.0598f + arg1->depth);
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, color);
    q[0] = pos[0];
    q[1] = pos[1];
    q[2] = 16.0f + q[0];
    q[3] = 19.0f + q[1];
    q[4] = 0.56640625f;
    q[5] = 0.92578125f;
    q[6] = 0.62890625f;
    q[7] = 1.0f;
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)q);
    draw_textured_quad_at_depth(q, scale);
    if (textW < 20.0f)
    {
      q[0] = 12.0f + ((20.0f + pos[0]) - 16.0f);
    }
    else
    {
      q[0] = 12.0f + ((pos[0] + textW) - 16.0f);
    }
    q[1] = pos[1];
    q[2] = 16.0f + q[0];
    q[3] = 19.0f + q[1];
    q[4] = 0.69140625f;
    q[5] = 0.92578125f;
    q[6] = 0.75390625f;
    q[7] = 1.0f;
    ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)q);
    draw_textured_quad_at_depth(q, scale);
    if (textW > 20.0f)
    {
      {
        f32 k = 16.0f;
        q[0] = (new_var = pos[0]) + k;
      }
      q[1] = pos[1];
      q[2] = 12.0f + ((new_var + textW) - 16.0f);
      q[3] = 19.0f + q[1];
      q[4] = 0.62890625f;
      q[5] = 0.92578125f;
      q[6] = 0.69140625f;
      q[7] = 1.0f;
      ((WindowDrawContext *)arg1)->transform_quad((TexturedQuad *)q);
      draw_textured_quad_at_depth(q, scale);
    }
    TWindowSubStatusDisp::get_player();
    pos[0] += 6.0f;
    if (textW < 20.0f)
    {
      pos[0] = (0.5f * (20.0f - textW)) + pos[0];
    }
    pos[1] += 3.0f;
    set_text_draw_params(reinterpret_cast<WindowDrawContext *>(arg1), 0, 1, -1.0f / (0.07475f + arg1->depth), 100000.0f);
    draw_small_font_string_clipped__FPfPCcUlf(pos, self->name, alphaBits, 1000000.0f);
  }
}
}

#pragma pop
extern "C" {
void TUnk_804CF0B8::sub_80251DF0(s16 arg1, saddr str, s16 arg3, f32 farg0) {
    u32 len;

    *(s32 *)((s8 *)this + 0) = (saddr) window_fukidasi_class_name;
    this->m_70 = 0;
    this->m_71 = 0;
    *(s8 *)&this->unk_72 = 2;
    this->m_73 = -1;
    this->m_76 = arg1;
    this->client_index = arg3;
    if (str != 0) {
        len = TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)0x18);
        this->name = (char *)mem_alloc(len + 1);
        strncpy(this->name, (const char *)str, len + 1);
    } else {
        this->name = 0;
    }
    ((s32 (*)(void *, s16))set_color__13TUnk_804CF0B8FUs)(this, arg1);
    this->frame_size[14] = 0.0f;
    this->m_7c = farg0;
    this->frame_size[0] = 0.0f;
    this->frame_size[1] = 0.0f;
    this->clear_flag();
    this->clear_flag2c_bit100();
}

void init_flags__15TWindowFukidasiFPvi(void *arg0, s32 arg1) {
    ((TUnk_804CF0B8 *)arg0)->m_58 = 0.0f;
    ((TWindowBase *)arg0)->set_depth(60000.0f);
    if (((TWindowBase *)arg0)->sub_80246948() != 0) {
        ((TUnk_804CF0B8 *)arg0)->window_flags = (s32) (((TUnk_804CF0B8 *)arg0)->window_flags | 1);
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

// Dead-stripped from the DOL: no code of it survives, only its literal (1e6 at
// 0x805DCD54, pooled between set_text's 200 and init_flags's 60000). It measures a
// text entry the way set_text does but without its 200 wrap width, using the
// 1e6 "no limit" width draw_name_plate clips names with. Name inferred from that role.
void TUnk_804CF0B8::measure_text_unbounded(int entry) {
    measure_message_text_width(entry, 1000000.0f);
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void set_text__15TWindowFukidasiFPvii(u8 *arg0, saddr str, saddr flags) {
  u32 new_var;
  u8 *entry;
  ((s32 (*)(void *, void *))init_flags__15TWindowFukidasiFPvi)((void *) arg0, (void *) flags);
  ((TUnk_804CF0B8 *)arg0)->clear_flag();
  if (((u8) (*((u8 *) (((s8 *) arg0) + 0x72)))) != 0)
  {
    *((u8 *) (((s8 *) arg0) + 0x72)) = 0U;
    reinterpret_cast<WindowLayoutEntries *>((arg0 + 0x24))->destroy_all_items();
    init_window_layout_entries(
        reinterpret_cast<WindowLayoutEntries *>(arg0 + 0x24),
        reinterpret_cast<const void *>(&window_fukidasi_layout_entries.value),
        (int) (*((s16 *) (((s8 *) arg0) + 0x20))));
  }
  entry = (u8 *) ((TWindowBase *)arg0)->get_array_entry(0);
  if (flags & 1)
  {
    set_text_entry_string(entry, str, 0x20);
  }
  else
  {
    set_text_entry_string(entry, str, 0);
  }
  if (flags & 4)
  {
    *((u16 *) (((s8 *) entry) + 0)) = (u16) ((*((u16 *) (((s8 *) entry) + 0))) | 0x40);
    measure_message_text_width_default(entry);
  }
  else
  {
    measure_message_text_width((saddr) entry, 200.0f);
  }
  if (flags & 0x80)
  {
    *((u16 *) (((s8 *) entry) + 0)) = (u16) ((*((u16 *) (((s8 *) entry) + 0))) | 0x200);
  }
  else
  {
    *((u16 *) (((s8 *) entry) + 0)) = (u16) ((*((u16 *) (((s8 *) entry) + 0))) & 0xFFFFFDFF);
  }
  *((s32 *) (((s8 *) entry) + 0x24)) = 0xFF000000;
  new_var = TWindowKeyBoardSoft::strnlen((s8 *)str, (u32)(0x100));
  *((s16 *) (((s8 *) arg0) + 0x74)) = (s16) ((3.3f * ((f32) new_var)) + 55.5f);
  if (TWindowSubStatusDisp::get_card_window_scale((int) ((s32) (*((s16 *) (((s8 *) arg0) + 0x20))))) > 0.0f)
  {
    *((s32 *) (((s8 *) arg0) + 0x5C)) = 0;
  }
  play_sound_effect(0x53705, 0, 0, 0);
  if (((u8) (*((u8 *) (((s8 *) arg0) + 0x70)))) != 0)
  {
    *((u8 *) (((s8 *) arg0) + 0x70)) = 5U;
  }
}
}

#pragma pop
extern "C" {
void open__15TWindowFukidasiFPvPvi(u8 *arg0, u32 *arg1, s32 flags) {
    s32 var_r31;
    u8 temp_r0;

    var_r31 = 0;
    ((s32 (*)(void *, s32))init_flags__15TWindowFukidasiFPvi)(arg0, flags);
    if ((u8) *(u8 *)((s8 *)arg0 + 0x72) != 1) {
        *(u8 *)((s8 *)arg0 + 0x72) = 1U;
        reinterpret_cast<WindowLayoutEntries *>((arg0 + 0x24))->destroy_all_items();
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
        if (TWindowSubStatusDisp::get_card_window_scale(*(s16 *)((s8 *)arg0 + 0x20)) > 0.0f) {
            *(s32 *)((s8 *)arg0 + 0x5C) = 0;
        }
    }
    set_symbol_chat_parts__20TWindowSubSymbolChatFiPv((saddr)(arg0 + 0x24), (void *)arg1);
    TWindowSubSymbolChat::play_symbol_sound(((u32) *arg1 >> 5U) & 0xF);
    *(s16 *)((s8 *)arg0 + 0x74) = 0x5A;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
s32 TUnk_804CF0B8::clamp_position(void *arg1, f32 farg0) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    s32 var_r31;

    var_r31 = 0;
    temp_f1 = 20.0f + TWindowCtrlMain::get_position_z(this->client_index);
    if (*(f32 *)((s8 *)arg1 + 0) < temp_f1) {
        *(f32 *)((s8 *)arg1 + 0) = temp_f1;
        var_r31 = 1;
    }
    temp_f1_2 = (TWindowCtrlMain::get_ctrl_field14(this->client_index) - 20.0f) - (this->frame_size[0] * farg0);
    if (*(f32 *)((s8 *)arg1 + 0) > temp_f1_2) {
        *(f32 *)((s8 *)arg1 + 0) = temp_f1_2;
        var_r31 = 1;
    }
    temp_f1_3 = 40.0f + TWindowCtrlMain::get_field10(this->client_index);
    if (*(f32 *)((s8 *)arg1 + 4) < temp_f1_3) {
        *(f32 *)((s8 *)arg1 + 4) = temp_f1_3;
        var_r31 = 1;
    }
    temp_f1_4 = (TWindowCtrlMain::get_field_18(this->client_index) - 40.0f) - (this->frame_size[1] * farg0);
    if (*(f32 *)((s8 *)arg1 + 4) > temp_f1_4) {
        *(f32 *)((s8 *)arg1 + 4) = temp_f1_4;
        var_r31 = 1;
    }
    return var_r31;
}
}

#pragma pop
extern "C" {
void TUnk_804CF0B8::set_color(u16 arg1) {
    this->m_84 = 0xFFF8F8F8;
    TObjChara *chara;
    if (((u32)arg1 < 0xCU) && ((chara = get_player_by_client_id((u32)arg1)) != 0) && (chara->obj_isState3_324() == 0)) {
        this->m_84 = (s32) TWindowFukidasi__balloon_color_table[(u16)arg1];
    }
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void TWindowFukidasi::get_boundary_offset(s32 angle, f32 *out) {
    Fuki_8025181C *b = (Fuki_8025181C *)this;
    f32 ax;
    f32 ay;
    f32 kx;
    f32 ky;
    s32 neg;
    ax = 0.5f * (0.5f * b->w + 14.0f);
    ay = 0.5f * (0.5f * b->h + 10.0f);
    out[0] = ax * cos_table_lookup(angle);
    out[1] = ay * sin_table_lookup(angle);
    if ((angle + 0x2000) & 0x4000) {
        kx = sin_table_lookup(angle - 0x4000) / cos_table_lookup(angle - 0x4000);
        if (!(angle & 0x8000)) {
            kx = -kx;
        }
        if (angle & 0x8000) {
            ky = -1.0f;
        } else {
            ky = 1.0f;
        }
    } else {
        neg = (angle + 0x2000) & 0x8000;
        if (neg) {
            kx = -1.0f;
        } else {
            kx = 1.0f;
        }
        ky = sin_table_lookup(angle) / cos_table_lookup(angle);
        if (neg) {
            ky = -ky;
        }
    }
    out[0] += ax * kx;
    out[1] += ay * ky;
}
}

#pragma pop
extern "C" {
void TUnk_804CF0B8::sub_80251790() {
    Fuki_80251790 *b = (Fuki_80251790 *)this;
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
}

#pragma push
#pragma fp_contract on
extern "C" {
void TUnk_804CF0B8::follow_anchor() {
    Fuki_80251594 *b = (Fuki_80251594 *)this;
    f32 cx;
    f32 cy;
    f32 dx;
    f32 dy;

    cx = 0.5f * b->anchor[0] + b->rect[0];
    cy = 0.5f * b->anchor[1] + b->rect[1];
    if (b->options & 0x40) {
        b->center[0] = cx;
        b->center[1] = cy;
    } else {
        dx = 0.21f * (cx - b->center[0]);
        dy = 0.21f * (cy - b->center[1]);
        if (fabs_float(dx) < 0.1f) {
            b->center[0] = cx;
        } else {
            b->center[0] += dx;
        }
        if (fabs_float(dy) < 0.1f) {
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
    b->pos[0] = b->center[0] - 0.5f * b->size[0];
    b->pos[1] = b->center[1] - 0.5f * b->size[1];
    ((TUnk_804CF0B8 *)b)->clamp_position(b->pos, b->margin);
    b->center[0] = 0.5f * b->size[0] + b->pos[0];
    b->center[1] = 0.5f * b->size[1] + b->pos[1];
    project_anchor(NULL, b->head);
}

s32 TUnk_804CF0B8::is_speaker_far_or_offscreen() {
    Fuki_802504C0 *arg0 = (Fuki_802504C0 *)this;
    f32 pos[3];
    f32 scr[2];
    f32 m;
    f32 xx;
    f32 yy;
    f32 zz;
    clear_flag_20();
    if (project_anchor(pos, scr) == 0) {
        return 1;
    }
    if (((TUnk_804CF0B8 *)arg0)->is_flag_set() != 0) {
        m = -50.0f;
    } else {
        m = 0.0f;
    }
    if (scr[0] < TWindowCtrlMain::get_position_z(((Fuki_80251380 *)arg0)->viewport) - m) {
        return 1;
    }
    if (scr[1] < TWindowCtrlMain::get_field10(((Fuki_80251380 *)arg0)->viewport) - m) {
        return 1;
    }
    if (scr[0] > m + TWindowCtrlMain::get_ctrl_field14(((Fuki_80251380 *)arg0)->viewport)) {
        return 1;
    }
    if (scr[1] > m + TWindowCtrlMain::get_field_18(((Fuki_80251380 *)arg0)->viewport)) {
        return 1;
    }
    Vec v = fukidasi_forward_vec;
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
    if (vec3_dot(&v, d) <= 0.0f) {
        return 1;
    }
    xx = d[0] * d[0];
    yy = d[1] * d[1];
    zz = d[2] * d[2];
    if (zz + (xx + yy) > 40.0f * m + 14400.0f) {
        return 1;
    }
    ((TUnk_804CF0B8 *)arg0)->sub_80252C68();
    return ((TUnk_804CF0B8 *)arg0)->get_flag_bit1() != 0 ? 1 : 0;
}
}

#pragma pop
extern "C" {
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
    if (get_player_by_client_id(b->id) != 0 && (u32)TObjPlayer::get_battle_ctrl_flag(b->id) == 0) {
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
        out[0] -= (f32)TCameraCtrl::get_screen_height();
        out[0] /= TCameraCtrl::get_view_scale();
        out[1] -= (f32)TCameraCtrl::get_screen_width();
        out[1] /= TCameraCtrl::get_fov();
    }
    out[0] += TCameraCtrl__data_804FF634.x - 320.0f;
    out[1] += TCameraCtrl__data_804FF634.y - 240.0f;
    return 1;
}

// Dead-stripped from the DOL: no code of it survives, only its literal (0.0 at
// 0x805DCD30, pooled between rest_balloon's 65536 and project_anchor's 320). It
// clears the width sub_80251DF0 zeroes when it sets the balloon up. Name inferred
// from that role.
void TUnk_804CF0B8::clear_width() {
    frame_size[0] = 0.0f;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
void refresh_rect_placement__15TWindowFukidasiFPv(Fuki_80251028 *b) {
    if (((TUnk_804CF0B8 *)b)->is_speaker_far_or_offscreen() != 0) {
        f32 *m;
        if ((s8)b->slot == -1) {
            ((TUnk_804CF0B8 *)b)->set_flag();
            ((TUnk_804CF0B8 *)b)->set_flag2c_bit200();
            b->slot = ((TUnk_804CF0B8 *)b)->alloc_nearest_free_slot();
        }
        m = get_message_by_type__11TWindowCtrlFScl(b->slot, b->viewport);
        b->rect[0] = m[0] - 0.5f * b->anchor[0];
        b->rect[1] = m[1] - 0.5f * b->anchor[1];
        ((TUnk_804CF0B8 *)b)->clamp_position(b->rect, 1.0f);
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
}

#pragma pop
extern "C" {
s32 shift_rect_with_head__15TWindowFukidasiFPvPvPv(Fuki_80250F70 *b, f32 *rect, f32 *out) {
    f32 x = b->head[0];
    f32 y = b->head[1];
    ((TUnk_804CF0B8 *)b)->project_anchor(0, b->head);
    out[0] = rect[0] + (b->head[0] - x);
    out[1] = rect[1] + (b->head[1] - y);
    ((TUnk_804CF0B8 *)b)->clamp_position(out, 1.0f);
    if (TWindowFukidasi::draw_resolved_window((saddr)b, (saddr)out, (saddr)b->anchor, 4) == 0) {
        return 1;
    }
    return 0;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
s32 rest_balloon__15TWindowFukidasiFv(Fuki_80250A24 *b, f32 *rect, f32 *arg2) {
    NJS_POINT2 *o = (NJS_POINT2 *)arg2;
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
    reach = 1000.0f / xyz_distance(camera_ctrl_instance->pos, world);
    dx = (0.5f * b->rsize[0] + rect[0]) - b->center[0];
    dy = (0.5f * b->rsize[1] + rect[1]) - b->center[1];
    dist = newton_sqrtf(dx * dx + dy * dy);
    if (dist < 3.0f) {
        angle = 0xD400;
    } else {
        a = (s32) (10430.38043493439 * ((f64)atan2_float(dy, dx)));
        edge[0] = dx - reach * cos_table_lookup(a);
        edge[1] = dy - reach * sin_table_lookup(a);
        edge[0] /= 14.0f + b->rsize[0];
        edge[1] /= 10.0f + b->rsize[1];
        angle = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    }
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    if (fabs_float(dist - newton_sqrtf(edge[0] * edge[0] + edge[1] * edge[1])) < 10.0f) {
        return 0;
    }
    o->x = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o->y = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, 1.0f) != 0) {
        return 0;
    }
    if (DRAW_80250A24(F70_80250A24, (f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    t = 0.000030517578f * (f32) rand();
    edge[0] += t * (dx - edge[0]);
    edge[1] += t * (dy - edge[1]);
    o->x = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o->y = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (DRAW_80250A24(F70_80250A24, (f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) ((f32) a + (32768.0f * (0.000030517578f * (f32) rand()) - 16384.0f));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o->x = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o->y = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, 1.0f) != 0) {
        return 0;
    }
    if (DRAW_80250A24(F70_80250A24, (f32 *)o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) (65536.0f * (0.000030517578f * (f32) rand()));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o->x = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o->y = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_80250A24(F70_80250A24, (f32 *)o, 1.0f) != 0) {
        return 0;
    }
    return (u32) __cntlzw((uaddr) DRAW_80250A24(F70_80250A24, (f32 *)o, b->size, 4)) >> 5;
}
}

#pragma push
#pragma fp_contract on
extern "C" {
s32 try_place_bubble__15TWindowFukidasiFPvPvPv(Fuki_802506E8 *b, f32 *rect, f32 *o) {
    f32 world[3];
    f32 edge[2];
    f32 dx;
    f32 dy;
    f32 reach;
    s32 a;
    s32 angle;
    ((TUnk_804CF0B8 *)F70_802506E8)->project_anchor(world, NULL);
    reach = 1000.0f / xyz_distance((u8 *)camera_ctrl_instance + 0x178, world);
    dx = (0.5f * b->rsize[0] + rect[0]) - b->center[0];
    dy = (0.5f * b->rsize[1] + rect[1]) - b->center[1];
    a = (s32) (10430.38043493439 * ((f64)atan2_float(dy, dx)));
    edge[0] = dx - reach * cos_table_lookup(a);
    edge[1] = dy - reach * sin_table_lookup(a);
    edge[0] /= 14.0f + b->rsize[0];
    edge[1] /= 10.0f + b->rsize[1];
    angle = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle + 0x8000, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o[0] = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o[1] = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_802506E8(F70_802506E8, o, 1.0f) != 0) {
        return 0;
    }
    if (DRAW_802506E8(F70_802506E8, o, b->size, 4) == NULL) {
        return 1;
    }
    angle = (s32) ((f32) a + (32768.0f * (0.000030517578f * (f32) rand()) - 16384.0f));
    ((TWindowFukidasi *)b)->get_boundary_offset(angle, edge);
    a = (s32) (10430.38043493439 * ((f64)atan2_float(edge[1], edge[0])));
    edge[0] += reach * cos_table_lookup(a);
    edge[1] += reach * sin_table_lookup(a);
    o[0] = (b->center[0] + edge[0]) - 0.5f * b->size[0];
    o[1] = (b->center[1] + edge[1]) - 0.5f * b->size[1];
    if (CLAMP_802506E8(F70_802506E8, o, 1.0f) != 0) {
        return 0;
    }
    return (u32) __cntlzw((uaddr) DRAW_802506E8(F70_802506E8, o, b->size, 4)) >> 5;
}
}

#pragma pop
#undef F70_80250A24
#undef CLAMP_80250A24
#undef DRAW_80250A24
#undef F70_802506E8
#undef CLAMP_802506E8
#undef DRAW_802506E8
extern "C" {
s32 TWindowFukidasi__sub_802505C0(Fuki_80251028 *b, f32 *rect, f32 *out) {
    f32 x = TWindowCtrlMain::get_position_z(b->viewport);
    f32 w = (TWindowCtrlMain::get_ctrl_field14(b->viewport) - TWindowCtrlMain::get_position_z(b->viewport)) - b->anchor[0];
    f32 y;
    f32 h;
    f32 t;
    t = 0.000030517578f * (f32) rand();
    out[0] = t * w + x;
    y = TWindowCtrlMain::get_field10(b->viewport);
    h = (TWindowCtrlMain::get_field_18(b->viewport) - TWindowCtrlMain::get_field10(b->viewport)) - b->anchor[1];
    t = 0.000030517578f * (f32) rand();
    out[1] = t * h + y;
    return (u32) __cntlzw((u32) TWindowFukidasi::draw_resolved_window((saddr)b, (saddr)out, (saddr)b->anchor, 4)) >> 5;
}

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
        b->rect[0] = m[0] - 0.5f * b->anchor[0];
        b->rect[1] = m[1] - 0.5f * b->anchor[1];
        ((TUnk_804CF0B8 *)b)->clamp_position(b->rect, 1.0f);
    } else {
        f32 p[2];
        if ((s8)b->slot != -1) {
            ((TUnk_804CF0B8 *)b)->clear_visible_flag();
            ((TUnk_804CF0B8 *)b)->clear_flag2c_bit200();
            TWindowCtrl::release_slot((s8 *)&b->slot);
        }
        project_anchor((f32 *)(0), p);
        b->rect[0] = p[0] - 0.5f * b->anchor[0];
        b->rect[1] = p[1] - 0.5f * b->anchor[1];
    }
}
}

#pragma pop
extern "C" {
// Dead-stripped from the DOL: no code of it survives, only its literals (1000, 0.5
// and 19 at 0x805DCD08-0x805DCD13 and 10430.38 at 0x8044ED70), pooled between
// approach's 0.011 and TWindowFukidasi__sub_802505C0's 2^-15. It aims from the
// middle of the 19-unit name plate draw_name_plate puts on the balloon's top edge at
// the tail tip draw_tail places 1000/distance short of the speaker, with the
// same atan2 scale. Name inferred from that role.
s32 TUnk_804CF0B8::calc_name_plate_angle(f32 *world, f32 *scr, f32 *rect, f32 *size) {
    f32 reach = 1000.0f / xyz_distance(camera_ctrl_instance->pos, world);
    f32 dx = (0.5f * size[0] + rect[0]) - scr[0];
    f32 dy = ((0.5f * size[1] + rect[1]) - 19.0f) - (scr[1] - reach);
    return (s32) (10430.38043493439 * atan2_float(dy, dx));
}

void TUnk_804CF0B8::sub_802504A8() {
    if (!(this->m_71 & 0x10)) {
        this->m_70 = 7;
    }
}

s32 TWindowFukidasi::approach(f32 farg0) {
    f32 temp_f31;

    temp_f31 = 0.47f * (farg0 - *(f32 *)((s8 *)this + 0x80));
    if (fabs_float(temp_f31) < 0.011f) {
        *(f32 *)((s8 *)this + 0x80) = farg0;
        return 1;
    }
    *(f32 *)((s8 *)this + 0x80) = (f32) (*(f32 *)((s8 *)this + 0x80) + temp_f31);
    return 0;
}

void TWindowFukidasi::sync_display_pos() { *(f32*)((char*)this + 0x60) = *(f32*)((char*)this + 0x80); *(f32*)((char*)this + 0x64) = *(f32*)((char*)this + 0x80); }

void TUnk_804CF0B8::calc_text_size(f32 *out) {
    Entry_80250380 *e;
    switch (((Fuki_80250380 *)this)->kind) {
    case 0:
        e = (Entry_80250380 *)((TWindowBase *)this)->get_array_entry(0);
        out[0] = 0.1f + (8.0f + e->w);
        out[1] = 0.1f + (20.0f + e->h);
        break;
    case 1:
        TWindowSubSymbolChat__sub_802483F0((saddr)((Fuki_80250380 *)this)->entries, (void *)out);
        break;
    case 2:
        break;
    }
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
}

s32 TWindowFukidasi::check_card_match_enabled(saddr arg1) {
    if ((u8) *(u8 *)((s8 *)this + 0x72) != 0) {
        return 0;
    }
    return (u32) __cntlzw(strcmp((const char *)((TWindowSubComCard *)((TWindowBase *)this)->get_array_entry(0))->get_field_20(), (const char *)arg1)) >> 5;
}

#pragma push
#pragma fp_contract on
void TWindowFukidasi::rearm_balloon(saddr flags) {
    u32 n;

    if (((s32 (*)(void))sub_80246948__11TWindowBaseFv)() != 0) {
        *(s8 *)((s8 *)((u8 *)this) + 0x70) = 5;
    }
    ((s32 (*)(void *, void *))init_flags__15TWindowFukidasiFPvi)(this, (void *)flags);
    switch ((s32) (*(u8 *)((s8 *)((u8 *)this) + 0x72))) {
    case 0:
        n = TWindowKeyBoardSoft::strnlen((s8 *)(((TWindowSubComCard *)(void *)((TWindowBase *)this)->get_array_entry(0))->get_field_20()), (u32)0x100);
        *(s16 *)((s8 *)((u8 *)this) + 0x74) = (s16) ((3.3f * (f32) n) + 55.5f);
        break;
    case 1:
        *(s16 *)((s8 *)((u8 *)this) + 0x74) = 0x5A;
        break;
    case 2:
        break;
    }
}

#pragma pop
s32 is_speech_balloon_ready(u8 *window_base) {
    s32 t = *(window_base + 0x72);
    switch (t) {
    case 0:
        ((TWindowBase *)window_base)->get_array_entry(0);
        return fn_80252CBC();
    case 1:
    case 2:
        break;
    }
    return 0;
}

void complete_speech_balloon(u8 *arg0) {
    s32 t;
    *(s8 *)(arg0 + 0x70) = 4;
    *(u8 *)(arg0 + 0x71) |= 0x40;
    ((TUnk_804CF0B8 *)arg0)->calc_text_size((f32 *)(arg0 + 0x38));
    ((s32 (*)(void *))refresh_rect_placement__15TWindowFukidasiFPv)(arg0);
    TWindowFukidasi__sub_80252C38(arg0);
    ((TUnk_804CF0B8 *)arg0)->set_flag2c_bit100();
    ((TWindowBase *)arg0)->save_position();
    *(f32 *)(arg0 + 0x80) = 1.0f;
    ((TWindowFukidasi *)arg0)->sync_display_pos();
    *(s32 *)(arg0 + 0x5C) = 0x186A0;
    t = *(u8 *)(arg0 + 0x72);
    switch (t) {
    case 0:
        ((TWindowBase *)arg0)->get_array_entry(0);
        reset_float_field__15TWindowHelpItemFv();
        break;
    case 1:
    case 2:
        break;
    }
}
