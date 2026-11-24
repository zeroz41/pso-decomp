#include "pso/map/MapSetArchive.h"
#include <stddef.h>
#include "pso/map/FloorPopulation.h"

#include "pso/map/ChallengeEnemySet.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/unk/TLobby_80209524.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/map/TSetManager.h"
#include "pso/unk/TLobby_8007C550.h"
#include "pso/unk/text_80209584.h"
#include "pso/system/byteswap.h"
#include "pso/unk/text_802097B0.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"
#include "pso/system/SubtractiveRng.h"
#include "pso/unk/TLobby_8020A350.h"
#include "pso/unk/TLobby_8020A568.h"
#include "pso/system/EventShuffleTable.h"
#include "pso/unk/TLobby_80209BD8.h"
#include "string.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/unk/text_8020A2AC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/text_8020A6B0.h"
#include "pso/unk/text_8020A768.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_8020AB50.h"
#include "pso/unk/TLobby_8020B03C.h"
#include "pso/unk/text_8020AD40.h"
#include "pso/unk/text_800F8A0C.h"
#include "pso/system/TGStream.h"
#include "pso/unk/TLobby_8020B334.h"
#include "pso/unk/text_8020B5CC.h"
#include "pso/unk/TLobby_803DE778.h"
#include <stdlib.h>
#include "pso/unk/TLobby_800F8AA8.h"

// ---- pso/unk/TLobby_80209524

extern "C" {

void *mem_alloc(u32 size);
void mem_free(void *memory);

EventShuffleTable *destroy_event_shuffle_table(EventShuffleTable *table, s16 delete_storage) {
    if (table != NULL) {
        mem_free(table->entries);
        ::operator delete(table->rngState);
        table->cursor = 0;
        table->count = 0;
        if (delete_storage > 0) {
            ::operator delete(table);
        }
    }
    return table;
}

}

struct Ent_802098AC;
struct SpawnRecord_8020A9C4;

SubtractiveRng *item_drop_rng;
EventShuffleTable *challenge_event_shuffle;
u8 *challenge_event_source;
u8 *lbl_805D60AC;
u8 *item_data_table_buffer;
u8 *challenge_enemy_buffer;
Ent_802098AC *lbl_805D60B8;
ChallengeFixedEvent *challenge_event_buffer;
s32 challenge_event_count;
u8 *challenge_action_buffer;
s32 challenge_action_size;
s32 challenge_event_source_size;

// ---- pso/unk/text_80209584

struct Hdr_802095EC { s32 type; s32 size; s32 id; s32 x; };

struct Hdr_8020967C { s32 type; s32 size; s32 id; s32 x; };

extern "C" {
EventShuffleTable *TLobby__sub_80209584(EventShuffleTable *table, s32 capacity) {
    void *storage = ::operator new(0xE8);
    SubtractiveRng *rng = static_cast<SubtractiveRng *>(storage);
    if (rng != NULL) {
        rng = reinterpret_cast<SubtractiveRng *>(__ct__14SubtractiveRngFv(storage));
    }
    table->rngState = rng;
    table->entries = static_cast<s32 *>(mem_alloc(capacity * sizeof(*table->entries)));
    table->cursor = 0;
    table->count = capacity;
    table->capacity = capacity;
    return table;
}
Hdr_802095EC *find_type5_header__6TLobbyFPvi(Hdr_802095EC *arg, s32 id) {
    Hdr_802095EC *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_802095EC h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 5) {
                if (h.id == id) {
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_802095EC *)((u8 *)p + h.size);
        }
    }
    return NULL;
}
Hdr_8020967C *find_chunk_by_id__6TLobbyFPvi(Hdr_8020967C *arg, s32 id) {
    Hdr_8020967C *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_8020967C h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 4) {
                if (h.id == id) {
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_8020967C *)((u8 *)p + h.size);
        }
    }
    return NULL;
}

}

// ---- pso/unk/TLobby_8020970C


void TLobby::append_swapped_u32(s32 *arg0) {
    s32 src;

    if (challenge_action_buffer != NULL) {
        src = *arg0;
        bswap_32((u32 *)&src);
        move_data((void *)(challenge_action_buffer + challenge_action_size), &src, 4);
        challenge_action_size += 4;
    }
}

void ChallengeEventCommand::append() const {
    if (challenge_action_buffer != NULL) {
        move_data(challenge_action_buffer + challenge_action_size, &opcode, 1);
        challenge_action_size += 1;
    }
}

// ---- pso/unk/text_802097B0
struct Ent_802098AC { f32 a, b, c; u32 d, e, f, g; };

struct Out_802098AC { u8 pad[0x14]; f32 a, b, c; u32 d, e, f; };

struct Hdr_802099FC { s32 table; s32 b; s32 count; s32 d; };

struct Rec_802099FC { f32 f[5]; s16 h[6]; };

struct Out_802099FC {
    u8 pad0[6];
    s16 f6;
    u8 pad8[0x2C - 8];
    f32 f[5];
    s16 f40;
    s16 f42;
};

struct Hdr_80209AEC { s32 a; s32 table; s32 c; s32 count; };

struct Ent_80209AEC { u8 b0; u8 b1; u8 weight; u8 pad; };

struct Rec_802099FC;
struct Tmp_8020994C { u8 pad[0x18]; s16 v; u8 pad2[2]; };

