// Implements both TObject and TMainTask; they were one source file. The
// out-of-line copy of the TObject.h inline allow_rendering_shadows(), whose
// only callers are in TMainTask::render_shadows, follows this file's static
// initializer together with the copies TObject::defer_render needs. A
// separate TMainTask.cpp would have emitted it at its own end.
#pragma readonly_strings on
#define TOBJECT_CPP
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/THeap.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/misc/TKeyBoardControl_803DE9C4.h"
#include "pso/misc/TLobby_803382E4.h"
#include "pso/player/TObjPlayer_80083B38.h"
#include "pso/system/debug_print.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"

extern u32 model_render_flags;

// 0 while the scene tree is drawn for geometry, particles and UI; 1 during
// the effects traversal and the deferred-object pass (see TMainTask::render).
u32 render_pass = 1;

// The original's static initializer sits before the weak copies of the
// TObject inlines this unit emits, which no compiler-generated __sinit
// reproduces, so the destructor chain and __sinit are spelled out.
struct DestructorChain {
    DestructorChain *next;
    void *destructor;
    void *object;
};
#pragma suppress_init_code on
#pragma no_static_dtors on
DestructorChain main_task_dtor_chain;
TMainTask main_task;
DestructorChain end_of_render_root_dtor_chain;
TObject end_of_render_root;
DestructorChain keyboard_task_object_dtor_chain;
TObject keyboard_task_object;
#pragma no_static_dtors reset
#pragma suppress_init_code reset

#define o(name) OBJECT_NAME(name)
OBJECT_NAMES
#undef o

#define o(var, name) const char *var##_name = #name;
TL_OBJECTS_IN_ADDRESS_ORDER
#undef o

#define o(var, name) TObject *var;
TL_OBJECTS_IN_ADDRESS_ORDER
#undef o

u32 update_flags;
u32 old_update_flags;
u32 render_flags;
u32 old_render_flags;
u32 render_shadow_flags;
u32 old_render_shadow_flags;

extern "C" {
void __sinit_TObject_cpp();
TMainTask *__ct__9TMainTaskFv(TMainTask *);
TObject *__ct__7TObjectFP7TObject(TObject *, TObject *);
void __dt__9TMainTaskFv(TMainTask *, s16);
void __dt__7TObjectFv(TObject *, s16);
void *__register_global_object(void *, void *, void *);
}
__declspec(section ".ctors") static void *const object_global_initializer = (void *)__sinit_TObject_cpp;

#pragma defer_codegen on
u32 TObject::is_render_deferred() { return m_flags & DEFER_RENDER; }

void TObject::set_render_deferred() { m_flags |= DEFER_RENDER; }

void TObject::clear_render_deferred() { m_flags &= ~DEFER_RENDER; }

void TObject::allow_rendering_shadows() { m_flags &= ~DISALLOW_RENDER_SHADOWS; }

void __sinit_TObject_cpp() {
    __register_global_object(__ct__9TMainTaskFv(&main_task),
        (void *)__dt__9TMainTaskFv, &main_task_dtor_chain);
    __register_global_object(__ct__7TObjectFP7TObject(&end_of_render_root, NULL),
        (void *)__dt__7TObjectFv, &end_of_render_root_dtor_chain);
    __register_global_object(__ct__7TObjectFP7TObject(&keyboard_task_object, NULL),
        (void *)__dt__7TObjectFv, &keyboard_task_object_dtor_chain);
}

TObject::TObject(TObject *parent) {
    m_flags = NONE;
    m_up = parent;
    m_down = NULL;
    m_name = TObject_name;
    add_parent(parent, false);
}

TObject::~TObject() {
    if (!(m_flags & DISALLOW_DESTRUCTION)) {
        m_flags |= DISALLOW_DESTRUCTION;
        _delete_children();
        remove_parent();
    }
}

void TObject::delete_children() {
    _delete_children();
}

