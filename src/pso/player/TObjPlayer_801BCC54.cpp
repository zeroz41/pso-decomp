#include "types.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TLobby.h"

extern "C" {

u8 *get_class_attack_template(TObjPlayer *arg0);
u8 *get_class_defense_template(TObjPlayer *arg0);
s32 copy_data__6TLobbyFPvPv(void *);
void set_move_mode__10TObjPlayerFi(s32 arg0);

extern const f32 TObjPlayer__data_805DC28C;

void TObjPlayer::init_player_data() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    f32 yscale;

    temp_f31 = this->m_d48;
    copy_data__6TLobbyFPvPv(arg0 + 0xD38);
    this->m_d48 = temp_f31;
    this->m_2b0 = (arg0 + 0xD38);
    ((TObjPlayer *)arg0)->apply_input_mode();
    set_move_mode__10TObjPlayerFi((s32)arg0);
    ((TObjPlayer *)arg0)->init_trait_flags();
    ((TLobby *)(arg0 + 0xD5C))->copy_from((void *)(get_class_attack_template((TObjPlayer *)arg0)));
    ((TLobby *)(arg0 + 0xD8C))->copy_entry((void *)(get_class_defense_template((TObjPlayer *)arg0)));
    yscale = ((TObjPlayer *)arg0)->get_tp_class_factor();
    ((TObjChara *)arg0)->recalc_combat_stats(this->m_2b0, arg0 + 0xD5C, arg0 + 0xD8C, ((TObjPlayer *)arg0)->get_class_hp_factor(), yscale);
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (TObjPlayer__data_805DC28C * *(f32 *)((s8 *)this->m_2b0 + 0x10));
}

}
