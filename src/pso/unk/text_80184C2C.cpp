#include "types.h"
#include "pso/unk/text_800F5BC0.h"
#include "pso/unk/text_80184C2C.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/warp/TObjLaboMapWarp.h"

struct Obj_80185160 { u8 pad[0x8C]; s32 dest; };

extern int lbl_8050DC20[];
extern s32 lobby_event_theme_id_table[];
extern s32 TLobby__event_theme_id;
extern "C" {
void debug_printf_at(s32 id, const char *fmt, ...);
extern const char lbl_804449C0[];
extern const char lbl_804449D0[];
extern const char lbl_804449E0[];
extern const char lbl_804449F0[];
extern const char lbl_80444A00[];
extern const char lbl_80444A10[];
extern const char *labo_map_warp_dest_name_table_b[];
void TLobby__sub_8001FE7C(void *, s32);
extern int city_season_easter_egg_model_table[];
extern int city_season_xmas_model_table[];
extern void *lbl_805D5B34;
extern void *lbl_805D5B38;
extern s32 lbl_805D5B3C;
extern s32 lbl_805D5B40;
extern s32 lbl_805D5B44;
extern void *lbl_805D5B48;

int TLobby__sub_80184C2C(int a0) {  return city_season_xmas_model_table[a0]; }
}

int get_season_model_resource(int a0) {  return city_season_easter_egg_model_table[a0]; }

extern s32 lbl_805D5B30;

u8 TLobby__sub_80184C54(void) {
    return (u8) (lbl_805D5B30 != -1);
}

int TLobby__sub_80184C6C(int a0) {  return lbl_8050DC20[a0]; }

void TLobby__sub_80184C80(void *p) {
    s32 i;
    TLobby::clear_global_array(p);
    for (i = 0; i < 6; i++) {
        if (TLobby__event_theme_id == lobby_event_theme_id_table[i]) {
            lbl_8050DC20[i] = 1;
            return;
        }
    }
}

void TLobby__sub_80184CE0(void* p) { TLobby::clear_global_array(p); }
void TLobby::clear_global_array(void* _w0) {
    s32 i;
    for (i = 0; i < 6; i++) {
        ((s32 *)&lbl_8050DC20)[i] = 0;
    }
}

void TLobby::free_buffers() {
    s32 i;
    if (lbl_805D5B48 != NULL) {
        destroy_buffer_pair(lbl_805D5B48, 1);
        lbl_805D5B48 = NULL;
    }
    if (lbl_805D5B38 != NULL) {
        TLobby__sub_8001FE7C(lbl_805D5B38, 1);
        lbl_805D5B38 = NULL;
    }
    lbl_805D5B44 = 0;
    lbl_805D5B3C = 0;
    lbl_805D5B40 = 0;
    if (lbl_805D5B34 != NULL) {
        destroy_buffer_pair(lbl_805D5B34, 1);
        lbl_805D5B34 = NULL;
    }
    for (i = 5; i >= 0; i--) {
        if ((u32)city_season_easter_egg_model_table[i] != 0) {
            TLobby__sub_8001FE7C((void *)city_season_easter_egg_model_table[i], 1);
        }
        city_season_easter_egg_model_table[i] = 0;
        city_season_xmas_model_table[i] = 0;
    }
}

extern "C" s32 get_main_phase(void);
extern "C" extern u8 lbl_804B5E80[];
extern "C" void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern "C" void clear_global_array__6TLobbyFPv();

