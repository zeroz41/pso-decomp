#include "pso/system/TLanguage.h"
#include "types.h"
#include "pso/item/MaterialStats.h"
#include "pso/item/TItemData.h"
#include "pso/item/MagStats.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"


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

s16 MagStats::get_mind_level() const {
    return mind / 100;
}

s16 MagStats::get_def_level() const {
    return def / 100;
}

s16 MagStats::get_dex_level() const {
    return dex / 100;
}

s16 MagStats::get_pow_level() const {
    return pow / 100;
}

s32 TObjPlayer::can_use_more_materials_for_class() {
    return this->materials.can_use_more_materials(get_class_index());
}
saddr get_item_description_text(s32 name) {
    return (saddr)text_language_group_table[1][name];
}
const char *get_text_collection(s32 index) {
    return text_language_group_table[0][index];
}
