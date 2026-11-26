#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/map/MapSetArchive.h"
#include <stddef.h>
#include "pso/map/FloorPopulation.h"
#include "pso/render/gjSystem.h"
#include "pso/map/ChallengeEnemySet.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/map/MapSetData.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/network/TLobby.h"
#include "pso/map/AreaEventSet.h"
#include "pso/map/TSetManager.h"
#include "pso/system/byteswap.h"
#include "pso/item/drop/TItemDrop.h"
#include "pso/system/SubtractiveRng.h"
#include "pso/system/EventShuffleTable.h"
#include "string.h"
#include "pso/map/FloorMapSelection.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/map/FloorWaveEvents.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/GameModeQueries.h"
#include "pso/system/TGStream.h"
#include "pso/system/MemoryMove.h"
#include <stdlib.h>
#include "pso/map/TSetEvtDestroy.h"
#include <string.h>
#include "pso/system/THeap.h"
#include "pso/network/protocol/protocol.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
#include "pso/network/EntitySetFlagsCmd.h"
#include "pso/enemy/EnemyFactoryTables.h"
#include "pso/object/base/ObjectFactoryTables.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/map/FloorArea.h"
#include "pso/enemy/BattleParamTables.h"
#include "pso/quest/QuestFloorDesignation.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <dolphin/ar.h>
#include "pso/system/scene/TScene.h"
#include "pso/system/scene/TSceneMaterial.h"
#include "pso/system/task/TMainTask.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/MatrixStack.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixReflect.h"

#pragma readonly_strings on


// The header is followed by the s16 flags of every object set, then of every enemy set.
int pack_floor_set_flags(FloorSetFlagsPayload *buf) {
    s32 enemies;
    FloorSetFlagsHeader *out = buf;
    s32 objects = 0;
    s16 *p = buf->flags;
    out->object_offset = sizeof(FloorSetFlagsHeader);
    for (s32 i = 0; i < 18; i++) {
        if (floor_enemy_group_table[i].object_count > 0) {
            FloorSavedSetRow *e = floor_enemy_group_table[i].object_rows;
            s32 n = floor_enemy_group_table[i].object_count;
            if (get_current_floor() == i) {
                FloorObjectSetRow *s = current_floor_object_set_rows;
                if (s != NULL) {
                    for (s32 j = 0; j < n; j++) {
                        s16 flags = s->flags & ~2;
                        bswap_16((u16 *)&flags);
                        *p++ = flags;
                        s++;
                        objects++;
                    }
                }
            } else {
                for (s32 j = 0; j < n; j++) {
                    s16 flags = e->flags & ~2;
                    bswap_16((u16 *)&flags);
                    *p++ = flags;
                    e++;
                    objects++;
                }
            }
        }
    }
    enemies = 0;
    out->object_count = objects;
    out->enemy_offset = out->object_count * 2 + 0x10;
    for (s32 i = 0; i < 18; i++) {
        if (floor_enemy_group_table[i].enemy_count > 0) {
            FloorSavedSetRow *e = floor_enemy_group_table[i].enemy_rows;
            s32 n = floor_enemy_group_table[i].enemy_count;
            if (get_current_floor() == i) {
                EnemySetRecord *s = current_floor_enemy_set_rows;
                if (s != NULL) {
                    for (s32 j = 0; j < n; j++) {
                        s16 flags = s->flags & ~2;
                        bswap_16((u16 *)&flags);
                        *p++ = flags;
                        s++;
                        enemies++;
                    }
                }
            } else {
                for (s32 j = 0; j < n; j++) {
                    s16 flags = e->flags & ~2;
                    bswap_16((u16 *)&flags);
                    *p++ = flags;
                    e++;
                    enemies++;
                }
            }
        }
    }
    out->enemy_count = enemies;
    swap_floor_set_flags_header(out);
    return get_floor_set_flags_size();
}

#pragma push
#pragma opt_propagation off
s32 init_quest_floor_enemies(s32 idx, EnemySetRecord *src, u32 size) {
    if (floor_saved_row_heap != 0 && floor_set_archive_pool != 0) {
    uaddr sz = size;
    s32 n = (0, sz / 72);
    LobbyFloorRows *t = &floor_enemy_group_table[idx];
    EnemySetRecord *s;
    FloorSavedSetRow *d;
    s32 i;
    void *buf;
    t->enemy_count = 0;
    s = src;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            t->enemy_count++;
        }
        s++;
    }
    t->enemy_rows = (FloorSavedSetRow *)floor_saved_row_heap->heap_alloc(t->enemy_count * 8);
    memset(t->enemy_rows, 0, t->enemy_count * 8);
    s = src;
    d = t->enemy_rows;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            d->id = s->placement.id;
            d->room = s->placement.room;
            d->wave = s->placement.wave;
            d++;
        }
        s++;
    }
    if (floor_set_archives[idx].enemies != NULL) {
        floor_set_archive_pool->free(floor_set_archives[idx].enemies);
    }
    floor_set_archives[idx].enemies = floor_set_archive_pool->alloc(sz);
    if ((uaddr)src & 0x1F) {
        buf = TQuestVmDownLoadServer::alloc(sz);
        memcpy(buf, src, sz);
        if (floor_set_archives[idx].enemies != NULL) {
            floor_set_archive_pool->transfer(buf, floor_set_archives[idx].enemies, sz, 0);
        }
        safe_free(buf);
    } else if (floor_set_archives[idx].enemies != NULL) {
        floor_set_archive_pool->transfer(src, floor_set_archives[idx].enemies, sz, 0);
    }
    return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
