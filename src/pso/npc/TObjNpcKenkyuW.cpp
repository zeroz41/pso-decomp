#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/npc/TObjNpcKenkyuW.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/npc/TUnk_804A9F50.h"

struct RecoveredGlobal_802A3C30_lbl_804DCE48 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802A3C30_lbl_804DCE48_size[sizeof(RecoveredGlobal_802A3C30_lbl_804DCE48) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802A3CD8___vt__14TObjNpcKenkyuW {
    s32 value;
    u8 remaining[0x174];
};

#include "pso/technique/TechniqueContact.h"
#include "pso/misc/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80236290_lbl_80516150 {
    s32 value;
    u8 remaining[0x84];
};

struct RecoveredGlobal_80236290_lbl_80516150;
struct Vec_802A3DE8 { f32 x; f32 y; f32 z; };

struct Pl_802A3DE8 {
    u8 pad0[0x30];
    u32 flags;
};

struct Obj_802A3DE8 {
    u8 pad0[0x68];
    u8 *body;
    Vec_802A3DE8 pos;
    u8 pad78[0xA0 - 0x78];
    Vec_802A3DE8 fA0;
};

struct Vec_802A41CC { f32 x; f32 y; f32 z; };

struct Pl_802A41CC {
    u8 pad0[0x30];
    u32 flags;
};

struct Obj_802A41CC {
    u8 pad0[0x68];
    u8 *body;
    Vec_802A41CC pos;
    u8 pad78[0xA0 - 0x78];
    Vec_802A41CC fA0;
};

struct Vec_802A3FDC { f32 x; f32 y; f32 z; };

struct Pl_802A3FDC {
    u8 pad0[0x30];
    u32 flags;
};

struct Obj_802A3FDC {
    u8 pad0[0x68];
    u8 *body;
    Vec_802A3FDC pos;
    u8 pad78[0xA0 - 0x78];
    Vec_802A3FDC fA0;
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_802A3C30_lbl_804DCE48 bm_npc_kenkyu_w_resource_descriptor;
extern u32 TObjNpcKenkyuW__model_resource;
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
extern s32 __vt__14TObjNpcKenkyuW[];
extern s32 TObjNpcKenkyuW__name;
s32 obj_is_hit_receivable(void *);
extern RecoveredGlobal_80236290_lbl_80516150 technique_contact_list;
Vec_802A3DE8 *get_shoot_data__12TNeedleShootFv(void *);
void vector_length(void *);
int get_player_data__10TObjPlayerFi(int a0);
s32 get_entity_id(void *);
extern const f32 lbl_805DDF60;
extern const f32 lbl_805DDF64;
TechniqueContactList *TObjPlayer__sub_802A3DE8(Obj_802A3DE8 *self, void *src);
void *find_entity_by_id(u16 id);
TechniqueContactList *TObjPlayer__sub_802A3FDC(Obj_802A3FDC *self, void *src);
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);

void TObjNpcKenkyuW::destroy_instance() {
    if ((u32) TObjNpcKenkyuW__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcKenkyuW__model_resource, 1);
        TObjNpcKenkyuW__model_resource = 0U;
    }
}

void TObjNpcKenkyuW::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_npc_kenkyu_w_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjNpcKenkyuW__model_resource) = var_r0;
}

void *__dt__14TObjNpcKenkyuWFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TObjNpcKenkyuW;
        ((TUnk_804A9F50 *)arg0)->destroy_npc_lappy_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_802A3CD8___vt__14TObjNpcKenkyuW_size[sizeof(RecoveredGlobal_802A3CD8___vt__14TObjNpcKenkyuW) == 0x178 ? 1 : -1];
u8 *TObjNpcKenkyuW__ct(u8 *player, s32 arg1, s32 arg2) {
    construct_male_npc_base((player));
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_802A3CD8___vt__14TObjNpcKenkyuW *)&__vt__14TObjNpcKenkyuW).value;
    *(s32 *)((s8 *)player + 0) = (s32) TObjNpcKenkyuW__name;
    ((TObjNpcKenkyuW *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = get_bml_model((int) ((*(s32 *)&TObjNpcKenkyuW__model_resource)), 0);
    ((TObjNpcKenkyuW *)player)->texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TObjNpcKenkyuW__model_resource)), 0);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

