#include "types.h"
#include "pso/item/TItem.h"
#include "pso/misc/TWindowHelpItem_8025A60C.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TWindowSubStatusDisp_8026F6DC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_80262C3C.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowComCard.h"
#include "pso/misc/TWindowBase.h"
#include <stddef.h>
#include "pso/misc/TWindowLockOn.h"
#include "pso/TObject.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TOSwitchItem.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowDuelResult.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct VBase_18_7b8813
{
  char pad[0x18];
};

struct VObj_18_7b8813 : VBase_18_7b8813 {
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
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual s32 m31();
};

struct Win_8026385C {
    u8 pad00[0x24];
    u8 m24[0x38];
    s32 refresh_flags;
    u8 pad60[4];
    s32 retention;
    u8 pad68[8];
    void (Win_8026385C::*refresh)();
};

struct Win_8026366C {
    u8 pad00[0x60];
    u16 id;
    u8 pad62[2];
    s32 retention;
    u8 pad68[8];
    void (Win_8026366C::*refresh)();
};

struct Obj_80263370;
typedef void (Obj_80263370::*Cb_80263370)();
struct Lock_80263370 {
    u8 pad0[0x20];
    s16 player;
    u8 pad22[2];
    u8 sub[0x34 - 0x24];
    f32 dist;
    f32 w;
    f32 h;
    u8 pad40[0x50 - 0x40];
    s32 i50;
    u8 pad54[0x6C - 0x54];
    f32 scale;
    Cb_80263370 cb;
};

struct Ent_80263370 { u16 flags; u8 pad2[6]; f32 y; u8 padc[4]; f32 w; u8 pad14[8]; u8 kind; };

struct Ent2_80263370 { u16 flags; u8 pad2[0xE]; s32 grade; };

typedef struct Ent_80262E90 {
    u8 pad0[0x32C];
    s16 f32c;
    s16 f32e;
} Ent_80262E90;

typedef struct Gauge_80262E90 {
    u8 pad0[0x20];
    f32 cur;
    f32 max;
} Gauge_80262E90;

struct C_80263944 { void f(); };
typedef void (C_80263944::*PMF_80263944)();

struct Obj_802634E8;
typedef void (Obj_802634E8::*Cb_802634E8)();
struct Lock_802634E8 {
    u8 pad0[0x20];
    s16 player;
    u8 pad22[2];
    u8 sub[0x34 - 0x24];
    f32 dist;
    f32 w;
    f32 h;
    u8 pad40[0x50 - 0x40];
    s32 i50;
    u8 pad54[0x6C - 0x54];
    f32 scale;
    Cb_802634E8 cb;
};

struct Ent_802634E8 { u8 pad0[0x10]; f32 w; };