s32 TLobby::load_floor_enemy_group_entries(s32 idx, FloorObjectSetRow *src, u32 size) {
    if (floor_saved_row_heap != 0 && floor_set_archive_pool != 0) {
    uaddr sz = size;
    s32 n = sz / 68;
    LobbyFloorRows *t = &floor_enemy_group_table[idx];
    FloorObjectSetRow *s;
    FloorSavedSetRow *d;
    s32 i;
    void *buf;
    t->object_count = 0;
    s = src;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            t->object_count++;
        }
        s++;
    }
    t->object_rows = (FloorSavedSetRow *)floor_saved_row_heap->heap_alloc(t->object_count * 8);
    memset(t->object_rows, 0, t->object_count * 8);
    s = src;
    d = t->object_rows;
    for (i = 0; i < n; i++) {
        if (s->type != -1) {
            d->id = s->placement.entity_id;
            d->room = s->placement.room;
            d->wave = s->placement.wave;
            d++;
        }
        s++;
    }
    if (floor_set_archives[idx].objects != NULL) {
        floor_set_archive_pool->free(floor_set_archives[idx].objects);
    }
    floor_set_archives[idx].objects = floor_set_archive_pool->alloc(sz);
    if ((uaddr)src & 0x1F) {
        buf = TQuestVmDownLoadServer::alloc(sz);
        memcpy(buf, src, sz);
        if (floor_set_archives[idx].objects != NULL) {
            floor_set_archive_pool->transfer(buf, floor_set_archives[idx].objects, sz, 0);
        }
        safe_free(buf);
    } else if (floor_set_archives[idx].objects != NULL) {
        floor_set_archive_pool->transfer(src, floor_set_archives[idx].objects, sz, 0);
    }
    return 1;
    }
    return 0;
}
#pragma pop
void destroy_floor_decoration_objects(void) {
    FloorObjectSetRow *p = floor_decoration_rows;
    s32 i;
    for (i = 0; i < floor_decoration_row_count; i++, p++) {
        if (p->object != 0) {
            TLobby::destroy_child_recursive(tl_02, p->object);
            TLobby::destroy_child_recursive(tl_05, p->object);
            TLobby::destroy_child_recursive(tl_06, p->object);
            TLobby::destroy_child_recursive(tl_07, p->object);
            p->flags = 0;
            p->object = 0;
        }
    }
}

void TLobby::destroy_child_recursive(TObject *task, TObject *object) {
    TObject *p = task->m_down;
    TObject *cur;
    while (task->m_down != 0 && p != 0) {
        cur = p;
        p = p->m_next;
        if (cur == object) {
            cur->queue_destruction();
        } else {
            destroy_child_recursive(cur, object);
        }
    }
}

void init_scene_objects() { TLobby::init_sub_objects(); reset_id_tables(); clear_floor_event_flags(); init_switch_table(); TRaderMapCore::set_piece_flags(1); attach_objects_by_id((s32)get_current_floor()); create_objects((s32)get_current_floor()); TQuestThread::create_for_floor(); }

void destroy_current_floor_objects(void) {
    s32 n;
    FloorObjectSetRow *p;
    s32 i;
    p = get_active_floor_object_rows(get_current_floor());
    n = TLobby::get_obj_table_entry(get_current_floor());
    for (i = 0; i < n; i++, p++) {
        if (p->object != 0) {
            TLobby::destroy_child_recursive(tl_02, p->object);
            TLobby::destroy_child_recursive(tl_05, p->object);
            TLobby::destroy_child_recursive(tl_06, p->object);
            TLobby::destroy_child_recursive(tl_07, p->object);
            p->object = 0;
        }
    }
}
extern "C" {

void TLobby__sub_8020BCE4(void) {
    EnemySetRecord *p;
    s32 n;
    s32 i;
    p = get_active_floor_enemy_rows(get_current_floor());
    n = TLobby::get_object_type(get_current_floor());
    for (i = 0; i < n; i++, p++) {
        u32 r = (uaddr)find_entity_by_id(p->placement.id);
        if (r != 0) {
            ((TObjBase *)(saddr)r)->set_actor_flags(0x800);
        }
    }
}
}
void handle_6x76_set_entity_set_flags(G_SetEntitySetFlags_6x76 *command) {
    FloorSavedSetRow *e;
    LobbyFloorRows *a;
    FloorSavedSetRow *e2;
    LobbyFloorRows *a2;
    s32 i;
    u16 id;
    command->bswap();
    id = command->header.entity_id;
    if (id >= 0x1000 && id < 0x4000) {
        a = &floor_enemy_group_table[command->floor];
        if (a->enemy_rows != NULL) {
            e = a->enemy_rows;
            for (i = 0; i < a->enemy_count; i++, e++) {
                if (e->id == id) {
                    e->flags |= command->flags;
                    break;
                }
            }
        }
        if (command->floor == get_current_floor()) {
            for (i = 0; i < current_floor_enemy_set_count; i++) {
                if (command->header.entity_id == current_floor_enemy_set_rows[i].placement.id) {
                    current_floor_enemy_set_rows[i].flags |= command->flags;
                    break;
                }
            }
        }
    }
    id = command->header.entity_id;
    if (id >= 0x4000 && id < 0xFFFF) {
        a2 = &floor_enemy_group_table[command->floor];
        if (a2->object_rows != NULL) {
            e2 = a2->object_rows;
            for (i = 0; i < a2->object_count; i++, e2++) {
                if (e2->id == id) {
                    e2->flags |= command->flags;
                    break;
                }
            }
        }
        if (command->floor == get_current_floor()) {
            for (i = 0; i < current_floor_object_set_count; i++) {
                if (command->header.entity_id == current_floor_object_set_rows[i].placement.entity_id) {
                    current_floor_object_set_rows[i].flags |= command->flags;
                    break;
                }
            }
        }
    }
}


void send_6x76_set_entity_set_flags(TObjBase *object, s16 flags) {
    G_SetEntitySetFlags_6x76 pkt;
    build_6x76_set_entity_set_flags(&pkt);
    pkt.header.entity_id = object->get_entity_id();
    pkt.floor = ((s16 (*)())get_current_floor)();
    pkt.flags = flags;
    pkt.send();
}

void apply_floor_set_flags_packet(FloorSetFlagsHeader *buffer, u16) {
    unpack_floor_set_flags(buffer);
}

int get_floor_set_flags_size(void) {
    s32 count = 0;
    count += get_total_object_set_count();
    count += TLobby::sum_floor_enemy_counts();
    return count * 2 + 0x10;
}

int serialize_area_set_flags(FloorSetFlagsPayload *buffer) {
    return pack_floor_set_flags(buffer);
}

s32 get_enemy_factory_child_count(s32 area, s16 *enemy_type) {
    EnemyFactoryEntry *base = enemy_factory_area_table[area];
    EnemyFactoryEntry *p = base;
    for (; base != 0 && p->type != -1; p++) {
        if (p->type == *enemy_type) {
            return p->child_count;
        }
    }
    return 0;
}

s32 TLobby::find_floor_object_factory(s32 area, s16 *object_type) {
    ObjectFactoryEntry *base = floor_object_factory_tables[area];
    ObjectFactoryEntry *p = base;
    for (; base != 0 && p->type != -1; p++) {
        if (p->type == *object_type) {
            return p->extra_object_ids;
        }
    }
    return 0;
}

