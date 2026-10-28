#include "types.h"
#include "pso/TSetManager.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TScene.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

struct Dst_8020DEE4 { u16 id; s16 v; u8 pad[4]; };

struct SrcA_8020DEE4 { u8 pad0[2]; s16 v; u8 pad4[4]; u16 id; u8 padA[0x44 - 0xA]; };

struct SrcB_8020DEE4 { u8 pad0[2]; s16 v; u8 pad4[6]; u16 id; u8 padC[0x48 - 0xC]; };

struct Area_8020DEE4 { s32 countA; s32 countB; u8 pad8[8]; Dst_8020DEE4 *a; Dst_8020DEE4 *b; };

struct Vec3_8020DB44 { s32 a, b, c; };

struct A_8020DBCC { s16 a; s16 b; };

struct B_8020DBCC { s16 a; s16 b; s16 c; s16 d; s16 e; s16 f; };

struct Room_8020D9A0 { u8 pad0[8]; s32 name; };

struct Grp_8020D9A0 { Room_8020D9A0 *room; s32 count; };

struct Map_8020D9A0 { Grp_8020D9A0 *grp; s32 count; };

struct Rec_8020D9A0 { u8 pad0[2]; s16 f2; s16 f4; u8 pad6[2]; u16 f8; u8 padA[0x3A]; };

extern "C" {
void TLobby__sub_8020D94C(void);
extern s16 TLobby__data_805D6134;
s32 get_current_floor(void);
extern Area_8020DEE4 TLobby__floor_enemy_group_table[];
extern SrcA_8020DEE4 *TLobby__data_805D610C;
extern SrcB_8020DEE4 *TLobby__data_805D6114;
void depart_floor_population(int unused);
s32 lookup_scene_object__6TLobbyFPv(s32, void *);
void *memset(void *, int, unsigned long);
extern A_8020DBCC *quest_object_entries;
extern B_8020DBCC *TLobby__data_805D6144;
void read_disc_file(char *, void *);
s32 replace_file_extension__6TLobbyFPvPvPv(char *arg0, char *arg1, char *arg2);
void *mem_alloc(u32);
}
void arrive_floor_population(void);
extern s32 lbl_805D60F8;
extern s32 TLobby__data_805D60FC;
extern u32 TLobby__data_805D611C;
extern s32 TLobby__data_805D6120;
extern u32 TLobby__data_805D6124;
extern s32 TLobby__data_805D6128;
void swap_object_row_endian(void *);
extern char lbl_8044BC24[];
extern char lbl_8044BC2C[];
extern Map_8020D9A0 *TLobby__data_805D6068;
s32 load_map_decoration_rows(s32 map, s32 grp, s32 room);
extern "C" {
void* TSetManager__ct(void*, s32);
void* __nw__7TObjectFUl(u32);
void mem_free(void*);

extern s32 tl_02;

void TSetManager::create() {
    void* obj = __nw__7TObjectFUl(0x20);
    if (obj != 0) {
        TSetManager__ct(obj, tl_02);
    }
}

void TLobby__sub_8020D94C(void) {
    if ((u32) TLobby__data_805D611C != 0U) {
        mem_free((void*)TLobby__data_805D611C);
        TLobby__data_805D611C = 0U;
        TLobby__data_805D6120 = 0;
    }
    if ((u32) TLobby__data_805D6124 != 0U) {
        mem_free((void*)TLobby__data_805D6124);
        TLobby__data_805D6124 = 0U;
        TLobby__data_805D6128 = 0;
    }
}
}

