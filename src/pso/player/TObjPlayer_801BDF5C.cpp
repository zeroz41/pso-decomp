#include "pso/player/PhotonBlastRequests.h"
#include "pso/player/PlayerState.h"
#include "types.h"
#include "pso/player/TObjPlayer_801BDF5C.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSnapShot_802A7D68.h"
#include "pso/ui/hud/TLockOnCursor_8013D91C.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/text_80354BE4.h"
#include "pso/player/TPlayerFootStamp.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/player/TObjPlayer_801BE1C0.h"
#include "pso/unk/text_801BE104.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/memory.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TPlyInventory.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/player/TObjPlayer_801BE778.h"
#include "pso/player/TObjPlayer_801BEB0C.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/PlayerSlots.h"


extern "C" {
}

u8 *TObjPlayer::create_player_instance(s32 arg0, saddr player) {
    u8 *p;
    p = (u8 *)new TObjPlayer(tl_03, arg0 & 0xFFFF, get_field_0_s32((void *)player), ((TObjPlayer *)player)->get_char_data());
    ((TLobby *)(p + 0xDAC))->copy_header_struct((void *)((TObjPlayer *)player)->get_sub_obj());
    ((TObjPlayer *)p)->reset_motion_fields();
    return p;
}

TObjPlayer *create_player_object(s32 slot, s32 role, TPlyCharData *record) {
    decode_created_player_inventory(record);
    return new TObjPlayer(tl_03, slot, role, record);
}

extern "C" {


PhotonBlastRegistry *TObjPlayer__shared_photon_blast_state;
s32 lobby_player_count;
extern uaddr TObjPlayer__shared_model_buffer;

void TObjPlayer::free_shared_data() {
    if (TObjPlayer__shared_photon_blast_state != NULL) {
        delete TObjPlayer__shared_photon_blast_state;
        TObjPlayer__shared_photon_blast_state = NULL;
    }
    if (player_shared_buffer_base != NULL) {
        mem_free(player_shared_buffer_base);
        player_shared_buffer_base = NULL;
    }
    if ((u32) TObjPlayer__shared_model_buffer != 0U) {
        mem_free((void*)TObjPlayer__shared_model_buffer);
        TObjPlayer__shared_model_buffer = 0U;
    }
}

void TObjPlayer::alloc_shared_buffers() {
    if ((u32) TObjPlayer__shared_model_buffer == 0U) {
        TObjPlayer__shared_model_buffer = (uaddr)mem_alloc((uaddr)(0x9000));
    }
    if (player_shared_buffer_base == NULL) {
        player_shared_buffer_base = static_cast<PlayerJointMatrixSet *>(mem_alloc(12 * sizeof(PlayerJointMatrixSet)));
    }
    if (TObjPlayer__shared_photon_blast_state == NULL) {
        TObjPlayer__shared_photon_blast_state = new PhotonBlastRegistry();
    }
}

}

    extern unsigned char lobby_rule_settings[];
    extern int lbl_805D5D7C;
    extern int shared_state_flags;
void TObjPlayer::finalize_shared() { TLobby::set_player_count((saddr)(0)); TObjPlayer::set_shared_count((saddr)(0)); TObjPlayer::set_shared_flag((saddr)(0)); lbl_805D5D7C = 0; ((TLobby *)lobby_rule_settings)->reset_settings_to_default(); shared_state_flags = 0; TLockOnCursor::free_cursor_resources(); free_snapshot_image_buffer(); TPlayerFootStamp::free_instance(); TObjPlayer::free_shared_data(); }

void TObjPlayer::init_shared() { TObjPlayer::alloc_shared_buffers(); TLobby::set_player_count((saddr)(0)); TObjPlayer::set_shared_count((saddr)(1)); TObjPlayer::set_shared_flag((saddr)(0)); lbl_805D5D7C = 0; TLobby::alloc_snapshot_buffer(); load_player_motion_data(); copy_if_space(); TWindowSnapShot::init_default(); TWindowSnapShot::free_shared_instance(); load_target_cursor_models(); load_player_footstamp(); reset_client_quest_slot_table(); shared_state_flags = 0; }

