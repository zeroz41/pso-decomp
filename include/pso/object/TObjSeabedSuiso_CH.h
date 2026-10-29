#ifndef PSO_OBJECT_TOBJSEABEDSUISO_CH_H
#define PSO_OBJECT_TOBJSEABEDSUISO_CH_H
#include "types.h"
#include "pso/object/TObjMapObject.h"

class TParticleCtrl;

// The seabed tank set object (object 0x223): four kinds, each with its own
// model, motion and particle effect; kind 3 shows its lamps while a range
// of floor switches is set.
class TObjSeabedSuiso_CH : public TObjMapObject {
public:
    TObjSeabedSuiso_CH(TObject *parent, void *set_data);
    virtual ~TObjSeabedSuiso_CH();
    virtual void run_task();
    virtual void render();
    void init_kind_params();
    void update_state();
    void scroll_kind2_uvs();
    void update_switch_lock();
    static void *create(void *set_data);

    static const char *class_name;
    static s32 last_uv_scroll_tick;

    s32 kind;          // abs(set_params[0]) clamped to 3, indexes the kind table
    u32 switch_count;  // kind 3: how many switches, from set_params[1] >> 16
    s32 first_switch;  // kind 3: the first switch, from set_params[1] & 0xFFFF
    void *kind_model;  // the kind's model
    TParticleCtrl *emitter;  // the kind's particle emitter, 0 for none
};
typedef char TObjSeabedSuiso_CH_size[sizeof(TObjSeabedSuiso_CH) == 0xDC ? 1 : -1];

#endif
