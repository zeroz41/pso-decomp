#ifndef PSO_ITEM_TITEM_H
#define PSO_ITEM_TITEM_H

#include "types.h"
#include <stddef.h>
#include "pso/object/TObjMotion.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/FlagWord.h"

struct TItemData;
struct TObjPlayer;
struct G_PickUpItem_6x59;

// TItem::item_flags bits.
enum {
    ITEM_FLAG_EQUIPPABLE = 0x4,
    ITEM_FLAG_EQUIPPED = 0x8,
    ITEM_FLAG_CONSUMABLE = 0x10,
    ITEM_FLAG_HIDDEN = 0x40,         // the owner is not drawn, so neither is the item
    ITEM_FLAG_AT_TEKKER = 0x80,      // handed to the tekker for judging
    ITEM_FLAG_KILL_COUNTER = 0x100,  // kill_count counts kills (sealed weapons)
    ITEM_FLAG_UNSEALED = 0x200,      // the kill count reached its target
    ITEM_FLAG_WRAPPED = 0x400,       // shown as a present box until unwrapped
};

// item_render_state bits: what the item model draw switched on.
enum {
    ITEM_RENDER_MATERIAL = 0x1,       // the material colour was overridden
    ITEM_RENDER_EFFECT = 0x2,         // TParticleCtrl::begin_effect_render ran
    ITEM_RENDER_PARTICLE_TEV = 0x8,
    ITEM_RENDER_SHIELD_TEV = 0x10,
};

// TItem::mode values.
enum {
    ITEM_MODE_GROUND = 0,
    ITEM_MODE_OWNED = 1,     // in an inventory
    ITEM_MODE_EQUIPPED = 2,  // carried and drawn with its owner
    ITEM_MODE_INACTIVE = 3,
};

// Ground models; 6 and 7 are the present boxes, wrapped items use 6.
#define ITEM_MODEL_COUNT 11

// The base of every item object: an entry in the id-sorted item registry,
// drawn on the floor, in an inventory or with its owner.
struct TItem : public TUnk_804AF8A0 {
    TItem(TObject *parent, u8 *item);
    virtual ~TItem();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    virtual s32 update_object_view_visibility(f32 depth, f32 radius);
    virtual int vfunc_12();
    // The player interacting with the item: try to pick it up.
    virtual void vfunc_13(s32 client);
    virtual void update_owned();
    virtual void update_in_inventory();
    virtual void update_equipped();
    virtual void activate_effect(s32 effect);
    virtual void write_item_data(TItemData *data);
    virtual void set_attach_slot(s8 slot);
    virtual void equip();
    virtual void unequip();
    virtual void add_equip_stats(s32 apply);
    virtual void remove_equip_stats(s32 apply);
    virtual void subtract_item_stat_bonus(s32 player, s32 unused, s16 *stats);
    virtual void subtract_equip_stats(void *atp, s16 *stats, s16 *stats2);
    virtual void render_equipped();
    virtual void render_equipped_shadow();
    virtual void render_equipped_deferred();
    virtual void destroy();
    virtual void vfunc_30();
    virtual void use();
    virtual u32 get_attack_flags();
    virtual s8 get_attach_slot();
    virtual void vfunc_34();
    virtual s32 is_identified();
    virtual s32 get_amount();
    virtual s32 remove_amount(s32 count);
    virtual s32 add_amount(s32 count);
    virtual u8 get_slot_count();
    virtual void add_slot();
    virtual s32 feed(TItemData *food);
    virtual void vfunc_42();
    virtual u8 get_motion_type();

    static void *operator new(size_t size);
    static void operator delete(void *p);

    s32 is_wrapped();
    void unwrap();
    void use_combination_recipe();
    void assign_item_id();
    void apply_item_flags(TItemData *data);
    void render_ground();
    void render_owned();
    void render_following_owner();
    void render_present_box();
    void render_model();
    void set_drop_model(u8 model);
    u16 get_kill_count();
    void set_kill_count(u16 count);
    void notify_owner(s32 sound);
    void apply_switch_attack(s32 effect);
    void set_owner_technique_level(s16 technique, s16 level);
    s32 has_no_defer_render();
    s32 is_model_shown();
    void sub_80100D68();
    void set_item_index(u8 index);
    void set_item_group(u8 group);
    void get_icon_index();
    void refresh_if_current_player();
    f32 get_owner_alpha();
    void update_owner_visibility();
    // Switch the item_render_state settings on once per draw and off again.
    static void begin_constant_material_color(s32 color);
    static void begin_offset_material_color(s32 color);
    static void end_material_color();
    static void begin_effect_render();
    static void end_effect_render();
    void begin_particle_tev();
    void end_particle_tev();
    void end_shield_tev();
    void send_activate_effect(s32 effect);
    void has_bonus_stats();
    void is_custom_srank();
    void is_rare();
    void get_sell_price();
    u32 get_usable_action_flags(u32 mask, u32 player);
    void unregister_from_world();
    void register_in_world(s32 clear_status);
    void set_mode(s8 new_mode);
    void calc_display_grade();
    void check_equip_requirements(TObjPlayer *player, s16 *result);
    void draw_model();
    void draw_model_nodes(u8 *matrices);
    void apply_sign_effect(u8 *matrices);
    void visit_model_nodes(u8 *matrices);
    void get_max_stack();
    void set_owner_client(u16 client);
    s32 unregister_item();
    s32 insert_sorted_by_id();
    s32 copy_to_item_data(TItemData *data);
    void snap_to_ground();
    void send_field_state(s16 floor, TObjPlayer *player);
    void handle_pickup(s16 floor, TObjPlayer *player);
    void update_timer();
    void place_on_ground(s16 floor, f32 *pos, s32 quiet);
    u32 test_item_flags(u32 mask);
    void clear_item_flags(u32 mask);
    void add_item_flags(u32 mask);
    int is_at_tekker();
    s8 get_mode();
    u16 get_owner_client();
    u8 get_item_type();
    int is_hidden();
    void hide();
    void show();
    s32 get_item_id();
    s32 get_item_flags();
    u8 get_item_group();
    u8 get_item_index();
    static void push_equipped_id(s32 id);