typedef char RecoveredGlobal_80236290_lbl_80516150_size[sizeof(RecoveredGlobal_80236290_lbl_80516150) == 0x88 ? 1 : -1];
void clear_technique_contacts__10TObjPlayerFv() {
    for (s32 i=0;i<16;++i) {
        (*(TechniqueContactList *)&technique_contact_list).actors[i]=0;
        (*(TechniqueContactList *)&technique_contact_list).bodies[i]=0;
    }
    (*(TechniqueContactList *)&technique_contact_list).count=0;
}

bool TObjPlayer::is_hit_receivable_target(s32 arg0, u32 arg1) {
    if (arg1 == 0U) {
        return 0;
    }
    return obj_is_hit_receivable((void *)arg1) != 0;
}
#define L_802A3DE8 (*(TechniqueContactList *)&technique_contact_list)
TechniqueContactList *TObjPlayer__sub_802A3DE8(Obj_802A3DE8 *self, void *src) {
    Vec_802A3DE8 a;
    Vec_802A3DE8 d;
    Vec_802A3DE8 *sd;
    Pl_802A3DE8 *p;
    s32 i;
    TechniqueContactBody *r;
    VecCopy((Vec *)&a, (const Vec *)&self->pos);
    ((void (*)(void *))clear_technique_contacts__10TObjPlayerFv)(self);
    if (self->body == 0) return &L_802A3DE8;
    sd = get_shoot_data__12TNeedleShootFv(self);
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = lbl_805DDF60 * (a.x + sd->x);
    a.y = lbl_805DDF60 * (a.y + sd->y);
    a.z = lbl_805DDF60 * (a.z + sd->z);
    VecCopy((Vec *)(self->body + 0x38), (const Vec *)&a);
    ((TObjPlayer *)(self->body + 0x5C))->copy_xyz(&self->fA0);
    for (i = 0; i < TLobby::get_lobby_flag(); i++) {
        p = (Pl_802A3DE8 *)get_player_data__10TObjPlayerFi(i);
        if (p == 0) continue;
        if ((p->flags & 0x20000000) || (p->flags & 0x10000000)) {
            if ((u16)get_entity_id(p) == (u16)get_entity_id(src)) continue;
            r = (TechniqueContactBody *)((TUnk_804AF8A0 *)((u8 *)self->body))->find_actor_body_contact((u8 *)p, (f32)lbl_805DDF64);
            if (r == 0) continue;
            L_802A3DE8.bodies[L_802A3DE8.count] = r;
            L_802A3DE8.actors[L_802A3DE8.count] = (TechniqueContactActor *)p;
            if (++L_802A3DE8.count >= 0x10) {
                L_802A3DE8.count = 0xF;
                break;
            }
        } else if ((p->flags & 0x40000000) && !(p->flags & 0x80000000)) {
            if (((TUnk_804AF8A0 *)((u8 *)self->body))->find_actor_body_contact((u8 *)p, (f32)lbl_805DDF64) != 0) return 0;
        }
    }
    return &L_802A3DE8;
}
struct Vec_802A3DE8;
struct Pl_802A3DE8;
#define L_802A41CC (*(TechniqueContactList *)&technique_contact_list)

