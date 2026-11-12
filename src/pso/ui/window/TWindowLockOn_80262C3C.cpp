#include "types.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowHelpItem_8025A60C.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowSubStatusDisp_8026F6DC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowLockOn_80262C3C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/ui/window/TWindowBase.h"
#include <stddef.h>
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/system/task/TObject.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/object/switch/TOSwitchItem.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on
#pragma defer_codegen on

extern s32 lbl_805D63F0;

const char *TWindowLockOn__name = "TWindowLockOn";

// Other player: portrait sprite, name text.
struct LockOnPlayerLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
};

// Ground item: item row, grade stars.
struct LockOnItemLayout {
    u32 cols;
    u32 rows;
    TypeLayoutRecord rec_0;
    PointLayoutRecord rec_1;
};

// Enemy: name, label, type, four status icons, two gauges.
struct LockOnEnemyLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    TextLayoutRecord rec_2;
    SpritePartLayoutRecord rec_3;
    SpritePartLayoutRecord rec_4;
    SpritePartLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    LayoutEntryCopyRecord rec_7;
    LayoutEntryCopyRecord rec_8;
};

LockOnPlayerLayout lock_on_window_params = {
    2, 1,
    {6, {10.0f, 0.0f}, {34.0f, 29.0f}, 34.0f, 202.0f, 0.5f, -1, &lbl_805D63F0, 0, 4},
    {3, {44.0f, 5.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
};

LockOnItemLayout lockon_window_layout_entries = {
    2, 1,
    {8},
    {10, {10.0f, 20.0f}},
};

LockOnEnemyLayout lbl_804D00F4 = {
    9, 1,
    {3, {10.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {10.0f, 20.0f}, 0.5f, 0xFFFFFFFF, 0, NULL},
    {3, {10.0f, 20.0f}, 0.7f, 0xFFFFFFFF, 0, NULL},
    {6, {10.0f, 44.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.1f, -1, &lbl_805D63F0, 1, 6},
    {6, {26.0f, 44.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.2f, -1, &lbl_805D63F0, 1, 6},
    {6, {42.0f, 44.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.3f, -1, &lbl_805D63F0, 1, 6},
    {6, {58.0f, 44.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.4f, -1, &lbl_805D63F0, 1, 6},
    {2, {10.0f, 50.0f}, 0.5f, 0xFF00FF15, 0x2A, 100.0f, 0, 0, 0xFF00CA9E, 0xFFFF2924},
    {2, {10.0f, 62.0f}, 0.5f, 0xFF008CFC, 0x2A, 100.0f, 0, 0, 0xFF008DEE, 0xFFFF2924},
};

WindowDescriptor lbl_804D0268 = {
    {0.0f, 0.0f}, 50000.0f, NULL, 0x23,
};

// The enemy's status ailment slots and maximum HP/TP, read through the actor.
struct LockOnEnemyView {
    u8 pad_0[0x32C];
    s16 hp_max;
    s16 tp_max;
};

struct LockOnGauge {
    u8 pad_0[0x20];
    f32 cur;
    f32 max;
};

struct LockOnEntry {
    u16 flags;
    u8 pad_2[6];
    f32 y;
    u8 pad_c[4];
    f32 w;
    u8 pad_14[8];
    u8 kind;
};

struct LockOnEntryGrade {
    u16 flags;
    u8 pad_2[0xE];
    s32 grade;
};

struct LockOnEntryText {
    u8 pad_0[8];
    f32 y;
    u8 pad_c[0x14 - 0xC];
    f32 w;
    u8 pad_18[8];
    f32 cur;
    f32 max;
};

struct LockOnEntryColor {
    u8 pad_0[0x24];
    s32 color;
};

extern "C" {
u32 obj_getArrWord_254(LockOnEnemyView *, s32);
s16 obj_getS16_2BA(LockOnEnemyView *);
u16 get_entity_id(void *);
void refresh_status_display__9TWindowDDFv(void *);
void init_window_layout_entries(void *, void *, int);
f32 get_target_distance__13TWindowLockOnFv(s32);
extern s32 __vt__13TWindowLockOn[];
s32 draw_visible_window_entries(void *, void *, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(u32);
s32 get_window_layout_position(int);
s32 obj_testFlag_2E4__9TObjCharaFUl(TObjChara *, int);
s32 is_split_screen(void);
s32 get_message_10__20TWindowSubStatusDispFl(int);
s32 enemy_name_for_rt_index(int);
u32 calc_text_width(int);
}
s32 get_status_effect_icon_index(u32);

u8 *TWindowLockOn__ct(TWindowLockOn *self, s32 player, u16 id) {
    ((TWindowDD *)self)->construct_base((u8 *)&lbl_804D0268, player, (u8 *)get_window_layout_position(0x1E));
    *(s32 **)((s8 *)self + 0x18) = __vt__13TWindowLockOn;
    self->m_name = TWindowLockOn__name;
    if (TCameraCtrl::get_camera_id() > 2) {
        self->m_68 = 0.7f;
        self->m_6c = 0.7f;
    } else {
        self->m_68 = 1.0f;
        self->m_6c = 1.0f;
    }
    self->m_60 = 0xFFFF;
    self->m_20 = player;
    self->m_64 = 0;
    self->m_70 = NULL;
    self->bind_target(id);
    self->m_50 = 0;
    return (u8 *)self;
}

void *__dt__13TWindowLockOnFv(void *self, s16 flags) {
    if (self != NULL) {
        *(s32 **)((s8 *)self + 0x18) = __vt__13TWindowLockOn;
        ((TWindowDD *)self)->destroy_window_base(0);
        if (flags > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

void TWindowLockOn::run_task() {
    s32 old;
    m_5c = 0x01000000;
    if (m_70) {
        (this->*m_70)();
    }
    validate_target();
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
    update_window_entry_list(&m_24);
    old = m_64;
    m_64 = old - 1;
    if (old < 0) {
        close();
    }
}

void TWindowLockOn::render() {
    s32 context;

    context = setup_window_draw_context((s32)&m_68);
    draw_window_frame((void *)context);
    if (m_30 == m_40 && m_34 == m_44 && m_38 == m_48 && m_3c == m_4c) {
        draw_visible_window_entries(this, &m_24, context);
    }
}

void *TWindowLockOn::create_for_target(s32 player, u16 id) {
    void *p;
    if (id == 0xFFFF) {
        return NULL;
    }
    if (is_lockable_target(find_entity_by_id(id)) == 0) {
        return NULL;
    }
    p = __nw__7TObjectFUl(0x7C);
    if (p != NULL) {
        p = TWindowLockOn__ct((TWindowLockOn *)p, player, id);
    }
    return p;
}

void TWindowLockOn::bind_target(u16 id) {
    TObjCollidable *actor;

    if (id == 0xFFFF) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    actor = find_entity_by_id(id);
    if (is_lockable_target(actor) == 0) {
        return;
    }
    if (m_60 == id) {
        m_64 = 0x5A;
        return;
    }
    if ((f32)m_64 > 90.0f) {
        return;
    }
    m_60 = id;
    m_64 = 0x5A;
    update_for_target(actor);
    if (m_70) {
        (this->*m_70)();
    }
}

void TWindowLockOn::update_for_target(TObjCollidable *actor) {
    ((TWindowSubStatusDisp *)&m_24)->destroy_all_items();
    if (actor->obj_testFlags30(0x10000000) != 0) {
        update_for_other_player(actor);
        return;
    }
    if (actor->obj_testFlags30(0x80000000) != 0) {
        update_for_item((TItem *)actor);
        return;
    }
    if (actor->obj_testFlags30(0x20000000) != 0) {
        update_for_enemy((TObjChara *)actor);
    }
}

#pragma push
#pragma fp_contract on
void TWindowLockOn::update_for_other_player(TObjCollidable *player) {
    LockOnEntry *w;
    u16 id;
    init_window_layout_entries(&m_24, &lock_on_window_params, m_20);
    m_70 = &TWindowLockOn::update_photon_blast_marker;
    w = (LockOnEntry *)get_array_entry(1);
    id = get_entity_id(player);
    ((TWindowLockOn *)w)->update_for_player_index(id);
    ((TWindowHelpItem *)w)->reset_float_field();
    refresh_status_display__9TWindowDDFv(w);
    m_38 = 34.0f + w->w;
    m_3c = 49.0f;
    m_38 += 28.0f;
    m_34 = get_target_distance__13TWindowLockOnFv(0x1E) - m_3c * m_6c;
    m_50 = 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowLockOn::update_for_item(TItem *item) {
    LockOnEntry *e;
    LockOnEntry *e2;
    f32 r;
    init_window_layout_entries(&m_24, &lockon_window_layout_entries, m_20);
    m_70 = &TWindowLockOn::refresh_ground_item;
    e = (LockOnEntry *)get_array_entry(0);
    ((TWindowSubStatusDisp *)e)->init_item_row(item, 0);
    ((TWindowSubStatusDisp *)e)->calc_row_width();
    e->y = -8.0f;
    if (e->kind != 0x33) {
        e->y += 18.0f;
    }
    m_38 = e->w;
    m_3c = 38.0f;
    e2 = (LockOnEntry *)get_array_entry(1);
    if (item->get_item_type() == 0 || item->get_item_type() == 1) {
        ((LockOnEntryGrade *)e2)->grade = (u8)item->calc_display_grade();
        m_3c += 20.0f;
        e2->flags &= ~2;
        r = get_item_star_row_width((u8 *)e2);
        if (m_38 < r) {
            m_38 = r;
        }
    } else {
        e2->flags |= 2;
    }
    m_38 += 28.0f;
    m_34 = get_target_distance__13TWindowLockOnFv(0x1E) - m_3c * m_6c;
    m_50 = 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TWindowLockOn::update_for_enemy(TObjChara *enemy) {
    static const char *type_names[5] = {"Native", "A.Beast", "Machine", "Dark", "\tCG???"};
    static u32 type_colors[5] = {0xFFA5FFAA, 0xFFF5FF99, 0xFFFF958B, 0xFFE1A9FF, 0xFFFFFFFF};
    u32 width;
    s32 e;
    s32 kind;
    LockOnEntryText *p;
    u32 w2;

    init_window_layout_entries(&m_24, &lbl_804D00F4, m_20);
    m_70 = &TWindowLockOn::refresh_enemy_statuses;
    e = get_array_entry(1);
    TWindowDuelResult::set_default_status((void *)e, get_message_10__20TWindowSubStatusDispFl(0xA5));
    ((TWindowHelpItem *)e)->reset_float_field();
    width = calc_text_width(((TWindowSubComCard *)e)->get_field_20());
    e = get_array_entry(0);
    TWindowDuelResult::set_default_status((void *)e, enemy_name_for_rt_index(((TWindowLockOn *)enemy)->get_target_id()));
    ((TWindowHelpItem *)e)->reset_float_field();
    m_38 = (f32)calc_text_width(((TWindowSubComCard *)e)->get_field_20());
    m_3c = 64.0f;
    if (is_split_screen() == 0) {
        m_3c += 29.0f;
    }
    if (obj_testFlag_2E4__9TObjCharaFUl(enemy, 0x40) != 0) {
        kind = 4;
    } else if (obj_testFlag_2E4__9TObjCharaFUl(enemy, 1) != 0) {
        kind = 0;
    } else if (obj_testFlag_2E4__9TObjCharaFUl(enemy, 2) != 0) {
        kind = 1;
    } else if (obj_testFlag_2E4__9TObjCharaFUl(enemy, 4) != 0) {
        kind = 2;
    } else if (obj_testFlag_2E4__9TObjCharaFUl(enemy, 8) != 0) {
        kind = 3;
    } else {
        kind = 4;
    }
    e = get_array_entry(2);
    TWindowDuelResult::set_default_status((void *)e, (s32)type_names[kind]);
    ((TWindowHelpItem *)e)->reset_float_field();
    ((LockOnEntryText *)e)->y = 10.0f + (f32)width;
    ((LockOnEntryColor *)e)->color = type_colors[kind];
    w2 = calc_text_width(((TWindowSubComCard *)e)->get_field_20());
    w2 += width;
    if ((f32)w2 > m_38) {
        m_38 = (f32)w2;
    }
    m_38 += 28.0f;
    m_34 = get_target_distance__13TWindowLockOnFv(0x1E) - m_3c * m_6c;
    m_50 = 0;
    p = (LockOnEntryText *)get_array_entry(7);
    p->w = m_38 - 28.0f;
    p->cur = (f32)((TItemProShield *)enemy)->get_field_2b8();
    p->max = (f32)((LockOnEnemyView *)enemy)->hp_max;
    p = (LockOnEntryText *)get_array_entry(8);
    p->w = m_38 - 28.0f;
    p->cur = (f32)obj_getS16_2BA((LockOnEnemyView *)enemy);
    p->max = (f32)((LockOnEnemyView *)enemy)->tp_max;
}
#pragma pop

void TWindowLockOn::update_photon_blast_marker() {
    update_photon_blast_player_marker(get_array_entry(0), m_60);
}

void TWindowLockOn::refresh_ground_item() {}

void TWindowLockOn::refresh_enemy_statuses() {
    s32 i;
    LockOnEnemyView *enemy;
    s32 mode;
    LockOnGauge *g;
    if (m_60 == 0xFFFF) {
        return;
    }
    enemy = (LockOnEnemyView *)find_entity_by_id(m_60);
    if (enemy == NULL) {
        return;
    }
    i = 0;
    do {
        mode = get_status_effect_icon_index(obj_getArrWord_254(enemy, i));
        ((TWindowComCard *)get_array_entry(i + 3))->set_help_mode(mode);
        i++;
    } while (i < 4);
    {
        g = (LockOnGauge *)get_array_entry(7);
        g->cur = ((TItemProShield *)enemy)->get_field_2b8();
        g->max = enemy->hp_max;
        ((TWindowHelpItem *)g)->set_flag0_bit2();
    }
    {
        g = (LockOnGauge *)get_array_entry(8);
        g->cur = obj_getS16_2BA(enemy);
        g->max = enemy->tp_max;
        ((TWindowHelpItem *)g)->set_flag0_bit2();
    }
}

s32 TWindowLockOn::is_lockable_target(TObjCollidable *actor) {
    if (actor == NULL) {
        return 0;
    }
    if (actor->obj_testFlags30(0x10000000) != 0) {
        if (((TObjChara *)actor)->obj_isState3_324() != 0 || ((TObjPlayer *)actor)->is_script_controlled() != 0) {
            return 0;
        }
        return 1;
    }
    if (actor->obj_testFlags30(0x20000000) != 0) {
        if (actor->obj_testFlags30(0x40000000) != 0) {
            return 0;
        }
        if (((TWindowLockOn *)actor)->get_target_id() != 0) {
            return 1;
        }
        return 0;
    }
    if (actor->obj_testFlags30(0x80000000) != 0) {
        return 1;
    }
    return 0;
}

void TWindowLockOn::validate_target() {
    u16 id;
    TObjCollidable *target;
    id = m_60;
    if (id != 0xFFFF) {
        target = find_entity_by_id(id);
        if (target == NULL || target->all_parents_unqueued_for_destruction() == 0) {
            m_60 = 0xFFFF;
            if ((f32)m_64 > 15.0f) {
                m_64 = 0xF;
            }
        } else if (target->obj_testFlags30(0x10000000) == 0) {
            if (target->obj_testFlags30(0x20000000) != 0) {
                if (((TObjChara *)target)->has_flag_0x800() != 0) {
                    m_60 = 0xFFFF;
                    if ((f32)m_64 > 15.0f) {
                        m_64 = 0xF;
                    }
                }
            } else if (target->obj_testFlags30(0x80000000) != 0 && ((TItem *)target)->get_mode() != 0) {
                m_60 = 0xFFFF;
                if ((f32)m_64 > 15.0f) {
                    m_64 = 0xF;
                }
            }
        }
    }
}
