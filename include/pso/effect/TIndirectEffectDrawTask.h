#ifndef PSO_EFFECT_TINDIRECTEFFECTDRAWTASK_H
#define PSO_EFFECT_TINDIRECTEFFECTDRAWTASK_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/scene/TScene.h"
#include <dolphin/mtx.h>

// Where a queued model is drawn: the scene node's position and rotation plus its section's.
struct IndirectDrawPlacement {
    Vec position;
    SceneSectionAngles angles;
};

// One indirect-effect draw record (0x24 bytes): a scene model the scene's render pass queues for the
// indirect effect pass.
struct IndirectDrawRecord {
    IndirectDrawPlacement placement;
    NJS_TEXLIST *texlist;
    void *model;
    u16 scene;
    u8 effect_kind;  // indirect effect kind
    u8 pad_23;

    IndirectDrawRecord &operator=(IndirectDrawRecord &other);
};

// Empties a record: drops its texture list and model.
void clear_draw_record(IndirectDrawRecord *record);

// Draws the queued records with the indirect effect and the screen capture projected on them, then
// empties the queue every frame.
class TIndirectEffectDrawTask : public TObject {
public:
    TIndirectEffectDrawTask(TObject *parent);
    virtual ~TIndirectEffectDrawTask();
    virtual void run_task();
    virtual void render();
    void bind_capture_texture();
    void reset_projection_tex_matrix();
    void setup_projection_tex_matrix();
    void store_record(IndirectDrawRecord *record);
    static void queue_record(IndirectDrawRecord *record);
    static void clear_instance_on_floor_free();
    static void clear_instance_on_floor_load();

    IndirectDrawRecord *entries;  // 16 records, mem_alloc(0x240) by the constructor
    s32 entry_count;
};
LAYOUT_ASSERT(TIndirectEffectDrawTask_size, sizeof(TIndirectEffectDrawTask) == 0x24);

#endif