struct Hdr_802097B0 { s32 table; s32 data; s32 count; };

struct Ent_802097B0 { s16 id; s16 count; s32 offset; };

void init_event_shuffle_table(EventShuffleTable *table, s32 count);

s32 next_event_shuffle_entry(EventShuffleTable *s);
extern "C" {
void TLobby__sub_802099FC(Out_802099FC *arg0, s32 arg1);
Rec_802099FC *bsearch_record__6TLobbyFPvii(void *arg0, s32 n, s32 key);

void TLobby__sub_802097B0(s16 id) {
    Ent_802097B0 e;
    Hdr_802097B0 hdr = *(Hdr_802097B0 *)lbl_805D60AC;
    u8 *table;
    s32 lo;
    s32 hi;
    s32 mid;

    ((TLobby *)(&hdr))->bswap_vec3();
    table = lbl_805D60AC + hdr.table;
    lo = 0;
    hi = hdr.count - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        TLobby__sub_8020A3D0(&e, table + mid * 8);
        TLobby__sub_8020A394(&e);
        if (e.id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    TLobby__sub_8020A3D0(&e, table + lo * 8);
    TLobby__sub_8020A394(&e);
    if (e.id == id) {
        lbl_805D60B8 = (Ent_802098AC *)((uaddr)lbl_805D60AC + hdr.data + e.offset);
        init_event_shuffle_table(challenge_event_shuffle, e.count);
    }
}

void TLobby::pick_random_entry() {
    Out_802098AC *out = (Out_802098AC *)this;
    s32 i = next_event_shuffle_entry(challenge_event_shuffle);
    Ent_802098AC e = lbl_805D60B8[i];
    ((TLobby *)(&e))->swap_header_endian();
    out->a = e.a;
    out->b = e.b;
    out->c = e.c;
    out->d = e.d;
    out->e = e.e;
    out->f = e.f;
}

Rec_802099FC *bsearch_record__6TLobbyFPvii(void *arg0, s32 n, s32 key) {
    u8 *arr = (u8 *)arg0;
    u8 *e;
    Tmp_8020994C t;
    s32 lo;
    s32 hi;
    s32 mid;
    hi = n - 1;
    lo = 0;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        ((TLobby *)(&t))->copy_record_entry((saddr)(arr + mid * 32));
        TLobby__sub_8020A48C(&t);
        if (t.v < key) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    e = arr + lo * 32;
    ((TLobby *)(&t))->copy_record_entry((saddr)e);
    TLobby__sub_8020A48C(&t);
    if (t.v == key) {
        return (Rec_802099FC *)e;
    }
    return NULL;
}

void TLobby__sub_802099FC(Out_802099FC *arg0, s32 key) {
    Hdr_802099FC hdr = *(Hdr_802099FC *)item_data_table_buffer;
    Rec_802099FC *p;
    TLobby__sub_8020A568(&hdr);
    p = (Rec_802099FC *)TLobby::bsearch_record((void *)(item_data_table_buffer + hdr.table), hdr.count, key);
    if (p != NULL) {
        Rec_802099FC r = *p;
        TLobby__sub_8020A48C(&r);
        arg0->f[0] = r.f[0];
        arg0->f[1] = r.f[1];
        arg0->f[2] = r.f[2];
        arg0->f[3] = r.f[3];
        arg0->f[4] = r.f[4];
        arg0->f40 = r.h[1];
        arg0->f42 = r.h[0];
        arg0->f6 = TLobby::clamp_min_drop(r.h[4], r.h[5] + 1);
    }
}
}
void TLobby::pick_weighted_entry(s32 *arg0, s32 *arg1) {
    Hdr_80209AEC hdr = *(Hdr_80209AEC *)item_data_table_buffer;
    Ent_80209AEC *tbl;
    u32 total;
    u32 r;
    s32 i;
    s32 n;
    TLobby__sub_8020A568(&hdr);
    tbl = (Ent_80209AEC *)(item_data_table_buffer + hdr.table);
    n = hdr.count;
    total = 0;
    for (i = 0; i < n; i++) {
        total += tbl[i].weight;
    }
    r = item_drop_rng_below(item_drop_rng, total);
    for (i = 0; i < n; i++) {
        if (tbl[i].weight != 0) {
            if (r < tbl[i].weight) {
                *arg0 = tbl[i].b1;
                *arg1 = tbl[i].b0;
                return;
            }
            r -= tbl[i].weight;
        }
    }
    *arg1 = -1;
    *arg0 = -1;
}

// ---- pso/unk/TLobby_80209BD8


extern const s32 lobby_random_slot_id_table[42] = {
    68, 67, 65, 66, 64, 96, 97, 98, 99, 100, 101, 128, 129, 130,
    131, 132, 133, 160, 161, 162, 163, 164, 165, 166, 167, 168, 212, 213,
    214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 224, 225, 0,
};

s32 pick_random_slot__6TLobbyFPv(s16 *arg0) {
    s32 key;
    s32 sp8;

    TLobby::pick_weighted_entry(&key, &sp8);
    if ((key != -1) && (sp8 != -1)) {
        *arg0 = (s16) lobby_random_slot_id_table[sp8];
        TLobby__sub_802099FC((Out_802099FC *)arg0, key);
        ((TLobby *)arg0)->pick_random_entry();
        return 0;
    }
    return 1;
}


// ---- pso/unk/text_80209C58
struct Hdr_80209C58 { s32 type; s32 size; s32 id; s32 x; };

extern "C" {
Hdr_80209C58 *find_header_by_id__6TLobbyFPvi(Hdr_80209C58 *arg, s32 id) {
    Hdr_80209C58 *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_80209C58 h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 3) {
                if (h.id == id) {
                    challenge_event_source_size = h.x;
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_80209C58 *)((u8 *)p + h.size);
        }
    }
    challenge_event_source_size = -1;
    return NULL;
}

}

