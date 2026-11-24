#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/unk/text_8023601C.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/object/TObjLuker.h"
#include "pso/object/TObjLuker_801329B0.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/system/task/TObject.h"

#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/technique/TTecLuker.h"
#include "pso/unk/TUnk_804CCA0C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"


#pragma readonly_strings on


const char *TObjLuker__name = "TObjLuker";


struct Win_801A0DB4 { u8 pad[4]; u16 flags; };

struct Obj_801A0DB4 { u8 pad[0x90]; Win_801A0DB4 *wins[4]; };

struct Ctrl_801A0E38 { u8 pad[0x832]; s16 target; };

struct Obj_801A0E38 { u8 pad[0x90]; void *wins[4]; s32 cur; u8 pad2[4]; u16 id; };

struct Ctrl_801A0CE8 { u8 pad[0x832]; s16 target; };

struct Obj_801A0CE8 { u8 pad[0x90]; void *wins[4]; s32 cur; u8 pad2[4]; u16 id; };

struct Luker_801A16D8 { u8 pad0[0x18]; void *f18; u8 pad1C[0x74]; void *wins[4]; };

struct Luker_801A1768 {
    saddr f0;
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

struct Ctrl_801A0E38;
struct Obj_801A0DB4;
struct Obj_801A0E38;
struct Obj_801A0CE8;

struct Luker_801A1260
{
  u8 pad[0xA8];
  u16 owner;
  u16 partner;
};

extern "C" {
void close_windows__9TObjLukerFPv(Obj_801A0DB4 *self);
s32 is_split_screen(void);
void *get_window_layout_position(s32 a);
void *create_window_menu_default(void *p, s32 a);
f32 horizontal_distance_squared(void *, void *);
s32 TTecLuker__sub_8023401C(void *);
s32 is_player_in_range__9TObjLukerFv(saddr arg0, f32 farg0);
s32 init_fields__9TTecLukerFs(void *, int);
extern s32 lbl_805D55C0;

void TObjLuker::hide_part(u16 part) {
    if (windows[part] != 0) {
        windows[part]->suspend_update();
        windows[part]->disallow_rendering();
    }
}

#pragma push
#pragma opt_common_subs off
void TObjLuker::show_part(u16 arg1) {
    saddr arg0 = (saddr)this;
    u8 *temp_r31;
    u8 *temp_r3;
    temp_r31 = (u8 *)(arg0 + ((arg1 * 4) & 0x3FFFC));
    temp_r3 = (u8 *)(*(u8 **)((s8 *)temp_r31 + 0x90));
    if (temp_r3 != NULL) {
        if (*(u16 *)((s8 *)temp_r3 + 4) & 4) {
            play_sound_effect(0x53703, NULL, 0, 0);
        }
        ((TObject *)(*(u8 **)((s8 *)temp_r31 + 0x90)))->clear_update_suspension();
        ((TObject *)(*(u8 **)((s8 *)temp_r31 + 0x90)))->allow_rendering();
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
            ((TWindowMenu *)(self->wins[i]))->add_text_entry(get_floor_destination_name(get_floor_area(target)), 2, 0, -1);
            ((TWindowMenu *)(self->wins[i]))->calc_window_size();
            align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(self->wins[i]));
        }
    }
}

void close_windows__9TObjLukerFPv(Obj_801A0DB4 *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->wins[i] != 0) {
            if (!(self->wins[i]->flags & 4)) {
                play_sound_effect(0x53704, NULL, 0, 0);
            }
            ((TObject *)(self->wins[i]))->suspend_update();
            ((TObject *)self->wins[i])->disallow_rendering();
        }
    }
}

