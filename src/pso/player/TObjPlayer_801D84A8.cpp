#include "types.h"
#include "pso/object/TObjWarpBossMulti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804C4540.h"
struct Tag_801D7D4C { u8 d[4]; };

struct Obj_801D7D4C { s32 n; Tag_801D7D4C x[4]; Tag_801D7D4C y[4]; };

struct Tec_801D7DA4 { u8 pad[0x10]; s16 cost; };

struct TItemData_801D8044 { u8 kind; u8 type; u8 sub; u8 pad[0x11]; };

struct TObjPlayer_801D8044 {
    u8 pad0[0x428];
    u8 slots[0x4ac - 0x428];
    u8 cursor[0xd00 - 0x4ac];
    void *fd00;
};

extern "C" {
void init__6gc_tagFv(void *);
s32 obj_testFlags30__13TUnk_804AF8A0FUl(void *, u32);
s32 reset_key_machine_state__10TObjPlayerFv();
u8 get_cast_technique_level(void *, int);
Tec_801D7DA4 *calc_technique_parameters(s32, s32, s32);
s32 get_game_play_mode();
s32 is_technique_ready__8TTecCtrlFv();
s32 TObjPlayer__sub_801C1F50(void *);

u32 get_item_field_6__10TObjPlayerFPv(void *);
s32 weapon_has_extra_attack(u32);
int check_flag_100__10TObjPlayerFPv(void *p);
s32 validate_and_clear_slot__10TObjPlayerFv(void *, s32);
void init__9TItemDataFv(void *);
void *set_mode_and_refresh_object__10TObjPlayerFPvi(void *, TItemData_801D8044 *);
s32 is_boss_area(void);
s32 TObjPlayer__sub_801AF694(void *, s32);
u16 get_entity_id(void *);
s32 TWindowCtrl__sub_8024A228(s32);
s32 TMainCursor__sub_8013F244(void *);
s32 fn_8013F24C(void *, s32);
s32 is_palette_entry_displayable__10TObjPlayerFv(u8 *, u8, u8);
bool can_use_palette_action__10TObjPlayerFPvUcUc(TObjPlayer_801D8044 *self, u8 kind, u8 arg);
void TObjPlayer::init_action_config() {
    s32 i;
    i = 0;
    ((Obj_801D7D4C *)this)->n = 0;
    do {
        init__6gc_tagFv(&((Obj_801D7D4C *)this)->x[i]);
        init__6gc_tagFv(&((Obj_801D7D4C *)this)->y[i]);
        i++;
    } while (i < 4);
}
s32 is_palette_entry_displayable__10TObjPlayerFv(u8 *arg0, u8 kind, u8 sub) {
    s32 tec;

    switch (kind) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x20006) != 0 || reset_key_machine_state__10TObjPlayerFv() == 0 || ((TObjPlayer *)arg0)->get_camera_field() == 0) {
            return 0;
        }
        if ((u8)sub == 2) {
            if (get_item_field_6__10TObjPlayerFPv(arg0) != 0) {
                if (((s32 (*)())weapon_has_extra_attack)() == 0) {
                    return 0;
                }
            } else {
                return 0;
            }
        }
        return 1;
    case 3:
        if (((TObjPlayer *)(arg0 + 0x428))->test_bit1_at_10() != 0 || obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x20006) != 0 || ((TObjPlayer *)arg0)->get_camera_field() == 0) {
            return 0;
        }
        if (*(s16 *)(arg0 + 0x32E) - calc_technique_parameters(tec = sub, get_cast_technique_level(arg0 + 0x428, sub), ((s32 (*)(void *))get_entity_id)(arg0))->cost < 0) {
            return 0;
        }
        switch (tec) {
        case 0x11:
            if (get_game_play_mode() == 1) {
                return 0;
            }
            break;
        case 0xE:
            if (TObjWarpBossMulti::is_flag_clear(arg0) == 0) {
                return 0;
            }
            if (is_technique_ready__8TTecCtrlFv() != 0 || get_game_play_mode() == 1) {
                return 0;
            }
            break;
        }
        return 1;
    case 4:
        if (((TObjPlayer *)arg0)->get_camera_field() == 0) {
            return 0;
        }
        switch ((u8)sub) {
        case 9:
            if (get_game_play_mode() == 1) {
                return 0;
            }
            break;
        case 10:
            break;
        case 11:
            if (TObjWarpBossMulti::is_flag_clear(arg0) == 0) {
                return 0;
            }
            if (is_technique_ready__8TTecCtrlFv() != 0) {
                return 0;
            }
            break;
        }
        return 1;
    case 5:
        if (TObjPlayer__sub_801C1F50(arg0 + 0x4AC) == 0 || obj_testFlags30__13TUnk_804AF8A0FUl(arg0, 0x20006) != 0 || ((TObjPlayer *)arg0)->get_camera_field() == 0) {
            return 0;
        }
        return 1;
    case 7:
        return 1;
    }
    return 0;
}
bool can_use_palette_action__10TObjPlayerFPvUcUc(TObjPlayer_801D8044 *self, u8 kind, u8 arg) {
    TItemData_801D8044 item;
    u32 w;
    switch (kind) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (arg == 2) {
            w = get_item_field_6__10TObjPlayerFPv(self);
            if (w != 0) {
                if (weapon_has_extra_attack(w) == 0) {
                    return 0;
                }
            } else {
                return 0;
            }
        }
        if (check_flag_100__10TObjPlayerFPv(self) != 0) {
            return 1;
        }
        break;
    case 3:
        if (validate_and_clear_slot__10TObjPlayerFv(self->slots, arg) != 0) {
            return 0;
        }
        if (check_flag_100__10TObjPlayerFPv(self) != 0) {
            return 1;
        }
        break;
    case 4:
        init__9TItemDataFv(&item);
        item.kind = 3;
        switch (arg) {
        case 0:
            item.type = 0;
            item.sub = 0;
            break;
        case 1:
            item.type = 0;
            item.sub = 1;
            break;
        case 2:
            item.type = 0;
            item.sub = 2;
            break;
        case 3:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 1;
            item.sub = 0;
            break;
        case 4:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 1;
            item.sub = 1;
            break;
        case 5:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 1;
            item.sub = 2;
            break;
        case 6:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 6;
            item.sub = 0;
            break;
        case 7:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 6;
            item.sub = 1;
            break;
        case 8:
            item.type = 3;
            break;
        case 9:
            item.type = 4;
            break;
        case 10:
            item.type = 5;
            break;
        case 11:
            item.type = 7;
            break;
        case 12:
            if (((TObjPlayer *)self)->is_android() != 0) {
                return 0;
            }
            item.type = 8;
            break;
        }
        if (arg < 0xd || arg > 0x10) {
            if (set_mode_and_refresh_object__10TObjPlayerFPvi(self->fd00, &item) == 0) {
                return 0;
            }
        } else {
            if (is_boss_area() != 0) {
                return 0;
            }
            switch (arg) {
            case 0xd:
                if (TObjPlayer__sub_801AF694(self, 0) != 0) {
                    return 0;
                }
                if (TWindowCtrl__sub_8024A228(get_entity_id(self)) == 0) {
                    return 0;
                }
                break;
            case 0xe:
                if (TObjPlayer__sub_801AF694(self, 1) != 0) {
                    return 0;
                }
                if (TWindowCtrl__sub_8024A228(get_entity_id(self)) == 0) {
                    return 0;
                }
                break;
            case 0xf:
                if (TObjPlayer__sub_801AF694(self, 2) != 0) {
                    return 0;
                }
                if (TWindowCtrl__sub_8024A228(get_entity_id(self)) == 0) {
                    return 0;
                }
                break;
            case 0x10:
                if (TObjPlayer__sub_801AF694(self, 3) != 0) {
                    return 0;
                }
                if (TWindowCtrl__sub_8024A228(get_entity_id(self)) == 0) {
                    return 0;
                }
                break;
            }
        }
        if (check_flag_100__10TObjPlayerFPv(self) != 0) {
            return 1;
        }
        break;
    case 5:
        if ((s8)fn_8013F24C(self->cursor, arg) == (s8)TMainCursor__sub_8013F244(self)) {
            return 0;
        }
        break;
    case 7:
        return 1;
    }
    return is_palette_entry_displayable__10TObjPlayerFv((u8 *)self, kind, arg) != 0;
}

}