extern "C" {
extern u8 TObjPlayer__char_data_array[];
void __destroy_arr(void *arr, void *dtor, u32 size, u32 n);
void __register_global_object(void *obj, void *dtor, void *chain);
void *__construct_array(void *, void *, void *, u32, u32);
void init_char_data__10TObjPlayerFv(void *);

}

u8 TObjPlayer__arrival_override_table[0xF0];
u8 player_slot_table[0x30];
u8 lobby_rule_settings[0x24];
u8 lbl_8050EA64[0xC];
u8 TObjPlayer__char_data_array[0x42C * 0xC];


void __sinit_TObjPlayer_801BDF5C_cpp(void) {
    __construct_array(TObjPlayer__arrival_override_table, (void *)TObjPlayer__sub_801BFF80, NULL, 0x14, 0xC);
    ((TObjPlayer *)lobby_rule_settings)->reset_lobby_settings();
    __construct_array(TObjPlayer__char_data_array, (void *)init_char_data__10TObjPlayerFv, (void *)destroy_char_data__10TObjPlayerFis, 0x42C, 0xC);
    __register_global_object(NULL, (void *)TObjPlayer::destroy_char_data_array, lbl_8050EA64);
}

void TObjPlayer::destroy_char_data_array() {
    __destroy_arr(TObjPlayer__char_data_array, (void *)destroy_char_data__10TObjPlayerFis, 0x42c, 0xc);
}


__declspec(section ".ctors") static void *const __sinit_TObjPlayer_801BDF5C_cpp_ref = (void *)__sinit_TObjPlayer_801BDF5C_cpp;

extern "C" {

int subtract_photon_blast_charge(void*, f32);

s32 destroy_char_data__10TObjPlayerFis(saddr arg0, s16 arg1) {
    if (arg0 != 0) {
        ((TPlyCharData *)(arg0 + 0xC))->~TPlyCharData();
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

void TObjPlayer::get_pos(saddr out) {
    this->get_anim_node_position(0x3A, (Vec *)out);
}

void TObjPlayer::spend_photon_blast_charge(f32 charge) { photon_blast_gauge.subtract_photon_blast_charge(charge); }

void TObjPlayer::gain_photon_blast_chain_charge(f32 amount) { add_photon_blast_chain_charge(&photon_blast_gauge, amount); }

s32 TObjPlayer::vfunc_79() { return 0; }
s32 TObjPlayer::check_camera_mode() {
    return (u8)((u8) (is_quest_active() == 1));
}
void TObjPlayer::set_regen_timer(s32 v) { this->pad_370 = v; }
s32 TObjPlayer::get_regen_timer() { return this->pad_370; }
int TObjPlayer::is_newman() { return (this->class_flags & CLASS_FLAG_NEWMAN) != 0; }
int TObjPlayer::is_android() { return (this->class_flags & CLASS_FLAG_ANDROID) != 0; }
void TObjPlayer::check_stat_flag_41c() { ((FlagWord *)((char*)this + 0x41c))->set(32); }
void TObjPlayer::check_flag_at_41c() { ((FlagWord *)((char*)this + 0x41c))->set(4); }
void TObjPlayer::set_flag_41c_bit1() { ((FlagWord *)((char*)this + 0x41c))->set(2); }
void TObjPlayer::clamp_stat_41c() { ((FlagWord *)((char*)this + 0x41c))->set(8); }

}

s8 TObjPlayer::get_rule_field_0() {
    return ((TLobby *)lobby_rule_settings)->get_rule_field_0();
}

struct Base_801BE3D8 { char pad[0x8]; };
struct VObj_801BE3D8 : Base_801BE3D8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual int m25();
};
struct Base_801BE40C { char pad[0x8]; };
struct VObj_801BE40C : Base_801BE40C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual int m22();
};
struct Base_801BE440 { char pad[0x8]; };
struct VObj_801BE440 : Base_801BE440 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual int m24();
};
struct Base_801BE474 { char pad[0x8]; };
struct VObj_801BE474 : Base_801BE474 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual int m26();
};
struct Base_801BE4A8 { char pad[0x8]; };
struct VObj_801BE4A8 : Base_801BE4A8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual int m26();
};
struct Base_801BE4DC { char pad[0x8]; };
struct VObj_801BE4DC : Base_801BE4DC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual int m19();
};
struct Base_801BE510 { char pad[0x8]; };
struct VObj_801BE510 : Base_801BE510 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual int m27();
};
struct Base_801BE544 { char pad[0x8]; };
struct VObj_801BE544 : Base_801BE544 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual int m14();
};
struct Base_801BE578 { char pad[0x8]; };
struct VObj_801BE578 : Base_801BE578 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual int m17();
};
struct Base_801BE5AC { char pad[0x8]; };
struct VObj_801BE5AC : Base_801BE5AC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual int m16();
};
struct Base_801BE5E0 { char pad[0x8]; };
struct VObj_801BE5E0 : Base_801BE5E0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual int m15();
};
struct Base_801BE614 { char pad[0x8]; };
struct VObj_801BE614 : Base_801BE614 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual int m28();
};