void TObjLuker::open_destination_windows() {
    Obj_801A0E38 *self = (Obj_801A0E38 *)this;
    s32 target = ((Ctrl_801A0E38 *)get_player_by_client_id(this->m_a8))->target;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->wins[i] == 0 && target > 0) {
            if (is_split_screen() != 0) {
                self->wins[i] = create_window_menu((saddr)get_window_layout_position(0x33), 1, i);
            } else {
                self->wins[i] = create_window_menu_default(get_window_layout_position(0x33), 1);
            }
            if (self->wins[i] != 0) {
                this->m_a0 = target;
                ((TWindowMenu *)(self->wins[i]))->add_text_entry(get_floor_destination_name(get_floor_area(target)), 2, 0, -1);
                ((TWindowMenu *)(self->wins[i]))->set_flag_40();
                ((TWindowMenu *)(self->wins[i]))->calc_window_size();
                align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(self->wins[i]));
                ((TObject *)(self->wins[i]))->suspend_update();
                ((TObject *)self->wins[i])->disallow_rendering();
            }
        }
    }
}
}
s32 are_players_gathered_near(void *arg0, s32 *arg1, f32 range);
extern s32 local_client_id;
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
        p = (Plr_801A0F34 *)get_player_by_client_id(i);
        if (p != NULL) {
            pos = p->pos;
            if (!(p->flags & 0x800)) {
                if (((TObjPlayer *)p)->is_controls_locked() == 1) {
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
        for (j = 0; j < TCameraCtrl::get_view_count(); j++) {
            p = (Plr_801A0F34 *)get_player_by_client_id(TCameraCtrl::get_nth_view_player_id(j));
            if (p != NULL &&
                test_pressed_buttons_packed(&controller_input_state.controllers[((TObjPlayer *)p)->get_controller_port()], 4) != 0) {
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

#define DB4_801A10A0 ((void (*)(void *))close_windows__9TObjLukerFPv)

s32 is_player_in_range__9TObjLukerFv(saddr arg0, f32 farg0) {
    uaddr p;
    s32 found;
    found = 0;
    if (is_split_screen() != 0) {
        for (saddr i = 0; i < 4; i++) {
            p = (uaddr)get_player_by_client_id(i);
            if (p != 0U) {
                if (horizontal_distance_squared((void *)(arg0 + 0x38), (void *)(p + 0x38)) < (farg0 * farg0)) {
                    found = 1;
                    if ((p != 0U) && (((TObjPlayer *)p)->is_controls_locked() == 0)) {
                        ((TObjLuker *)arg0)->show_part((((TObjBase *)(p))->get_entity_id()));
                    }
                } else {
                    ((TObjLuker *)arg0)->hide_part((((TObjBase *)((saddr)p))->get_entity_id()));
                }
            }
        }
        for (saddr i = 0; i < 4; i++) {
            p = (uaddr)get_player_by_client_id(i);
            if ((p != 0U) && (((TObjPlayer *)p)->is_controls_locked() == 1)) {
                ((TObjLuker *)arg0)->hide_part((((TObjBase *)((saddr)p))->get_entity_id()));
            }
        }
    } else {
        p = (uaddr)get_player_by_client_id(local_client_id);
        if ((p != 0U) && (horizontal_distance_squared((void *)(p + 0x38), (void *)(arg0 + 0x38)) < (farg0 * farg0))) {
            found = 1;
        }
        if (found != 0) {
            if (p != 0U) {
                if (((TObjPlayer *)p)->is_controls_locked() == 0) {
                    ((TObjLuker *)arg0)->show_part((((TObjBase *)(p))->get_entity_id()));
                } else {
                    ((TObjLuker *)arg0)->hide_part((((TObjBase *)((saddr)p))->get_entity_id()));
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
  self = (u8 *)get_player_by_client_id(arg0->owner);
  local = (u8 *)get_player_by_client_id(local_client_id);
  if ((((get_main_phase() == 0xF) && (lbl_805D55C0 != 0)) || (self == 0)) || (local == 0))
  {
    return;
  }
  floor_transition_state.set_next_floor(*((s16 *) (((s8 *) self) + 0x832)), get_floor_map_terrain(*((s16 *) (((s8 *) self) + 0x832))));
  mark_area_change_pending();
  for (i = 0; i < 4; i++)
  {
    p = (u8 *)get_player_by_client_id(i);
    if (p != 0)
    {
      flag = 0x830 * 0;
      if (is_split_screen() != 0)
      {
        flag = 1;
      }
      else
        if (((TObjChara *)p)->obj_isState3_324() != 0)
      {
        flag = 1;
      }
      if (flag != 0)
      {
        ((TTecLuker *)(p + 0x848))->set_state(arg0->owner);
        send_6x21_inter_level_warp((TObjPlayer *)p, floor_transition_state.get_next_floor());
        ((TObjMotion *)p)->set_room((s16) (*((s32 *) (((s8 *) self) + 0x834))));
      }
    }
  }
  if (local != 0)
  {
    ((TTecLuker *)(local + 0x848))->set_state(arg0->owner);
    if (((Ctrl_801A0E38 *)get_player_by_client_id(arg0->owner)) != 0)
    {
      ((TObjMotion *)local)->set_room((s16) (*((s32 *) (((s8 *) self) + 0x834))));
    }
    send_6x21_inter_level_warp((TObjPlayer *)local, floor_transition_state.get_next_floor());
  }
  if (is_split_screen() != 0)
  {
    self = (u8 *)get_player_by_client_id(arg0->partner);
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


void TObjLuker::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    Vec effect_position;
    TObjPlayer *p;
    s32 flag;
    p = get_player_by_client_id(this->m_a8);
    if (p != NULL) {
        update_floor_name_windows();
        open_destination_windows();
    }
    if (p == NULL) {
        if (*(void * *)&this->m_a4 != NULL) {
            ((TObject *)(*(void * *)&this->m_a4))->queue_destruction();
            *(void * *)&this->m_a4 = NULL;
        }
        *(s32 *)&this->m_b4 = 1;
        close_windows__9TObjLukerFPv((Obj_801A0DB4 *) arg0);
        return;
    }
    if (this->m_a8 != 0xFFFF && p != NULL) {
        if (TTecLuker__sub_8023401C(&p->telepipe) != 0) {
            *(s16 *)&this->m_ae = 1;
            if (*(s32 *)&this->m_b4 != 0 && *(void * *)&this->m_a4 == NULL) {
                *(void * *)&this->m_a4 = new TUnk_804CCA0C(&this->position, this->m_a8, tl_07);
                *(s32 *)&this->m_b4 = 0;
            }
            play_persistent_sound(0x4002B219, arg0, &this->position, 0, 0);
            switch (this->m_b0) {
            case 0:
                sp8 = 0;
                if (is_player_in_range__9TObjLukerFv((s32)((saddr) arg0), 10.0f) != 0) {
                    flag = 0;
                    if (is_split_screen() != 0) {
                        if (are_players_gathered_near((u8 *)&this->position, &sp8, 10.0f) != 0) {
                            flag = 1;
                            this->m_aa = this->m_a8;
                        }
                    } else {
                        p = get_player_by_client_id(local_client_id);
                        if (p != NULL && p->is_controls_locked() == 0 &&
                            test_pressed_buttons_packed(&controller_input_state.controllers[sp8], 4) != 0) {
                            flag = 1;
                        }
                    }
                    if (flag != 0) {
                        this->m_b0 = 1;
                        offset_point_toward_camera(&this->position, &effect_position, 10.0f);
                        spawn_particle_effect(&effect_position, 0xB3);
                        p = get_player_by_client_id(local_client_id);
                        if (p != NULL) {
                            send_impose_hold(p, 0xA);
                            play_sound_effect(0x40022D1A, &this->position, 0, 0);
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
                ((TObject *)arg0)->queue_destruction();
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
                ((TObject *)(*(void * *)&this->m_a4))->queue_destruction();
                *(void * *)&this->m_a4 = NULL;
            }
            *(s32 *)&this->m_b4 = 1;
        }
    }
}

TObjLuker::~TObjLuker() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((Luker_801A16D8 *)this)->wins[i] != 0) {
            ((TWindowBase *)(((Luker_801A16D8 *)this)->wins[i]))->close();
            ((Luker_801A16D8 *)this)->wins[i] = 0;
        }
    }
}

#define self ((Luker_801A1768 *)this)
TObjLuker::TObjLuker(TObject *parent, void *set_data) : TObjBase(parent) {
    s32 i;
    self->f0 = ((saddr)TObjLuker__name);
    ((TObjBase *)self)->apply_object_set_data(set_data);
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
}
#undef self

void *TObjLuker::create(void *set_data) {
    return new TObjLuker((TObject *)tl_05, set_data);
}