void set_wave_object_flags(s32 pl, s16 b, s16 a, s32 mask, s32 set) {
    if (pl == get_current_floor()) {
        FloorObjectSetRow *p = current_floor_object_set_rows;
        s32 i;
        for (i = 0; i < current_floor_object_set_count; i++, p++) {
            if (p->placement.room == b && p->placement.wave == a) {
                p->flags &= mask;
                p->flags |= set;
            }
        }
    }
}

s32 TLobby::count_quest_enemies_flag8() {
    s32 n = 0;
    s32 i;
    s32 j;
    if (current_floor_enemy_set_rows != NULL) {
        for (j = 0; j < current_floor_enemy_set_count; j++) {
            EnemySetRecord *a = &current_floor_enemy_set_rows[j];
            if (a->type != -1 && (a->flags & 8)) {
                n++;
            }
        }
    }
    for (i = 0; i < 0x12; i++) {
        if (i != get_current_floor()) {
            LobbyFloorRows *t = &floor_enemy_group_table[i];
            FloorSavedSetRow *b = t->enemy_rows;
            if (b != NULL) {
                for (j = 0; j < t->enemy_count; j++) {
                    if (b->flags & 8) {
                        n++;
                    }
                    b++;
                }
            }
        }
    }
    return n;
}

s32 is_room_enemy_set_cleared(s32 floor, s16 room) {
    s32 i;
    if (floor == get_current_floor()) {
        if (current_floor_enemy_set_rows != NULL) {
            for (i = 0; i < current_floor_enemy_set_count; i++) {
                EnemySetRecord *row = &current_floor_enemy_set_rows[i];
                if (room == row->placement.room && !(row->flags & 8)) {
                    return 0;
                }
            }
        }
        return 1;
    } else {
        LobbyFloorRows *saved = &floor_enemy_group_table[floor];
        FloorSavedSetRow *row = saved->enemy_rows;
        if (row != NULL) {
            for (i = 0; i < saved->enemy_count; i++, row++) {
                if (row->room == room && !(row->flags & 8)) {
                    return 0;
                }
            }
        }
        return 1;
    }
}

s32 TWindowDD::check_all_ready(s32 floor) {
    s16 flags;
    s32 object_type;
    s32 i;
    u8 *active_floor_enemy_rows;

    active_floor_enemy_rows = reinterpret_cast<u8 *>(get_active_floor_enemy_rows(floor));
    object_type = TLobby::get_object_type(floor);
    if (active_floor_enemy_rows != NULL) {
        for (i = 0; i < object_type; i++) {
            flags = *(s16 *)((s8 *)active_floor_enemy_rows + 2);
            if (!(flags & 8) && (flags & 2)) {
                return 0;
            }
            active_floor_enemy_rows += 0x48;
        }
    }
    return 1;
}


s32 is_room_free_of_active_enemies(s32 floor, s16 room) {
    IsRoomFreeOfActiveEnemiesRow *rows = reinterpret_cast<IsRoomFreeOfActiveEnemiesRow *>(get_active_floor_enemy_rows(floor));
    s32 count = TLobby::get_object_type(floor);
    if (rows != NULL) {
        for (; count > 0; count--, rows++) {
            if (rows[0].room == room && !(rows[0].flags & 8) && (rows[0].flags & 2)) {
                return 0;
            }
        }
    }
    return 1;
}

s32 TObjEnemy::mask_sub_flags(s32 mask) {
    EnemySetRecord *set_entry;

    set_entry = (EnemySetRecord *)this->set_entry;
    if (set_entry != NULL) {
        set_entry->flags &= mask;
        return 1;
    }
    return 0;
}

s32 TObjBase::set_event_source_flag(s32 event_source_flag) {
    FloorObjectSetRow *set_entry;

    set_entry = (FloorObjectSetRow *)this->set_entry;
    if (set_entry != NULL) {
        set_entry->flags |= event_source_flag;
        return 1;
    }
    return 0;
}

s32 TObjBase::mask_object_set_row_flags(s32 arg1) {
    FloorObjectSetRow *set_entry;

    set_entry = (FloorObjectSetRow *)this->set_entry;
    if (set_entry != NULL) {
        set_entry->flags &= arg1;
        return 1;
    }
    return 0;
}
s32 TLobby::clear_record_flags_a() {
    s32 i;
    s32 j;
    s32 k;
    if (current_floor_enemy_set_rows != NULL) {
        for (i = 0; i < current_floor_enemy_set_count; i++) {
            current_floor_enemy_set_rows[i].flags = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (floor_enemy_group_table[k].enemy_rows != NULL) {
            for (j = 0; j < floor_enemy_group_table[k].enemy_count; j++) {
                floor_enemy_group_table[k].enemy_rows[j].flags = 0;
            }
        }
    }
    return 1;
}
s32 TLobby::clear_record_flags_b() {
    s32 i;
    s32 j;
    s32 k;
    if (current_floor_object_set_rows != NULL) {
        for (i = 0; i < current_floor_object_set_count; i++) {
            current_floor_object_set_rows[i].flags = 0;
        }
    }
    for (k = 0; k < 0x12; k++) {
        if (floor_enemy_group_table[k].object_rows != NULL) {
            for (j = 0; j < floor_enemy_group_table[k].object_count; j++) {
                floor_enemy_group_table[k].object_rows[j].flags = 0;
            }
        }
    }
    return 1;
}

s32 TObjEnemy::send_entity_set_flags() {
    if ((uaddr) this->set_entry != 0U) {
        send_6x76_set_entity_set_flags(this, 8);
        return 1;
    }
    return 0;
}

s32 TObjCollidable::set_flag8() {
    void *set_entry;

    set_entry = this->set_entry;
    if (set_entry != NULL) {
        *(s16 *)((s8 *)set_entry + 2) = (s16) (*(s16 *)((s8 *)set_entry + 2) | 8);
        return 1;
    }
    return 0;
}


s32 TLobby::spawn_matching_objects(s16 room, s16 wave, saddr wave_members) {
    s16 set_index;
    s16 flags;
    s32 row_count;
    s32 spawned;
    EnemySetRecord *row;
    s32 row_index;
    TObjEnemy *enemy;

    spawned = 0;
    if (active_set_floor < 0) {
        return 0;
    }
    row = get_active_floor_enemy_rows(active_set_floor);
    row_count = TLobby::get_object_type(active_set_floor);
    for (row_index = 0; row_index < row_count; row_index += 1, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->placement.room == room) && (row->placement.wave == wave)) {
            enemy = construct_enemy_from_set_row(row);
            if (enemy != NULL) {
                row->enemy = enemy;
                row->flags |= 2;
                enemy->room = row->placement.room;
                enemy->set_group = row->placement.wave;
                enemy->set_index = row->placement.enemy_index;
                enemy->set_entry = row;
                set_index = enemy->set_index;
                if (set_index != -1) {
                    enemy->apply_enemy_state(&enemy_state_records[set_index].flags);
                }
                append_wave_member((SendPlayerUpdateObject *)wave_members, (SendPlayerUpdateItem *)enemy);
                spawned += 1;
            } else {
                row->enemy = NULL;
            }
        }
    }
    return spawned;
}

