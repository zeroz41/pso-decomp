#include "types.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss4DarkFalz.h"

struct Ent_801BC194 { u8 pad[0x14]; };

extern "C" {

s32 get_main_phase();
s32 is_locally_controlled__10TObjPlayerFPv(void *);
s32 obj_isState2_324__13TUnk_804806E8Fv(void *);
u16 get_entity_id(void *);
s32 check_flag__10TObjPlayerFl(void *, int);
}
void reset_cameras_to_actor(void *actor, s32 arg1);
extern "C" {
s32 sub_801A1DDC__10TObjPlayerFv(void *);
s32 is_single_screen__10TObjPlayerFv();
s32 is_key_machine_ready__10TObjPlayerFv();
s32 play_effect_default__10TObjPlayerFii(void *, int);
void *get_player_by_client_id(s32);
s32 has_active_camera_event__10TObjPlayerFv(void *);
u8 *find_player_arrival_set(void *, s32);
s32 TObjPlayer__sub_801BF954(void *, int);
s32 TObjPlayer__sub_801BF95C(void *);
s32 TForceOperate__ct(void *, s32, u16);
s32 clear_movement_history(void *);
s32 TObjPlayer__sub_801D8C3C(void *);
u8 *get_lobby_entry_ptr__10TObjPlayerFv(void *);
void *__nw__7TObjectFUl(u32);
void *consume_telepipe_arrival(u16, void *);
extern Ent_801BC194 TObjPlayer__arrival_override_table[];
extern s32 local_client_id;
extern s32 tl_02;
extern const f32 TObjPlayer__data_805DC278;

void TObjPlayer::place_on_area_entry() {
    u8 *arg0 = (u8 *)this;
    void *obj;
    void *p;
    Ent_801BC194 *e;
    u8 *other;

    if (get_main_phase() == 0xE && is_single_screen__10TObjPlayerFv() == 0 &&
        is_locally_controlled__10TObjPlayerFPv(arg0) != 0 && has_active_camera_event__10TObjPlayerFv(arg0) == 0 &&
        check_flag__10TObjPlayerFl(arg0, 0x100000) == 0 && is_key_machine_ready__10TObjPlayerFv() != 0) {
        ((TObjPlayer *)arg0)->set_state_flags(0x100000);
        ((TUnk_804B9870 *)arg0)->set_position_from(get_lobby_entry_ptr__10TObjPlayerFv(arg0));
        this->rotation_y = TObjPlayer__sub_801D8C3C(arg0);
        play_effect_default__10TObjPlayerFii(arg0, 0x1E);
        TObjPlayer::set_camera_mode(3);
        obj = __nw__7TObjectFUl(0x24);
        if (obj != NULL) {
            TForceOperate__ct(obj, tl_02, get_entity_id(arg0));
        }
    } else if (obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0) {
        p = consume_telepipe_arrival(get_entity_id(arg0), (u8 *)&this->rotation_y);
        if (p != NULL) {
            ((TUnk_804B9870 *)arg0)->set_position_from(p);
        } else {
            e = &TObjPlayer__arrival_override_table[get_entity_id(arg0)];
            if (obj_isState2_324__13TUnk_804806E8Fv(arg0) == 0 && TObjPlayer__sub_801BF95C(e) == 1) {
                TObjPlayer__sub_801BF954(e, 0);
                this->rotation_y = ((TObjPlayer *)e)->get_lock_timer();
                ((TUnk_804B9870 *)arg0)->set_position_from(((TObjPlayer *)e)->get_sub_object());
            } else {
                other = find_player_arrival_set(arg0, get_entity_id(arg0));
                if (other != NULL) {
                    ((TUnk_804B9870 *)arg0)->set_position_from(other + 0x38);
                    this->rotation_y = *(s32 *)((s8 *)other + 0x60);
                } else {
                    ((TObjPlayer *)arg0)->set_position(TObjPlayer__data_805DC278, TObjPlayer__data_805DC278, TObjPlayer__data_805DC278);
                }
            }
        }
    }
    ((TBoss4DarkFalz *)arg0)->save_position();
    ((TUnk_804806E8 *)arg0)->calc_attach_pos();
    ((TObjPlayer *)(arg0 + 0x84C))->copy_offset_position(arg0);
    ((TObjPlayer *)arg0)->set_position_history_entry(0, this->position.x, this->position.z);
    clear_movement_history((u8 *)&this->m_6ac);
    if (is_single_screen__10TObjPlayerFv() != 0) {
        reset_cameras_to_actor(arg0, 0);
    } else if (sub_801A1DDC__10TObjPlayerFv(arg0) != 0) {
        if (is_locally_controlled__10TObjPlayerFPv(arg0) == 0 && (p = get_player_by_client_id(local_client_id)) != NULL) {
            reset_cameras_to_actor(p, 0);
        } else {
            reset_cameras_to_actor(arg0, 0);
        }
    }
}
}
