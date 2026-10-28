#include "types.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubStatusDisp_80071774.h"
#include "pso/misc/TWindowSubStatusDisp_80228CC0.h"
#include "pso/misc/TWindowSubStatusDisp_80228F5C.h"
#include "pso/player/TObjPlayer_800A7764.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/text_8027FD88.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/object/TObjLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Win_8027FD9C { u8 pad[0x60]; s16 f60; u8 pad2[6]; s32 f68; };

struct VBase_18_eecf68 { char pad[0x18]; };

struct VObj_18_eecf68 : VBase_18_eecf68 {
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
    virtual s32 m14();
};

struct En_80280F14 { u8 pad[0x20]; s32 v; };

struct Q_80280F14 { u8 pad[0x1C]; s32 a; s32 b; };

struct Wn_80280F14 { u8 pad[0x20]; s16 f20; };

struct VBase_80280FD0 { char pad[0x18]; };

struct VObj_80280FD0 : VBase_80280FD0 {
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
};

typedef struct Stats_80280B1C {
    s16 v[12];
} Stats_80280B1C;

typedef struct Entry_80280B1C {
    u8 pad0[0x1C];
    s32 color;
    s32 value;
} Entry_80280B1C;

extern "C" {
s32 get_message_10__20TWindowSubStatusDispFl(s32);
s32 TLobby__sub_801C2614();
void *get_array_entry__13TUnk_804CE018Fi(void *, s32);
s32 init_window_layout_entries(void *, s32 *, s16);
s8 get_type__20TWindowSubStatusDispFv(int);
void *get_player_by_client_id(s32 i);
void vt11__20TWindowSubStatusDispFv(Wn_80280F14 *arg0);
}
void set_text_entry_string(u8 *arg0, u32 str, s32 arg2);
extern s32 TWindowSubStatusDisp__record_summary_layout[];
extern const f32 TWindowSubStatusDisp__data_805DD708;
extern s32 TWindowSubStatusDisp__resistance_layout[];
extern s32 TWindowSubStatusDisp__stat_page_layout[];
s32 get_class_name_text(s32);
extern s32 TWindowSubStatusDisp__summary_page_layout[];
extern "C" {
s32 build_player_class_stat_template(s32 arg0, s32 arg1);
s32 build_player_equipment_requirement_stats(int, void *);
s32 get_shared_text_buffer();
s32 get_layout_id__20TWindowSubStatusDispFv(s32);
extern s32 status_disp_vt5_message_ids[];
extern s32 TWindowSubStatusDisp__numbered_times_layout[];
extern char lbl_805DD6E4[2];

void fn_8027FD88(void* p, f32 a, f32 b) { *(f32*)((char*)p + 0x6c) = a; *(f32*)((char*)p + 0x70) = b; }
void fn_8027FD94(void* p, s16 v) { *(s16*)((char*)p + 0x62) = v; }

s32 TWindowSubStatusDisp::get_display_mode() {
    Win_8027FD9C *arg0 = (Win_8027FD9C *)this;
    s32 r;
    if (arg0->f60 == 2) {
        s8 t = get_type__20TWindowSubStatusDispFv(arg0->f68);
        r = 3;
        if (t == 2) r = 2;
        return r;
    }
    return get_type__20TWindowSubStatusDispFv(arg0->f68) != 2 ? 1 : 0;
}

void TWindowSubStatusDisp::vt16() {  }

typedef struct Win_8027FD9C Win_8027FD9C;
void vt5__20TWindowSubStatusDispFv(u8 *arg0) {
  s32 type;
  s32 n;
  u16 *e;
  s32 r;
  u8 *new_var;
  int new_var2;
  s32 i;
  if (((f32) (*((s32 *) (((s8 *) arg0) + 0x5C)))) > TWindowSubStatusDisp__data_805DD708)
  {
    *((s32 *) (((s8 *) arg0) + 0x5C)) = 7;
  }
  init_window_layout_entries(arg0 + 0x24, TWindowSubStatusDisp__numbered_times_layout, *((s16 *) (((s8 *) arg0) + 0x20)));
  new_var = arg0;
  type = ((TWindowSubStatusDisp *)new_var)->get_display_mode();
  e = (u16 *) get_array_entry__13TUnk_804CE018Fi(arg0, 0);
  set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(status_disp_vt5_message_ids[type]), 0);
  n = get_layout_id__20TWindowSubStatusDispFv(type);
  i = 0;
  do
  {
    e = (u16 *) get_array_entry__13TUnk_804CE018Fi(arg0, i + 1);
    new_var2 = n > i;
    if (!new_var2)
    {
      *e |= 2;
    }
    else
    {
      r = TWindowSubStatusDisp__sub_80071A24(i, *((s16 *) (((s8 *) arg0) + 0x20)), type);
      if (r == 0)
      {
        *e |= 2;
      }
      else
      {
        *e &= ~2;
        text_builder_reset();
        append_padded_number(i + 1, 2);
        text_builder_append((u8 *)lbl_805DD6E4);
        TWindowSubStatusDisp::append_play_time(r);
        set_text_entry_string((u8 *)e, get_shared_text_buffer(), 0x20);
      }
    }
    i++;
  }
  while (i < 9);
}

