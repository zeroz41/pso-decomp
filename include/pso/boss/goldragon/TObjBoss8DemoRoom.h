#ifndef PSO_BOSS_GOLDRAGON_TOBJBOSS8DEMOROOM_H
#define PSO_BOSS_GOLDRAGON_TOBJBOSS8DEMOROOM_H

#include "pso/system/task/TObject.h"
#include "types.h"

#include "pso/system/BmlResourceDescriptor.h"
struct BmlResource;

class TObjBoss8DemoRoom : public TObject {
public:
    TObjBoss8DemoRoom(TObject *parent);
    virtual ~TObjBoss8DemoRoom();
    virtual void run_task();
    virtual void render();
public:
    static void free_static_instance();
    static void load_resource();
    static const char *name;
    static void * shared_resource_object;
    static BmlResourceDescriptor resource_desc;
};

// --- C functions defined in TObjBoss8DemoRoom_8036B654.cpp ---
// --- end of C functions

#endif
