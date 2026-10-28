#include "pso/protocol/protocol_types.h"
#include "pso/system/NinjaTypes.h"
// TItem, the base of every item object, with the item registry, the item
// packets (6x59/5A/5D/5E/61) and the item system's set-up. The data is
// emitted before the vtable; the static initializer is followed by this
// file's copies of header inlines.
#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/item/TItem.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemData_80104D0C.h"
#include "pso/item/TItemDisconnectCtrl.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItemIdCounters.h"
#include "pso/item/TItemMag.h"
#include "pso/item/TItemObject.h"
#include "pso/item/TItemProShield.h"
#include "pso/items/TItemWeapon.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TLobby_801F3A24.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TOTrapAncient02.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TShopEquipmentSellWindow.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/protocol/subcmd_6x.h"
#include "pso/render/model_render_state.h"
#include "pso/system/byteswap.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/GinjaUvScroll.h"
#include "pso/THeap.h"
#include "pso/TItemLoad.h"
#include "pso/TParticleCtrl.h"
#include "pso/unk/text_80104F4C.h"
#include "pso/unk/text_8011A780.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_801036CC.h"
#include "pso/unk/text_801057A8.h"
#include "pso/unk/text_801D98F8.h"
#include "pso/unk/text_80104FCC.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/FlagWord.h"
#include "pso/menu/TAdRicoRing_8001BEE8.h"
#include "pso/boss/TBoss1DragonColli.h"
#include "pso/item/TItemAttacker.h"
#include "pso/item/TItemProArmor.h"
#include "pso/item/TItemProUnit.h"
#include "pso/map/CsnQuery.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/vector.h"
#include "pso/TMainTask.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8007EB94.h"
#include <dolphin/base/PPCArch.h>
#include <stdlib.h>
#include <string.h>
#include "pso/map/CurrentArea.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_80141D1C.h"
#include "pso/player/TObjPlayer_80104860.h"
#include "pso/misc/TParticleCtrl_80327D30.h"
#include "pso/misc/TLobby_80207644.h"

// The two colours of the present box, by wrapping colour (box_color).
NJS_ARGB item_box_primary_colors[6] = {
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 0.0f},
    {1.0f, 0.298039228f, 0.298039228f, 0.298039228f},
    {1.0f, 0.0f, 0.698039234f, 1.0f},
    {1.0f, 1.0f, 0.400000006f, 0.800000012f},
    {1.0f, 1.0f, 0.0f, 0.0f},
};
NJS_ARGB item_box_secondary_colors[6] = {
    {1.0f, 1.0f, 0.0f, 0.400000006f},
    {1.0f, 0.0f, 0.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 0.0f},
    {1.0f, 0.90196079f, 0.298039228f, 0.0f},
    {1.0f, 0.0f, 1.0f, 0.0f},
    {1.0f, 0.0f, 1.0f, 0.0f},
};

// Counts the model nodes drawn this frame.
s32 model_node_counter;
// What the item model draw has switched on and must undo (ITEM_RENDER_*).
// Its constructor runs from __sinit_TItem_cpp, spelled out below because the
// original's static initializer precedes this file's inline copies.
#pragma push
#pragma suppress_init_code on
FlagWord item_render_state;
#pragma pop
int item_registry_count;
TItem **item_registry_sorted_entries;
void (*model_node_draw_callback)(s32 model);
void (*model_node_visit_callback)(NJS_OBJECT *object);
TItemIdCounters *item_id_counters;
u8 *model_node_matrix_output_cursor;

const char *TItem__name = "TItem";

const CollisionBody item_collider_body = {{0.0f, 0.0f, 0.0f}, 3.0f, 0.0f, 0, 0x31F0B};

// The ground model of each item type (weapon, armor, mag, tool, meseta).
const u8 item_type_drop_models[5] = {0, 1, 1, 2, 3};

int item_system_generation;


void __sinit_TItem_cpp();
__declspec(section ".ctors") static void *const item_global_initializer = (void *)__sinit_TItem_cpp;

void CursorAction::set_pick_up() { kind = CURSOR_ACTION_PICK_UP; }


s32 TUnk_804AF8A0::has_interactor() { return interactor != 0xFFFF; }

void FloorItem::clear() {
    source_type = 0;
    floor = -1;
    entity_index = -1;
    pos.x = 0.0f;
    pos.z = 0.0f;
    room_id = -1;
    drop_number = 0;
    item.init();
}

FloorItem::FloorItem() { clear(); }

void TUnk_804B9870::set_entity_id(u16 id) { entity_id = id; }

G_PickUpItemRequest_6x5A::G_PickUpItemRequest_6x5A() {
    item_id = -1;
    floor = 0;
    unused = 0;
    header.subcommand = 0x5A;
    header.size = 3;
}

void G_PickUpItemRequest_6x5A::bswap() {
    header.bswap();
    bswap_32(&item_id);
    bswap_16((u16 *)&floor);
    bswap_16(&unused);
}

void G_PickUpItemRequest_6x5A::send() {
    bswap();
    send_subcommand_to_leader(this);
}

G_PickUpItem_6x59::G_PickUpItem_6x59() {
    client_id2 = 0xFFFF;
    floor = 0;
    item_id = -1;
    header.subcommand = 0x59;
    header.size = 3;
}

void G_PickUpItem_6x59::send() {
    bswap();
    send_subcommand((u8 *)this);
}

void G_PickUpItem_6x59::bswap() {
    header.bswap();
    bswap_16((u16 *)&client_id2);
    bswap_16((u16 *)&floor);
    bswap_32(&item_id);
}

G_DropStackedItem_DC_6x5D::G_DropStackedItem_DC_6x5D() {
    floor = 0;
    room_id = 0;
    pos.z = 0.0f;
    pos.x = 0.0f;
    header.subcommand = 0x5D;
    header.size = 9;
}

G_DropStackedItem_PC_V3_BB_6x5D::G_DropStackedItem_PC_V3_BB_6x5D() {
    item_version = 2;
    unused3[0] = 0;
    unused3[1] = 0;
    unused3[2] = 0;
    header.size = 10;
}

