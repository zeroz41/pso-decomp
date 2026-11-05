#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TPlyDispConfig.h"
#include "pso/player/TObjPlayer_801BF978.h"
#include "pso/player/TObjPlayer_801D6C4C.h"
#include "pso/player/TObjPlayer_80309D80.h"
#include "pso/misc/TFontSmallLobby_801C013C.h"
#include "pso/misc/TPlyDispConfig_80071F1C.h"
#include "pso/misc/TWindowActionPalette_801C1890.h"
#include "pso/player/TObjPlayer_801BD384.h"
#include "pso/player/TObjPlayer_801BF548.h"
#include "pso/player/TObjPlayer_801BFAD4.h"
#include "pso/player/TObjPlayer_801BFB1C.h"
#include "pso/player/TObjPlayer_801BFE50.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/player/TObjChara.h"
#include "pso/misc/TCharaMaking.h"

extern "C" {
u16 get_entity_id(void *);
s32 sub_801AF454__10TObjPlayerFl(void *, u16);
s32 select_class_action_provider__10TObjPlayerFv(void *, int);
extern s32 TObjPlayer__shared_model_buffer;
void TObjPlayer::sub_801BD318() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = get_entity_id(arg0) * 0xC00;
    (*(s32 *)&this->joint_matrices) = (s32) (TObjPlayer__shared_model_buffer + temp_r4);
    select_class_action_provider__10TObjPlayerFv(arg0, temp_r4);
    sub_801AF454__10TObjPlayerFl(arg0, get_entity_id(arg0));
    ((TObjPlayer *)arg0)->init_idle_animation();
    ((TObjPlayer *)arg0)->draw();
}

}