void TWindowSubStatusDisp::vt15() {  }

void TWindowSubStatusDisp::vt18() {  }

void vt7__20TWindowSubStatusDispFv(u8 *arg0) {
    u8 *temp_r30;
    if ((f32) *(s32 *)((s8 *)arg0 + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 7;
    }
    init_window_layout_entries(arg0 + 0x24, TWindowSubStatusDisp__record_summary_layout, *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0);
    set_text_entry_string(temp_r30, get_message_10__20TWindowSubStatusDispFl(0x8F), 0);
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 1);
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 6), 0);
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 4);
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 7), 0);
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 7);
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 8), 0);
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xA);
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 9), 0);
    ((TWindowHelpItem *)(get_array_entry__13TUnk_804CE018Fi(arg0, 0xD)))->set_flag0_bit2();
    ((TWindowHelpItem *)(get_array_entry__13TUnk_804CE018Fi(arg0, 0xE)))->set_flag0_bit2();
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 3);
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_state((u16) *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 6);
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC__sub_801FC36C((u16) *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 9);
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_window_status((u16) *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = (u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xC);
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_window_field((u16) *(s16 *)((s8 *)arg0 + 0x20));
    ((TWindowHelpItem *)(get_array_entry__13TUnk_804CE018Fi(arg0, 0xF)))->set_flag0_bit2();
}

void TWindowSubStatusDisp::vt14() {  }

void vt3__20TWindowSubStatusDispFv(u8 *arg0) {
    s32 card_flag;
    u8 *temp_r30;
    if ((f32) *(s32 *)((s8 *)arg0 + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 7;
    }
    init_window_layout_entries(arg0 + 0x24, TWindowSubStatusDisp__record_summary_layout, *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0));
    set_text_entry_string(temp_r30, get_message_10__20TWindowSubStatusDispFl(0x8E), 0);
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 1));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 6), 0);
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 4));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 7), 0);
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 7));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 8), 0);
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xA));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 9), 0);
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xD));
    set_text_entry_string(temp_r30, get_localized_text_entry(0x10, 0xE), 0);
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 3));
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_field_21a8((u16) *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 6));
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_value((u16) *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 9));
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_status((u16) *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = ((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xC));
    *(s32 *)((s8 *)temp_r30 + 0x20) = (s32) TAdSinglePlyChrSelectGC::get_card_field((u16) *(s16 *)((s8 *)arg0 + 0x20));
    card_flag = TAdSinglePlyChrSelectGC::get_card_flag((u16) *(s16 *)((s8 *)arg0 + 0x20));
    if (TLobby__sub_801C2614() != 0) {
        card_flag -= 1;
    }
    *(s32 *)((s8 *)((u8 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xF)) + 0x20) = (s32) card_flag;
}