extern "C" {
u32 obj_getArrWord_254(Ent_80262E90 *, s32);
s16 obj_getS16_2BA(Ent_80262E90 *);
void *find_entity_by_id(u16 id);
}
s32 get_status_effect_icon_index(u32);
extern "C" {
u16 get_entity_id(void *);
void refresh_status_display__9TWindowDDFv(void *);
void init_window_layout_entries(void *, void *, int);
f32 get_target_distance__13TWindowLockOnFv(s32);
extern Cb_802634E8 lockon_photon_blast_marker_callback;
extern const f32 TWindowLockOn__data_805DD110;
extern const f32 lbl_805DD124;
extern const f32 lbl_805DD128;
extern const f32 lbl_805DD12C;

extern u8 lockon_window_layout_entries[];
extern Cb_80263370 lbl_804D0288;
extern s32 __vt__13TWindowLockOn[];
extern const f32 lbl_805DD100;
extern const f32 lbl_805DD114;
extern const f32 lbl_805DD118;
extern const f32 lbl_805DD11C;
extern const f32 lbl_805DD120;

s32 obj_testFlags30__14TObjCollidableFUl(s32, s32);
s32 obj_isState3_324__9TObjCharaFv(void *);
s32 is_script_controlled__10TObjPlayerFv(void *);
s32 draw_visible_window_entries(void *, void *, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(u32);
s32 construct_base__9TWindowDDFPUcsPUc(void *, void *, void *, int);
s32 get_window_layout_position(int);
extern u8 lbl_804D0268[];
extern s32 lbl_805D3948;
extern const f32 lbl_805DD130;
extern const f32 lbl_805DD134;

void bind_target__13TWindowLockOnFv(Win_8026366C *w, u16 id);

#define PSO_VCALL_VObj_18_7b8813_m31(_self) (((VObj_18_7b8813 *)(_self))->m31())
void TWindowLockOn::validate_target() {
  u16 temp_r3;
  u8 *item;
  temp_r3 = this->m_60;
  if (temp_r3 != ((-1U) & 0xFFFFu))
  {
    item = (u8 *) find_entity_by_id(temp_r3);
    if ((item == 0) || (((TObject *)item)->all_parents_unqueued_for_destruction() == 0))
    {
      this->m_60 = 0xFFFFU;
      if (((f32) (*(s32 *)&this->m_64)) > lbl_805DD100)
      {
        *(s32 *)&this->m_64 = 0xF;
      }
    }
    else
      if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(item, 0x10000000) == 0)
    {
      if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(item, 0x20000000) != 0)
      {
        if (PSO_VCALL_VObj_18_7b8813_m31(item) != 0)
        {
          this->m_60 = 0xFFFFU;
          if (((f32) (*(s32 *)&this->m_64)) > lbl_805DD100)
          {
            *(s32 *)&this->m_64 = 0xF;
          }
        }
      }
      else
        if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(item, 0x80000000) != 0) && (((TItem *)item)->get_mode() != 0))
      {
        this->m_60 = 0xFFFFU;
        if (((f32) (*(s32 *)&this->m_64)) > lbl_805DD100)
        {
          *(s32 *)&this->m_64 = 0xF;
        }
      }
    }
  }
}
#undef PSO_VCALL_VObj_18_7b8813_m31

bool is_lockable_target__13TWindowLockOnFi(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x10000000) != 0) {
        if ((obj_isState3_324__9TObjCharaFv((void *)arg0) != 0) || (is_script_controlled__10TObjPlayerFv((void *)arg0) != 0)) {
            return 0;
        }
        return 1;
    }
    if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x20000000) != 0) {
        if (obj_testFlags30__14TObjCollidableFUl(arg0, 0x40000000) != 0) {
            return 0;
        }
        return ((TWindowLockOn *)arg0)->get_target_id() != 0;
    }
    return obj_testFlags30__14TObjCollidableFUl(arg0, (s32)((int) (0x80000000))) != 0;
}

void TWindowLockOn::refresh_enemy_statuses() {
    s32 i;
    Ent_80262E90 *ent;
    s32 mode;
    Gauge_80262E90 *g;
    if (this->m_60 == 0xFFFF) {
        return;
    }
    ent = (Ent_80262E90 *)find_entity_by_id(this->m_60);
    if (ent == NULL) {
        return;
    }
    i = 0;
    do {
        mode = get_status_effect_icon_index(obj_getArrWord_254(ent, i));
        ((TWindowComCard *)(this->get_array_entry(i + 3)))->set_help_mode(mode);
        i++;
    } while (i < 4);
    {
        g = (Gauge_80262E90 *)this->get_array_entry(7);
        g->cur = ((TItemProShield *)ent)->get_field_2b8();
        g->max = ent->f32c;
        ((TWindowHelpItem *)g)->set_flag0_bit2();
    }
    {
        g = (Gauge_80262E90 *)this->get_array_entry(8);
        g->cur = obj_getS16_2BA(ent);
        g->max = ent->f32e;
        ((TWindowHelpItem *)g)->set_flag0_bit2();
    }
}

void TWindowLockOn::refresh_ground_item() {  }

void TWindowLockOn::update_photon_blast_marker() {
    u8 *arg0 = (u8 *)this;
    update_photon_blast_player_marker(((TWindowBase *)arg0)->get_array_entry(0), this->m_60);
}

