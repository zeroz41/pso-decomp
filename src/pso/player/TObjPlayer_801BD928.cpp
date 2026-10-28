#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/misc/TFontSmallLobby.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 TFontSmallLobby__sub_801C0164(void *);
s32 __ct__9TObjCharaFP7TObject();
s32 init_player_substructs__10TObjPlayerFv(void *, void *);
s32 TObjPlayer__sub_801BC8F0(void *);
s32 TObjPlayer__sub_801BCA14(void *, void *);
s32 init_player_data__10TObjPlayerFv(void *, void *);
s32 TObjPlayer__sub_801BEB68(void *, void *);
s32 get_quest_status__10TObjPlayerFv(void *, void *);
s32 TObjPlayer__sub_801BEC78(void *);
s32 sub_801BEE24__10TObjPlayerFs(void *, int);
s32 sub_801BEE2C__10TObjPlayerFs(void *, int);
s32 TObjPlayer__sub_801BF660(void *);
s32 TObjPlayer__sub_801BFB4C(void *);
s32 init_state__10TObjPlayerFi(void *);
s32 TObjPlayer__sub_801C1A00(void *);
s32 init_player_telepipe_record(void *);
s32 TObjPlayer__sub_801C221C(void *);
s32 TObjPlayer__sub_801C2224(void *);
s32 TObjPlayer__sub_801C222C(void *);
s32 TObjPlayer__sub_801C2234(void *);
s32 TObjPlayer__sub_801C223C(void *);
s32 TObjPlayer__sub_80309E9C(void *);
s32 TObjPlayer__sub_803374C4(void *);
s32 TObjPlayer__sub_80351974(void *);
s32 __ct__14TPlyDispConfigFv(void *);
s32 get_field_0x374__10TObjPlayerFv(void *, void *);
u16 get_entity_id(void *);
s32 query_field374__10TObjPlayerFv(void *, void *);
s32 query_flags_374__10TObjPlayerFv(void *, void *);
s32 update_body_parts__10TObjPlayerFv(void *, void *);

extern s32 __vt__10TObjPlayer[];
extern s32 lbl_805D3530;

u8 *TObjPlayer::construct_player_instance(s32 arg1, s16 arg2, s32 role, u8 *arg4) {
    __ct__9TObjCharaFP7TObject();
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = __vt__10TObjPlayer;
    ((TObjPlayer *)(((u8 *)this) + 0x340))->init_subobject();
    ((TObjPlayer *)(((u8 *)this) + 0x34C))->setup_ctrl();
    init_state__10TObjPlayerFi((void *) (((u8 *)this) + 0x360));
    TObjPlayer__sub_803374C4((void *) (((u8 *)this) + 0x374));
    TObjPlayer__sub_80309E9C((void *) (((u8 *)this) + 0x384));
    __ct__8FlagWordFv((((u8 *)this) + 0x41C));
    TFontSmallLobby__sub_801C0164((void *) (((u8 *)this) + 0x428));
    ((TFontSmallLobby *)(((u8 *)this) + 0x4AC))->construct_pb_controller();
    __ct__14TPlyDispConfigFv((void *) (((u8 *)this) + 0x500));
    TObjPlayer__sub_80351974((void *) (((u8 *)this) + 0x550));
    ((TObjPlayer *)(((u8 *)this) + 0x5B0))->init_subobjects();
    ((TObjPlayer *)(((u8 *)this) + 0x5E0))->init_sub();
    ((TObjPlayer *)(((u8 *)this) + 0x5F0))->init_wrapper();
    ((TObjPlayer *)(((u8 *)this) + 0x5FC))->init_members();
    ((TObjPlayer *)(((u8 *)this) + 0x608))->set_vec4_const_wrapper();
    ((TObjPlayer *)(((u8 *)this) + 0x634))->wrap_update();
    ((TObjPlayer *)(((u8 *)this) + 0x63C))->reset_and_clear();
    ((TObjPlayer *)(((u8 *)this) + 0x644))->construct_hurt_timer();
    ((TObjPlayer *)(((u8 *)this) + 0x64C))->reset_fields();
    ((TObjPlayer *)(((u8 *)this) + 0x658))->reset_scale_vector();
    ((TObjPlayer *)(((u8 *)this) + 0x66C))->set_vec3_const_wrapper();
    TObjPlayer__sub_801BEC78((void *) (((u8 *)this) + 0x678));
    ((TObjPlayer *)(((u8 *)this) + 0x6AC))->forward_release();
    TObjPlayer__sub_801BF660((void *) (((u8 *)this) + 0x730));
    ((TObjPlayer *)(((u8 *)this) + 0x744))->init_vec_record();
    ((TObjPlayer *)(((u8 *)this) + 0x754))->init_sub_objects();
    TObjPlayer::init_partial((s32)((void *) (((u8 *)this) + 0x7C4)));
    ((TObjPlayer *)(((u8 *)this) + 0x7C8))->clear_base();
    ((TObjPlayer *)(((u8 *)this) + 0x7CC))->init();
    TObjPlayer__sub_801C1A00((void *) (((u8 *)this) + 0x828));
    init_player_telepipe_record((void *) (((u8 *)this) + 0x830));
    TObjPlayer__sub_801BFB4C((void *) (((u8 *)this) + 0x84C));
    __ct__8FlagWordFv((((u8 *)this) + 0x858));
    TObjPlayer::reset_and_return((s32)((void *) (((u8 *)this) + 0xD04)));
    ((TObjPlayer *)(((u8 *)this) + 0xDAC))->clear_header_struct();
    *(s32 *)((s8 *)((u8 *)this) + 0) = (s32) lbl_805D3530;
    this->init_action_provider();
    this->entity_id = arg2;
    this->setup_control_role(role);
    update_body_parts__10TObjPlayerFv(this, arg4 + 0x370);
    sub_801BEE2C__10TObjPlayerFs(this, (int) (*(u8 *)((s8 *)arg4 + 1)));
    sub_801BEE24__10TObjPlayerFs(this, (int) (*(u8 *)((s8 *)arg4 + 2)));
    get_field_0x374__10TObjPlayerFv(this, (void *) (TObjPlayer__sub_801C223C(arg4)));
    get_quest_status__10TObjPlayerFv(this, (void *) (TObjPlayer__sub_801C2234(arg4)));
    query_flags_374__10TObjPlayerFv(this, (void *) (TObjPlayer__sub_801C222C(arg4)));
    query_field374__10TObjPlayerFv(this, (void *) (TObjPlayer__sub_801C2224(arg4)));
    TObjPlayer__sub_801BEB68(this, (void *) (TObjPlayer__sub_801C221C(arg4)));
    init_player_data__10TObjPlayerFv(this, arg4 + 0x34C);
    this->create_lockon_cursor();
    this->sub_801BD318();
    this->init_control_mode(role);
    TObjPlayer__sub_801BCA14(this, arg4);
    init_player_substructs__10TObjPlayerFv(this, arg4 + 0x3C0);
    this->load_character_state((u8 *)arg4);
    this->update_if_active();
    TObjPlayer__sub_801BC8F0(this);
    this->setup_fresh_player_state((u8 *)arg4);
    this->sub_801BB8B0((u8 *)arg4);
    TObjPlayer::set_com_card_window((s32)((void *) (get_entity_id(this))));
    return ((u8 *)this);
}

}