extern "C" {


void TObjPlayer::clear_flag_400000() {
    clear_state_flags(0x400000);
}

short TObjPlayer::get_model_field_m25() {
    struct VObj_801BE3D8 *o = (struct VObj_801BE3D8 *)this->action_provider;
    return o->m25();
}

short TObjPlayer::get_action_animation() {
    struct VObj_801BE40C *o = (struct VObj_801BE40C *)this->action_provider;
    return o->m22();
}

short TObjPlayer::call_model_m24() {
    struct VObj_801BE440 *o = (struct VObj_801BE440 *)this->action_provider;
    return o->m24();
}

short TObjPlayer::get_weapon_stat_c() {
    struct VObj_801BE474 *o = (struct VObj_801BE474 *)this->action_provider;
    return o->m26();
}

short TObjPlayer::call_obj_vt26() {
    struct VObj_801BE4A8 *o = (struct VObj_801BE4A8 *)this->action_provider;
    return o->m26();
}

short TObjPlayer::query_child_state() {
    struct VObj_801BE4DC *o = (struct VObj_801BE4DC *)this->action_provider;
    return o->m19();
}

short TObjPlayer::query_equip() {
    struct VObj_801BE510 *o = (struct VObj_801BE510 *)this->action_provider;
    return o->m27();
}

short TObjPlayer::get_status() {
    struct VObj_801BE544 *o = (struct VObj_801BE544 *)this->action_provider;
    return o->m14();
}

short TObjPlayer::get_model_state() {
    struct VObj_801BE578 *o = (struct VObj_801BE578 *)this->action_provider;
    return o->m17();
}

short TObjPlayer::get_state() {
    struct VObj_801BE5AC *o = (struct VObj_801BE5AC *)this->action_provider;
    return o->m16();
}

short TObjPlayer::call_subobject_m15() {
    struct VObj_801BE5E0 *o = (struct VObj_801BE5E0 *)this->action_provider;
    return o->m15();
}

short TObjPlayer::get_vobj_state_28() {
    struct VObj_801BE614 *o = (struct VObj_801BE614 *)this->action_provider;
    return o->m28();
}

extern "C" TObjPlayer *get_local_player() {
    return get_player_by_client_id(local_client_id);
}

int copy_subcommand_header(void*);

void TObjPlayer::clear_flag_200000() {
    clear_state_flags(0x200000);
}
int TObjPlayer::check_flag_4() { return check_flag(4); }
void*TObjPlayer::set_invisible() { copy_subcommand_header(this); return this; }
void TObjPlayer::clear_flag_4000_callback() { clear_flag_4000(); }
void TObjPlayer::clear_flag_4000() { clear_state_flags(16384); }
void TObjPlayer::set_flag_4000() { this->set_state_flags(16384); }
void TObjPlayer::set_battle_flag(s32 v) { this->m_3b4 = v; }
s32 TObjPlayer::get_anim_id() { return this->m_3b4; }
int TObjPlayer::check_flag_0x40000000() { return (this->state_flags >> 30) & 0x1; }
void TObjPlayer::clear_flag_0x2() { this->state_flags &= 0xfffffffd; }


int TObjPlayer::is_action_active() { return (this->state_flags >> 1) & 0x1; }
void TObjPlayer__sub_801BE784(void* p, u8 v) { *(u8*)((char*)p + 0x2e7) = v; }
u8 TObjPlayer::get_battle_mode() { return *(u8*)((char*)this + 0x33a); }
void TObjPlayer__sub_801BE794(void* p, u8 v) { *(u8*)((char*)p + 0x2cb) = v; }
u8 TObjPlayer::get_byte_339() { return this->m_339; }
void TObjPlayer__sub_801BE7A4(void* p, u8 v) { *(u8*)((char*)p + 0x2af) = v; }
u8 TObjPlayer::get_mag_level() { return *(u8*)((char*)this + 0x338); }
void TObjPlayer__sub_801BE7B4(void* p, u8 v) { *(u8*)((char*)p + 0x293) = v; }
u8 TObjPlayer::get_luck_materials_used() { return materials.get_luck_used(); }
void TObjPlayer__sub_801BE7E0(void* p, u8 v) { *(u8*)((char*)p + 0x277) = v; }
u8 TObjPlayer::get_def_materials_used() { return materials.get_def_used(); }
void TObjPlayer__sub_801BE80C(void* p, u8 v) { *(u8*)((char*)p + 0x25b) = v; }
u8 TObjPlayer::get_evade_materials_used() { return materials.get_evade_used(); }
void TObjPlayer__sub_801BE838(void* p, u8 v) { *(u8*)((char*)p + 0x23f) = v; }
u8 TObjPlayer::get_mind_materials_used() { return materials.get_mind_used(); }
void TObjPlayer__sub_801BE864(void* p, u8 v) { *(u8*)((char*)p + 0x223) = v; }
u8 TObjPlayer::get_power_materials_used() { return materials.get_power_used(); }

}

