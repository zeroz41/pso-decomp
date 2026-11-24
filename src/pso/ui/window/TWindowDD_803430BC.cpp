#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowDD_8034435C.h"
#include "pso/ui/window/WordSelectMessage.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/window/TWindowDD_80342428.h"
#include "pso/ui/window/TWindowDD_803424EC.h"
#include "pso/ui/window/TWindowDD_80347F34.h"
#include "pso/unk/text_8020C354.h"
#include "pso/ui/window/TWindowDD_80340EA8.h"

struct TWindowDD_803431C0 {
    u8 pad0[0x20];
    s32 depth;
    void *child[7];
    s32 ids[13];
    void *objs[5];
    s32 f88;
    s32 f8C;
    s32 f90;
    u8 pad94[0xB0 - 0x94];
    s32 index;
    u8 padB4[0xBC - 0xB4];
    s32 fBC;
    u8 padC0[0xC6 - 0xC0];
    s16 fC6;
};

struct TWindowDD_8034330C {
    u8 pad0[0x20];
    s32 depth;
    u8 *child[7];
    s32 ids[13];
    void *objs[5];
    s32 f88;
    s32 f8C;
    s32 f90;
    u8 pad94[0xAC - 0x94];
    s32 fAC;
    s32 index;
    u8 padB4[0xBC - 0xB4];
    s32 fBC;
    u8 fC0[4];
    u8 fC4[4];
};

struct Sub_803438C4 { u8 pad[0x50]; u32 x50; };

struct Win_803438C4 {
    u8 pad0[0x1C];
    u8 input[4];
    s32 idx;
    Sub_803438C4 *subs[(0x7C - 0x24) / 4];
    uaddr x7C;
    uaddr x80;
    u8 pad84[0x94 - 0x84];
    s32 x94;
    u8 pad98[0xA8 - 0x98];
    s32 xA8;
    s32 xAC;
    s32 xB0;
    u8 padB4[0xB8 - 0xB4];
    s32 xB8;
    u8 padBC[0xC0 - 0xBC];
    void *xC0;
    s16 xC4;
    u8 padC6[0xE0 - 0xC6];
    s16 xE0;
};

struct R_80343BC0 { s16 a; s16 b; u32 w[6]; };

struct Win_80343C64
{
  u8 pad0[0x30];
  f32 f30;
  f32 f34;
  f32 f38;
  u8 pad3C[4];
  f32 f40;
  f32 f44;
  f32 f48;
};

struct Obj_80343C64
{
  const char *m_name; // TObject::m_name
  u8 pad4[0x14];
  void *vt;
  s16 f1C;
  u8 pad1E[2];
  s32 f20;
  saddr a24[8];
  s32 a44[8];
  s32 a64[6];
  s32 f7C;
  s32 f80;
  s32 f84;
  s32 f88;
  s32 f8C;
  s32 f90;
  s32 f94;
  s32 f98;
  s32 f9C;
  s32 fA0;
  s32 fA4;
  s32 fA8;
  s32 fAC;
  s32 fB0;
  s32 fB4;
  s32 fB8;
  s32 fBC;
  void *fC0;
  u8 fC4[0x1C];
  u8 fE0[0x1C];
  s16 fFC;
  u8 padFE[2];
  s32 f100;
  s32 f104;
};

#include <stddef.h>
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/player/PlayerSlots.h"

struct NumberWindow;

struct WordSelectPage;

struct WordSelectWindowState {
    u8 unknown00[0x20];
    s32 activePage;
    WordSelectPage* pages[7];
    u8 unknown40[0x84 - 0x40];
    NumberWindow* numberWindow;
};

struct WindowPosition { f32 x, y; };

s32 TWindowDD__window_mode;

uaddr TWindowDD__work_buffer;

char *window_dd_buffer_a;

char *window_dd_buffer_b;

uaddr TWindowDD__player_name_buffers;

uaddr TWindowDD__word_select_lists;

uaddr lbl_805D6E20;

s16 lbl_805D6E24;

char **TWindowDD__data_805D6E28;

TWindowDDValueList *TWindowDD__ws_data_base;

TWindowDDValueList *TWindowDD__ws_data_table;