// ---- pso/unk/TLobby_80209CF8


// A random value in [0, max) from the item drop RNG, raised to at least min.
u32 TLobby::clamp_min_drop(u32 min, u32 max) {
    u32 value;

    value = item_drop_rng_below(item_drop_rng, max);
    if (value < min) {
        value = min;
    }
    return value;
}

struct SpawnRecord_8020A9C4 {
    s16 type;
    u16 flags;
    s16 index;
    s16 children;
    u16 reserved;
    s16 actor_id;
    s16 room;
    s16 wave;
    u8 placement[0x48 - 0x10];
};

extern "C" {
void reserve_enemy_set_actor_ids(SpawnRecord_8020A9C4 *slots, s32 count, s32 floor);
s32 init_floor_enemy_count__6TLobbyFlPUcUl(s32 floor, u8 *slots, s32 size);
}

#pragma push
#pragma dont_inline off
LAYOUT_ASSERT(ChallengeEventHeaderSize, sizeof(ChallengeEventHeader) == 0x10);
LAYOUT_ASSERT(ChallengeRandomEventSize, sizeof(ChallengeRandomEvent) == 0x18);
LAYOUT_ASSERT(ChallengeFixedEventSize, sizeof(ChallengeFixedEvent) == 0x14);
LAYOUT_ASSERT(ChallengeEnemyPlacementSize, sizeof(SpawnRecord_8020A9C4) == 0x48);
LAYOUT_ASSERT(ChallengeEnemyRoomOffset, offsetof(SpawnRecord_8020A9C4, room) == 0x0C);
LAYOUT_ASSERT(ChallengeEnemyWaveOffset, offsetof(SpawnRecord_8020A9C4, wave) == 0x0E);

void build_challenge_enemy_set(s32 floor) {
    s32 enemyOffset;
    ChallengeRandomEvent *nextEvent;
    u32 commandSize;
    s32 enemyCount;
    s16 wave;
    s16 id;
    s32 eventIndex;
    s32 waves;
    s32 enemies;
    u32 addedSize;
    u8 *output;
    s32 area;
    s32 nextId;

    ChallengeEventHeader input = *reinterpret_cast<const ChallengeEventHeader *>(challenge_event_source);
    input.swap_endian();
    nextEvent = reinterpret_cast<ChallengeRandomEvent *>(challenge_event_source + input.eventOffset);
    commandSize = challenge_event_source_size -
                  (input.eventCount * sizeof(ChallengeRandomEvent) + sizeof(ChallengeEventHeader));

    memset(challenge_enemy_buffer, 0, ChallengeEnemyBufferSize);
    memset(challenge_event_buffer, 0, ChallengeEventBufferSize);
    challenge_event_count = 0;
    memset(challenge_action_buffer, 0, ChallengeCommandBufferSize);
    challenge_action_size = enemyOffset = 0;
    enemyCount = 0;
    ChallengeRandomEvent event;
    for (eventIndex = 0; eventIndex < input.eventCount; ++eventIndex) {
        TLobby__sub_8020A618(&event, nextEvent);
        event.swap_endian();
        waves = TLobby::clamp_min_drop(1, event.maxWaves + 1);
        wave = event.wave;
        id = event.id;
        while (waves-- > 0) {
            enemies = TLobby::clamp_min_drop(event.minEnemies, event.maxEnemies + 1);
            TLobby__sub_802097B0(event.room);
            while (enemies-- > 0) {
                u8 *placement = challenge_enemy_buffer + enemyOffset;
                if (TLobby::pick_random_slot(reinterpret_cast<s16 *>(placement)) == 0) {
                    reinterpret_cast<SpawnRecord_8020A9C4 *>(challenge_enemy_buffer + enemyOffset)->wave = wave;
                    reinterpret_cast<SpawnRecord_8020A9C4 *>(challenge_enemy_buffer + enemyOffset)->room = event.room;
                    ++enemyCount;
                    enemyOffset += sizeof(SpawnRecord_8020A9C4);
                }
            }

            if (waves > 0) {
                challenge_event_buffer[challenge_event_count].id = id;
                challenge_event_buffer[challenge_event_count].flags = event.flags;
                challenge_event_buffer[challenge_event_count].eventType = event.eventType;
                challenge_event_buffer[challenge_event_count].room = event.room;
                challenge_event_buffer[challenge_event_count].wave = wave;
                challenge_event_buffer[challenge_event_count].delay =
                    TLobby::clamp_min_drop(event.minDelay, event.maxDelay + 1);
                challenge_event_buffer[challenge_event_count].commandOffset = commandSize + challenge_action_size;

                // When this wave ends, its action stream triggers the next event.
                id = event.id + 10000 + wave;
                ChallengeEventCommand command;
                command.opcode = ChallengeEventCommand::TriggerEvent;
                command.append();
                nextId = static_cast<u16>(id);
                TLobby::append_swapped_u32(&nextId);
                command.opcode = ChallengeEventCommand::Stop;
                command.append();
                ++challenge_event_count;
                ++wave;
            }
        }

        // The final wave uses the original event's action stream.
        TLobby__sub_8020A618(&event, nextEvent);
        event.swap_endian();
        challenge_event_buffer[challenge_event_count].id = id;
        challenge_event_buffer[challenge_event_count].flags = event.flags;
        challenge_event_buffer[challenge_event_count].eventType = event.eventType;
        challenge_event_buffer[challenge_event_count].room = event.room;
        challenge_event_buffer[challenge_event_count].wave = wave;
        challenge_event_buffer[challenge_event_count].delay = TLobby::clamp_min_drop(event.minDelay, event.maxDelay + 1);
        ++nextEvent;
        challenge_event_buffer[challenge_event_count].commandOffset = event.commandOffset;
        ++challenge_event_count;
    }

    if (enemyCount > 0) {
        area = get_floor_area(floor);
        reserve_enemy_set_actor_ids(
            reinterpret_cast<SpawnRecord_8020A9C4 *>(challenge_enemy_buffer), enemyCount, area);
        TLobby::init_floor_enemy_count(floor, challenge_enemy_buffer, enemyCount * sizeof(SpawnRecord_8020A9C4));
    }

    if (challenge_event_count > 0) {
        addedSize = (challenge_action_size + 3) & ~3;
        output = TLobby::alloc_heap_slot(
            floor, sizeof(ChallengeEventHeader) + challenge_event_count * sizeof(ChallengeFixedEvent) +
                       commandSize + addedSize);
        if (output != NULL) {
            // The original copies all 16 bytes and leaves the format word unwritten.
            ChallengeEventHeader header;
            header.eventOffset = sizeof(ChallengeEventHeader);
            header.eventCount = challenge_event_count;
            header.commandOffset = challenge_event_count * sizeof(ChallengeFixedEvent) + sizeof(ChallengeEventHeader);
            move_data(output, &header, sizeof(header));
            if (challenge_event_count > 0) {
                output += sizeof(header);
                move_data(output, challenge_event_buffer, challenge_event_count * sizeof(ChallengeFixedEvent));
            }
            if (static_cast<s32>(commandSize) > 0) {
                output += challenge_event_count * sizeof(ChallengeFixedEvent);
                move_data(output, challenge_event_source + input.commandOffset, commandSize);
            }
            if (static_cast<s32>(addedSize) > 0) {
                    u8 *tail = output;
                tail += commandSize;
                move_data(tail, challenge_action_buffer, addedSize);
            }
        }
    }
}
#pragma pop

