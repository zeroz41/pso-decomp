#include "pso/render/GinjaMaterial.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/city/CityVerticalModel.h"
#include "pso/object/city/CityTraffic.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TUnk_804B5C08.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804B5C08::vfunc_13(s32) {
    y_offset = 0.0f;
    state = 1;
}

void TUnk_804B5C08::render() {
    if (state != 0) {
        if (!update_object_view_visibility(600.0f, 50.0f)) {
            y_offset = y_offset;
            return;
        }
        TObjFish::set_global_param(city_common_texture_list);
        push_matrix();
        post_translate_matrix(&position.x);
        translate_matrix(0, 0.0f, y_offset, 0.0f);
        rotate_matrix_y(0, rotation_y);
        draw_ginja_object(get_city_common_model(8));
        pop_matrix();
    }
}

void TUnk_804B5C08::run_task() {
    switch (state) {
    case 0:
        wait_timer--;
        if (wait_timer <= 0) {
            wait_timer = 300;
            if (last_state == 2) {
                state = 1;
                y_offset = -200.0f;
                return;
            }
            state = 2;
            y_offset = 200.0f;
        }
        break;
    case 1:
        y_offset += 2.0f;
        if (y_offset >= 200.0f) {
            last_state = 1;
            state = 0;
        }
        break;
    case 2:
        y_offset -= 2.0f;
        if (y_offset <= -200.0f) {
            last_state = 2;
            state = 0;
        }
        break;
    }
}

extern "C" void *create_city_vertical_model(void *set_data) {
    return new TUnk_804B5C08(tl_05, set_data);
}

TUnk_804B5C08::~TUnk_804B5C08() {}

TUnk_804B5C08::TUnk_804B5C08(TObject *parent, void *set_data) : TObjBase(parent) {
    apply_object_set_data(set_data);
    state = 1;
    last_state = 2;
    wait_timer = 0;
    y_offset = 0.0f;
}
