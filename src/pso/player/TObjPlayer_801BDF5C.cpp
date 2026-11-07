#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_801C1FF8.h"
#include "pso/unk/text_801BDE60.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSnapShot_802A7D68.h"
#include "pso/ui/hud/TLockOnCursor_8013D91C.h"
#include "pso/player/TPlayerFootStamp_802B01D8.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/text_80354BE4.h"
#include "pso/player/TPlayerFootStamp.h"
#include "pso/ui/hud/TLockOnCursor.h"
#include "pso/ui/window/TWindowSnapShot.h"
#include "pso/player/TObjPlayer_801BE1C0.h"
#include "pso/player/TObjPlayer_801BFED4.h"
#include "pso/unk/text_801BE104.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/memory.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TPlyPhotonChair.h"
#include "pso/player/TPlyInventoryItem_800721D4.h"
#include "pso/item/TItemLockCountCtrl_8011E184.h"
#include "pso/player/TObjPlayer_801BE778.h"
#include "pso/player/TObjPlayer_801BEB0C.h"

struct VBase_801BDE60 { u8 pad[0x18]; };

struct Obj_801BDE60 : VBase_801BDE60 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6();
};

extern "C" {
u8 * construct_player_instance__10TObjPlayerFlslPUc(void *, s32, s16, s32, void *);
u8 *__nw__7TObjectFUl(s32);
extern s32 tl_03;
s32 get_char_data__10TObjPlayerFv(void *);

u8 *TObjPlayer::create_player_instance(s32 arg0, s32 arg1) {
    u8 *p;
    p = __nw__7TObjectFUl(0xDB8);
    if (p != NULL) {
        p = ((u8 *(*)(void *, s32, u16, s32, s32))construct_player_instance__10TObjPlayerFlslPUc)(
            p, tl_03, arg0, TObjPlayer__sub_801C22B4((void *)arg1), get_char_data__10TObjPlayerFv((void *)arg1));
    }
    ((TLobby *)(p + 0xDAC))->copy_header_struct((void *)((TObjPlayer *)arg1)->get_sub_obj());
    ((Obj_801BDE60 *)p)->v6();
    return p;
}

u8 *create_player_object(s16 slot, s32 role, u8 *arg2) {
    u8 *player;
    u8 *var_r0;
    decode_created_player_inventory(arg2);
    player = (u8 *)(__nw__7TObjectFUl(0xDB8));
    var_r0 = player;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(construct_player_instance__10TObjPlayerFlslPUc(player, tl_03, slot, role, arg2));
    }
    return var_r0;
}

}

extern "C" {

void mem_free(void*);

extern u32 TObjPlayer__shared_photon_blast_state;
extern u32 TObjPlayer__shared_model_buffer;
extern u32 player_shared_buffer_base;

void TObjPlayer::free_shared_data() {
    if ((u32) TObjPlayer__shared_photon_blast_state != 0U) {
        destroy_photon_blast_array((void *)TObjPlayer__shared_photon_blast_state, 1);
        TObjPlayer__shared_photon_blast_state = 0U;
    }
    if ((u32) player_shared_buffer_base != 0U) {
        mem_free((void*)player_shared_buffer_base);
        player_shared_buffer_base = 0U;
    }
    if ((u32) TObjPlayer__shared_model_buffer != 0U) {
        mem_free((void*)TObjPlayer__shared_model_buffer);
        TObjPlayer__shared_model_buffer = 0U;
    }
}

}

extern "C" {
void *mem_alloc(u32 size);
void *construct_photon_blast_array(void *arg0);
void TObjPlayer::alloc_shared_buffers() {
    s32 temp_r3;
    s32 var_r0;
    if ((u32) TObjPlayer__shared_model_buffer == 0U) {
        TObjPlayer__shared_model_buffer = (u32)mem_alloc((u32)((void *)0x9000));
    }
    if ((u32) player_shared_buffer_base == 0U) {
        player_shared_buffer_base = (u32)mem_alloc((u32)((void *)0x4800));
    }
    if ((u32) TObjPlayer__shared_photon_blast_state == 0U) {
        temp_r3 = (int)::operator new(0x60);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = (s32)construct_photon_blast_array((void *)temp_r3);
        }
        TObjPlayer__shared_photon_blast_state = (u32) var_r0;
    }
}

}

    extern unsigned char lobby_rule_settings[];
    extern int lbl_805D5D7C;
    extern int shared_state_flags;