extern "C" {

void TLobby::init_buffers(int id, u8 *quest) {
    Hdr_802095EC *items;

    challenge_event_source = (u8 *)TLobby::find_header_by_id((Hdr_80209C58 *)quest, id);
    lbl_805D60AC = (u8 *)TLobby::find_chunk_by_id((Hdr_8020967C *)quest, id);
    items = find_type5_header__6TLobbyFPvi((Hdr_802095EC *)quest, id);
    item_data_table_buffer = (u8 *)items;
    if (challenge_event_source != NULL && lbl_805D60AC != NULL && items != NULL) {
        challenge_enemy_buffer = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(ChallengeEnemyBufferSize));
        challenge_event_buffer = static_cast<ChallengeFixedEvent *>(TQuestVmDownLoadServer::alloc(ChallengeEventBufferSize));
        challenge_event_count = 0;
        challenge_action_buffer = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(ChallengeCommandBufferSize));
        challenge_action_size = 0;
        build_challenge_enemy_set(id);
        safe_free(challenge_action_buffer);
        safe_free(challenge_event_buffer);
        challenge_event_buffer = NULL;
        safe_free(challenge_enemy_buffer);
        challenge_enemy_buffer = NULL;
    }
}

void TLobby::free_boss4rock() {
    destroy_event_shuffle_table(challenge_event_shuffle, 1);
    challenge_event_shuffle = NULL;
    ::operator delete(item_drop_rng);
    item_drop_rng = 0;
}

// ---- pso/unk/text_8020A2AC
s32 __cvt_fp2unsigned(f32);
saddr item_drop_server_seed;
s32 lbl_805D60D4;
s32 map_set_data_handle_a;
s32 map_set_data_handle_b;
s32 map_set_object_id_counter;
s32 next_enemy_set_actor_id;
s32 map_object_id_counter;
s32 map_set_enemy_id_counter;
u8 *map_set_file_buffer;
s32 map_set_file_buffer_size;
void TLobby__sub_8020A2AC(void) {
    SubtractiveRng *temp_r3;
    SubtractiveRng *var_r0;
    static const f32 seed_scale = 4294967296.0f;
    static const f32 rand_reciprocal = 3.0517578e-05f;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        item_drop_server_seed = __cvt_fp2unsigned(seed_scale * (rand_reciprocal * (f32)rand()));
    }
    temp_r3 = static_cast<SubtractiveRng *>(::operator new(sizeof(SubtractiveRng)));
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = temp_r3->reseed(item_drop_server_seed);
    }
    item_drop_rng = var_r0;
    EventShuffleTable *table = static_cast<EventShuffleTable *>(::operator new(sizeof(EventShuffleTable)));
    if (table != NULL) {
        table = TLobby__sub_80209584(table, 0x20);
    }
    challenge_event_shuffle = table;
}

}