struct Inv_801BE890 { s32 f0; TPlyInventoryItem items[0x1E]; };

extern "C" {
Inv_801BE890 *init_inventory_list__10TObjPlayerFPv(Inv_801BE890 *arg0);

Inv_801BE890 *init_inventory_list__10TObjPlayerFPv(Inv_801BE890 *arg0) {
    s32 i;
    arg0->f0 = 0;
    for (i = 0; i < 0x1E; i++) {
        arg0->items[i].init();
    }
    return arg0;
}

void TObjPlayer::set_move_mode(s32 v) { this->m_3dc = v; }
void TObjPlayer::set_input_mode(s32 v) { this->m_3d8 = v; }

}

struct E_801BE8F4 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };

struct O_801BE8F4 { u8 pad[0xa4]; E_801BE8F4 *entries; };

extern "C" {
u8 TObjPlayer__sub_801BE8F4(O_801BE8F4 *self, s32 i, u32 mask);

u8 TObjPlayer__sub_801BE8F4(O_801BE8F4 *self, s32 i, u32 mask) {
    return (self->entries[i].flags & mask) != 0;
}

void* TObjPlayer::get_position_history_entry(int a1, void* a2, void* a3) { *(float*)((char*)a2 + 0x0) = *(float*)((char*)this + a1 * 8 + 0x6b0); *(float*)((char*)a3 + 0x0) = *(float*)((char*)this + a1 * 8 + 0x6b4); return (char*)this + a1 * 8; }
s32 TObjPlayer::clamp_index_to_max(s32 level) {
    s32 max_level;

    max_level = level;
    if (max_level < 0) {
        max_level = 0;
    } else if (max_level > TObjPlayer::get_max_level()) {
        max_level = TObjPlayer::get_max_level();
    }
    return max_level;
}
s32 TObjPlayer::clamp_nested_index() {
    return TObjPlayer::clamp_index_to_max(this->stat_block->level);
}
void TObjPlayer::clear_flag_20000() {
    clear_state_flags(0x20000);
}
void TObjPlayer::set_flag_20000() {
    set_state_flags(0x20000);
}
void TObjPlayer::clear_flag_2000000() {
    clear_state_flags(0x02000000);
}
int TObjPlayer::check_flag_02000000() {
    return check_flag(0x02000000);
}

void TObjPlayer::set_position_history_entry(s32 arg1, f32 farg0, f32 farg1) {
    saddr arg0 = (saddr)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)(arg0 + (arg1 * 8));
    *(f32 *)((s8 *)temp_r3 + 0x6B0) = farg0;
    *(f32 *)((s8 *)temp_r3 + 0x6B4) = farg1;
}

}


