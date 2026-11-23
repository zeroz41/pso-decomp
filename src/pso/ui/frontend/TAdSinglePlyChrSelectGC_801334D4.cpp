#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/object/ambient/PointLight.h"

s32 TAdSelectCurGC::confirmation_result() const { return confirmation; }
s32 TAdSelectCurGC::selection_index() const { return selected_index; }
void PointLight::apply_color() {}
void PointLight::set_color(f32 *argb) { color[0] = argb[1]; color[1] = argb[2]; color[2] = argb[3]; }
void PointLight::disable() {}
void PointLight::enable() {}
void PointLight::set_range(f32 *range) { copy_light_range(this->range, range); }
void copy_light_range(f32 *dst, f32 *src) { dst[0] = src[0]; dst[1] = src[1]; }
void PointLight::apply_range() {}
void PointLight::apply_position() {}
void PointLight::set_position(Vec *position) { this->position.x = position->x; this->position.y = position->y; this->position.z = position->z; }