u32 lbl_805D6E34;
extern "C" {
s32 apply_input__9TWindowDDFPvPv(int, int);
s32 update__9TWindowDDFl(int, int, int);
void TWindowDD__sub_803434F4(u8 *arg0);
void TWindowDD__sub_80342800(u8 *arg0);
void update__9TWindowDDFi(saddr window_dd);
void TWindowDD__sub_803429B0(u8 *window_dd);
void TWindowDD__sub_80342D14(u8 *window_dd);
void run_state__9TWindowDDFPv(u8 *window_dd);
s16 TWindowDD__sub_8034214C(u8 *arg0);
void TWindowDD__sub_80347980(void *);
void pop_menu_level__9TWindowDDFPv(TWindowDD_803431C0 *window);
void TWindowDD__sub_80347CC8(void *, void *);
extern const s32 TWindowDD__data_805DFB50;

extern const f32 TWindowDD__data_805DFB74;

extern const f32 lbl_805DFB7C;

extern const f32 lbl_805DFB80;

extern const f32 lbl_805DFB88;

extern const f32 TWindowDD__data_805DFBFC;

extern const f32 lbl_805DFC0C;

extern const f32 TWindowDD__data_805DFC10;
void TWindowDD__sub_80347A4C(u8 *arg0, saddr arg1);
u8 *TWindowDD__sub_80347AD4(void *, s32, s32);
s32 TWindowDD__sub_80347E04(void *, int);
extern const f32 TWindowDD__data_805DFB6C;

extern const f32 lbl_805DFB90;
void TWindowDD__sub_803435A0(u8 *arg0);
s32 TWindowDD__sub_80341AE0(int);
s32 TWindowDD__sub_80341AF8(int);
s32 TWindowDD__sub_8034217C(int);
s32 TWindowDD__sub_803482B0(void *);
s32 TWindowDD__sub_803484C4(void *);
void copy_chat_entry__9TWindowDDFPvPv(R_80343BC0 *arg0, R_80343BC0 *arg1);
saddr TWindowDD__sub_80342384(s32 element_list, s32 rows);
s32 TWindowDD__sub_8034146C(NJS_POINT2 *pos, NJS_POINT2 *size, s32 arg2, s32 style, f32 width);
void TWindowDD__sub_803412A0(TWindowDD_WS_String *self);
const char *word_select_type_name_pointer = "TWindowDD";

extern s32 local_client_id;



extern char *lbl_805D6E64;

extern s8 lbl_805D6E68;

extern char *lbl_805D6E6C;

extern s8 lbl_805D6E70;

extern const f32 lbl_805DFB54;

extern const f32 lbl_805DFB60;

extern const f32 lbl_805DFB64;

extern const f32 lbl_805DFB68;

extern const f32 lbl_805DFBA4;

extern const f32 lbl_805DFBA8;

extern const f32 lbl_805DFBAC;

extern const f32 lbl_805DFBB0;

extern const f32 lbl_805DFBB4;

extern const f32 lbl_805DFBB8;

extern const f32 lbl_805DFBD0;

extern const f32 lbl_805DFBD4;

extern const f32 lbl_805DFBD8;

extern const f32 lbl_805DFBF0;

extern const f32 lbl_805DFBF4;

extern const f32 lbl_805DFBF8;


extern const f32 lbl_805DFB70, lbl_805DFC28;
void open_numeric_parameter_input__9TWindowDDFPviii(WordSelectWindowState* self, s32 minimum, s32 maximum, s32 initial);
void free_buffers__9TWindowDDFv(void);



s32 classify_id__9TWindowDDFs();
}