struct Obj_801D8474 { s8 a; u8 b; };

extern "C" {

s32 TObjPlayer__sub_801D8664(s32, s16, s16);
void *get_anim_table_entry__10TObjPlayerFl();
s32 TObjPlayer__sub_801D84A8(void* p);
s32 TObjPlayer__sub_801D84F0(void* p);
int bswap_16__FPUs(void*);

s32 TObjPlayer::can_use_palette_action_for_entry(u32 obj) {
    return ((s32 (*)(u32, u8, u8))can_use_palette_action__10TObjPlayerFPvUcUc)(obj, ((Obj_801D8474 *)this)->a, ((Obj_801D8474 *)this)->b);
}

s32 TObjPlayer__sub_801D84A8(void* p) { return *(s32*)((char*)p + 0x0); }

u8 *TObjPlayer__sub_801D84B0(s32 *arg0);

u8 *TObjPlayer__sub_801D84B0(s32 *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0) == 0) {
        return (u8 *)arg0 + 4;
    }
    return (u8 *)arg0 + 0x14;
}

u32 advance_item_id_counter(s32 client);
void equip_saved_item_if_slot_empty__10TObjPlayerFPvPv(u8 *arg0, u8 *arg1);

int TObjPlayer::bswap_disp_config_field() { return bswap_16__FPUs((char*)this + 0x2); }
s32 TObjPlayer__sub_801D84F0(void* p) { return *(s32*)((char*)p + 0x4); }
void TObjPlayer::set_animation_from_data(s32 arg0, s32 arg1) {
    void *temp_r3;

    temp_r3 = get_anim_table_entry__10TObjPlayerFl();
    TObjPlayer__sub_801D8664(arg0, *(s16 *)((s8 *)temp_r3 + 0), *(s16 *)((s8 *)temp_r3 + 2));
    ((TUnk_804C4540 *)arg0)->set_animation_default(arg1);
}

extern s32 local_client_id;

void TObjPlayer::assign_lobby_slot_if_flagged(s32 arg0, void *arg1) {
    if (*(s32 *)((s8 *)arg1 + 4) & 8) {
        *(s32 *)((s8 *)arg1 + 0x14) = advance_item_id_counter((u16) local_client_id);
        equip_saved_item_if_slot_empty__10TObjPlayerFPvPv((u8 *)arg0, (u8 *)arg1);
    }
}

}