s32 unhide_enemies_at(s32 floor, s16 room, s16 wave) {
    s32 n;
    s32 count;
    s32 local;
    EnemySetRecord *set;
    s32 i;
    TObjEnemy *obj;
    count = 0;
    local = 0;
    if (floor == get_current_floor()) {
        local = 1;
    }
    if (local == 0) {
        return TLobby::set_flags_on_matching_entries(floor, room, wave, 1);
    }
    set = get_active_floor_enemy_rows(floor);
    n = TLobby::get_object_type(floor);
    for (i = 0; i < n; i++, set++) {
        if (set->flags & 8) continue;
        if (set->flags & 2) continue;
        if (set->flags & 1) continue;
        if (set->placement.room != room) continue;
        if (set->placement.wave != wave) continue;
        if (local != 0) {
            obj = construct_enemy_from_set_row(set);
            if (obj != NULL) {
                set->enemy = obj;
                set->flags |= 2;
                obj->room = set->placement.room;
                obj->set_group = set->placement.wave;
                obj->set_index = set->placement.enemy_index;
                obj->set_entry = set;
                if (obj->set_index != -1) {
                    obj->apply_enemy_state(&enemy_state_records[obj->set_index].flags);
                }
                count++;
            } else {
                set->enemy = NULL;
            }
        } else {
            set->flags |= 1;
            count++;
        }
    }
    return count;
}

s32 TLobby::link_matching_objects(s16 room, s16 wave) {
    s16 set_index;
    s16 flags;
    s32 row_count;
    s32 spawned;
    EnemySetRecord *row;
    s32 row_index;
    TObjEnemy *enemy;

    spawned = 0;
    if (active_set_floor < 0) {
        return 0;
    }
    row = get_active_floor_enemy_rows(active_set_floor);
    row_count = TLobby::get_object_type(active_set_floor);
    for (row_index = 0; row_index < row_count; row_index += 1, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->placement.room == room) && (row->placement.wave == wave)) {
            enemy = construct_enemy_from_set_row(row);
            if (enemy != NULL) {
                row->enemy = enemy;
                row->flags |= 2;
                enemy->room = row->placement.room;
                enemy->set_group = row->placement.wave;
                enemy->set_index = row->placement.enemy_index;
                enemy->set_entry = row;
                set_index = enemy->set_index;
                if (set_index != -1) {
                    enemy->apply_enemy_state(&enemy_state_records[set_index].flags);
                }
                spawned += 1;
            } else {
                row->enemy = NULL;
            }
        }
    }
    return spawned;
}

s32 unhide_room_set_objects(s32 floor, s16 room, s16 group) {
    s32 n;
    s32 count;
    s32 local;
    FloorObjectSetRow *set;
    s32 i;
    TObjBase *obj;
    count = 0;
    local = 0;
    if (floor == get_current_floor()) {
        local = 1;
    }
    if (local == 0) {
        return TLobby::set_room_group_flags(floor, room, group, 1);
    }
    set = get_active_floor_object_rows(floor);
    n = TLobby::get_obj_table_entry(floor);
    for (i = 0; i < n; i++, set++) {
        if (set->flags & 8) continue;
        if (set->flags & 2) continue;
        if (set->flags & 1) continue;
        if (set->placement.room != room) continue;
        if (set->placement.wave != group) continue;
        if (local != 0) {
            obj = create_set_object_from_row(set);
            if (obj != NULL) {
                set->object = obj;
                set->flags |= 0x12;
                obj->room = set->placement.room;
                obj->set_group = set->placement.wave;
                obj->set_index = set->placement.set_index;
                obj->set_entry = set;
                if (obj->set_index != -1) {
                    obj->apply_saved_state(&quest_object_entries[obj->set_index].flags, 0);
                }
                count++;
            } else {
                set->object = NULL;
            }
        } else {
            set->flags |= 1;
            count++;
        }
    }
    return count;
}

s32 spawn_objects_at_pos(s16 room, s16 wave) {
    s16 set_index;
    s16 flags;
    s32 obj_table_entry;
    s32 spawned;
    FloorObjectSetRow *row;
    s32 k;
    TObjBase *set_object;

    spawned = 0;
    row = get_active_floor_object_rows(active_set_floor);
    obj_table_entry = TLobby::get_obj_table_entry(active_set_floor);
    for (k = 0; k < obj_table_entry; k++, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->placement.room == room) && (row->placement.wave == wave)) {
            set_object = create_set_object_from_row(row);
            if (set_object != NULL) {
                row->object = set_object;
                row->flags = (s16) (row->flags | 0x12);
                set_object->room = row->placement.room;
                set_object->set_group = row->placement.wave;
                set_object->set_index = row->placement.set_index;
                set_object->set_entry = row;
                set_index = set_object->set_index;
                if (set_index != -1) {
                    set_object->apply_saved_state(&quest_object_entries[set_index].flags, 0);
                }
                spawned += 1;
            } else {
                row->object = NULL;
            }
        }
    }
    return spawned;
}

s32 find_enemy_factory_entry(const volatile EnemySetRecord *row, EnemyFactoryEntry *out) {
    s32 index = 0;
    EnemyFactoryEntry *table = enemy_factory_area_table[get_current_floor_area()];
    EnemyFactoryEntry *entry = table;
    while (table != NULL && entry->type != -1) {
        if (entry->type == row->type) {
            copy_enemy_factory_entry(out, entry);
            return index;
        }
        entry++;
        index++;
    }
    return -1;
}

void copy_enemy_factory_entry(EnemyFactoryEntry *out, EnemyFactoryEntry *entry) {
    out->type = entry->type;
    out->create = entry->create;
    out->field_08 = entry->field_08;
    out->child_count = entry->child_count;
}