extern "C" void TLobby__sub_80184DF4(void) {
    s32 i;
    s32 count;
    u8 *obj;
    u8 *tmp;
    u8 *base;
    u8 *ent;
    s32 ph;
    void *p;
    s32 off;

    obj = lbl_804B5E80;
    clear_global_array__6TLobbyFPv();
    ph = get_main_phase();
    if (ph == 0xf) {
        TLobby__sub_80184C80((void *)ph);
    } else {
        TLobby__sub_80184CE0((void *)ph);
    }
    lbl_805D5B30 = -1;
    for (i = 0; i < 6; i++) {
        if (TLobby__sub_80184C6C(i)) {
            lbl_805D5B30 = i;
            break;
        }
    }
    if (lbl_805D5B30 != -1) {
        {
            s32 j;
            for (j = 0; j < 6; j++) {
                city_season_easter_egg_model_table[j] = 0;
                city_season_xmas_model_table[j] = 0;
            }
        }
        tmp = (u8 *)::operator new(0x440);
        if (tmp != NULL) {
            void **d = (void **)(obj + 0x15c);
            d += lbl_805D5B30;
            tmp = (u8 *)load_resource_from_descriptor(tmp, 1, *d, 0, 0, 0);
        }
        off = lbl_805D5B30 * 4;
        *(s32 *)((u8 *)city_season_easter_egg_model_table + off) = (int)tmp;
        for (i = 0; i < *(s32 *)(tmp + 0x434); i++) {
            if ((*(u32 (**)[4])(tmp + 0x42c))[i][3] != 0) {
                *(s32 *)((u8 *)city_season_xmas_model_table + off) = (*(u32 (**)[4])(tmp + 0x42c))[i][3];
                break;
            }
        }
        if (lbl_805D5B30 == 0) {
            base = *(u8 **)(tmp + 0x42c);
            ent = *(u8 **)(base + 0x18);
            tmp = (u8 *)::operator new(0x14);
            if (tmp != NULL) tmp = (u8 *)((TLobby *)tmp)->alloc_tables((s32)ent, 3);
            lbl_805D5B34 = tmp;
            base = *(u8 **)(*(u8 **)(ent + 0x2c) + 4);
            base = *(u8 **)(base + 4);
            *(s16 *)(base + 0xc) &= ~0x1000;
        } else if (lbl_805D5B30 == 4) {
            base = *(u8 **)(tmp + 0x42c);
            ent = *(u8 **)(base + 0x18);
            tmp = (u8 *)::operator new(0x14);
            if (tmp != NULL) tmp = (u8 *)((TLobby *)tmp)->alloc_tables((s32)ent, 0);
            lbl_805D5B34 = tmp;
            base = *(u8 **)(*(u8 **)(ent + 0x2c) + 4);
            base = *(u8 **)(base + 4);
            *(s16 *)(base + 0xc) &= ~0x1000;
        } else {
            lbl_805D5B34 = NULL;
        }
    }

    if (lbl_805D5B30 == 2) {
        u8 *r = (u8 *)::operator new(0x440);
        if (r != NULL) {
            r = (u8 *)load_resource_from_descriptor(r, 1, obj + 0x130, 0, 0, 0);
        }
        obj = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    } else if (lbl_805D5B30 == 4) {
        u8 *r = (u8 *)::operator new(0x440);
        if (r != NULL) {
            r = (u8 *)load_resource_from_descriptor(r, 1, obj + 0x14c, 0, 0, 0);
        }
        obj = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    } else {
        u8 *r = (u8 *)::operator new(0x440);
        if (r != NULL) {
            r = (u8 *)load_resource_from_descriptor(r, 1, obj + 0x114, 0, 0, 0);
        }
        obj = r;
        lbl_805D5B3C = *(s32 *)(*(u8 **)(r + 0x42c) + 8);
        lbl_805D5B40 = *(s32 *)(*(u8 **)(r + 0x42c) + 0x18);
    }

    tmp = (u8 *)::operator new(0x14);
    if (tmp != NULL) tmp = (u8 *)((TLobby *)tmp)->alloc_tables((s32)(void *)lbl_805D5B3C, 2);
    lbl_805D5B48 = tmp;
    base = (u8 *)lbl_805D5B3C;
    base = *(u8 **)(base + 4);
    base = *(u8 **)(base + 4);
    *(s16 *)(base + 0xc) &= ~0x2000;
    lbl_805D5B38 = obj;
    for (i = 0; i < *(s32 *)(obj + 0x434); i++) {
        if ((*(u32 (**)[4])(obj + 0x42c))[i][3] != 0) {
            lbl_805D5B44 = (*(u32 (**)[4])(obj + 0x42c))[i][3];
            break;
        }
    }
}


void TObjLaboMapWarp::slot4C() {
    Obj_80185160 *self = (Obj_80185160 *)this;
    ((TObjLaboMapWarp *)self)->clamp_index();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, lbl_804449C0);
    debug_printf_at(0x13001D, lbl_804449D0);
    debug_printf_at(0x13001E, lbl_804449E0);
    debug_printf_at(0x130020, lbl_804449F0);
    debug_printf_at(0x130021, lbl_80444A00);
    debug_printf_at(0x130022, lbl_80444A10, labo_map_warp_dest_name_table_b[this->set_params[2]]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