struct Obj_80263014;
typedef void (Obj_80263014::*Cb_80263014)();
struct Lock_80263014 {
    u8 pad0[0x20];
    s16 player;
    u8 pad22[2];
    u8 sub[0x34 - 0x24];
    f32 dist;
    f32 w;
    f32 h;
    u8 pad40[0x50 - 0x40];
    s32 i50;
    u8 pad54[0x6C - 0x54];
    f32 scale;
    Cb_80263014 cb;
};
struct Ent_80263014 { u8 pad0[8]; f32 y; u8 padc[0x14 - 0xC]; f32 x14; u8 pad18[8]; f32 x20; f32 x24; };
struct Ent2_80263014 { u8 pad0[0x24]; s32 color; };
struct Data_80263014 {
    u8 pad0[0x6C];
    u8 m6c[0x20C - 0x6C];
    s32 names[5];
    s32 colors[5];
    Cb_80263014 cb;
};

s32 obj_testFlag_2E4__9TObjCharaFUl(void *, int);
s32 is_split_screen(void);
s32 get_message_10__20TWindowSubStatusDispFl(int);
s32 enemy_name_for_rt_index(int);
u32 calc_text_width(int);
extern Data_80263014 lock_on_window_params;
extern const f32 lbl_805DD104;
extern const f32 lbl_805DD108;
extern const f32 lbl_805DD10C;

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
#define arg0 ((Lock_80263014 *)a0)
#define obj ((void *)a1)
void TWindowLockOn__update_for_enemy(s32 a0, s32 a1) {
    Data_80263014 *d = &lock_on_window_params;
    u32 width;
    s32 e;
    s32 kind;
    s32 idx;
    Ent_80263014 *p;
    u32 w2;
    s32 *np;

    init_window_layout_entries(arg0->sub, d->m6c, arg0->player);
    arg0->cb = d->cb;
    e = ((TWindowBase *)arg0)->get_array_entry(1);
    TWindowDuelResult::set_default_status((void *)e, get_message_10__20TWindowSubStatusDispFl(0xA5));
    ((TWindowHelpItem *)e)->reset_float_field();
    width = calc_text_width(((TWindowSubComCard *)e)->get_field_20());
    e = ((TWindowBase *)arg0)->get_array_entry(0);
    TWindowDuelResult::set_default_status((void *)e, enemy_name_for_rt_index(((TWindowLockOn *)obj)->get_target_id()));
    ((TWindowHelpItem *)e)->reset_float_field();
    arg0->w = (f32)calc_text_width(((TWindowSubComCard *)e)->get_field_20());
    arg0->h = lbl_805DD104;
    if (is_split_screen() == 0) {
        arg0->h += lbl_805DD108;
    }
    if (obj_testFlag_2E4__9TObjCharaFUl(obj, 0x40) != 0) {
        kind = 4;
    } else if (obj_testFlag_2E4__9TObjCharaFUl(obj, 1) != 0) {
        kind = 0;
    } else if (obj_testFlag_2E4__9TObjCharaFUl(obj, 2) != 0) {
        kind = 1;
    } else if (obj_testFlag_2E4__9TObjCharaFUl(obj, 4) != 0) {
        kind = 2;
    } else if (obj_testFlag_2E4__9TObjCharaFUl(obj, 8) != 0) {
        kind = 3;
    } else {
        kind = 4;
    }
    e = ((TWindowBase *)arg0)->get_array_entry(2);
    np = d->names;
    TWindowDuelResult::set_default_status((void *)e, np[kind]);
    ((TWindowHelpItem *)e)->reset_float_field();
    ((Ent_80263014 *)e)->y = lbl_805DD10C + (f32)width;
    np = d->colors;
    ((Ent2_80263014 *)e)->color = np[kind];
    w2 = calc_text_width(((TWindowSubComCard *)e)->get_field_20());
    w2 += width;
    if ((f32)w2 > arg0->w) {
        arg0->w = (f32)w2;
    }
    arg0->w += TWindowLockOn__data_805DD110;
    arg0->dist = get_target_distance__13TWindowLockOnFv(0x1E) - arg0->h * arg0->scale;
    arg0->i50 = 0;
    p = (Ent_80263014 *)((TWindowBase *)arg0)->get_array_entry(7);
    p->x14 = arg0->w - TWindowLockOn__data_805DD110;
    p->x20 = (f32)((TItemProShield *)obj)->get_field_2b8();
    p->x24 = (f32)*(s16 *)((u8 *)obj + 0x32C);
    p = (Ent_80263014 *)((TWindowBase *)arg0)->get_array_entry(8);
    p->x14 = arg0->w - TWindowLockOn__data_805DD110;
    p->x20 = (f32)obj_getS16_2BA((Ent_80262E90 *)obj);
    p->x24 = (f32)*(s16 *)((u8 *)obj + 0x32E);
}
#undef arg0
#undef obj
#pragma pop