TObjEnemy *construct_enemy_from_set_row(EnemySetRecord *row) {
    EnemyFactoryEntry entry;
    if (find_enemy_factory_entry(row, &entry) >= 0) {
        return static_cast<TObjEnemy *>(entry.create(&row->placement));
    }
    return NULL;
}

void create_objects(s32 floor) {
    s16 flags;
    s16 set_index;
    s32 row_count;
    EnemySetRecord *row;
    s32 row_index;
    TObjEnemy *enemy;

    row = get_active_floor_enemy_rows(floor);
    row_count = TLobby::get_object_type(floor);
    for (row_index = 0; row_index < row_count; row_index++, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->type != -1) && ((flags & 1) || (row->placement.wave == 0))) {
            enemy = construct_enemy_from_set_row(row);
            if (enemy != NULL) {
                row->enemy = enemy;
                row->flags |= 2;
                enemy->room = row->placement.room;
                enemy->set_group = row->placement.wave;
                enemy->set_index = row->placement.enemy_index;
                enemy->set_entry = row;
                set_index = enemy->set_index;
                if (set_index != -1) {
                    enemy->apply_enemy_state(&enemy_state_records[set_index].flags);
                }
            } else {
                row->enemy = NULL;
            }
            row->flags &= ~1;
        }
    }
}

void assign_display_objects(EnemySetRecord *rows, s32 enemy_count) {
    s16 flags;
    s16 set_index;
    EnemySetRecord *row;
    s32 row_index;
    TObjEnemy *enemy;

    row = rows;
    for (row_index = 0; row_index < enemy_count; row_index++, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->type != -1) && ((flags & 1) || (row->placement.wave == 0))) {
            enemy = construct_enemy_from_set_row(row);
            if (enemy != NULL) {
                row->enemy = enemy;
                row->flags |= 2;
                enemy->room = row->placement.room;
                enemy->set_group = row->placement.wave;
                enemy->set_index = row->placement.enemy_index;
                enemy->set_entry = row;
                set_index = enemy->set_index;
                if (set_index != -1) {
                    enemy->apply_enemy_state(&enemy_state_records[set_index].flags);
                }
            } else {
                row->enemy = NULL;
            }
            row->flags &= ~1;
        }
    }
}

s32 find_set_factory_index(FloorObjectSetRow *row, ObjectFactoryEntry *out) {
    s32 index = 0;
    ObjectFactoryEntry *table = floor_object_factory_tables[get_current_floor_area()];
    ObjectFactoryEntry *entry = table;
    while (table != NULL && entry->type != -1) {
        if (entry->type == row->type) {
            copy_object_factory_entry(out, entry);
            return index;
        }
        entry++;
        index++;
    }
    return -1;
}

void copy_object_factory_entry(ObjectFactoryEntry *out, ObjectFactoryEntry *entry) {
    out->type = entry->type;
    out->create = entry->create;
    out->creation_distance_squared = entry->creation_distance_squared;
    out->extra_object_ids = entry->extra_object_ids;
}

TObjBase *call_area_set_factory(TSetManager *, FloorObjectSetRow *row) {
    ObjectFactoryFunction factory = floor_object_factory_tables[get_current_floor_area()][row->type].create;
    if (factory != NULL) {
        return static_cast<TObjBase *>(factory(&row->placement));
    }
    return NULL;
}

TObjBase *create_set_object_from_row(FloorObjectSetRow *row) {
    ObjectFactoryEntry entry;
    if (row->type != -1 && find_set_factory_index(row, &entry) >= 0) {
        return static_cast<TObjBase *>(entry.create(&row->placement));
    }
    return NULL;
}

void attach_objects_by_id(s32 floor) {
    s16 flags;
    s16 set_index;
    s32 count;
    FloorObjectSetRow *row;
    s32 i;
    TObjBase *set_object;

    row = get_active_floor_object_rows(floor);
    count = TLobby::get_obj_table_entry(floor);
    for (i = 0; i < count; i++, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->type != -1) && ((flags & 0x10) || (flags & 1) || (row->placement.wave == 0))) {
            set_object = create_set_object_from_row(row);
            if (set_object != NULL) {
                row->object = set_object;
                row->flags = (s16) (row->flags | 2);
                set_object->room = row->placement.room;
                set_object->set_index = row->placement.set_index;
                set_object->set_entry = row;
                set_index = set_object->set_index;
                if (set_index != -1) {
                    set_object->apply_saved_state(&quest_object_entries[set_index].flags, 0);
                }
            } else {
                row->object = NULL;
            }
            row->flags = (s16) (row->flags & 0xFFFFFFFE);
        }
    }
}

void assign_objects_to_slots(u8 *rows, s32 object_count) {
    s16 flags;
    s16 set_index;
    FloorObjectSetRow *row;
    s32 i;
    TObjBase *set_object;

    row = (FloorObjectSetRow *)rows;
    for (i = 0; i < object_count; i++, row++) {
        flags = row->flags;
        if (!(flags & 8) && !(flags & 2) && (row->type != -1) && ((flags & 0x10) || (flags & 1) || (row->placement.wave == 0))) {
            set_object = create_set_object_from_row(row);
            if (set_object != NULL) {
                row->object = set_object;
                row->flags = (s16) (row->flags | 2);
                set_object->room = row->placement.room;
                set_object->set_index = row->placement.set_index;
                set_object->set_entry = row;
                set_index = set_object->set_index;
                if (set_index != -1) {
                    set_object->apply_saved_state(&quest_object_entries[set_index].flags, 0);
                }
            } else {
                row->object = NULL;
            }
            row->flags = (s16) (row->flags & 0xFFFFFFFE);
        }
    }
}


s32 active_set_floor_area;
s32 active_set_floor;
s32 lbl_805D6100;
AramPool *floor_set_archive_pool;
THeap *floor_saved_row_heap;
FloorObjectSetRow *current_floor_object_set_rows;
s32 current_floor_object_set_count;
EnemySetRecord *current_floor_enemy_set_rows;
s32 current_floor_enemy_set_count;
FloorObjectSetRow *floor_decoration_rows;
s32 floor_decoration_row_count;
void *floor_decoration_rows_b;
s32 floor_decoration_row_count_b;
s32 item_drop_memory_pool_ar_addr;
s32 item_drop_memory_pool_size;
s16 floor_set_flags;
FloorObjectSetRow *object_set_row_buffer;
EnemySetRecord *enemy_set_row_buffer;
QuestObjectEntry *quest_object_entries;
EnemyStateRecord *enemy_state_records;
s32 object_condition_count;
s32 enemy_condition_count;


