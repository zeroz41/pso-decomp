#include "types.h"
#include "pso/render/render_util.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"

struct Msg_8014DC5C { s16 hdr; s16 type; s16 angle; s16 flag; };

struct Pl_8014DC5C { u8 pad[0x38]; u8 pos[0x7cc - 0x38]; u8 state[4]; };

struct Npc_8014DC5C { u8 pad[0x94]; Pl_8014DC5C *pl; };

struct Self_8014DC5C {
    u8 pad[0x5c];
    u8 f5C[0x78 - 0x5c];
    Npc_8014DC5C *npc;
};

extern "C" {
u32 get_npc_state__10TNpcPlayerFv(s32);
s32 npc_counter_reset_if_reached(void *, s32, s32);
}
void set_partner_counter(s32 arg0, s32 arg1, s16 arg2);
extern "C" {
s32 TNpcPlayer__sub_80152978(void *p);
u8 *find_active_entity_by_id(s32);
u8 *get_state_ptr__10TObjPlayerFv(void *);
void reset_partner_counter(void *, s32);
void increment_partner_counter(void *, s32);
s16 TNpcPlayer__sub_801528DC(void *);
s16 get_npc_type__10TNpcPlayerFPv(void *);
s16 get_partner_counter(void *, s32);
void init_6x45_attack_packet(void *);
void init_6x44_attack_packet(void *);
void init_6x43_attack_packet(void *);
void set_field2__10TNpcPlayerFs(void *, s32);
void set_field_0__10TNpcPlayerFs(void *, s32);
void TNpcPlayer__sub_8014DC30(void);
int TNpcPlayer__sub_8014DC3C(void* p);
int request_technique_cast__10TNpcPlayerFPvi(void*);
s32 set_technique_seed_level(s32, s32, u8);
void clamp_and_set_unit_value__10TObjPlayerFiUci(s32 arg0, u8 arg1, s32 i);

void TNpcPlayer::init_equipment() {
    s32 temp_r31;
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)this + 0x34);
    temp_r31 = *(s32 *)(this->m_78 + 0x94);
    if (temp_r4 & 4) {
        clamp_and_set_unit_value__10TObjPlayerFiUci(temp_r31, this->m_50, 0);
        clamp_and_set_unit_value__10TObjPlayerFiUci(temp_r31, this->m_50, 1);
        set_technique_seed_level(temp_r31 + 0x428, 0, this->m_50);
        set_technique_seed_level(temp_r31 + 0x428, 1, this->m_50);
    } else if (temp_r4 & 8) {
        clamp_and_set_unit_value__10TObjPlayerFiUci(temp_r31, this->m_50, 3);
        clamp_and_set_unit_value__10TObjPlayerFiUci(temp_r31, this->m_50, 4);
        set_technique_seed_level(temp_r31 + 0x428, 3, this->m_50);
        set_technique_seed_level(temp_r31 + 0x428, 4, this->m_50);
    } else if (temp_r4 & 0x10) {
        clamp_and_set_unit_value__10TObjPlayerFiUci(temp_r31, this->m_50, 6);
        clamp_and_set_unit_value__10TObjPlayerFiUci(temp_r31, this->m_50, 8);
        set_technique_seed_level(temp_r31 + 0x428, 6, this->m_50);
        set_technique_seed_level(temp_r31 + 0x428, 8, this->m_50);
    }
    clamp_and_set_unit_value__10TObjPlayerFiUci(temp_r31, *(u8 *)((s8 *)this + 0x51), 0xF);
    clamp_and_set_unit_value__10TObjPlayerFiUci(temp_r31, *(u8 *)((s8 *)this + 0x51), 0x10);
    set_technique_seed_level(temp_r31 + 0x428, 0xF, *(u8 *)((s8 *)this + 0x51));
    set_technique_seed_level(temp_r31 + 0x428, 0x10, *(u8 *)((s8 *)this + 0x51));
}

    extern int TNpcPlayer__data_805D5864;
void TNpcPlayer__sub_8014DC30(void) { TNpcPlayer__data_805D5864 = 1; }

int TNpcPlayer__sub_8014DC3C(void* p) { return request_technique_cast__10TNpcPlayerFPvi(p); }

