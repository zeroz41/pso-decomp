#ifndef PSO_UI_FRONTEND_TADGUIDEBUTTONGC_H
#define PSO_UI_FRONTEND_TADGUIDEBUTTONGC_H
#include "pso/system/task/TObject.h"
struct GuideButtonPoint { f32 x, y; };
struct GuideButtonQuad { f32 x0, y0, x1, y1, u0, v0, u1, v1; };
struct GuideButtonSpec {
    s32 kind;
    GuideButtonPoint from;
    GuideButtonPoint to;
    s32 alpha;
    s32 alpha_step;
    s32 duration;
    const char *label;
};
class TAdGuideButtonGC : public TObject {
public:
    GuideButtonQuad quads[8];
    u32 alpha[8];
    s32 frame;
    s32 settled_frames;
    s32 kind;
    GuideButtonPoint from;
    GuideButtonPoint to;
    u8 reserved_158[0x40];
    s32 alpha_step;
    s32 duration;
    const char *label;
    s32 active;
    TAdGuideButtonGC(TObject *parent);
    virtual ~TAdGuideButtonGC();
    virtual void run_task();
    virtual void render();
    void draw_label(int style, const char *text);
    void draw_quad(int style);
    void setup_button(GuideButtonSpec *spec);
    void update_trail_quads();
};
typedef char TAdGuideButtonGC_size_check[sizeof(TAdGuideButtonGC)==0x1A8 ? 1 : -1];
typedef char GuideButtonSpec_size_check[sizeof(GuideButtonSpec)==0x24 ? 1 : -1];

extern "C" {
void create_guide_button(TObject *parent, GuideButtonSpec *spec);
void init_guide_button_params(GuideButtonSpec *spec);
}

#endif
