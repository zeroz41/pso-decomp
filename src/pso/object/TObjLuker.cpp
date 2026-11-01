#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/TObject.h"
#include "pso/object/TObjLuker.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TTecLuker.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/object/TObjAreaWarpQuest.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/misc/TLobby_80207644.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D34A8 = "TObjLuker";
}


struct Win_801A0DB4 { u8 pad[4]; u16 flags; };

struct Obj_801A0DB4 { u8 pad[0x90]; Win_801A0DB4 *wins[4]; };

struct Ctrl_801A0E38 { u8 pad[0x832]; s16 target; };

struct Obj_801A0E38 { u8 pad[0x90]; void *wins[4]; s32 cur; u8 pad2[4]; u16 id; };

struct Ctrl_801A0CE8 { u8 pad[0x832]; s16 target; };

struct Obj_801A0CE8 { u8 pad[0x90]; void *wins[4]; s32 cur; u8 pad2[4]; u16 id; };

struct Obj_801A0C38 { u8 pad[0x90]; void *parts[1]; };

struct Luker_801A16D8 { u8 pad0[0x18]; void *f18; u8 pad1C[0x74]; void *wins[4]; };

struct Luker_801A1768 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *f18;
    u8 pad1C[0x84 - 0x1C];
    s32 f84;
    u8 pad88[0x90 - 0x88];
    s32 wins[4];
    s32 fA0;
    s32 fA4;
    u16 fA8;
    u16 fAA;
    s16 fAC;
    s16 fAE;
    s16 fB0;
    u8 padB2[2];
    s32 fB4;
    s32 fB8;
};

struct Plr_801A0F34 { u8 pad[0x30]; s32 flags; u8 pad34[4]; u8 pos[0xc]; };

struct Pad_801A0F34 { u8 pad[0x20]; u8 btn[0x30]; };

struct Ctrl_801A0E38;
struct Obj_801A0DB4;
struct Obj_801A0E38;
struct Obj_801A0CE8;
struct Obj_801A0C38;

struct Luker_801A1260
{
  u8 pad[0xA8];
  u16 owner;
  u16 partner;
};

