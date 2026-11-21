#ifndef PSO_MAP_TOBJMAPCSN_H
#define PSO_MAP_TOBJMAPCSN_H

#include "types.h"
#include "pso/map/CsnGeometry.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"

class TMapCsnCtrl;

// Defined by TMapCsnCtrl.cpp, whose .sdata and .rodata it opens.
extern const char *TObjMapCsn__class_name;

// object set data passed (as an address) to TObjMapCsn::create
struct MapCsnSetData {
    u8 pad_0[0xC];
    Vec position;
    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
    Vec scale;
    s32 params[2];
};

struct TObjMapCsn : public TObjCollidable {
    TObjMapCsn(TObject *parent, void *set_data);
    virtual ~TObjMapCsn();
    CsnGroup collision_group;
    CsnModel collision_model;
    CsnFace collision_faces[8];
    Vec collision_vertices[8];
    virtual void render();
    void update_state();
    s32 build_box_triangles();
    static TObjMapCsn *create(void *set_data);
    static TMapCsnCtrl *get_collision_controller();
    void*init();
    static s32 init_and_return(s32 arg0);
};

typedef char TObjMapCsnGroupOffset[offsetof(TObjMapCsn, collision_group) == 0xAC ? 1 : -1];
typedef char TObjMapCsnModelOffset[offsetof(TObjMapCsn, collision_model) == 0xC4 ? 1 : -1];
typedef char TObjMapCsnFacesOffset[offsetof(TObjMapCsn, collision_faces) == 0xD4 ? 1 : -1];
typedef char TObjMapCsnVerticesOffset[offsetof(TObjMapCsn, collision_vertices) == 0x1F4 ? 1 : -1];

typedef char TObjMapCsn_size[sizeof(TObjMapCsn) == 0x254 ? 1 : -1];
#endif