void clear_window_dd_nodes(void);
extern "C" {
NumberWindow* __ct__18TWindowInputNumberFPvllls(void* storage, const WindowPosition* position,
                                   s32 minimum, s32 maximum, s32 initial, s16 client);





extern uaddr ws_data_jp;

extern uaddr ws_data_us;

extern uaddr ws_data_es;

extern uaddr ws_data_de;

extern uaddr TWindowDD__ws_data_buffer;

typedef struct Obj_80343C64 Obj_80343C64;

typedef struct Win_80343C64 Win_80343C64;

struct WordList_80344114 { u8 *words; s32 count; };
extern "C++" void ws_data_load(void);


extern NJS_POINT2 TWindowDD__data_805434E8[][8];

extern const NJS_POINT2 window_dd_quad_positions[];

extern const f32 window_dd_quad_scales[];

extern const f32 TWindowDD__data_805DFB18;

extern const f32 lbl_805DFB24;

extern const f32 lbl_805DFB28;

#pragma push
#pragma opt_common_subs off
void TWindowDD__sub_80344114(void) {
    s32 i;
    u8 *list;
    s32 j;
    WordList_80344114 *entry;
    const NJS_POINT2 *src;
    NJS_POINT2 *pt;
    f32 x;
    f32 y;
    f32 x2;
    f32 dy;

    TWindowDD__data_805D6E28 = 0;
    TWindowDD__ws_data_base = 0;
    TWindowDD__ws_data_table = 0;
    lbl_805D6E34 = 0;
    TWindowDD__data_805D6E40 = 0;
    TWindowDD__data_805D6E44 = 0;
    TWindowDD__data_805D6E48 = 0;
    lbl_805D6E4C = 0;
    ws_data_jp = 0;
    ws_data_us = 0;
    ws_data_es = 0;
    ws_data_de = 0;
    TWindowDD__ws_data_buffer = 0;
    TWindowDD__window_mode = current_language;
    if (TWindowDD__window_mode < 0 || TWindowDD__window_mode >= 5) {
        TWindowDD__window_mode = 0;
    }
    ws_data_load();
    TWindowDD__work_buffer = (uaddr)mem_alloc(0x80);
    window_dd_buffer_a = (char *)mem_alloc(0x80);
    memset((void *)TWindowDD__work_buffer, 0, 0x80);
    memset(window_dd_buffer_a, 0, 0x80);
    window_dd_buffer_b = (char *)mem_alloc(0x120);
    memset(window_dd_buffer_b, 0, 0x120);
    TWindowDD__player_name_buffers = (uaddr)mem_alloc(0x30);
    for (i = 0; i < 12; i++) {
        ((char **)TWindowDD__player_name_buffers)[i] = window_dd_buffer_b + i * 0x18;
        ((char **)TWindowDD__player_name_buffers)[i][0] = 0;
    }
    lbl_805D6E20 = (uaddr)mem_alloc(0x100);
    TWindowDD__word_select_lists = (uaddr)mem_alloc(0x30);
    list = (u8 *)lbl_805D6E20;
    for (j = 0; j < 6; j++) {
        entry = &((WordList_80344114 *)TWindowDD__word_select_lists)[j];
        entry->words = list;
        entry->count = 0;
        switch (j) {
        case 0:
        case 1:
            list += 0x40;
            break;
        default:
            list += 0x20;
            break;
        }
    }
    lbl_805D6E24 = -1;
    for (i = 0; i < 6; i++) {
        src = &window_dd_quad_positions[i];
        ((TWindowDD *)(TWindowDD__data_805434E8[i]))->set_quad_corners_scaled(src->x, src->y, window_dd_quad_scales[i]);
    }
    pt = TWindowDD__data_805434E8[6];
    x2 = window_dd_quad_positions[6].x;
    y = window_dd_quad_positions[6].y;
    x = x2 * TWindowDD__data_805DFB18;
    y *= TWindowDD__data_805DFB18;
    x2 = TWindowDD__data_805DFB18 * (x2 + lbl_805DFB24);
    dy = lbl_805DFB28 * TWindowDD__data_805DFB18;
    for (i = 0; i < 4; i++) {
        pt[0].x = x;
        pt[0].y = y;
        pt[1].x = x2;
        pt[1].y = y;
        y += dy;
        pt += 2;
    }
    TWindowDD::init_ws_data_tables();
}

void free_buffers__9TWindowDDFv(void) {
    clear_window_dd_nodes();
    if ((u32) TWindowDD__word_select_lists != 0U) {
        mem_free((void*)TWindowDD__word_select_lists);
        TWindowDD__word_select_lists = 0U;
    }
    if ((u32) lbl_805D6E20 != 0U) {
        mem_free((void*)lbl_805D6E20);
        lbl_805D6E20 = 0U;
    }
    if ((u32) TWindowDD__player_name_buffers != 0U) {
        mem_free((void*)TWindowDD__player_name_buffers);
        TWindowDD__player_name_buffers = 0U;
    }
    if (window_dd_buffer_b != NULL) {
        mem_free(window_dd_buffer_b);
        window_dd_buffer_b = NULL;
    }
    if (window_dd_buffer_a != NULL) {
        mem_free(window_dd_buffer_a);
        window_dd_buffer_a = NULL;
    }
    if ((u32) TWindowDD__work_buffer != 0U) {
        mem_free((void*)TWindowDD__work_buffer);
        TWindowDD__work_buffer = 0U;
    }
    if ((u32) TWindowDD__ws_data_buffer != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)TWindowDD__ws_data_buffer));
        TWindowDD__ws_data_buffer = 0U;
    }
    if ((u32) ws_data_de != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)ws_data_de));
        ws_data_de = 0U;
    }
    if ((u32) ws_data_es != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)ws_data_es));
        ws_data_es = 0U;
    }
    if ((u32) ws_data_us != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)ws_data_us));
        ws_data_us = 0U;
    }
    if ((u32) ws_data_jp != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)ws_data_jp));
        ws_data_jp = 0U;
    }
}