extern "C" {
void allow_rendering__7TObjectFv(TObject *);
s32 play_sound_effect(s32, u32, s16, s32);
void disallow_rendering__7TObjectFv(TObject *w);
void close_windows__9TObjLukerFPv(Obj_801A0DB4 *self);
Ctrl_801A0E38 *get_player_by_client_id(u16 id);
s32 is_split_screen(void);
void *get_window_layout_position(s32 a);
void *create_window_menu(void *p, s32 a, s32 b);
void *check_room_seq_4__16TAdChrSelASlotGCFl(void *p, s32 a);
s32 get_floor_destination_name(s32 f);
void align_menu_entry_positions(void *w);
void hide_part__9TObjLukerFPvUs(Obj_801A0C38 *self, u16 i);
void __dl__7TObjectFPv(void *);
extern u8 __vt__9TObjLuker[];
Luker_801A16D8 *__dt__9TObjLukerFv(Luker_801A16D8 *arg0, s16 arg1);
void __ct__8TObjBaseFP7TObject(void *, void *);
extern const char *lbl_805D34A8;
void *TObjLuker__ct(void *arg0, void *arg1, void *arg2);
f32 horizontal_distance_squared(void *, void *);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 check_flag_100__10TObjPlayerFPv(void *);
void queue_destruction__7TObjectFv(void *);
s32 spawn_particle_effect(void *, int);
s32 play_effect_default__10TObjPlayerFii(void *, int);
s32 play_persistent_sound(int, void *, void *, int, int);
void *__nw__7TObjectFUl(int);
s32 TTecLuker__sub_8023401C(void *);
void *create_telepipe_visual(void *, void *, int, int);
s32 get_entity_id(int);
s32 is_player_in_range__9TObjLukerFv(s32 arg0, f32 farg0);
s32 get_main_phase();
s32 mark_area_change_pending();
s32 obj_isState3_324__9TObjCharaFv(int);
s32 send_6x21_inter_level_warp(int, void *);
s32 set_area__6TLobbyFl(void *, int, int);
s32 init_fields__9TTecLukerFs(void *, int);
extern s32 lbl_80515BA0[];
extern s32 lbl_805D55C0;
void *TObjLuker__create(void *arg0);

void hide_part__9TObjLukerFPvUs(Obj_801A0C38 *self, u16 i) {
    if (self->parts[i] != 0) {
        ((TObject *)(self->parts[i]))->suspend_update();
        disallow_rendering__7TObjectFv((TObject *)self->parts[i]);
    }
}

#pragma push
#pragma opt_common_subs off
void TObjLuker::show_part(s32 arg1) {
    s32 arg0 = (s32)this;
    u8 *temp_r31;
    u8 *temp_r3;
    temp_r31 = (u8 *)(arg0 + ((arg1 * 4) & 0x3FFFC));
    temp_r3 = (u8 *)(*(u8 **)((s8 *)temp_r31 + 0x90));
    if (temp_r3 != NULL) {
        if (*(u16 *)((s8 *)temp_r3 + 4) & 4) {
            play_sound_effect(0x53703, 0U, 0, 0);
        }
        ((TQuestVmDownLoadServer *)(*(u8 **)((s8 *)temp_r31 + 0x90)))->clear_flag4_bit4();
        allow_rendering__7TObjectFv((TObject *)(*(u8 **)((s8 *)temp_r31 + 0x90)));
    }
}
#pragma pop

void TObjLuker::update_floor_name_windows() {
    Obj_801A0CE8 *self = (Obj_801A0CE8 *)this;
    s32 target = ((Ctrl_801A0CE8 *)get_player_by_client_id(this->m_a8))->target;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->wins[i] != 0 && target > 0) {
            if (*(s32 *)&this->m_a0 != target) {
                s32 j;
                for (j = 0; j < 4; j++) {
                    ((TWindowSubComCardList *)(self->wins[j]))->reset_entries();
                }
                *(s32 *)&this->m_a0 = target;
            }
            ((TWindowSubTradeMain *)(self->wins[i]))->add_text_entry(get_floor_destination_name(get_floor_area(target)), 2, 0, -1);
            ((TWindowSubComCard *)(self->wins[i]))->calc_window_size();
            align_menu_entry_positions(self->wins[i]);
        }
    }
}

void close_windows__9TObjLukerFPv(Obj_801A0DB4 *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->wins[i] != 0) {
            if (!(self->wins[i]->flags & 4)) {
                play_sound_effect(0x53704, 0, 0, 0);
            }
            ((TObject *)(self->wins[i]))->suspend_update();
            disallow_rendering__7TObjectFv((TObject *)self->wins[i]);
        }
    }
}