// ---- pso/unk/TLobby_8020A350

void TLobby::bswap_quad_word() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }

void TLobby__sub_8020A394(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); bswap_32((u32 *)((char*)p + 0x4)); }

void TLobby__sub_8020A3D0(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
}

void TLobby::bswap_vec3() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void TLobby::swap_header_endian() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_32((u32 *)((char*)this + 0x14)); bswap_16((u16 *)((char*)this + 0x18)); bswap_16((u16 *)((char*)this + 0x1a)); }

void TLobby__sub_8020A48C(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); bswap_32((u32 *)((char*)p + 0x10)); bswap_16((u16 *)((char*)p + 0x14)); bswap_16((u16 *)((char*)p + 0x16)); bswap_16((u16 *)((char*)p + 0x18)); bswap_16((u16 *)((char*)p + 0x1a)); bswap_16((u16 *)((char*)p + 0x1c)); bswap_16((u16 *)((char*)p + 0x1e)); }

// ---- pso/unk/text_8020A508

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

void TLobby::copy_record_entry(saddr arg1) {
    saddr arg0 = (saddr)this;
    *(ByteBlock_14 *)(arg0) = *(const ByteBlock_14 *)(arg1);
    *(s16 *)((s8 *)arg0 + 0x14) = (s16) *(s16 *)((s8 *)arg1 + 0x14);
    *(s16 *)((s8 *)arg0 + 0x16) = (s16) *(s16 *)((s8 *)arg1 + 0x16);
    *(s16 *)((s8 *)arg0 + 0x18) = (s16) *(s16 *)((s8 *)arg1 + 0x18);
    *(s16 *)((s8 *)arg0 + 0x1A) = (s16) *(s16 *)((s8 *)arg1 + 0x1A);
    *(s16 *)((s8 *)arg0 + 0x1C) = (s16) *(s16 *)((s8 *)arg1 + 0x1C);
    *(s16 *)((s8 *)arg0 + 0x1E) = (s16) *(s16 *)((s8 *)arg1 + 0x1E);
}

// ---- pso/unk/TLobby_8020A568

void TLobby__sub_8020A568(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); }

void ChallengeRandomEvent::swap_endian() {
    bswap_32(reinterpret_cast<u32 *>(&id));
    bswap_16(reinterpret_cast<u16 *>(&flags));
    bswap_16(reinterpret_cast<u16 *>(&eventType));
    bswap_16(reinterpret_cast<u16 *>(&room));
    bswap_16(reinterpret_cast<u16 *>(&wave));
    bswap_16(reinterpret_cast<u16 *>(&minDelay));
    bswap_16(reinterpret_cast<u16 *>(&maxDelay));
    bswap_16(reinterpret_cast<u16 *>(&maxWaves));
    bswap_32(reinterpret_cast<u32 *>(&commandOffset));
}

void TLobby__sub_8020A618(ChallengeRandomEvent *dst, ChallengeRandomEvent *src) {
    dst->id = src->id;
    dst->flags = src->flags;
    dst->eventType = src->eventType;
    dst->room = src->room;
    dst->wave = src->wave;
    dst->minDelay = src->minDelay;
    dst->maxDelay = src->maxDelay;
    dst->minEnemies = src->minEnemies;
    dst->maxEnemies = src->maxEnemies;
    dst->maxWaves = src->maxWaves;
    dst->commandOffset = src->commandOffset;
}

void ChallengeEventHeader::swap_endian() {
    bswap_32(reinterpret_cast<u32 *>(&commandOffset));
    bswap_32(reinterpret_cast<u32 *>(&eventOffset));
    bswap_32(reinterpret_cast<u32 *>(&eventCount));
}

// ---- pso/unk/text_8020A6B0

void TLobby__sub_8020A6B0(s32 player) {
    s32 area = get_floor_area(player);
    s32 terrain = get_floor_map_terrain(player);
    MapSetVariant *variants;
    MapSetEntry *entries;

    variants = map_set_areas[area].variants;
    if (variants == NULL || map_set_areas[area].count - 1 < terrain) {
        return;
    }
    entries = variants[terrain].entries;
    if (entries == NULL || variants[terrain].count - 1 < 0) {
        return;
    }
    load_map_set_data(player, entries[0].object_set_name);
}

// ---- pso/unk/TLobby_8020A744


void TLobby::init_sub_objects() { TLobby::init_sub_state(); TLobby::rebuild_entry(); }


// ---- pso/unk/text_8020A768
struct Ent_8020A768 { s16 a; s16 b; u8 pad[0x48 - 4]; };

struct Name_8020A768 { char s[0x20]; };

struct Ent_8020A834 { s16 a; s16 b; u8 pad[0x44 - 4]; };

struct Name_8020A834 { char s[0x20]; };