#define self ((Obj_80343C64 *)this)
TWindowDD::TWindowDD(TObject *parent, void *arg2) : TObject(parent) {
  NJS_POINT2 a;
  NJS_POINT2 b;
  u8 *p;
  s32 floor;
  s32 v;
  self->m_name = word_select_type_name_pointer;
  self->f1C = (floor = lbl_805D6E24);
  build_item_list__9TWindowDDFPv(this);
  *((u8 *) TWindowDD__work_buffer) = 0;
  self->fA0 = 0;
  {
    p = (u8 *) get_player_by_client_id(local_client_id);
    if (p != 0)
    {
      floor = get_current_floor();
      s32 r;
      v = ((TObjBase *)p)->get_room();
      if (is_boss_area() != 0)
      {
        r = TWindowDD::check_all_ready(floor);
      }
      else
      {
        r = is_room_free_of_active_enemies(floor, v);
      }
      if (r == 0)
      {
        self->fA0 = 1;
      }
    }
  }
  TWindowDD::build_player_word_lists();
  self->fC0 = arg2;
  ((TWindowDD *)self->fC4)->init_item_slots();
  ((TWindowDD *)self->fE0)->init_item_slots();
  self->f7C = (saddr)TWindowDD__sub_80340F70();
  {
    s32 i;
    for (i = 0; i < 8; i++)
    {
      self->a24[i] = 0;
      self->a44[i] = 0;
    }
  }
  self->f20 = 0;
  self->f88 = TWindowDD__sub_80346DB8((saddr) self);
  self->f8C = -1;
  self->f90 = -1;
  {
    saddr w = TWindowDD__sub_80342384(self->f88, (s32) lbl_805DFB54);
    if (w != 0)
    {
      TWindowDD::set_default_positions(self, (TWindowDD_WS_Word *)w);
      self->a24[0] = w;
    }
  }
  self->a44[0] = 0;
  p = (u8 *) TWindowDD__sub_80342384(self->f8C, (s32) lbl_805DFB54);
  if (p != 0)
  {
    TWindowDD::init_layout(self, (TWindowDD_WS_Word *)p);
    self->a24[1] = (saddr) p;
  }
  if (!lbl_805D6E68)
  {
    lbl_805D6E64 = "SELECT";
    lbl_805D6E68 = 1;
  }
  if (!lbl_805D6E70)
  {
    lbl_805D6E6C = "NEXT";
    lbl_805D6E70 = 1;
  }
  {
    s32 i;
    for (i = 0; i < 6; i++)
    {
      self->a64[i] = 0;
    }
  }
  {
    a.x = lbl_805DFBA4;
    a.y = lbl_805DFBA8;
    b.x = lbl_805DFB60;
    b.y = lbl_805DFBA8;
    self->a64[0] = ((s32 (*)(f32, NJS_POINT2 *, NJS_POINT2 *, s32, s32)) TWindowDD__sub_8034146C)(lbl_805DFBAC, &a, &b, (saddr) lbl_805D6E64, 4);
  }
  {
    a.x = lbl_805DFBB0;
    a.y = lbl_805DFBB4;
    b.x = lbl_805DFB64;
    b.y = lbl_805DFBB4;
    self->a64[1] = ((s32 (*)(f32, NJS_POINT2 *, NJS_POINT2 *, s32, s32)) TWindowDD__sub_8034146C)(lbl_805DFBB8, &a, &b, (saddr) lbl_805D6E6C, 4);
  }
  {
    a.x = lbl_805DFBD0;
    a.y = lbl_805DFBD4;
    b.x = lbl_805DFBD0;
    b.y = lbl_805DFB68;
    void *q = (void *) ((saddr (*)(f32, NJS_POINT2 *, NJS_POINT2 *, s32, s32)) TWindowDD__sub_8034146C)(lbl_805DFBD8, &a, &b, get_word_select_token_text(0x687), 5);
    self->a64[2] = (saddr) q;
    if (q != 0)
    {
      TWindowDD__sub_803412A0((TWindowDD_WS_String *)q);
    }
  }
  TWindowDD::format_message(reinterpret_cast<WordSelectMessage *>(self->fC4), reinterpret_cast<char *>(TWindowDD__work_buffer), local_client_id);
  {
    a.x = lbl_805DFBF0;
    a.y = lbl_805DFBF4;
    b.x = lbl_805DFB60;
    b.y = lbl_805DFBF4;
    p = (u8 *) ((saddr (*)(f32, NJS_POINT2 *, NJS_POINT2 *, s32, s32)) TWindowDD__sub_8034146C)(lbl_805DFBF8, &a, &b, TWindowDD__work_buffer, 0);
    self->a64[3] = (saddr) p;
    if (p != 0)
    {
      TWindowDD__sub_803412A0((TWindowDD_WS_String *)p);
      ((TWindowDD_WS_String *)p)->update_position(0);
      ((Win_80343C64 *) p)->f30 = lbl_805DFB60;
      ((Win_80343C64 *) p)->f40 = lbl_805DFB60;
      ((Win_80343C64 *) p)->f34 = lbl_805DFBF4;
      ((Win_80343C64 *) p)->f44 = lbl_805DFBF4;
      ((Win_80343C64 *) p)->f38 = 2.0f;
      ((Win_80343C64 *) p)->f48 = 2.0f;
    }
  }
  self->f80 = (saddr)TWindowDD::create();
  self->f84 = 0;
  self->fA8 = 0;
  self->fAC = 0;
  self->fB0 = 0;
  self->fB4 = 0;
  self->fB8 = 0;
  self->fBC = 0;
  self->fFC = 0x37;
  self->f100 = 0;
  self->f94 = 0;
  self->f98 = 0;
  self->f9C = -1;
  self->fA4 = 0;
  self->f104 = 0;
}
#undef self

