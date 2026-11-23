#include "types.h"
#include "pso/npc/TNpcPlayer_8014DADC.h"
#include "pso/render/render_util.h"
#include "pso/npc/TNpcPlayer.h"
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
void set_partner_counter(saddr arg0, s32 arg1, s16 arg2);
extern "C" {
s32 TNpcPlayer__sub_80152978(void *p);
u8 *find_active_entity_by_id(s32);
void reset_partner_counter(void *, s32);
void increment_partner_counter(void *, s32);
s16 TNpcPlayer__sub_801528DC(void *);
s16 get_npc_type__10TNpcPlayerFPv(void *);
s16 get_partner_counter(void *, s32);
void init_6x45_attack_packet(void *);
void init_6x44_attack_packet(void *);
void init_6x43_attack_packet(void *);
void set_field_0__10TNpcPlayerFs(void *, s32);
int request_technique_cast__10TNpcPlayerFl(void*);
s32 set_technique_seed_level(s32, s32, u8);

void TNpcPlayer::init_equipment() {
    s32 temp_r31;
    s32 flags;

    flags = this->ai_params.technique_flags;
    temp_r31 = (saddr)this->m_78->m_94;
    if (flags & TECHNIQUE_FLAGS_FOIE_GIFOIE) {
        TObjPlayer::clamp_and_set_unit_value(temp_r31, this->ai_params.attack_technique_level, 0);
        TObjPlayer::clamp_and_set_unit_value(temp_r31, this->ai_params.attack_technique_level, 1);
        set_technique_seed_level(temp_r31 + 0x428, 0, this->ai_params.attack_technique_level);
        set_technique_seed_level(temp_r31 + 0x428, 1, this->ai_params.attack_technique_level);
    } else if (flags & TECHNIQUE_FLAGS_BARTA_GIBARTA) {
        TObjPlayer::clamp_and_set_unit_value(temp_r31, this->ai_params.attack_technique_level, 3);
        TObjPlayer::clamp_and_set_unit_value(temp_r31, this->ai_params.attack_technique_level, 4);
        set_technique_seed_level(temp_r31 + 0x428, 3, this->ai_params.attack_technique_level);
        set_technique_seed_level(temp_r31 + 0x428, 4, this->ai_params.attack_technique_level);
    } else if (flags & TECHNIQUE_FLAGS_ZONDE_RAZONDE) {
        TObjPlayer::clamp_and_set_unit_value(temp_r31, this->ai_params.attack_technique_level, 6);
        TObjPlayer::clamp_and_set_unit_value(temp_r31, this->ai_params.attack_technique_level, 8);
        set_technique_seed_level(temp_r31 + 0x428, 6, this->ai_params.attack_technique_level);
        set_technique_seed_level(temp_r31 + 0x428, 8, this->ai_params.attack_technique_level);
    }
    TObjPlayer::clamp_and_set_unit_value(temp_r31, this->ai_params.support_technique_level, 0xF);
    TObjPlayer::clamp_and_set_unit_value(temp_r31, this->ai_params.support_technique_level, 0x10);
    set_technique_seed_level(temp_r31 + 0x428, 0xF, this->ai_params.support_technique_level);
    set_technique_seed_level(temp_r31 + 0x428, 0x10, this->ai_params.support_technique_level);
}

    extern int TNpcPlayer__data_805D5864;
void TNpcPlayer__sub_8014DC30(void) { TNpcPlayer__data_805D5864 = 1; }

int TNpcPlayer__sub_8014DC3C(void* p) { return request_technique_cast__10TNpcPlayerFl(p); }

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
                ((TNpcPlayer *)(((TObjPlayer *)pl->state)->get_state_ptr()))->set_state(1);
                set_field_0__10TNpcPlayerFs((u8 *)((TObjPlayer *)pl->state)->get_state_ptr() + 4, ((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
                ((TNpcPlayer *)((u8 *)((TObjPlayer *)pl->state)->get_state_ptr() + 4))->set_field2((s16)(TNpcPlayer__sub_801528DC(self->npc)));
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
                ((TNpcPlayer *)(((TObjPlayer *)pl->state)->get_state_ptr()))->set_state(1);
                set_field_0__10TNpcPlayerFs((u8 *)((TObjPlayer *)pl->state)->get_state_ptr() + 4, ((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
                ((TNpcPlayer *)((u8 *)((TObjPlayer *)pl->state)->get_state_ptr() + 4))->set_field2((s16)(TNpcPlayer__sub_801528DC(self->npc)));
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
                ((TNpcPlayer *)(((TObjPlayer *)pl->state)->get_state_ptr()))->set_state(1);
                set_field_0__10TNpcPlayerFs((u8 *)((TObjPlayer *)pl->state)->get_state_ptr() + 4, ((GetState_8014DC5C)get_npc_state__10TNpcPlayerFv)(self->npc));
                ((TNpcPlayer *)((u8 *)((TObjPlayer *)pl->state)->get_state_ptr() + 4))->set_field2((s16)(TNpcPlayer__sub_801528DC(self->npc)));
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
    u32 npc_state;
    temp_r31 = TNpcPlayer__sub_80152978((void *)this->m_78);
    npc_state = ((TNpcPlayer *)(this->m_78))->get_npc_state();
    if (npc_state != temp_r31) {
        set_partner_counter((saddr)&this->m_5c, 1, 0);
    }
    npc_counter_reset_if_reached((u8 *)&this->m_5c, 1, 3);
    ((TNpcPlayer *)arg0)->send_partner_attack_stage_request();
}
}
#pragma pop
