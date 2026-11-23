#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/PlayerSlots.h"


struct B_80312D4C { char pad[0x18]; };

struct Ply_80312D4C : B_80312D4C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(f32);
};

extern "C" {
int TObjPlayer__sub_80313218(void* p);
u8 *TObjPlayer__sub_80312FB0(TObjPlayer *player);
void append_photon_blast_request(saddr arg0, u16 arg1, s16 arg2);
int TObjPlayer__sub_803131AC(void* a0);
void TObjPlayer__sub_80312E98(void *o, u16 id);
void *TObjPlayer__sub_803131B4(void *, int);
void set_field_0__10TObjPlayerFUs(void* p, u16 v);
void TObjPlayer__sub_80313250(void *arg0, s32 arg1);
void TObjPlayer__sub_80313010(void *o, u16 id);
u16 get_client_id__18PhotonBlastRequestFv(void *);
int TObjPlayer__sub_803131AC(void* a0 = 0);
}
void release_photon_blast_requests(void *registry);

void release_photon_blast_requests(void *registry) {
    s32 count;
    saddr i;
    u8 *owner;
    count = TObjPlayer__sub_803131AC(registry);
    for (i = 0; i < count; i++) {
        u16 player = ((u16)((PhotonBlastRequest *)(TObjPlayer::get_element(registry, i)))->get_client_id());
        if (player != 0xFFFF) {
            owner = (u8 *)get_player_by_client_id(player);
            if (owner != NULL) {
                ((PhotonBlastGauge *)(owner + 0x4AC))->check_photon_blast_flag();
                ((PhotonBlastGauge *)(owner + 0x4AC))->trigger_photon_blast();
            }
        }
    }
}

void *TObjPlayer::find_by_section_id(u16 section) {
    s32 n;
    saddr i;
    u8 *e;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        e = (u8 *)TObjPlayer::get_element(this, i);
        if (section == (u16)((PhotonBlastRequest *)e)->get_client_id()) {
            return TObjPlayer__sub_803131B4(e, 0);
        }
    }
    return 0;
}

void TObjPlayer::create_party_effects(u16 id) {
    s32 n;
    saddr i;
    u16 sec;
    Ply_80312D4C *ent;
    u8 *e;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        e = (u8 *)TObjPlayer::get_element(this, i);
        sec = get_client_id__18PhotonBlastRequestFv(e);
        ent = (Ply_80312D4C *)get_player_by_client_id(sec);
        if (ent != NULL && id != sec && ((TObjPlayer *)ent)->photon_blast_gauge.query_field40() != 0) {
            TWindowCtrl::create_party_effect(id, sec);
            TObjPlayer__sub_80313010(e, id);
            ent->m75(10.0f);
        }
    }
}

typedef u16 (*SectionFn_80312E0C)(void *);
u16 TObjPlayer::find_first_valid_target_id() {
    s32 n;
    saddr i;
    u8 *e;
    u8 *ent;
    n = TObjPlayer__sub_803131AC(this);
    for (i = 0; i < n; i++) {
        e = (u8 *)TObjPlayer::get_element(this, i);
        ent = (u8 *)get_player_by_client_id(((SectionFn_80312E0C)get_client_id__18PhotonBlastRequestFv)(e));
        if (ent != NULL && ((TObjPlayer *)ent)->photon_blast_gauge.query_field40() != 0) {
            return ((SectionFn_80312E0C)get_client_id__18PhotonBlastRequestFv)(e);
        }
    }
    return 0xFFFF;
}

void TObjPlayer__sub_80312E98(void *o, u16 id) {
    s32 n = TObjPlayer__sub_803131AC(o);
    saddr i;
    for (i = 0; i < n; i++) {
        if (id == ((u16)((PhotonBlastRequest *)(TObjPlayer::get_element(o, i)))->get_client_id())) {
            ((TObjPlayer *)o)->process_indexed_element(i);
        }
    }
}

void TObjPlayer::process_all_elements() {
    int n = TObjPlayer__sub_803131AC(this);
    int i;
    for (i = 0; i < n; i++) {
        process_indexed_element(i);
    }
}

void append_photon_blast_request(saddr arg0, u16 type, s16 kind) {
    saddr temp_r3;
    temp_r3 = ((saddr)TObjPlayer__sub_80312FB0((TObjPlayer *)((u8 *)arg0)));
    if (temp_r3 != 0) {
        ((TObjPlayer *)temp_r3)->check_flag_at_4();
        ((PhotonBlastRequest *)temp_r3)->set_client_id(type);
        ((PhotonBlastRequest *)temp_r3)->set_kind(kind);
    }
}

u8 *TObjPlayer__sub_80312FB0(TObjPlayer *player) {
    s32 var_r31;
    u8 *temp_r3;
    var_r31 = 0;
loop_1:
    temp_r3 = (u8 *)(TObjPlayer::get_element(player, var_r31));
    if (TObjPlayer__sub_80313218(temp_r3) != 0) {
        return temp_r3;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        return NULL;
    }
    goto loop_1;
}
void TObjPlayer__sub_80313010(void *o, u16 id) {
    s32 n;
    saddr i;
    void *e;
    n = TObjPlayer::get_max_children(o);
    for (i = 0; i < n; i++) {
        e = TObjPlayer__sub_803131B4(o, i);
        if (id == ((PhotonBlastRequestSlot *)e)->get_client_id()) {
            TObjPlayer__sub_80313250(e, 10);
            return;
        }
        if (((PhotonBlastRequestSlot *)e)->get_client_id() == 0xFFFF) {
            set_field_0__10TObjPlayerFUs(e, id);
            TObjPlayer__sub_80313250(e, 10);
            return;
        }
    }
}