#pragma push
#pragma fp_contract on
#define arg0 ((Lock_80263370 *)a0)
#define item ((void *)a1)
s32 TWindowLockOn__update_for_item(s32 a0, s32 a1) {
    Ent_80263370 *e;
    Ent_80263370 *e2;
    f32 r;
    init_window_layout_entries(arg0->sub, lockon_window_layout_entries, arg0->player);
    arg0->cb = lbl_804D0288;
    e = (Ent_80263370 *)((TWindowBase *)arg0)->get_array_entry(0);
    ((TWindowSubStatusDisp *)e)->init_item_row(item, 0);
    ((TWindowSubStatusDisp *)e)->calc_row_width();
    e->y = lbl_805DD114;
    if (e->kind != 0x33) {
        e->y += lbl_805DD118;
    }
    arg0->w = e->w;
    arg0->h = lbl_805DD11C;
    e2 = (Ent_80263370 *)((TWindowBase *)arg0)->get_array_entry(1);
    if (((TItem *)item)->get_item_type() == 0 || ((TItem *)item)->get_item_type() == 1) {
        ((Ent2_80263370 *)e2)->grade = (u8)((TItem *)item)->calc_display_grade();
        arg0->h += lbl_805DD120;
        e2->flags &= ~2;
        r = get_item_star_row_width((u8 *)e2);
        if (arg0->w < r) {
            arg0->w = r;
        }
    } else {
        e2->flags |= 2;
    }
    arg0->w += TWindowLockOn__data_805DD110;
    arg0->dist = get_target_distance__13TWindowLockOnFv(0x1E) - arg0->h * arg0->scale;
    arg0->i50 = 0;
}
#undef arg0
#undef item
#pragma pop

#pragma push
#pragma fp_contract on
#define arg0 ((Lock_802634E8 *)a0)
#define arg1 ((void *)a1)
s32 TWindowLockOn__update_for_other_player(s32 a0, s32 a1) {
    Ent_802634E8 *w;
    u16 id;
    init_window_layout_entries(arg0->sub, &lock_on_window_params, arg0->player);
    arg0->cb = lockon_photon_blast_marker_callback;
    w = (Ent_802634E8 *)((TWindowBase *)arg0)->get_array_entry(1);
    id = get_entity_id(arg1);
    ((TWindowLockOn *)w)->update_for_player_index(id);
    ((TWindowHelpItem *)w)->reset_float_field();
    refresh_status_display__9TWindowDDFv(w);
    arg0->w = lbl_805DD124 + w->w;
    arg0->h = lbl_805DD128;
    arg0->w += TWindowLockOn__data_805DD110;
    arg0->dist = get_target_distance__13TWindowLockOnFv(0x1E) - arg0->h * arg0->scale;
    arg0->i50 = 0;
}
#undef arg0
#undef arg1
#pragma pop

void update_for_target__13TWindowLockOnFii(s32 arg0, s32 arg1) {
    ((TWindowSubStatusDisp *)(arg0 + 0x24))->destroy_all_items();
    if (obj_testFlags30__14TObjCollidableFUl(arg1, 0x10000000) != 0) {
        TWindowLockOn__update_for_other_player(arg0, arg1);
        return;
    }
    if (obj_testFlags30__14TObjCollidableFUl(arg1, 0x80000000) != 0) {
        TWindowLockOn__update_for_item(arg0, arg1);
        return;
    }
    if (obj_testFlags30__14TObjCollidableFUl(arg1, 0x20000000) != 0) {
        TWindowLockOn__update_for_enemy(arg0, arg1);
    }
}

