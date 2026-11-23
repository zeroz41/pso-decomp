#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/DrawLineResource.h"
#include "pso/item/TItemLoad_8010FDF0.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/frontend/TAdDrawLineTask.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {
void draw_projected_line_strip__10TObjPlayerFPvii(DrawLineVertex *, s32, s32);
void copy_draw_line_record(DrawLineRecord *, const DrawLineRecord *);
}

extern const char draw_line_task_resource_path[] = "AdDrawLineTask.prs";
extern const char draw_line_task_name[] = "TAdDrawLineTask";
extern const char draw_line_ctrl_name[] = "TAdDrawLineCtrl";
const char *TAdDrawLineTask__class_name = draw_line_task_name;
const char *TAdDrawLineCtrl__class_name = draw_line_ctrl_name;
DrawLineGroup *draw_line_task_data;
RelocatedFile *draw_line_task_resource;

#ifdef __MWERKS__
#define DRAW_LINE_CONST __declspec(section ".sdata2")
#else
#define DRAW_LINE_CONST
#endif
DRAW_LINE_CONST extern const f32 lbl_805D7DD8;
DRAW_LINE_CONST extern const f32 lbl_805D7DDC;
DRAW_LINE_CONST extern const f32 lbl_805D7DE0;
DRAW_LINE_CONST extern const f32 lbl_805D7DE4;

// The TObject and TMainTask accessors whose kept out-of-line copies sit at
// the end of this file; deferred code generation emits them last.
void TObject::disallow_rendering() { m_flags |= DISALLOW_RENDER; }

void TObject::allow_rendering() { m_flags &= ~DISALLOW_RENDER; }

void TObject::suspend_update() { m_flags |= SUSPEND_UPDATE; }

s32 TMainTask::get_render_pass() { return render_pass; }

TAdDrawLineTask *create_draw_line_task(TObject *parent, const DrawLineRecord *record, TAdDrawLineCtrl *controller) {
    if (record != NULL && lbl_805D7DDC != record->speed) {
        return new TAdDrawLineTask(parent, record, controller);
    }
    return NULL;
}

TAdDrawLineTask::TAdDrawLineTask(TObject *parent, const DrawLineRecord *record, TAdDrawLineCtrl *ctrl)
    : TObject(parent) {
    m_name = TAdDrawLineTask__class_name;
    controller = ctrl;
    copy_draw_line_record(&line, record);
    line.start.w = lbl_805D7DE0 / line.start.w;
    line.end.w = lbl_805D7DE0 / line.end.w;
    f32 dx = line.end.x - line.start.x;
    f32 dy = line.end.y - line.start.y;
    f32 length = newton_sqrtf(dx * dx + dy * dy);
    duration = length / line.speed;
    step_x = dx / duration;
    step_y = dy / duration;
    step_w = (line.end.w - line.start.w) / duration;
    DrawLineColor end_color;
    DrawLineColor start_color;
    start_color.value = line.start.color.value;
    end_color.value = line.end.color.value;
    color_step.channels.green = (end_color.channels.green - start_color.channels.green) / duration;
    color_step.channels.red = (end_color.channels.red - start_color.channels.red) / duration;
    color_step.channels.alpha = (end_color.channels.alpha - start_color.channels.alpha) / duration;
    color_step.channels.blue = (end_color.channels.blue - start_color.channels.blue) / duration;
    color.value = line.start.color.value;
    frame = lbl_805D7DDC;
    f32 normal_x = lbl_805D7DE0 * dy;
    f32 half_width = line.width * lbl_805D7DE4;
    half_width_x = normal_x * half_width / length;
    half_width_y = dx * half_width / length;
    vertices[0].x = line.start.x + half_width_x;
    vertices[0].y = line.start.y + half_width_y;
    vertices[0].w = line.start.w;
    vertices[0].color.value = line.start.color.value;
    vertices[1].x = line.start.x - half_width_x;
    vertices[1].y = line.start.y - half_width_y;
    vertices[1].w = line.start.w;
    vertices[1].color.value = line.start.color.value;
    copy_line_vertex(&vertices[2], &vertices[0]);
    copy_line_vertex(&vertices[3], &vertices[1]);
    disallow_rendering();
}

TAdDrawLineTask::~TAdDrawLineTask() {}