void G_DropStackedItem_PC_V3_BB_6x5D::send() {
    bswap();
    send_subcommand((u8 *)this);
}

void G_DropStackedItem_PC_V3_BB_6x5D::bswap() {
    header.bswap();
    bswap_16((u16 *)&floor);
    bswap_16((u16 *)&room_id);
    pos.bswap();
    item_data.bswap();
}

G_BuyShopItem_6x5E::G_BuyShopItem_6x5E() {
    header.subcommand = 0x5E;
    header.size = 6;
}

void TItemData::copy_from(TItemData *src) {
    data1.data_u8[0] = src->data1.data_u8[0];
    data1.data_u8[1] = src->data1.data_u8[1];
    data1.data_u8[2] = src->data1.data_u8[2];
    data1.data_u8[3] = src->data1.data_u8[3];
    data1.data_u8[4] = src->data1.data_u8[4];
    data1.data_u8[5] = src->data1.data_u8[5];
    *(u32 *)&data1.data_u8[6] = *(u32 *)&src->data1.data_u8[6];
    data1.data_u16[5] = src->data1.data_u16[5];
    id = src->id;
    data2.data_u32 = src->data2.data_u32;
}

void G_BuyShopItem_6x5E::send() {
    bswap();
    send_subcommand((u8 *)this);
}

void G_BuyShopItem_6x5E::bswap() {
    header.bswap();
    item_data.bswap();
}

s32 G_ClientIDHeader::is_local(u16 client) {
    return dispatching_own_subcommand == 0 && client == local_client_id;
}

s32 G_ClientIDHeader::is_remote() { return !is_local(client_id); }

G_ActivateMagEffect_6x61::G_ActivateMagEffect_6x61() {
    mag_item_id = -1;
    header.subcommand = 0x61;
    effect_number = 0;
    header.size = 3;
}

void G_ActivateMagEffect_6x61::bswap() {
    ((G_ClientIDHeader *)&header)->bswap();
    bswap_32(&mag_item_id);
    bswap_32(&effect_number);
}

void G_ActivateMagEffect_6x61::send() {
    bswap();
    send_subcommand((u8 *)this);
}

void VectorXZF::bswap() {
    bswap_32((u32 *)&x);
    bswap_32((u32 *)&z);
}

f32 RenderMaterialState::get_alpha() { return alpha; }

s32 TObjPlayer::is_flag_20000_set() { return check_flag(0x20000); }

TItem *TObjPlayer::get_equipped_item(s32 slot) { return (TItem *)get_slot_value(equipped_items, slot); }

s32 TObjPlayer::get_hp_bonus() { return hp_bonus; }

s32 TObjPlayer::get_tp_bonus() { return tp_bonus; }

void TObjPlayer::set_tp(s16 value) { tp = value; }

void TItem::show() { item_flags &= ~ITEM_FLAG_HIDDEN; }

void TItem::hide() { item_flags |= ITEM_FLAG_HIDDEN; }

int TItem::is_hidden() { return item_flags & ITEM_FLAG_HIDDEN; }

u8 TItem::get_item_type() { return item_type; }

u16 TItem::get_owner_client() { return owner_client_id; }

s8 TItem::get_mode() { return mode; }

int TItem::is_at_tekker() { return test_item_flags(0x80); }

void TItem::add_item_flags(u32 mask) { item_flags |= mask; }

void TItem::clear_item_flags(u32 mask) { item_flags &= ~mask; }

u32 TItem::test_item_flags(u32 mask) { return item_flags & mask; }

u8 TItem::get_motion_type() { return 0; }

// The copies of header inlines this file emits, in the original's order.
s8 TItem::get_attach_slot() { return 0; }

void __sinit_TItem_cpp() {
    __ct__8FlagWordFv(&item_render_state);
}

void init_item_system() {
    item_registry_count = 0;
    item_registry_sorted_entries = (TItem **)mem_alloc(0x1000);
    memset(item_registry_sorted_entries, 0, 0x1000);
    item_id_counters = new TItemIdCounters;
    TObjPlayer::alloc_and_init_object_b4();
    TObjPlayer::alloc_and_run_object();
    TObjPlayer::init_game_resources();
    advance_item_system_generation();
}

void free_item_system() {
    TObjPlayer::free_item_globals();
    TObjPlayer::free_static_buffer();
    TObjPlayer::free_global_805D6FB8();
    if (item_id_counters != NULL) {
        delete item_id_counters;
        item_id_counters = NULL;
    }
    if (item_registry_sorted_entries != NULL) {
        mem_free(item_registry_sorted_entries);
        item_registry_sorted_entries = NULL;
    }
    item_registry_count = 0;
}

TItem *create_item(TItemData *data) { return construct_item(data); }

void advance_item_system_generation() { item_system_generation++; }

int get_item_system_generation() { return item_system_generation; }

void *TItem::operator new(size_t size) { return obj_heap->heap_alloc(size); }

void TItem::operator delete(void *p) { obj_heap->heap_free(p); }

TItem::TItem(TObject *parent, u8 *item) : TUnk_804AF8A0(parent) {
    m_name = TItem__name;
    obj_setFlags30(this, 0x80000000);
    copy_collision_body(&collision_body, &item_collider_body);
    cursor_action.set_pick_up();
    initialize_linked_object_reference(&collision_body);
    owner_client_id = 0xFFFF;
    item_id = ((TItemData *)item)->id;
    item_flags = 0;
    pickup_wait_frames = 0;
    model_node_callback = 0;
    item_type = item[0];
    item_group = item[1];
    item_index = item[2];
    owner = NULL;
    item_model = NULL;
    kill_count = 0;
    apply_item_flags((TItemData *)item);
    box_color = ((TItemData *)item)->get_type_nibble();
    if (TItemData::is_rare_item(item) != 0) {
        set_drop_model(4);
    } else {
        set_drop_model(item_type_drop_models[clamp_s32(get_item_type(), 0, 4)]);
    }
    if (item_object_set_data != NULL) {
        apply_object_set_data(item_object_set_data);
        set_entity_id(0xFFFF);
        set_mode(ITEM_MODE_GROUND);
    } else {
        set_mode(ITEM_MODE_INACTIVE);
    }
    assign_item_id();
    insert_sorted_by_id();
}

