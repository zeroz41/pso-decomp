#ifndef PSO_UI_FRONTEND_TADGAMESTARTGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdGameStartSubGC.h"

class TAdGameStartShadowGC;
class TAdGameStartBackGC;
class TAdGameStartLineGC;
class TAdGameStartShineGC;

// The multiplayer GAME START banner: drops in one TAdGameStartSubGC letter per
// frame and, once create_effects() runs, its shadow, back, line and shine
// effects; any button press or the 60th frame tears it all down.
class TAdGameStartGC : public TObject {
public:
    TAdGameStartGC(TObject *parent);
    virtual ~TAdGameStartGC();
    virtual void run_task();
    virtual void render();

    void destroy_windows();
    void create_effects();

    static void bswap_6x92(void *p);
    static void send_6x92(void *p);
    static void init_6x92(void *p);

    GameStartLetterLayout m_letters[8];
    s32 m_frame;
    s32 m_active;
    TAdGameStartSubGC *m_letter_tasks[8];
    TAdGameStartShadowGC *m_shadow;
    TAdGameStartBackGC *m_back;
    TAdGameStartLineGC *m_line;
    TAdGameStartShineGC *m_shine;
};

LAYOUT_ASSERT(TAdGameStartGC_size, sizeof(TAdGameStartGC) == 0xD4);

void register_texture_f512_multiplay(void);

#endif