#define L_802A3FDC (*(TechniqueContactList *)&technique_contact_list)
TechniqueContactList *TObjPlayer__sub_802A3FDC(Obj_802A3FDC *self, void *src) {
    Vec_802A3FDC a;
    Vec_802A3FDC d;
    s32 i;
    Vec_802A3FDC *sd;
    u32 id;
    Pl_802A3FDC *p;
    TechniqueContactBody *r;
    VecCopy((Vec *)&a, (const Vec *)&self->pos);
    ((void (*)(void *))clear_technique_contacts__10TObjPlayerFv)(self);
    if (self->body == 0) return &L_802A3FDC;
    sd = ((Vec_802A3FDC *)get_shoot_data__12TNeedleShootFv(self));
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = lbl_805DDF60 * (a.x + sd->x);
    a.y = lbl_805DDF60 * (a.y + sd->y);
    a.z = lbl_805DDF60 * (a.z + sd->z);
    VecCopy((Vec *)(self->body + 0x38), (const Vec *)&a);
    ((TObjPlayer *)(self->body + 0x5C))->copy_xyz(&self->fA0);
    for (i = TLobby::get_game_mode(); i < TLobby::get_lobby_flag(); i++) {
        p = ((Pl_802A3FDC *)get_player_data__10TObjPlayerFi(i));
        if (p == 0) continue;
        if (p->flags & 0x20000000) {
            if ((u16)get_entity_id(p) != (u16)get_entity_id(src)) {
                r = (TechniqueContactBody *)((TUnk_804AF8A0 *)((u8 *)self->body))->find_actor_body_contact((u8 *)p, (f32)lbl_805DDF64);
                if (r != 0) {
                    L_802A3FDC.bodies[L_802A3FDC.count] = r;
                    L_802A3FDC.actors[L_802A3FDC.count] = (TechniqueContactActor *)p;
                    if (++L_802A3FDC.count >= 0x10) {
                        L_802A3FDC.count = 0xF;
                        break;
                    }
                }
            }
        } else if ((p->flags & 0x40000000) && !(p->flags & 0x80000000)) {
            if (((TUnk_804AF8A0 *)((u8 *)self->body))->find_actor_body_contact((u8 *)p, (f32)lbl_805DDF64) != 0) return 0;
        }
    }
    return &L_802A3FDC;
}

TechniqueContactList *TObjPlayer::collect_technique_contacts(void *src) {
    Vec_802A41CC a;
    Vec_802A41CC d;
    Vec_802A41CC *sd;
    Pl_802A41CC *p;
    s32 i;
    s32 n;
    TechniqueContactBody *r;
    VecCopy((Vec *)&a, (const Vec *)(&((Obj_802A41CC *)this)->pos));
    ((void (*)(void *))clear_technique_contacts__10TObjPlayerFv)(this);
    if (((Obj_802A41CC *)this)->body == 0) return &L_802A41CC;
    sd = (Vec_802A41CC *)get_shoot_data__12TNeedleShootFv(this);
    d.x = a.x - sd->x;
    d.y = a.y - sd->y;
    d.z = a.z - sd->z;
    vector_length(&d);
    a.x = lbl_805DDF60 * (a.x + sd->x);
    a.y = lbl_805DDF60 * (a.y + sd->y);
    a.z = lbl_805DDF60 * (a.z + sd->z);
    VecCopy((Vec *)(((Obj_802A41CC *)this)->body + 0x38), (const Vec *)&a);
    ((TObjPlayer *)(((Obj_802A41CC *)this)->body + 0x5C))->copy_xyz(&((Obj_802A41CC *)this)->fA0);
    if ((u16)get_entity_id(src) < 4) {
        n = TLobby::get_lobby_flag();
        for (i = 0; i < n; i++) {
            p = (Pl_802A41CC *)get_player_data__10TObjPlayerFi(i);
            if (p == 0) continue;
            if ((u16)get_entity_id(p) == (u16)get_entity_id(src)) continue;
            r = (TechniqueContactBody *)((TUnk_804AF8A0 *)(((Obj_802A41CC *)this)->body))->find_actor_body_contact((u8 *)p, (f32)lbl_805DDF64);
            if (r == 0) continue;
            if ((p->flags & 0x20000000) || (p->flags & 0x10000000)) {
                L_802A41CC.bodies[L_802A41CC.count] = r;
                L_802A41CC.actors[L_802A41CC.count] = (TechniqueContactActor *)p;
                if (++L_802A41CC.count >= 0x10) {
                    L_802A41CC.count = 0xF;
                    break;
                }
            }
        }
    } else {
        s32 j;
        for (j = 0; j < 4; j++) {
            p = (Pl_802A41CC *)find_entity_by_id(j);
            if (p == 0) continue;
            if ((u16)get_entity_id(p) == (u16)get_entity_id(src)) continue;
            r = (TechniqueContactBody *)((TUnk_804AF8A0 *)(((Obj_802A41CC *)this)->body))->find_actor_body_contact((u8 *)p, (f32)lbl_805DDF64);
            if (r == 0) continue;
            if (p->flags & 0x10000000) {
                L_802A41CC.bodies[L_802A41CC.count] = r;
                L_802A41CC.actors[L_802A41CC.count] = (TechniqueContactActor *)p;
                if (++L_802A41CC.count >= 0x10) {
                    L_802A41CC.count = 0xF;
                    break;
                }
            }
        }
    }
    return &L_802A41CC;
}

}
