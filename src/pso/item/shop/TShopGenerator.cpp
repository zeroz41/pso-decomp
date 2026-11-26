#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/NinjaUtil.h"
#include "pso/system/save/CardFileInfo.h"
#include "types.h"
#include "pso/system/MatrixOps.h"
#include "pso/item/shop/TShopGenerator.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"

#include <stddef.h>
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/city/TMedicalCenterMes.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_80222C28.h"
#include "pso/network/TLobby.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/ui/city/TShopEquipmentSequence.h"
#include "pso/ui/city/TMedicalCenterSequence.h"
#include "pso/ui/city/TShopEquipmentGearSequence.h"
#include "pso/ui/city/TShopItemTecSequence.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/city/TJudgmentSequence.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

ShopService TShopGenerator::service_dispatch_table[7] = {
    {"WEAPON STORE", TShopEquipmentSequence__sub_8021DC08, TShopEquipmentSequence__sub_8021DBE0,
     TShopEquipmentSequence::create_instance, get_equipment_shop_slot_active_flag},
    {"MEDICAL CENTER", TMedicalCenterSequence::clear_window_slots, TMedicalCenterSequence::clear_slot_data,
     create_medical_center_sequence, get_medical_center_slot_active_flag},
    {"GEAR STORE", TShopEquipmentGearSequence::clear_window_slot_table, TShopEquipmentGearSequence::clear_window_slots,
     TShopEquipmentGearSequence::create_instance, get_equipment_gear_shop_window_slot},
    {"ITEM STORE", TShopItemTecSequence__sub_80220560, TShopItemTecSequence__sub_80220538,
     create_shop_item_tec_sequence, get_item_technique_shop_slot},
    // TLobby::handle_main_phase and is_in_hunter_guild still carry recovered s32 prototypes; the table
    // proves create(void *) / int(int) (follow-up: retype them with their callers).
    {"HUNTER GUILD", TLobby::update_guild_or_quest_phase, update_hunter_guild_phase,
     (void *(*)(void *))TLobby::handle_main_phase, (int (*)(int))is_in_hunter_guild},
    {"CHECK ROOM", TCheckRoomSequence::reset_slots, TCheckRoomSequence::reset_slot_state,
     TCheckRoomSequence::create, get_check_room_slot_active_flag},
    {"JUDGMENT", TJudgmentSequence__sub_80216058, TJudgmentSequence__sub_80216030,
     TJudgmentSequence::create, get_judgment_shop_slot_flags},
};

const char *TShopGenerator::class_name = "TShopGenerator";

s32 TShopGenerator::slot_active_table[4];

extern "C" {
f32 vec3_dot(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
extern s32 lbl_805D55C0;
// run_task reads the bool through an int-returning call (no clrlwi after either call); kept as found.
bool is_player_in_service_range__14TShopGeneratorFPUcf(u8 *self, u8 *player, f32 range);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
bool TShopGenerator::is_player_in_service_range(u8 *player, f32 range) {
    f32 to_self[3];
    if (xyz_distance_squared(&reinterpret_cast<const TObjBase *>(player)->position, &position) > (range * range)) {
        return 0;
    }
    f32 facing[3] = {0.0f, 0.0f, -1.0f};
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, (int) reinterpret_cast<const TObjBase *>(player)->rotation_y);
    rotate_vector_by_matrix(0, facing, facing);
    pop_matrix();
    to_self[0] = this->position.x - reinterpret_cast<const TObjBase *>(player)->position.x;
    to_self[1] = this->position.y - reinterpret_cast<const TObjBase *>(player)->position.y;
    to_self[2] = this->position.z - reinterpret_cast<const TObjBase *>(player)->position.z;
    normalize_vector((Vec *)to_self);
    return (vec3_dot(facing, to_self) > -0.5f) == 0;
}
#pragma pop

s32 TShopGenerator::is_no_service_active(void *self, saddr player) {
    s32 i;
    int (*get_slot_flag)(int);
    for (i = 0; i < 7; i++) {
        get_slot_flag = service_dispatch_table[i].get_slot_flag;
        if (get_slot_flag((u16)get_client_split_screen_slot(((TObjBase *)(player))->get_entity_id())) == 1) {
            return 0;
        }
    }
    return 1;
}

void TShopGenerator::run_task() {
    ShopService *service;
    s32 i;
    saddr p;
    int (*get_slot_flag)(int);
    service = &service_dispatch_table[this->set_params[0]];
    if (this->service_check_delay > 0) {
        this->service_check_delay--;
        return;
    }
    if (lbl_805D55C0 != 0) {
        return;
    }
    if (poll_memcard_result((s8)TAdSinglePlyChrSelectGC::get_chr_select_state()) != 0) {
        return;
    }
    if (TAdPlayerLoadGC::get_instance() != 0) {
        return;
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            p = (saddr)get_player_by_client_id(i);
            if (p == 0) continue;
            if (((s32 (*)(u8 *, u8 *, f32))is_player_in_service_range__14TShopGeneratorFPUcf)((u8 *)this, (u8 *)p, 20.0f) == 0) continue;
            if (is_slot_active(((TObjBase *)(p))->get_entity_id()) == 1) continue;
            if (TMedicalCenterMes::get_slot_flag(((TObjBase *)(p))->get_entity_id()) == 1) continue;
            if (((TObjPlayer *)p)->is_action_input_disabled() == 1) continue;
            if (((TObjPlayer *)p)->is_controls_locked() == 1) continue;
            get_slot_flag = service->get_slot_flag;
            if (get_slot_flag((u16)get_client_split_screen_slot(((TObjBase *)(p))->get_entity_id())) == 1) continue;
            if (test_pressed_buttons_packed(&controller_input_state.controllers[((TObjPlayer *)p)->get_controller_port()], 4) == 0) continue;
            service->create((void *)p);
        }
    } else {
        saddr q;
        int (*get_slot_flag2)(int);
        q = (saddr)get_player_by_client_id(local_client_id);
        if (q == 0) return;
        if (is_slot_active(((TObjBase *)(q))->get_entity_id()) == 1) return;
        if (TMedicalCenterMes::get_slot_flag(((TObjBase *)(q))->get_entity_id()) == 1) return;
        if (((TObjPlayer *)q)->is_action_input_disabled() == 1) return;
        if (((TObjPlayer *)q)->is_controls_locked() == 1) return;
        if (is_no_service_active(this, q) == 0) return;
        get_slot_flag2 = service->get_slot_flag;
        if (get_slot_flag2((u16)get_client_split_screen_slot(((TObjBase *)(q))->get_entity_id())) == 1) return;
        if (((s32 (*)(u8 *, u8 *, f32))is_player_in_service_range__14TShopGeneratorFPUcf)((u8 *)this, (u8 *)q, 20.0f) == 0) return;
        if (test_pressed_buttons_packed(&controller_input_state.controllers[((TObjPlayer *)q)->get_controller_port()], 4) == 0) return;
        service->create((void *)q);
    }
}

