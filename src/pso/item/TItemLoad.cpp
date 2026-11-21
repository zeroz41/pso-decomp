#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemLoad_8010FDF0.h"
#include "pso/item/TUnk_8049C658.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/unk/text_800F7DAC.h"
#include "pso/unk/text_803CC294.h"
#include "pso/weapon/TItemAttacker.h"

// The loaders are written from their last function back: the unit is built
// with deferred code generation, which emits functions in reverse order.

extern "C" {
// No shared declarations yet: adxf_get_stat and load_gvm_texture_archive are
// declared per caller, TLobby_801E2F94.h gives the two partition helpers the
// wrong parameters and text_800F7D30.h gives prs_decompress_alloc two.
s32 adxf_get_stat(void *handle);
s32 load_gvm_texture_archive(s32 data, NJS_TEXLIST *texlist);
void *TLobby__sub_801E38A0(saddr data, u32 *pos, s32 *tag, u8 *dst, s32 *size);
void TLobby__sub_801E3E9C(s32 partition_id, const char *path, void *partition_info, s32);
s32 prs_decompress_alloc(s32 src, u32 dst, s32 size);
}

__declspec(section ".data") const char *item_model_names[15] = {
    "gun_bullet.gj", "armor_scan.gj", "ixm_box01.gj", "ixm_box02.gj", "ixm_box03.gj", "ixm_box04.gj", "ixm_box05.gj",
    "ixm_box06.gj", "ixm_box07_gift.gj", "ixm_box08_xmas.gj", "ixm_box09_egg.gj", "ixm_box10_pumpkin.gj",
    "ixm_box11_flower.gj", "wxmR04_d_t_efect.gj", NULL
};
__declspec(section ".data") const char *item_motion_names[2] = { "armor_scan.njm", NULL };
BmlResourceDescriptor item_bml_resource_descriptor = { "item.bml", item_model_names, item_motion_names, 14, 1 };

// Per item class (item[0]) offsets added to the PMT record's model and
// texture file indices.
const s16 item_class_model_offsets[4] = { 0, 0x10A, 0xC7, 0 };
const s16 item_class_texture_offsets[4] = { 0, 0x11F, 0xDC, 0 };

const char *item_texture_archive_path = "ItemTexture.afs";
const char *item_model_archive_path = "ItemModel.afs";
const char *item_load_tmp_buffer = "ItemLoad";
const char *TItemLoad__name = "TItemLoad";

BmlResource *TItemLoad__bml_resource;
TObject *TItemLoad__model_load_task_root;
TObject *TItemLoad__completed_model_load_task_root;
s32 *TItemLoad__model_slot_in_use;
s32 item_load_resource_handle;
u8 *item_load_compressed_work_buffer;
s32 item_load_work_buffer_busy;
ItemTextureArchiveLoader *item_texture_archive_loader;
ItemModelChunkLoader *item_model_chunk_loader;
u8 *item_load_model_buffer;

// The texture name every NJTL entry of a loaded model is pointed at.
u8 item_blank_texture_name[32];

TItemLoad::~TItemLoad() {}

BOOL TItemModelLoadTask::is_done() { return state == 0; }

ItemModelResource *TItemModelLoadTask::get_resource() { return &resource; }

s32 TItemModelLoadTask::get_slot() { return slot; }

s32 AfsPartition::get_size_sectors() { return size_sectors; }

s32 AfsPartition::get_stat() { return adxf_get_stat(handle); }

void AfsFileLoader::on_loaded() {}

ItemModelResource::ItemModelResource() {
    s32 i;
    for (i = 0; i < 4; i++) {
        models[i] = NULL;
    }
    texlist = NULL;
    motion = NULL;
}

s32 AfsFileLoader::is_loaded() { return test_flags_any(&flags.bits, 2); }

NJS_OBJECT *ItemModelChunkLoader::get_model(s32 i) { return models[i]; }

NJS_TEXLIST *ItemModelChunkLoader::get_texlist() { return texlist; }

