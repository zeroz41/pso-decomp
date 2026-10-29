#include "types.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct Base_8016A0E0_80169EE4 { char pad[0x18]; };
struct VObj_8016A0E0_80169EE4 : Base_8016A0E0_80169EE4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(void *);
};

struct SwitchPacket {u8 code,words;u16 object,zero,reserved,switchId;u8 area,flags;};

struct Self_8016A310 { u8 pad[0x38]; u8 pos[0xCC - 0x38]; f32 range; };

struct Obj_8016A280 { u8 pad[0x38]; u8 pos[0xCC - 0x38]; f32 radius; };

extern "C" {
s32 get_current_floor();
void *get_player_by_client_id(s32 i);
f32 xyz_distance_squared(u8 *arg0, u8 *arg1);
extern s32 local_client_id;
int get_player_data__10TObjPlayerFi(int a0);
extern s32 registered_player_count;
void TOKey__sub_80169FB0(void* p);
s32 play_sound_effect(s32, s32, s32, s32);
void *find_entity_by_id(u16);
}
void handle_6x05_write_switch_flag(void *arg0);
void clear_floor_switch_flag(u32 id, s16 floor);
void clear_current_floor_switch(s32 id);
void set_floor_switch_flag(u32 id, s16 floor);
void set_current_floor_switch(s32 id);
extern "C" {
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
void __dl__7TObjectFPv(void *);
s32 bswap_6x05_switch_flag__5TOKeyFv();
s32 update_object_view_visibility__8TObjBaseFff();
void *__ct__13TUnk_804AFBF8FP7TObject(void *a0);
s32 start_camera_pan__10TObjPlayerFs(s32, s32, s32);

extern s32 lbl_804B27D8[];

void *TUnk_804B27D8::destroy_key_object(s16 arg1) {
    if (this != NULL) {
        *(s32 * *)((u8 *)this + 0x18) = lbl_804B27D8;
        __dt__13TUnk_804AFBF8Fv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_804B27D8::init() {
    __ct__13TUnk_804AFBF8FP7TObject(this);
    *(s32 * *)((u8 *)this + 0x18) = lbl_804B27D8;
    *(u32 *)&this->unk_D0 = -1;
    (*(u32 *)&this->unk_C8) = 0;
    this->m_ac = 0;
    this->m_cc = 0;
    this->m_d4 = 0;
    *(u32 *)&this->unk_D8 = 0;
    TOKey__sub_80169FB0((void*)((void *)((char *)this + 152)));
    this->m_dc = 0;
    this->m_e0 = 1;
    return this;
}

void TOKey__sub_80169FB0(void* p) { *(s32*)((char*)p + 0x0) = 1; }
s32 TOKey::update_object_view_visibility(f32, f32) {
    if (update_object_view_visibility__8TObjBaseFff() == 1) {
        *(s32 *)((s8 *)this + 0xE4) = 1;
        return 1;
    }
    return 0;
}

void TOKey::handle_switch_trigger(void *arg1) {

    if ((*(u8 *)((s8 *)arg1 + 0xB) & 2) && ((s8) *(u8 *)((s8 *)arg1 + 0xA) == get_current_floor())) {
        play_sound_effect(0x4005281F, 0, 0, 0);
    }
    if (*(u8 *)((s8 *)arg1 + 0xB) & 1) {
        set_current_floor_switch(*(u16 *)((s8 *)arg1 + 8));
    } else {
        clear_current_floor_switch(*(u16 *)((s8 *)arg1 + 8));
    }
    switch (this->m_d4) {
    case 0:
        this->trigger_activate_sound();
        this->m_d4 = 1;
        return;
    case 1:
        this->vfunc_19();
        this->m_d4 = 0;
        return;
    }
}
}

void handle_6x05_write_switch_flag(void *arg0) {
    void *entity;

    bswap_6x05_switch_flag__5TOKeyFv();
    entity = find_entity_by_id(*(u16 *)((s8 *)arg0 + 2));
    if (entity != NULL) {
        ((VObj_8016A0E0_80169EE4 *)entity)->m25(arg0);
        return;
    }
    if ((*(u8 *)((s8 *)arg0 + 0xB) & 2) && ((s8) *(u8 *)((s8 *)arg0 + 0xA) == get_current_floor())) {
        play_sound_effect(0x4005281F, 0, 0, 0);
    }
    if (*(u8 *)((s8 *)arg0 + 0xB) & 1) {
        set_floor_switch_flag(*(u16 *)((s8 *)arg0 + 8), *(s8 *)((s8 *)arg0 + 0xA));
        return;
    }
    clear_floor_switch_flag(*(u16 *)((s8 *)arg0 + 8), *(s8 *)((s8 *)arg0 + 0xA));
}

void TOKey::interact(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 player;

    temp_r0 = this->m_d0;
    if ((temp_r0 != 2) && ((temp_r0 != 0) || ((s32) this->m_d4 != 1))) {
        player = (s32)get_player_by_client_id((u16)((u16)arg1));
        if (player != 0) {
            start_camera_pan__10TObjPlayerFs(player, 0xC, ((TObjPlayer *)(player + 0x38))->calc_angle_to((u8 *)&this->position));
            *(s32 *)((s8 *)arg0 + 0xDC) = (s32) *(s32 *)((s8 *)arg0 + 0xD8);
            *(s32 *)((s8 *)arg0 + 0xE0) = 1;
        }
    }
}

extern s8 controller_input_state[];

void TOKey::send_switch_on() {
    SwitchPacket packet;
    ((TLobby *)(&packet))->init_6x05_switch_changed();
    packet.object=this->entity_id;
    packet.zero=0;
    packet.switchId=this->m_e4;
    packet.area=((s8)get_current_floor());
    packet.flags=1;
    ((TLobby *)(&packet))->finalize_and_send_60();
}

s32 TOKey::is_any_player_in_range() {
    Obj_8016A280 *arg0 = (Obj_8016A280 *)this;
    u8 *p;
    s32 i;
    for (i = 0; i < registered_player_count; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (p != 0) {
            if (((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
                if (xyz_distance_squared(p + 0x38, arg0->pos) < arg0->radius * arg0->radius) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TOKey::is_local_player_in_range() {
    Self_8016A310 *self = (Self_8016A310 *)this;
    u8 *p = (u8 *)((void *)get_player_by_client_id(local_client_id));
    if (p != 0) {
        if (((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            if (xyz_distance_squared(p + 0x38, self->pos) < self->range * self->range) {
                return 1;
            }
        }
    }
    return 0;
}

s32 TOKey::is_confirm_pressed() {
    s32 temp_r0;

    temp_r0 = this->m_d0;
    if (temp_r0 == 2) {
        return 0;
    }
    if ((temp_r0 == 0) && ((s32) this->m_d4 == 1)) {
        return 0;
    }
    if ((is_local_player_in_range() != 0) && (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 4) != 0)) {
        return 1;
    }
    return 0;
}