extern "C" {
// The callers pass the signed file size as the count.
s32 load_object_set_entries__6TLobbyFlPUcUl(s32, u8 *, s32);
}
s32 load_enemy_set_file(s32 idx, const char *filename) {
    Name_8020A768 name;
    s32 size;
    Ent_8020A768 *p;
    s32 n;
    s32 i;
    s32 floor;
    replace_file_extension__6TLobbyFPvPvPv((char *)&name, (char *)filename, "e.dat");
    size = read_disc_file(name.s, map_set_file_buffer);
    if (size < 0) {
        return 0;
    }
    if (size > map_set_file_buffer_size) {
        return 0;
    }
    p = (Ent_8020A768 *)map_set_file_buffer;
    n = size / sizeof(Ent_8020A768);
    for (i = 0; i < n; i++, p++) {
        bswap_enemy_set_row(p);
        p->b = 0;
    }
    floor = get_floor_area(idx);
    reserve_enemy_set_actor_ids((struct SpawnRecord_8020A9C4 *)map_set_file_buffer, n, floor);
    init_floor_enemy_count__6TLobbyFlPUcUl(idx, map_set_file_buffer, size);
    return 1;
}
s32 load_object_set_file(s32 idx, const char *filename) {
    Name_8020A834 name;
    s32 size;
    Ent_8020A834 *p;
    s32 n;
    s32 i;
    saddr floor;
    replace_file_extension__6TLobbyFPvPvPv(name.s, (char *)filename, "o.dat");
    size = read_disc_file(name.s, map_set_file_buffer);
    if (size < 0) {
        return 0;
    }
    if (size > map_set_file_buffer_size) {
        return 0;
    }
    p = (Ent_8020A834 *)map_set_file_buffer;
    n = size / sizeof(Ent_8020A834);
    for (i = 0; i < n; i++, p++) {
        swap_object_row_endian(p);
        p->b = 0;
    }
    floor = get_floor_area(idx);
    ((TLobby *)map_set_file_buffer)->assign_object_ids(n, (void *)floor);
    load_object_set_entries__6TLobbyFlPUcUl(idx, map_set_file_buffer, size);
    return 1;
}


void load_map_set_data(s32 idx, const char *filename) {
    map_set_data_handle_a = 0;
    map_set_data_handle_b = 0;
    map_set_object_id_counter = 0;
    next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    copy_name("SET");
    floor_set_flags = 0;
    if (TLobby::init_handle(0x8000) != 0) {
        load_object_set_file(idx, filename);
        load_enemy_set_file(idx, filename);
        advance_object_id_counter((u16) map_object_id_counter);
        object_condition_count = map_set_object_id_counter;
        advance_enemy_id_counter((u16) map_set_enemy_id_counter);
        enemy_condition_count = next_enemy_set_actor_id;
        TLobby::free_data_60F0();
        floor_set_flags |= 1;
    }
    copy_name("..");
}

struct Rec_8020AA94 {
    u8 pad0[4];
    s16 f4;
    u8 pad6[2];
    s16 f8;
    u8 padA[0x44 - 0xA];
};

extern "C" {
s32 get_enemy_factory_child_count(s32, SpawnRecord_8020A9C4 *);
s32 find_floor_object_factory__6TLobbyFlPs(void *, Rec_8020AA94 *);
void reserve_enemy_set_actor_ids(SpawnRecord_8020A9C4 *lobby, s32 count, s32 floor) {
    SpawnRecord_8020A9C4 *r;
    s32 i;
    s32 n;
    for (i = 0; i < count; i++) {
        r = &lobby[i];
        r->actor_id = map_set_enemy_id_counter++ + 0x1000;
        r->index = next_enemy_set_actor_id++;
        if (r->children > 0) {
            next_enemy_set_actor_id += r->children;
            map_set_enemy_id_counter += r->children;
        } else {
            n = get_enemy_factory_child_count(floor, r);
            if (n > 0) {
                next_enemy_set_actor_id += n;
                map_set_enemy_id_counter += n;
                r->children = n;
            }
        }
    }
}
void TLobby::assign_object_ids(s32 arg1, void *lobby) {
    s32 i;
    s32 r;
    for (i = 0; i < arg1; i++) {
        ((Rec_8020AA94 *)this)[i].f8 = map_object_id_counter++ + 0x4000;
        ((Rec_8020AA94 *)this)[i].f4 = map_set_object_id_counter++;
        r = find_floor_object_factory__6TLobbyFlPs(lobby, &((Rec_8020AA94 *)this)[i]);
        if (r >= 0) {
            map_set_object_id_counter += r;
            map_object_id_counter += r;
        }
    }
}

// ---- pso/unk/TLobby_8020AB30

int TLobby::rebuild_entry() { return clear_record_flags_a(); }

}

// ---- pso/unk/text_8020AB50