typedef ObjectFactoryEntry Ent_8020D5AC;

extern "C" {
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
}
void apply_room_transform_to_enemy_rows(EnemySetRecord *rows, s32 count);
void apply_room_transform_to_object_rows(FloorObjectSetRow *arr, s32 n);
extern "C" {
s32 is_battle_mode_running();
}
void apply_room_transform(void *matrix, u8 *rotation, u8 *room);
void resolve_set_row_factory_indices(void *unused, FloorObjectSetRow *rows, int count);
s32 is_within_camera_distance(void *unused, Vec *pos, f32 max_dist_sq);
void spawn_decorations_in_range(TSetManager *manager);
void apply_room_transform(void *matrix, u8 *rotation, u8 *room_arg) {
    SceneMaterialSection *room = (SceneMaterialSection *)room_arg;
    s32 *angles = (s32 *)rotation;
    push_matrix_from(identity_matrix);
    translate_matrix(0, room->position.x, room->position.y, room->position.z);
    rotate_matrix_z(0, room->angles[2]);
    rotate_matrix_x(0, room->angles[0]);
    rotate_matrix_y(0, room->angles[1]);
    matrix_mult_vec(0, matrix, matrix);
    pop_matrix();
    angles[0] = angles[0] + room->angles[0];
    angles[1] = angles[1] + room->angles[1];
    angles[2] = angles[2] + room->angles[2];
}

void apply_room_transform_to_enemy_rows(EnemySetRecord *rows, s32 count) {
    EnemySetRecord *row;
    void *cached_room;
    s16 cached_id = -1;
    s32 i;
    for (i = 0; i < count; i++) {
        row = &rows[i];
        if (cached_id != row->placement.room) {
            cached_room = find_scene_room_by_id(row->placement.room);
            cached_id = row->placement.room;
        }
        if (cached_room) {
            apply_room_transform(&row->placement.position, (u8 *)row->placement.rotation, (u8 *)cached_room);
        }
    }
}

void apply_room_transform_to_object_rows(FloorObjectSetRow *arr, s32 n) {
    FloorObjectSetRow *p;
    void *sec;
    s16 key;
    s32 i;
    key = -1;
    i = 0;
    for (; i < n; i++) {
        p = &arr[i];
        if (key != p->placement.room) {
            sec = find_scene_room_by_id(p->placement.room);
            key = p->placement.room;
        }
        if (sec != NULL) {
            apply_room_transform(&p->placement.position, (u8 *)p->placement.rotation, (u8 *)sec);
        }
    }
}

void resolve_set_row_factory_indices(void *unused, FloorObjectSetRow *rows, int count) {
    ObjectFactoryEntry entry;
    FloorObjectSetRow *p;
    s32 i;
    s32 r;
    p = rows;
    for (i = 0; i < count; i++, p++) {
        if (p->type != -1) {
            r = find_set_factory_index(p, &entry);
            if (r >= 0) {
                p->type = r;
            } else {
                p->type = -1;
            }
        }
    }
}

s32 is_within_camera_distance(void *unused, Vec *pos, f32 max_dist_sq) {
    s32 n;
    s32 i;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (camera_ctrl_instance != NULL) {
            n = TCameraCtrl::get_view_count();
            for (i = 0; i < n; i++) {
                if (xyz_distance_squared(pos, &camera_ctrl_instance->split_pos[i]) < max_dist_sq) {
                    return 1;
                }
            }
        }
    } else if (camera_ctrl_instance != NULL && xyz_distance_squared(pos, &camera_ctrl_instance->pos) < max_dist_sq) {
        return 1;
    }
    return 0;
}

void spawn_decorations_in_range(TSetManager *manager) {
    Ent_8020D5AC *tbl;
    FloorObjectSetRow *p;
    s32 i;
    TObjBase *obj;
    tbl = floor_object_factory_tables[get_current_floor_area()];
    if (tbl == NULL) {
        return;
    }
    if (TObjPlayer::get_player_count() != 0 && is_quest_active() != 0 && is_battle_mode_running() == 0) {
        return;
    }
    p = floor_decoration_rows;
    for (i = 0; i < floor_decoration_row_count; i++, p++) {
        if (p->type != -1 && !(p->flags & 2) && !(p->flags & 8)
            && is_within_camera_distance(manager, &p->placement.position, tbl[p->type].creation_distance_squared) == 1) {
            p->placement.entity_id = 0xFFFF;
            p->placement.set_index = -1;
            obj = call_area_set_factory(manager, p);
            if (obj != NULL) {
                p->object = obj;
                obj->room = p->placement.room;
                obj->set_entry = p;
                p->flags |= 2;
            } else {
                p->object = NULL;
                p->flags |= 8;
            }
        }
    }
}

void TSetManager::update_decoration_spawning() { spawn_decorations_in_range(this); }
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TSetManager::apply_floor_set_rows() {
    u8 *self = (u8 *)this;
    s32 current_floor;
    LobbyFloorRows *floor;
    current_floor = get_current_floor();
    active_set_floor = current_floor;
    floor = &floor_enemy_group_table[current_floor];
    if (!(floor->object_placement & 2)) {
        apply_room_transform_to_object_rows(current_floor_object_set_rows, floor->object_count);
        floor->object_placement |= 2U;
    }
    if (!(floor->enemy_placement & 4)) {
        apply_room_transform_to_enemy_rows(current_floor_enemy_set_rows, floor->enemy_count);
        floor->enemy_placement |= 4U;
    }
    if (floor->object_placement & 2) {
        assign_objects_to_slots((u8 *)current_floor_object_set_rows, floor->object_count);
    }
    if (floor->enemy_placement & 4) {
        assign_display_objects(current_floor_enemy_set_rows, floor->enemy_count);
    }
    if (floor_decoration_row_count > 0) {
        apply_room_transform_to_object_rows(floor_decoration_rows, floor_decoration_row_count);
        resolve_set_row_factory_indices(self, floor_decoration_rows, floor_decoration_row_count);
    }
    this->step = 1;
}
#pragma pop

void TSetManager::post_step() {  }

void TSetManager::run_task() {
    static void (TSetManager::*steps[])() = {
        &TSetManager::apply_floor_set_rows,
        &TSetManager::update_decoration_spawning,
    };
    (this->*steps[step])();
    post_step();
}

TSetManager::~TSetManager() {}

const char *TSetManager::class_name = "TSetManager";

TSetManager::TSetManager(TObject *parent) : TObject(parent) {
    m_name = class_name;
    step = 0;
}

