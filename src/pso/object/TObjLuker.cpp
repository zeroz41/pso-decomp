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
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTelepipeEffect.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/network/client_id.h"


#pragma readonly_strings on


const char *luker_name = "TObjLuker";


extern "C" {
s32 is_split_screen(void);
s32 TTecLuker__sub_8023401C(void *);
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
    u8 *slot_base;
    u8 *slot;
    slot_base = (u8 *)(arg0 + ((arg1 * 4) & 0x3FFFC));
    slot = (u8 *)(*(u8 **)((s8 *)slot_base + 0x90));
    if (slot != NULL) {
        if (*(u16 *)((s8 *)slot + 4) & 4) {
            play_sound_effect(0x53703, NULL, 0, 0);
        }
        ((TObject *)(*(u8 **)((s8 *)slot_base + 0x90)))->clear_update_suspension();
        ((TObject *)(*(u8 **)((s8 *)slot_base + 0x90)))->allow_rendering();
    }
}
#pragma pop

void TObjLuker::update_floor_name_windows() {
    s32 target = get_player_by_client_id(this->owner_id)->telepipe.state.floor;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (windows[i] != 0 && target > 0) {
            if (this->current_floor != target) {
                s32 j;
                for (j = 0; j < 4; j++) {
                    ((TWindowSubComCardList *)(windows[j]))->reset_entries();
                }
                this->current_floor = target;
            }
            ((TWindowMenu *)(windows[i]))->add_text_entry(get_floor_destination_name(get_floor_area(target)), 2, 0, -1);
            ((TWindowMenu *)(windows[i]))->calc_window_size();
            align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(windows[i]));
        }
    }
}

void TObjLuker::close_windows() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (windows[i] != 0) {
            if (!(windows[i]->m_flags & 4)) {
                play_sound_effect(0x53704, NULL, 0, 0);
            }
            windows[i]->suspend_update();
            windows[i]->disallow_rendering();
        }
    }
}