s32 load_area_enemy_set(s32 floor, s32 area, s32 terrain, s32 entities) {
    char buf[0x28];
    const char *filename;
    s32 size;
    u8 *p;
    s32 count;
    s32 i;
    MapSetVariant *t2;
    MapSetEntry *t3;
    t2 = map_set_areas[area].variants;
    if (t2 == NULL || map_set_areas[area].count - 1 < terrain) {
        TLobby::debug_print("NOT FOUND SET");
        return 0;
    }
    t3 = t2[terrain].entries;
    if (t3 == NULL || t2[terrain].count - 1 < entities) {
        TLobby::debug_print("NOT FOUND SET");
        return 0;
    }
    filename = t3[entities].enemy_set_name;
    if (area == 0 || area == 0x12) {
        switch (get_game_play_mode()) {
        case 0:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)filename, "e.dat");
            break;
        case 1:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)filename, "e_c1.dat");
            break;
        case 2:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)filename, "e_d.dat");
            break;
        }
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)filename, "e.dat");
    }
    size = read_disc_file(buf, map_set_file_buffer);
    if (size < 0) {
        return 0;
    }
    if (size > map_set_file_buffer_size) {
        return 0;
    }
    p = map_set_file_buffer;
    count = (u32)size / 0x48;
    for (i = 0; i < count; i++, p += 0x48) {
        bswap_enemy_set_row(p);
        *(s16 *)(p + 2) = 0;
    }
    reserve_enemy_set_actor_ids((SpawnRecord_8020A9C4 *)map_set_file_buffer, count, area);
    init_floor_enemy_count__6TLobbyFlPUcUl(floor, map_set_file_buffer, size);
    return 1;
}

// ---- pso/unk/TLobby_8020AD20


int TLobby::init_sub_state() { return clear_record_flags_b(); }


// ---- pso/unk/text_8020AD40

struct Rec_8020AD40 { u8 pad0[2]; s16 f2; u8 pad4[0x40]; };

extern "C" {
}

s32 load_area_object_set(s32 arg0, saddr lobby, s32 terrain, s32 entities) {
    char name[0x20];
    MapSetVariant *subs;
    MapSetEntry *items;
    const char *filename;
    s32 len;
    Rec_8020AD40 *r;
    s32 n;
    s32 i;
    subs = map_set_areas[lobby].variants;
    if (subs == NULL || map_set_areas[lobby].count - 1 < terrain) {
        TLobby::debug_print("NOT FOUND SET");
        return 0;
    }
    items = subs[terrain].entries;
    if (items == NULL || subs[terrain].count - 1 < entities) {
        TLobby::debug_print("NOT FOUND SET");
        return 0;
    }
    filename = items[entities].object_set_name;
    if (lobby == 0 || lobby == 0x12) {
        switch (get_game_play_mode()) {
        case 0:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)filename, "o.dat");
            break;
        case 1:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)filename, "o_c1.dat");
            break;
        case 2:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)filename, "o_d.dat");
            break;
        }
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)filename, "o.dat");
    }
    len = read_disc_file(name, map_set_file_buffer);
    if (len < 0) {
        return 0;
    }
    if (len > map_set_file_buffer_size) {
        return 0;
    }
    r = (Rec_8020AD40 *)map_set_file_buffer;
    n = len / sizeof(Rec_8020AD40);
    for (i = 0; i < n; i++, r++) {
        swap_object_row_endian(r);
        r->f2 = 0;
    }
    ((TLobby *)map_set_file_buffer)->assign_object_ids((s32)n, (void *)lobby);
    load_object_set_entries__6TLobbyFlPUcUl(arg0, map_set_file_buffer, len);
    return 1;
}

s32 TLobby::load_all_floor_enemy_sets() {
    FloorMapSelection stack;
    s32 var_r31;
    var_r31 = 0;
loop_1:
    if ((get_floor_map_selection(var_r31, &stack) == 1) && (stack.area >= 0)) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        load_area_enemy_set(var_r31, stack.area, stack.terrain, stack.entities);
        goto block_6;
    }
block_6:
    var_r31 += 1;
    if (var_r31 >= 0x12) {
        advance_enemy_id_counter(((u16) map_set_enemy_id_counter));
        enemy_condition_count = next_enemy_set_actor_id;
        TLobby::sum_floor_enemy_counts();
        return 1;
    }
    goto loop_1;
}
s32 TLobby::load_all_floor_object_sets() {
    FloorMapSelection stack;
    s32 var_r31;
    var_r31 = 0;
loop_1:
    if ((get_floor_map_selection(var_r31, &stack) == 1) && (stack.area >= 0)) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        load_area_object_set(var_r31, stack.area, stack.terrain, stack.entities);
        goto block_6;
    }
block_6:
    var_r31 += 1;
    if (var_r31 >= 0x12) {
        advance_object_id_counter(((u16) map_object_id_counter));
        object_condition_count = map_set_object_id_counter;
        TLobby__sub_8020B308();
        return 1;
    }
    goto loop_1;
}

// ---- pso/unk/TLobby_8020B03C


void TLobby::free_data_60F0() {
    if (map_set_file_buffer != NULL) {
        safe_free(map_set_file_buffer);
        map_set_file_buffer = NULL;
        map_set_file_buffer_size = 0;
    }
}

s32 TLobby::init_handle(s32 size) {
    u8 *buffer = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(size));
    map_set_file_buffer = buffer;
    if (buffer != NULL) {
        map_set_file_buffer_size = size;
        return 1;
    }
    map_set_file_buffer = NULL;
    return 0;
}


void clear_map_set_data(void) {
    map_set_object_id_counter = 0;
    next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    map_set_file_buffer_size = 0;
    const char *name = (const char *)get_player_name_copy_buffer();
    if (strncmp(name, "SET", 0x10) == 0) {
        copy_name("..");
    }
}