void bind_target__13TWindowLockOnFv(Win_8026366C *w, u16 id) {
    s32 actor;

    if (id == 0xFFFF) {
        queue_destruction__7TObjectFv(w);
        return;
    }
    actor = (s32)find_entity_by_id(id);
    if (((s32 (*)(s32))is_lockable_target__13TWindowLockOnFi)(actor) == 0) {
        return;
    }
    if (w->id == id) {
        w->retention = 0x5A;
        return;
    }
    if ((f32)w->retention > lbl_805DD12C) {
        return;
    }
    w->id = id;
    w->retention = 0x5A;
    update_for_target__13TWindowLockOnFii((s32)w, actor);
    if (w->refresh) {
        (w->*w->refresh)();
    }
}

void *TWindowLockOn::create_for_target(s32 arg0, u16 arg1) {
    void *p;
    if (arg1 == 0xFFFF) {
        return NULL;
    }
    if (((s32 (*)(s32))is_lockable_target__13TWindowLockOnFi)((s32)find_entity_by_id(arg1)) == 0) {
        return NULL;
    }
    p = __nw__7TObjectFUl(0x7C);
    if (p != NULL) {
        p = ((void *(*)(void *, s32, u16))TWindowLockOn__ct)(p, arg0, arg1);
    }
    return p;
}

void render__13TWindowLockOnFv(TWindowLockOn *arg0) {
    s32 temp_r3;

    temp_r3 = ((TWindowBase *)arg0)->setup_window_draw_context((s32)((u8 *)arg0 + 0x68));
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    if ((arg0->m_30 == arg0->m_40) && (*(f32 *)((s8 *)arg0 + 0x34) == *(f32 *)((s8 *)arg0 + 0x44)) && (arg0->m_38 == arg0->m_48) && (*(f32 *)((s8 *)arg0 + 0x3C) == *(f32 *)((s8 *)arg0 + 0x4C))) {
        draw_visible_window_entries(arg0, (u8 *)arg0 + 0x24, temp_r3);
    }
}

void TWindowLockOn::run_task() {
    Win_8026385C *w = (Win_8026385C *)this;
    s32 old;
    w->refresh_flags = 0x01000000;
    if (w->refresh) {
        (w->*w->refresh)();
    }
    validate_target();
    ((TWindowDD *)w)->initialize_subwindow();
    ((TWindowBase *)w)->update_fade();
    ((TWindowBase *)w)->update_window_entry_list(w->m24);
    old = w->retention;
    w->retention = old - 1;
    if (old < 0) {
        ((TWindowBase *)w)->close();
    }
}

void *__dt__13TWindowLockOnFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TWindowLockOn;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TWindowLockOn__ct(TWindowLockOn *window_lock_on, s16 arg1, s32 arg2) {
    construct_base__9TWindowDDFPUcsPUc((void *)window_lock_on, (void *)lbl_804D0268, (void *)arg1, (int) (get_window_layout_position(0x1E)));
    *(s32 **)((s8 *)window_lock_on + 0x18) = __vt__13TWindowLockOn;
    *(s32 *)((s8 *)window_lock_on + 0) = (s32) lbl_805D3948;
    if (TCameraCtrl::get_camera_id() > 2) {
        *(f32 *)((s8 *)window_lock_on + 0x68) = (f32) lbl_805DD130;
        *(f32 *)((s8 *)window_lock_on + 0x6C) = (f32) lbl_805DD130;
    } else {
        *(f32 *)((s8 *)window_lock_on + 0x68) = (f32) lbl_805DD134;
        *(f32 *)((s8 *)window_lock_on + 0x6C) = (f32) lbl_805DD134;
    }
    window_lock_on->m_60 = 0xFFFF;
    window_lock_on->m_20 = arg1;
    window_lock_on->m_64 = 0;
    *(PMF_80263944 *)((s8 *)window_lock_on + 0x70) = 0;
    ((void (*)(void *, s32))bind_target__13TWindowLockOnFv)(window_lock_on, arg2);
    window_lock_on->m_50 = 0;
    return (u8 *)window_lock_on;
}
}