void TObjLuker::open_destination_windows() {
    Obj_801A0E38 *self = (Obj_801A0E38 *)this;
    s32 target = get_player_by_client_id(this->m_a8)->target;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->wins[i] == 0 && target > 0) {
            if (is_split_screen() != 0) {
                self->wins[i] = create_window_menu(get_window_layout_position(0x33), 1, i);
            } else {
                self->wins[i] = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x33), 1);
            }
            if (self->wins[i] != 0) {
                this->m_a0 = target;
                ((TWindowSubTradeMain *)(self->wins[i]))->add_text_entry(get_floor_destination_name(get_floor_area(target)), 2, 0, -1);
                ((TAdChrSelASlotGC *)(self->wins[i]))->set_flag_40();
                ((TWindowSubComCard *)(self->wins[i]))->calc_window_size();
                align_menu_entry_positions(self->wins[i]);
                ((TObject *)(self->wins[i]))->suspend_update();
                disallow_rendering__7TObjectFv((TObject *)self->wins[i]);
            }
        }
    }
}
}
extern Pad_801A0F34 controller_input_state[];
s32 are_players_gathered_near(void *arg0, s32 *arg1, f32 range);
void offset_point_toward_camera(u8 *arg0, u8 *arg1, f32 farg0);
extern s32 local_client_id;
extern s32 tl_07;
s32 are_players_gathered_near(void *arg0, s32 *arg1, f32 range) {
    s32 ret;
    s32 flag;
    s32 i;
    Plr_801A0F34 *p;
    void *pos;
    ret = 1;
    flag = 0;
    if (is_split_screen() == 0) {
        return 1;
    }
    i = 0;
    range = range * range;
    do {
        p = (Plr_801A0F34 *)((Ctrl_801A0E38 *(*)(s32))get_player_by_client_id)(i);
        if (p != NULL) {
            pos = p->pos;
            if (!(p->flags & 0x800)) {
                if (check_flag_100__10TObjPlayerFPv(p) == 1) {
                    ret = 0;
                }
                if (horizontal_distance_squared(arg0, pos) > range) {
                    ret = 0;
                }
                flag = 0;
            } else {
                flag = 1;
            }
        }
            i++;
    } while (i < 4);
    if (arg1 == NULL) {
        return ret;
    }
    if (ret != 0 && flag == 0) {
        s32 found = 0;
        s32 j;
        for (j = 0; j < TCameraCtrl::get_instance(); j++) {
            p = (Plr_801A0F34 *)((Ctrl_801A0E38 *(*)(s32))get_player_by_client_id)(TCameraCtrl::get_nth_view_player_id(j));
            if (p != NULL &&
                TWindowShortListCtrl__check_controller_button(controller_input_state[((TRaderMapCore *)p)->get_map_id()].btn, 4) != 0) {
                found = 1;
                if (arg1 != NULL) {
                    *arg1 = j;
                }
                break;
            }
        }
        if (found != 0) {
            ret = 1;
        } else {
            ret = 0;
        }
    }
    return ret;
}

#define C38_801A10A0 ((void (*)(void *, int))hide_part__9TObjLukerFPvUs)
#define DB4_801A10A0 ((void (*)(void *))close_windows__9TObjLukerFPv)
#define PBC_801A10A0 ((u32 (*)(void *))get_player_by_client_id)

s32 is_player_in_range__9TObjLukerFv(s32 arg0, f32 farg0) {
    u32 p;
    s32 found;
    found = 0;
    if (is_split_screen() != 0) {
        for (s32 i = 0; i < 4; i++) {
            p = PBC_801A10A0((void *)i);
            if (p != 0U) {
                if (horizontal_distance_squared((void *)(arg0 + 0x38), (void *)(p + 0x38)) < (farg0 * farg0)) {
                    found = 1;
                    if ((p != 0U) && (check_flag_100__10TObjPlayerFPv((void *)p) == 0)) {
                        ((TObjLuker *)arg0)->show_part((int) (get_entity_id(p)));
                    }
                } else {
                    C38_801A10A0((void *)arg0, (int) (get_entity_id((int)p)));
                }
            }
        }
        for (s32 i = 0; i < 4; i++) {
            p = PBC_801A10A0((void *)i);
            if ((p != 0U) && (check_flag_100__10TObjPlayerFPv((void *)p) == 1)) {
                C38_801A10A0((void *)arg0, (int) (get_entity_id((int)p)));
            }
        }
    } else {
        p = PBC_801A10A0((void *)local_client_id);
        if ((p != 0U) && (horizontal_distance_squared((void *)(p + 0x38), (void *)(arg0 + 0x38)) < (farg0 * farg0))) {
            found = 1;
        }
        if (found != 0) {
            if (p != 0U) {
                if (check_flag_100__10TObjPlayerFPv((void *)p) == 0) {
                    ((TObjLuker *)arg0)->show_part((int) (get_entity_id(p)));
                } else {
                    C38_801A10A0((void *)arg0, (int) (get_entity_id((int)p)));
                }
            }
            return 1;
        }
    }
    if (is_split_screen() != 0) {
        if (found != 1) {
            DB4_801A10A0((void *)arg0);
        }
        return found;
    }
    DB4_801A10A0((void *)arg0);
    return 0;
}