void *ItemModelChunkLoader::get_motion() { return motion; }

void TItemLoad::create() {
    new TItemLoad(tl_05);
}

void TItemLoad::init_resources() {
    BmlResource *resource;
    s32 *slots;
    s32 i;
    TItemLoad::alloc_work_buffer();
    TItemLoad::alloc_all_models();
    resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &item_bml_resource_descriptor, 0, 0, 0);
    }
    TItemLoad__bml_resource = resource;
    TItemLoad__completed_model_load_task_root = new TObject(NULL);
    TItemLoad__model_load_task_root = new TObject(NULL);
    slots = (s32 *)mem_alloc(0x30);
    TItemLoad__model_slot_in_use = slots;
    item_load_resource_handle = 0;
    if (slots != NULL) {
        for (i = 0; i < 12; i++) {
            TItemLoad__model_slot_in_use[i] = 0;
        }
    }
}

void TItemLoad::free_all() {
    mem_free(TItemLoad__model_slot_in_use);
    delete TItemLoad__model_load_task_root;
    delete TItemLoad__completed_model_load_task_root;
    free_bin_model_request(TItemLoad__bml_resource, 1);
    item_load_resource_handle = 0;
    TItemLoad__bml_resource = NULL;
    TItemLoad__model_load_task_root = NULL;
    TItemLoad__completed_model_load_task_root = NULL;
    TItemLoad__model_slot_in_use = NULL;
    TItemLoad::free_all_models();
    TItemLoad::free_work_buffer();
}

TItemLoad::TItemLoad(TObject *parent) : TObject(parent) {
    m_name = TItemLoad__name;
    disallow_rendering();
}

void TItemLoad::run_task() {
    update();
}

void TItemLoad::update() {
    TItemModelLoadTask *task;

    TItemLoad::update_all();
    if (TItemLoad__model_load_task_root != NULL && TItemLoad__completed_model_load_task_root != NULL) {
        task = (TItemModelLoadTask *)TItemLoad__model_load_task_root->m_down;
        if (task != NULL) {
            task->run_task();
            if (task->is_done() == 1) {
                task->set_parent(TItemLoad__completed_model_load_task_root);
            }
        }
    }
}

void TItemLoad::release_resource_by_id(s32 id) {
    TObject *roots[2] = { TItemLoad__completed_model_load_task_root, TItemLoad__model_load_task_root };
    s32 i;
    TItemModelLoadTask *task;
    for (i = 0; i != 2; i++) {
        if (roots[i] != NULL) {
            for (task = (TItemModelLoadTask *)roots[i]->m_down; task != NULL; task = (TItemModelLoadTask *)task->m_next) {
                if (id == task->get_slot()) {
                    delete task;
                    TItemLoad__model_slot_in_use[id] = 0;
                    return;
                }
            }
        }
    }
}

ItemModelResource *TItemLoad::find_node_by_id(s32 id) {
    TItemModelLoadTask *task;
    if (TItemLoad__completed_model_load_task_root != NULL) {
        for (task = (TItemModelLoadTask *)TItemLoad__completed_model_load_task_root->m_down; task != NULL;
             task = (TItemModelLoadTask *)task->m_next) {
            if (id == task->get_slot()) {
                return task->get_resource();
            }
        }
    }
    return NULL;
}