void TWindowSubStatusDisp::vt13() {
    s32 player;
    void *temp_r31;
    void *temp_r31_2;
    void *temp_r31_3;
    void *temp_r31_4;
    void *temp_r31_5;

    player = (s32)get_player_by_client_id(this->m_20);
    if (player != 0) {
        temp_r31 = get_array_entry__13TUnk_804CE018Fi(this, 2);
        *(s32 *)((s8 *)temp_r31 + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_stat();
        temp_r31_2 = get_array_entry__13TUnk_804CE018Fi(this, 8);
        *(s32 *)((s8 *)temp_r31_2 + 0x20) = (s32) ((TObjPlayer *)player)->get_class_id();
        temp_r31_3 = get_array_entry__13TUnk_804CE018Fi(this, 0xE);
        *(s32 *)((s8 *)temp_r31_3 + 0x20) = (s32) ((TObjPlayer *)player)->get_item_index();
        temp_r31_4 = get_array_entry__13TUnk_804CE018Fi(this, 0x14);
        *(s32 *)((s8 *)temp_r31_4 + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_field_2F8();
        temp_r31_5 = get_array_entry__13TUnk_804CE018Fi(this, 0x1A);
        *(s32 *)((s8 *)temp_r31_5 + 0x20) = (s32) ((TWindowSubStatusDisp *)player)->get_item_type();
    }
}
void vt2__20TWindowSubStatusDispFv(u8 *arg0) {
    s32 temp_r30;
    if ((f32) *(s32 *)((s8 *)arg0 + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 7;
    }
    init_window_layout_entries(arg0 + 0x24, TWindowSubStatusDisp__resistance_layout, *(s16 *)((s8 *)arg0 + 0x20));
    temp_r30 = ((s32)get_array_entry__13TUnk_804CE018Fi(arg0, 0));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x89)), 0x20);
    temp_r30 = ((s32)get_array_entry__13TUnk_804CE018Fi(arg0, 6));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x8A)), 0x20);
    temp_r30 = ((s32)get_array_entry__13TUnk_804CE018Fi(arg0, 0xC));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x8B)), 0x20);
    temp_r30 = ((s32)get_array_entry__13TUnk_804CE018Fi(arg0, 0x12));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x8C)), 0x20);
    temp_r30 = ((s32)get_array_entry__13TUnk_804CE018Fi(arg0, 0x18));
    set_text_entry_string((u8 *)temp_r30, (get_message_10__20TWindowSubStatusDispFl(0x8D)), 0x20);
}

void vt12__20TWindowSubStatusDispFv(u8 *arg0) {
    Stats_80280B1C cur;
    Stats_80280B1C req;
    Entry_80280B1C *e2;
    s32 pl;
    Entry_80280B1C *e;
    u8 *q;
    ((TWindowSubStatusDisp *)(&cur))->clear_fields();
    ((TWindowSubStatusDisp *)(&req))->clear_fields();
    pl = (s32)get_player_by_client_id(*(s16 *)(arg0 + 0x20));
    if (pl != 0) {
        e2 = (Entry_80280B1C *)get_array_entry__13TUnk_804CE018Fi(arg0, 2);
        e2->value = TObjPlayer__sub_800A776C((void *)pl) + (((TObjPlayer *)pl)->get_field_2c8() + ((TObjPlayer *)pl)->get_actor_attack_params_atp_min());
        e = (Entry_80280B1C *)get_array_entry__13TUnk_804CE018Fi(arg0, 8);
        e->value = ((TWindowSubStatusDisp *)pl)->get_value();
        e = (Entry_80280B1C *)get_array_entry__13TUnk_804CE018Fi(arg0, 0x14);
        e->value = ((TObjPlayer *)pl)->get_ata();
        e = (Entry_80280B1C *)get_array_entry__13TUnk_804CE018Fi(arg0, 0x1A);
        e->value = ((TObjPlayer *)pl)->get_hp();
        q = ((TObjPlayer *)pl)->get_stats();
        if (q != NULL) {
            e = (Entry_80280B1C *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xE);
            e->value = *(s16 *)(q + 2);
            e = (Entry_80280B1C *)get_array_entry__13TUnk_804CE018Fi(arg0, 0x20);
            e->value = *(s16 *)(q + 0xC);
        }
    }
    if (build_player_equipment_requirement_stats(pl, &cur) != 0) {
        build_player_class_stat_template(pl, (s32)&req);
#define ROW(idx, k) \
        e = (Entry_80280B1C *)get_array_entry__13TUnk_804CE018Fi(arg0, idx); \
        e->value = cur.v[k]; \
        if (req.v[k] <= cur.v[k]) { e->color = -0x100; } else { e->color = -1; }
        ROW(4, 0)
        ROW(0xA, 1)
        ROW(0x16, 3)
        ROW(0x1C, 4)
        ROW(0x10, 2)
        ROW(0x22, 5)
#undef ROW
    }
}