void TObject::queue_destruction_for_each_node() {
    FOREACH_NODE(TObject, this->m_down, child) {
        child->queue_destruction();
        child->queue_destruction_for_each_node();
    }
}

void TObject::run_tasks() {
    TObject *child = this->m_down;
    while (this->m_down != NULL && child != NULL) {
        TObject *node = child;
        child = child->m_next;
        if (node->m_flags & DISALLOW_UPDATE) {
            if (node->m_flags & QUEUE_DESTRUCTION && (node->m_flags &= ~QUEUE_DESTRUCTION, !(node->m_flags & DISALLOW_DESTRUCTION))) {
                delete node;
            } else {
                if (node->m_flags & CHILD_QUEUE_DESTRUCTION) {
                    node->delete_children();
                    node->run_task();
                    node->m_flags &= ~CHILD_QUEUE_DESTRUCTION;
                }

                if (node->m_flags & SUSPEND_UPDATE) {
                    continue;
                }

                if (node->m_flags & PAUSE_UPDATE) {
                    continue;
                }
            }
        } else {
            node->run_task();
            node->run_tasks();
        }
    }
}

void TObject::render_nodes() {
    FOREACH_NODE(TObject, this->m_down, child) {
        if (!(child->m_flags & DISALLOW_RENDER)) {
            child->render();
            child->render_nodes();
        }
    }
}

void TObject::render_shadows_for_each_node() {
    FOREACH_NODE(TObject, this->m_down, child) {
        if (!(child->m_flags & DISALLOW_RENDER_SHADOWS)) {
            child->render_shadows();
            child->render_shadows_for_each_node();
        }
    }
}

void TObject::render_deferred_nodes() {
    FOREACH_NODE(TObject, this->m_down, child) {
        if (child->m_flags & DEFER_RENDER) {
            child->render();
            child->clear_render_deferred();
        }
        child->render_deferred_nodes();
    }
}

void TObject::debug_render() {

}

void TObject::set_parent(TObject *parent) {
    remove_parent();
    add_parent(parent, true);
}

void TObject::run_task() {

}

void TObject::render() {

}

void TObject::render_shadows() {

}

void TObject::debug_update() {

}

void TObject::log(const char *str) {
    debug_print(str);
}

int TObject::get_node_count() {
    TObject *child;
    int node_count = 0;
    FOREACH_NODE_NODECL(TObject, this->m_down, child) {
        node_count += child->get_node_count() + 1;
    }
    return node_count;
}

int TObject::all_parents_unqueued_for_destruction() {
    for (TObject *parent = this; parent != NULL; parent = parent->m_up) {
        if (parent->m_flags & QUEUE_DESTRUCTION) {
            return false;
        }
    }
    return true;
}

void *TObject::operator new(size_t size) {
    return obj_heap->heap_alloc(size);
}

void TObject::operator delete(void *ptr) {
    obj_heap->heap_free(ptr);
}

int TObject::defer_render() {
    if (m_flags & NO_DEFER_RENDER) {
        return false;
    }
    if ((s32)is_render_deferred() == 0) {
        set_render_deferred();
        return true;
    } else {
        clear_render_deferred();
        return false;
    }
}

TMainTask::TMainTask() : TObject(NULL) {
    m_name = TMainTask_name;
    task_flags = 0;
    reserved_20 = 0;
    reserved_24 = 0;
}

void TMainTask::init_main_task() {
    obj_heap = new THeap(0x7a000, 16);
    alt_heap = new THeap(0x17000, 16);
    #define o(var, dummy) \
        var = new TObject(this); \
        var->m_name = var##_name;
        TL_OBJECTS
    #undef o
}

TMainTask::~TMainTask() {
    delete_children();
    delete alt_heap;
    delete obj_heap;
}