TItem::~TItem() {
    set_mode(ITEM_MODE_INACTIVE);
    clear_obj_links();
    unregister_item();
}

#pragma push
#pragma fp_contract on
void TItem::run_task() {
    switch (get_mode()) {
    case ITEM_MODE_GROUND:
        update_timer();
        return;
    case ITEM_MODE_OWNED:
        owner = get_player_by_client_id(get_owner_client());
        if (owner != NULL) {
            update_owner_visibility();
            update_owned();
            update_in_inventory();
        }
        break;
    case ITEM_MODE_EQUIPPED:
        owner = get_player_by_client_id(get_owner_client());
        if (owner != NULL) {
            VecCopy(&position, &owner->position);
            update_owner_visibility();
            update_owned();
            update_equipped();
            push_equipped_id(get_item_id());
        }
        break;
    }
}
#pragma pop

void TItem::render() {
    if (all_parents_unqueued_for_destruction() != 0) {
        static void (TItem::*by_mode[4])() = {
            &TItem::render_ground,
            &TItem::render_owned,
            &TItem::render_following_owner,
            NULL,
        };
        void (TItem::*draw)() = by_mode[get_mode()];
        if (draw) {
            (this->*draw)();
        }
    }
}

void TItem::render_shadows() {
    if (all_parents_unqueued_for_destruction() != 0) {
        set_shadow_flag();
        if (get_mode() == ITEM_MODE_EQUIPPED && are_items_enabled_here() != 0) {
            set_depth_buffer_settings_id(1);
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            copy_argb(&saved_model_draw_color, &model_material_color);
            render_equipped_shadow();
            copy_argb(&model_material_color, &saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
            set_default_alpha_blend();
            restore_draw_list_mask();
        }
        clear_shadow_flag();
    }
}

// Puts the item on the floor at `pos`, facing a random direction; `quiet`
// skips adding it to the floor item list.
void TItem::place_on_ground(s16 floor, f32 *pos, s32 quiet) {
    TItemData data;
    set_parent((TObject *)tl_05);
    set_mode(ITEM_MODE_GROUND);
    VecCopy(&position, (const Vec *)pos);
    owner_client_id = 0xFFFF;
    if (quiet == 0) {
        copy_to_item_data(&data);
        add_item_condition(floor, position.x, position.z, room, (u8 *)&data);
    }
    if (is_local_player_off_current_floor() == 1 || floor != get_current_floor()) {
        destroy();
        return;
    }
    rotation_x = 0;
    rotation_z = 0;
    rotation_y = (s32)(65536.0f * ((1.0f / 32768.0f) * (f32)rand()));
    snap_to_ground();
    refresh_collision_body_centers();
    if (item_ground_placement_enabled != 0) {
        spawn_particle_effect(&position, 0x9B);
    }
}

void TItem::update_owned() {}

void TItem::update_timer() {
    rotation_y += 0x200;
    if (has_interactor() != 0) {
        s16 timer = pickup_wait_frames;
        if (timer == 900) {
            interactor = 0xFFFF;
            pickup_wait_frames = 0;
        } else {
            pickup_wait_frames = timer + 1;
        }
    }
    submit_cursor_candidate(this, -1);
}

void TItem::interact(s32 client) {
    u16 id = client;
    if (id != 0xFFFF) {
        if ((get_player_by_client_id(id))->can_pickup_item_by_id(this) != 0 && has_interactor() == 0) {
            TUnk_804AF8A0::interact(client);
            G_PickUpItemRequest_6x5A cmd;
            cmd.header.client_id = client;
            cmd.item_id = get_item_id();
            cmd.floor = get_current_floor();
            cmd.send();
            pickup_wait_frames = 0;
        }
    } else {
        TUnk_804AF8A0::interact(0xFFFF);
    }
}

void handle_6x59_pick_up_item(G_PickUpItem_6x59 *cmd) {
    cmd->bswap();
    const s16 floor = cmd->floor;
    TObjPlayer *player = get_player_by_client_id(cmd->client_id2);
    if (player != NULL) {
        TItem *item = find_item_by_id(cmd->item_id);
        if (item != NULL) {
            item->interactor = 0xFFFF;
            if (item->get_item_type() == 4) {
                item->handle_pickup(floor, player);
                item->send_field_state(floor, player);
            } else if (player->can_pickup_item_by_id(item) == 1) {
                item->handle_pickup(floor, player);
                item->send_field_state(floor, player);
            }
        } else {
            FloorItemEntry *entry = TLobby::find_item_condition_entry(floor, cmd->item_id);
            if (entry != NULL) {
                TItemData *data = &entry->data;
                if (data->data1.data_u8[0] == 4) {
                    TItem *created = create_item(data);
                    if (created != NULL) {
                        created->handle_pickup(floor, player);
                    }
                } else if (player->can_pickup_item(data) == 1) {
                    TItem *created = create_item(data);
                    if (created != NULL) {
                        created->handle_pickup(floor, player);
                    }
                }
            } else {
                item_desync_detected = 1;
            }
        }
    }
}

void TItem::handle_pickup(s16 floor, TObjPlayer *player) {
    remove_item_condition_at(floor, get_item_id());
    if (player != NULL && player->pickup_item(this) != 0) {
        set_mode(ITEM_MODE_OWNED);
        set_flag8();
    }
}

void TItem::send_field_state(s16 floor, TObjPlayer *player) {
    if (floor == get_current_floor()) {
        spawn_particle_effect(&position, 0x9B);
        TObjPlayer::send_field_state_if_active(player, 0x52802);
    }
}

void drop_stacked_item(TItemData *data, u16 client, f32 *pos) {
    if ((s32)data->id == -1) {
        data->id = advance_item_id_counter(client);
    }
    send_drop_stacked_item(data, client, pos);
}

void send_drop_stacked_item(TItemData *data, u16 client, f32 *pos) {
    G_DropStackedItem_PC_V3_BB_6x5D cmd;
    TObjPlayer *player = get_player_by_client_id(client);
    if (player == NULL) {
        item_desync_detected = 1;
        return;
    }
    cmd.header.client_id = client;
    cmd.floor = get_current_floor();
    cmd.room_id = player->get_stat_by_key_state();
    cmd.pos.x = pos[0];
    cmd.pos.z = pos[2];
    cmd.item_data.copy_from(data);
    cmd.item_data.encode_for_network();
    cmd.send();
}

void handle_6x5D_drop_stacked_item(G_DropStackedItem_PC_V3_BB_6x5D *cmd) {
    cmd->bswap();
    if (get_floor_area(cmd->floor) != 15) {
        FloorItem drop;
        drop.floor = cmd->floor;
        drop.pos.x = cmd->pos.x;
        drop.pos.z = cmd->pos.z;
        drop.room_id = cmd->room_id;
        drop.item.copy_from(&cmd->item_data);
        if (cmd->header.size * 4 == sizeof(G_DropStackedItem_DC_6x5D)) {
            cmd->item_data.convert_from_version(0);
        } else {
            cmd->item_data.convert_from_version(2);
        }
        drop.item.decode_from_network();
        spawn_dropped_item_from_msg(&drop, 0);
    }
}

void buy_item_for_client(TItemData *data, u16 client) {
    if (TObjPlayer::is_locally_controlled(get_player_by_client_id(client)) != 0) {
        if ((s32)data->id == -1) {
            data->id = advance_item_id_counter(client);
        }
        send_buy_shop_item(data, client);
    }
}

void send_buy_shop_item(TItemData *data, u16 client) {
    G_BuyShopItem_6x5E cmd;
    cmd.header.client_id = client;
    cmd.item_data.copy_from(data);
    cmd.item_data.encode_for_network();
    cmd.send();
}

void handle_6x5E_buy_shop_item(G_BuyShopItem_6x5E *cmd) {
    cmd->bswap();
    if (cmd->header.is_remote() != 0) {
        cmd->item_data.decode_from_network();
        give_item_to_client(cmd->header.client_id, &cmd->item_data);
    }
}

// Drops the item onto the floor below it.
void TItem::snap_to_ground() {
    f32 probe[3];
    probe[0] = position.x;
    probe[1] = 300.0f + position.y;
    probe[2] = position.z;
    CsnHit *hit = (CsnHit *)csnVecterUnder((s32)probe, 0x41);
    if (hit != NULL) {
        position.y = 6.0f + hit->contact->point.y;
    }
}

void debug_print_item_param(void *) {}

void TItem::write_item_data(TItemData *) {}

s32 TItem::copy_to_item_data(TItemData *data) {
    if (data != NULL) {
        data->init();
        data->data1.data_u8[0] = item_type;
        data->data1.data_u8[1] = item_group;
        data->data1.data_u8[2] = item_index;
        data->id = item_id;
        write_item_data(data);
        if (item_flags & ITEM_FLAG_KILL_COUNTER) {
            data->set_packed_value(kill_count);
        }
        if (item_flags & ITEM_FLAG_WRAPPED) {
            data->set_wrapped();
            data->set_present_color(box_color);
        }
        return 1;
    }
    return 0;
}

void encode_uploaded_player_inventory(void *) {}

void encode_player_record_inventory(void *) {}

void decode_remote_player_inventory(void *) {}

void decode_created_player_inventory(void *) {}

s32 TItem::insert_sorted_by_id() {
    s32 id;
    s32 lo;
    s32 mid;
    s32 hi;
    id = item_id;
    hi = item_registry_count - 1;
    if (id == -1) {
        item_desync_detected = 1;
        return id;
    }
    if (hi > -1 && id < (s32)item_registry_sorted_entries[hi]->item_id) {
        lo = 0;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if ((s32)item_registry_sorted_entries[mid]->item_id < id) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        TItem **slot = &item_registry_sorted_entries[lo];
        if (id == (s32)(*slot)->item_id) {
            item_desync_detected = 1;
            return id;
        }
        memcpy(&item_registry_sorted_entries[lo + 1], slot, (item_registry_count - lo) * 4);
    } else {
        lo = item_registry_count;
    }
    item_registry_sorted_entries[lo] = this;
    item_registry_count++;
    return id;
}

s32 TItem::unregister_item() {
    s32 lo;
    s32 id;
    s32 mid;
    s32 hi;
    lo = 0;
    id = item_id;
    hi = item_registry_count - 1;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if ((s32)item_registry_sorted_entries[mid]->item_id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    TItem **slot = &item_registry_sorted_entries[lo];
    if (*slot == this) {
        memcpy(slot, &item_registry_sorted_entries[lo + 1], (item_registry_count - (lo + 1)) * 4);
        item_registry_count--;
        item_registry_sorted_entries[item_registry_count] = NULL;
        return id;
    }
    return -1;
}

TItem *find_item_by_id(s32 id) {
    s32 lo;
    s32 mid;
    s32 hi;
    lo = 0;
    hi = item_registry_count - 1;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if ((s32)item_registry_sorted_entries[mid]->item_id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    TItem *item = item_registry_sorted_entries[lo];
    if (item != NULL && (s32)item->item_id == id) {
        return item;
    }
    return NULL;
}

int get_item_registry_count() { return item_registry_count; }

TItem *get_sorted_item_registry_entry(int index) { return item_registry_sorted_entries[index]; }

s32 is_item_stackable(s32 type, s32 kind) {
    if (type == 4) {
        return 1;
    }
    if (type != 3) {
        return 0;
    }
    if (kind < 9 && kind != 2) {
        return 1;
    }
    if (kind == 0x10) {
        return 1;
    }
    return 0;
}

s32 TItem::get_max_stack_size() {
    TItemData data;
    copy_to_item_data(&data);
    return data.get_max_stack_size();
}

void TItem::check_equip_requirements(TObjPlayer *player, s16 *result) {
    TItemData data;
    s32 requirement;
    data.init();
    copy_to_item_data(&data);
    ::check_equip_requirements(player, &data, &requirement);
    if (result != NULL) {
        *result = requirement;
    }
}

void TItem::set_owner_client(u16 client) {
    owner_client_id = client;
    owner = get_player_by_client_id(client);
}

void TItem::visit_model_nodes(u8 *matrices) {
    model_node_visit_callback = model_node_callback;
    model_node_matrix_output_cursor = matrices;
    model_node_draw_callback = NULL;
    draw_model_node_tree(item_model);
    model_node_draw_callback = NULL;
    model_node_matrix_output_cursor = NULL;
    model_node_visit_callback = NULL;
    set_default_alpha_blend();
}

void TItem::apply_sign_effect(u8 *matrices) {
    model_node_visit_callback = model_node_callback;
    model_node_matrix_output_cursor = matrices;
    model_node_draw_callback = ::draw_ginja_model;
    draw_model_node_tree(item_model);
    model_node_draw_callback = NULL;
    model_node_matrix_output_cursor = NULL;
    model_node_visit_callback = NULL;
    set_default_alpha_blend();
}

void TItem::draw_model_nodes(u8 *matrices) {
    model_node_visit_callback = model_node_callback;
    model_node_matrix_output_cursor = matrices;
    model_node_draw_callback = ::draw_ginja_model;
    draw_model_node_tree(item_model);
    model_node_draw_callback = NULL;
    model_node_matrix_output_cursor = NULL;
    model_node_visit_callback = NULL;
    set_default_alpha_blend();
}

void TItem::draw_model() { draw_ginja_object(item_model); }

void draw_node_tree_with_callback(NJS_OBJECT *object, void (*visit)(NJS_OBJECT *)) {
    model_node_visit_callback = visit;
    model_node_matrix_output_cursor = NULL;
    model_node_draw_callback = ::draw_ginja_model;
    draw_model_node_tree(object);
    model_node_draw_callback = NULL;
    model_node_matrix_output_cursor = NULL;
    model_node_visit_callback = NULL;
    set_default_alpha_blend();
}

// Walks a Ninja object tree like njDrawObject, handing every node to the
// visit callback, the model of every shown node to the draw callback and,
// when set, writing each node's matrix to model_node_matrix_output_cursor.
void draw_model_node_tree(NJS_OBJECT *object) {
    do {
        u32 flags = object->evalflags;
        if ((flags & (NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL))
            == (NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL)) {
            push_matrix();
            if (model_node_matrix_output_cursor != NULL) {
                get_current_matrix(model_node_matrix_output_cursor);
                model_node_matrix_output_cursor += 0x30;
            }
            if (model_node_visit_callback != NULL) {
                model_node_visit_callback(object);
            }
            if (!(flags & NJD_EVAL_HIDE) && model_node_draw_callback != NULL) {
                model_node_draw_callback((s32)object->model);
            }
            if (!(flags & NJD_EVAL_BREAK)) {
                draw_model_node_tree(object->child);
            }
            pop_matrix();
        } else {
            push_matrix();
            if (!(flags & NJD_EVAL_UNIT_POS)) {
                post_translate_matrix(object->pos);
            }
            if (!(flags & NJD_EVAL_UNIT_ANG)) {
                rotate_matrix_by_node_angles(object->ang, flags & NJD_EVAL_ZXY_ANG);
            }
            if (!(flags & NJD_EVAL_UNIT_SCL)) {
                scale_current_matrix(object->scl);
            }
            if (model_node_visit_callback != NULL) {
                model_node_visit_callback(object);
            }
            if (model_node_matrix_output_cursor != NULL) {
                get_current_matrix(model_node_matrix_output_cursor);
                model_node_matrix_output_cursor += 0x30;
            }
            if (!(flags & NJD_EVAL_HIDE) && model_node_draw_callback != NULL) {
                model_node_draw_callback((s32)object->model);
            }
            if (!(flags & NJD_EVAL_BREAK)) {
                draw_model_node_tree(object->child);
            }
            pop_matrix();
        }
        object = object->sibling;
    } while (object != NULL);
}

int TItem::calc_display_grade() {
    TItemData data;
    copy_to_item_data(&data);
    return data.calc_display_grade();
}

const char *TItem::get_name() {
    TItemData data;
    copy_to_item_data(&data);
    char *name = (char *)get_item_chunk_buffer(0);
    data.format_item_name(name);
    return name;
}

void TItem::set_mode(s8 new_mode) {
    if (new_mode == ITEM_MODE_INACTIVE) {
        owner = NULL;
    }
    if (new_mode == ITEM_MODE_GROUND) {
        owner = NULL;
        register_in_world(0);
    } else {
        unregister_from_world();
    }
    mode = new_mode;
}

void TItem::register_in_world(s32 clear_status) {
    if (get_entity_id(this) == 0xFFFF) {
        set_entity_id(pop_free_entity_id());
        ((TObjPlayer *)this)->reset_photon_effect();
        if (clear_status != 0) {
            clear_player_status_flag(0, 1);
        }
    }
}

// Gives the object id back to the free list and drops the item out of the
// world's object table.
void TItem::unregister_from_world() {
    if (get_entity_id(this) != 0xFFFF) {
        unregister_object_by_id();
        push_free_entity_id(get_entity_id(this));
        set_entity_id(0xFFFF);
        set_indexed_flags(0, 1);
    }
}

u32 TItem::get_usable_action_flags(u32 mask, u32 player) {
    TItemData data;
    copy_to_item_data(&data);
    if (player == 0) {
        player = (u32)owner;
    }
    u32 flags = data.calc_action_flags(mask, (u8 *)player);
    if (test_item_flags(0x200) != 0) {
        flags |= 2;
    }
    if (flags == 0 && is_at_tekker() != 0) {
        flags |= 0x10;
        flags &= ~2;
    }
    return flags & mask;
}

s32 TItem::calc_price() {
    TItemData data;
    copy_to_item_data(&data);
    return ((TShopEquipmentSellWindow *)&data)->get_item_price_if_valid();
}

void TItem::destroy() {
    unregister_item();
    disallow_rendering();
    queue_destruction();
}

s32 TItem::is_rare_item() {
    TItemData data;
    copy_to_item_data(&data);
    return TItemData::is_rare_item(&data);
}

s32 TItem::is_custom_name_srank() {
    TItemData data;
    copy_to_item_data(&data);
    return TItemData::is_custom_name_srank(&data);
}

void handle_6x61_activate_item_effect(G_ActivateMagEffect_6x61 *cmd) {
    if (get_current_area() != 15) {
        cmd->bswap();
        TItem *mag = find_item_by_id(cmd->mag_item_id);
        if (mag != NULL && mag->owner != NULL) {
            mag->activate_effect(cmd->effect_number);
        }
    }
}

void TItem::send_activate_effect(s32 effect) {
    if (owner != NULL && get_current_area() != 15 && owner->obj_isState2_324() == 0) {
        G_ActivateMagEffect_6x61 cmd;
        cmd.mag_item_id = get_item_id();
        cmd.effect_number = effect;
        cmd.send();
    }
}

s16 calc_base_hp_bonus(u16 client) {
    TObjPlayer *player = get_player_by_client_id(client);
    s32 bonus = 0;
    if (player != NULL) {
        s32 slot = 9;
        do {
            TItemEquipBase *equipped = (TItemEquipBase *)player->get_equipped_item(slot);
            if (equipped != NULL) {
                bonus += *(s16 *)equipped->get_stat_bonus_ptr();
            }
            slot++;
        } while (slot != 13);
        return player->get_hp_bonus() - bonus;
    }
    return 0;
}

// The owner's stat less what the equipped armor, shield and units add.
s16 calc_base_tp_bonus(u16 client) {
    TObjPlayer *player = get_player_by_client_id(client);
    s32 bonus = 0;
    if (player != NULL) {
        s32 slot = 9;
        do {
            TItemEquipBase *equipped = (TItemEquipBase *)player->get_equipped_item(slot);
            if (equipped != NULL) {
                bonus += ((s16 *)equipped->get_stat_bonus_ptr())[1];
            }
            slot++;
        } while (slot != 13);
        return player->get_tp_bonus() - bonus;
    }
    return 0;
}

s32 TItem::has_bonus_stats() {
    TItemData data;
    copy_to_item_data(&data);
    return data.has_bonus_stats();
}

void TItem::begin_constant_material_color(const NJS_ARGB *color) {
    if (color != NULL && test_flags_any(&item_render_state.bits, ITEM_RENDER_MATERIAL) == 0) {
        model_render_flags &= ~0x20;
        model_render_flags |= 0x10;
        set_constant_material(color);
        item_render_state.set(ITEM_RENDER_MATERIAL);
    }
}

void TItem::begin_offset_material_color(const NJS_ARGB *color) {
    if (color != NULL && test_flags_any(&item_render_state.bits, ITEM_RENDER_MATERIAL) == 0) {
        model_render_flags &= ~0x10;
        model_render_flags |= 0x20;
        set_constant_material(color);
        item_render_state.set(ITEM_RENDER_MATERIAL);
    }
}

void TItem::end_material_color() {
    if (test_flags_any(&item_render_state.bits, ITEM_RENDER_MATERIAL) != 0) {
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        item_render_state.clear(ITEM_RENDER_MATERIAL);
    }
}

void TItem::begin_effect_render() {
    if (test_flags_any(&item_render_state.bits, ITEM_RENDER_EFFECT) == 0) {
        TParticleCtrl::begin_effect_render();
        item_render_state.set(ITEM_RENDER_EFFECT);
    }
}

void TItem::end_effect_render() {
    if (test_flags_any(&item_render_state.bits, ITEM_RENDER_EFFECT) != 0) {
        TParticleCtrl::end_effect_render();
        item_render_state.clear(ITEM_RENDER_EFFECT);
    }
}

void TItem::begin_particle_tev() {
    TItem::begin_effect_render();
    if (test_flags_any(&item_render_state.bits, ITEM_RENDER_PARTICLE_TEV) == 0) {
        setup_particle_tev(0);
        set_texlist(texture_id);
        item_render_state.set(ITEM_RENDER_PARTICLE_TEV);
    }
}

void TItem::end_particle_tev() {
    if (test_flags_any(&item_render_state.bits, ITEM_RENDER_PARTICLE_TEV) != 0) {
        TParticleCtrl::disable_if_single_screen();
        set_texlist(texture_id);
        item_render_state.clear(ITEM_RENDER_PARTICLE_TEV);
    }
}

void TItem::request_particle_indirect_effect() { request_indirect_effect(31); }

void TItem::end_shield_tev() {
    if (test_flags_any(&item_render_state.bits, ITEM_RENDER_SHIELD_TEV) != 0) {
        TParticleCtrl::disable_if_single_screen();
        TParticleCtrl::set_tev_direct(1);
        set_texlist(texture_id);
        item_render_state.clear(ITEM_RENDER_SHIELD_TEV);
    }
}

void TItem::load_projection_tex(s32 rotation_y) {
    load_projection_tex_matrix(rotation_y);
}

// Hides the item while its owner is hidden or out of the local view.
void TItem::update_owner_visibility() {
    if (owner != NULL) {
        if (owner->is_body_collision_inactive() == 0 && are_items_enabled_here() == 1
            && owner->is_flag_20000_set() == 0) {
            show();
            return;
        }
        hide();
        return;
    }
    hide();
}

f32 TItem::get_owner_alpha() {
    TObjPlayer *player = owner;
    if (player != NULL) {
        return player->render_material_state.get_alpha();
    }
    return 1.0f;
}

void TItem::refresh_if_current_player() {
    if ((s32)owner_client_id == local_client_id) {
        TLobby::mark_selected();
    }
}

s32 TItem::get_icon_index() {
    TItemData data;
    copy_to_item_data(&data);
    return TLobby::get_item_data((u32)&data);
}

void TItem::set_item_group(u8 value) { item_group = value; }

void TItem::set_item_index(u8 value) { item_index = value; }

s32 TItem::get_name_style() {
    TItemData data;
    copy_to_item_data(&data);
    return data.get_name_style();
}

s32 TItem::is_model_shown() {
    if (is_hidden() == 0 && item_model != 0) {
        return 1;
    }
    return 0;
}

s32 TItem::has_no_defer_render() { return m_flags & NO_DEFER_RENDER; }

s32 is_default_camera() {
    return get_main_phase() != 14 || TCameraCtrl::get_camera_no() == 0;
}

// Sets one of the owner's technique levels, taking the stats of the
// equipped armor, shield and units off and back on around the change.
void TItem::set_owner_technique_level(s16 technique, s16 level) {
    if (technique >= 0 && technique < 19 && level >= 0 && level <= 29) {
        TObjPlayer *owner = get_player_by_client_id(get_owner_client());
        if (owner != NULL) {
            s16 hp = get_actor_hp(owner);
            s16 tp = get_actor_tp(owner);
            s32 slot;
            for (slot = 9; slot != 13; slot++) {
                TItem *equipped = owner->get_equipped_item(slot);
                if (equipped != NULL) {
                    equipped->remove_equip_stats(1);
                }
            }
            set_technique_level_entry(owner->technique_levels, technique, (u8)level);
            for (slot = 9; slot != 13; slot++) {
                TItem *equipped = owner->get_equipped_item(slot);
                if (equipped != NULL) {
                    equipped->add_equip_stats(1);
                }
            }
            owner->set_hp_clamped(hp);
            owner->set_tp(tp);
        }
    }
}

s32 TItem::update_object_view_visibility(f32 depth, f32 radius) {
    return is_point_on_screen(&position.x, depth, radius);
}

// Whether a sphere of `radius` around `pos` is in front of the camera,
// within `range` and inside the 640-pixel-wide screen.
#pragma push
#pragma fp_contract on
s32 is_point_on_screen(const f32 *pos, f32 range, f32 radius) {
    Vec view;
    f32 screen[2];
    transform_point_by_current_matrix(pos, &view);
    if (view.z > 0.0f) {
        return 0;
    }
    if (view.z < -range) {
        return 0;
    }
    if (view.x < 0.0f) {
        view.x = camera_right[0] * radius + pos[0];
        view.y = camera_right[1] * radius + pos[1];
        view.z = camera_right[2] * radius + pos[2];
        project_world_to_screen(0, &view, screen);
        if (screen[0] < 0.0f) {
            return 0;
        }
    } else {
        view.x = pos[0] - camera_right[0] * radius;
        view.y = pos[1] - camera_right[1] * radius;
        view.z = pos[2] - camera_right[2] * radius;
        project_world_to_screen(0, &view, screen);
        if (screen[0] > 640.0f) {
            return 0;
        }
    }
    return 1;
}
#pragma pop

// Gives the owner of `item` a new item with the code in `data`, carrying
// over what the old item's class keeps (grinds, slots, bonuses, mag stats).
void replace_item_with_new_code(const TItemData *data, TItem *item) {
    TItemData replacement;
    replacement.init();
    replacement.data1.data_u8[0] = data->data1.data_u8[0];
    replacement.data1.data_u8[1] = data->data1.data_u8[1];
    replacement.data1.data_u8[2] = data->data1.data_u8[2];
    if (item != NULL) {
        switch (item->get_item_type()) {
        case 0:
            TItemWeapon::carry_over_stats(&replacement, item);
            break;
        case 1:
            switch (item->get_item_group()) {
            case 1:
                TItemProArmor::carry_over_stats(&replacement, item);
                break;
            case 2:
                TItemProShield::carry_over_stats(&replacement, item);
                break;
            case 3:
                TItemProUnit::carry_over_stats(&replacement, item);
                break;
            }
            break;
        case 2:
            TItemMag::carry_over_stats(&replacement, item);
            break;
        case 3:
            TItemObject::carry_over_stats(&replacement, item);
            break;
        }
        u16 client = item->get_owner_client();
        replacement.id = item->get_item_id();
        if (consume_item_by_id(item->get_item_id()) != 0) {
            give_item_to_client(client, &replacement);
        }
    }
}

s32 consume_item_by_id(s32 id) {
    TItem *item = find_item_by_id(id);
    if (item == NULL) {
        return 0;
    }
    TObjPlayer *owner = get_player_by_client_id(item->get_owner_client());
    if (owner == NULL) {
        return 0;
    }
    s32 count = item->get_amount();
    s32 item_id = item->get_item_id();
    owner->dispatch_action(id, 1);
    if (TObjPlayer::is_locally_controlled(owner) != 0) {
        owner->send_unequip_held_item();
    }
    if (find_item_by_id(item_id) != NULL && count < 2) {
        return 0;
    }
    return 1;
}

void give_item_to_client(u16 client, TItemData *data) {
    TObjPlayer *player = get_player_by_client_id(client);
    if (player != NULL) {
        TItem *item = create_item(data);
        if (item != NULL && player->pickup_item(item) == 0) {
            item->destroy();
        }
    }
}

void TItem::equip() {}

void TItem::unequip() {}

void TItem::perform_action() {}

void TItem::use() {
    if (is_wrapped()) {
        unwrap();
        return;
    }
    use_combination_recipe();
}

void TItem::add_equip_stats(s32) {}

void TItem::remove_equip_stats(s32) {}

// Takes this item's stats off its owner and puts them back, keeping the
// owner's current HP and TP.
void TItemEquipBase::refresh_owner_stats() {
    TObjPlayer *player = owner;
    if (player != NULL) {
        s16 hp = get_actor_hp(player);
        s16 tp = get_actor_tp(owner);
        remove_equip_stats(0);
        add_equip_stats(0);
        owner->recalc_stats();
        owner->set_hp_clamped(hp);
        owner->set_tp(tp);
        owner->clamp_hp();
        owner->clamp_tp();
    }
}

void TItem::subtract_item_stat_bonus(s32, s32, s16 *) {}

void TItem::subtract_equip_stats(void *, s16 *, s16 *) {}

void TItem::render_equipped() {}

void TItem::render_equipped_shadow() {}

void TItem::render_equipped_deferred() {}

u32 TItem::get_attack_flags() { return 0; }

void TItem::set_attach_slot(s8) {}

void TItem::activate_effect(s32) {}

void TItem::vfunc_34() {}

s32 TItem::is_identified() { return 1; }

s32 TItem::get_amount() { return 0; }

s32 TItem::remove_amount(s32) { return 0; }

s32 TItem::add_amount(s32) { return 0; }

u8 TItem::get_slot_count() { return 0; }

void TItem::add_slot() {}

s32 feed_item_to_mag(TItem *mag, TItem *item) {
    TItemData data;
    if (item != NULL) {
        item->copy_to_item_data(&data);
        return mag->feed(&data);
    }
    return 0;
}

s32 TItem::feed(TItemData *) { return 0; }

void TItem::update_in_inventory() {}

void TItem::update_equipped() {}

void TItem::snap_to_owner() {}

void TItem::apply_switch_attack(s32 effect) {
    if (owner != NULL && owner->is_body_collision_inactive() == 0) {
        TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect_with_flags(&owner->m_2fc, effect, 0x10);
        if (particle != NULL) {
            particle->set_owner_id(get_owner_client());
        }
    }
}

void TItem::notify_owner(s32 sound) {
    if (owner != NULL && owner->is_body_collision_inactive() == 0) {
        play_sound_effect(sound, &owner->position, 0, 0);
    }
}

void scroll_item_model_uvs(NJS_OBJECT *object, s16 du, s16 dv, u16 mesh) {
    scroll_ginja_mesh_uvs(object->model, du, dv, mesh, 1);
    PPCSync();
}

// The item with this id while it is carried by its owner (an equipped
// weapon), or NULL.
TItem *find_equipped_item(s32 id) {
    TItem *item = find_item_by_id(id);
    if (item != NULL && item->get_mode() == 2) {
        return item;
    }
    return NULL;
}

void TItem::set_kill_count(u16 count) {
    if (item_flags & ITEM_FLAG_KILL_COUNTER) {
        kill_count = count;
    }
}

u16 TItem::get_kill_count() { return kill_count; }

void TItem::set_drop_model(u8 index) {
    drop_model = index;
    if (drop_model < ITEM_MODEL_COUNT) {
        if (drop_model == 7) {
            box_color = 5;
        }
        return;
    }
    drop_model = 2;
    box_color = 0;
}

void TItem::render_ground() {
    if (update_object_view_visibility(200.0f, 5.0f)) {
        void (TItem::*draw[ITEM_MODEL_COUNT])() = {
            &TItem::render_model,
            &TItem::render_model,
            &TItem::render_model,
            &TItem::render_model,
            &TItem::render_model,
            &TItem::render_model,
            &TItem::render_present_box,
            &TItem::render_present_box,
            &TItem::render_model,
            &TItem::render_model,
            &TItem::render_model,
        };
        if (drop_model < ITEM_MODEL_COUNT) {
            if (test_item_flags(ITEM_FLAG_WRAPPED)) {
                (this->*draw[6])();
            } else {
                (this->*draw[drop_model])();
            }
        }
    }
}

void TItem::render_model() {
    void *model;
    s32 texture;
    TItemLoad::get_model_ids(drop_model, (s32 *)&model, &texture);
    if (model != NULL) {
        set_depth_buffer_settings_id(3);
        TParticleCtrl::begin_effect_render();
        set_texlist(texture);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_object(model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        set_default_alpha_blend();
        restore_draw_list_mask();
    }
}

// A wrapped item on the ground is drawn as the present box, in the two
// colours of its wrapping.
void TItem::render_present_box() {
    NJS_OBJECT *box;
    s32 texture;
    TItemLoad::get_model_ids(6, (s32 *)&box, &texture);
    if (box != NULL) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb(&saved_model_draw_color, &model_material_color);
        model_render_flags |= 0x10;
        set_depth_buffer_settings_id(3);
        TParticleCtrl::begin_effect_render();
        set_texlist(texture);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        set_constant_material(&item_box_primary_colors[box_color]);
        draw_ginja_model((s32)box->model);
        set_constant_material(&item_box_secondary_colors[box_color]);
        draw_ginja_model((s32)box->child->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        set_default_alpha_blend();
        restore_draw_list_mask();
        copy_argb(&model_material_color, &saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    }
}

void TItem::render_owned() {}

void TItem::render_following_owner() {}

void TItem::apply_item_flags(TItemData *data) {
    if (TItemData::is_usable(data) != 0) {
        item_flags |= ITEM_FLAG_KILL_COUNTER;
        kill_count = data->get_packed_value();
    }
    if (TItemData::is_wrapped(data) != 0) {
        item_flags |= ITEM_FLAG_WRAPPED;
    }
}

void TItem::assign_item_id() {
    if (get_main_phase() == 15) {
        if ((s32)item_id == -1) {
            item_desync_detected = 1;
            QuestObjectEntry entry = quest_object_entries[set_index];
            item_id = build_item_id(entry.drop_id_base);
        }
    } else if ((s32)item_id == -1) {
        item_desync_detected = 1;
        item_id = advance_item_id_counter(local_client_id);
    }
}

// Turns the owner's combination target into the recipe's result item.
void TItem::use_combination_recipe() {
    TItemData data;
    TItemData result;
    if (owner != NULL) {
        copy_to_item_data(&data);
        TItem *target = (TItem *)find_unique_combination_target((void *)owner, &data);
        u8 *recipe = (u8 *)find_eligible_combination_recipe((s32)owner, (u8 *)&data);
        if (recipe != NULL && target != NULL) {
            result.init();
            result.data1.data_u8[0] = recipe[6];
            result.data1.data_u8[1] = recipe[7];
            result.data1.data_u8[2] = recipe[8];
            int had_flag_80 = target->is_at_tekker();
            s32 target_id = target->get_item_id();
            replace_item_with_new_code(&result, target);
            TItem *replaced = find_item_by_id(target_id);
            if (had_flag_80 != 0 && replaced != NULL) {
                replaced->add_item_flags(0x80);
            }
        }
        apply_switch_attack(0x8D);
        notify_owner(0x40001421);
        consume_item_by_id(get_item_id());
    }
}

void TItem::unwrap() {
    clear_item_flags(ITEM_FLAG_WRAPPED);
}

s32 TItem::is_wrapped() {
    return test_item_flags(ITEM_FLAG_WRAPPED) == ITEM_FLAG_WRAPPED;
}
