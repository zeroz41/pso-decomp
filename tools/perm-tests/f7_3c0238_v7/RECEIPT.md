# 3c0238 v7 — P@4 interleave (ONE spelled lever, land-or-close)

Seat: TLobby__sub_803C0238 (psov3/pso/unk/TLobby_803BFE50, post-#196 typed path).
Gate RE-DERIVED at intake: symbols row `.text:0x803C0238 size:0x3F0`; era .fn
block build/GPOE8P/asm/pso/unk/TLobby_803BFE50.s 0x803C0238..0x803C0624 = 0x3F0 (1008B, 252 insns).

## STEP 0 base-row screen — PASS
base-report-fc62998f: unit 35/36 matched fns, seat row present UNPAIRED (no fuzzy key)
= seat open on base, no upstream closure. Single-open-fn unit = door-shaped.

## Transplant (champion 3dfa1b7a, f8 card-3c0238-v2) — zero decay
File-level graft of the self-contained champion + typed include-path keep
(pso/system->pso/audio SjRingBuffer, pso/misc->pso/unk TLobby). Diff = 7 hunks
(vtable +reserve, struct rings[2]+f14+f18 + u32 f48/f50, seat decl void(arg0*),
7 phase-2 externs appended at decl-block tail, call-site arg, seat body).
Sibling safety: rings loop dynamic-index, f48/f50 stores are li-0 -> byte-neutral.
MEASURED build 1: one_shot PAIRED ORIG=OURS 97.9127, 252/252 rows, gnm 0x3f0
GATE-EXACT, 36-sym gnm int-parse drift 0. Park echo reproduces exactly on typed tree.

## v6 receipt basis (8154_seal.md v6/v7 sections)
v6: ascending pb[0..3] store-order = era reverse-index walk, 3 rows cleared,
cascade inversion (8154 closed P@4 there as no-emitter 55/55). Successor note:
"P@4 interleave (3-loads-ahead)". Levers ARE PER-UNIT HYPOTHESES: 3c0238 re-probe
judged on ITS era rows around the walk.

## Era rows that decide (slots 4-13, zero-park window)
era:  mr r31,r3 | lwz r27,4(r3) | mr r3,r27 | bl get_entry_id | cmpwi | bne |
      lbz r0,3(r31) | lwz r29,4(r31)=P-RELOAD | cmpwi r0,1 | lwz r30,8(r31)
b1 (v2 head): park mr r31,r29 (+1), reload MISSING (-1), f8/cmpwi INVERTED.
v2 head `lb = f4; h = lb;` = copy-def = the park emitter.

## v7 lever: P@4 interleave (ONE knob: zone-A entry def restage)
```
lb = (s32)arg0->f4;                       // first-read, persists (era r27)
if (get_entry_id__6TLobbyFv(lb) == 0) {   // era mr r3,r27 direct
    f3v = arg0->f3;                       // era slot 10 lbz
    h = (s32)arg0->f4;                    // def POSITION 4 = era slot 11 reload
    st = (s32)arg0->f8;                   // era slot 13 (after cmpwi sandwich)
    if (f3v == 1) {...
```
All zone-A-internal calls route h (era r29: get_field_a8 x2, init_scroll,
sub_803C3A04); phase-2 head routes lb (era r27: sub_803C34F4, get_entry_id).

## RESULT — FUSE LANDED
build 2: gnm 0x3f0 GATE-EXACT (park mr -1 + reload lwz +1 = net-zero: the v3
"mutually exclusive at the pin" verdict FALSIFIED by def-position, not store-order).
one_shot PAIRED 97.9127 -> **98.4127** (+0.50), 252/252 rows.
Window slots 4-6/10-13 fire ERA-SHAPE (reload row present, cmpwi sandwich landed,
zero-park load-to-home-direct lwz r28,4(r27)); residual window = pure 2-reg home
rotation {r31<->r27 self, r29->r28 reload} = sealed bind-to-home stratum colors.
SURPASSES banked +1W rung 97.99603@0x3F4 at the correct gate (+0.41667).

## Gates (builds used: 3/4)
rm .o + ninja unit rc=0 (MWCC line); full link rc=0 Code 141/141 Data 100.00%;
report_delta --check vs base-report-fc62998f: New exact 0 (fuzzy seat) /
regressions 0 / matched_functions 27363 stable / linked_units 2933 +0;
check_pr PASS (linked 2933, regressed 0, skipped 0, exact candidates 1 = known);
DOL byte-identical 0d85744b51d7379efb025a943d0cd5aaae2191a3 == main checkout;
36-sym gnm int-parse sibling drift 0.
Global fuzzy 95.99771 -> 96.0205. Unit fuzzy 83.657585 -> 99.74059.

## Residual census v7
REAL rows remaining = 2-reg home-rotation color class (prologue r31<->r27 self/
first swap = park-confirmed bind-to-home stratum, + reload r29->r28 rank shift)
and rename-inherited display rows (base-disp r31->r27 = same class, one binding).
Seat v2 97.61508 -> b99ed8d3e 97.9127 -> v7 98.4127. NOT 100.0: unit stays 35/36,
no link config touched, no push.