LobbyPoolEntry floor_set_archives[18];
LobbyFloorRows floor_enemy_group_table[18];
s32 floor_object_set_counts[18];
s32 floor_enemy_set_counts[18];
u32 TLobby__data_80513D10[9];
#pragma push
#pragma force_active on
u8 lbl_80513D34[0x24];
#pragma pop
extern const char decoration_file_suffix_online[7] = "ad.dat";
extern const char decoration_file_suffix_offline[6] = "d.dat";

void TSetManager::create() {
    new TSetManager(tl_02);
}

void free_floor_decorations() {
    if (floor_decoration_rows != NULL) {
        mem_free(floor_decoration_rows);
        floor_decoration_rows = NULL;
        floor_decoration_row_count = 0;
    }
    if (floor_decoration_rows_b != NULL) {
        mem_free(floor_decoration_rows_b);
        floor_decoration_rows_b = NULL;
        floor_decoration_row_count_b = 0;
    }
}

s32 load_map_decoration_rows(s32 map, s32 grp, s32 room) {
    MapSetEntry *r;
    s32 i;
    s32 size;
    char path[0x20];
    if (map_set_areas[map].variants == NULL || map_set_areas[map].count - 1 < grp) {
        return 0;
    }
    r = map_set_areas[map].variants[grp].entries;
    if (r == NULL || map_set_areas[map].variants[grp].count - 1 < room) {
        return 0;
    }
    if (TLobby::is_online_ready() != 0) {
        TLobby::replace_file_extension(path, (char *)r->decoration_set_name, (char *)decoration_file_suffix_online);
    } else {
        TLobby::replace_file_extension(path, (char *)r->decoration_set_name, (char *)decoration_file_suffix_offline);
    }
    size = get_resource_file_size(path);
    if (size < 0) {
        return 0;
    }
    floor_decoration_row_count = (u32)size / sizeof(FloorObjectSetRow);
    if ((floor_decoration_rows = static_cast<FloorObjectSetRow *>(mem_alloc(floor_decoration_row_count * sizeof(FloorObjectSetRow)))) == 0) {
        return 0;
    }
    read_disc_file(path, floor_decoration_rows);
    for (i = 0; i < floor_decoration_row_count; i++) {
        swap_object_row_endian(&floor_decoration_rows[i]);
        floor_decoration_rows[i].flags = 0;
        floor_decoration_rows[i].placement.entity_id = 0xFFFF;
        floor_decoration_rows[i].placement.set_index = -1;
    }
    return 1;
}

void clear_floor_flags_and_depart() {
    free_floor_decorations();
    floor_set_flags &= ~8;
    floor_set_flags &= ~16;
    depart_floor_population();
}

void setup_floor_decorations() {
    FloorMapSelection v;
    saddr r;
    arrive_floor_population();
    floor_decoration_rows = NULL;
    floor_set_flags &= ~8;
    floor_decoration_rows_b = NULL;
    floor_decoration_row_count = 0;
    floor_decoration_row_count_b = 0;
    floor_set_flags &= ~16;
    active_set_floor_area = get_current_floor_area();
    r = get_current_floor();
    active_set_floor = r;
    if (lookup_floor_map_selection(r, &v) != 0) {
        load_map_decoration_rows(v.area, v.terrain, v.entities);
        return;
    }
    active_set_floor_area = -1;
}

void reset_id_tables() {
    s32 i;
    s32 n = 0;
    if (quest_object_entries != 0) {
        memset(quest_object_entries, 0, 0x2E80);
        for (i = 0; i < 0xBA0; i++) {
            s16 t = n + 0x100;
            n++;
            quest_object_entries[i].drop_id_base = t;
        }
    }
    if (enemy_state_records != 0) {
        memset(enemy_state_records, 0, 0x87C0);
        for (i = 0; i < 0xB50; i++) {
            s16 t = n + 0x100;
            n++;
            enemy_state_records[i].drop_id = t;
        }
    }
}