s32 request_item_model_load(u8 *item) {
    ItemPmtHeader *parm;
    s32 model;
    s32 texture;
    s32 i;
    if (item != NULL) {
        parm = (ItemPmtHeader *)lookup_item_pmt_record(item);
        if (parm != NULL) {
            model = parm->model;
            texture = parm->texture;
            if (model != -1 && texture != -1) {
                model += item_class_model_offsets[item[0]];
                texture += item_class_texture_offsets[item[0]];
                if (TItemLoad__model_load_task_root != NULL && TItemLoad__model_slot_in_use != NULL) {
                    for (i = 0; i < 12; i++) {
                        if (TItemLoad__model_slot_in_use[i] == 0) {
                            TItemLoad__model_slot_in_use[i] = 1;
                            new TItemModelLoadTask(TItemLoad__model_load_task_root, i, model, texture);
                            return i;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

void TItemLoad::get_model_ids(u8 index, s32 *model, s32 *texlist) {
    if ((model != NULL) && (texlist != NULL)) {
        *model = get_bml_model(TItemLoad__bml_resource, index + 2);
        *texlist = get_bml_texlist(TItemLoad__bml_resource, 0);
    }
}

void TItemLoad::get_item_params(s32 *model, s32 *texlist, s32 *motion) {
    if ((model != NULL) && (texlist != NULL) && (motion != NULL)) {
        *model = get_bml_model(TItemLoad__bml_resource, 1);
        *texlist = get_bml_texlist(TItemLoad__bml_resource, 0);
        *motion = (saddr)get_bml_motion(TItemLoad__bml_resource, 0);
    }
}

void TItemLoad::lookup_item_data(s32 index, s32 *model) {
    if (model != NULL) {
        *model = get_bml_model(TItemLoad__bml_resource, index);
    }
}

void TItemLoad::get_data_entry(s32 index, s32 *texlist) {
    if (texlist != NULL) {
        *texlist = get_bml_texlist(TItemLoad__bml_resource, 0);
    }
}

s32 TItemLoad::has_resource_id(s32 id) {
    TItemModelLoadTask *task;
    if (TItemLoad__completed_model_load_task_root != NULL) {
        for (task = (TItemModelLoadTask *)TItemLoad__completed_model_load_task_root->m_down; task != NULL;
             task = (TItemModelLoadTask *)task->m_next) {
            if (id == task->get_slot()) {
                return 1;
            }
        }
    }
    return 0;
}

AfsPartition::AfsPartition(const char *path, s32 id, s32 nfiles) {
    partition_info = mem_alloc((((nfiles + 1) * 2) + 0x116) & ~3);
    partition_id = id;
    handle = NULL;
    size_sectors = 0;
    TLobby__sub_801E3E9C(id, path, partition_info, 0);
    ready = 1;
}

AfsPartition::~AfsPartition() {
    close();
    mem_free(partition_info);
}

void *AfsPartition::open(s32 index) {
    if (ready == 1) {
        close();
        handle = TLobby::adxf_open_afs(partition_id, index);
        if (handle != NULL) {
            size_sectors = adxf_get_fsize_sct((u8 *)handle);
        }
    }
    return handle;
}

void AfsPartition::close() {
    if (handle != NULL) {
        ((TLobby *)handle)->close_adxf_handle();
        handle = NULL;
        size_sectors = 0;
    }
}

void AfsPartition::read(s32 buffer) {
    TLobby::read_checked_align((saddr)handle, size_sectors, buffer);
}

RelocatedFile::RelocatedFile(const char *path, s32 size) {
    s32 decompressed_size;
    saddr item_buff;

    buffer = NULL;
    root = NULL;
    if ((size != 0) && (path != NULL)) {
        buffer = mem_alloc(size);
        item_buff = create_item_buff(size);
        if ((item_buff != 0) && (buffer != NULL) && (read_disc_file(path, (void *)item_buff) > 0)) {
            decompressed_size = prs_decompress_alloc(item_buff, (uaddr)buffer, size);
            TUnk_8049C658 file;
            file.data = (u8 *)buffer;
            file.size = decompressed_size;
            root = apply_rel_relocations(&file);
        }
        TItemBuff__ct();
    }
}

RelocatedFile::~RelocatedFile() {
    mem_free(buffer);
}

void TItemLoad::alloc_work_buffer() {
    item_load_compressed_work_buffer = (u8 *)mem_alloc(0x6000);
    item_load_work_buffer_busy = 0;
}

void TItemLoad::free_work_buffer() {
    mem_free(item_load_compressed_work_buffer);
    item_load_compressed_work_buffer = NULL;
}

s32 TItemLoad::decompress_buffer(u32 dst) {
    if ((item_load_compressed_work_buffer != NULL) && (dst != 0)) {
        return prs_decompress_buffer((saddr)item_load_compressed_work_buffer, dst);
    }
    return 0;
}

AfsFileLoader::AfsFileLoader(const char *path, s32 id, s32 nfiles) : AfsPartition(path, id, nfiles) {
    state = 0;
    flags.reset();
}

AfsFileLoader::~AfsFileLoader() {
    if (test_flags_any(&flags.bits, 4) != 0) {
        item_load_work_buffer_busy = 0;
    }
}

void AfsFileLoader::advance_load_state() {
    if (test_flags_any(&flags.bits, 4) == 0) {
        if (item_load_work_buffer_busy == 1) {
            return;
        }
        item_load_work_buffer_busy = 1;
        flags.set(4);
    }
    if (open(file_index) != NULL) {
        get_size_sectors();
        read((saddr)item_load_compressed_work_buffer);
        state = 2;
    }
}

void AfsFileLoader::update_load_state() {
    close();
    if (test_flags_any(&flags.bits, 1) != 0) {
        state = 1;
        return;
    }
    state = 4;
}

void AfsFileLoader::update_ring() {
    s32 stat = get_stat();
    if (stat != 2) {
        if (stat == 3) {
            flags.clear(1);
        } else {
            flags.set(1);
        }
        update_load_state();
    }
}

void AfsFileLoader::reset_state() {
    close();
    flags.set(2);
    if (test_flags_any(&flags.bits, 4) != 0) {
        item_load_work_buffer_busy = 0;
        flags.clear(4);
    }
    state = 0;
}

s32 AfsFileLoader::begin_load(s32 index) {
    if (state == 0) {
        file_index = index;
        flags.clear(2);
        state = 1;
        return 1;
    }
    return 0;
}

void AfsFileLoader::update_state() {
    switch (state) {
    case 1:
        advance_load_state();
        return;
    case 2:
        update_ring();
        return;
    case 4:
        on_loaded();
    case 3:
        return;
    }
}

void AfsFileLoader::reset_ring_state() {
    if (test_flags_any(&flags.bits, 4) != 0) {
        item_load_work_buffer_busy = 0;
        flags.clear(4);
    }
    state = 0;
    flags.reset();
}

ItemTextureArchiveLoader::ItemTextureArchiveLoader(const char *path, s32 id, s32 nfiles)
    : AfsFileLoader(path, id, nfiles) {
    texlist = NULL;
}

ItemTextureArchiveLoader::~ItemTextureArchiveLoader() {}

void ItemTextureArchiveLoader::on_loaded() {
    s32 data;

    if (TLobby::tmp_buf_is_free() == 1) {
        data = (saddr)TLobby::tmp_buf_use_req(item_load_tmp_buffer);
        TItemLoad::decompress_buffer(data);
        load_gvm_texture_archive(data, texlist);
        TLobby::tmp_buf_release(item_load_tmp_buffer);
        texlist = NULL;
        reset_state();
    }
}

void ItemTextureArchiveLoader::begin_load_if_pending(NJS_TEXLIST *dst, s32 index) {
    if ((dst != NULL) && (begin_load(index) == 1)) {
        texlist = dst;
    }
}

ItemModelChunkLoader::ItemModelChunkLoader(const char *path, s32 id, s32 nfiles) : AfsFileLoader(path, id, nfiles) {
    s32 i;
    buffer = NULL;
    for (i = 0; i < 4; i++) {
        models[i] = NULL;
    }
    texlist = NULL;
    motion = NULL;
}

ItemModelChunkLoader::~ItemModelChunkLoader() {}

void ItemModelChunkLoader::on_loaded() {
    u32 pos;
    s32 tag;
    s32 size;
    s32 data;
    u8 *dst;
    u32 total;
    s32 n;
    void *chunk;
    u32 i;
    if (TLobby::tmp_buf_is_free() == 1) {
        data = (saddr)TLobby::tmp_buf_use_req(item_load_tmp_buffer);
        dst = buffer;
        total = TItemLoad::decompress_buffer(data);
        pos = 0;
        n = 0;
        while (pos < total) {
            chunk = TLobby__sub_801E38A0(data, &pos, &tag, dst, &size);
            dst += (size + 0x20) & ~0x1F;
            switch (tag) {
            case 'NJCM':
                if (n < 4) {
                    models[n] = (NJS_OBJECT *)chunk;
                    n++;
                }
                break;
            case 'NJTL':
                if (texlist == NULL) {
                    texlist = (NJS_TEXLIST *)chunk;
                    for (i = 0; i != texlist->nbTexture; i++) {
                        texlist->textures[i].filename = item_blank_texture_name;
                    }
                }
                break;
            case 'NMDM':
                motion = chunk;
                break;
            }
        }
        TLobby::tmp_buf_release(item_load_tmp_buffer);
        buffer = NULL;
        reset_state();
    }
}

void ItemModelChunkLoader::start_load_with_id(u8 *dst, s32 index) {
    s32 i;
    if (dst != NULL && begin_load(index) == 1) {
        buffer = dst;
        texlist = NULL;
        for (i = 0; i < 4; i++) {
            models[i] = NULL;
        }
        motion = NULL;
    }
}

void TItemLoad::alloc_all_models() {
    item_texture_archive_loader = new ItemTextureArchiveLoader(item_texture_archive_path, 0xB5, 0x144);
    item_model_chunk_loader = new ItemModelChunkLoader(item_model_archive_path, 0xB4, 0x12F);
    item_load_model_buffer = (u8 *)mem_alloc(0x21000);
}

void TItemLoad::free_all_models() {
    mem_free(item_load_model_buffer);
    delete item_model_chunk_loader;
    delete item_texture_archive_loader;
    item_texture_archive_loader = NULL;
    item_model_chunk_loader = NULL;
    item_load_model_buffer = NULL;
}

void TItemLoad::update_all() {
    if (item_texture_archive_loader != NULL) {
        item_texture_archive_loader->update_state();
    }
    if (item_model_chunk_loader != NULL) {
        item_model_chunk_loader->update_state();
    }
}

TItemModelLoadTask::TItemModelLoadTask(TObject *parent, s32 slot_index, s32 model, s32 texture)
    : TObject(parent), slot(slot_index), state(0), model_index(model), texture_index(texture) {
    state = 1;
}

TItemModelLoadTask::~TItemModelLoadTask() {
    switch (state) {
    case 2:
        item_model_chunk_loader->reset_ring_state();
        break;
    case 3:
        item_texture_archive_loader->reset_ring_state();
        break;
    }
    if ((resource.texlist != NULL) && (resource.texlist->textures->texaddr != 0)) {
        free_texture_if_valid((uaddr)resource.texlist);
    }
}

void TItemModelLoadTask::run_task() {
    s32 i;

    switch (state) {
    case 1:
        if ((item_model_chunk_loader != NULL) && (item_texture_archive_loader != NULL)) {
            item_model_chunk_loader->start_load_with_id(item_load_model_buffer + slot * 0x2C00, model_index);
            state = 2;
        }
        return;
    case 2:
        if (item_model_chunk_loader->is_loaded() == 1) {
            for (i = 0; i != 4; i++) {
                resource.models[i] = item_model_chunk_loader->get_model(i);
            }
            resource.texlist = item_model_chunk_loader->get_texlist();
            resource.motion = item_model_chunk_loader->get_motion();
            if (resource.texlist != NULL) {
                state = 3;
                item_texture_archive_loader->begin_load_if_pending(resource.texlist, texture_index);
                return;
            }
            state = 0;
            return;
        }
        break;
    case 3:
        if (item_texture_archive_loader->is_loaded() == 1) {
            state = 0;
        }
        break;
    }
}
