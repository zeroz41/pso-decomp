#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 is_invalid_slot__10TObjPlayerFUc(s32 level);

struct Rec_801D96CC { u8 a; u8 pad[3]; s16 b; };

s32 set_technique_level_entry(s32, s16, s32);
s32 get_cast_technique_level(s32, s16);
u8 get_effective_technique_level__10TObjPlayerFPvs(void *, int);
s32 TObjPlayer__sub_801C010C(void *, s16);
s32 clamp_to_max__10TObjPlayerFlUcUc(void *, s32, s32);

s16 TObjPlayer::get_section_clamped() {
    s16 temp_r4;

    temp_r4 = *(s16 *)&this->m_id;
    if ((temp_r4 < 0) || (temp_r4 > 0xA)) {
        *(s16 *)&this->m_id = 0;
    }
    return *(s16 *)&this->m_id;
}

s16 TObjPlayer::get_or_init_field_4() {
    if (TObjPlayer::is_valid_technique_id(*(s16 *)&this->m_flags) == 0) {
        this->set_technique_id((s16)0);
    }
    return *(s16 *)&this->m_flags;
}

void TObjPlayer::split_capped_value(u8 level, u8 *arg1, s8 *arg2) {
    if ((TObjPlayer::is_invalid_slot(level) != 0) || (level <= 0xEU)) {
        *arg1 = level;
        *arg2 = 0;
        return;
    }
    *arg1 = 0xE;
    *arg2 = level - 0xE;
}

u8 TObjPlayer::get_valid_technique() {
    u8 var_r31;

    var_r31 = *(u8 *)((s8 *)this + 1);
    if (TObjPlayer::is_valid_technique_slot(var_r31) == 0) {
        var_r31 = 0;
    }
    return var_r31;
}

u8 TObjPlayer::get_castable_technique_level() {
    u8 a = ((Rec_801D96CC *)this)->a;
    u8 t;
    if (TObjPlayer::check_technique_level((saddr)(((Rec_801D96CC *)this)), (s32)(((Rec_801D96CC *)this)->b), (u8)a) == 0) {
        a = 0x1D;
    }
    if (TObjPlayer::is_invalid_slot(a) != 0) {
        return a;
    }
    t = get_effective_technique_level__10TObjPlayerFPvs(((Rec_801D96CC *)this), ((Rec_801D96CC *)this)->b);
    if (TObjPlayer::is_invalid_slot(t) != 0) {
        return TObjPlayer::get_item_count_max();
    }
    if (a > t) {
        a = t;
    }
    return a;
}

void TObjPlayer::update_all_units(s32 levels, s32 level) {
    s32 var_r31;

    var_r31 = 0;
    do {
        if (is_invalid_slot__10TObjPlayerFUc(get_cast_technique_level(levels, (s16) var_r31)) == 0) {
            set_technique_level_entry(levels, (s16) var_r31, level);
        }
        var_r31 += 1;
    } while (var_r31 < 0x13);
}

void TObjPlayer::level_up_all_techniques(s32 add) {
    s32 i = 0;
    do {
        s32 v = ((s32 (*)(void *, s16))get_cast_technique_level)(this, i);
        if (is_invalid_slot__10TObjPlayerFUc(v) == 0) {
            v += add;
            v = clamp_to_max__10TObjPlayerFlUcUc(this, v, ((s32 (*)(void *, s16))get_effective_technique_level__10TObjPlayerFPvs)(this, i));
            ((void (*)(void *, s16, s32))set_technique_level_entry)(this, i, clamp_to_max__10TObjPlayerFlUcUc(this, v, TObjPlayer__sub_801C010C(this, i)));
        }
        i++;
    } while (i < 0x13);
}

}
