#include "musyx/runtime/musyx_runtime_a.h"

struct VolInfo_803B8CA0 {
    f32 volL;
    f32 volR;
    f32 volS;
    f32 volAuxAL;
    f32 volAuxAR;
    f32 volAuxAS;
    f32 volAuxBL;
    f32 volAuxBR;
    f32 volAuxBS;
};

struct PanInfo_803B8CA0 {
    u32 pan_i;
    u32 pan_im;
    u32 span_i;
    u32 span_im;
    u32 rpan_i;
    u32 rpan_im;
    f32 pan_f;
    f32 pan_fm;
    f32 span_f;
    f32 span_fm;
    f32 rpan_f;
    f32 rpan_fm;
};

extern "C" {

static f32 musyx_vol_tab[129] = {
    0.f,           3.0518499e-05f, 0.000152593f,  0.000396741f,  0.00070192601f,
    0.00112918f,   0.001648f,      0.00222785f,   0.0029297799f, 0.00372326f,
    0.0046082898f, 0.00558489f,    0.0066530402f, 0.0078432597f, 0.0091250297f,
    0.0104984f,    0.0119633f,     0.0135502f,    0.0151982f,    0.0169988f,
    0.0188604f,    0.0208441f,     0.0229194f,    0.025116701f,  0.027405599f,
    0.0298166f,    0.032319099f,   0.0349437f,    0.037659802f,  0.040467501f,
    0.043427799f,  0.046479698f,   0.049623098f,  0.052888598f,  0.056276102f,
    0.059785798f,  0.063386902f,   0.067110203f,  0.0709555f,    0.074922897f,
    0.078981899f,  0.083162896f,   0.087466002f,  0.091921799f,  0.096469f,
    0.101138f,     0.10593f,       0.110843f,     0.115879f,     0.121036f,
    0.12634701f,   0.13174801f,    0.13730299f,   0.142979f,     0.14877801f,
    0.15472899f,   0.160772f,      0.166997f,     0.173315f,     0.179785f,
    0.186407f,     0.193121f,      0.200018f,     0.20700701f,   0.21417899f,
    0.22147299f,   0.228919f,      0.236488f,     0.24420901f,   0.252083f,
    0.260079f,     0.26825801f,    0.276559f,     0.28501201f,   0.29364899f,
    0.30240801f,   0.31131899f,    0.32038301f,   0.32960001f,   0.33899999f,
    0.34852099f,   0.358226f,      0.36808401f,   0.37809399f,   0.38828701f,
    0.398633f,     0.40913099f,    0.41981301f,   0.43064699f,   0.44166401f,
    0.45286399f,   0.46421701f,    0.47575301f,   0.48744199f,   0.499313f,
    0.51139897f,   0.523606f,      0.53602701f,   0.54863101f,   0.56141901f,
    0.57438898f,   0.587542f,      0.60087901f,   0.61439902f,   0.62813199f,
    0.64201802f,   0.65614802f,    0.67043102f,   0.68492699f,   0.699637f,
    0.71452999f,   0.72963703f,    0.74492598f,   0.76042998f,   0.77614701f,
    0.792077f,     0.808191f,      0.82454902f,   0.84109002f,   0.85784501f,
    0.87484401f,   0.89205599f,    0.90945202f,   0.927122f,     0.94500601f,
    0.96307302f,   0.98141402f,    1.f,           1.f,
};

static f32 pan_tab[4] = {
    0.f,
    0.7079f,
    1.0f,
    1.0f,
};

static f32 pan_tab_dpl2[4] = {
    0.575f,
    0.7079f,
    1.f,
    1.f,
};


#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
#pragma exceptions off
inline f32 fmodf_803B8CA0(f32 x, f32 m) {
    f32 a = __fabsf(m);
    f32 b = __fabsf(x);
    if (a > b) {
        return x;
    } else {
        s64 c = (s64)(x / m);
        return x - m * c;
    }
}

static void CalcBus_803B8CA0(f32 *vol_tab, f32 *vl, f32 *vr, f32 *vs, f32 vol, PanInfo_803B8CA0 *pi) {
    u32 i;
    f32 f;
    f32 v;

    i = vol * 127.f;
    v = (vol * 127) - (f32) i;
    f = (1.f - v) * vol_tab[i] + v * vol_tab[i + 1];
    *vs = f * ((1.f - pi->span_f) * pan_tab[pi->span_i] + pi->span_f * pan_tab[pi->span_i + 1]) * 0.7079f;
    f = f * ((1.f - pi->span_fm) * pan_tab[pi->span_im] + pi->span_fm * pan_tab[pi->span_im + 1]);
    *vr = f * ((1.f - pi->pan_f) * pan_tab[pi->pan_i] + pi->pan_f * pan_tab[pi->pan_i + 1]);
    *vl = f * ((1.f - pi->pan_fm) * pan_tab[pi->pan_im] + pi->pan_fm * pan_tab[pi->pan_im + 1]);
}

static void CalcBusDPL2_803B8CA0(f32 *vol_tab, f32 *fvl, f32 *fvr, f32 *rvl, f32 *rvr, f32 vol,
                                 PanInfo_803B8CA0 *pi) {
    u32 i;
    f32 f;
    f32 v;
    f32 vs;

    i = vol * 127;
    f = vol * 127 - (f32) i;
    v = (1.f - f) * vol_tab[i] + f * vol_tab[i + 1];
    vs = v * ((1.f - pi->span_f) * pan_tab[pi->span_i] + pi->span_f * pan_tab[pi->span_i + 1]);
    v *= (1.f - pi->span_fm) * pan_tab[pi->span_im] + pi->span_fm * pan_tab[pi->span_im + 1];
    *fvr = v * ((1.f - pi->pan_f) * pan_tab[pi->pan_i] + pi->pan_f * pan_tab[pi->pan_i + 1]);
    *fvl = v * ((1.f - pi->pan_fm) * pan_tab[pi->pan_im] + pi->pan_fm * pan_tab[pi->pan_im + 1]);
    *rvr = vs * ((1.f - pi->rpan_f) * pan_tab_dpl2[pi->rpan_i] + pi->rpan_f * pan_tab[pi->rpan_i + 1]);
    *rvl = vs * ((1.f - pi->rpan_fm) * pan_tab_dpl2[pi->rpan_im] + pi->rpan_fm * pan_tab[pi->rpan_im + 1]);
}

#pragma exceptions on
void salCalcVolume(u8 voltab_index, VolInfo_803B8CA0 *vi, f32 vol, u32 pan, u32 span, f32 auxa,
                           f32 auxb, u32 itd, u32 dpl2) {
    f32 *vol_tab;
    f32 p;
    f32 sp;
    f32 sp2;
    PanInfo_803B8CA0 pi;

    vol_tab = voltab_index == 0 ? musyx_vol_tab : dspDLSVolTab;

    if (pan == 0x800000) {
        pan = 0;
        span = 0x7f0000;
    }

    pan = (pan <= 0x10000 ? 0 : pan - 0x10000);
    span = (span <= 0x10000 ? 0 : span - 0x10000);

    p = pan * 2.4220301e-07f;
    sp = span * 2.4220301e-07f;

    if (dpl2 != 0) {
        pi.rpan_f = fmodf_803B8CA0(p, 1.f);
        pi.rpan_i = p;
        sp2 = 2.f - p;
        pi.rpan_fm = fmodf_803B8CA0(sp2, 1.f);
        pi.rpan_im = sp2;
    }

    if (itd != 0) {
        p = (p - 1.f) * 0.76604f + 1.f;
    }

    pi.pan_f = fmodf_803B8CA0(p, 1.f);
    pi.pan_i = p;
    pi.span_f = fmodf_803B8CA0(sp, 1.f);
    pi.span_i = sp;
    p = 2.f - p;
    sp = 2.f - sp;
    pi.pan_fm = fmodf_803B8CA0(p, 1.f);
    pi.pan_im = p;
    pi.span_fm = fmodf_803B8CA0(sp, 1.f);
    pi.span_im = sp;

    if (!dpl2) {
        CalcBus_803B8CA0(vol_tab, &vi->volL, &vi->volR, &vi->volS, vol, &pi);
        CalcBus_803B8CA0(vol_tab, &vi->volAuxAL, &vi->volAuxAR, &vi->volAuxAS, auxa, &pi);
        CalcBus_803B8CA0(vol_tab, &vi->volAuxBL, &vi->volAuxBR, &vi->volAuxBS, auxb, &pi);
    } else {
        CalcBusDPL2_803B8CA0(vol_tab, &vi->volL, &vi->volR, &vi->volAuxBL, &vi->volAuxBR, vol, &pi);
        CalcBus_803B8CA0(vol_tab, &vi->volAuxAL, &vi->volAuxAR, &vi->volAuxAS, auxa, &pi);
        vi->volS = 0.f;
        vi->volAuxBS = 0.f;
    }
}
#pragma pop

}
