#include "pso/player/PlayerState.h"
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/player/TObjPlayer_801BC404.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TForceOperate.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/camera/TCameraCtrl.h"

struct Ent_801BC194 { u8 pad[0x14]; };

extern "C" {

s32 get_main_phase();
}
extern "C" {
s32 is_key_machine_ready__10TObjPlayerFv();
u8 *find_player_arrival_set(void *, s32);
s32 clear_movement_history(void *);
void *consume_telepipe_arrival(u16, void *);
extern Ent_801BC194 TObjPlayer__arrival_override_table[];
extern s32 local_client_id;
extern const f32 TObjPlayer__data_805DC278;

void TObjPlayer::place_on_area_entry() {
    u8 *arg0 = (u8 *)this;
    void *p;
    Ent_801BC194 *e;
    u8 *other;

    if (get_main_phase() == 0xE && TObjPlayer::is_single_screen() == 0 &&
        TObjPlayer::is_locally_controlled(arg0) != 0 && this->has_active_camera_event() == 0 &&
        this->check_flag(0x100000) == 0 && is_key_machine_ready__10TObjPlayerFv() != 0) {
        this->set_state_flags(0x100000);
        this->set_position_from(this->get_lobby_entry_ptr());
        this->rotation_y = get_lobby_entry_yaw();
        send_impose_hold(this, 0x1E);
        TObjPlayer::set_camera_mode(3);
        new TForceOperate(tl_02, ((TObjBase *)(arg0))->get_entity_id());
    } else if (this->obj_isState2_324() == 0) {
        p = consume_telepipe_arrival(((TObjBase *)(arg0))->get_entity_id(), (u8 *)&this->rotation_y);
        if (p != NULL) {
            this->set_position_from(p);
        } else {
            e = &TObjPlayer__arrival_override_table[((TObjBase *)(arg0))->get_entity_id()];
            if (this->obj_isState2_324() == 0 && TObjPlayer__sub_801BF95C(e) == 1) {
                TObjPlayer__sub_801BF954(e, 0);
                this->rotation_y = ((TObjPlayer *)e)->get_lock_timer();
                this->set_position_from(((TObjPlayer *)e)->get_sub_object());
            } else {
                other = find_player_arrival_set(arg0, ((TObjBase *)(arg0))->get_entity_id());
                if (other != NULL) {
                    this->set_position_from(other + 0x38);
                    this->rotation_y = *(s32 *)((s8 *)other + 0x60);
                } else {
                    this->set_position(TObjPlayer__data_805DC278, TObjPlayer__data_805DC278, TObjPlayer__data_805DC278);
                }
            }
        }
    }
    this->save_previous_position();
    this->calc_attach_pos();
    ((TObjPlayer *)(arg0 + 0x84C))->copy_offset_position(arg0);
    this->set_position_history_entry(0, this->position.x, this->position.z);
    clear_movement_history((u8 *)&this->m_6ac);
    if (TObjPlayer::is_single_screen() != 0) {
        reset_cameras_to_actor(this, 0);
    } else if (this->sub_801A1DDC() != 0) {
        TObjPlayer *player;
        if (TObjPlayer::is_locally_controlled(arg0) == 0 && (player = get_player_by_client_id(local_client_id)) != NULL) {
            reset_cameras_to_actor(player, 0);
        } else {
            reset_cameras_to_actor(this, 0);
        }
    }
}
void TObjPlayer__sub_801BEEAC(u8 *arg0, u8 *arg1);
void TObjPlayer__sub_801BEEE0(void *p, void *q);
void TObjPlayer__sub_801BEF30(void *p, void *q);

s32 TObjPlayer::has_active_camera_event() {
    if (TLobby::get_instance() == 0) {
        if ((TObjPlayer::check_camera_mode() == 0) && (TLevelSelect::get_difficulty_flag_bit(0, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(1, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(2, 0xB) == 0) && (TLevelSelect::get_difficulty_flag_bit(3, 0xB) == 0)) {
            return 0;
        }
        goto block_14;
    }
    if ((TLobby::get_instance() == 1) && (TObjPlayer::check_camera_mode() == 0) && (TLevelSelect::get_difficulty_flag_bit(0, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(1, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(2, 0x5B) == 0) && (TLevelSelect::get_difficulty_flag_bit(3, 0x5B) == 0)) {
        return 0;
    }
block_14:
    return 1;
}
void TObjPlayer::release_area_placement() {  }
void TObjPlayer::init_from_data(void* a1) { init_action_provider(); *(short *)&this->entity_id = *(unsigned short*)(a1); *(short*)((char*)this + 0x2e) = *(short*)((char*)a1 + 0x2); *(void* *)&this->actorFlags = *(void**)((char*)a1 + 0x4); copy_xyz((char*)this + 0x5c, (char*)a1 + 0x14); *(short *)&this->mode = *(short*)((char*)a1 + 0x20); *(short *)&this->hp = *(short*)((char*)a1 + 0x22); ((TLobby *)((char*)this + 0xdac))->copy_header_struct((char*)a1 + 0x68); TObjPlayer__sub_801BEF30((void *)((char*)this + 0x828), (void *)((char*)a1 + 0x70)); ((TObjPlayer *)((char*)this + 0x830))->copy_player_record_header((u8 *)((char*)a1 + 0x78)); TObjPlayer__sub_801BEEE0((void *)((char*)this + 0x858), (void *)((char*)a1 + 0x94)); TObjPlayer__sub_801BEEAC((u8 *)((char*)this + 0x730), (u8 *)((char*)a1 + 0x98)); set_floor_index((saddr)(*(void**)((char*)a1 + 0xac))); set_floor((saddr)(*(void**)((char*)a1 + 0x488))); *(void* *)&this->state_flags = *(void**)((char*)a1 + 0xb0); set_language((saddr)(*(void**)((char*)a1 + 0x64))); }

}