void TMainTask::render_shadows() {
    tl_particlemodel->disallow_rendering_shadows();
    begin_shadow_map_pass();
    DISALLOW_OR_ALLOW_CHILD(render_shadow_flags, old_render_shadow_flags, rendering_shadows);

    set_depth_buffer_settings_3();
    set_draw_list_mask(1);
    save_depth_buffer_settings();

    render_shadows_for_each_node();
    end_shadow_map_pass();

    tl_particlemodel->allow_rendering_shadows();
    tl_particlemodel->render_shadows_for_each_node();

    restore_depth_buffer_settings();
}

void TMainTask::run_task() {
    PAUSE_OR_RESUME_CHILD(update_flags, old_update_flags);
    render_pass = 0;
    task_flags |= MAIN_TASK_UPDATING;
    run_tasks();
    task_flags &= ~MAIN_TASK_UPDATING;
    task_flags |= MAIN_TASK_UPDATED;
}

void TMainTask::render_clipout_and_fade() {
    u32 saved_render_flags;
    task_flags |= MAIN_TASK_RENDERING;

    set_depth_buffer_settings_2();
    set_draw_list_mask(1);
    save_depth_buffer_settings();
    saved_render_flags = model_render_flags;
    set_model_render_flags(1);

    tl_clipout->allow_rendering();
    tl_clipout->render_nodes();
    tl_fade->allow_rendering();
    tl_fade->render_nodes();
    tl_fadeafter->allow_rendering();
    tl_fadeafter->render_nodes();

    set_model_render_flags(saved_render_flags);
    restore_depth_buffer_settings();

    task_flags &= ~MAIN_TASK_RENDERING;
}

void TMainTask::render_scene_passes() {
    task_flags |= MAIN_TASK_SCENE_PASSES;
    render_pass = 0;
    render_geometry();
    render_pass = 1;
    render_effects();
    render_objects();
    render_pass = 0;
    render_particle_effects();
    render_after_scene();
    task_flags &= ~MAIN_TASK_SCENE_PASSES;
}

void TMainTask::render_object_layers(int mode) {
    task_flags |= MAIN_TASK_OBJECT_LAYERS;
    render_pass = 0;
    set_depth_buffer_settings_3();
    set_draw_list_mask(1);
    save_depth_buffer_settings();
    switch (mode) {
    case 0:
        tl_03->render_nodes();
        tl_04->render_nodes();
        set_draw_list_mask(3);
        tl_item_equip->allow_rendering();
        tl_item_equip->render_nodes();
        tl_item_equip->disallow_rendering();
        restore_draw_list_mask();
        break;
    case 1:
        tl_03->render_nodes();
        tl_04->render_nodes();
        break;
    case 2:
        tl_03->render_nodes();
        break;
    case 3:
        tl_04->render_nodes();
        break;
    case 4:
        set_draw_list_mask(1);
        set_chunk_render_flags(1);
        tl_item_equip->allow_rendering();
        tl_item_equip->render_nodes();
        tl_item_equip->disallow_rendering();
        clear_chunk_render_flags();
        restore_draw_list_mask();
        break;
    case 5:
        set_draw_list_mask(2);
        set_chunk_render_flags(2);
        tl_item_equip->allow_rendering();
        tl_item_equip->render_nodes();
        tl_item_equip->disallow_rendering();
        clear_chunk_render_flags();
        restore_draw_list_mask();
        break;
    }
    restore_depth_buffer_settings();
    render_pass = 1;
    set_depth_buffer_settings_1();
    set_draw_list_mask(2);
    save_depth_buffer_settings();
    restore_depth_buffer_settings();
    task_flags &= ~MAIN_TASK_OBJECT_LAYERS;
}

void TMainTask::render_task_layer_02() {
    task_flags |= MAIN_TASK_LAYER_02;
    render_pass = 0;
    set_depth_buffer_settings_3();
    set_draw_list_mask(1);
    save_depth_buffer_settings();
    tl_02->render_nodes();
    restore_depth_buffer_settings();
    render_pass = 1;
    set_depth_buffer_settings_1();
    set_draw_list_mask(2);
    save_depth_buffer_settings();
    tl_02->render_nodes();
    restore_depth_buffer_settings();
    task_flags &= ~MAIN_TASK_LAYER_02;
}