TShopGenerator::~TShopGenerator() {
}

TShopGenerator::TShopGenerator(saddr set_data) : TObjBase(tl_05) {
    s32 service_index;
    m_name = class_name;
    this->apply_object_set_data((void *)set_data);
    this->m_90 = 0;
    this->service_check_delay = 5;
    service_index = this->set_params[0];
    if (service_index < 0) {
        queue_destruction();
        return;
    }
    if (service_index > 6) {
        queue_destruction();
        return;
    }
}

int TShopGenerator::is_slot_active(u16 client) {
    return slot_active_table[(u16)get_client_split_screen_slot(client)] == 1;
}

void TShopGenerator::clear_slot_active(u16 client) {
    u16 idx = get_client_split_screen_slot(client);
    slot_active_table[idx] = 0;
}


void set_shop_slot_active(u16 client) {
    u16 idx = get_client_split_screen_slot(client);
    TShopGenerator::slot_active_table[idx] = 1;
}

void *TShopGenerator::create(void *set_data) {
    void *o = (void *)new TShopGenerator((saddr)set_data);
    return o;
}

void TShopGenerator::run_fn_table_reverse() {
    ShopService *p;
    s32 n;
    s32 i;
    TMedicalCenterMes::clear_slot_flags();
    p = &service_dispatch_table[7];
    n = 7;
    do {
        void (*f)() = (p - 1)->reverse_fn;
        p--;
        f();
    } while (--n > 0);
    for (i = 0; i < 4; i++) {
        slot_active_table[i] = 0;
    }
}

void TShopGenerator::run_fn_table_forward() {
    ShopService *p;
    s32 n;
    s32 i;
    n = 7;
    p = &service_dispatch_table[0];
    do {
        p->forward_fn();
        p++;
    } while (--n > 0);
    TMedicalCenterMes__sub_80216260();
    for (i = 0; i < 4; i++) {
        slot_active_table[i] = 0;
    }
}

void *TShopEquipmentSequence::create_instance(void *player) {
    return new TShopEquipmentSequence(tl_05, (TObjPlayer *)player);
}

int get_equipment_shop_slot_active_flag(int slot) { return TShopEquipmentSequence::slot_active_flags[slot]; }

void *create_medical_center_sequence(void *player) {
    return new TMedicalCenterSequence(tl_05, (TObjPlayer *)player);
}

int get_medical_center_slot_active_flag(int slot) { return medical_center_slot_active_flags[slot]; }

void *TShopEquipmentGearSequence::create_instance(void *player) {
    return new TShopEquipmentGearSequence(tl_05, (TObjPlayer *)player);
}

int get_equipment_gear_shop_window_slot(int slot) { return TShopEquipmentGearSequence::window_slot_table[slot]; }

void *create_shop_item_tec_sequence(void *player) {
    return new TShopItemTecSequence(tl_05, (TObjPlayer *)player);
}

int get_item_technique_shop_slot(int slot) { return TShopItemTecSequence::slot_table[slot]; }

void *TCheckRoomSequence::create(void *player) {
    return new TCheckRoomSequence(tl_05, (TObjPlayer *)player);
}

int get_check_room_slot_active_flag(int slot) { return TCheckRoomSequence::slot_active_flags[slot]; }

void *TJudgmentSequence::create(void *player) {
    return new TJudgmentSequence(tl_05, (TObjPlayer *)player);
}

int get_judgment_shop_slot_flags(int slot) { return TJudgmentSequence::slot_flags[slot]; }