extern "C" {

void update_body_parts__10TObjPlayerFv(void* p);
int copy_player_visual_record(void*);
s32 fn_800FE73C(TObjPlayer *player);
int free_loaded_buffers__12TCharaMakingFv(void*);
int apply_pending_effect__11TBoss6Type2Fv(void*);
typedef void (*Fn_vpvp_801BD570)(void *, void *);

void TObjPlayer__sub_801BD384(void* p) { ((TObjPlayer *)p)->update_body_parts(); }
void TObjPlayer__sub_801BD3A4(void) {  }
void TObjPlayer::free_chara_making() { apply_pending_effect__11TBoss6Type2Fv(this); free_loaded_buffers__12TCharaMakingFv(this); }
void TObjPlayer::update_body_parts() { copy_player_visual_record((char*)this + 0x85c); this->m_cfc = 255; ((TCharaMaking *)this)->update_body_parts(); fn_800FE73C(this); }

void TObjPlayer__sub_801BCD54(void *);
void TObjPlayer__sub_801BCC50(void *);
void TObjPlayer__sub_801BCB28(void *);
void TObjPlayer__sub_801BCA10(void *);
void TObjPlayer__sub_801BD314(void *);
void TObjPlayer__sub_801BC504(void *);
void TObjPlayer__sub_801BBC64(void *);
void TObjPlayer__sub_801BBB94(void *);
void TObjPlayer__sub_801BB8AC(void *);
void dt__10TObjPlayerFls(void *, int);
void *TObjPlayer__sub_801BEDC0(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
extern s32 __vt__10TObjPlayer[];

void *__dt__10TObjPlayerFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__10TObjPlayer;
        ((TObjPlayer *)arg0)->release_child_object();
        ((TObjPlayer *)arg0)->free_chara_making();
        ((TObjPlayer *)arg0)->destroy_child();
        TObjPlayer__sub_801BCD54(arg0);
        TObjPlayer__sub_801BCC50(arg0);
        TObjPlayer__sub_801BCB28(arg0);
        TObjPlayer__sub_801BCA10(arg0);
        ((TObjPlayer *)arg0)->destroy_owned_object();
        TObjPlayer__sub_801BD314(arg0);
        TObjPlayer__sub_801BC504(arg0);
        TObjPlayer__sub_801BBC64(arg0);
        TObjPlayer__sub_801BBB94(arg0);
        TObjPlayer__sub_801BB8AC(arg0);
        ((TObjPlayer *)arg0)->unregister();
        TObjPlayer::free_owned_buffer_b((s32)((s8 *)arg0 + 0x7CC), (s16)(-1));
        destroy__10TObjPlayerFis((s32)((s8 *)arg0 + 0x754), -1);
        TObjPlayer__sub_801BFAD4((s8 *)arg0 + 0x644, -1);
        dt__10TObjPlayerFls((s8 *)arg0 + 0x550, -1);
        __dt__14TPlyDispConfigFv((s32)((s8 *)arg0 + 0x500), -1);
        TObjPlayer::free_owned_buffer_a((s32)((s8 *)arg0 + 0x4AC), (s16)(-1));
        TObjPlayer__sub_80309E4C((s32)((s8 *)arg0 + 0x384), -1);
        TObjPlayer__sub_801BEDC0((s8 *)arg0 + 0x374, -1);
        TObjPlayer__sub_801BFA4C((s32)((s8 *)arg0 + 0x360), -1);
        TObjPlayer::conditional_delete_ex((s32)((s8 *)arg0 + 0x34C), (s16)(-1));
        TObjPlayer__sub_801BF9F0((u8 *)((s8 *)arg0 + 0x340), -1);
        __dt__9TObjCharaFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjPlayer__sub_801BB85C(TObjPlayer *player, u8 *record);
void sub_801BBC2C__10TObjPlayerFv(void *, void *);
void init_battle__10TObjPlayerFv(void *, void *);
void init_session_technique_caps__10TObjPlayerFPvPv(void *, void *);
void TObjPlayer__sub_801BCAB0(void *, void *);
void init_player_data__10TObjPlayerFv(void *, void *);
void is_flag_set_550__10TObjPlayerFv(void *, void *);
void sub_801BD240__10TObjPlayerFv(void *, void *);
void TObjPlayer__sub_801BEC78(void *);
void init_player_telepipe_record(void *);
void __ct__9TObjCharaFP7TObject(void *);
void TObjPlayer__sub_801BBB70(void *, void *);
void TObjPlayer__sub_80309E9C(void *);
void TObjPlayer__sub_803374C4(void *);
void TObjPlayer__sub_80351974(void *);
extern void *lbl_805D3530;

void *TObjPlayer__ct(TObjPlayer *player, void *arg1, void *arg2) {
    __ct__9TObjCharaFP7TObject(player);
    *(s32 **)((s8 *)player + 0x18) = __vt__10TObjPlayer;
    ((TObjPlayer *)((char *)player + 832))->init_subobject();
    ((TObjPlayer *)((char *)player + 844))->setup_ctrl();
    init_state__10TObjPlayerFi((s32)((char *)player + 864));
    TObjPlayer__sub_803374C4((void *)((char *)player + 884));
    TObjPlayer__sub_80309E9C((void *)((char *)player + 900));
    __ct__8FlagWordFv(((char *)player + 1052));
    TFontSmallLobby__sub_801C0164(((char *)player + 1064));
    ((TFontSmallLobby *)((char *)player + 1196))->construct_pb_controller();
    __ct__14TPlyDispConfigFv(((char *)player + 1280));
    TObjPlayer__sub_80351974((void *)((char *)player + 1360));
    ((TObjPlayer *)((char *)player + 1456))->init_subobjects();
    ((TObjPlayer *)((char *)player + 1504))->init_sub();
    ((TObjPlayer *)((char *)player + 1520))->init_wrapper();
    ((TObjPlayer *)((char *)player + 1532))->init_members();
    ((TObjPlayer *)((char *)player + 1544))->set_vec4_const_wrapper();
    ((TObjPlayer *)((char *)player + 1588))->wrap_update();
    ((TObjPlayer *)((char *)player + 1596))->reset_and_clear();
    ((TObjPlayer *)((char *)player + 1604))->construct_hurt_timer();
    ((TObjPlayer *)((char *)player + 1612))->reset_fields();
    ((TObjPlayer *)((char *)player + 1624))->reset_scale_vector();
    ((TObjPlayer *)((char *)player + 1644))->set_vec3_const_wrapper();
    TObjPlayer__sub_801BEC78((void *)((char *)player + 1656));
    ((TObjPlayer *)((char *)player + 1708))->forward_release();
    TObjPlayer__sub_801BF660(((char *)player + 1840));
    ((TObjPlayer *)((char *)player + 1860))->init_vec_record();
    ((TObjPlayer *)((char *)player + 1876))->init_sub_objects();
    TObjPlayer::init_partial((s32)((void *)((char *)player + 1988)));
    ((TObjPlayer *)((char *)player + 1992))->clear_base();
    ((TObjPlayer *)((char *)player + 1996))->init();
    TObjPlayer__sub_801C1A00(((char *)player + 2088));
    init_player_telepipe_record((void *)((char *)player + 2096));
    TObjPlayer__sub_801BFB4C((u8 *)((char *)player + 2124));
    __ct__8FlagWordFv(((char *)player + 2136));
    TObjPlayer::reset_and_return((s32)((void *)((char *)player + 3332)));
    ((TObjPlayer *)((char *)player + 3500))->clear_header_struct();
    *(void * *)&player->m_name = lbl_805D3530;
    player->init_action_provider();
    player->entity_id = 0;
    player->setup_control_role(7);
    ((Fn_vpvp_801BD570)update_body_parts__10TObjPlayerFv)(player, arg2);
    init_player_data__10TObjPlayerFv(player, (void *)((char *)arg2 + 136));
    player->init_data_table_ptr();
    return player;
}

}
TObjPlayer::TObjPlayer(TObject *arg1, void *arg2) : TObjChara(arg1) {
    ((TObjPlayer *)((char *)this + 832))->init_subobject();
    ((TObjPlayer *)((char *)this + 844))->setup_ctrl();
    init_state__10TObjPlayerFi((s32)((char *)this + 864));
    TObjPlayer__sub_803374C4((void *)((char *)this + 884));
    TObjPlayer__sub_80309E9C((void *)((char *)this + 900));
    __ct__8FlagWordFv(((char *)this + 1052));
    TFontSmallLobby__sub_801C0164(((char *)this + 1064));
    ((TFontSmallLobby *)((char *)this + 1196))->construct_pb_controller();
    __ct__14TPlyDispConfigFv(((char *)this + 1280));
    TObjPlayer__sub_80351974((void *)((char *)this + 1360));
    ((TObjPlayer *)((char *)this + 1456))->init_subobjects();
    ((TObjPlayer *)((char *)this + 1504))->init_sub();
    ((TObjPlayer *)((char *)this + 1520))->init_wrapper();
    ((TObjPlayer *)((char *)this + 1532))->init_members();
    ((TObjPlayer *)((char *)this + 1544))->set_vec4_const_wrapper();
    ((TObjPlayer *)((char *)this + 1588))->wrap_update();
    ((TObjPlayer *)((char *)this + 1596))->reset_and_clear();
    ((TObjPlayer *)((char *)this + 1604))->construct_hurt_timer();
    ((TObjPlayer *)((char *)this + 1612))->reset_fields();
    ((TObjPlayer *)((char *)this + 1624))->reset_scale_vector();
    ((TObjPlayer *)((char *)this + 1644))->set_vec3_const_wrapper();
    TObjPlayer__sub_801BEC78((void *)((char *)this + 1656));
    ((TObjPlayer *)((char *)this + 1708))->forward_release();
    TObjPlayer__sub_801BF660(((char *)this + 1840));
    ((TObjPlayer *)((char *)this + 1860))->init_vec_record();
    ((TObjPlayer *)((char *)this + 1876))->init_sub_objects();
    TObjPlayer::init_partial((s32)((void *)((char *)this + 1988)));
    ((TObjPlayer *)((char *)this + 1992))->clear_base();
    ((TObjPlayer *)((char *)this + 1996))->init();
    TObjPlayer__sub_801C1A00(((char *)this + 2088));
    init_player_telepipe_record((void *)((char *)this + 2096));
    TObjPlayer__sub_801BFB4C((u8 *)((char *)this + 2124));
    __ct__8FlagWordFv(((char *)this + 2136));
    TObjPlayer::reset_and_return((s32)((void *)((char *)this + 3332)));
    ((TObjPlayer *)((char *)this + 3500))->clear_header_struct();
    *(void * *)&this->m_name = lbl_805D3530;
    this->init_from_data(arg2);
    this->setup_control_role(4);
    ((Fn_vpvp_801BD570)TObjPlayer__sub_801BD384)(this, (void *)((char *)arg2 + 200));
    this->load_char_data((u8 *)arg2);
    this->update_position((s32)arg2);
    sub_801BBC2C__10TObjPlayerFv(this, arg2);
    sub_801BD240__10TObjPlayerFv(this, arg2);
    is_flag_set_550__10TObjPlayerFv(this, arg2);
    init_session_technique_caps__10TObjPlayerFPvPv(this, arg2);
    this->init_from_source((u8 *)arg2);
    TObjPlayer__sub_801BCAB0(this, arg2);
    init_battle__10TObjPlayerFv(this, arg2);
    TObjPlayer__sub_801BBB70(this, arg2);
    this->init_class_flags((s32)arg2);
    TObjPlayer__sub_801BB85C(this, (u8 *)arg2);
    this->hp = *(s16 *)((s8 *)arg2 + 0x22);
}
