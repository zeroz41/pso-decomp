#ifndef PSO_UNK_TDEFERREDRENDERQUEUE_H
#define PSO_UNK_TDEFERREDRENDERQUEUE_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Created by TLobby::create_tasks outside split screen. TObjEneMe3Stelth, TOTrapAncient02 and TOTrapSeabed01
// queue themselves from their render() through enqueue_in_instance; render() then
// renders every queued object once and empties the queue (a deferred render list; role inferred).
class TDeferredRenderQueue : public TObject {
public:
    TDeferredRenderQueue(TObject *parent);
    virtual ~TDeferredRenderQueue();
    virtual void render();
    void clear_queue();                // empties the queue
    void render_queued();               // renders each queued object whose parents are not being destroyed
    static s32 enqueue_in_instance(TObject *object);
    void enqueue(TObject *object);   // appends to the queue while it has room
    s32 is_rendering();              // nonzero while render() runs

    static TDeferredRenderQueue *instance;       // set by the ctor, cleared by the dtor and the floor callbacks

    s32 rendering;
    TObject *queued[24];
    s32 queued_count;
};
LAYOUT_ASSERT(TDeferredRenderQueue_size, sizeof(TDeferredRenderQueue) == 0x84);

// Floor resource callbacks (TLobby's load/release table): both forget the instance.
void clear_deferred_render_queue_on_floor_free(void);
void clear_deferred_render_queue_on_floor_load(void);

#endif