#pragma pop

TWindowDD::~TWindowDD() {
    close_all_windows();
}
}

#pragma push
#pragma optimization_level 1
extern "C" {
void copy_chat_entry__9TWindowDDFPvPv(R_80343BC0 *body, R_80343BC0 *arg1) {
    u32 a, b;
    body->a = arg1->a;
    body->b = arg1->b;
    b = arg1->w[0]; a = arg1->w[1]; body->w[0] = b; body->w[1] = a;
    b = arg1->w[2]; a = arg1->w[3]; body->w[2] = b; body->w[3] = a;
    body->w[4] = arg1->w[4];
    body->w[5] = arg1->w[5];
}
}

#pragma pop
extern "C" {
void TWindowDD::run_task() {
    Win_803438C4 *w = (Win_803438C4 *)this;
    Sub_803438C4 *cur;
    s32 done;
    if (w->x80 != 0) {
        if (w->xB0 == 0) {
            ((TWindowDD *)w->x80)->set_clamped_page(2);
        } else if (w->xC4 > 1) {
            ((TWindowDD *)w->x80)->set_clamped_page(0);
        } else {
            ((TWindowDD *)w->x80)->set_clamped_page(1);
        }
    }
    cur = w->subs[w->idx];
    if (w->x7C != 0 && cur != NULL) {
        ((TWindowDD *)w->x7C)->set_value_f32(TWindowDD__sub_8034217C((saddr)cur));
    }
    switch (w->xA8) {
    case 2:
        break;
    case 1:
        ((TWindowDD *)w->x80)->handle_input();
        done = 0;
        if (((TWindowDD *)w)->test_input_flag_4() != 0) {
            if (w->x80 != 0) {
                switch (TWindowDD__sub_80340820((void *)w->x80)) {
                case 0:
                    TWindowDD::play_sound();
                    TWindowDD__sub_803484C4(w);
                    copy_chat_entry__9TWindowDDFPvPv((R_80343BC0 *)(w->xC0), (R_80343BC0 *)(&w->xE0));
                    break;
                case 1:
                    TWindowDD::play_se();
                    done = 1;
                    w->x94 |= 2;
                    break;
                case 2:
                    TWindowDD::play_se();
                    ((TWindowDD *)w)->set_state();
                    break;
                }
            }
        } else if (TWindowDD__sub_803482B0(w) != 0) {
            TWindowDD::play_se();
            done = 1;
            w->x94 |= 2;
        } else if (TWindowDD::apply_both_choices((saddr)w->input, 0x40) != 0) {
            TWindowDD::spawn_window();
            done = 1;
        }
        if (done != 0) {
            w->xA8 = 0;
            TWindowDD__sub_80340910((void *)w->x80);
            TWindowDD__sub_80341AF8((saddr)cur);
            if (w->xC4 > 0) {
                TWindowDD__sub_80347CC8(w, &w->xC4);
            }
        }
        break;
    case 0:
        switch (w->xAC) {
        case 0:
            if (w->xB8 != 1 && TWindowDD_check_input_mask(w->input, 0x80) != 0) {
                TWindowDD::spawn_window();
                w->xA8 = 1;
                ((TWindowDD *)w->x80)->set_clamped_selection(((TWindowDD *)(w->subs[w->idx]))->get_cursor_index());
                TWindowDD__sub_80341AE0((saddr)cur);
                copy_chat_entry__9TWindowDDFPvPv((R_80343BC0 *)(&w->xE0), (R_80343BC0 *)(&w->xC4));
                if (w->xE0 > 0) {
                    w->xE0--;
                    TWindowDD__sub_80347CC8(w, &w->xE0);
                }
            } else {
                run_state__9TWindowDDFPv((u8 *)w);
                w->x94 = 0;
            }
            break;
        case 1:
            if (w->subs[w->idx + 1] != NULL && w->subs[w->idx + 1]->x50 == 0) {
                TWindowDD__sub_803434F4((u8 *)w);
                w->xAC = 0;
            }
            break;
        case 2:
            if (w->subs[w->idx]->x50 == 0) {
                pop_menu_level__9TWindowDDFPv((TWindowDD_803431C0 *)(w));
                w->xAC = 0;
            }
            break;
        }
        break;
    }
}

void run_state__9TWindowDDFPv(u8 *window_dd) {
    switch (*(u32 *)((s8 *)window_dd + 0xB0)) {
    case 0:
        ((TWindowDD *)window_dd)->handle_confirm_input();
        return;
    case 1:
    case 2:
        ((TWindowDD *)window_dd)->update();
        return;
    case 3:
        TWindowDD__sub_80342D14((window_dd));
        return;
    case 5:
        ((TWindowDD *)window_dd)->update_transition();
        return;
    case 6:
        ((TWindowDD *)window_dd)->update_layout();
        return;
    case 7:
        ((TWindowDD *)window_dd)->update_dispatch();
        return;
    case 8:
        ((TWindowDD *)window_dd)->enter_state_9();
        return;
    case 9:
        TWindowDD__sub_803429B0((window_dd));
        return;
    case 12:
        update__9TWindowDDFi((saddr)window_dd);
        return;
    case 13:
        TWindowDD__sub_80342800((window_dd));
        return;
    case 14:
        TWindowDD::update_state((window_dd));
        return;
    case 15:
        TWindowDD::enter_state_16((window_dd));
        return;
    case 17:
        ((TWindowDD *)window_dd)->enter_state_18();
        return;
    case 18:
        ((TWindowDD *)window_dd)->enter_state_19();
        return;
    case 20:
        handle_input__9TWindowDDFi((saddr)window_dd);
        return;
    case 10:
    case 11:
    case 16:
    case 19:
        TWindowDD__sub_80342428((window_dd));
    default:
        return;
    }
}

void TWindowDD__sub_803435A0(u8 *arg0) {
    s32 *entry;
    s32 *temp_r31;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3_5;
    s32 temp_r4;
    u8 *temp_r3;
    u8 *window_dd;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0xB4);
    if ((temp_r0 == 0x14) || (temp_r0 == 0xC)) {
        TWindowDD::build_player_word_lists();
    }
    *(s32 *)((s8 *)arg0 + 0xB8) = 0;
    if (*(s32 *)((s8 *)arg0 + 0xB4) == 1 || *(s32 *)((s8 *)arg0 + 0xB4) == 2 || *(s32 *)((s8 *)arg0 + 0xB4) == 8 || *(s32 *)((s8 *)arg0 + 0xB4) == 0xF || *(s32 *)((s8 *)arg0 + 0xB4) == 0x11) {
        ((TWindowDD *)(arg0 + 0xC4))->reset_index();
    }
    entry = (s32 *)TWindowDD::get_entry(arg0, *(s32 *)((s8 *)arg0 + 0xB0));
    temp_r31 = (s32 *)TWindowDD::get_entry(arg0, *(s32 *)((s8 *)arg0 + 0xB4));
    temp_r3 = arg0 + *(s32 *)((s8 *)arg0 + 0x20) * 4;
    temp_r3 = *(u8 **)((s8 *)temp_r3 + 0x24);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)temp_r3 + 0x30) = (f32) lbl_805DFB90;
        *(f32 *)((s8 *)temp_r3 + 0x38) = (f32) TWindowDD__data_805DFB74;
        *(s32 *)((s8 *)temp_r3 + 0x50) = (s32) TWindowDD__data_805DFB50;
        if (*entry & 4) {
            temp_r4 = *(s32 *)((s8 *)arg0 + 0xBC);
            *(s32 *)((s8 *)arg0 + 0xBC) = (temp_r4 + 1);
            TWindowDD__sub_80347E04(arg0, temp_r4);
        }
    }
    window_dd = TWindowDD__sub_80347AD4(arg0, 1, *(s32 *)((s8 *)arg0 + 0x8C));
    if (window_dd != NULL) {
        ((TWindowDD *)window_dd)->set_pos_and_data(TWindowDD__data_805DFB6C);
        if (*(s32 *)((s8 *)temp_r31 + 0) & 1) {
            *(f32 *)((s8 *)window_dd + 0x38) = (f32) lbl_805DFB7C;
            temp_r3_3 = (unsigned char *) (*(void **)((s8 *)arg0 + 0x80));
            if (temp_r3_3 != NULL) {
                *(f32 *)((s8 *)temp_r3_3 + 0x30) = (f32) lbl_805DFC0C;
                *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x80)) + 0x50) = (s32) TWindowDD__data_805DFB50;
            }
        } else {
            *(f32 *)((s8 *)window_dd + 0x38) = (f32) TWindowDD__data_805DFB74;
            temp_r3_4 = (unsigned char *) (*(void **)((s8 *)arg0 + 0x80));
            if (temp_r3_4 != NULL) {
                *(f32 *)((s8 *)temp_r3_4 + 0x30) = (f32) TWindowDD__data_805DFBFC;
                *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x80)) + 0x50) = (s32) TWindowDD__data_805DFB50;
            }
        }
        if (*(s32 *)((s8 *)temp_r31 + 0) & 2) {
            TWindowDD__sub_80347A4C((arg0), (saddr)window_dd);
        }
    }
    temp_r3_5 = *(s32 *)((s8 *)temp_r31 + 0);
    if (!(temp_r3_5 & 8)) {
        if (temp_r3_5 & 1) {
            *(s32 *)((s8 *)arg0 + 0x90) = dispatch_by_window_mode(reinterpret_cast<TWindowDD *>(arg0), (int) (*(s32 *)((s8 *)arg0 + 0xB4)), (int) (*(s32 *)((s8 *)arg0 + 0x8C)), 0);
            if ((temp_r3 = TWindowDD__sub_80347AD4(arg0, 2, *(s32 *)((s8 *)arg0 + 0x90))) != NULL) {
                ((TWindowDD *)temp_r3)->set_pos_and_data(TWindowDD__data_805DFC10);
            }
            TWindowDD__sub_80347F48((arg0));
        } else {
            *(s32 *)((s8 *)arg0 + 0x90) = dispatch_by_window_mode(reinterpret_cast<TWindowDD *>(arg0), (int) (*(s32 *)((s8 *)arg0 + 0xB4)), (int) (*(s32 *)((s8 *)arg0 + 0x8C)), 0);
            if ((temp_r3 = TWindowDD__sub_80347AD4(arg0, 2, *(s32 *)((s8 *)arg0 + 0x90))) != NULL) {
                ((TWindowDD *)temp_r3)->set_pos_and_data(lbl_805DFB80);
            }
            ((TWindowDD *)arg0)->init_entry_field_64(1);
        }
    } else {
        TWindowDD__sub_80347FA0((saddr)arg0, 1);
    }
    if ((s16) *(s16 *)((s8 *)temp_r31 + 4) == -1) {
        TWindowDD__sub_80347FA0((saddr)arg0, 2);
    } else {
        ((TWindowDD *)arg0)->setup_entry(*(s16 *)((s8 *)temp_r31 + 4));
        ((TWindowDD *)arg0)->init_entry_field_64(2);
    }
    *(s32 *)((s8 *)arg0 + 0xAC) = 1;
}