void TLobby::load_set_gsl_files() {
    map_set_data_handle_a = 0;
    map_set_data_handle_b = 0;
    map_set_object_id_counter = 0;
    next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    map_set_file_buffer_size = 0;
    floor_set_flags = 0;
    if (TLobby::init_handle(0x8000) != 0) {
        open_gsl_archive("gsl_set_object.gsl");
        if (TLobby::load_all_floor_object_sets() == 0) {
            close_gsl_archive();
            TLobby::free_data_60F0();
            floor_set_flags |= 1;
            return;
        }
        close_gsl_archive();
        open_gsl_archive("gsl_set_enemy.gsl");
        if (TLobby::load_all_floor_enemy_sets() == 0) {
            close_gsl_archive();
            TLobby::free_data_60F0();
            floor_set_flags |= 1;
            return;
        }
        close_gsl_archive();
        TLobby::free_data_60F0();
        floor_set_flags |= 1;
    }
}

s32 TLobby::set_flags_on_matching_entries(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    LobbyFloorRows *g = &floor_enemy_group_table[arg0];
    FloorSavedSetRow *e;
    s32 n = 0;
    s32 i;
    if (g->enemy_count > 0) {
        e = g->enemy_rows;
        if (e != 0) {
            for (i = 0; i < g->enemy_count; i++, e++) {
                if (e->room == arg1 && e->wave == arg2) {
                    n++;
                    e->flags |= arg3;
                }
            }
        }
    }
    return n;
}

s32 TLobby::set_room_group_flags(s32 floor, s16 room, s16 group, s32 bits) {
    LobbyFloorRows *t = &floor_enemy_group_table[floor];
    s32 n = 0;
    FloorSavedSetRow *e;
    s32 i;
    if (t->object_count > 0) {
        e = t->object_rows;
        if (e != NULL) {
            for (i = 0; i < t->object_count; i++, e++) {
                if (e->room == room && e->wave == group) {
                    e->flags |= bits;
                    n++;
                }
            }
        }
    }
    return n;
}

s32 TLobby::sum_floor_enemy_counts() {
    s32 sum = 0;
    s32 i;
    for (i = 0; i < 18; i++) sum += floor_enemy_set_counts[i];
    return sum;
}
s32 TLobby__sub_8020B308(void) {
    s32 sum = 0;
    s32 i;
    for (i = 0; i < 18; i++) sum += floor_object_set_counts[i];
    return sum;
}

// ---- pso/unk/TLobby_8020B334

extern "C" {

EnemySetRecord *get_loaded_enemy_set_rows();
FloorObjectSetRow *get_loaded_object_set_rows();

EnemySetRecord *get_active_floor_enemy_rows(s32) { return get_loaded_enemy_set_rows(); }
FloorObjectSetRow *get_active_floor_object_rows(s32) { return get_loaded_object_set_rows(); }

// ---- pso/unk/text_8020B374
s32 TLobby::init_floor_enemy_count(s32 floor, u8 *source, u32 size) {
    if (init_quest_floor_enemies(floor, (EnemySetRecord *)source, size) == 1) {
        floor_enemy_set_counts[floor] = size / 72U;
        return 1;
    }
    floor_enemy_set_counts[floor] = -1;
    return 0;
}

s32 TLobby::load_object_set_entries(s32 arg0, u8 *rows, u32 byte_size) {
    if (TLobby::load_floor_enemy_group_entries(arg0, (FloorObjectSetRow *)rows, byte_size) == 1) {
        floor_object_set_counts[arg0] = byte_size / 68U;
        return 1;
    }
    floor_object_set_counts[arg0] = -1;
    return 0;
}

int TLobby::get_object_type(int a0) {  return floor_enemy_set_counts[a0]; }

int TLobby::get_obj_table_entry(int a0) {  return floor_object_set_counts[a0]; }

// ---- pso/unk/text_8020B47C
// Copies the received object and enemy set flags of every floor into the floor tables.
void TLobby__sub_8020B47C(FloorSetFlagsHeader *block) {
    s32 j;
    FloorSavedSetRow *row;
    s32 i;
    s16 *src;
    s32 count;

    swap_floor_set_flags_header(block);
    src = (s16 *)((u8 *)block + block->object_offset);
    for (i = 0; i < 18; i++) {
        if (floor_enemy_group_table[i].object_count > 0) {
            count = floor_enemy_group_table[i].object_count;
            row = floor_enemy_group_table[i].object_rows;
            for (j = 0; j < count; j++) {
                s16 flags = *src;
                bswap_16((u16 *)&flags);
                row->flags = flags;
                src++;
                row++;
            }
        }
    }
    src = (s16 *)((u8 *)block + block->enemy_offset);
    for (j = 0; j < 18; j++) {
        if (floor_enemy_group_table[j].enemy_count > 0) {
            row = floor_enemy_group_table[j].enemy_rows;
            count = floor_enemy_group_table[j].enemy_count;
            for (i = 0; i < count; i++) {
                s16 flags = *src;
                bswap_16((u16 *)&flags);
                row->flags = flags;
                src++;
                row++;
            }
        }
    }
}
}

// ---- pso/unk/TLobby_8020B588

void swap_floor_set_flags_header(FloorSetFlagsHeader *header) {
    bswap_32(&header->object_offset);
    bswap_32(reinterpret_cast<u32 *>(&header->object_count));
    bswap_32(&header->enemy_offset);
    bswap_32(reinterpret_cast<u32 *>(&header->enemy_count));
}