void TObjPlayer::finalize_shared() { set_player_count__6TLobbyFi((int)((void*)0)); TObjPlayer::set_shared_count((int)((void*)0)); TObjPlayer::set_shared_flag((int)((void*)0)); lbl_805D5D7C = 0; ((TLobby *)lobby_rule_settings)->reset_settings_to_default(); shared_state_flags = 0; TLockOnCursor::free_cursor_resources(); TLobby__sub_802A7BD8(); TPlayerFootStamp::free_instance(); TObjPlayer::free_shared_data(); }

void TObjPlayer::init_shared() { TObjPlayer::alloc_shared_buffers(); set_player_count__6TLobbyFi((int)((void*)0)); TObjPlayer::set_shared_count((int)((void*)1)); TObjPlayer::set_shared_flag((int)((void*)0)); lbl_805D5D7C = 0; TLobby::alloc_snapshot_buffer(); load_player_motion_data(); copy_if_space(); TWindowSnapShot::init_default(); TWindowSnapShot::free_shared_instance(); load_target_cursor_models(); load_player_footstamp(); TObjPlayer__sub_80354E7C(); shared_state_flags = 0; }

extern "C" {
extern u8 TObjPlayer__char_data_array[];
void __destroy_arr(void *arr, void *dtor, u32 size, u32 n);
void __register_global_object(void *obj, void *dtor, void *chain);
void *__construct_array(void *, void *, void *, u32, u32);
void init_char_data__10TObjPlayerFv(void *);

u8 TObjPlayer__arrival_override_table[0xF0];
u8 player_slot_table[0x30];
u8 lobby_rule_settings[0x24];
u8 lbl_8050EA64[0xC];
u8 TObjPlayer__char_data_array[0x42C * 0xC];
void TObjPlayer__sub_801BE104(void) {
    __construct_array(TObjPlayer__arrival_override_table, (void *)TObjPlayer__sub_801BFF80, NULL, 0x14, 0xC);
    ((TObjPlayer *)lobby_rule_settings)->reset_lobby_settings();
    __construct_array(TObjPlayer__char_data_array, (void *)init_char_data__10TObjPlayerFv, (void *)destroy_char_data__10TObjPlayerFis, 0x42C, 0xC);
    __register_global_object(NULL, (void *)TObjPlayer::destroy_char_data_array, lbl_8050EA64);
}

void TObjPlayer::destroy_char_data_array() {
    __destroy_arr(TObjPlayer__char_data_array, (void *)destroy_char_data__10TObjPlayerFis, 0x42c, 0xc);
}

}

__declspec(section ".ctors") static void *const __sinit_text_801BE104_cpp_ref = (void *)TObjPlayer__sub_801BE104;