void TMainTask::render_geometry() {
    set_depth_buffer_settings_3();
    set_draw_list_mask(1);
    save_depth_buffer_settings();

    tl_03->allow_rendering();
    tl_04->allow_rendering();
    tl_06->allow_rendering();

    tl_07->disallow_rendering();
    tl_window->disallow_rendering();
    tl_particle->disallow_rendering();
    tl_particlemodel->disallow_rendering();
    tl_radermap->disallow_rendering();
    tl_clipout->disallow_rendering();
    tl_fade->disallow_rendering();
    tl_fadeafter->disallow_rendering();
    tl_item_equip->disallow_rendering();

    render_nodes();

    restore_depth_buffer_settings();
    set_draw_list_mask(1);
    set_chunk_render_flags(1);

    tl_item_equip->allow_rendering();
    tl_item_equip->render_nodes();
    clear_chunk_render_flags();
    tl_item_equip->disallow_rendering();

    restore_draw_list_mask();
}

void TMainTask::render_effects() {
    set_depth_buffer_settings_1();
    set_draw_list_mask(2);
    save_depth_buffer_settings();

    tl_03->disallow_rendering();
    tl_04->disallow_rendering();
    tl_06->disallow_rendering();

    tl_07->allow_rendering();
    tl_item_equip->disallow_rendering();

    render_nodes();

    restore_depth_buffer_settings();
}

void TMainTask::render_particle_effects() {
    set_depth_buffer_settings_1();
    set_draw_list_mask(1);
    save_depth_buffer_settings();

    tl_particle->render_nodes();
    tl_particlemodel->render_nodes();

    restore_depth_buffer_settings();
}

void TMainTask::render_ui() {
    u32 saved_render_flags;
    set_depth_buffer_settings_2();
    set_draw_list_mask(1);
    save_depth_buffer_settings();
    saved_render_flags = model_render_flags;
    set_model_render_flags(1);

    tl_window->allow_rendering();
    tl_window->render_nodes();
    tl_radermap->allow_rendering();
    tl_radermap->render_nodes();

    set_model_render_flags(saved_render_flags);
    restore_depth_buffer_settings();
}

void TMainTask::render_objects() {
    task_flags |= MAIN_TASK_DEFERRED_OBJECTS;

    tl_03->render_deferred_nodes();
    tl_04->render_deferred_nodes();

    set_draw_list_mask(0);
    set_chunk_render_flags(4);

    tl_item_equip->allow_rendering();
    tl_item_equip->render_nodes();

    restore_draw_list_mask();
    clear_chunk_render_flags();

    task_flags &= ~MAIN_TASK_DEFERRED_OBJECTS;

    set_draw_list_mask(2);
    set_chunk_render_flags(2);

    tl_item_equip->allow_rendering();
    tl_item_equip->render_nodes();
    tl_item_equip->disallow_rendering();

    clear_chunk_render_flags();
    restore_draw_list_mask();
}

void TMainTask::render_after_scene() {

}

void TMainTask::render() {
    ALLOW_OR_DISALLOW_CHILD(render_flags, old_render_flags, rendering);
    task_flags |= MAIN_TASK_RENDERING;
    render_pass = 0;
    render_geometry();
    render_pass = 1;
    render_effects();
    render_pass = 0;
    render_particle_effects();
    render_pass = 1;
    render_objects();
    render_pass = 0;
    render_after_scene();
    render_ui();
    task_flags &= ~MAIN_TASK_RENDERING;
    task_flags |= MAIN_TASK_RENDERED;
}

void TMainTask::run_tl_camera_tasks() {
    task_flags |= MAIN_TASK_UPDATING;
    tl_camera->run_tasks();
    task_flags &= ~MAIN_TASK_UPDATING;
}

