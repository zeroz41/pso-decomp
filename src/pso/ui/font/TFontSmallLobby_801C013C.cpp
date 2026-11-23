#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/ui/font/TFontSmallLobby_801C013C.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/ui/font/TFontSmallLobby.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include <string.h>
#include "pso/network/protocol/packet_classes.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct O_801C0708 { u8 a; u8 b; u8 pad[2]; s32 c; u16 d; u16 e; };

struct O_801C0350 { u8 a; u8 b; u8 pad[2]; u16 c; u16 d; };

extern "C" {
void __copy(void *, void *, int);
void TFontSmallLobby__sub_801C013C(void* p) { ((FlagWord *)((void*)((char*)p + 0x10)))->clear(2); }

}

PlayerTechniqueState::PlayerTechniqueState() {
    reset_tech_state();
}

extern "C" {

void bswap_g_client_id_header(void* p) { ((G_ClientIDHeader *)p)->bswap(); }

void *TFontSmallLobby__sub_801C01DC(G_LevelUpAllTechniques_6x9B *arg0, G_LevelUpAllTechniques_6x9B *source) {
    copy_subcommand_header(arg0, source);
    arg0->num_levels = source->num_levels;
    __copy(arg0->unused, source->unused, 3);
    return arg0;
}

void* copy_subcommand_header(void* p, void* source) { assign_subcommand_header(p, source); return p; }

void assign_subcommand_header(void *destination, void *source) {
    u8 *out = static_cast<u8 *>(destination);
    const u8 *in = static_cast<const u8 *>(source);
    out[0] = in[0];
    out[1] = in[1];
#ifdef __MWERKS__
    __memcpy(out + 2, in + 2, 2);
#else
    memcpy(out + 2, in + 2, 2);
#endif
}

void TFontSmallLobby::init_packet_6x9b_level_up() {
    u8 *arg0 = (u8 *)this;
    *(s8 *)((s8 *)arg0 + 4) = 0;
    *(s8 *)((s8 *)arg0 + 5) = 0;
    *(s8 *)((s8 *)arg0 + 6) = 0;
    *(s8 *)((s8 *)arg0 + 7) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0x9B;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void send_6x9B_level_up_all_techniques(void* p) { bswap_g_client_id_header(p); send_subcommand((u8 *)p); }

void TFontSmallLobby::bswap_battle_damage_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void* TFontSmallLobby__sub_801C030C(void* p, void* source) { copy_subcommand_header(p, source); *(short*)((char*)p + 0x4) = *(unsigned short*)((char*)source + 0x4); *(short*)((char*)p + 0x6) = *(short*)((char*)source + 0x6); return p; }

void TFontSmallLobby::init_packet_6x8f_battle_damage() {
    O_801C0350 *p = (O_801C0350 *)this;
    p->c = 0xFFFF;
    p->d = 0;
    p->a = 0x8f;
    p->b = 2;
}

void send_6x8F_add_battle_damage_scores(void* p) { ((TFontSmallLobby *)p)->bswap_battle_damage_packet(); ((game_command *)p)->send(); }

void TFontSmallLobby::bswap_6x90_set_player_battle_team() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); }

void *TFontSmallLobby__sub_801C03E0(G_SetPlayerBattleTeam_6x90 *arg0, G_SetPlayerBattleTeam_6x90 *source) {
    copy_subcommand_header(arg0, source);
    arg0->team_number = source->team_number;
    return arg0;
}

void init_packet_6x90_set_player_battle_team(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 4) = 0;
    *(u8 *)((s8 *)arg0 + 0) = 0x90;
    *(s8 *)((s8 *)arg0 + 1) = 2;
}

void init_packet_6x82_enable_drop_weapon_on_death(void* p) { *(u8*)((char*)p + 0x0) = 130; *(u8*)((char*)p + 0x1) = 1; }

void send_6x82_enable_drop_weapon_on_death(void* p) { bswap_g_client_id_header(p); send_subcommand((u8 *)p); }

void init_packet_6x81_disable_drop_weapon_on_death(void* p) { *(u8*)((char*)p + 0x0) = 129; *(u8*)((char*)p + 0x1) = 1; }

void TFontSmallLobby::send_font_state_msg() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }

void init_packet_6x7B_disable_stealth_suit_effect(void* p) { *(u8*)((char*)p + 0x0) = 123; *(u8*)((char*)p + 0x1) = 1; }

void send_6x7B_disable_stealth_suit_effect(void* p) { bswap_g_client_id_header(p); send_subcommand((u8 *)p); }

void init_packet_6x7A_enable_stealth_suit_effect(void* p) { *(u8*)((char*)p + 0x0) = 122; *(u8*)((char*)p + 0x1) = 1; }

void TLobby::cleanup_small_font() { bswap_g_client_id_header(this); send_subcommand((u8 *)this); }

void init_packet_6x1C_disable_pk_mode_for_player(void* p) { *(u8*)((char*)p + 0x0) = 28; *(u8*)((char*)p + 0x1) = 1; }

void send_6x1C_disable_pk_mode_for_player(void* p) { bswap_g_client_id_header(p); send_subcommand((u8 *)p); }

void init_packet_6x1B_enable_pk_mode_for_player(void* p) { *(u8*)((char*)p + 0x0) = 27; *(u8*)((char*)p + 0x1) = 1; }

void send_6x1B_enable_pk_mode_for_player(void* p) { bswap_g_client_id_header(p); send_subcommand((u8 *)p); }

void init_packet_6x23_set_player_visible(void* p) { *(u8*)((char*)p + 0x0) = 35; *(u8*)((char*)p + 0x1) = 1; }

void send_6x23_set_player_visible(void* p) { bswap_g_client_id_header(p); send_subcommand((u8 *)p); }

void fn_801C0630(void* p) { *(u8*)((char*)p + 0x0) = 34; *(u8*)((char*)p + 0x1) = 1; }

void fn_801C0644(void* p) { bswap_g_client_id_header(p); send_subcommand((u8 *)p); }

void TObjPlayer::bswap_change_hp_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)((void *)((char *)this + 4)));
    bswap_16((u16 *)((void *)((char *)this + 8)));
    bswap_16((u16 *)((void *)((char *)this + 10)));
}

void *TObjPlayer__sub_801C06BC(G_ChangePlayerHP_6x2F *arg0, G_ChangePlayerHP_6x2F *source) {
    copy_subcommand_header(arg0, source);
    arg0->type = source->type;
    arg0->amount = source->amount;
    arg0->client_id = source->client_id;
    return arg0;
}

void TObjPlayer::init_6x2F_packet_header() {
    O_801C0708 *p = (O_801C0708 *)this;
    p->c = 0;
    p->d = 0;
    p->e = 0xFFFF;
    p->a = 0x2f;
    p->b = 3;
}

void TObjPlayer__sub_801C0734(void* p) { ((TObjPlayer *)p)->bswap_change_hp_packet(); send_subcommand((u8 *)p); }

void TObjPlayer::byteswap_packet_body() {
    ((G_ClientIDHeader *)this)->bswap();
    bswap_32((u32 *)((void *)((char *)this + 4)));
    bswap_32((u32 *)((void *)((char *)this + 8)));
    bswap_32((u32 *)((void *)((char *)this + 12)));
    bswap_32((u32 *)((void *)((char *)this + 16)));
}
u8 *TObjPlayer__sub_801C07B4(u8 *arg0, u8 *source) {
    copy_subcommand_header(arg0, source);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)source + 4);
    *(ByteBlock_C *)((saddr) arg0 + 8) = *(const ByteBlock_C *)((saddr) source + 8);
    return arg0;
}

}