typedef u16 (*GetState_8014DC5C)(void *);
void TNpcPlayer::send_partner_attack_stage_request() {
    Self_8014DC5C *self = (Self_8014DC5C *)this;
    Msg_8014DC5C m0;
    Msg_8014DC5C m1;
    Msg_8014DC5C m2;
    Pl_8014DC5C *pl;
    u8 *tgt;
    switch (get_partner_counter(self->f5C, 1)) {
    case 0:
        init_6x43_attack_packet(&m0);
        if (self->npc != NULL) {
            m0.type = get_npc_type__10TNpcPlayerFPv(self->npc);
            m0.flag = 0;
            tgt = find_active_entity_by_id(((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
            if (tgt != NULL) {
                m0.angle = calc_angle_to((Vec *)(self->npc->pl->pos), (Vec *)(tgt + 0x38));
                pl = self->npc->pl;
                ((TNpcPlayer *)(get_state_ptr__10TObjPlayerFv(pl->state)))->set_state(1);
                set_field_0__10TNpcPlayerFs(get_state_ptr__10TObjPlayerFv(pl->state) + 4, ((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
                set_field2__10TNpcPlayerFs(get_state_ptr__10TObjPlayerFv(pl->state) + 4, TNpcPlayer__sub_801528DC(self->npc));
                ((TNpcPlayer *)(&m0))->update_lobby();
                increment_partner_counter(self->f5C, 1);
            }
        }
        break;
    case 1:
        init_6x44_attack_packet(&m1);
        if (self->npc != NULL) {
            m1.type = get_npc_type__10TNpcPlayerFPv(self->npc);
            m1.flag = 1;
            tgt = find_active_entity_by_id(((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
            if (tgt != NULL) {
                m1.angle = calc_angle_to((Vec *)(self->npc->pl->pos), (Vec *)(tgt + 0x38));
                pl = self->npc->pl;
                ((TNpcPlayer *)(get_state_ptr__10TObjPlayerFv(pl->state)))->set_state(1);
                set_field_0__10TNpcPlayerFs(get_state_ptr__10TObjPlayerFv(pl->state) + 4, ((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
                set_field2__10TNpcPlayerFs(get_state_ptr__10TObjPlayerFv(pl->state) + 4, TNpcPlayer__sub_801528DC(self->npc));
                ((TNpcPlayer *)(&m1))->update_players();
                increment_partner_counter(self->f5C, 1);
            }
        }
        break;
    case 2:
        init_6x45_attack_packet(&m2);
        if (self->npc != NULL) {
            m2.type = get_npc_type__10TNpcPlayerFPv(self->npc);
            m2.flag = 1;
            tgt = find_active_entity_by_id(((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
            if (tgt != NULL) {
                m2.angle = calc_angle_to((Vec *)(self->npc->pl->pos), (Vec *)(tgt + 0x38));
                pl = self->npc->pl;
                ((TNpcPlayer *)(get_state_ptr__10TObjPlayerFv(pl->state)))->set_state(1);
                set_field_0__10TNpcPlayerFs(get_state_ptr__10TObjPlayerFv(pl->state) + 4, ((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
                set_field2__10TNpcPlayerFs(get_state_ptr__10TObjPlayerFv(pl->state) + 4, TNpcPlayer__sub_801528DC(self->npc));
                ((TNpcPlayer *)(&m2))->update();
                reset_partner_counter(self->f5C, 1);
                ((TNpcPlayer *)self)->request_chatter(0xD);
            }
        }
        break;
    }
}

#pragma push
#pragma scheduling off
void TNpcPlayer::partner_request_physical_attack() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r31;
    u32 temp_r3;
    temp_r31 = TNpcPlayer__sub_80152978((void *)this->m_78);
    temp_r3 = ((TNpcPlayer *)(this->m_78))->get_npc_state();
    if (temp_r3 != temp_r31) {
        set_partner_counter((s32)&this->m_5c, 1, 0);
    }
    npc_counter_reset_if_reached((u8 *)&this->m_5c, 1, 3);
    ((TNpcPlayer *)arg0)->send_partner_attack_stage_request();
}
}
#pragma pop
