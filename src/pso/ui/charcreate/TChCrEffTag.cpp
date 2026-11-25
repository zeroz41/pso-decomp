#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/ui/charcreate/TChCrEffTagStr.h"
#include "types.h"
#include "pso/render/render_util.h"
#include <stddef.h>
#include "pso/math/TMath.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/ui/UISprite.h"
#include "pso/ui/charcreate/TChCrEffWall.h"

void TChCrEffTag::draw_chcr_tag_heading_frame() {
    vec2f pos;
    pos.x = 62.0f;
    pos.y = 67.0f;
    TChCrEffWall::draw_default_sprite(0x36, &pos, -2.75f);
}
void TChCrEffTag::draw_chcr_tag_frame() {
    vec2f position;
    vec2f scale;
    position.y = 37.0f;
    position.x = 0.0f;
    scale.x = width / 32.0f;
    scale.y = 1.0f;
    draw_ui_sprite_opaque(0x34, &position, &scale, -3.0625f);
    position.x = width;
    TChCrEffWall::draw_default_sprite(0x35, &position, -3.0625f);
}

const char *TChCrEffTag__name = "TChCrEffTag";
s32 TChCrEffTag::selected_heading = -1;
static const saddr heading_sprite_ids[] = {0xA4, 0xA5, 0xA6, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3};

void TChCrEffTag::render() { set_depth_buffer_settings_1(); draw_chcr_tag_frame(); draw_chcr_tag_heading_frame(); restore_saved_depth_alpha_state(); }
void TChCrEffTag::refresh_label() {
    vec2f pos;
    s32 heading;
    if (label != NULL) {
        label->start_fade_out();
        label = NULL;
    }
    this->heading = (s32) TChCrEffTag::selected_heading;
    heading = this->heading;
    if (heading >= 0) {
        pos.x = 27.0f;
        pos.y = 44.0f;
        label = TChCrEffTagStr::create(this, heading_sprite_ids[heading], &pos);
    }
}

#pragma push
#pragma fp_contract on
void TChCrEffTag::run_task()
{
  f32 current;
  f32 target;
  s32 index;
  if (((s32) heading) != ((s32) TChCrEffTag::selected_heading))
  {
    refresh_label();
  }
  index = heading;
  if (index >= 0)
  {
    targetWidth = 15.0f + (f32) TObjCMMainMenu::get_creation_sprite_id(heading_sprite_ids[index]);
  }
  target = targetWidth;
  if (width + 12.933333f < target)
  {
    width += 12.933333f;
  }
  else if (width - 12.933333f > target)
  {
    width -= 12.933333f;
  }
  else
  {
    width += 0.2f * (target - width);
  }
  current = width;
  if (current < 100.0f)
  {
    width = 100.0f;
    return;
  }
  if (current > 294.0f)
  {
    width = 294.0f;
  }
}
#pragma pop

TChCrEffTag::~TChCrEffTag() {}

TChCrEffTag::TChCrEffTag(TObject *parent) : TObject(parent) {
    m_name = TChCrEffTag__name;
    heading = -1;
    TChCrEffTag::selected_heading = -1;
    label = NULL;
    targetWidth = 1e+02f;
    width = 1e+02f;
}


    void TChCrEffTag::set_eff_tag(int a0) { TChCrEffTag::selected_heading = a0; }

TChCrEffTag *create_TChCrEffTag(TObject *parent) {
    return new TChCrEffTag(parent);
}
