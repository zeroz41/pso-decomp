#ifndef PSO_ITEM_TITEMLOAD_H
#define PSO_ITEM_TITEMLOAD_H

#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

struct NJS_OBJECT;
struct AnimationMotion;
struct GinjaTextureList;

// One loaded ItemModel.afs file as TItemLoad::find_node_by_id hands it out:
// the file's NJCM models, its NJTL texture list and its NMDM motion.
struct ItemModelResource {
    ItemModelResource();

    NJS_OBJECT *models[4];
    GinjaTextureList *texlist;
    NJS_MOTION *motion;
};

// An AFS archive opened through ADXF: the partition info block (sized for
// nfiles files, as ADXF_CALC_PTINFO_SIZE does) and the file open in it.
// Name inferred from what it calls.
class AfsPartition {
public:
    void *partition_info;
    void *handle;
    s32 partition_id;
    s32 size_sectors;
    s32 ready;

    AfsPartition(const char *path, s32 partition_id, s32 nfiles);
    virtual ~AfsPartition();
    void close();
    void *open(s32 index);
    void read(s32 buffer);
    s32 get_stat();
    s32 get_size_sectors();
};

// Reads one file of an AFS partition into the shared compressed work buffer
// and hands it to on_loaded (update_state drives it). Name inferred.
class AfsFileLoader : public AfsPartition {
public:
    s32 state;
    FlagWord flags;
    s32 file_index;

    AfsFileLoader(const char *path, s32 partition_id, s32 nfiles);
    virtual ~AfsFileLoader();
    virtual void on_loaded();
    void reset_ring_state();
    void update_state();
    s32 begin_load(s32 index);
    void reset_state();
    void update_ring();
    void update_load_state();
    void advance_load_state();
    s32 is_loaded();
};

// Loads a GVM texture archive of ItemTexture.afs into a texture list (the
// item_texture_archive_loader). Name from the archive it loads.
class ItemTextureArchiveLoader : public AfsFileLoader {
public:
    GinjaTextureList *texlist;

    ItemTextureArchiveLoader(const char *path, s32 partition_id, s32 nfiles);
    virtual ~ItemTextureArchiveLoader();
    virtual void on_loaded();
    void begin_load_if_pending(GinjaTextureList *dst, s32 index);
};

// Loads one ItemModel.afs file and splits it into its NJCM, NJTL and NMDM
// chunks (the item_model_chunk_loader). Name from the archive it loads.
class ItemModelChunkLoader : public AfsFileLoader {
public:
    u8 *buffer;
    GinjaTextureList *texlist;
    NJS_OBJECT *models[4];
    NJS_MOTION *motion;

    ItemModelChunkLoader(const char *path, s32 partition_id, s32 nfiles);
    virtual ~ItemModelChunkLoader();
    virtual void on_loaded();
    void start_load_with_id(u8 *dst, s32 index);
    NJS_MOTION *get_motion();
    GinjaTextureList *get_texlist();
    NJS_OBJECT *get_model(s32 i);
};

// The task request_item_model_load starts for one model slot: loads the
// model file, then its textures, under TItemLoad's model load task root.
// Name inferred from that root.
class TItemModelLoadTask : public TObject {
public:
    s32 slot;
    s32 state;
    s32 model_index;
    s32 texture_index;
    ItemModelResource resource;

    TItemModelLoadTask(TObject *parent, s32 slot_index, s32 model, s32 texture);
    virtual ~TItemModelLoadTask();
    virtual void run_task();
    s32 get_slot();
    ItemModelResource *get_resource();
    BOOL is_done();
};
typedef char TItemModelLoadTask_size[sizeof(TItemModelLoadTask) == 0x44 ? 1 : -1];

class TItemLoad : public TObject {
public:
    TItemLoad(TObject *parent);
    virtual ~TItemLoad();
    virtual void run_task();
    static void update_all();
    static void free_all_models();
    static void alloc_all_models();
    static s32 decompress_buffer(void *dst);
    static void free_work_buffer();
    static void alloc_work_buffer();
    static s32 has_resource_id(s32 id);
    static void get_item_texture_list(s32 index, GinjaTextureList **texlist);
    static void get_item_model(s32 index, NJS_OBJECT **model);
    static void get_armor_effect_model(NJS_OBJECT **model, GinjaTextureList **texlist, AnimationMotion **motion);
    static void get_drop_model(u8 index, NJS_OBJECT **model, GinjaTextureList **texlist);
    static ItemModelResource *find_node_by_id(s32 id);
    static void release_resource_by_id(s32 id);
    static void update();
    static void free_all();
    static void init_resources();
    static void create();
};

// Starts loading the model of `item` into a free slot; returns the slot or -1.
s32 request_item_model_load(u8 *item);

#endif