typedef struct Ctrl_801A0E38 Ctrl_801A0E38;
typedef struct Luker_801A1260 Luker_801A1260;
void TObjLuker::transfer_to_town() {
    u8 *arg0_ = (u8 *)this;
  Luker_801A1260 *arg0 = (Luker_801A1260 *) arg0_;
  u8 *self;
  u8 *local;
  s32 i;
  u8 *p;
  s32 flag;
  self = (u8 *) ((Ctrl_801A0E38 *(*)(s32)) get_player_by_client_id)(arg0->owner);
  local = (u8 *) ((Ctrl_801A0E38 *(*)(s32)) get_player_by_client_id)(local_client_id);
  if ((((get_main_phase() == 0xF) && (lbl_805D55C0 != 0)) || (self == 0)) || (local == 0))
  {
    return;
  }
  set_area__6TLobbyFl(lbl_80515BA0, *((s16 *) (((s8 *) self) + 0x832)), get_floor_map_terrain(*((s16 *) (((s8 *) self) + 0x832))));
  mark_area_change_pending();
  for (i = 0; i < 4; i++)
  {
    p = (u8 *) ((Ctrl_801A0E38 *(*)(s32)) get_player_by_client_id)(i);
    if (p != 0)
    {
      flag = 0x830 * 0;
      if (is_split_screen() != 0)
      {
        flag = 1;
      }
      else
        if (obj_isState3_324__9TObjCharaFv((int) p) != 0)
      {
        flag = 1;
      }
      if (flag != 0)
      {
        ((TTecLuker *)(p + 0x848))->set_state(arg0->owner);
        send_6x21_inter_level_warp((int) p, (void *) ((TObjAreaWarpQuest *)lbl_80515BA0)->get_dest_area());
        ((TObjMotion *)p)->set_room((s16) (*((s32 *) (((s8 *) self) + 0x834))));
      }
    }
  }
  if (local != 0)
  {
    ((TTecLuker *)(local + 0x848))->set_state(arg0->owner);
    if (((Ctrl_801A0E38 *(*)(s32)) get_player_by_client_id)(arg0->owner) != 0)
    {
      ((TObjMotion *)local)->set_room((s16) (*((s32 *) (((s8 *) self) + 0x834))));
    }
    send_6x21_inter_level_warp((int) local, (void *) ((TObjAreaWarpQuest *)lbl_80515BA0)->get_dest_area());
  }
  if (is_split_screen() != 0)
  {
    self = (u8 *) ((Ctrl_801A0E38 *(*)(s32)) get_player_by_client_id)(arg0->partner);
    if (self != 0)
    {
      init_fields__9TTecLukerFs(self + 0x830, arg0->partner);
      ((TTecLuker *)(self + 0x830))->send_telepipe_packet();
    }
  }
  else
    if (local_client_id == arg0->owner)
  {
    init_fields__9TTecLukerFs(local + 0x830, arg0->owner);
    ((TTecLuker *)(local + 0x830))->send_telepipe_packet();
  }
}

void TObjLuker::render() {  }

extern void *tl_05;

