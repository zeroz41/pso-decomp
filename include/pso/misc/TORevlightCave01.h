#ifndef PSO_MISC_TOREVLIGHTCAVE01_H
#define PSO_MISC_TOREVLIGHTCAVE01_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

class TORevlightCave01 : public TObjMapObject {
public:
    TORevlightCave01(TObject *parent, void *set_data);
    virtual ~TORevlightCave01();
    virtual void run_task();
    virtual void render();
    void update_demo();
    static void *create(void *set_data);
    static void release_static_instance();
    static void load_shared_resource();
    s32 spin_angle;  // y angle of the turning child node
    s32 spin_speed;  // angle added per frame: scale.x degrees
};

typedef char TORevlightCave01_size[sizeof(TORevlightCave01) == 0xD0 ? 1 : -1];
#endif