void TWindowDD__sub_803434F4(u8 *arg0) {
    u8 *var_r31;
    u8 *var_r3;
    u8 *var_r4;
    u8 *var_r5;
    var_r31 = arg0;
    var_r3 = (u8 *)(var_r31 + (*(s32 *)((s8 *)arg0 + 0x20) * 4));
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r3 + 0x24));
    reinterpret_cast<TWindowDD_WS_Word *>(var_r3)->free_child();
    var_r3 = var_r31;
    var_r4 = (u8 *)(var_r31 + (*(s32 *)((s8 *)var_r31 + 0x20) * 4));
    var_r4 = (u8 *)(*(u8 **)((s8 *)var_r4 + 0x24));
    apply_input__9TWindowDDFPvPv((saddr)var_r3, (saddr)var_r4);
    var_r3 = var_r31;
    var_r5 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0xB0));
    var_r4 = (u8 *)(var_r31 + (*(s32 *)((s8 *)var_r31 + 0x20) * 4));
    *(u8 **)((s8 *)var_r4 + 0x44) = var_r5;
    var_r4 = (u8 *)((void *) *(saddr *)((s8 *)var_r31 + 0x20));
    *(s32 *)((s8 *)var_r31 + 0x20) = (saddr)(var_r4 + 1);
    var_r4 = (u8 *)(var_r31 + (*(s32 *)((s8 *)var_r31 + 0x20) * 4));
    var_r4 = (u8 *)(*(u8 **)((s8 *)var_r4 + 0x24));
    update__9TWindowDDFl((saddr)var_r3, (saddr)var_r4, (saddr)var_r5);
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0xB4));
    *(u8 **)((s8 *)var_r31 + 0xB0) = var_r3;
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0x8C));
    *(u8 **)((s8 *)var_r31 + 0x88) = var_r3;
    var_r3 = (u8 *)(*(u8 **)((s8 *)var_r31 + 0x90));
    *(u8 **)((s8 *)var_r31 + 0x8C) = var_r3;
    *(u8 **)((s8 *)var_r31 + 0x90) = (unsigned char *) ((void *)-1);
}