s32 load_map_decoration_rows(s32 map, s32 grp, s32 room) {
    Room_8020D9A0 *r;
    s32 i;
    s32 size;
    char path[0x20];
    if (TLobby__data_805D6068[map].grp == NULL || TLobby__data_805D6068[map].count - 1 < grp) {
        return 0;
    }
    r = TLobby__data_805D6068[map].grp[grp].room;
    if (r == NULL || TLobby__data_805D6068[map].grp[grp].count - 1 < room) {
        return 0;
    }
    if (TLobby::is_online_ready() != 0) {
        replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)r->name, (char *)lbl_8044BC24);
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)path, (char *)r->name, (char *)lbl_8044BC2C);
    }
    size = ((TScene *)path)->update_lobby_scene();
    if (size < 0) {
        return 0;
    }
    TLobby__data_805D6120 = (u32)size / 0x44;
    if ((TLobby__data_805D611C = (u32)mem_alloc(TLobby__data_805D6120 * 0x44)) == 0) {
        return 0;
    }
    read_disc_file(path, (void *)TLobby__data_805D611C);
    for (i = 0; i < TLobby__data_805D6120; i++) {
        swap_object_row_endian(&((Rec_8020D9A0 *)TLobby__data_805D611C)[i]);
        ((Rec_8020D9A0 *)TLobby__data_805D611C)[i].f2 = 0;
        ((Rec_8020D9A0 *)TLobby__data_805D611C)[i].f8 = 0xFFFF;
        ((Rec_8020D9A0 *)TLobby__data_805D611C)[i].f4 = -1;
    }
    return 1;
}

#pragma push
#pragma scheduling off

void TLobby::clear_floor_flags_and_depart() {
    s32 unused;
    TLobby__sub_8020D94C();
    unused = TLobby__data_805D6134 & ~8;
    TLobby__data_805D6134 = unused;
    TLobby__data_805D6134 &= ~16;
    depart_floor_population(unused);
}
#pragma pop

void TLobby::setup_floor_decorations() {
    Vec3_8020DB44 v;
    s32 t;
    s32 r;
    arrive_floor_population();
    (*(s32 *)&TLobby__data_805D611C) = 0;
    TLobby__data_805D6134 &= ~8;
    (*(s32 *)&TLobby__data_805D6124) = 0;
    TLobby__data_805D6120 = 0;
    TLobby__data_805D6128 = 0;
    TLobby__data_805D6134 &= ~16;
    lbl_805D60F8 = get_current_floor_area();
    r = get_current_floor();
    TLobby__data_805D60FC = r;
    if (lookup_scene_object__6TLobbyFPv(r, &v) != 0) {
        load_map_decoration_rows(v.a, v.b, v.c);
        return;
    }
    lbl_805D60F8 = -1;
}

void TLobby::reset_id_tables() {
    s32 i;
    s32 n = 0;
    if (quest_object_entries != 0) {
        memset(quest_object_entries, 0, 0x2E80);
        for (i = 0; i < 0xBA0; i++) {
            s16 t = n + 0x100;
            n++;
            quest_object_entries[i].b = t;
        }
    }
    if (TLobby__data_805D6144 != 0) {
        memset(TLobby__data_805D6144, 0, 0x87C0);
        for (i = 0; i < 0xB50; i++) {
            s16 t = n + 0x100;
            n++;
            TLobby__data_805D6144[i].c = t;
        }
    }
}

void depart_floor_population(int unused) {
    Area_8020DEE4 *area = &TLobby__floor_enemy_group_table[get_current_floor()];
    if (TLobby__data_805D610C != 0) {
        SrcA_8020DEE4 *s = TLobby__data_805D610C;
        Dst_8020DEE4 *d = area->a;
        s32 i;
        for (i = 0; i < area->countA; i++, s++, d++) {
            if (s->id == d->id) {
                d->v = s->v;
            }
        }
    }
    if (TLobby__data_805D6114 != 0) {
        SrcB_8020DEE4 *s = TLobby__data_805D6114;
        Dst_8020DEE4 *d = area->b;
        s32 i;
        for (i = 0; i < area->countB; i++, s++, d++) {
            if (s->id == d->id) {
                d->v = s->v;
            }
        }
    }
    if (TLobby__data_805D6114 != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)TLobby__data_805D6114);
        TLobby__data_805D6114 = 0;
    }
    if (TLobby__data_805D610C != 0) {
        TAdSinglePlyChrSelectGC::safe_free((u32)TLobby__data_805D610C);
        TLobby__data_805D610C = 0;
    }
}
