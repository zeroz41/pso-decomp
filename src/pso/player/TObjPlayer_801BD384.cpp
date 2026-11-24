#include "pso/player/PlayerState.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyDispConfig.h"
#include "pso/player/TObjPlayer_801D6C4C.h"
#include "pso/player/TObjPlayer_80309D80.h"
#include "pso/ui/font/TFontSmallLobby_801C013C.h"
#include "pso/ui/window/TWindowActionPalette_801C1890.h"
#include "pso/player/TObjPlayer_801BD384.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/object/base/TObjChara.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/player/TUnk_804C4540.h"
#include "pso/object/base/TObjBase.h"


extern "C" {
s32 sub_801AF454__10TObjPlayerFl(void *, u16);
extern s32 TObjPlayer__shared_model_buffer;
void TObjPlayer::sub_801BD318() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = ((TObjBase *)(arg0))->get_entity_id() * 0xC00;
    (*(s32 *)&this->joint_matrices) = (s32) (TObjPlayer__shared_model_buffer + temp_r4);
    this->select_class_action_provider();
    sub_801AF454__10TObjPlayerFl(arg0, ((TObjBase *)(arg0))->get_entity_id());
    this->init_idle_animation();
    this->draw();
}

int copy_player_visual_record(void *dst, void *src);
s32 fn_800FE73C(TObjPlayer *player);

void TObjPlayer::init_body_parts(void *visual) { update_body_parts(visual); }
void TObjPlayer::reset_body_parts() {  }
void TObjPlayer::free_chara_making() { restore_boss6_player_snapshot(this); ((TCharaMaking *)this)->free_loaded_buffers(); }
void TObjPlayer::update_body_parts(void *visual) { copy_player_visual_record((char*)this + 0x85c, visual); this->model_load_flags = 255; ((TCharaMaking *)this)->update_body_parts(); fn_800FE73C(this); }

}

TObjPlayer::~TObjPlayer() {
    release_child_object();
    free_chara_making();
    destroy_child();
    release_pad_binding();
    release_char_data();
    release_area_sync();
    release_technique_caps();
    destroy_owned_object();
    release_motion();
    release_area_placement();
    release_lock_on_cursor();
    release_action_palettes();
    release_pending_action();
    unregister();
    TObjPlayer::free_owned_buffer_b((saddr)&this->attack_state, (s16)(-1));
    destroy__10TObjPlayerFis((saddr)((s8 *)this + 0x754), -1);
    TObjPlayer__sub_801BFAD4(&this->protection, -1);
}

extern "C" {
void TObjPlayer__sub_801BB85C(TObjPlayer *player, u8 *record);
void init_session_technique_caps__10TObjPlayerFPvPv(void *, void *);
void TObjPlayer__sub_801BCAB0(void *, void *);
void init_player_telepipe_record(void *);
void TObjPlayer__sub_801BBB70(void *, void *);
extern const char *lbl_805D3530;
}

TObjPlayer::TObjPlayer(TObject *parent, TUnk_801D8A4C *src) : TObjChara(parent) {
    ((TObjPlayer *)((char *)this + 1544))->set_vec4_const_wrapper();
    ((TObjPlayer *)((char *)this + 1588))->wrap_update();
    battle_music.reset_and_clear();
    ((TObjPlayer *)((char *)this + 1604))->construct_hurt_timer();
    stick_escape_detector.reset_fields();
    ((TObjPlayer *)((char *)this + 1624))->reset_scale_vector();
    ((TObjPlayer *)((char *)this + 1644))->set_vec3_const_wrapper();
    npc_control.reset();
    ((TObjPlayer *)((char *)this + 1708))->forward_release();
    movement_hold.init();
    ((TObjPlayer *)((char *)this + 1860))->init_vec_record();
    ((TObjPlayer *)((char *)this + 1876))->init_sub_objects();
    TObjPlayer::init_partial((saddr)(((char *)this + 1988)));
    ((TObjPlayer *)((char *)this + 1992))->clear_base();
    ((TObjPlayer *)((char *)this + 1996))->init();
    TObjPlayer__sub_801C1A00(((char *)this + 2088));
    init_player_telepipe_record((void *)((char *)this + 2096));
    TObjPlayer__sub_801BFB4C(&m_84c);
    __ct__8FlagWordFv(((char *)this + 2136));
    TObjPlayer::reset_and_return((saddr)(((char *)this + 3332)));
    ((TObjPlayer *)((char *)this + 3500))->clear_header_struct();
    this->m_name = lbl_805D3530;
    this->init_action_provider();
    this->entity_id = 0;
    this->setup_control_role(7);
    this->update_body_parts(src);
    this->init_player_data(src->stats);
    this->init_data_table_ptr();
}

TObjPlayer::TObjPlayer(TObject *parent, void *arg2) : TObjChara(parent) {
    ((TObjPlayer *)((char *)this + 1544))->set_vec4_const_wrapper();
    ((TObjPlayer *)((char *)this + 1588))->wrap_update();
    battle_music.reset_and_clear();
    ((TObjPlayer *)((char *)this + 1604))->construct_hurt_timer();
    stick_escape_detector.reset_fields();
    ((TObjPlayer *)((char *)this + 1624))->reset_scale_vector();
    ((TObjPlayer *)((char *)this + 1644))->set_vec3_const_wrapper();
    npc_control.reset();
    ((TObjPlayer *)((char *)this + 1708))->forward_release();
    movement_hold.init();
    ((TObjPlayer *)((char *)this + 1860))->init_vec_record();
    ((TObjPlayer *)((char *)this + 1876))->init_sub_objects();
    TObjPlayer::init_partial((saddr)(((char *)this + 1988)));
    ((TObjPlayer *)((char *)this + 1992))->clear_base();
    ((TObjPlayer *)((char *)this + 1996))->init();
    TObjPlayer__sub_801C1A00(((char *)this + 2088));
    init_player_telepipe_record((void *)((char *)this + 2096));
    TObjPlayer__sub_801BFB4C(&m_84c);
    __ct__8FlagWordFv(((char *)this + 2136));
    TObjPlayer::reset_and_return((saddr)(((char *)this + 3332)));
    ((TObjPlayer *)((char *)this + 3500))->clear_header_struct();
    this->m_name = lbl_805D3530;
    this->init_from_data(arg2);
    this->setup_control_role(4);
    init_body_parts((char *)arg2 + 200);
    this->load_char_data((u8 *)arg2);
    this->update_position((saddr)arg2);
    clear_lock_on_cursor(arg2);
    init_model_buffer_and_actions(arg2);
    is_flag_set_550(arg2);
    init_session_technique_caps__10TObjPlayerFPvPv(this, arg2);
    this->init_from_source((u8 *)arg2);
    TObjPlayer__sub_801BCAB0(this, arg2);
    init_battle(arg2);
    TObjPlayer__sub_801BBB70(this, arg2);
    this->init_class_flags((saddr)arg2);
    TObjPlayer__sub_801BB85C(this, (u8 *)arg2);
    this->hp = *(s16 *)((s8 *)arg2 + 0x22);
}
