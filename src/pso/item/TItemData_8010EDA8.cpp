#include "types.h"
#include "pso/item/TItemData_8010EDA8.h"
#include "pso/item/TItemData.h"
#include "pso/item/MagStats.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
extern u8 *text_language_group_table;
s32 get_class_index__10TObjPlayerFv(void *);

void add_elt_resist(void *res, s32 amount) {
    *(s16 *)((s8 *)res + 8) = (s16) (*(s16 *)((s8 *)res + 8) + amount);
}

void TItemData::add_quantity(s32 amount) {
    *(s16 *)((s8 *)this + 0xA) = (s16) (*(s16 *)((s8 *)this + 0xA) + amount);
}

void add_eth_resist(void *res, s32 amount) {
    *(s16 *)((s8 *)res + 6) = (s16) (*(s16 *)((s8 *)res + 6) + amount);
}

void TItemData__sub_8010EDD8(void *res, s32 amount) {
    *(s16 *)((s8 *)res + 4) = (s16) (*(s16 *)((s8 *)res + 4) + amount);
}

void TItemData::adjust_count(s32 amount) {
    *(s16 *)((s8 *)this + 2) = (s16) (*(s16 *)((s8 *)this + 2) + amount);
}

void TItemData::add_stat_ptr(s16 *arg0, s32 amount) {
    *arg0 += amount;
}

void TItemData::add_bonus(s16 amount) {
    *(s32 *)((s8 *)this + 0x1C) = (s32) (*(s32 *)((s8 *)this + 0x1C) + amount);
}

void subtract_dfp(void *arg0, s16 arg1) {
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) (*(s32 *)((s8 *)arg0 + 0x1C) - arg1);
}

void subtract_stat_ptr(s16 *arg0, s32 arg1) {
    *arg0 -= arg1;
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
saddr get_text_collection(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)text_language_group_table) + (arg0 * 4));
}

}