void TWindowDD::apply_entry_layout(void *window) {
    TWindowDD_8034330C *window_dd = (TWindowDD_8034330C *)window;
    s32 *prev;
    s32 *entry;
    u8 *w;
    u8 *child;
    s32 id;
    prev = (s32 *)TWindowDD::get_entry(window_dd, window_dd->index);
    entry = (s32 *)TWindowDD::get_entry(window_dd, window_dd->ids[window_dd->depth]);
    w = ((TWindowDD *)window_dd)->init_last_child();
    if (w != NULL) {
        if (*entry & 1) {
            *(f32 *)((s8 *)w + 0x38) = lbl_805DFB7C;
            if (window_dd->objs[3] != NULL) {
                *(f32 *)((s8 *)window_dd->objs[3] + 0x30) = lbl_805DFC0C;
                *(s32 *)((s8 *)window_dd->objs[3] + 0x50) = TWindowDD__data_805DFB50;
            }
        } else {
            *(f32 *)((s8 *)w + 0x38) = TWindowDD__data_805DFB74;
            if (window_dd->objs[3] != NULL) {
                *(f32 *)((s8 *)window_dd->objs[3] + 0x30) = TWindowDD__data_805DFBFC;
                *(s32 *)((s8 *)window_dd->objs[3] + 0x50) = TWindowDD__data_805DFB50;
            }
        }
    }
    child = window_dd->child[window_dd->depth];
    if (child != NULL) {
        if (*entry & 8) {
            ((TWindowDD *)window_dd)->set_item_pos(0);
            TWindowDD__sub_80347FA0((saddr)window_dd, 1);
        } else if (*entry & 1) {
            ((TWindowDD *)child)->set_pos_and_data(TWindowDD__data_805DFC10);
            *(f32 *)((s8 *)child + 0x38) = lbl_805DFB88;
            TWindowDD__sub_80347F48((u8 *)window_dd);
        } else {
            ((TWindowDD *)child)->set_pos_and_data(lbl_805DFB80);
            *(f32 *)((s8 *)child + 0x38) = lbl_805DFB88;
            ((TWindowDD *)window_dd)->init_entry_field_64(1);
        }
        if (*prev & 2) {
            ((TWindowDD *)window_dd->fC4)->pop_entry();
            TWindowDD__sub_80347CC8(window_dd, window_dd->fC4);
        }
    }
    ((TWindowDD *)window_dd)->set_item_pos(1);
    if (!(*entry & 2)) {
        TWindowDD__sub_80347FA0((saddr)window_dd, 3);
    }
    if (*entry & 4) {
        if (window_dd->fBC > 0) {
            TWindowDD__sub_80347FA0((saddr)window_dd, window_dd->fBC + 3);
        }
    }
    id = ((s16 *)entry)[2];
    if (id == -1) {
        TWindowDD__sub_80347FA0((saddr)window_dd, 2);
    } else {
        ((TWindowDD *)window_dd)->setup_entry(id);
        ((TWindowDD *)window_dd)->init_entry_field_64(2);
    }
    window_dd->fAC = 2;
}