    CollisionBody collision_body;  // the pick-up sphere (item_collider_body)
    u32 item_id;
    u32 item_flags;                // ITEM_FLAG_*
    void (*model_node_callback)(NJS_OBJECT *object);  // visit callback for draw_model_nodes
    u16 owner_client_id;           // 0xFFFF: nobody's
    s16 pickup_wait_frames;        // frames a pick-up request has been pending
    u16 kill_count;                // ITEM_FLAG_KILL_COUNTER items
    char box_color;                // present/drop box colour (item_box_*_colors)
    u8 mode;                       // ITEM_MODE_*
    u8 item_type;                  // the item code bytes data1[0..2]
    u8 item_group;
    u8 item_index;
    u8 drop_model;                 // ground model, < ITEM_MODEL_COUNT
    TObjPlayer *owner;             // the player carrying it
    NJS_OBJECT *item_model;        // the object tree drawn for it
};

typedef char TItemCollisionOffset[(offsetof(TItem, collision_body) == 0xAC) ? 1 : -1];
typedef char TItemIdOffset[(offsetof(TItem, item_id) == 0xD8) ? 1 : -1];
typedef char TItemModeOffset[(offsetof(TItem, mode) == 0xEB) ? 1 : -1];
typedef char TItemModelOffset[(offsetof(TItem, drop_model) == 0xEF) ? 1 : -1];
typedef char TItemSize[(sizeof(TItem) == 0xF8) ? 1 : -1];

extern NJS_ARGB item_box_primary_colors[6];
extern NJS_ARGB item_box_secondary_colors[6];

// The item registry: every live item, sorted by id.
extern int item_registry_count;
extern TItem **item_registry_sorted_entries;

extern FlagWord item_render_state;
extern u32 player_rock_objects_handle;

// Bumped each time the item system is set up for a game.
extern int item_system_generation;

// draw_model_node_tree's callbacks; when model_node_matrix_output_cursor
// is set each node's matrix is stored there.
extern void (*model_node_draw_callback)(s32 model);
extern void (*model_node_visit_callback)(NJS_OBJECT *object);
extern u8 *model_node_matrix_output_cursor;
extern s32 model_node_counter;

extern "C" {
// TItem's constructor and destructor under their own symbols, for the
// derived classes still written as C functions.
void *__ct__5TItemFP7TObjectPUc(void *item, void *parent, void *data);
void *__dt__5TItemFv(void *item, s16 deleting);
void TItem__sub_801031C0(void *tag);
// Empty in this build; the debug build checked the data passed.
void TItem__sub_80101CEC(void *data);
void TItem__sub_80101CF0(void *data);
void TItem__sub_80101CF4(void *data);
void TItem__sub_80101CF8(void *data);
void TItem__sub_80101DB8(void *data);
int TObjPlayer__sub_80100F34(void *unused);
}

TItem *find_item_by_id(s32 id);
s32 consume_item_by_id(s32 id);
s32 is_item_stackable(s32 type, s32 kind);
void handle_6x59_pick_up_item(G_PickUpItem_6x59 *cmd);
TItem *find_equipped_item(s32 id);
void scroll_item_model_uvs(NJS_OBJECT *object, s16 du, s16 dv, u16 mesh);
s32 feed_item_to_mag(TItem *mag, TItem *item);
void give_item_to_client(u16 client, TItemData *data);
void replace_item_with_new_code(const TItemData *data, TItem *item);
s32 is_point_on_screen(const f32 *pos, f32 range, f32 radius);
s32 is_default_camera();
s16 calc_stat_bonus_sum(u16 client);
s16 calc_equip_bonus(u16 client);
void handle_6x61_activate_item_effect(struct G_ActivateMagEffect_6x61 *cmd);
void draw_model_node_tree(NJS_OBJECT *object);
void draw_node_tree_with_callback(NJS_OBJECT *object, void (*visit)(NJS_OBJECT *));
TItem *get_sorted_item_registry_entry(int index);
int get_item_registry_count();
void handle_6x5E_buy_shop_item(struct G_BuyShopItem_6x5E *cmd);
void send_buy_shop_item(TItemData *data, u16 client);
void buy_item_for_client(TItemData *data, u16 client);
void handle_6x5D_drop_stacked_item(struct G_DropStackedItem_PC_V3_BB_6x5D *cmd);
void send_drop_stacked_item(TItemData *data, u16 client, f32 *pos);
void drop_stacked_item(TItemData *data, u16 client, f32 *pos);
int get_item_system_generation();
void advance_item_system_generation();
TItem *create_item(TItemData *data);
void free_item_system();
void init_item_system();

#endif
