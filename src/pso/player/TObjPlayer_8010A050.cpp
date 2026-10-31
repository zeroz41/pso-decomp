#include "types.h"
#include "pso/player/TUnk_8049F130.h"

#include "pso/item/TUnk_8049F148.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/map/FloorArea.h"

struct Obj_8010A1D0 {
    u8 pad0[0x18];
    void *vt;
    s32 f_1C;
    s32 f_20;
    s32 f_24;
    s16 f_28;
    u8 f_2A;
    u8 pad2B;
    u32 f_2C;
};

struct Base_8010A26C { char pad[0x18]; };
struct VObj_8010A26C : Base_8010A26C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual s32 m63(s32, s32 *);
};

int get_item_system_generation(void);
extern const s32 lbl_8043E280[];
extern const s32 lbl_8043E2A0[];
extern "C" {
s32 get_field_3e0__12TBoss3VoloptFv();
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void *spawn_particle_effect(void *pos, s32 id);
s32 is_item_area_enabled();
void *get_player_by_client_id(s32 i);
s16 count_nearby_players_with_shield__10TObjPlayerFUsPUc(u16, s8 *);
s32 init__9TItemDataFv(s8 *);
void queue_destruction__7TObjectFv(void *arg0);

void *create_particle_emitter(void *pos, s32 id);
s32 get_current_floor();
int get_item_field_6__10TObjPlayerFPv(void *p);
u8 get_item_group__5TItemFv();

s32 TObjBase::get_texlist() { return texlist; }
NJS_OBJECT *TItem::get_item_model() { return item_model; }

extern const f32 lbl_805DAB58;

struct TItemData8_8010a060 { s8 a; s8 b; u8 c; s8 pad[21]; };

void TUnk_8049F130::run_task() {
    struct TItemData8_8010a060 sp8;
    s32 player;

    if ((u32) this->m_2c != get_item_system_generation()) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (lbl_805DAB58 == (f32) *(s32 *)&this->unk_1C) {
        init__9TItemDataFv(&sp8.a);
        sp8.a = 1;
        sp8.b = 2;
        sp8.c = *(u8 *)((s8 *)this + 0x2A);
        if ((count_nearby_players_with_shield__10TObjPlayerFUsPUc(this->m_28, &sp8.a) > 0) && ((s32) this->m_20 != -1)) {
            player = (s32)get_player_by_client_id(this->m_28);
            if (player != 0) {
                get_field_3e0__12TBoss3VoloptFv();
                if (is_item_area_enabled() == 1) {
                    if ((s32) *(s32 *)&this->unk_24 == 0) {
                        create_timed_particle_emitter((void *)(player + 0x2FC), this->m_20, 0, 0xA);
                    } else {
                        spawn_particle_effect((void *)(player + 0x2FC), this->m_20);
                    }
                }
            }
        }
        *(s32 *)&this->unk_1C = 0;
    }
    *(s32 *)&this->unk_1C = (s32) (*(s32 *)&this->unk_1C + 1);
}

}
TUnk_8049F130::~TUnk_8049F130() {

}
TUnk_8049F130::TUnk_8049F130(TObject *parent, s16 a, u8 b) : TObject(parent) {
    ((Obj_8010A1D0 *)this)->f_1C = 0;
    ((Obj_8010A1D0 *)this)->f_20 = lbl_8043E2A0[(b - 0x53) % 8];
    ((Obj_8010A1D0 *)this)->f_24 = lbl_8043E280[(b - 0x53) % 8];
    ((Obj_8010A1D0 *)this)->f_28 = a;
    ((Obj_8010A1D0 *)this)->f_2A = b;
    ((Obj_8010A1D0 *)this)->f_2C = get_item_system_generation();
}

void TUnk_8049F148::run_task() {
    s32 sp8[6];
    s32 temp_r3_2;
    u32 temp_r3_3;
    VObj_8010A26C *player;

    if ((u32) this->m_28 != get_item_system_generation()) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    player = (VObj_8010A26C *)get_player_by_client_id(*(u16 *)((s8 *)this + 0x24));
    if (player != NULL) {
        player->m63(0x24, sp8);
        temp_r3_2 = get_current_floor();
        if (temp_r3_2 != (s32) this->m_20) {
            this->m_20 = temp_r3_2;
            if ((is_current_area_item_enabled() != 0) && (temp_r3_2 == ((TObjPlayer *)player)->get_floor())) {
                *(u32 *)&this->unk_1C = (u32)create_particle_emitter(sp8, 0x101);
            } else {
                *(u32 *)&this->unk_1C = 0U;
            }
        }
        temp_r3_3 = get_item_field_6__10TObjPlayerFPv(player);
        if ((u32) *(u32 *)&this->unk_1C != 0U) {
            s32 var_r30 = 0;
            if ((temp_r3_3 != 0U) && (get_item_group__5TItemFv() == 0x1A)) {
                var_r30 = 1;
            }
            if (var_r30 != 0) {
                ((TParticleCtrl *)(*(u32 *)&this->unk_1C))->clear_active_flag();
            } else {
                ((TParticleCtrl *)(*(u32 *)&this->unk_1C))->enable();
            }
            ((TParticleCtrl *)*(u32 *)&this->unk_1C)->set_position(sp8);
        }
    } else {
        queue_destruction__7TObjectFv(this);
    }
}