void pop_menu_level__9TWindowDDFPv(TWindowDD_803431C0 *window) {
    s32 *entry;
    void *child;
    TWindowDD::get_entry(window, window->index);
    entry = (s32 *)TWindowDD::get_entry(window, window->ids[window->depth]);
    TWindowDD__sub_80347980(window);
    if (*entry & 8) {
        ((TWindowDD *)window)->destroy_menu_entry(0);
    } else if ((child = window->child[window->depth]) != NULL) {
        TWindowDD::update(window, child);
    }
    ((TWindowDD *)window)->destroy_menu_entry(1);
    window->depth--;
    if (*entry & 4) {
        window->fBC--;
        if (window->fBC >= 0 && window->objs[window->fBC] != NULL) {
            ((TObject *)window->objs[window->fBC])->queue_destruction();
            window->objs[window->fBC] = NULL;
        }
    }
    window->f90 = window->f8C;
    window->f8C = window->f88;
    window->f88 = TWindowDD__sub_8034214C((u8 *)window->child[window->depth]);
    window->index = window->ids[window->depth + 1];
    if (window->index == 0xD) {
        window->fC6 = 4;
    }
}

void open_numeric_parameter_input__9TWindowDDFPviii(WordSelectWindowState* self, s32 minimum, s32 maximum, s32 initial) {
    WindowPosition position;
    position.x = 60.0f + TWindowDD__data_805DFB6C;
    position.y = 10.0f + lbl_805DFB70;
    NumberWindow* window = (NumberWindow*)TObject::operator new(0x7C);
    if (window) {
        window = __ct__18TWindowInputNumberFPvllls(window, &position, minimum, maximum, initial,
                                      (s16)local_client_id);
    }
    self->numberWindow = window;
    if (self->numberWindow) {
        ((TWindowBase *)(self->numberWindow))->set_depth(lbl_805DFC28);
        ((TWindowSubItem *)(self->numberWindow))->set_flag60_bit10();
        TWindowDD__sub_80341AE0((saddr)self->pages[self->activePage]);
    }
}

s32 TWindowDD::update_close_flag(void *window_dd) {
    ((TWindowDD *)window_dd)->get_current_child_index();
    if (classify_id__9TWindowDDFs() != 7) {
        *(s32 *)((s8 *)window_dd + 0xB8) = 1;
        return 1;
    }
    return 0;
}
}