void TMainTask::debug_render_overlay() {

}

void TMainTask::resume_game_layers() {
    tl_02->resume_update();
    tl_03->resume_update();
    tl_item_equip->resume_update();
    tl_loc_start->resume_update();
    tl_04->resume_update();
    tl_05->resume_update();
    tl_06->resume_update();
    tl_07->resume_update();
    tl_loc_end->resume_update();
    tl_window->resume_update();
    tl_particle->resume_update();
    tl_particlemodel->resume_update();
    tl_radermap->resume_update();
    tl_clipout->resume_update();
    tl_fade->resume_update();
    tl_fadeafter->resume_update();
}

void TMainTask::toggle_pause_game_layers() {
    tl_02->toggle_pause();
    tl_03->toggle_pause();
    tl_item_equip->toggle_pause();
    tl_loc_start->toggle_pause();
    tl_04->toggle_pause();
    tl_05->toggle_pause();
    tl_06->toggle_pause();
    tl_07->toggle_pause();
    tl_loc_end->toggle_pause();
    tl_window->toggle_pause();
    tl_particle->toggle_pause();
    tl_particlemodel->toggle_pause();
    tl_radermap->toggle_pause();
    tl_clipout->toggle_pause();
    tl_fade->toggle_pause();
    tl_fadeafter->toggle_pause();
}

void TMainTask::delete_layer_children() {
    tl_00->delete_children();
    tl_camera->delete_children();
    tl_01->delete_children();
    tl_02->delete_children();
    tl_03->delete_children();
    tl_item_equip->delete_children();
    tl_loc_start->delete_children();
    tl_04->delete_children();
    tl_05->delete_children();
    tl_06->delete_children();
    tl_07->delete_children();
    tl_loc_end->delete_children();
    tl_window->delete_children();
    tl_particle->delete_children();
    tl_particlemodel->delete_children();
    tl_radermap->delete_children();
    tl_clipout->delete_children();
    tl_fade->delete_children();
    tl_fadeafter->delete_children();
}

void TMainTask::resume_layers() {
    tl_00->resume_update();
    tl_camera->resume_update();
    tl_01->resume_update();
    tl_02->resume_update();
    tl_03->resume_update();
    tl_item_equip->resume_update();
    tl_loc_start->resume_update();
    tl_04->resume_update();
    tl_05->resume_update();
    tl_06->resume_update();
    tl_07->resume_update();
    tl_loc_end->resume_update();
    tl_window->resume_update();
    tl_particle->resume_update();
    tl_particlemodel->resume_update();
    tl_radermap->resume_update();
    tl_clipout->resume_update();
    tl_fade->resume_update();
    tl_fadeafter->resume_update();
}

void TMainTask::toggle_pause_layers() {
    tl_00->toggle_pause();
    tl_camera->toggle_pause();
    tl_01->toggle_pause();
    tl_02->toggle_pause();
    tl_03->toggle_pause();
    tl_item_equip->toggle_pause();
    tl_loc_start->toggle_pause();
    tl_04->toggle_pause();
    tl_05->toggle_pause();
    tl_06->toggle_pause();
    tl_07->toggle_pause();
    tl_loc_end->toggle_pause();
    tl_window->toggle_pause();
    tl_particlemodel->toggle_pause();
    tl_radermap->toggle_pause();
    tl_clipout->toggle_pause();
    tl_fade->toggle_pause();
    tl_fadeafter->toggle_pause();
}

void TMainTask::begin_frame() {

}

void TMainTask::render_screen_overlay() {
    if (task_flags & MAIN_TASK_RENDERED) {
        render_clipout_and_fade();
        debug_render();
        debug_render_overlay();
        render_info_icon_overlay();
    }
    task_flags &= ~(MAIN_TASK_UPDATED | MAIN_TASK_RENDERED);
}

#pragma defer_codegen off