// inferred: clears the set object and enemy rows and frees every floor's enemy and object arrays; a lobby area reload callback
void clear_floor_population(void) {
    s32 n;
    s32 i;
    floor_set_flags = 0;
    if (object_set_row_buffer != NULL) {
        memset(object_set_row_buffer, 0, 0xBA0 * sizeof(FloorObjectSetRow));
        for (i = 0; i < 0xBA0; i++) {
            object_set_row_buffer[i].type = -1;
        }
    }
    if (enemy_set_row_buffer != NULL) {
        memset(enemy_set_row_buffer, 0, 0x5A8 * sizeof(EnemySetRecord));
        for (i = 0; i < 0x5A8; i++) {
            enemy_set_row_buffer[i].type = -1;
        }
    }
    memset(floor_object_set_counts, 0, sizeof(floor_object_set_counts));
    memset(floor_enemy_set_counts, 0, sizeof(floor_enemy_set_counts));
    memset(TLobby__data_80513D10, 0, sizeof(TLobby__data_80513D10));
    n = 0;
    if (quest_object_entries != 0) {
        memset(quest_object_entries, 0, 0x2E80);
        for (i = 0; i < 0xBA0; i++) {
            quest_object_entries[i].drop_id_base = n++ + 0x100;
        }
    }
    if (enemy_state_records != 0) {
        memset(enemy_state_records, 0, 0x87C0);
        for (i = 0; i < 0xB50; i++) {
            enemy_state_records[i].drop_id = n++ + 0x100;
        }
    }
    object_condition_count = 0;
    enemy_condition_count = 0;
    floor_decoration_rows = 0;
    floor_decoration_rows_b = NULL;
    floor_decoration_row_count = 0;
    floor_decoration_row_count_b = 0;
    lbl_805D6100 = 0;
    for (s32 i = 17; i >= 0; i--) {
        if (floor_set_archives[i].enemies != NULL) {
            floor_set_archive_pool->free(floor_set_archives[i].enemies);
            floor_set_archives[i].enemies = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (floor_set_archives[i].objects != NULL) {
            floor_set_archive_pool->free(floor_set_archives[i].objects);
            floor_set_archives[i].objects = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (floor_enemy_group_table[i].enemy_rows != NULL) {
            floor_saved_row_heap->heap_free(floor_enemy_group_table[i].enemy_rows);
            floor_enemy_group_table[i].enemy_rows = NULL;
        }
    }
    for (s32 i = 17; i >= 0; i--) {
        if (floor_enemy_group_table[i].object_rows != NULL) {
            floor_saved_row_heap->heap_free(floor_enemy_group_table[i].object_rows);
            floor_enemy_group_table[i].object_rows = NULL;
        }
    }
    memset(floor_enemy_group_table, 0, sizeof(floor_enemy_group_table));
}

void depart_floor_population() {
    LobbyFloorRows *area = &floor_enemy_group_table[get_current_floor()];
    if (current_floor_object_set_rows != 0) {
        FloorObjectSetRow *s = current_floor_object_set_rows;
        FloorSavedSetRow *d = area->object_rows;
        s32 i;
        for (i = 0; i < area->object_count; i++, s++, d++) {
            if (s->placement.entity_id == d->id) {
                d->flags = s->flags;
            }
        }
    }
    if (current_floor_enemy_set_rows != 0) {
        EnemySetRecord *s = current_floor_enemy_set_rows;
        FloorSavedSetRow *d = area->enemy_rows;
        s32 i;
        for (i = 0; i < area->enemy_count; i++, s++, d++) {
            if (s->placement.id == d->id) {
                d->flags = s->flags;
            }
        }
    }
    if (current_floor_enemy_set_rows != 0) {
        safe_free(current_floor_enemy_set_rows);
        current_floor_enemy_set_rows = 0;
    }
    if (current_floor_object_set_rows != 0) {
        safe_free(current_floor_object_set_rows);
        current_floor_object_set_rows = 0;
    }
}

void free_item_drop_tables() {
    if (enemy_state_records != NULL) {
        safe_free(enemy_state_records);
        enemy_state_records = NULL;
    }
    if (quest_object_entries != NULL) {
        safe_free(quest_object_entries);
        quest_object_entries = NULL;
    }
    if (floor_saved_row_heap != NULL) {
        delete floor_saved_row_heap;
        floor_saved_row_heap = NULL;
    }
    if (floor_set_archive_pool != NULL) {
        delete floor_set_archive_pool;
        floor_set_archive_pool = NULL;
    }
    if (enemy_set_row_buffer != NULL) {
        safe_free(enemy_set_row_buffer);
        enemy_set_row_buffer = NULL;
    }
    if (object_set_row_buffer != NULL) {
        safe_free(object_set_row_buffer);
        object_set_row_buffer = NULL;
    }
}

void arrive_floor_population() {
    s32 index;
    LobbyFloorRows *floor;
    saddr bytes;
    FloorObjectSetRow *o;
    FloorSavedSetRow *r;
    s32 i;
    EnemySetRecord *e;
    FloorSavedSetRow *r2;
    s32 j;
    current_floor_object_set_rows = 0;
    current_floor_enemy_set_rows = 0;
    current_floor_object_set_count = 0;
    current_floor_enemy_set_count = 0;
    index = get_current_floor();
    floor = &floor_enemy_group_table[index];
    bytes = floor->object_count * 0x44;
    if (bytes > 0) {
        bytes = (bytes + 0x1F) & ~0x1F;
        current_floor_object_set_rows = (FloorObjectSetRow *)TQuestVmDownLoadServer::alloc(bytes);
    }
    if (current_floor_object_set_rows != NULL) {
        floor_set_archive_pool->transfer(floor_set_archives[index].objects, current_floor_object_set_rows, bytes, 1);
        o = current_floor_object_set_rows;
        r = floor->object_rows;
        for (i = 0; i < floor->object_count; i++, o++, r++) {
            if (o->placement.entity_id == r->id) {
                o->flags = r->flags;
            }
        }
        floor->object_placement &= ~2U;
        current_floor_object_set_count = floor->object_count;
    }
    bytes = floor->enemy_count * 0x48;
    if (bytes > 0) {
        bytes = (bytes + 0x1F) & ~0x1F;
        current_floor_enemy_set_rows = (EnemySetRecord *)TQuestVmDownLoadServer::alloc(bytes);
    }
    if (current_floor_enemy_set_rows != NULL) {
        floor_set_archive_pool->transfer(floor_set_archives[index].enemies, current_floor_enemy_set_rows, bytes, 1);
        e = current_floor_enemy_set_rows;
        r2 = floor->enemy_rows;
        for (j = 0; j < floor->enemy_count; j++, e++, r2++) {
            if (e->placement.id == r2->id) {
                e->flags = r2->flags;
            }
        }
        floor->enemy_placement &= ~4U;
        current_floor_enemy_set_count = floor->enemy_count;
    }
}

void init_item_drop_tables(void) {
    s32 i;
    s32 k;

    floor_set_flags = 0;
    object_set_row_buffer = 0;
    enemy_set_row_buffer = 0;
    floor_set_archive_pool = 0;
    floor_saved_row_heap = 0;
    floor_set_archive_pool = new AramPool(item_drop_memory_pool_ar_addr, item_drop_memory_pool_size, 0x40);
    for (i = 0; i < 18; i++) {
        floor_set_archives[i].objects = NULL;
        floor_set_archives[i].enemies = NULL;
    }
    floor_saved_row_heap = new THeap(0xA000, 0x20);
    memset(floor_enemy_group_table, 0, 0x1B0);
    memset(floor_object_set_counts, 0, 0x48);
    memset(floor_enemy_set_counts, 0, 0x48);
    memset(TLobby__data_80513D10, 0, 0x24);
    quest_object_entries = (QuestObjectEntry *)alloc_zeroed_array(0xBA0, sizeof(QuestObjectEntry));
    enemy_state_records = (EnemyStateRecord *)alloc_zeroed_array(0xB50, sizeof(EnemyStateRecord));
    k = 0;
    for (i = 0; i < 0xBA0; i++) {
        quest_object_entries[i].drop_id_base = k++ + 0x100;
    }
    for (i = 0; i < 0xB50; i++) {
        enemy_state_records[i].drop_id = k++ + 0x100;
    }
    object_condition_count = 0;
    enemy_condition_count = 0;
    floor_decoration_rows = 0;
    floor_decoration_rows_b = NULL;
    floor_decoration_row_count = 0;
    floor_decoration_row_count_b = 0;
    lbl_805D6100 = 0;
}

void free_item_drop_memory_pool() {  }

void alloc_item_drop_memory_pool() {
    item_drop_memory_pool_size = 0x100000;
    item_drop_memory_pool_ar_addr = ARAlloc(0x100000);
}

EnemySetRecord *get_loaded_enemy_set_rows() { return current_floor_enemy_set_rows; }

FloorObjectSetRow *get_loaded_object_set_rows() { return current_floor_object_set_rows; }

