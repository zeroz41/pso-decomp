#ifndef PSO_OBJECT_JUNGLE_TOROCKJUNGLES01_H
#define PSO_OBJECT_JUNGLE_TOROCKJUNGLES01_H

#include "types.h"

struct NJS_TEXLIST;
#include "pso/object/cave/TORockCaveBrakable.h"

struct TObjMapCsn;

struct NJS_OBJECT;
struct GinjaTextureList;

struct TORockJungleS01 : public TORockCaveBrakable {
    TORockJungleS01(ObjectSetData *set_data);
    virtual ~TORockJungleS01();
    virtual void throw_debris();
    virtual void play_break_sound();
    TObjMapCsn *map_csn;     // the rock's map collision
    static void *create(ObjectSetData *set_data);
    static NJS_OBJECT *get_model(s32 index);
    static void free_globals();
    static void load_resources();
};

LAYOUT_ASSERT(TORockJungleS01_size, sizeof(TORockJungleS01) == 0xC0);

NJS_TEXLIST *get_jungle_rock_texture_resource(s32 index);

#endif
