#ifndef PSO_SYSTEM_TASK_TOBJECT_H
#define PSO_SYSTEM_TASK_TOBJECT_H

/* TObject - Base scene graph / task hierarchy node.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 * Adapted for GPOE8P (PSO EP I&II Plus, MWCC 2.6).
 *
 * TObject forms a tree structure where each node has:
 *   m_up   = parent node
 *   m_down = first child node
 *   m_next = next sibling
 *   m_prev = previous sibling (circular for first child)
 */

#include "pso/forward.h"
#include "pso/macros.h"
#include "types.h"

#define o(name) extern const char *name##_name;
OBJECT_NAMES
#undef o

extern TMainTask main_task;
extern TObject end_of_render_root;
extern TObject keyboard_task_object;

enum object_flags {
    NONE                    = 0x0000,
    QUEUE_DESTRUCTION       = 0x0001,
    CHILD_QUEUE_DESTRUCTION = 0x0002,
    SUSPEND_UPDATE          = 0x0004, // the object stops updating itself
    PAUSE_UPDATE            = 0x0008, // paused from outside (whole layers via TMainTask)
    DISALLOW_UPDATE         = 0x000F, // any of the above: run_tasks skips the node
    DISALLOW_RENDER         = 0x0010,
    DISALLOW_DESTRUCTION    = 0x0020,
    DISALLOW_RENDER_SHADOWS = 0x0100,
    DEFER_RENDER            = 0x0200, // drawn in render_deferred_nodes' later pass
    NO_DEFER_RENDER         = 0x0400  // defer_render() never defers this node
};

class TObject {
#ifdef TOBJECT_CPP
    #define _delete_children() { \
        while (m_down != NULL) { \
            delete m_down; \
        } \
    }
    #define add_parent(parent, set_parent) { \
        if (set_parent) { \
            m_up = parent; \
        } \
        if (parent == NULL) { \
            m_prev = this; \
            m_next = NULL; \
        } else { \
            TObject *child = parent->m_down; \
            if (child != NULL) { \
                m_prev = child->m_prev; \
                m_next = NULL; \
                child->m_prev->m_next = this; \
                child->m_prev = this; \
            } else { \
                m_prev = this; \
                parent->m_down = this; \
                m_next = NULL; \
            } \
        } \
    }
    #define remove_parent() { \
        if (m_up != NULL) { \
            if (m_prev == this) { \
                m_up->m_down = NULL; \
            } else if (m_up->m_down == this) { \
                m_up->m_down = m_next; \
                m_prev->m_next = NULL; \
                if (m_next != NULL) { \
                    m_next->m_prev = m_prev; \
                } \
            } else { \
                m_prev->m_next = m_next; \
                if (m_next != NULL) { \
                    m_next->m_prev = m_prev; \
                } else { \
                    m_up->m_down->m_prev = m_prev; \
                } \
            } \
        } \
    }
#endif
public:
    const char *m_name;
    u16 m_flags;
    u16 m_id;
    TObject *m_prev;
    TObject *m_next;
    TObject *m_up;
    TObject *m_down;

public:
#ifdef TOBJECT_OUT_OF_LINE_HELPERS
    void allow_rendering_shadows();
    void disallow_rendering_shadows();
    void clear_render_deferred();
    void set_render_deferred();
    u32 is_render_deferred();
    void allow_rendering();
    void disallow_rendering();
    void resume_update();
    void pause_update();
    void toggle_pause();
    void queue_destruction();
#else
    void allow_rendering_shadows()    { m_flags &= ~DISALLOW_RENDER_SHADOWS; }
    void disallow_rendering_shadows() { m_flags |= DISALLOW_RENDER_SHADOWS; }
    void clear_render_deferred()      { m_flags &= ~DEFER_RENDER; }
    void set_render_deferred()        { m_flags |= DEFER_RENDER; }
    u32  is_render_deferred()         { return m_flags & DEFER_RENDER; }
    void allow_rendering()            { m_flags &= ~DISALLOW_RENDER; }
    void disallow_rendering()         { m_flags |= DISALLOW_RENDER; }
    void resume_update()              { m_flags &= ~PAUSE_UPDATE; }
    void pause_update()               { m_flags |= PAUSE_UPDATE; }
    void toggle_pause();
    void queue_destruction()          { m_flags |= QUEUE_DESTRUCTION; }

#endif

    TObject(TObject *parent = NULL);
    virtual ~TObject();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    void suspend_update();

    void *operator new(size_t size);
    void  operator delete(void *ptr);

    void delete_children();
    void queue_destruction_for_each_node();
    void run_tasks();
    void render_nodes();
    void render_shadows_for_each_node();
    void render_deferred_nodes();
    void debug_render();
    void set_parent(TObject *parent);

    void debug_update();
    void log(const char *str);
    int  get_node_count();
    int  all_parents_unqueued_for_destruction();
    int defer_render();
public:
};

#endif