void TObjLuker::open_destination_windows() {
    s32 target = get_player_by_client_id(this->owner_id)->telepipe.state.floor;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (windows[i] == 0 && target > 0) {
            if (is_split_screen() != 0) {
                windows[i] = (TObject *)create_window_menu(get_window_layout_position(0x33), 1, i);
            } else {
                windows[i] = (TObject *)create_window_menu_default(get_window_layout_position(0x33), 1);
            }
            if (windows[i] != 0) {
                this->current_floor = target;
                ((TWindowMenu *)(windows[i]))->add_text_entry(get_floor_destination_name(get_floor_area(target)), 2, 0, -1);
                ((TWindowMenu *)(windows[i]))->set_flag_40();
                ((TWindowMenu *)(windows[i]))->calc_window_size();
                align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(windows[i]));
                windows[i]->suspend_update();
                windows[i]->disallow_rendering();
            }
        }
    }
}
}
s32 are_players_gathered_near(const Vec *center, s32 *confirming_view, f32 range);
s32 are_players_gathered_near(const Vec *center, s32 *confirming_view, f32 range) {
    s32 ret;
    s32 flag;
    s32 i;
    TObjPlayer *p;
    Vec *pos;
    ret = 1;
    flag = 0;
    if (is_split_screen() == 0) {
        return 1;
    }
    i = 0;
    range = range * range;
    do {
        p = get_player_by_client_id(i);
        if (p != NULL) {
            pos = &p->position;
            if (!(p->actorFlags & 0x800)) {
                if (p->is_controls_locked() == 1) {
                    ret = 0;
                }
                if (horizontal_distance_squared(center, pos) > range) {
                    ret = 0;
                }
                flag = 0;
            } else {
                flag = 1;
            }
        }
            i++;
    } while (i < 4);
    if (confirming_view == NULL) {
        return ret;
    }
    if (ret != 0 && flag == 0) {
        s32 found = 0;
        s32 j;
        for (j = 0; j < TCameraCtrl::get_view_count(); j++) {
            p = get_player_by_client_id(TCameraCtrl::get_nth_view_player_id(j));
            if (p != NULL &&
                test_pressed_buttons_packed(&controller_input_state.controllers[p->get_controller_port()], 4) != 0) {
                found = 1;
                if (confirming_view != NULL) {
                    *confirming_view = j;
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

s32 TObjLuker::is_player_in_range(f32 farg0) {
    TObjPlayer *p;
    s32 found;
    found = 0;
    if (is_split_screen() != 0) {
        for (s32 i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if (p != NULL) {
                if (horizontal_distance_squared(&position, &p->position) < (farg0 * farg0)) {
                    found = 1;
                    if ((p != NULL) && (p->is_controls_locked() == 0)) {
                        show_part(p->get_entity_id());
                    }
                } else {
                    hide_part(p->get_entity_id());
                }
            }
        }
        for (s32 i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if ((p != NULL) && (p->is_controls_locked() == 1)) {
                hide_part(p->get_entity_id());
            }
        }
    } else {
        p = get_player_by_client_id(local_client_id);
        if ((p != NULL) && (horizontal_distance_squared(&p->position, &position) < (farg0 * farg0))) {
            found = 1;
        }
        if (found != 0) {
            if (p != NULL) {
                if (p->is_controls_locked() == 0) {
                    show_part(p->get_entity_id());
                } else {
                    hide_part(p->get_entity_id());
                }
            }
            return 1;
        }
    }
    if (is_split_screen() != 0) {
        if (found != 1) {
            close_windows();
        }
        return found;
    }
    close_windows();
    return 0;
}

void TObjLuker::transfer_to_town() {
  TObjPlayer *self;
  TObjPlayer *local;
  s32 i;
  TObjPlayer *p;
  s32 flag;
  self = get_player_by_client_id(owner_id);
  local = get_player_by_client_id(local_client_id);
  if ((((get_main_phase() == 0xF) && (lbl_805D55C0 != 0)) || (self == 0)) || (local == 0))
  {
    return;
  }
  floor_transition_state.set_next_floor(self->telepipe.state.floor, get_floor_map_terrain(self->telepipe.state.floor));
  mark_area_change_pending();
  for (i = 0; i < 4; i++)
  {
    p = get_player_by_client_id(i);
    if (p != 0)
    {
      flag = 0x830 * 0;
      if (is_split_screen() != 0)
      {
        flag = 1;
      }
      else
        if (p->obj_isState3_324() != 0)
      {
        flag = 1;
      }
      if (flag != 0)
      {
        ((TTecLuker *)&p->telepipe.flags)->set_state(owner_id);
        send_6x21_inter_level_warp(p, floor_transition_state.get_next_floor());
        p->set_room((s16) self->telepipe.state.room_id);
      }
    }
  }
  if (local != 0)
  {
    ((TTecLuker *)&local->telepipe.flags)->set_state(owner_id);
    if (get_player_by_client_id(owner_id) != 0)
    {
      local->set_room((s16) self->telepipe.state.room_id);
    }
    send_6x21_inter_level_warp(local, floor_transition_state.get_next_floor());
  }
  if (is_split_screen() != 0)
  {
    self = get_player_by_client_id(partner_id);
    if (self != 0)
    {
      self->telepipe.state.init_fields(partner_id);
      self->telepipe.state.send_telepipe_packet();
    }
  }
  else
    if (local_client_id == owner_id)
  {
    local->telepipe.state.init_fields(owner_id);
    local->telepipe.state.send_telepipe_packet();
  }
}

void TObjLuker::render() {  }


void TObjLuker::run_task() {
    s32 sp8;
    Vec effect_position;
    TObjPlayer *p;
    s32 flag;
    p = get_player_by_client_id(this->owner_id);
    if (p != NULL) {
        update_floor_name_windows();
        open_destination_windows();
    }
    if (p == NULL) {
        if (this->effect != NULL) {
            ((TObject *)(this->effect))->queue_destruction();
            this->effect = NULL;
        }
        this->effect_pending = 1;
        close_windows();
        return;
    }
    if (this->owner_id != 0xFFFF && p != NULL) {
        if (TTecLuker__sub_8023401C(&p->telepipe) != 0) {
            this->warp_active = 1;
            if (this->effect_pending != 0 && this->effect == NULL) {
                this->effect = new TTelepipeEffect(&this->position, this->owner_id, tl_07);
                this->effect_pending = 0;
            }
            play_persistent_sound(0x4002B219, this, &this->position, 0, 0);
            switch (this->state) {
            case 0:
                sp8 = 0;
                if (is_player_in_range(10.0f) != 0) {
                    flag = 0;
                    if (is_split_screen() != 0) {
                        if (are_players_gathered_near(&this->position, &sp8, 10.0f) != 0) {
                            flag = 1;
                            this->partner_id = this->owner_id;
                        }
                    } else {
                        p = get_player_by_client_id(local_client_id);
                        if (p != NULL && p->is_controls_locked() == 0 &&
                            test_pressed_buttons_packed(&controller_input_state.controllers[sp8], 4) != 0) {
                            flag = 1;
                        }
                    }
                    if (flag != 0) {
                        this->state = 1;
                        offset_point_toward_camera(&this->position, &effect_position, 10.0f);
                        spawn_particle_effect(&effect_position, 0xB3);
                        p = get_player_by_client_id(local_client_id);
                        if (p != NULL) {
                            send_impose_hold(p, 0xA);
                            play_sound_effect(0x40022D1A, &this->position, 0, 0);
                        }
                        TWindowCtrl::suppress_all_slots();
                        this->slots_locked = 1;
                    }
                }
                break;
            case 1:
                if ((this->hold_frames)++ > 10) {
                    this->state = 2;
                }
                break;
            case 2:
                transfer_to_town();
                queue_destruction();
                break;
            }
        } else {
            close_windows();
            this->state = this->warp_active = 0;
            if (this->slots_locked != 0) {
                this->slots_locked = 0;
                TWindowCtrl::unsuppress_all_slots();
            }
            this->hold_frames = 0;
            if (this->effect != NULL) {
                ((TObject *)(this->effect))->queue_destruction();
                this->effect = NULL;
            }
            this->effect_pending = 1;
        }
    }
}

TObjLuker::~TObjLuker() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (windows[i] != 0) {
            ((TWindowBase *)windows[i])->close();
            windows[i] = 0;
        }
    }
}

TObjLuker::TObjLuker(TObject *parent, void *set_data) : TObjBase(parent) {
    s32 i;
    m_name = luker_name;
    apply_object_set_data(set_data);
    state = 0;
    partner_id = 0xFFFF;
    owner_id = set_params[0];
    if (owner_id > 4) {
        owner_id = 0xFFFF;
    }
    for (i = 0; i < 4; i++) {
        windows[i] = 0;
    }
    effect_pending = 1;
    effect = 0;
    hold_frames = 0;
    current_floor = -1;
    slots_locked = 0;
}

void *TObjLuker::create(void *set_data) {
    return new TObjLuker((TObject *)tl_05, set_data);
}
