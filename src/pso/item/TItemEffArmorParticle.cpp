#include "pso/TItemEffArmorParticle.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/TParticleCtrl.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TNowLoading.h"

#include <stddef.h>

typedef char armor_item_id_offset[(offsetof(TItemEffArmorParticle, m_item_id) == 0x1C) ? 1 : -1];
typedef char armor_particle_offset[(offsetof(TItemEffArmorParticle, m_20) == 0x20) ? 1 : -1];
typedef char armor_player_id_offset[(offsetof(TItemEffArmorParticle, m_player_id) == 0x24) ? 1 : -1];
typedef char armor_item_ctrl_offset[(offsetof(TItemEffArmorParticle, m_item_ctrl) == 0x28) ? 1 : -1];
typedef char armor_size_check[(sizeof(TItemEffArmorParticle) == 0x2C) ? 1 : -1];

extern "C" {
void queue_destruction__7TObjectFv(void *);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(int, int);
s8 get_mode__5TItemFv();
void *get_player_by_client_id(s32 i);
}
int get_item_system_generation(void);
void TItemEffArmorParticle::run_task() {
    s32 active;
    u32 player, item;

    if (m_item_ctrl != (u32)get_item_system_generation()) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    active = 0;
    if ((u32)m_20 != 0U) {
        player = (u32)get_player_by_client_id(m_player_id);
        item = (u32)find_item_by_id(m_item_id);
        if (player != 0U) {
            if (item != 0U) {
                if (get_mode__5TItemFv() == 2) {
                    if (obj_testFlags30__13TUnk_804AF8A0FUl((int)player, 0x800) == 0) {
                        if (((TItem *)item)->is_hidden() == 0) {
                            ((TParticleCtrl *)m_20)->clear_active_flag();
                        } else {
                            goto enable_particle;
                        }
                    } else {
                    enable_particle:
                        ((TParticleCtrl *)m_20)->enable();
                    }
                    active = 1;
                    ((TNowLoading *)m_20)->copy_pos((void *)(player + 0x2FC));
                }
            }
        }
    }
    if (active == 0) {
        queue_destruction__7TObjectFv(this);
    }
}

TItemEffArmorParticle::~TItemEffArmorParticle() {
    if (m_20 != nullptr) queue_destruction__7TObjectFv(m_20);
}

#include "types.h"
#include "pso/item/TItem.h"

struct Base_A_80364364 { char pad[0x18]; };
struct V_A_80364364 : Base_A_80364364 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual s32 m7();
};

extern "C" {

void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void disallow_rendering__7TObjectFv(TObject *arg0);

extern s32 TItemEffArmorParticle__class_name;

}
TItemEffArmorParticle::TItemEffArmorParticle(TObject *object, s32 item_id, s32 player_id, s32 arg4) : TObject(object) {
    void *player;
    u32 p;
    *(s32 *)((s8 *)this + 0) = (s32) TItemEffArmorParticle__class_name;
    disallow_rendering__7TObjectFv(this);
    this->m_item_id = item_id;
    this->m_player_id = (s16) player_id;
    this->m_item_ctrl = get_item_system_generation();
    player = get_player_by_client_id((u16) player_id);
    if (player != NULL) {
        *(u32 *)((s8 *)this + 0x20) = (u32)spawn_continuous_particle_effect_with_flags((void *)(((V_A_80364364 *) player)->m7()), (s32)arg4, 0x10);
        p = *(u32 *)((s8 *)this + 0x20);
        if (p != 0U) {
            ((TParticleCtrl *)p)->set_owner_id(this->m_player_id);
        }
    } else {
        *(u32 *)((s8 *)this + 0x20) = 0U;
    }
}