void TObjPlayer::set_action_flag_2() { this->state_flags |= 0x2; }
void set_flag_400000(TObjPlayer *player) {
    player->set_state_flags(0x400000);
}
int TObjPlayer::check_flag_48() { return check_flag(48); }
int TObjPlayer::is_status_locked() { return this->actorFlags & 0x10000; }
int TObjPlayer::is_status_flag_200() { return this->actorFlags & 0x200; }
int TObjPlayer__sub_801BEABC(void* p) { return ((TObjPlayer *)p)->end_camera_pan(); }
int TObjPlayer::start_freeze_self() { return start_freeze(); }
void TObjPlayer::set_floor(s32 v) { this->current_floor = v; }
void TObjPlayer::set_floor_index(s32 v) { current_area = v; }

extern "C" {


s32 TObjPlayer::get_state_flags() { return this->state_flags; }
int TObjPlayer::unregister_sub() { return unregister_object_by_id(); }
void TObjPlayer::set_control_role(s32 v) { *(s32 *)&this->unk_3E8 = v; }
u8 TObjPlayer__sub_801BEB3C(void* p) { return *(u8*)((char*)p + 0x2e7); }
u8 TObjPlayer__sub_801BEB44(void* p) { return *(u8*)((char*)p + 0x2cb); }
u8 TObjPlayer__sub_801BEB4C(void* p) { return *(u8*)((char*)p + 0x2af); }
void TObjPlayer::set_language(s32 v) { this->language = v; }
void TObjPlayer::reset_entrance_id() { *(s32*)((char*)this + 0x3c8) = -1; }
void TObjPlayer::set_luck_materials_used(u8 v) { materials.set_luck_used(v); }
u8 TObjPlayer__sub_801BEB8C(void* p) { return *(u8*)((char*)p + 0x293); }
void TObjPlayer::set_equip_flags(u8 v) { materials.set_def_used(v); }
u8 TObjPlayer__sub_801BEBB8(void* p) { return *(u8*)((char*)p + 0x277); }
void TObjPlayer::set_inventory_state(u8 v) { materials.set_evade_used(v); }
u8 TObjPlayer__sub_801BEBE4(void* p) { return *(u8*)((char*)p + 0x25b); }
void TObjPlayer::set_field_374_state(u8 v) { materials.set_mind_used(v); }
u8 TObjPlayer__sub_801BEC10(void* p) { return *(u8*)((char*)p + 0x23f); }
void TObjPlayer::set_field_374(u8 v) { materials.set_power_used(v); }
u8 TObjPlayer__sub_801BEC3C(void* p) { return *(u8*)((char*)p + 0x223); }

}
