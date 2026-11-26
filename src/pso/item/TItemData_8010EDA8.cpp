#include "types.h"
#include "pso/item/TItemData_8010EDA8.h"
#include "pso/item/TItemData.h"
#include "pso/item/MagStats.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"

extern u8 *text_language_group_table;
extern "C" {
s32 get_class_index__10TObjPlayerFv(void *);
}

void ActorParamBlock::add_elt(s32 amount) {
    values[4] = values[4] + amount;
}

void ActorParamBlock::add_edk(s32 amount) {
    values[5] = values[5] + amount;
}

void ActorParamBlock::add_eth(s32 amount) {
    values[3] = values[3] + amount;
}

void ActorParamBlock::add_eic(s32 amount) {
    values[2] = values[2] + amount;
}

void ActorParamBlock::add_efr(s32 amount) {
    values[1] = values[1] + amount;
}

void ActorParamBlock::add_evp(s32 amount) {
    values[0] += amount;
}

void ActorParamBlock::add_dfp(s16 amount) {
    value_1c = value_1c + amount;
}

void ActorParamBlock::sub_dfp(s16 amount) {
    value_1c = value_1c - amount;
}
void ActorParamBlock::sub_evp(s32 amount) {
    values[0] -= amount;
}

s16 MagStats::get_mind_level() {
    return mind / 100;
}

s16 MagStats::get_def_level() {
    return def / 100;
}

s16 MagStats::get_dex_level() {
    return dex / 100;
}

s16 MagStats::get_pow_level() {
    return pow / 100;
}

s32 TObjPlayer::can_use_more_materials_for_class() {
    return this->materials.can_use_more_materials(get_class_index__10TObjPlayerFv(this));
}
saddr get_item_description_text(s32 name) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 4)) + (name * 4));
}
saddr get_text_collection(s32 index) {
    return *(s32 *)((s8 *)(*(saddr *)text_language_group_table) + (index * 4));
}