void vt1__20TWindowSubStatusDispFv(u8 *arg0) {
    void *e;
    if ((f32) *(s32 *)((s8 *)arg0 + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 7;
    }
    init_window_layout_entries(arg0 + 0x24, TWindowSubStatusDisp__stat_page_layout, *(s16 *)((s8 *)arg0 + 0x20));
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 0);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x83), 0x20);
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 6);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x84), 0x20);
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 0xC);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x85), 0x20);
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 0x12);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x86), 0x20);
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 0x18);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x87), 0x20);
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 0x1E);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x88), 0x20);
}

void vt11__20TWindowSubStatusDispFv(Wn_80280F14 *arg0) {
    VObj_18_eecf68 *p;
    Q_80280F14 *q;
    En_80280F14 *e;
    p = ((VObj_18_eecf68 *)get_player_by_client_id(arg0->f20));
    if (p != NULL) {
        q = (Q_80280F14 *)((TObjPlayer *)p)->get_stats();
        if (q != NULL) {
            e = ((En_80280F14 *)get_array_entry__13TUnk_804CE018Fi(arg0, 2));
            e->v = p->m14() + 1;
            e = ((En_80280F14 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0x10));
            e->v = q->b;
            e = ((En_80280F14 *)get_array_entry__13TUnk_804CE018Fi(arg0, 8));
            e->v = q->a;
            e = ((En_80280F14 *)get_array_entry__13TUnk_804CE018Fi(arg0, 0xC));
            e->v = ((TObjPlayer *)p)->get_next_level_exp() - q->a;
        }
    }
}
void vt0__20TWindowSubStatusDispFv(u8 *arg0) {
    void *e;
    u8 *pl;
    s32 v;
    s8 *st;
    if ((f32) *(s32 *)((s8 *)arg0 + 0x5C) > TWindowSubStatusDisp__data_805DD708) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 7;
    }
    init_window_layout_entries(arg0 + 0x24, TWindowSubStatusDisp__summary_page_layout, *(s16 *)((s8 *)arg0 + 0x20));
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 6);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x80), 0x20);
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 0xA);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x81), 0x20);
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 0xE);
    set_text_entry_string((u8 *)e, get_message_10__20TWindowSubStatusDispFl(0x82), 0x20);
    e = get_array_entry__13TUnk_804CE018Fi(arg0, 0x11);
    set_text_entry_string((u8 *)e, TWindowSubStatusDisp::get_download_server(), 0x20);
    pl = (u8 *)get_player_by_client_id(*(s16 *)((s8 *)arg0 + 0x20));
    if (pl != NULL) {
        st = (s8 *)(pl + 0x85C);
        if (st != NULL) {
            v = ((VObj_80280FD0 *)pl)->m10();
            set_text_entry_string((u8 *)(get_array_entry__13TUnk_804CE018Fi(arg0, 0)), v, 0x20);
            v = get_class_name_text(st[0x31]);
            set_text_entry_string((u8 *)(get_array_entry__13TUnk_804CE018Fi(arg0, 3)), v, 0);
            v = TObjLuker::get_stat_table_entry(st[0x30]);
            set_text_entry_string((u8 *)(get_array_entry__13TUnk_804CE018Fi(arg0, 4)), v, 0);
        }
        e = get_array_entry__13TUnk_804CE018Fi(arg0, 5);
        *(u8 **)((s8 *)e + 0x30) = arg0 + 0x64;
        *(u8 **)((s8 *)arg0 + 0x64) = pl + 0xCF4;
    }
}
}
