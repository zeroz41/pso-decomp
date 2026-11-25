#ifndef PSO_ITEM_TPLACEMENTSEARCH_H
#define PSO_ITEM_TPLACEMENTSEARCH_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

class TObjBase;
class PlacementQueue;
class PositionPlacementQueue;
class ItemDropQueue;
struct CollisionBodySet;
struct PendingItemDrop;

// Base of the two item placement searches: walks rings of candidate positions
// around origin until one has ground below and no player body in the way.
class TPlacementSearch : public TObject {
public:
    TPlacementSearch(TObject *parent, TObjBase *source, const Vec *pos, s32 slot);
    virtual ~TPlacementSearch();
    void set_ring(u8 index);
    void reset_placement_search_ring();
    void *find_obstruction(CollisionBodySet *probe);
    s32 step_placement_search();
    Vec *get_candidate();
    u8 get_slot();
    void set_slot_placed(PlacementQueue *queue);
    void set_slot_failed(PlacementQueue *queue);
    void clear_slot(PlacementQueue *queue);
    void finish(PlacementQueue *queue);
    s8 slot; // the queue slot this search places
    s8 ring;
    s8 sample;
    s8 count;
    u16 client_id; // get_entity_id(source), 0xFFFF without one
    s32 room;
    s32 heading;
    s32 step;
    s32 angle;
    f32 radius;
    Vec origin;
    Vec candidate;
    s32 online;
};

// Finds the spot for a position queue entry (the telepipe) and stores it.
class TPositionSearch : public TPlacementSearch {
public:
    TPositionSearch(TObject *parent, PositionPlacementQueue *queue, TObjBase *source, const Vec *pos, s32 slot);
    virtual ~TPositionSearch();
    virtual void run_task();
    static TPositionSearch *create(PositionPlacementQueue *queue, TObjBase *source, const Vec *pos, s32 slot);
    void store_position();
    PositionPlacementQueue *queue;
};
LAYOUT_ASSERT(TPositionSearch_size, sizeof(TPositionSearch) == 0x58);

// Finds the spot for a pending item drop, then drops the item there.
class TItemDropSearch : public TPlacementSearch {
public:
    TItemDropSearch(TObject *parent, ItemDropQueue *queue, TObjBase *source, const Vec *pos, s32 slot);
    virtual ~TItemDropSearch();
    virtual void run_task();
    static TItemDropSearch *create(ItemDropQueue *queue, TObjBase *source, const Vec *pos, s32 slot);
    void store_position();
    u16 get_client_id();
    PendingItemDrop *get_record();
    ItemDropQueue *queue;
};
LAYOUT_ASSERT(TItemDropSearch_size, sizeof(TItemDropSearch) == 0x58);

#endif