#define PBC_801A1418(x) (((u8 *(*)(s32))get_player_by_client_id)(x))
void TObjLuker::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    u8 spC[0xC];
    u8 *p;
    void *o;
    s32 flag;
    p = (u8 *)get_player_by_client_id(this->m_a8);
    if (p != NULL) {
        update_floor_name_windows();
        open_destination_windows();
    }
    if (p == NULL) {
        if (*(void * *)&this->m_a4 != NULL) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_a4);
            *(void * *)&this->m_a4 = NULL;
        }
        *(s32 *)&this->m_b4 = 1;
        close_windows__9TObjLukerFPv((Obj_801A0DB4 *) arg0);
        return;
    }
    if (this->m_a8 != 0xFFFF && p != NULL) {
        if (TTecLuker__sub_8023401C(p + 0x830) != 0) {
            *(s16 *)&this->m_ae = 1;
            if (*(s32 *)&this->m_b4 != 0 && *(void * *)&this->m_a4 == NULL) {
                o = __nw__7TObjectFUl(0x44);
                if (o != NULL) {
                    o = create_telepipe_visual(o, (u8 *)&this->position, this->m_a8, tl_07);
                }
                *(void * *)&this->m_a4 = o;
                *(s32 *)&this->m_b4 = 0;
            }
            play_persistent_sound(0x4002B219, arg0, (u8 *)&this->position, 0, 0);
            switch (this->m_b0) {
            case 0:
                sp8 = 0;
                if (is_player_in_range__9TObjLukerFv((s32)((s32) arg0), 10.0f) != 0) {
                    flag = 0;
                    if (is_split_screen() != 0) {
                        if (are_players_gathered_near((u8 *)&this->position, &sp8, 10.0f) != 0) {
                            flag = 1;
                            this->m_aa = this->m_a8;
                        }
                    } else {
                        p = PBC_801A1418(local_client_id);
                        if (p != NULL && check_flag_100__10TObjPlayerFPv(p) == 0 &&
                            TWindowShortListCtrl__check_controller_button(controller_input_state[sp8].btn, 4) != 0) {
                            flag = 1;
                        }
                    }
                    if (flag != 0) {
                        this->m_b0 = 1;
                        offset_point_toward_camera((u8 *)&this->position, (u8 *)spC, 10.0f);
                        spawn_particle_effect(spC, 0xB3);
                        p = PBC_801A1418(local_client_id);
                        if (p != NULL) {
                            play_effect_default__10TObjPlayerFii(p, 0xA);
                            play_sound_effect(0x40022D1A, (u32)(arg0 + 0x38), 0, 0);
                        }
                        TWindowCtrl::init_all_slots();
                        *(s32 *)&this->m_b8 = 1;
                    }
                }
                break;
            case 1:
                if ((this->m_ac)++ > 10) {
                    this->m_b0 = 2;
                }
                break;
            case 2:
                transfer_to_town();
                queue_destruction__7TObjectFv(arg0);
                break;
            }
        } else {
            close_windows__9TObjLukerFPv((Obj_801A0DB4 *) arg0);
            this->m_b0 = *(s16 *)&this->m_ae = 0;
            if (*(s32 *)&this->m_b8 != 0) {
                *(s32 *)&this->m_b8 = 0;
                TWindowCtrl::init_all_slots2();
            }
            this->m_ac = 0;
            if (*(void * *)&this->m_a4 != NULL) {
                queue_destruction__7TObjectFv(*(void * *)&this->m_a4);
                *(void * *)&this->m_a4 = NULL;
            }
            *(s32 *)&this->m_b4 = 1;
        }
    }
}

Luker_801A16D8 *__dt__9TObjLukerFv(Luker_801A16D8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        s32 i;
        arg0->f18 = __vt__9TObjLuker;
        for (i = 0; i < 4; i++) {
            if (arg0->wins[i] != 0) {
                ((TWindowBase *)(arg0->wins[i]))->close();
                arg0->wins[i] = 0;
            }
        }
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define self ((Luker_801A1768 *)arg0)
void *TObjLuker__ct(void *arg0, void *parent, void *arg2) {
    s32 i;
    __ct__8TObjBaseFP7TObject(self, parent);
    self->f18 = __vt__9TObjLuker;
    self->f0 = ((s32)lbl_805D34A8);
    ((TObjBase *)self)->apply_object_set_data(arg2);
    self->fB0 = 0;
    self->fAA = 0xFFFF;
    self->fA8 = self->f84;
    if (self->fA8 > 4) {
        self->fA8 = 0xFFFF;
    }
    for (i = 0; i < 4; i++) {
        self->wins[i] = 0;
    }
    self->fB4 = 1;
    self->fA4 = 0;
    self->fAC = 0;
    self->fA0 = -1;
    self->fB8 = 0;
    return self;
}
#undef self

void *TObjLuker__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TObjLuker__ct(o, tl_05, arg0);
    }
    return o;
}