void TAdDrawLineTask::run_task() {
    allow_rendering();
    if (lbl_805D7DD8 + frame < duration) {
        color.channels.green += color_step.channels.green;
        color.channels.red += color_step.channels.red;
        color.channels.alpha += color_step.channels.alpha;
        color.channels.blue += color_step.channels.blue;
        vertices[2].x += step_x;
        vertices[2].y += step_y;
        vertices[2].w += step_w;
        vertices[2].color.value = color.value;
        vertices[3].x += step_x;
        vertices[3].y += step_y;
        vertices[3].w += step_w;
        vertices[3].color.value = color.value;
        frame += lbl_805D7DD8;
        return;
    }
    vertices[2].x = line.end.x + half_width_x;
    vertices[2].y = line.end.y + half_width_y;
    vertices[2].w = line.end.w;
    vertices[2].color.value = line.end.color.value;
    vertices[3].x = line.end.x - half_width_x;
    vertices[3].y = line.end.y - half_width_y;
    vertices[3].w = line.end.w;
    vertices[3].color.value = line.end.color.value;
    if (controller != NULL) {
        controller->start_lines_for_key(line.key);
    }
    suspend_update();
}

void TAdDrawLineTask::render() {
    set_default_alpha_blend();
    draw_projected_line_strip__10TObjPlayerFPvii(vertices, 4, 1);
}

void TAdDrawLineTask::set_depth(f32 depth) {
    if (lbl_805D7DDC == depth) {
        return;
    }
    f32 reciprocal = lbl_805D7DE0 / depth;
    line.start.w = reciprocal;
    line.end.w = reciprocal;
    step_w = lbl_805D7DDC;
    for (s32 i = 0; i < 4; i++) {
        vertices[i].w = reciprocal;
    }
}

void load_draw_line_task_resource() {
    RelocatedFile *file = new RelocatedFile(draw_line_task_resource_path, 0x4800);
    draw_line_task_resource = file;
    if (file != NULL) {
        draw_line_task_data = static_cast<DrawLineGroup *>(file->get_root());
    }
}

void free_draw_line_task_resource() {
    if (draw_line_task_resource != NULL) {
        delete draw_line_task_resource;
        draw_line_task_resource = NULL;
        draw_line_task_data = NULL;
    }
}

TAdDrawLineCtrl *create_draw_line_ctrl(TObject *parent, s32 group_index, f32 depth) {
    if (draw_line_task_data != NULL) {
        return new TAdDrawLineCtrl(parent, &draw_line_task_data[group_index], depth);
    }
    return NULL;
}

TAdDrawLineCtrl::TAdDrawLineCtrl(TObject *parent, void *data, f32 depth) : TObject(parent) {
    m_name = TAdDrawLineCtrl__class_name;
    line_data = static_cast<DrawLineGroup *>(data);
    child_root = new TObject(NULL);
    render_mode = 1;
    set_depth_all_nodes(depth);
    start_lines_for_key(-1);
}

TAdDrawLineCtrl::~TAdDrawLineCtrl() {
    delete child_root;
}

void TAdDrawLineCtrl::run_task() {
    if (child_root != NULL) {
        child_root->run_tasks();
        return;
    }
    queue_destruction();
}

void TAdDrawLineCtrl::render() {
    if (render_mode == 0) {
        if (defer_render() != 0) {
            return;
        }
        set_depth_buffer_settings_2();
    } else if (get_main_phase() == 2 && TMainTask::get_render_pass() == 1) {
        return;
    }
    set_default_alpha_blend();
    if (child_root != NULL) {
        child_root->render_nodes();
    }
    if (render_mode == 0) {
        restore_saved_depth_alpha_state();
    }
}

void TAdDrawLineCtrl::start_line(s32 index) {
    TAdDrawLineTask *task = create_draw_line_task(child_root, &line_data->lines[index], this);
    if (task != NULL && lbl_805D7DDC != line_depth) {
        task->set_depth(line_depth);
    }
}

void TAdDrawLineCtrl::start_lines_for_key(s32 key) {
    for (s32 i = 0; i != line_data->key_count; i++) {
        DrawLineKey *entry = &line_data->keys[i];
        if (entry->key == key) {
            start_line(entry->line_index);
        }
    }
}

void TAdDrawLineCtrl::set_depth_all_nodes(f32 depth) {
    line_depth = depth;
    for (TObject *node = child_root->m_down; node != NULL; node = node->m_next) {
        static_cast<TAdDrawLineTask *>(node)->set_depth(depth);
    }
}

void copy_line_vertex(void *destination, void *source) {
    DrawLineVertex *to = static_cast<DrawLineVertex *>(destination);
    const DrawLineVertex *from = static_cast<const DrawLineVertex *>(source);
    to->x = from->x;
    to->y = from->y;
    to->w = from->w;
    to->color.value = from->color.value;
}

DRAW_LINE_CONST extern const f32 lbl_805D7DD8 = 1.0f;
DRAW_LINE_CONST extern const f32 lbl_805D7DDC = 0.0f;
DRAW_LINE_CONST extern const f32 lbl_805D7DE0 = -1.0f;
DRAW_LINE_CONST extern const f32 lbl_805D7DE4 = 0.5f;
#undef DRAW_LINE_CONST