extern "C" {

int is_quest_active(void);
int subtract_photon_blast_charge(void*, f32);
int add_photon_blast_chain_charge(void*);
int set__8FlagWordFUl(void*, int);

s32 destroy_char_data__10TObjPlayerFis(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        __dt__12TPlyCharDataFv(arg0 + 0xC, -1);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

void TObjPlayer::get_pos(s32 arg1) {
    this->get_anim_node_position(0x3A, (Vec *)arg1);
}

void TObjPlayer::vfunc_76(f32 charge) { subtract_photon_blast_charge((char*)this + 0x4ac, charge); }

void TObjPlayer::vfunc_77() { add_photon_blast_chain_charge((char*)this + 0x4ac); }

int TObjPlayer__vt77(void) { return 0; }
u8 TObjPlayer::check_camera_mode() {
    return (u8) (is_quest_active() == 1);
}
void TObjPlayer__sub_801BE2C0(void* p, s32 v) { *(s32*)((char*)p + 0x370) = v; }
s32 TObjPlayer__sub_801BE2C8(void* p) { return *(s32*)((char*)p + 0x370); }
int TObjPlayer::is_newman() { return (this->class_flags & CLASS_FLAG_NEWMAN) != 0; }
int TObjPlayer::is_android() { return (this->class_flags & CLASS_FLAG_ANDROID) != 0; }
int TObjPlayer::check_stat_flag_41c() { return set__8FlagWordFUl((char*)this + 0x41c, 32); }
int TObjPlayer::check_flag_at_41c() { return set__8FlagWordFUl((char*)this + 0x41c, 4); }
int TObjPlayer::set_flag_41c_bit1() { return set__8FlagWordFUl((char*)this + 0x41c, 2); }
int TObjPlayer::clamp_stat_41c() { return set__8FlagWordFUl((char*)this + 0x41c, 8); }

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

void *get_player_by_client_id(s32 i);

void TObjPlayer::set_flag_400000() {
    sub_8011E204(0x400000);
}

short TObjPlayer::get_model_field_m25() {
    struct VObj_801BE3D8 *o = (struct VObj_801BE3D8 *)*(void * *)&this->unk_380;
    return o->m25();
}

short TObjPlayer::get_action_animation() {
    struct VObj_801BE40C *o = (struct VObj_801BE40C *)*(void * *)&this->unk_380;
    return o->m22();
}

short TObjPlayer::call_model_m24() {
    struct VObj_801BE440 *o = (struct VObj_801BE440 *)*(void * *)&this->unk_380;
    return o->m24();
}

short TObjPlayer::get_weapon_stat_c() {
    struct VObj_801BE474 *o = (struct VObj_801BE474 *)*(void * *)&this->unk_380;
    return o->m26();
}

short TObjPlayer::call_obj_vt26() {
    struct VObj_801BE4A8 *o = (struct VObj_801BE4A8 *)*(void * *)&this->unk_380;
    return o->m26();
}

short TObjPlayer::query_child_state() {
    struct VObj_801BE4DC *o = (struct VObj_801BE4DC *)*(void * *)&this->unk_380;
    return o->m19();
}

short TObjPlayer::query_equip() {
    struct VObj_801BE510 *o = (struct VObj_801BE510 *)*(void * *)&this->unk_380;
    return o->m27();
}

short TObjPlayer::get_status() {
    struct VObj_801BE544 *o = (struct VObj_801BE544 *)*(void * *)&this->unk_380;
    return o->m14();
}

short TObjPlayer::get_model_state() {
    struct VObj_801BE578 *o = (struct VObj_801BE578 *)*(void * *)&this->unk_380;
    return o->m17();
}

short TObjPlayer::get_state() {
    struct VObj_801BE5AC *o = (struct VObj_801BE5AC *)*(void * *)&this->unk_380;
    return o->m16();
}

short TObjPlayer::call_subobject_m15() {
    struct VObj_801BE5E0 *o = (struct VObj_801BE5E0 *)*(void * *)&this->unk_380;
    return o->m15();
}

short TObjPlayer::get_vobj_state_28() {
    struct VObj_801BE614 *o = (struct VObj_801BE614 *)*(void * *)&this->unk_380;
    return o->m28();
}

    extern int local_client_id;
void TObjPlayer::update_battle_controller() { get_player_by_client_id((local_client_id)); }

}

extern "C" {

int TFontSmallLobby__sub_801C0228(void*);
int check_flag__10TObjPlayerFl(void*, int);
int set_state_flags__10TObjPlayerFUl(void*, int);

void TObjPlayer::set_flag_200000() {
    sub_8011E204(0x200000);
}
int TObjPlayer::check_flag_4() { return check_flag__10TObjPlayerFl(this, 4); }
void*TObjPlayer::set_invisible() { TFontSmallLobby__sub_801C0228(this); return this; }
void TObjPlayer::clear_flag_4000_callback() { set_flag_4000(); }
void TObjPlayer::set_flag_4000() { sub_8011E204(16384); }
int TObjPlayer::clear_flag_4000() { return set_state_flags__10TObjPlayerFUl(this, 16384); }
void TObjPlayer::set_battle_flag(s32 v) { this->m_3b4 = v; }
s32 TObjPlayer::get_anim_id() { return this->m_3b4; }
int TObjPlayer::check_flag_0x40000000() { return (this->m_334 >> 30) & 0x1; }
void TObjPlayer::clear_flag_0x2() { this->m_334 &= 0xfffffffd; }

}

extern "C" {

int TObjPlayer__sub_801BED70(void*);
int TObjPlayer__sub_801BED78(void*);
int TObjPlayer__sub_801BED80(void*);
int TObjPlayer__sub_801BED88(void*);
int TObjPlayer__sub_801BED90(void*);

int TObjPlayer::is_action_active() { return (this->m_334 >> 1) & 0x1; }
void TObjPlayer__sub_801BE784(void* p, u8 v) { *(u8*)((char*)p + 0x2e7) = v; }
u8 TObjPlayer::get_battle_mode() { return *(u8*)((char*)this + 0x33a); }
void TObjPlayer__sub_801BE794(void* p, u8 v) { *(u8*)((char*)p + 0x2cb) = v; }
u8 TObjPlayer::get_byte_339() { return this->m_339; }
void TObjPlayer__sub_801BE7A4(void* p, u8 v) { *(u8*)((char*)p + 0x2af) = v; }
u8 get_mag_level__10TObjPlayerFPv(void* p) { return *(u8*)((char*)p + 0x338); }
void TObjPlayer__sub_801BE7B4(void* p, u8 v) { *(u8*)((char*)p + 0x293) = v; }
int TObjPlayer__sub_801BE7BC(void* p) { return TObjPlayer__sub_801BED70((char*)p + 0x374); }
void TObjPlayer__sub_801BE7E0(void* p, u8 v) { *(u8*)((char*)p + 0x277) = v; }
int TObjPlayer::get_equip_flags() { return TObjPlayer__sub_801BED78((char*)this + 0x374); }
void TObjPlayer__sub_801BE80C(void* p, u8 v) { *(u8*)((char*)p + 0x25b) = v; }
int TObjPlayer::get_inventory_state() { return TObjPlayer__sub_801BED80((char*)this + 0x374); }
void TObjPlayer__sub_801BE838(void* p, u8 v) { *(u8*)((char*)p + 0x23f) = v; }
int TObjPlayer::get_field_374_state() { return TObjPlayer__sub_801BED88((char*)this + 0x374); }
void TObjPlayer__sub_801BE864(void* p, u8 v) { *(u8*)((char*)p + 0x223) = v; }
int TObjPlayer::get_field_374() { return TObjPlayer__sub_801BED90((char*)this + 0x374); }

}

struct Item_801BE890 { u8 b[0x1C]; };

struct Inv_801BE890 { s32 f0; Item_801BE890 items[0x1E]; };

extern "C" {
Inv_801BE890 *init_inventory_list__10TObjPlayerFPv(Inv_801BE890 *arg0);

Inv_801BE890 *init_inventory_list__10TObjPlayerFPv(Inv_801BE890 *arg0) {
    s32 i;
    arg0->f0 = 0;
    for (i = 0; i < 0x1E; i++) {
        init__17TPlyInventoryItemFv((u8 *)&arg0->items[i]);
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

void* TObjPlayer__sub_801BE918(void* a0, int a1, void* a2, void* a3) { *(float*)((char*)a2 + 0x0) = *(float*)((char*)a0 + a1 * 8 + 0x6b0); *(float*)((char*)a3 + 0x0) = *(float*)((char*)a0 + a1 * 8 + 0x6b4); return (char*)a0 + a1 * 8; }
s32 TObjPlayer::clamp_index_to_max(s32 arg0) {
    s32 max_level;

    max_level = arg0;
    if (max_level < 0) {
        max_level = 0;
    } else if (max_level > TObjPlayer::get_max_level()) {
        max_level = TObjPlayer::get_max_level();
    }
    return max_level;
}
void TObjPlayer::clamp_nested_index() {
    TObjPlayer::clamp_index_to_max(*(s32 *)(this->m_2b0 + 0x18));
}
void TObjPlayer__sub_801BE9A8(s32 arg0) {
    ((TObjPlayer *)arg0)->sub_8011E204(0x20000);
}
void set_flag_20000__10TObjPlayerFi(s32 arg0) {
    ((TObjPlayer *)arg0)->set_state_flags(0x20000);
}
void TObjPlayer::set_flag_2000000() {
    sub_8011E204(0x02000000);
}
void TObjPlayer::set_flag_02000000() {
    check_flag__10TObjPlayerFl(this, 0x02000000);
}

void TObjPlayer::set_position_history_entry(s32 arg1, f32 farg0, f32 farg1) {
    s32 arg0 = (s32)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)(arg0 + (arg1 * 8));
    *(f32 *)((s8 *)temp_r3 + 0x6B0) = farg0;
    *(f32 *)((s8 *)temp_r3 + 0x6B4) = farg1;
}

}


void TObjPlayer::set_action_flag_2() { this->m_334 |= 0x2; }
void set_flag_400000__10TObjPlayerFi(s32 arg0) {
    ((TObjPlayer *)arg0)->set_state_flags(0x400000);
}
int TObjPlayer::check_flag_48() { return check_flag__10TObjPlayerFl(this, 48); }
int TObjPlayer::is_status_locked() { return this->actorFlags & 0x10000; }
int TObjPlayer::is_status_flag_200() { return this->actorFlags & 0x200; }
int TObjPlayer__sub_801BEABC(void* p) { return ((TObjPlayer *)p)->end_camera_pan(); }
int TObjPlayer::start_freeze_self() { return start_freeze(); }
void TObjPlayer::set_floor(s32 v) { this->current_floor = v; }
void TObjPlayer::set_floor_index(s32 v) { *(s32*)((char*)this + 0x3e0) = v; }

extern "C" {

int unregister_object_by_id__14TObjCollidableFv(void*);
int TObjPlayer__sub_801BED98(void*);
int TObjPlayer__sub_801BEDA0(void*);
int TObjPlayer__sub_801BEDA8(void*);
int TObjPlayer__sub_801BEDB0(void*);
int TObjPlayer__sub_801BEDB8(void*);

s32 TObjPlayer__sub_801BEB0C(void* p) { return *(s32*)((char*)p + 0x334); }
int TObjPlayer::unregister_sub() { return unregister_object_by_id__14TObjCollidableFv(this); }
void TObjPlayer::set_control_role(s32 v) { *(s32 *)&this->unk_3E8 = v; }
u8 TObjPlayer__sub_801BEB3C(void* p) { return *(u8*)((char*)p + 0x2e7); }
u8 TObjPlayer__sub_801BEB44(void* p) { return *(u8*)((char*)p + 0x2cb); }
u8 TObjPlayer__sub_801BEB4C(void* p) { return *(u8*)((char*)p + 0x2af); }
void TObjPlayer::set_play_time(s32 v) { this->m_3bc = v; }
void TObjPlayer::reset_entrance_id() { *(s32*)((char*)this + 0x3c8) = -1; }
int TObjPlayer__sub_801BEB68(void* p) { return TObjPlayer__sub_801BED98((char*)p + 0x374); }
u8 TObjPlayer__sub_801BEB8C(void* p) { return *(u8*)((char*)p + 0x293); }
int TObjPlayer::query_field374() { return TObjPlayer__sub_801BEDA0((char*)this + 0x374); }
u8 TObjPlayer__sub_801BEBB8(void* p) { return *(u8*)((char*)p + 0x277); }
int TObjPlayer::query_flags_374() { return TObjPlayer__sub_801BEDA8((char*)this + 0x374); }
u8 TObjPlayer__sub_801BEBE4(void* p) { return *(u8*)((char*)p + 0x25b); }
int TObjPlayer::get_quest_status() { return TObjPlayer__sub_801BEDB0((char*)this + 0x374); }
u8 TObjPlayer__sub_801BEC10(void* p) { return *(u8*)((char*)p + 0x23f); }
int TObjPlayer::get_field_0x374() { return TObjPlayer__sub_801BEDB8((char*)this + 0x374); }
u8 TObjPlayer__sub_801BEC3C(void* p) { return *(u8*)((char*)p + 0x223); }

}
