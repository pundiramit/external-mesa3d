/* Copyright (C) 2020 Google, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "decode.h"

/*
 * enum tables, these don't have any link back to other tables so just
 * dump them up front before the bitset tables
 */

static const struct isa_enum enum___flut = {
    .num_values = 12,
    .values = {
        { .val = 0, .display = "(0.0)" },
        { .val = 1, .display = "(0.5)" },
        { .val = 8, .display = "(log2(e))" },
        { .val = 11, .display = "(4.0)" },
        { .val = 9, .display = "(1/log2(10))" },
        { .val = 5, .display = "(pi)" },
        { .val = 2, .display = "(1.0)" },
        { .val = 3, .display = "(2.0)" },
        { .val = 7, .display = "(1/log2(e))" },
        { .val = 10, .display = "(log2(10))" },
        { .val = 4, .display = "(e)" },
        { .val = 6, .display = "(1/pi)" },
    },
};
static const struct isa_enum enum___rptn = {
    .num_values = 6,
    .values = {
        { .val = 0, .display = "" },
        { .val = 5, .display = "(rpt5)" },
        { .val = 1, .display = "(rpt1)" },
        { .val = 2, .display = "(rpt2)" },
        { .val = 3, .display = "(rpt3)" },
        { .val = 4, .display = "(rpt4)" },
    },
};
static const struct isa_enum enum___cat5_s2en_bindless_desc_mode = {
    .num_values = 8,
    .values = {
        { .val = 0, .display = "CAT5_NONUNIFORM" },
        { .val = 5, .display = "CAT5_BINDLESS_UNIFORM" },
        { .val = 6, .display = "CAT5_BINDLESS_IMM" },
        { .val = 7, .display = "CAT5_BINDLESS_A1_IMM" },
        { .val = 1, .display = "CAT5_BINDLESS_A1_UNIFORM" },
        { .val = 2, .display = "CAT5_BINDLESS_NONUNIFORM" },
        { .val = 3, .display = "CAT5_BINDLESS_A1_NONUNIFORM" },
        { .val = 4, .display = "CAT5_UNIFORM" },
    },
};
static const struct isa_enum enum___cat6_src_mode = {
    .num_values = 3,
    .values = {
        { .val = 0, .display = "imm" },
        { .val = 1, .display = "uniform" },
        { .val = 2, .display = "nonuniform" },
    },
};
static const struct isa_enum enum___absneg = {
    .num_values = 4,
    .values = {
        { .val = 0, .display = "" },
        { .val = 1, .display = "(neg)" },
        { .val = 2, .display = "(abs)" },
        { .val = 3, .display = "(absneg)" },
    },
};
static const struct isa_enum enum___swiz = {
    .num_values = 4,
    .values = {
        { .val = 0, .display = "x" },
        { .val = 1, .display = "y" },
        { .val = 2, .display = "z" },
        { .val = 3, .display = "w" },
    },
};
static const struct isa_enum enum___type = {
    .num_values = 8,
    .values = {
        { .val = 0, .display = "f16" },
        { .val = 5, .display = "s32" },
        { .val = 6, .display = "u8" },
        { .val = 7, .display = "s8" },
        { .val = 1, .display = "f32" },
        { .val = 2, .display = "u16" },
        { .val = 3, .display = "u32" },
        { .val = 4, .display = "s16" },
    },
};
static const struct isa_enum enum___wrmask = {
    .num_values = 16,
    .values = {
        { .val = 0, .display = "" },
        { .val = 1, .display = "x" },
        { .val = 8, .display = "w" },
        { .val = 15, .display = "xyzw" },
        { .val = 11, .display = "xyw" },
        { .val = 13, .display = "xzw" },
        { .val = 12, .display = "zw" },
        { .val = 9, .display = "xw" },
        { .val = 5, .display = "zx" },
        { .val = 2, .display = "y" },
        { .val = 3, .display = "xy" },
        { .val = 7, .display = "xyz" },
        { .val = 10, .display = "yw" },
        { .val = 4, .display = "z" },
        { .val = 6, .display = "zy" },
        { .val = 14, .display = "yzw" },
    },
};
static const struct isa_enum enum___cond = {
    .num_values = 6,
    .values = {
        { .val = 0, .display = "lt" },
        { .val = 5, .display = "ne" },
        { .val = 1, .display = "le" },
        { .val = 2, .display = "gt" },
        { .val = 3, .display = "ge" },
        { .val = 4, .display = "eq" },
    },
};

/*
 * generated expression functions, can be linked from bitset tables, so
 * also dump them up front
 */

static uint64_t
expr_anon_19(struct decode_scope *scope)
{
    int64_t HAS_SAMP = isa_decode_field(scope, "HAS_SAMP");
    return HAS_SAMP;
}
static uint64_t
expr_anon_18(struct decode_scope *scope)
{
    int64_t NUM_SRC = isa_decode_field(scope, "NUM_SRC");
    int64_t O = isa_decode_field(scope, "O");
    return O || (NUM_SRC > 1);
}
static uint64_t
expr___true(struct decode_scope *scope)
{
    return 1;
}
static uint64_t
expr_anon_32(struct decode_scope *scope)
{
    int64_t SRC_IM = isa_decode_field(scope, "SRC_IM");
    return SRC_IM;
}
static uint64_t
expr_anon_25(struct decode_scope *scope)
{
    int64_t SRC2_REG = isa_decode_field(scope, "SRC2_REG");
    return !SRC2_REG;
}
static uint64_t
expr_anon_7(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    return SRC_TYPE == 0 /* f16 */;
}
static uint64_t
expr_anon_22(struct decode_scope *scope)
{
    int64_t HAS_TEX = isa_decode_field(scope, "HAS_TEX");
    return HAS_TEX;
}
static uint64_t
expr_anon_29(struct decode_scope *scope)
{
    int64_t K = isa_decode_field(scope, "K");
    return K;
}
static uint64_t
expr_anon_31(struct decode_scope *scope)
{
    int64_t BINDLESS = isa_decode_field(scope, "BINDLESS");
    return BINDLESS;
}
static uint64_t
expr_anon_11(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    return SRC_TYPE == 5 /* s32 */;
}
static uint64_t
expr_anon_24(struct decode_scope *scope)
{
    int64_t BINDLESS = isa_decode_field(scope, "BINDLESS");
    return !BINDLESS;
}
static uint64_t
expr_anon_5(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    int64_t DST = isa_decode_field(scope, "DST");
    int64_t DST_TYPE = isa_decode_field(scope, "DST_TYPE");
    return (DST == 0xf5 /* a0.y */) && (SRC_TYPE == 2 /* u16 */) && (DST_TYPE == 2);
}
static uint64_t
expr_anon_21(struct decode_scope *scope)
{
    int64_t HAS_TEX = isa_decode_field(scope, "HAS_TEX");
    return HAS_TEX;
}
static uint64_t
expr___cat5_s2enb_is_indirect(struct decode_scope *scope)
{
    int64_t DESC_MODE = isa_decode_field(scope, "DESC_MODE");
    return DESC_MODE < 6  /* CAT5_BINDLESS_IMM */;
}
static uint64_t
expr_anon_3(struct decode_scope *scope)
{
    int64_t DST_TYPE = isa_decode_field(scope, "DST_TYPE");
    return (DST_TYPE == 0) /* f16 */ ||
			(DST_TYPE == 2) /* u16 */ ||
			(DST_TYPE == 4) /* s16 */ ||
			(DST_TYPE == 6) /* u8 */  ||
			(DST_TYPE == 7) /* s8 */;
}
static uint64_t
expr___cat5_s2enb_uses_a1(struct decode_scope *scope)
{
    int64_t DESC_MODE = isa_decode_field(scope, "DESC_MODE");
    return (DESC_MODE == 1) /* CAT5_BINDLESS_A1_UNIFORM */ ||
	(DESC_MODE == 3) /* CAT5_BINDLESS_A1_NONUNIFORM */ ||
	(DESC_MODE == 7) /* CAT5_BINDLESS_A1_IMM */;
}
static uint64_t
expr_anon_9(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    int64_t IMMED = isa_decode_field(scope, "IMMED");
    return (SRC_TYPE == 3 /* u32 */) && (IMMED > 0x1000);
}
static uint64_t
expr___one(struct decode_scope *scope)
{
    return 1;
}
static uint64_t
expr_anon_10(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    return SRC_TYPE == 4 /* s16 */;
}
static uint64_t
expr_anon_26(struct decode_scope *scope)
{
    int64_t G = isa_decode_field(scope, "G");
    return !G;
}
static uint64_t
expr___multisrc_half(struct decode_scope *scope)
{
    int64_t FULL = isa_decode_field(scope, "FULL");
    return !FULL;
}
static uint64_t
expr_anon_4(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    int64_t DST = isa_decode_field(scope, "DST");
    int64_t DST_TYPE = isa_decode_field(scope, "DST_TYPE");
    return (DST == 0xf4 /* a0.x */) && (SRC_TYPE == 4 /* s16 */) && (DST_TYPE == 4);
}
static uint64_t
expr___cat6_direct(struct decode_scope *scope)
{
    int64_t MODE = isa_decode_field(scope, "MODE");
    return MODE == 0;
}
static uint64_t
expr___cat2_cat3_nop_value(struct decode_scope *scope)
{
    int64_t SRC2_R = isa_decode_field(scope, "SRC2_R");
    int64_t SRC1_R = isa_decode_field(scope, "SRC1_R");
    return SRC1_R | (SRC2_R << 1);
}
static uint64_t
expr___dest_half(struct decode_scope *scope)
{
    int64_t DST_CONV = isa_decode_field(scope, "DST_CONV");
    int64_t DST = isa_decode_field(scope, "DST");
    int64_t FULL = isa_decode_field(scope, "FULL");
    return (FULL == DST_CONV) && (DST <= 0xf7 /* p0.x */);
}
static uint64_t
expr___zero(struct decode_scope *scope)
{
    return 0;
}
static uint64_t
expr_anon_16(struct decode_scope *scope)
{
    int64_t S2EN_BINDLESS = isa_decode_field(scope, "S2EN_BINDLESS");
    return S2EN_BINDLESS;
}
static uint64_t
expr_anon_12(struct decode_scope *scope)
{
    int64_t REPEAT = isa_decode_field(scope, "REPEAT");
    return (REPEAT + 1) * 32;
}
static uint64_t
expr_anon_1(struct decode_scope *scope)
{
    int64_t DST_REL = isa_decode_field(scope, "DST_REL");
    return DST_REL;
}
static uint64_t
expr___two(struct decode_scope *scope)
{
    return 2;
}
static uint64_t
expr_anon_28(struct decode_scope *scope)
{
    int64_t OFF_HI = isa_decode_field(scope, "OFF_HI");
    int64_t OFF_LO = isa_decode_field(scope, "OFF_LO");
    return (OFF_HI << 8) | OFF_LO;
}
static uint64_t
expr___cat6_global(struct decode_scope *scope)
{
    int64_t G = isa_decode_field(scope, "G");
    return G;
}
static uint64_t
expr_anon_17(struct decode_scope *scope)
{
    int64_t NUM_SRC = isa_decode_field(scope, "NUM_SRC");
    return NUM_SRC > 0;
}
static uint64_t
expr_anon_15(struct decode_scope *scope)
{
    int64_t TYPE = isa_decode_field(scope, "TYPE");
    return (TYPE == 0) /* f16 */ ||
			(TYPE == 2) /* u16 */ ||
			(TYPE == 4) /* s16 */ ||
			(TYPE == 6) /* u8 */  ||
			(TYPE == 7) /* s8 */;
}
static uint64_t
expr_anon_14(struct decode_scope *scope)
{
    int64_t BINDLESS = isa_decode_field(scope, "BINDLESS");
    return BINDLESS;
}
static uint64_t
expr_anon_8(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    return SRC_TYPE == 1 /* f32 */;
}
static uint64_t
expr_anon_27(struct decode_scope *scope)
{
    int64_t OFF_HI = isa_decode_field(scope, "OFF_HI");
    int64_t OFF_LO = isa_decode_field(scope, "OFF_LO");
    return (OFF_HI << 8) | OFF_LO;
}
static uint64_t
expr___reg_gpr_p0(struct decode_scope *scope)
{
    int64_t GPR = isa_decode_field(scope, "GPR");
    return GPR == 62 /* p0.x */;
}
static uint64_t
expr_anon_0(struct decode_scope *scope)
{
    int64_t DST_REL = isa_decode_field(scope, "DST_REL");
    int64_t OFFSET = isa_decode_field(scope, "OFFSET");
    return (OFFSET == 0) && DST_REL;
}
static uint64_t
expr_anon_6(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    int64_t DST_TYPE = isa_decode_field(scope, "DST_TYPE");
    return SRC_TYPE != DST_TYPE;
}
static uint64_t
expr___cat5_s2enb_is_bindless(struct decode_scope *scope)
{
    int64_t DESC_MODE = isa_decode_field(scope, "DESC_MODE");
    return (DESC_MODE == 1) /* CAT5_BINDLESS_A1_UNIFORM */ ||
	(DESC_MODE == 2) /* CAT5_BINDLESS_NONUNIFORM */ ||
	(DESC_MODE == 3) /* CAT5_BINDLESS_A1_NONUNIFORM */ ||
	(DESC_MODE == 5) /* CAT5_BINDLESS_UNIFORM */ ||
	(DESC_MODE == 6) /* CAT5_BINDLESS_IMM */ ||
	(DESC_MODE == 7) /* CAT5_BINDLESS_A1_IMM */;
}
static uint64_t
expr___offset_zero(struct decode_scope *scope)
{
    int64_t OFFSET = isa_decode_field(scope, "OFFSET");
    return OFFSET == 0;
}
static uint64_t
expr___reg_gpr_a0(struct decode_scope *scope)
{
    int64_t GPR = isa_decode_field(scope, "GPR");
    return GPR == 61 /* a0.* */;
}
static uint64_t
expr_anon_13(struct decode_scope *scope)
{
    int64_t BASE_HI = isa_decode_field(scope, "BASE_HI");
    int64_t BASE_LO = isa_decode_field(scope, "BASE_LO");
    return (BASE_HI * 2) | BASE_LO;
}
static uint64_t
expr___cat5_s2enb_is_uniform(struct decode_scope *scope)
{
    int64_t DESC_MODE = isa_decode_field(scope, "DESC_MODE");
    return (DESC_MODE == 1) /* CAT5_BINDLESS_A1_UNIFORM */ ||
	(DESC_MODE == 4) /* CAT5_UNIFORM */ ||
	(DESC_MODE == 5) /* CAT5_BINDLESS_UNIFORM */;
}
static uint64_t
expr_anon_30(struct decode_scope *scope)
{
    int64_t TYPED = isa_decode_field(scope, "TYPED");
    return TYPED;
}
static uint64_t
expr___false(struct decode_scope *scope)
{
    return 0;
}
static uint64_t
expr_anon_2(struct decode_scope *scope)
{
    int64_t SRC_TYPE = isa_decode_field(scope, "SRC_TYPE");
    return (SRC_TYPE == 0) /* f16 */ ||
			(SRC_TYPE == 2) /* u16 */ ||
			(SRC_TYPE == 4) /* s16 */ ||
			(SRC_TYPE == 6) /* u8 */  ||
			(SRC_TYPE == 7) /* s8 */;
}
static uint64_t
expr___cat6_type_size(struct decode_scope *scope)
{
    int64_t TYPE_SIZE_MINUS_ONE = isa_decode_field(scope, "TYPE_SIZE_MINUS_ONE");
    return TYPE_SIZE_MINUS_ONE + 1;
}
static uint64_t
expr_anon_20(struct decode_scope *scope)
{
    int64_t HAS_SAMP = isa_decode_field(scope, "HAS_SAMP");
    return HAS_SAMP;
}
static uint64_t
expr_anon_23(struct decode_scope *scope)
{
    int64_t HAS_TYPE = isa_decode_field(scope, "HAS_TYPE");
    return HAS_TYPE;
}
static uint64_t
expr___cat6_d(struct decode_scope *scope)
{
    int64_t D_MINUS_ONE = isa_decode_field(scope, "D_MINUS_ONE");
    return D_MINUS_ONE + 1;
}
static uint64_t
expr___cat2_cat3_nop_encoding(struct decode_scope *scope)
{
    int64_t SRC2_R = isa_decode_field(scope, "SRC2_R");
    int64_t SRC1_R = isa_decode_field(scope, "SRC1_R");
    int64_t REPEAT = isa_decode_field(scope, "REPEAT");
    return ((SRC1_R != 0) || (SRC2_R != 0)) && (REPEAT == 0);
}

/*
 * Forward-declarations (so we don't have to figure out which order to
 * emit various tables when they have pointers to each other)
 */

static const struct isa_bitset bitset___instruction_cat3;
static const struct isa_bitset bitset_sel_b16;
static const struct isa_bitset bitset_floor_f;
static const struct isa_bitset bitset_cmps_f;
static const struct isa_bitset bitset_isamm;
static const struct isa_bitset bitset___instruction_cat0_immed;
static const struct isa_bitset bitset_mull_u;
static const struct isa_bitset bitset_rgetinfo;
static const struct isa_bitset bitset___cat3_src_relative_const;
static const struct isa_bitset bitset___cat5_tex_s2en_bindless;
static const struct isa_bitset bitset_exp2;
static const struct isa_bitset bitset_ldg;
static const struct isa_bitset bitset___cat1_relative_const_src;
static const struct isa_bitset bitset_shb;
static const struct isa_bitset bitset_sam;
static const struct isa_bitset bitset___cat1_gpr_src;
static const struct isa_bitset bitset_mov_immed;
static const struct isa_bitset bitset_mad_s24;
static const struct isa_bitset bitset_cut;
static const struct isa_bitset bitset_getbit_b;
static const struct isa_bitset bitset_shr_b;
static const struct isa_bitset bitset_mov_gpr;
static const struct isa_bitset bitset_max_u;
static const struct isa_bitset bitset_msad;
static const struct isa_bitset bitset_atomic_b_max;
static const struct isa_bitset bitset_stib_b;
static const struct isa_bitset bitset___instruction_cat2;
static const struct isa_bitset bitset___cat3_src_const;
static const struct isa_bitset bitset_cmpv_f;
static const struct isa_bitset bitset_getinfo;
static const struct isa_bitset bitset_braa;
static const struct isa_bitset bitset___multisrc_const;
static const struct isa_bitset bitset_xor_b;
static const struct isa_bitset bitset_max_s;
static const struct isa_bitset bitset___instruction_cat6_a6xx_ibo;
static const struct isa_bitset bitset___multisrc_relative_const;
static const struct isa_bitset bitset_ldib_b;
static const struct isa_bitset bitset___reg_relative_const;
static const struct isa_bitset bitset_getone;
static const struct isa_bitset bitset___instruction_cat0_0src;
static const struct isa_bitset bitset_getwid;
static const struct isa_bitset bitset___multisrc_immed_flut_full;
static const struct isa_bitset bitset___cat5_src3;
static const struct isa_bitset bitset_sign_f;
static const struct isa_bitset bitset_sad_s32;
static const struct isa_bitset bitset___cat1_immed_src;
static const struct isa_bitset bitset_stl;
static const struct isa_bitset bitset_mgen_b;
static const struct isa_bitset bitset_atomic_b_xchg;
static const struct isa_bitset bitset_saml;
static const struct isa_bitset bitset_mul_u24;
static const struct isa_bitset bitset_atomic_xor;
static const struct isa_bitset bitset_samb;
static const struct isa_bitset bitset_atomic_add;
static const struct isa_bitset bitset_ldc;
static const struct isa_bitset bitset___cat5_samp;
static const struct isa_bitset bitset_min_s;
static const struct isa_bitset bitset_cmps_s;
static const struct isa_bitset bitset_setrm;
static const struct isa_bitset bitset___multisrc_gpr;
static const struct isa_bitset bitset_nop;
static const struct isa_bitset bitset_log2;
static const struct isa_bitset bitset_shl_b;
static const struct isa_bitset bitset_atomic_b_cmpxchg;
static const struct isa_bitset bitset_shps;
static const struct isa_bitset bitset_sel_s32;
static const struct isa_bitset bitset_trunc_f;
static const struct isa_bitset bitset___multisrc_relative_gpr;
static const struct isa_bitset bitset_absneg_f;
static const struct isa_bitset bitset_getsize;
static const struct isa_bitset bitset___cat1_dst;
static const struct isa_bitset bitset___cat6_base;
static const struct isa_bitset bitset_mad_f32;
static const struct isa_bitset bitset_or_b;
static const struct isa_bitset bitset_cmpv_s;
static const struct isa_bitset bitset_min_f;
static const struct isa_bitset bitset_ldl;
static const struct isa_bitset bitset___cat5_src1;
static const struct isa_bitset bitset_min_u;
static const struct isa_bitset bitset___cat5_type;
static const struct isa_bitset bitset_mad_s16;
static const struct isa_bitset bitset_predt;
static const struct isa_bitset bitset_ret;
static const struct isa_bitset bitset_cmps_u;
static const struct isa_bitset bitset_atomic_b_or;
static const struct isa_bitset bitset_atomic_cmpxchg;
static const struct isa_bitset bitset_sin;
static const struct isa_bitset bitset___cat5_src2;
static const struct isa_bitset bitset___cat1_relative_gpr_src;
static const struct isa_bitset bitset___multisrc_relative;
static const struct isa_bitset bitset_samgp3;
static const struct isa_bitset bitset_atomic_inc;
static const struct isa_bitset bitset_atomic_dec;
static const struct isa_bitset bitset_sqrt;
static const struct isa_bitset bitset_shpe;
static const struct isa_bitset bitset_add_u;
static const struct isa_bitset bitset_dsy;
static const struct isa_bitset bitset___instruction_cat6_a3xx_st;
static const struct isa_bitset bitset_brac;
static const struct isa_bitset bitset_atomic_min;
static const struct isa_bitset bitset_bary_f;
static const struct isa_bitset bitset_jump;
static const struct isa_bitset bitset_call;
static const struct isa_bitset bitset___reg_gpr;
static const struct isa_bitset bitset_max_f;
static const struct isa_bitset bitset_getpos;
static const struct isa_bitset bitset___cat5_s2en_bindless_base;
static const struct isa_bitset bitset_dsxpp_1;
static const struct isa_bitset bitset_atomic_and;
static const struct isa_bitset bitset___mulitsrc_immed;
static const struct isa_bitset bitset_samgp0;
static const struct isa_bitset bitset_resinfo;
static const struct isa_bitset bitset_rcp;
static const struct isa_bitset bitset_gather4r;
static const struct isa_bitset bitset_ball;
static const struct isa_bitset bitset_add_s;
static const struct isa_bitset bitset_atomic_or;
static const struct isa_bitset bitset_gather4a;
static const struct isa_bitset bitset_atomic_b_xor;
static const struct isa_bitset bitset_add_f;
static const struct isa_bitset bitset_ldlw;
static const struct isa_bitset bitset___instruction_cat1_mov;
static const struct isa_bitset bitset_hexp2;
static const struct isa_bitset bitset_atomic_xchg;
static const struct isa_bitset bitset_atomic_b_min;
static const struct isa_bitset bitset___instruction_cat6;
static const struct isa_bitset bitset_chsh;
static const struct isa_bitset bitset_chmask;
static const struct isa_bitset bitset_hrsq;
static const struct isa_bitset bitset_emit;
static const struct isa_bitset bitset_getlod;
static const struct isa_bitset bitset_madsh_u16;
static const struct isa_bitset bitset_rndaz_f;
static const struct isa_bitset bitset___instruction_cat0_1src;
static const struct isa_bitset bitset___instruction_cat0;
static const struct isa_bitset bitset_samgp2;
static const struct isa_bitset bitset_cos;
static const struct isa_bitset bitset_stc;
static const struct isa_bitset bitset___cat3_src_gpr;
static const struct isa_bitset bitset_clz_b;
static const struct isa_bitset bitset___instruction_cat6_a3xx_atomic_2src;
static const struct isa_bitset bitset___instruction_cat1;
static const struct isa_bitset bitset_mov_relgpr;
static const struct isa_bitset bitset___instruction_cat2_1src;
static const struct isa_bitset bitset_atomic_max;
static const struct isa_bitset bitset_cmpv_u;
static const struct isa_bitset bitset_getspid;
static const struct isa_bitset bitset_ceil_f;
static const struct isa_bitset bitset_resinfo_b;
static const struct isa_bitset bitset_rsq;
static const struct isa_bitset bitset_sad_s16;
static const struct isa_bitset bitset___instruction_cat4;
static const struct isa_bitset bitset_rgetpos;
static const struct isa_bitset bitset_stg;
static const struct isa_bitset bitset_atomic_b_sub;
static const struct isa_bitset bitset_mul_f;
static const struct isa_bitset bitset___cat3_src_relative;
static const struct isa_bitset bitset___cat5_tex;
static const struct isa_bitset bitset___mulitsrc_immed_flut;
static const struct isa_bitset bitset_sub_s;
static const struct isa_bitset bitset_end;
static const struct isa_bitset bitset___multisrc;
static const struct isa_bitset bitset_stgb;
static const struct isa_bitset bitset_bany;
static const struct isa_bitset bitset___cat6_typed;
static const struct isa_bitset bitset_hlog2;
static const struct isa_bitset bitset_absneg_s;
static const struct isa_bitset bitset_clz_s;
static const struct isa_bitset bitset___instruction_cat6_a3xx_ld;
static const struct isa_bitset bitset___instruction_cat1_relative;
static const struct isa_bitset bitset_sel_b32;
static const struct isa_bitset bitset_ldgb;
static const struct isa_bitset bitset_bkt;
static const struct isa_bitset bitset___cat6_src;
static const struct isa_bitset bitset_and_b;
static const struct isa_bitset bitset___cat3_src;
static const struct isa_bitset bitset_sel_s16;
static const struct isa_bitset bitset_movmsk;
static const struct isa_bitset bitset___instruction_cat7;
static const struct isa_bitset bitset_samgp1;
static const struct isa_bitset bitset_dsypp_1;
static const struct isa_bitset bitset___instruction_cat0_branch;
static const struct isa_bitset bitset_brax;
static const struct isa_bitset bitset_brao;
static const struct isa_bitset bitset_mov_relconst;
static const struct isa_bitset bitset_ldlv;
static const struct isa_bitset bitset_stib;
static const struct isa_bitset bitset___cat5_samp_s2en_bindless_a1;
static const struct isa_bitset bitset_br;
static const struct isa_bitset bitset_bfrev_b;
static const struct isa_bitset bitset_dsx;
static const struct isa_bitset bitset___instruction_cat6_a3xx;
static const struct isa_bitset bitset_gather4b;
static const struct isa_bitset bitset_ashr_b;
static const struct isa_bitset bitset___instruction_cat6_a6xx;
static const struct isa_bitset bitset___instruction_cat2_2src;
static const struct isa_bitset bitset___cat3_src_relative_gpr;
static const struct isa_bitset bitset___multisrc_immed_flut_half;
static const struct isa_bitset bitset_isaml;
static const struct isa_bitset bitset_gather4g;
static const struct isa_bitset bitset_mul_s24;
static const struct isa_bitset bitset___instruction_cat5;
static const struct isa_bitset bitset_atomic_b_add;
static const struct isa_bitset bitset___instruction;
static const struct isa_bitset bitset_mov_const;
static const struct isa_bitset bitset___cat1_const_src;
static const struct isa_bitset bitset___instruction_cat2_2src_cond;
static const struct isa_bitset bitset_prede;
static const struct isa_bitset bitset_bar;
static const struct isa_bitset bitset_sel_f32;
static const struct isa_bitset bitset_conv;
static const struct isa_bitset bitset_isam;
static const struct isa_bitset bitset_samgq;
static const struct isa_bitset bitset_predf;
static const struct isa_bitset bitset___instruction_cat0_branch_1src;
static const struct isa_bitset bitset_mad_f16;
static const struct isa_bitset bitset_stp;
static const struct isa_bitset bitset___reg_relative_gpr;
static const struct isa_bitset bitset_ldp;
static const struct isa_bitset bitset_flow_rev;
static const struct isa_bitset bitset_mad_u16;
static const struct isa_bitset bitset_kill;
static const struct isa_bitset bitset___instruction_cat6_a3xx_atomic_1src;
static const struct isa_bitset bitset_sel_f16;
static const struct isa_bitset bitset_sub_u;
static const struct isa_bitset bitset_atomic_sub;
static const struct isa_bitset bitset_convm;
static const struct isa_bitset bitset_mad_u24;
static const struct isa_bitset bitset_fence;
static const struct isa_bitset bitset___instruction_cat6_a3xx_ibo;
static const struct isa_bitset bitset_madsh_m16;
static const struct isa_bitset bitset_getbuf;
static const struct isa_bitset bitset_cbits_b;
static const struct isa_bitset bitset_atomic_b_and;
static const struct isa_bitset bitset___instruction_cat6_a3xx_atomic;
static const struct isa_bitset bitset_stlw;
static const struct isa_bitset bitset___instruction_cat0_branch_2src;
static const struct isa_bitset bitset_not_b;
static const struct isa_bitset bitset_rndne_f;
static const struct isa_bitset bitset___reg_const;

const struct isa_bitset *__cat5_type[];
const struct isa_bitset *__cat6_src[];
const struct isa_bitset *__cat3_src[];
const struct isa_bitset *__cat5_samp_s2en_bindless_a1[];
const struct isa_bitset *__cat6_typed[];
const struct isa_bitset *__cat1_relative_gpr_src[];
const struct isa_bitset *__reg_gpr[];
const struct isa_bitset *__reg_relative_const[];
const struct isa_bitset *__reg_relative_gpr[];
const struct isa_bitset *__cat1_relative_const_src[];
const struct isa_bitset *__cat5_src2[];
const struct isa_bitset *__cat5_tex[];
const struct isa_bitset *__cat1_gpr_src[];
const struct isa_bitset *__cat1_dst[];
const struct isa_bitset *__cat6_base[];
const struct isa_bitset *__cat5_src3[];
const struct isa_bitset *__cat5_s2en_bindless_base[];
const struct isa_bitset *__multisrc[];
const struct isa_bitset *__cat1_immed_src[];
const struct isa_bitset *__cat5_tex_s2en_bindless[];
const struct isa_bitset *__cat5_src1[];
const struct isa_bitset *__cat5_samp[];
const struct isa_bitset *__instruction[];
const struct isa_bitset *__reg_const[];
const struct isa_bitset *__cat1_const_src[];

/*
 * bitset tables:
 */

static const struct isa_case __instruction_cat3__case0 = {
       .expr     = &expr___cat2_cat3_nop_encoding,
       .display  = "{SY}{SS}{JP}{SAT}(nop{NOP}) {UL}{NAME} {DST_HALF}{DST}, {SRC1_NEG}{SRC1}, {SRC2_NEG}{HALF}{SRC2}, {SRC3_NEG}{SRC3}",
       .num_fields = 1,
       .fields   = {
          { .name = "NOP", .low = 0, .high = 0,
            .expr = &expr___cat2_cat3_nop_value,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_field_params __instruction_cat3__default_src1 = {
       .num_params = 1,
       .params = {
           { .name= "HALF",  .as = "HALF" },

       },
};
static const struct isa_field_params __instruction_cat3__default_src3 = {
       .num_params = 1,
       .params = {
           { .name= "HALF",  .as = "HALF" },

       },
};
static const struct isa_case __instruction_cat3__default = {
       .display  = "{SY}{SS}{JP}{SAT}{REPEAT}{UL}{NAME} {DST_HALF}{DST}, {SRC1_NEG}{SRC1_R}{SRC1}, {SRC2_NEG}{SRC2_R}{HALF}{SRC2}, {SRC3_NEG}{SRC3_R}{SRC3}",
       .num_fields = 19,
       .fields   = {
          { .name = "DST_CONV", .low = 46, .high = 46,
            .type = TYPE_BOOL,
          },
          { .name = "DST_HALF", .low = 0, .high = 0,
            .expr = &expr___dest_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "SRC1_NEG", .low = 14, .high = 14,
            .display = "(neg)",
            .type = TYPE_BOOL,
          },
          { .name = "JP", .low = 59, .high = 59,
            .display = "(jp)",
            .type = TYPE_BOOL,
          },
          { .name = "SRC2_NEG", .low = 30, .high = 30,
            .display = "(neg)",
            .type = TYPE_BOOL,
          },
          { .name = "SS", .low = 44, .high = 44,
            .display = "(ss)",
            .type = TYPE_BOOL,
          },
          { .name = "REPEAT", .low = 40, .high = 41,
            .type = TYPE_ENUM,
            .enums = &enum___rptn,
          },
          { .name = "SRC2_R", .low = 15, .high = 15,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
          { .name = "SAT", .low = 42, .high = 42,
            .display = "(sat)",
            .type = TYPE_BOOL,
          },
          { .name = "HALF", .low = 0, .high = 0,
            .expr = &expr___multisrc_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SY", .low = 60, .high = 60,
            .display = "(sy)",
            .type = TYPE_BOOL,
          },
          { .name = "SRC1", .low = 0, .high = 12,
            .type = TYPE_BITSET,
            .bitsets = __cat3_src,
            .params = &__instruction_cat3__default_src1,
          },
          { .name = "SRC3", .low = 16, .high = 28,
            .type = TYPE_BITSET,
            .bitsets = __cat3_src,
            .params = &__instruction_cat3__default_src3,
          },
          { .name = "SRC3_NEG", .low = 31, .high = 31,
            .display = "(neg)",
            .type = TYPE_BOOL,
          },
          { .name = "UL", .low = 45, .high = 45,
            .display = "(ul)",
            .type = TYPE_BOOL,
          },
          { .name = "SRC2", .low = 47, .high = 54,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC1_R", .low = 43, .high = 43,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
          { .name = "SRC3_R", .low = 29, .high = 29,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat3 = {

       .parent   = &bitset___instruction,
       .name     = "#instruction-cat3",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6000000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe000000000002000,
       .num_cases = 2,
       .cases    = {
            &__instruction_cat3__case0,
            &__instruction_cat3__default,
       },
};
static const struct isa_case sel_b16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sel_b16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "sel.b16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6400000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &sel_b16__default,
       },
};
static const struct isa_case floor_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_floor_f = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "floor.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4120000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &floor_f__default,
       },
};
static const struct isa_case cmps_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cmps_f = {

       .parent   = &bitset___instruction_cat2_2src_cond,
       .name     = "cmps.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x40a0000000000000,
       .dontcare = 0x0,
       .mask     = 0xe7e0000000000000,
       .num_cases = 1,
       .cases    = {
            &cmps_f__default,
       },
};
static const struct isa_case isamm__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_isamm = {

       .parent   = &bitset___instruction_cat5,
       .name     = "isamm",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa080000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &isamm__default,
       },
};
static const struct isa_case __instruction_cat0_immed__default = {
       .display  = "{SY}{SS}{JP}{NAME} #{IMMED}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___instruction_cat0_immed = {

       .parent   = &bitset___instruction_cat0,
       .name     = "#instruction-cat0-immed",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x70e8ff00000000,
       .mask     = 0xe070e8ff00000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat0_immed__default,
       },
};
static const struct isa_case mull_u__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_mull_u = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "mull.u",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4640000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &mull_u__default,
       },
};
static const struct isa_case rgetinfo__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___zero,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_rgetinfo = {

       .parent   = &bitset___instruction_cat5,
       .name     = "rgetinfo",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa6c0000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &rgetinfo__default,
       },
};
static const struct isa_case __cat3_src_relative_const__default = {
       .display  = "{HALF}c<a0.x + {OFFSET}>",
       .num_fields = 1,
       .fields   = {
          { .name = "OFFSET", .low = 0, .high = 9,
            .type = TYPE_INT,
          },
       },
};
static const struct isa_bitset bitset___cat3_src_relative_const = {

       .parent   = &bitset___cat3_src_relative,
       .name     = "#cat3-src-relative-const",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc00,
       .dontcare = 0x0,
       .mask     = 0x1c00,
       .num_cases = 1,
       .cases    = {
            &__cat3_src_relative_const__default,
       },
};
static const struct isa_case __cat5_tex_s2en_bindless__case0 = {
       .expr     = &expr_anon_22,
       .display  = ", t#{TEX}",
       .num_fields = 1,
       .fields   = {
          { .name = "TEX", .low = 0, .high = 3,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_case __cat5_tex_s2en_bindless__default = {
       .display  = "",
       .num_fields = 1,
       .fields   = {
          { .name = "#cat5-tex-s2en-bindless#assert0", .low = 0, .high = 3,
            .type = TYPE_ASSERT,
            .val = 0,
          },
       },
};
static const struct isa_bitset bitset___cat5_tex_s2en_bindless = {

       .name     = "#cat5-tex-s2en-bindless",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat5_tex_s2en_bindless__case0,
            &__cat5_tex_s2en_bindless__default,
       },
};
static const struct isa_case exp2__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_exp2 = {

       .parent   = &bitset___instruction_cat4,
       .name     = "exp2",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8060000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &exp2__default,
       },
};
static const struct isa_case ldg__case0 = {
       .expr     = &expr_anon_25,
       .display  = "{SY}{JP}{NAME}.{TYPE} {DST}, g[{SRC1}{OFF}], {SIZE}",
       .num_fields = 1,
       .fields   = {
          { .name = "OFF", .low = 1, .high = 13,
            .type = TYPE_OFFSET,
          },
       },
};
static const struct isa_case ldg__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} {DST}, g[{SRC1}+{SRC2}], {SIZE}",
       .num_fields = 6,
       .fields   = {
          { .name = "SIZE", .low = 24, .high = 31,
            .type = TYPE_UINT,
          },
          { .name = "ldg#assert0", .low = 9, .high = 13,
            .type = TYPE_ASSERT,
            .val = 0,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC1", .low = 14, .high = 21,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC2_REG", .low = 22, .high = 22,
            .type = TYPE_BOOL,
          },
          { .name = "SRC2", .low = 1, .high = 8,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset_ldg = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "ldg",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000000000800001,
       .dontcare = 0x1ff0000000000,
       .mask     = 0xe7f1ff0000800001,
       .num_cases = 2,
       .cases    = {
            &ldg__case0,
            &ldg__default,
       },
};
static const struct isa_case __cat1_relative_const_src__default = {
       .display  = "{SRC_R}{HALF}{SRC}",
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 9,
            .type = TYPE_BITSET,
            .bitsets = __reg_relative_const,
          },
       },
};
static const struct isa_bitset bitset___cat1_relative_const_src = {

       .name     = "#cat1-relative-const-src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 1,
       .cases    = {
            &__cat1_relative_const_src__default,
       },
};
static const struct isa_case shb__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_shb = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "shb",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x47c0000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &shb__default,
       },
};
static const struct isa_case sam__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sam = {

       .parent   = &bitset___instruction_cat5,
       .name     = "sam",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa0c0000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &sam__default,
       },
};
static const struct isa_case __cat1_gpr_src__default = {
       .display  = "{SRC_R}{HALF}{SRC}",
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset___cat1_gpr_src = {

       .name     = "#cat1-gpr-src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 1,
       .cases    = {
            &__cat1_gpr_src__default,
       },
};
static const struct isa_field_params mov_immed__default_src = {
       .num_params = 1,
       .params = {
           { .name= "SRC_TYPE",  .as = "SRC_TYPE" },

       },
};
static const struct isa_case mov_immed__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __cat1_immed_src,
            .params = &mov_immed__default_src,
          },
       },
};
static const struct isa_bitset bitset_mov_immed = {

       .parent   = &bitset___instruction_cat1_mov,
       .name     = "mov-immed",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2040000000000000,
       .dontcare = 0x0,
       .mask     = 0xe660080000000000,
       .num_cases = 1,
       .cases    = {
            &mov_immed__default,
       },
};
static const struct isa_case mad_s24__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_mad_s24 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "mad.s24",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6280000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &mad_s24__default,
       },
};
static const struct isa_case cut__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cut = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "cut",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x400000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &cut__default,
       },
};
static const struct isa_case getbit_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_getbit_b = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "getbit.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4760000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &getbit_b__default,
       },
};
static const struct isa_case shr_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_shr_b = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "shr.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x46e0000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &shr_b__default,
       },
};
static const struct isa_field_params mov_gpr__default_src = {
       .num_params = 2,
       .params = {
           { .name= "SRC_R",  .as = "SRC_R" },
           { .name= "HALF",  .as = "HALF" },

       },
};
static const struct isa_case mov_gpr__default = {
       .num_fields = 2,
       .fields   = {
          { .name = "SRC_R", .low = 43, .high = 43,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
          { .name = "SRC", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __cat1_gpr_src,
            .params = &mov_gpr__default_src,
          },
       },
};
static const struct isa_bitset bitset_mov_gpr = {

       .parent   = &bitset___instruction_cat1_mov,
       .name     = "mov-gpr",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2000000000000000,
       .dontcare = 0x0,
       .mask     = 0xe6600000ffffff00,
       .num_cases = 1,
       .cases    = {
            &mov_gpr__default,
       },
};
static const struct isa_case max_u__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_max_u = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "max.u",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4300000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &max_u__default,
       },
};
static const struct isa_case msad__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_msad = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "msad",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x47e0000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &msad__default,
       },
};
static const struct isa_case atomic_b_max__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_max = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.max",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc03000000065c001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_max__default,
       },
};
static const struct isa_case stib_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_stib_b = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "stib.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc020000000674000,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &stib_b__default,
       },
};
static const struct isa_case __instruction_cat2__default = {
       .num_fields = 14,
       .fields   = {
          { .name = "DST_CONV", .low = 46, .high = 46,
            .type = TYPE_BOOL,
          },
          { .name = "SRC1_R", .low = 43, .high = 43,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
          { .name = "ZERO", .low = 0, .high = 0,
            .expr = &expr___zero,
            .display = "",
            .type = TYPE_BOOL,
          },
          { .name = "DST_HALF", .low = 0, .high = 0,
            .expr = &expr___dest_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "JP", .low = 59, .high = 59,
            .display = "(jp)",
            .type = TYPE_BOOL,
          },
          { .name = "SS", .low = 44, .high = 44,
            .display = "(ss)",
            .type = TYPE_BOOL,
          },
          { .name = "REPEAT", .low = 40, .high = 41,
            .type = TYPE_ENUM,
            .enums = &enum___rptn,
          },
          { .name = "EI", .low = 47, .high = 47,
            .display = "(ei)",
            .type = TYPE_BOOL,
          },
          { .name = "SAT", .low = 42, .high = 42,
            .display = "(sat)",
            .type = TYPE_BOOL,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "FULL", .low = 52, .high = 52,
            .type = TYPE_BOOL,
          },
          { .name = "SRC2_R", .low = 51, .high = 51,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
          { .name = "UL", .low = 45, .high = 45,
            .display = "(ul)",
            .type = TYPE_BOOL,
          },
          { .name = "SY", .low = 60, .high = 60,
            .display = "(sy)",
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat2 = {

       .parent   = &bitset___instruction,
       .name     = "#instruction-cat2",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4000000000000000,
       .dontcare = 0x0,
       .mask     = 0xe000000000000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat2__default,
       },
};
static const struct isa_case __cat3_src_const__default = {
       .display  = "{HALF}c{CONST}.{SWIZ}",
       .num_fields = 2,
       .fields   = {
          { .name = "CONST", .low = 2, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "SWIZ", .low = 0, .high = 1,
            .type = TYPE_ENUM,
            .enums = &enum___swiz,
          },
       },
};
static const struct isa_bitset bitset___cat3_src_const = {

       .parent   = &bitset___cat3_src,
       .name     = "#cat3-src-const",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x1000,
       .dontcare = 0x0,
       .mask     = 0x1800,
       .num_cases = 1,
       .cases    = {
            &__cat3_src_const__default,
       },
};
static const struct isa_case cmpv_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cmpv_f = {

       .parent   = &bitset___instruction_cat2_2src_cond,
       .name     = "cmpv.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x40e0000000000000,
       .dontcare = 0x0,
       .mask     = 0xe7e0000000000000,
       .num_cases = 1,
       .cases    = {
            &cmpv_f__default,
       },
};
static const struct isa_case getinfo__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___zero,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_getinfo = {

       .parent   = &bitset___instruction_cat5,
       .name     = "getinfo",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa340000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &getinfo__default,
       },
};
static const struct isa_case braa__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_braa = {

       .parent   = &bitset___instruction_cat0_branch_2src,
       .name     = "braa",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80004000000000,
       .dontcare = 0xc081f00000000,
       .mask     = 0xe78e08ff00000000,
       .num_cases = 1,
       .cases    = {
            &braa__default,
       },
};
static const struct isa_case __multisrc_const__default = {
       .display  = "{ABSNEG}{SRC_R}{HALF}{SRC}",
       .num_fields = 3,
       .fields   = {
          { .name = "ABSNEG", .low = 14, .high = 15,
            .type = TYPE_ENUM,
            .enums = &enum___absneg,
          },
          { .name = "HALF", .low = 0, .high = 0,
            .expr = &expr___multisrc_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "SRC", .low = 0, .high = 10,
            .type = TYPE_BITSET,
            .bitsets = __reg_const,
          },
       },
};
static const struct isa_bitset bitset___multisrc_const = {

       .parent   = &bitset___multisrc,
       .name     = "#multisrc-const",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x1000,
       .dontcare = 0x2000,
       .mask     = 0x3800,
       .num_cases = 1,
       .cases    = {
            &__multisrc_const__default,
       },
};
static const struct isa_case xor_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_xor_b = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "xor.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x43e0000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &xor_b__default,
       },
};
static const struct isa_case max_s__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_max_s = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "max.s",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4320000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &max_s__default,
       },
};
static const struct isa_field_params __instruction_cat6_a6xx_ibo__default_ssbo = {
       .num_params = 1,
       .params = {
           { .name= "SSBO_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_case __instruction_cat6_a6xx_ibo__default = {
       .display  = "{SY}{JP}{NAME}.{TYPED}.{D}d.{TYPE}.{TYPE_SIZE}.{MODE}{BASE} {SRC1}, {SRC2}, {SSBO}",
       .num_fields = 9,
       .fields   = {
          { .name = "TYPED", .low = 11, .high = 11,
            .type = TYPE_BITSET,
            .bitsets = __cat6_typed,
          },
          { .name = "TRUE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "D_MINUS_ONE", .low = 9, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "SSBO_IM", .low = 0, .high = 0,
            .expr = &expr___cat6_direct,
            .type = TYPE_BOOL,
          },
          { .name = "SRC1", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "D", .low = 0, .high = 0,
            .expr = &expr___cat6_d,
            .type = TYPE_UINT,
          },
          { .name = "TYPE", .low = 49, .high = 51,
            .type = TYPE_ENUM,
            .enums = &enum___type,
          },
          { .name = "SSBO", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &__instruction_cat6_a6xx_ibo__default_ssbo,
          },
          { .name = "SRC2", .low = 24, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat6_a6xx_ibo = {

       .parent   = &bitset___instruction_cat6_a6xx,
       .name     = "#instruction-cat6-a6xx-ibo",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000000000600000,
       .dontcare = 0x0,
       .mask     = 0xe7c0010000f00030,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6_a6xx_ibo__default,
       },
};
static const struct isa_case __multisrc_relative_const__default = {
       .display  = "{ABSNEG}{SRC_R}{HALF}{SRC}",
       .num_fields = 2,
       .fields   = {
          { .name = "HALF", .low = 0, .high = 0,
            .expr = &expr___multisrc_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "SRC", .low = 0, .high = 9,
            .type = TYPE_BITSET,
            .bitsets = __reg_relative_const,
          },
       },
};
static const struct isa_bitset bitset___multisrc_relative_const = {

       .parent   = &bitset___multisrc_relative,
       .name     = "#multisrc-relative-const",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc00,
       .dontcare = 0x0,
       .mask     = 0x3c00,
       .num_cases = 1,
       .cases    = {
            &__multisrc_relative_const__default,
       },
};
static const struct isa_case ldib_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_ldib_b = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "ldib.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc020000000618000,
       .dontcare = 0x1,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &ldib_b__default,
       },
};
static const struct isa_case __reg_relative_const__case0 = {
       .expr     = &expr___offset_zero,
       .display  = "c<a0.x>",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_case __reg_relative_const__default = {
       .display  = "c<a0.x + {OFFSET}>",
       .num_fields = 1,
       .fields   = {
          { .name = "OFFSET", .low = 0, .high = 9,
            .type = TYPE_INT,
          },
       },
};
static const struct isa_bitset bitset___reg_relative_const = {

       .name     = "#reg-relative-const",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__reg_relative_const__case0,
            &__reg_relative_const__default,
       },
};
static const struct isa_case getone__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_getone = {

       .parent   = &bitset___instruction_cat0_immed,
       .name     = "getone",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x282000000000000,
       .dontcare = 0x7ce8ff00000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &getone__default,
       },
};
static const struct isa_case __instruction_cat0_0src__default = {
       .display  = "{SY}{SS}{EQ}{JP}{REPEAT}{NAME}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___instruction_cat0_0src = {

       .parent   = &bitset___instruction_cat0,
       .name     = "#instruction-cat0-0src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x80000000000,
       .mask     = 0xe070e8ff00000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat0_0src__default,
       },
};
static const struct isa_case getwid__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} {DST}",
       .num_fields = 2,
       .fields   = {
          { .name = "TYPE", .low = 49, .high = 51,
            .type = TYPE_ENUM,
            .enums = &enum___type,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset_getwid = {

       .parent   = &bitset___instruction_cat6_a6xx,
       .name     = "getwid",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc020000000494000,
       .dontcare = 0x11fe00ffb00e00,
       .mask     = 0xe7f1ff00ffffce31,
       .num_cases = 1,
       .cases    = {
            &getwid__default,
       },
};
static const struct isa_case __multisrc_immed_flut_full__default = {
       .display  = "{ABSNEG}{SRC_R}{IMMED}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___multisrc_immed_flut_full = {

       .parent   = &bitset___mulitsrc_immed_flut,
       .name     = "#multisrc-immed-flut-full",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2800,
       .dontcare = 0x0,
       .mask     = 0x3c00,
       .num_cases = 1,
       .cases    = {
            &__multisrc_immed_flut_full__default,
       },
};
static const struct isa_case __cat5_src3__case0 = {
       .expr     = &expr___cat5_s2enb_is_indirect,
       .display  = ", {SRC_HALF}{SRC}",
       .num_fields = 2,
       .fields   = {
          { .name = "SRC_HALF", .low = 0, .high = 0,
            .expr = &expr_anon_24,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "SRC", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_case __cat5_src3__case1 = {
       .expr     = &expr___cat5_s2enb_uses_a1,
       .display  = "{SAMP}",
       .num_fields = 1,
       .fields   = {
          { .name = "SAMP", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __cat5_samp_s2en_bindless_a1,
          },
       },
};
static const struct isa_field_params __cat5_src3__default_samp = {
       .num_params = 1,
       .params = {
           { .name= "HAS_SAMP",  .as = "HAS_SAMP" },

       },
};
static const struct isa_field_params __cat5_src3__default_tex = {
       .num_params = 1,
       .params = {
           { .name= "HAS_TEX",  .as = "HAS_TEX" },

       },
};
static const struct isa_case __cat5_src3__default = {
       .display  = "{SAMP}{TEX}",
       .num_fields = 2,
       .fields   = {
          { .name = "SAMP", .low = 0, .high = 3,
            .type = TYPE_BITSET,
            .bitsets = __cat5_samp,
            .params = &__cat5_src3__default_samp,
          },
          { .name = "TEX", .low = 4, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __cat5_tex_s2en_bindless,
            .params = &__cat5_src3__default_tex,
          },
       },
};
static const struct isa_bitset bitset___cat5_src3 = {

       .name     = "#cat5-src3",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 3,
       .cases    = {
            &__cat5_src3__case0,
            &__cat5_src3__case1,
            &__cat5_src3__default,
       },
};
static const struct isa_case sign_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_sign_f = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "sign.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4080000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &sign_f__default,
       },
};
static const struct isa_case sad_s32__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sad_s32 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "sad.s32",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6780000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &sad_s32__default,
       },
};
static const struct isa_case __cat1_immed_src__case0 = {
       .expr     = &expr_anon_7,
       .display  = "h({IMMED})",
       .num_fields = 1,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 15,
            .type = TYPE_FLOAT,
          },
       },
};
static const struct isa_case __cat1_immed_src__case1 = {
       .expr     = &expr_anon_8,
       .display  = "({IMMED})",
       .num_fields = 1,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 31,
            .type = TYPE_FLOAT,
          },
       },
};
static const struct isa_case __cat1_immed_src__case2 = {
       .expr     = &expr_anon_9,
       .display  = "0x{IMMED}",
       .num_fields = 1,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 31,
            .type = TYPE_HEX,
          },
       },
};
static const struct isa_case __cat1_immed_src__case3 = {
       .expr     = &expr_anon_10,
       .num_fields = 1,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 15,
            .type = TYPE_INT,
          },
       },
};
static const struct isa_case __cat1_immed_src__case4 = {
       .expr     = &expr_anon_11,
       .num_fields = 1,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 31,
            .type = TYPE_INT,
          },
       },
};
static const struct isa_case __cat1_immed_src__default = {
       .display  = "{IMMED}",
       .num_fields = 1,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 31,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_bitset bitset___cat1_immed_src = {

       .name     = "#cat1-immed-src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 6,
       .cases    = {
            &__cat1_immed_src__case0,
            &__cat1_immed_src__case1,
            &__cat1_immed_src__case2,
            &__cat1_immed_src__case3,
            &__cat1_immed_src__case4,
            &__cat1_immed_src__default,
       },
};
static const struct isa_case stl__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} l[{DST}{OFF}], {SRC}, {SIZE}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_stl = {

       .parent   = &bitset___instruction_cat6_a3xx_st,
       .name     = "stl",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc100010000800000,
       .dontcare = 0x300000007fc001,
       .mask     = 0xe7f0010000ffc001,
       .num_cases = 1,
       .cases    = {
            &stl__default,
       },
};
static const struct isa_case mgen_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_mgen_b = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "mgen.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4740000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &mgen_b__default,
       },
};
static const struct isa_case atomic_b_xchg__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_xchg = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.xchg",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc030000000648001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_xchg__default,
       },
};
static const struct isa_case saml__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___two,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_saml = {

       .parent   = &bitset___instruction_cat5,
       .name     = "saml",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa140000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &saml__default,
       },
};
static const struct isa_case mul_u24__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_mul_u24 = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "mul.u24",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4600000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &mul_u24__default,
       },
};
static const struct isa_case atomic_xor__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_xor = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.xor",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc680000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_xor__default,
       },
};
static const struct isa_case samb__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___two,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_samb = {

       .parent   = &bitset___instruction_cat5,
       .name     = "samb",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa100000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &samb__default,
       },
};
static const struct isa_case atomic_add__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_add = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.add",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc400000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_add__default,
       },
};
static const struct isa_case ldc__case0 = {
       .expr     = &expr_anon_29,
       .display  = "{SY}{JP}{NAME}.{TYPE_SIZE}.k.{MODE}{BASE} c[a1.x], {SRC1}, {SRC2}",
       .num_fields = 1,
       .fields   = {
          { .name = "TYPE_SIZE_MINUS_ONE", .low = 32, .high = 39,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_field_params ldc__default_src1 = {
       .num_params = 1,
       .params = {
           { .name= "SRC1_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_field_params ldc__default_src2 = {
       .num_params = 1,
       .params = {
           { .name= "SRC2_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_case ldc__default = {
       .display  = "{SY}{JP}{NAME}.offset{OFFSET}.{TYPE_SIZE}.{MODE}{BASE} {DST}, {SRC1}, {SRC2}",
       .num_fields = 7,
       .fields   = {
          { .name = "SRC1_IM", .low = 23, .high = 23,
            .type = TYPE_BOOL,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC2_IM", .low = 0, .high = 0,
            .expr = &expr___cat6_direct,
            .type = TYPE_BOOL,
          },
          { .name = "SRC1", .low = 24, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &ldc__default_src1,
          },
          { .name = "K", .low = 52, .high = 52,
            .type = TYPE_BOOL,
          },
          { .name = "OFFSET", .low = 9, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "SRC2", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &ldc__default_src2,
          },
       },
};
static const struct isa_bitset bitset_ldc = {

       .parent   = &bitset___instruction_cat6_a6xx,
       .name     = "ldc",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc026000000478000,
       .dontcare = 0x8000000300801,
       .mask     = 0xe7ee0100007fc831,
       .num_cases = 2,
       .cases    = {
            &ldc__case0,
            &ldc__default,
       },
};
static const struct isa_case __cat5_samp__case0 = {
       .expr     = &expr_anon_19,
       .display  = ", s#{SAMP}",
       .num_fields = 1,
       .fields   = {
          { .name = "SAMP", .low = 0, .high = 3,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_case __cat5_samp__default = {
       .display  = "",
       .num_fields = 1,
       .fields   = {
          { .name = "#cat5-samp#assert0", .low = 0, .high = 3,
            .type = TYPE_ASSERT,
            .val = 0,
          },
       },
};
static const struct isa_bitset bitset___cat5_samp = {

       .name     = "#cat5-samp",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat5_samp__case0,
            &__cat5_samp__default,
       },
};
static const struct isa_case min_s__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_min_s = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "min.s",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x42e0000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &min_s__default,
       },
};
static const struct isa_case cmps_s__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cmps_s = {

       .parent   = &bitset___instruction_cat2_2src_cond,
       .name     = "cmps.s",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x42a0000000000000,
       .dontcare = 0x0,
       .mask     = 0xe7e0000000000000,
       .num_cases = 1,
       .cases    = {
            &cmps_s__default,
       },
};
static const struct isa_case setrm__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_setrm = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "setrm",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4780000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &setrm__default,
       },
};
static const struct isa_case __multisrc_gpr__default = {
       .display  = "{ABSNEG}{SRC_R}{HALF}{SRC}",
       .num_fields = 3,
       .fields   = {
          { .name = "ABSNEG", .low = 14, .high = 15,
            .type = TYPE_ENUM,
            .enums = &enum___absneg,
          },
          { .name = "HALF", .low = 0, .high = 0,
            .expr = &expr___multisrc_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "SRC", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset___multisrc_gpr = {

       .parent   = &bitset___multisrc,
       .name     = "#multisrc-gpr",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x3f00,
       .num_cases = 1,
       .cases    = {
            &__multisrc_gpr__default,
       },
};
static const struct isa_case nop__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_nop = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "nop",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &nop__default,
       },
};
static const struct isa_case log2__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_log2 = {

       .parent   = &bitset___instruction_cat4,
       .name     = "log2",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8040000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &log2__default,
       },
};
static const struct isa_case shl_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_shl_b = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "shl.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x46c0000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &shl_b__default,
       },
};
static const struct isa_case atomic_b_cmpxchg__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_cmpxchg = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.cmpxchg",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc030000000654001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_cmpxchg__default,
       },
};
static const struct isa_case shps__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_shps = {

       .parent   = &bitset___instruction_cat0_immed,
       .name     = "shps",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x382000000000000,
       .dontcare = 0x7ce8ff00000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &shps__default,
       },
};
static const struct isa_case sel_s32__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sel_s32 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "sel.s32",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6580000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &sel_s32__default,
       },
};
static const struct isa_case trunc_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_trunc_f = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "trunc.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x41a0000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &trunc_f__default,
       },
};
static const struct isa_case __multisrc_relative_gpr__default = {
       .display  = "{ABSNEG}{SRC_R}{HALF}{SRC}",
       .num_fields = 2,
       .fields   = {
          { .name = "HALF", .low = 0, .high = 0,
            .expr = &expr___multisrc_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "SRC", .low = 0, .high = 9,
            .type = TYPE_BITSET,
            .bitsets = __reg_relative_gpr,
          },
       },
};
static const struct isa_bitset bitset___multisrc_relative_gpr = {

       .parent   = &bitset___multisrc_relative,
       .name     = "#multisrc-relative-gpr",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x800,
       .dontcare = 0x0,
       .mask     = 0x3c00,
       .num_cases = 1,
       .cases    = {
            &__multisrc_relative_gpr__default,
       },
};
static const struct isa_case absneg_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_absneg_f = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "absneg.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x40c0000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &absneg_f__default,
       },
};
static const struct isa_case getsize__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_getsize = {

       .parent   = &bitset___instruction_cat5,
       .name     = "getsize",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa280000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &getsize__default,
       },
};
static const struct isa_case __cat1_dst__case0 = {
       .expr     = &expr_anon_0,
       .display  = "r<a0.x>",
       .num_fields = 1,
       .fields   = {
          { .name = "OFFSET", .low = 0, .high = 7,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_case __cat1_dst__case1 = {
       .expr     = &expr_anon_1,
       .display  = "r<a0.x + {OFFSET}>",
       .num_fields = 1,
       .fields   = {
          { .name = "OFFSET", .low = 0, .high = 7,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_case __cat1_dst__default = {
       .display  = "{DST}",
       .num_fields = 1,
       .fields   = {
          { .name = "DST", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset___cat1_dst = {

       .name     = "#cat1-dst",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 3,
       .cases    = {
            &__cat1_dst__case0,
            &__cat1_dst__case1,
            &__cat1_dst__default,
       },
};
static const struct isa_case __cat6_base__case0 = {
       .expr     = &expr_anon_31,
       .display  = ".base{BASE}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_case __cat6_base__default = {
       .display  = "",
       .num_fields = 1,
       .fields   = {
          { .name = "BASE", .low = 0, .high = 2,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_bitset bitset___cat6_base = {

       .name     = "#cat6-base",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat6_base__case0,
            &__cat6_base__default,
       },
};
static const struct isa_case mad_f32__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_mad_f32 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "mad.f32",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6380000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &mad_f32__default,
       },
};
static const struct isa_case or_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_or_b = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "or.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x43a0000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &or_b__default,
       },
};
static const struct isa_case cmpv_s__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cmpv_s = {

       .parent   = &bitset___instruction_cat2_2src_cond,
       .name     = "cmpv.s",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4440000000000000,
       .dontcare = 0x0,
       .mask     = 0xe7e0000000000000,
       .num_cases = 1,
       .cases    = {
            &cmpv_s__default,
       },
};
static const struct isa_case min_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_min_f = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "min.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4020000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &min_f__default,
       },
};
static const struct isa_case ldl__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} {DST}, l[{SRC}{OFF}], {SIZE}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_ldl = {

       .parent   = &bitset___instruction_cat6_a3xx_ld,
       .name     = "ldl",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc040000000800001,
       .dontcare = 0x31ff0000400000,
       .mask     = 0xe7f1ff0000c00001,
       .num_cases = 1,
       .cases    = {
            &ldl__default,
       },
};
static const struct isa_case __cat5_src1__case0 = {
       .expr     = &expr_anon_17,
       .display  = ", {HALF}{SRC}",
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_case __cat5_src1__default = {
       .display  = "",
       .num_fields = 1,
       .fields   = {
          { .name = "#cat5-src1#assert0", .low = 0, .high = 7,
            .type = TYPE_ASSERT,
            .val = 0,
          },
       },
};
static const struct isa_bitset bitset___cat5_src1 = {

       .name     = "#cat5-src1",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat5_src1__case0,
            &__cat5_src1__default,
       },
};
static const struct isa_case min_u__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_min_u = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "min.u",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x42c0000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &min_u__default,
       },
};
static const struct isa_case __cat5_type__case0 = {
       .expr     = &expr_anon_23,
       .display  = "({TYPE})",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_case __cat5_type__default = {
       .display  = "",
       .num_fields = 1,
       .fields   = {
          { .name = "TYPE", .low = 0, .high = 2,
            .type = TYPE_ENUM,
            .enums = &enum___type,
          },
       },
};
static const struct isa_bitset bitset___cat5_type = {

       .name     = "#cat5-type",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat5_type__case0,
            &__cat5_type__default,
       },
};
static const struct isa_case mad_s16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_mad_s16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "mad.s16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6100000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &mad_s16__default,
       },
};
static const struct isa_case predt__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_predt = {

       .parent   = &bitset___instruction_cat0_1src,
       .name     = "predt",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x682000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe78ee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &predt__default,
       },
};
static const struct isa_case ret__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_ret = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "ret",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x200000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &ret__default,
       },
};
static const struct isa_case cmps_u__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cmps_u = {

       .parent   = &bitset___instruction_cat2_2src_cond,
       .name     = "cmps.u",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4280000000000000,
       .dontcare = 0x0,
       .mask     = 0xe7e0000000000000,
       .num_cases = 1,
       .cases    = {
            &cmps_u__default,
       },
};
static const struct isa_case atomic_b_or__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_or = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.or",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc030000000664001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_or__default,
       },
};
static const struct isa_case atomic_cmpxchg__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_cmpxchg = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.cmpxchg",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc540000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_cmpxchg__default,
       },
};
static const struct isa_case sin__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_sin = {

       .parent   = &bitset___instruction_cat4,
       .name     = "sin",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8080000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &sin__default,
       },
};
static const struct isa_case __cat5_src2__case0 = {
       .expr     = &expr_anon_18,
       .display  = ", {HALF}{SRC}",
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_case __cat5_src2__default = {
       .display  = "",
       .num_fields = 1,
       .fields   = {
          { .name = "#cat5-src2#assert0", .low = 0, .high = 7,
            .type = TYPE_ASSERT,
            .val = 0,
          },
       },
};
static const struct isa_bitset bitset___cat5_src2 = {

       .name     = "#cat5-src2",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat5_src2__case0,
            &__cat5_src2__default,
       },
};
static const struct isa_case __cat1_relative_gpr_src__default = {
       .display  = "{SRC_R}{HALF}{SRC}",
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 9,
            .type = TYPE_BITSET,
            .bitsets = __reg_relative_gpr,
          },
       },
};
static const struct isa_bitset bitset___cat1_relative_gpr_src = {

       .name     = "#cat1-relative-gpr-src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 1,
       .cases    = {
            &__cat1_relative_gpr_src__default,
       },
};
static const struct isa_case __multisrc_relative__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "ABSNEG", .low = 14, .high = 15,
            .type = TYPE_ENUM,
            .enums = &enum___absneg,
          },
       },
};
static const struct isa_bitset bitset___multisrc_relative = {

       .parent   = &bitset___multisrc,
       .name     = "#multisrc-relative",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x800,
       .dontcare = 0x0,
       .mask     = 0x3800,
       .num_cases = 1,
       .cases    = {
            &__multisrc_relative__default,
       },
};
static const struct isa_case samgp3__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_samgp3 = {

       .parent   = &bitset___instruction_cat5,
       .name     = "samgp3",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa5c0000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &samgp3__default,
       },
};
static const struct isa_case atomic_inc__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_inc = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_1src,
       .name     = "atomic.inc",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc4c0000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_inc__default,
       },
};
static const struct isa_case atomic_dec__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_dec = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_1src,
       .name     = "atomic.dec",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc500000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_dec__default,
       },
};
static const struct isa_case sqrt__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_sqrt = {

       .parent   = &bitset___instruction_cat4,
       .name     = "sqrt",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80c0000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &sqrt__default,
       },
};
static const struct isa_case shpe__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_shpe = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "shpe",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x402000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &shpe__default,
       },
};
static const struct isa_case add_u__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_add_u = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "add.u",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4200000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &add_u__default,
       },
};
static const struct isa_case dsy__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_dsy = {

       .parent   = &bitset___instruction_cat5,
       .name     = "dsy",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa3c0000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &dsy__default,
       },
};
static const struct isa_case __instruction_cat6_a3xx_st__default = {
       .num_fields = 6,
       .fields   = {
          { .name = "OFF", .low = 0, .high = 13 - 1,
            .expr = &expr_anon_28,
            .type = TYPE_OFFSET,
          },
          { .name = "OFF_HI", .low = 9, .high = 13,
            .type = TYPE_UINT,
          },
          { .name = "DST", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC", .low = 1, .high = 8,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SIZE", .low = 24, .high = 31,
            .type = TYPE_UINT,
          },
          { .name = "OFF_LO", .low = 32, .high = 39,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat6_a3xx_st = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "#instruction-cat6-a3xx-st",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000010000800000,
       .dontcare = 0x300000007fc000,
       .mask     = 0xe030010000ffc000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6_a3xx_st__default,
       },
};
static const struct isa_case brac__default = {
       .display  = "{SY}{SS}{EQ}{JP}{NAME}.{INDEX} #{IMMED}",
       .num_fields = 1,
       .fields   = {
          { .name = "INDEX", .low = 32, .high = 36,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_bitset bitset_brac = {

       .parent   = &bitset___instruction_cat0_branch,
       .name     = "brac",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80006000000000,
       .dontcare = 0x7ce80000000000,
       .mask     = 0xe7fee8e000000000,
       .num_cases = 1,
       .cases    = {
            &brac__default,
       },
};
static const struct isa_case atomic_min__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_min = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.min",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc580000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_min__default,
       },
};
static const struct isa_case bary_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_bary_f = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "bary.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4720000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &bary_f__default,
       },
};
static const struct isa_case jump__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_jump = {

       .parent   = &bitset___instruction_cat0_immed,
       .name     = "jump",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x100000000000000,
       .dontcare = 0x7ce8ff00000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &jump__default,
       },
};
static const struct isa_case call__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_call = {

       .parent   = &bitset___instruction_cat0_immed,
       .name     = "call",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x180000000000000,
       .dontcare = 0x7ce8ff00000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &call__default,
       },
};
static const struct isa_case __reg_gpr__case0 = {
       .expr     = &expr___reg_gpr_a0,
       .display  = "a0.{SWIZ}",
       .num_fields = 1,
       .fields   = {
          { .name = "#reg-gpr#assert0", .low = 2, .high = 7,
            .type = TYPE_ASSERT,
            .val = 61,
          },
       },
};
static const struct isa_case __reg_gpr__case1 = {
       .expr     = &expr___reg_gpr_p0,
       .display  = "p0.{SWIZ}",
       .num_fields = 1,
       .fields   = {
          { .name = "#reg-gpr#assert0", .low = 2, .high = 7,
            .type = TYPE_ASSERT,
            .val = 62,
          },
       },
};
static const struct isa_case __reg_gpr__default = {
       .display  = "r{GPR}.{SWIZ}",
       .num_fields = 2,
       .fields   = {
          { .name = "GPR", .low = 2, .high = 7,
            .type = TYPE_UINT,
          },
          { .name = "SWIZ", .low = 0, .high = 1,
            .type = TYPE_ENUM,
            .enums = &enum___swiz,
          },
       },
};
static const struct isa_bitset bitset___reg_gpr = {

       .name     = "#reg-gpr",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 3,
       .cases    = {
            &__reg_gpr__case0,
            &__reg_gpr__case1,
            &__reg_gpr__default,
       },
};
static const struct isa_case max_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_max_f = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "max.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4040000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &max_f__default,
       },
};
static const struct isa_case getpos__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_getpos = {

       .parent   = &bitset___instruction_cat5,
       .name     = "getpos",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa300000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &getpos__default,
       },
};
static const struct isa_case __cat5_s2en_bindless_base__case0 = {
       .expr     = &expr_anon_14,
       .display  = ".base{BASE}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_case __cat5_s2en_bindless_base__default = {
       .display  = "",
       .num_fields = 2,
       .fields   = {
          { .name = "BASE", .low = 0, .high = 0,
            .expr = &expr_anon_13,
            .type = TYPE_UINT,
          },
          { .name = "BASE_LO", .low = 0, .high = 0,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_bitset bitset___cat5_s2en_bindless_base = {

       .name     = "#cat5-s2en-bindless-base",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat5_s2en_bindless_base__case0,
            &__cat5_s2en_bindless_base__default,
       },
};
static const struct isa_case dsxpp_1__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_dsxpp_1 = {

       .parent   = &bitset___instruction_cat5,
       .name     = "dsxpp.1",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa600000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &dsxpp_1__default,
       },
};
static const struct isa_case atomic_and__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_and = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.and",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc600000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_and__default,
       },
};
static const struct isa_case __mulitsrc_immed__case0 = {
       .expr     = &expr___multisrc_half,
       .display  = "{ABSNEG}{SRC_R}h({IMMED})",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_case __mulitsrc_immed__default = {
       .display  = "{ABSNEG}{SRC_R}{IMMED}",
       .num_fields = 2,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 10,
            .type = TYPE_INT,
          },
          { .name = "ABSNEG", .low = 14, .high = 15,
            .type = TYPE_ENUM,
            .enums = &enum___absneg,
          },
       },
};
static const struct isa_bitset bitset___mulitsrc_immed = {

       .parent   = &bitset___multisrc,
       .name     = "#mulitsrc-immed",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2000,
       .dontcare = 0x0,
       .mask     = 0x3800,
       .num_cases = 2,
       .cases    = {
            &__mulitsrc_immed__case0,
            &__mulitsrc_immed__default,
       },
};
static const struct isa_case samgp0__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_samgp0 = {

       .parent   = &bitset___instruction_cat5,
       .name     = "samgp0",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa500000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &samgp0__default,
       },
};
static const struct isa_field_params resinfo__default_ssbo = {
       .num_params = 1,
       .params = {
           { .name= "SSBO_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_case resinfo__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE}.{D}d {DST}, g[{SSBO}]",
       .num_fields = 5,
       .fields   = {
          { .name = "D", .low = 0, .high = 0,
            .expr = &expr___cat6_d,
            .type = TYPE_UINT,
          },
          { .name = "SSBO", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &resinfo__default_ssbo,
          },
          { .name = "D_MINUS_ONE", .low = 9, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SSBO_IM", .low = 53, .high = 53,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_resinfo = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "resinfo",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc3c0000000000000,
       .dontcare = 0x100000fffff9ff,
       .mask     = 0xe7d00100fffff9ff,
       .num_cases = 1,
       .cases    = {
            &resinfo__default,
       },
};
static const struct isa_case rcp__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_rcp = {

       .parent   = &bitset___instruction_cat4,
       .name     = "rcp",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8000000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &rcp__default,
       },
};
static const struct isa_case gather4r__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_gather4r = {

       .parent   = &bitset___instruction_cat5,
       .name     = "gather4r",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa400000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &gather4r__default,
       },
};
static const struct isa_case ball__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_ball = {

       .parent   = &bitset___instruction_cat0_branch_1src,
       .name     = "ball",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8000a000000000,
       .dontcare = 0xce81f00000000,
       .mask     = 0xe78ee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &ball__default,
       },
};
static const struct isa_case add_s__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_add_s = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "add.s",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4220000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &add_s__default,
       },
};
static const struct isa_case atomic_or__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_or = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.or",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc640000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_or__default,
       },
};
static const struct isa_case gather4a__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_gather4a = {

       .parent   = &bitset___instruction_cat5,
       .name     = "gather4a",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa4c0000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &gather4a__default,
       },
};
static const struct isa_case atomic_b_xor__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_xor = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.xor",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc030000000668001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_xor__default,
       },
};
static const struct isa_case add_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_add_f = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "add.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4000000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &add_f__default,
       },
};
static const struct isa_case ldlw__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} {DST}, l[{SRC}{OFF}], {SIZE}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_ldlw = {

       .parent   = &bitset___instruction_cat6_a3xx_ld,
       .name     = "ldlw",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc280000000800001,
       .dontcare = 0x31ff0000400000,
       .mask     = 0xe7f1ff0000c00001,
       .num_cases = 1,
       .cases    = {
            &ldlw__default,
       },
};
static const struct isa_case __instruction_cat1_mov__case0 = {
       .expr     = &expr_anon_4,
       .display  = "{SY}{SS}{JP}{REPEAT}{UL}mova {EVEN}{POS_INF}a0.x, {SRC}",
       .num_fields = 3,
       .fields   = {
          { .name = "#instruction-cat1-mov#assert0", .low = 32, .high = 39,
            .type = TYPE_ASSERT,
            .val = 244,
          },
          { .name = "#instruction-cat1-mov#assert1", .low = 46, .high = 48,
            .type = TYPE_ASSERT,
            .val = 4,
          },
          { .name = "#instruction-cat1-mov#assert2", .low = 50, .high = 52,
            .type = TYPE_ASSERT,
            .val = 4,
          },
       },
};
static const struct isa_case __instruction_cat1_mov__case1 = {
       .expr     = &expr_anon_5,
       .display  = "{SY}{SS}{JP}{REPEAT}{UL}mova1 {EVEN}{POS_INF}a1.x, {SRC}",
       .num_fields = 3,
       .fields   = {
          { .name = "#instruction-cat1-mov#assert0", .low = 32, .high = 39,
            .type = TYPE_ASSERT,
            .val = 245,
          },
          { .name = "#instruction-cat1-mov#assert1", .low = 46, .high = 48,
            .type = TYPE_ASSERT,
            .val = 2,
          },
          { .name = "#instruction-cat1-mov#assert2", .low = 50, .high = 52,
            .type = TYPE_ASSERT,
            .val = 2,
          },
       },
};
static const struct isa_case __instruction_cat1_mov__case2 = {
       .expr     = &expr_anon_6,
       .display  = "{SY}{SS}{JP}{REPEAT}{UL}cov.{SRC_TYPE}{DST_TYPE} {EVEN}{POS_INF}{DST_HALF}{DST}, {SRC}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_case __instruction_cat1_mov__default = {
       .display  = "{SY}{SS}{JP}{REPEAT}{UL}mov.{SRC_TYPE}{DST_TYPE} {EVEN}{POS_INF}{DST_HALF}{DST}, {SRC}",
       .num_fields = 4,
       .fields   = {
          { .name = "SRC_TYPE", .low = 50, .high = 52,
            .type = TYPE_ENUM,
            .enums = &enum___type,
          },
          { .name = "HALF", .low = 0, .high = 0,
            .expr = &expr_anon_2,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "DST_HALF", .low = 0, .high = 0,
            .expr = &expr_anon_3,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "DST_TYPE", .low = 46, .high = 48,
            .type = TYPE_ENUM,
            .enums = &enum___type,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat1_mov = {

       .parent   = &bitset___instruction_cat1,
       .name     = "#instruction-cat1-mov",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2000000000000000,
       .dontcare = 0x0,
       .mask     = 0xe600000000000000,
       .num_cases = 4,
       .cases    = {
            &__instruction_cat1_mov__case0,
            &__instruction_cat1_mov__case1,
            &__instruction_cat1_mov__case2,
            &__instruction_cat1_mov__default,
       },
};
static const struct isa_case hexp2__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_hexp2 = {

       .parent   = &bitset___instruction_cat4,
       .name     = "hexp2",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8160000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &hexp2__default,
       },
};
static const struct isa_case atomic_xchg__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_xchg = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.xchg",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc480000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_xchg__default,
       },
};
static const struct isa_case atomic_b_min__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_min = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.min",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc030000000658001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_min__default,
       },
};
static const struct isa_case __instruction_cat6__default = {
       .num_fields = 2,
       .fields   = {
          { .name = "JP", .low = 59, .high = 59,
            .display = "(jp)",
            .type = TYPE_BOOL,
          },
          { .name = "SY", .low = 60, .high = 60,
            .display = "(sy)",
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat6 = {

       .parent   = &bitset___instruction,
       .name     = "#instruction-cat6",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000000000000000,
       .dontcare = 0x0,
       .mask     = 0xe000000000000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6__default,
       },
};
static const struct isa_case chsh__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_chsh = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "chsh",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x500000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &chsh__default,
       },
};
static const struct isa_case chmask__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_chmask = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "chmask",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x480000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &chmask__default,
       },
};
static const struct isa_case hrsq__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_hrsq = {

       .parent   = &bitset___instruction_cat4,
       .name     = "hrsq",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8120000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &hrsq__default,
       },
};
static const struct isa_case emit__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_emit = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "emit",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x380000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &emit__default,
       },
};
static const struct isa_case getlod__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_getlod = {

       .parent   = &bitset___instruction_cat5,
       .name     = "getlod",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa1c0000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &getlod__default,
       },
};
static const struct isa_case madsh_u16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_madsh_u16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "madsh.u16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6080000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &madsh_u16__default,
       },
};
static const struct isa_case rndaz_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_rndaz_f = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "rndaz.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4180000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &rndaz_f__default,
       },
};
static const struct isa_case __instruction_cat0_1src__default = {
       .display  = "{SY}{SS}{EQ}{JP}{NAME} {INV1}p0.{COMP1}",
       .num_fields = 2,
       .fields   = {
          { .name = "INV1", .low = 52, .high = 52,
            .display = "!",
            .type = TYPE_BOOL,
          },
          { .name = "COMP1", .low = 53, .high = 54,
            .type = TYPE_ENUM,
            .enums = &enum___swiz,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat0_1src = {

       .parent   = &bitset___instruction_cat0,
       .name     = "#instruction-cat0-1src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x80000000000,
       .mask     = 0xe000e8ff00000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat0_1src__default,
       },
};
static const struct isa_case __instruction_cat0__default = {
       .num_fields = 6,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 31,
            .type = TYPE_BRANCH,
          },
          { .name = "SY", .low = 60, .high = 60,
            .display = "(sy)",
            .type = TYPE_BOOL,
          },
          { .name = "JP", .low = 59, .high = 59,
            .display = "(jp)",
            .type = TYPE_BOOL,
          },
          { .name = "EQ", .low = 48, .high = 48,
            .display = "(eq)",
            .type = TYPE_BOOL,
          },
          { .name = "SS", .low = 44, .high = 44,
            .display = "(ss)",
            .type = TYPE_BOOL,
          },
          { .name = "REPEAT", .low = 40, .high = 42,
            .type = TYPE_ENUM,
            .enums = &enum___rptn,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat0 = {

       .parent   = &bitset___instruction,
       .name     = "#instruction-cat0",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x80000000000,
       .mask     = 0xe000080000000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat0__default,
       },
};
static const struct isa_case samgp2__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_samgp2 = {

       .parent   = &bitset___instruction_cat5,
       .name     = "samgp2",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa580000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &samgp2__default,
       },
};
static const struct isa_case cos__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cos = {

       .parent   = &bitset___instruction_cat4,
       .name     = "cos",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80a0000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &cos__default,
       },
};
static const struct isa_case stc__default = {
       .display  = "{SY}{JP}{NAME} c[{DST}], {SRC}, {SIZE}",
       .num_fields = 3,
       .fields   = {
          { .name = "SIZE", .low = 24, .high = 26,
            .type = TYPE_UINT,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_UINT,
          },
          { .name = "SRC", .low = 1, .high = 8,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset_stc = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "stc",
       .gen      = {
           .min  = 600,
           .max  = -1,
       },
       .match    = 0xc700000000800000,
       .dontcare = 0x31ff00f87ffe01,
       .mask     = 0xe7f1ff00f8fffe01,
       .num_cases = 1,
       .cases    = {
            &stc__default,
       },
};
static const struct isa_case __cat3_src_gpr__default = {
       .display  = "{HALF}{SRC}",
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 7,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset___cat3_src_gpr = {

       .parent   = &bitset___cat3_src,
       .name     = "#cat3-src-gpr",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x1f00,
       .num_cases = 1,
       .cases    = {
            &__cat3_src_gpr__default,
       },
};
static const struct isa_case clz_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_clz_b = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "clz.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x46a0000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &clz_b__default,
       },
};
static const struct isa_case __instruction_cat6_a3xx_atomic_2src__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___instruction_cat6_a3xx_atomic_2src = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic,
       .name     = "#instruction-cat6-a3xx-atomic-2src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe0000100000001ff,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6_a3xx_atomic_2src__default,
       },
};
static const struct isa_field_params __instruction_cat1__default_dst = {
       .num_params = 1,
       .params = {
           { .name= "DST_REL",  .as = "DST_REL" },

       },
};
static const struct isa_case __instruction_cat1__default = {
       .num_fields = 9,
       .fields   = {
          { .name = "DST_REL", .low = 49, .high = 49,
            .type = TYPE_BOOL,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __cat1_dst,
            .params = &__instruction_cat1__default_dst,
          },
          { .name = "SY", .low = 60, .high = 60,
            .display = "(sy)",
            .type = TYPE_BOOL,
          },
          { .name = "EVEN", .low = 55, .high = 55,
            .display = "(even)",
            .type = TYPE_BOOL,
          },
          { .name = "JP", .low = 59, .high = 59,
            .display = "(jp)",
            .type = TYPE_BOOL,
          },
          { .name = "REPEAT", .low = 40, .high = 42,
            .type = TYPE_ENUM,
            .enums = &enum___rptn,
          },
          { .name = "POS_INF", .low = 56, .high = 56,
            .display = "(pos_infinity)",
            .type = TYPE_BOOL,
          },
          { .name = "SS", .low = 44, .high = 44,
            .display = "(ss)",
            .type = TYPE_BOOL,
          },
          { .name = "UL", .low = 45, .high = 45,
            .display = "(ul)",
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat1 = {

       .parent   = &bitset___instruction,
       .name     = "#instruction-cat1",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2000000000000000,
       .dontcare = 0x0,
       .mask     = 0xe000000000000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat1__default,
       },
};
static const struct isa_field_params mov_relgpr__default_src = {
       .num_params = 2,
       .params = {
           { .name= "SRC_R",  .as = "SRC_R" },
           { .name= "HALF",  .as = "HALF" },

       },
};
static const struct isa_case mov_relgpr__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 9,
            .type = TYPE_BITSET,
            .bitsets = __cat1_relative_gpr_src,
            .params = &mov_relgpr__default_src,
          },
       },
};
static const struct isa_bitset bitset_mov_relgpr = {

       .parent   = &bitset___instruction_cat1_relative,
       .name     = "mov-relgpr",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2000000000000800,
       .dontcare = 0x0,
       .mask     = 0xe6600000fffffc00,
       .num_cases = 1,
       .cases    = {
            &mov_relgpr__default,
       },
};
static const struct isa_field_params __instruction_cat2_1src__case0_src1 = {
       .num_params = 2,
       .params = {
           { .name= "ZERO",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_case __instruction_cat2_1src__case0 = {
       .expr     = &expr___cat2_cat3_nop_encoding,
       .display  = "{SY}{SS}{JP}{SAT}(nop{NOP}) {UL}{NAME} {EI}{DST_HALF}{DST}, {SRC1}",
       .num_fields = 2,
       .fields   = {
          { .name = "NOP", .low = 0, .high = 0,
            .expr = &expr___cat2_cat3_nop_value,
            .type = TYPE_UINT,
          },
          { .name = "SRC1", .low = 0, .high = 15,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_1src__case0_src1,
          },
       },
};
static const struct isa_field_params __instruction_cat2_1src__default_src1 = {
       .num_params = 2,
       .params = {
           { .name= "SRC1_R",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_case __instruction_cat2_1src__default = {
       .display  = "{SY}{SS}{JP}{SAT}{REPEAT}{UL}{NAME} {EI}{DST_HALF}{DST}, {SRC1}",
       .num_fields = 1,
       .fields   = {
          { .name = "SRC1", .low = 0, .high = 15,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_1src__default_src1,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat2_1src = {

       .parent   = &bitset___instruction_cat2,
       .name     = "#instruction-cat2-1src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4000000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe0070000ffff0000,
       .num_cases = 2,
       .cases    = {
            &__instruction_cat2_1src__case0,
            &__instruction_cat2_1src__default,
       },
};
static const struct isa_case atomic_max__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_max = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.max",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc5c0000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_max__default,
       },
};
static const struct isa_case cmpv_u__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cmpv_u = {

       .parent   = &bitset___instruction_cat2_2src_cond,
       .name     = "cmpv.u",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4420000000000000,
       .dontcare = 0x0,
       .mask     = 0xe7e0000000000000,
       .num_cases = 1,
       .cases    = {
            &cmpv_u__default,
       },
};
static const struct isa_case getspid__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} {DST}",
       .num_fields = 2,
       .fields   = {
          { .name = "TYPE", .low = 49, .high = 51,
            .type = TYPE_ENUM,
            .enums = &enum___type,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset_getspid = {

       .parent   = &bitset___instruction_cat6_a6xx,
       .name     = "getspid",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc020000000490000,
       .dontcare = 0x11fe00ffb00e00,
       .mask     = 0xe7f1ff00ffffce31,
       .num_cases = 1,
       .cases    = {
            &getspid__default,
       },
};
static const struct isa_case ceil_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_ceil_f = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "ceil.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4140000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &ceil_f__default,
       },
};
static const struct isa_field_params resinfo_b__default_ssbo = {
       .num_params = 1,
       .params = {
           { .name= "TRUE",  .as = "SRC_IM" },

       },
};
static const struct isa_case resinfo_b__default = {
       .display  = "{SY}{JP}{NAME}.{TYPED}.{D}d.{TYPE}.{TYPE_SIZE}.{MODE}{BASE} {DST}, {SSBO}",
       .num_fields = 7,
       .fields   = {
          { .name = "TYPED", .low = 11, .high = 11,
            .type = TYPE_BITSET,
            .bitsets = __cat6_typed,
          },
          { .name = "TRUE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "D_MINUS_ONE", .low = 9, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "D", .low = 0, .high = 0,
            .expr = &expr___cat6_d,
            .type = TYPE_UINT,
          },
          { .name = "TYPE", .low = 49, .high = 51,
            .type = TYPE_ENUM,
            .enums = &enum___type,
          },
          { .name = "SSBO", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &resinfo_b__default_ssbo,
          },
       },
};
static const struct isa_bitset bitset_resinfo_b = {

       .parent   = &bitset___instruction_cat6_a6xx,
       .name     = "resinfo.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc02000000063c000,
       .dontcare = 0x100000ff000000,
       .mask     = 0xe7f00100ffffc031,
       .num_cases = 1,
       .cases    = {
            &resinfo_b__default,
       },
};
static const struct isa_case rsq__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_rsq = {

       .parent   = &bitset___instruction_cat4,
       .name     = "rsq",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8020000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &rsq__default,
       },
};
static const struct isa_case sad_s16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sad_s16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "sad.s16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6700000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &sad_s16__default,
       },
};
static const struct isa_field_params __instruction_cat4__default_src = {
       .num_params = 2,
       .params = {
           { .name= "SRC_R",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_case __instruction_cat4__default = {
       .display  = "{SY}{SS}{JP}{SAT}{REPEAT}{UL}{NAME} {DST_HALF}{DST}, {SRC}",
       .num_fields = 12,
       .fields   = {
          { .name = "DST_CONV", .low = 46, .high = 46,
            .type = TYPE_BOOL,
          },
          { .name = "DST_HALF", .low = 0, .high = 0,
            .expr = &expr___dest_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "JP", .low = 59, .high = 59,
            .display = "(jp)",
            .type = TYPE_BOOL,
          },
          { .name = "SS", .low = 44, .high = 44,
            .display = "(ss)",
            .type = TYPE_BOOL,
          },
          { .name = "REPEAT", .low = 40, .high = 41,
            .type = TYPE_ENUM,
            .enums = &enum___rptn,
          },
          { .name = "SAT", .low = 42, .high = 42,
            .display = "(sat)",
            .type = TYPE_BOOL,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "FULL", .low = 52, .high = 52,
            .type = TYPE_BOOL,
          },
          { .name = "SRC", .low = 0, .high = 15,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat4__default_src,
          },
          { .name = "SRC_R", .low = 43, .high = 43,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
          { .name = "UL", .low = 45, .high = 45,
            .display = "(ul)",
            .type = TYPE_BOOL,
          },
          { .name = "SY", .low = 60, .high = 60,
            .display = "(sy)",
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat4 = {

       .parent   = &bitset___instruction,
       .name     = "#instruction-cat4",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8000000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe00f8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat4__default,
       },
};
static const struct isa_case rgetpos__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_rgetpos = {

       .parent   = &bitset___instruction_cat5,
       .name     = "rgetpos",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa680000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &rgetpos__default,
       },
};
static const struct isa_case stg__case0 = {
       .expr     = &expr_anon_26,
       .display  = "{SY}{JP}{NAME}.{TYPE} g[{SRC1}{OFF}], {SRC3}, {SIZE}",
       .num_fields = 3,
       .fields   = {
          { .name = "OFF", .low = 0, .high = 13 - 1,
            .expr = &expr_anon_27,
            .type = TYPE_OFFSET,
          },
          { .name = "OFF_HI", .low = 9, .high = 13,
            .type = TYPE_UINT,
          },
          { .name = "OFF_LO", .low = 32, .high = 39,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_case stg__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} g[{SRC1}+{SRC2}], {SRC3}, {SIZE}",
       .num_fields = 7,
       .fields   = {
          { .name = "SIZE", .low = 24, .high = 31,
            .type = TYPE_UINT,
          },
          { .name = "SRC1", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC3", .low = 1, .high = 8,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "G", .low = 52, .high = 52,
            .type = TYPE_BOOL,
          },
          { .name = "DST_OFF", .low = 40, .high = 40,
            .type = TYPE_BOOL,
          },
          { .name = "stg#assert0", .low = 9, .high = 13,
            .type = TYPE_ASSERT,
            .val = 0,
          },
          { .name = "SRC2", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset_stg = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "stg",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc0c0000000800000,
       .dontcare = 0x200000007fc001,
       .mask     = 0xe7e0000000ffc001,
       .num_cases = 2,
       .cases    = {
            &stg__case0,
            &stg__default,
       },
};
static const struct isa_case atomic_b_sub__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_sub = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.sub",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc030000000644001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_sub__default,
       },
};
static const struct isa_case mul_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_mul_f = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "mul.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4060000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &mul_f__default,
       },
};
static const struct isa_case __cat3_src_relative__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___cat3_src_relative = {

       .parent   = &bitset___cat3_src,
       .name     = "#cat3-src-relative",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x800,
       .dontcare = 0x0,
       .mask     = 0x1800,
       .num_cases = 1,
       .cases    = {
            &__cat3_src_relative__default,
       },
};
static const struct isa_case __cat5_tex__case0 = {
       .expr     = &expr_anon_21,
       .display  = ", t#{TEX}",
       .num_fields = 1,
       .fields   = {
          { .name = "TEX", .low = 0, .high = 6,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_case __cat5_tex__default = {
       .display  = "",
       .num_fields = 1,
       .fields   = {
          { .name = "#cat5-tex#assert0", .low = 0, .high = 6,
            .type = TYPE_ASSERT,
            .val = 0,
          },
       },
};
static const struct isa_bitset bitset___cat5_tex = {

       .name     = "#cat5-tex",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat5_tex__case0,
            &__cat5_tex__default,
       },
};
static const struct isa_case __mulitsrc_immed_flut__default = {
       .num_fields = 2,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 9,
            .type = TYPE_ENUM,
            .enums = &enum___flut,
          },
          { .name = "ABSNEG", .low = 14, .high = 15,
            .type = TYPE_ENUM,
            .enums = &enum___absneg,
          },
       },
};
static const struct isa_bitset bitset___mulitsrc_immed_flut = {

       .parent   = &bitset___multisrc,
       .name     = "#mulitsrc-immed-flut",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2800,
       .dontcare = 0x0,
       .mask     = 0x3800,
       .num_cases = 1,
       .cases    = {
            &__mulitsrc_immed_flut__default,
       },
};
static const struct isa_case sub_s__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_sub_s = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "sub.s",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4260000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &sub_s__default,
       },
};
static const struct isa_case end__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_end = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "end",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x300000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &end__default,
       },
};
static const struct isa_case __multisrc__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___multisrc = {

       .name     = "#multisrc",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 1,
       .cases    = {
            &__multisrc__default,
       },
};
static const struct isa_case stgb__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_stgb = {

       .parent   = &bitset___instruction_cat6_a3xx_ibo,
       .name     = "stgb",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc700000000000001,
       .dontcare = 0x100000007fc000,
       .mask     = 0xe7d00000007fc001,
       .num_cases = 1,
       .cases    = {
            &stgb__default,
       },
};
static const struct isa_case bany__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_bany = {

       .parent   = &bitset___instruction_cat0_branch_1src,
       .name     = "bany",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80008000000000,
       .dontcare = 0xce81f00000000,
       .mask     = 0xe78ee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &bany__default,
       },
};
static const struct isa_case __cat6_typed__case0 = {
       .expr     = &expr_anon_30,
       .display  = "typed",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_case __cat6_typed__default = {
       .display  = "untyped",
       .num_fields = 1,
       .fields   = {
          { .name = "TYPED", .low = 0, .high = 0,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___cat6_typed = {

       .name     = "#cat6-typed",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat6_typed__case0,
            &__cat6_typed__default,
       },
};
static const struct isa_case hlog2__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_hlog2 = {

       .parent   = &bitset___instruction_cat4,
       .name     = "hlog2",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8140000000000000,
       .dontcare = 0xf8000ffff0000,
       .mask     = 0xe7ef8000ffff0000,
       .num_cases = 1,
       .cases    = {
            &hlog2__default,
       },
};
static const struct isa_case absneg_s__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_absneg_s = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "absneg.s",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4340000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &absneg_s__default,
       },
};
static const struct isa_case clz_s__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_clz_s = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "clz.s",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4680000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &clz_s__default,
       },
};
static const struct isa_case __instruction_cat6_a3xx_ld__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "OFF", .low = 1, .high = 13,
            .type = TYPE_OFFSET,
          },
          { .name = "SIZE", .low = 24, .high = 31,
            .type = TYPE_UINT,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC", .low = 14, .high = 21,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat6_a3xx_ld = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "#instruction-cat6-a3xx-ld",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000000000800001,
       .dontcare = 0x31ff0000400000,
       .mask     = 0xe031ff0000c00001,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6_a3xx_ld__default,
       },
};
static const struct isa_case __instruction_cat1_relative__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "SRC_R", .low = 43, .high = 43,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat1_relative = {

       .parent   = &bitset___instruction_cat1_mov,
       .name     = "#instruction-cat1-relative",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2000000000000800,
       .dontcare = 0x0,
       .mask     = 0xe6600000fffff800,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat1_relative__default,
       },
};
static const struct isa_case sel_b32__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sel_b32 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "sel.b32",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6480000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &sel_b32__default,
       },
};
static const struct isa_field_params ldgb__default_ssbo = {
       .num_params = 1,
       .params = {
           { .name= "SSBO_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_field_params ldgb__default_src1 = {
       .num_params = 1,
       .params = {
           { .name= "SRC1_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_field_params ldgb__default_src2 = {
       .num_params = 1,
       .params = {
           { .name= "SRC2_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_case ldgb__default = {
       .display  = "{SY}{JP}{NAME}.{TYPED}.{D}d.{TYPE}.{TYPE_SIZE} {DST}, g[{SSBO}], {SRC1}, {SRC2}",
       .num_fields = 12,
       .fields   = {
          { .name = "TYPE_SIZE", .low = 0, .high = 0,
            .expr = &expr___cat6_type_size,
            .type = TYPE_UINT,
          },
          { .name = "SRC1_IM", .low = 22, .high = 22,
            .type = TYPE_BOOL,
          },
          { .name = "D_MINUS_ONE", .low = 9, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "TYPE_SIZE_MINUS_ONE", .low = 12, .high = 13,
            .type = TYPE_UINT,
          },
          { .name = "SRC2_IM", .low = 23, .high = 23,
            .type = TYPE_BOOL,
          },
          { .name = "TYPED", .low = 11, .high = 11,
            .type = TYPE_BITSET,
            .bitsets = __cat6_typed,
          },
          { .name = "SSBO", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &ldgb__default_ssbo,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SSBO_IM", .low = 53, .high = 53,
            .type = TYPE_BOOL,
          },
          { .name = "SRC1", .low = 14, .high = 21,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &ldgb__default_src1,
          },
          { .name = "D", .low = 0, .high = 0,
            .expr = &expr___cat6_d,
            .type = TYPE_UINT,
          },
          { .name = "SRC2", .low = 24, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &ldgb__default_src2,
          },
       },
};
static const struct isa_bitset bitset_ldgb = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "ldgb",
       .gen      = {
           .min  = 0,
           .max  = 599,
       },
       .match    = 0xc6c0000000000000,
       .dontcare = 0x100000000001ff,
       .mask     = 0xe7d00100000001ff,
       .num_cases = 1,
       .cases    = {
            &ldgb__default,
       },
};
static const struct isa_case bkt__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_bkt = {

       .parent   = &bitset___instruction_cat0_immed,
       .name     = "bkt",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2000000000000,
       .dontcare = 0x7ce8ff00000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &bkt__default,
       },
};
static const struct isa_case __cat6_src__case0 = {
       .expr     = &expr_anon_32,
       .display  = "{IMMED}",
       .num_fields = 1,
       .fields   = {
          { .name = "IMMED", .low = 0, .high = 7,
            .type = TYPE_INT,
          },
       },
};
static const struct isa_case __cat6_src__default = {
       .display  = "r{GPR}.{SWIZ}",
       .num_fields = 2,
       .fields   = {
          { .name = "GPR", .low = 2, .high = 7,
            .type = TYPE_UINT,
          },
          { .name = "SWIZ", .low = 0, .high = 1,
            .type = TYPE_ENUM,
            .enums = &enum___swiz,
          },
       },
};
static const struct isa_bitset bitset___cat6_src = {

       .name     = "#cat6-src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat6_src__case0,
            &__cat6_src__default,
       },
};
static const struct isa_case and_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_and_b = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "and.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4380000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &and_b__default,
       },
};
static const struct isa_case __cat3_src__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___cat3_src = {

       .name     = "#cat3-src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 1,
       .cases    = {
            &__cat3_src__default,
       },
};
static const struct isa_case sel_s16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sel_s16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "sel.s16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6500000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &sel_s16__default,
       },
};
static const struct isa_case movmsk__default = {
       .display  = "{SY}{SS}{JP}{UL}movmsk.w{W} {DST}",
       .num_fields = 1,
       .fields   = {
          { .name = "W", .low = 0, .high = 0,
            .expr = &expr_anon_12,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_bitset bitset_movmsk = {

       .parent   = &bitset___instruction_cat1,
       .name     = "movmsk",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x260cc00000000000,
       .dontcare = 0x0,
       .mask     = 0xe67dc800ffffffff,
       .num_cases = 1,
       .cases    = {
            &movmsk__default,
       },
};
static const struct isa_case __instruction_cat7__default = {
       .display  = "{SY}{JP}{NAME}{G}{L}{R}{W}",
       .num_fields = 6,
       .fields   = {
          { .name = "JP", .low = 59, .high = 59,
            .display = "(jp)",
            .type = TYPE_BOOL,
          },
          { .name = "R", .low = 52, .high = 52,
            .display = ".r",
            .type = TYPE_BOOL,
          },
          { .name = "SY", .low = 60, .high = 60,
            .display = "(sy)",
            .type = TYPE_BOOL,
          },
          { .name = "W", .low = 51, .high = 51,
            .display = ".w",
            .type = TYPE_BOOL,
          },
          { .name = "G", .low = 54, .high = 54,
            .display = ".g",
            .type = TYPE_BOOL,
          },
          { .name = "L", .low = 53, .high = 53,
            .display = ".l",
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat7 = {

       .parent   = &bitset___instruction,
       .name     = "#instruction-cat7",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xe002000000000000,
       .dontcare = 0x5ffffffffffff,
       .mask     = 0xe007ffffffffffff,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat7__default,
       },
};
static const struct isa_case samgp1__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_samgp1 = {

       .parent   = &bitset___instruction_cat5,
       .name     = "samgp1",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa540000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &samgp1__default,
       },
};
static const struct isa_case dsypp_1__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_dsypp_1 = {

       .parent   = &bitset___instruction_cat5,
       .name     = "dsypp.1",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa640000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &dsypp_1__default,
       },
};
static const struct isa_case __instruction_cat0_branch__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___instruction_cat0_branch = {

       .parent   = &bitset___instruction_cat0,
       .name     = "#instruction-cat0-branch",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe78e080000000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat0_branch__default,
       },
};
static const struct isa_case brax__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_brax = {

       .parent   = &bitset___instruction_cat0_branch,
       .name     = "brax",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x8000c000000000,
       .dontcare = 0x7ce81f00000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &brax__default,
       },
};
static const struct isa_case brao__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_brao = {

       .parent   = &bitset___instruction_cat0_branch_2src,
       .name     = "brao",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80002000000000,
       .dontcare = 0xc081f00000000,
       .mask     = 0xe78e08ff00000000,
       .num_cases = 1,
       .cases    = {
            &brao__default,
       },
};
static const struct isa_field_params mov_relconst__default_src = {
       .num_params = 2,
       .params = {
           { .name= "SRC_R",  .as = "SRC_R" },
           { .name= "HALF",  .as = "HALF" },

       },
};
static const struct isa_case mov_relconst__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "SRC", .low = 0, .high = 9,
            .type = TYPE_BITSET,
            .bitsets = __cat1_relative_const_src,
            .params = &mov_relconst__default_src,
          },
       },
};
static const struct isa_bitset bitset_mov_relconst = {

       .parent   = &bitset___instruction_cat1_relative,
       .name     = "mov-relconst",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2000000000000c00,
       .dontcare = 0x0,
       .mask     = 0xe6600000fffffc00,
       .num_cases = 1,
       .cases    = {
            &mov_relconst__default,
       },
};
static const struct isa_case ldlv__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} {DST}, l[{OFF}], {SIZE}",
       .num_fields = 3,
       .fields   = {
          { .name = "OFF", .low = 1, .high = 13,
            .type = TYPE_UINT,
          },
          { .name = "SIZE", .low = 24, .high = 31,
            .type = TYPE_UINT,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
       },
};
static const struct isa_bitset bitset_ldlv = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "ldlv",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc7c0000000c00000,
       .dontcare = 0x31ff00003fc000,
       .mask     = 0xe7f1ff0000ffc001,
       .num_cases = 1,
       .cases    = {
            &ldlv__default,
       },
};
static const struct isa_case stib__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_stib = {

       .parent   = &bitset___instruction_cat6_a3xx_ibo,
       .name     = "stib",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc740000000000001,
       .dontcare = 0x100000007fc000,
       .mask     = 0xe7d00000007fc001,
       .num_cases = 1,
       .cases    = {
            &stib__default,
       },
};
static const struct isa_case __cat5_samp_s2en_bindless_a1__case0 = {
       .expr     = &expr_anon_20,
       .display  = ", s#{SAMP}",
       .num_fields = 1,
       .fields   = {
          { .name = "SAMP", .low = 0, .high = 8,
            .type = TYPE_UINT,
          },
       },
};
static const struct isa_case __cat5_samp_s2en_bindless_a1__default = {
       .display  = "",
       .num_fields = 1,
       .fields   = {
          { .name = "#cat5-samp-s2en-bindless-a1#assert0", .low = 0, .high = 7,
            .type = TYPE_ASSERT,
            .val = 0,
          },
       },
};
static const struct isa_bitset bitset___cat5_samp_s2en_bindless_a1 = {

       .name     = "#cat5-samp-s2en-bindless-a1",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__cat5_samp_s2en_bindless_a1__case0,
            &__cat5_samp_s2en_bindless_a1__default,
       },
};
static const struct isa_case br__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_br = {

       .parent   = &bitset___instruction_cat0_branch_1src,
       .name     = "br",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80000000000000,
       .dontcare = 0xce81f00000000,
       .mask     = 0xe78ee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &br__default,
       },
};
static const struct isa_case bfrev_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_bfrev_b = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "bfrev.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4660000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &bfrev_b__default,
       },
};
static const struct isa_case dsx__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_dsx = {

       .parent   = &bitset___instruction_cat5,
       .name     = "dsx",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa380000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &dsx__default,
       },
};
static const struct isa_case __instruction_cat6_a3xx__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "TYPE", .low = 49, .high = 51,
            .type = TYPE_ENUM,
            .enums = &enum___type,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat6_a3xx = {

       .parent   = &bitset___instruction_cat6,
       .name     = "#instruction-cat6-a3xx",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000000000000000,
       .dontcare = 0x0,
       .mask     = 0xe000000000000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6_a3xx__default,
       },
};
static const struct isa_case gather4b__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_gather4b = {

       .parent   = &bitset___instruction_cat5,
       .name     = "gather4b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa480000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &gather4b__default,
       },
};
static const struct isa_case ashr_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_ashr_b = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "ashr.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4700000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &ashr_b__default,
       },
};
static const struct isa_field_params __instruction_cat6_a6xx__default_base = {
       .num_params = 1,
       .params = {
           { .name= "BINDLESS",  .as = "BINDLESS" },

       },
};
static const struct isa_case __instruction_cat6_a6xx__default = {
       .num_fields = 5,
       .fields   = {
          { .name = "TYPE_SIZE", .low = 0, .high = 0,
            .expr = &expr___cat6_type_size,
            .type = TYPE_UINT,
          },
          { .name = "BASE", .low = 1, .high = 3,
            .type = TYPE_BITSET,
            .bitsets = __cat6_base,
            .params = &__instruction_cat6_a6xx__default_base,
          },
          { .name = "MODE", .low = 6, .high = 7,
            .type = TYPE_ENUM,
            .enums = &enum___cat6_src_mode,
          },
          { .name = "TYPE_SIZE_MINUS_ONE", .low = 12, .high = 13,
            .type = TYPE_UINT,
          },
          { .name = "BINDLESS", .low = 8, .high = 8,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat6_a6xx = {

       .parent   = &bitset___instruction_cat6,
       .name     = "#instruction-cat6-a6xx",
       .gen      = {
           .min  = 600,
           .max  = -1,
       },
       .match    = 0xc000000000000000,
       .dontcare = 0x0,
       .mask     = 0xe7c0010000000030,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6_a6xx__default,
       },
};
static const struct isa_field_params __instruction_cat2_2src__case0_src2 = {
       .num_params = 2,
       .params = {
           { .name= "ZERO",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_field_params __instruction_cat2_2src__case0_src1 = {
       .num_params = 2,
       .params = {
           { .name= "ZERO",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_case __instruction_cat2_2src__case0 = {
       .expr     = &expr___cat2_cat3_nop_encoding,
       .display  = "{SY}{SS}{JP}{SAT}(nop{NOP}) {UL}{NAME} {EI}{DST_HALF}{DST}, {SRC1}, {SRC2}",
       .num_fields = 3,
       .fields   = {
          { .name = "SRC2", .low = 16, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_2src__case0_src2,
          },
          { .name = "NOP", .low = 0, .high = 0,
            .expr = &expr___cat2_cat3_nop_value,
            .type = TYPE_UINT,
          },
          { .name = "SRC1", .low = 0, .high = 15,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_2src__case0_src1,
          },
       },
};
static const struct isa_field_params __instruction_cat2_2src__default_src2 = {
       .num_params = 2,
       .params = {
           { .name= "SRC2_R",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_field_params __instruction_cat2_2src__default_src1 = {
       .num_params = 2,
       .params = {
           { .name= "SRC1_R",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_case __instruction_cat2_2src__default = {
       .display  = "{SY}{SS}{JP}{SAT}{REPEAT}{UL}{NAME} {EI}{DST_HALF}{DST}, {SRC1}, {SRC2}",
       .num_fields = 2,
       .fields   = {
          { .name = "SRC2", .low = 16, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_2src__default_src2,
          },
          { .name = "SRC1", .low = 0, .high = 15,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_2src__default_src1,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat2_2src = {

       .parent   = &bitset___instruction_cat2,
       .name     = "#instruction-cat2-2src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4000000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe007000000000000,
       .num_cases = 2,
       .cases    = {
            &__instruction_cat2_2src__case0,
            &__instruction_cat2_2src__default,
       },
};
static const struct isa_case __cat3_src_relative_gpr__default = {
       .display  = "{HALF}r<a0.x + {OFFSET}>",
       .num_fields = 1,
       .fields   = {
          { .name = "OFFSET", .low = 0, .high = 9,
            .type = TYPE_INT,
          },
       },
};
static const struct isa_bitset bitset___cat3_src_relative_gpr = {

       .parent   = &bitset___cat3_src_relative,
       .name     = "#cat3-src-relative-gpr",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x800,
       .dontcare = 0x0,
       .mask     = 0x1c00,
       .num_cases = 1,
       .cases    = {
            &__cat3_src_relative_gpr__default,
       },
};
static const struct isa_case __multisrc_immed_flut_half__default = {
       .display  = "{ABSNEG}{SRC_R}h{IMMED}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___multisrc_immed_flut_half = {

       .parent   = &bitset___mulitsrc_immed_flut,
       .name     = "#multisrc-immed-flut-half",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2c00,
       .dontcare = 0x0,
       .mask     = 0x3c00,
       .num_cases = 1,
       .cases    = {
            &__multisrc_immed_flut_half__default,
       },
};
static const struct isa_case isaml__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___two,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_isaml = {

       .parent   = &bitset___instruction_cat5,
       .name     = "isaml",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa040000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &isaml__default,
       },
};
static const struct isa_case gather4g__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_gather4g = {

       .parent   = &bitset___instruction_cat5,
       .name     = "gather4g",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa440000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &gather4g__default,
       },
};
static const struct isa_case mul_s24__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_mul_s24 = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "mul.s24",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4620000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &mul_s24__default,
       },
};
static const struct isa_field_params __instruction_cat5__case0_base = {
       .num_params = 2,
       .params = {
           { .name= "BINDLESS",  .as = "BINDLESS" },
           { .name= "BASE_HI",  .as = "BASE_HI" },

       },
};
static const struct isa_field_params __instruction_cat5__case0_src3 = {
       .num_params = 4,
       .params = {
           { .name= "BINDLESS",  .as = "BINDLESS" },
           { .name= "DESC_MODE",  .as = "DESC_MODE" },
           { .name= "HAS_SAMP",  .as = "HAS_SAMP" },
           { .name= "HAS_TEX",  .as = "HAS_TEX" },

       },
};
static const struct isa_case __instruction_cat5__case0 = {
       .expr     = &expr_anon_16,
       .display  = "{SY}{JP}{NAME}{3D}{A}{O}{P}{S}{S2EN}{UNIFORM}{BASE} {TYPE}({WRMASK}){DST_HALF}{DST}{SRC1}{SRC2}{SRC3}{A1}",
       .num_fields = 8,
       .fields   = {
          { .name = "BINDLESS", .low = 0, .high = 0,
            .expr = &expr___cat5_s2enb_is_bindless,
            .type = TYPE_BOOL,
          },
          { .name = "A1", .low = 0, .high = 0,
            .expr = &expr___cat5_s2enb_uses_a1,
            .display = ", a1.x",
            .type = TYPE_BOOL,
          },
          { .name = "BASE", .low = 47, .high = 47,
            .type = TYPE_BITSET,
            .bitsets = __cat5_s2en_bindless_base,
            .params = &__instruction_cat5__case0_base,
          },
          { .name = "S2EN", .low = 0, .high = 0,
            .expr = &expr___cat5_s2enb_is_indirect,
            .display = ".s2en",
            .type = TYPE_BOOL,
          },
          { .name = "SRC3", .low = 21, .high = 28,
            .type = TYPE_BITSET,
            .bitsets = __cat5_src3,
            .params = &__instruction_cat5__case0_src3,
          },
          { .name = "DESC_MODE", .low = 29, .high = 31,
            .type = TYPE_ENUM,
            .enums = &enum___cat5_s2en_bindless_desc_mode,
          },
          { .name = "BASE_HI", .low = 19, .high = 20,
            .type = TYPE_UINT,
          },
          { .name = "UNIFORM", .low = 0, .high = 0,
            .expr = &expr___cat5_s2enb_is_uniform,
            .display = ".uniform",
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_field_params __instruction_cat5__default_samp = {
       .num_params = 1,
       .params = {
           { .name= "HAS_SAMP",  .as = "HAS_SAMP" },

       },
};
static const struct isa_field_params __instruction_cat5__default_tex = {
       .num_params = 1,
       .params = {
           { .name= "HAS_TEX",  .as = "HAS_TEX" },

       },
};
static const struct isa_field_params __instruction_cat5__default_src1 = {
       .num_params = 2,
       .params = {
           { .name= "NUM_SRC",  .as = "NUM_SRC" },
           { .name= "HALF",  .as = "HALF" },

       },
};
static const struct isa_field_params __instruction_cat5__default_type = {
       .num_params = 1,
       .params = {
           { .name= "HAS_TYPE",  .as = "HAS_TYPE" },

       },
};
static const struct isa_field_params __instruction_cat5__default_src2 = {
       .num_params = 3,
       .params = {
           { .name= "NUM_SRC",  .as = "NUM_SRC" },
           { .name= "HALF",  .as = "HALF" },
           { .name= "O",  .as = "O" },

       },
};
static const struct isa_case __instruction_cat5__default = {
       .display  = "{SY}{JP}{NAME}{3D}{A}{O}{P}{S} {TYPE}({WRMASK}){DST_HALF}{DST}{SRC1}{SRC2}{SAMP}{TEX}",
       .num_fields = 20,
       .fields   = {
          { .name = "SAMP", .low = 21, .high = 24,
            .type = TYPE_BITSET,
            .bitsets = __cat5_samp,
            .params = &__instruction_cat5__default_samp,
          },
          { .name = "#instruction-cat5#assert2", .low = 19, .high = 20,
            .type = TYPE_ASSERT,
            .val = 0,
          },
          { .name = "S2EN_BINDLESS", .low = 51, .high = 51,
            .type = TYPE_BOOL,
          },
          { .name = "DST_HALF", .low = 0, .high = 0,
            .expr = &expr_anon_15,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "SY", .low = 60, .high = 60,
            .display = "(sy)",
            .type = TYPE_BOOL,
          },
          { .name = "JP", .low = 59, .high = 59,
            .display = "(jp)",
            .type = TYPE_BOOL,
          },
          { .name = "P", .low = 53, .high = 53,
            .display = ".p",
            .type = TYPE_BOOL,
          },
          { .name = "TEX", .low = 25, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __cat5_tex,
            .params = &__instruction_cat5__default_tex,
          },
          { .name = "WRMASK", .low = 40, .high = 43,
            .type = TYPE_ENUM,
            .enums = &enum___wrmask,
          },
          { .name = "A", .low = 49, .high = 49,
            .display = ".a",
            .type = TYPE_BOOL,
          },
          { .name = "3D", .low = 48, .high = 48,
            .display = ".3d",
            .type = TYPE_BOOL,
          },
          { .name = "#instruction-cat5#assert3", .low = 47, .high = 47,
            .type = TYPE_ASSERT,
            .val = 0,
          },
          { .name = "HALF", .low = 0, .high = 0,
            .expr = &expr___multisrc_half,
            .display = "h",
            .type = TYPE_BOOL,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "FULL", .low = 0, .high = 0,
            .type = TYPE_BOOL,
          },
          { .name = "SRC1", .low = 1, .high = 8,
            .type = TYPE_BITSET,
            .bitsets = __cat5_src1,
            .params = &__instruction_cat5__default_src1,
          },
          { .name = "TYPE", .low = 44, .high = 46,
            .type = TYPE_BITSET,
            .bitsets = __cat5_type,
            .params = &__instruction_cat5__default_type,
          },
          { .name = "S", .low = 50, .high = 50,
            .display = ".s",
            .type = TYPE_BOOL,
          },
          { .name = "O", .low = 52, .high = 52,
            .display = ".o",
            .type = TYPE_BOOL,
          },
          { .name = "SRC2", .low = 9, .high = 16,
            .type = TYPE_BITSET,
            .bitsets = __cat5_src2,
            .params = &__instruction_cat5__default_src2,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat5 = {

       .parent   = &bitset___instruction,
       .name     = "#instruction-cat5",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa000000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe000000000060000,
       .num_cases = 2,
       .cases    = {
            &__instruction_cat5__case0,
            &__instruction_cat5__default,
       },
};
static const struct isa_case atomic_b_add__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_add = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.add",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc030000000640001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_add__default,
       },
};
static const struct isa_case __instruction__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___instruction = {

       .name     = "#instruction",
       .gen      = {
           .min  = 300,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 1,
       .cases    = {
            &__instruction__default,
       },
};
static const struct isa_field_params mov_const__default_src = {
       .num_params = 2,
       .params = {
           { .name= "SRC_R",  .as = "SRC_R" },
           { .name= "HALF",  .as = "HALF" },

       },
};
static const struct isa_case mov_const__default = {
       .num_fields = 2,
       .fields   = {
          { .name = "SRC_R", .low = 43, .high = 43,
            .display = "(r)",
            .type = TYPE_BOOL,
          },
          { .name = "SRC", .low = 0, .high = 10,
            .type = TYPE_BITSET,
            .bitsets = __cat1_const_src,
            .params = &mov_const__default_src,
          },
       },
};
static const struct isa_bitset bitset_mov_const = {

       .parent   = &bitset___instruction_cat1_mov,
       .name     = "mov-const",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x2020000000000000,
       .dontcare = 0x0,
       .mask     = 0xe6600000fffff800,
       .num_cases = 1,
       .cases    = {
            &mov_const__default,
       },
};
static const struct isa_case __cat1_const_src__default = {
       .display  = "{SRC_R}{HALF}{CONST}",
       .num_fields = 1,
       .fields   = {
          { .name = "CONST", .low = 0, .high = 10,
            .type = TYPE_BITSET,
            .bitsets = __reg_const,
          },
       },
};
static const struct isa_bitset bitset___cat1_const_src = {

       .name     = "#cat1-const-src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 1,
       .cases    = {
            &__cat1_const_src__default,
       },
};
static const struct isa_field_params __instruction_cat2_2src_cond__case0_src2 = {
       .num_params = 2,
       .params = {
           { .name= "ZERO",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_field_params __instruction_cat2_2src_cond__case0_src1 = {
       .num_params = 2,
       .params = {
           { .name= "ZERO",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_case __instruction_cat2_2src_cond__case0 = {
       .expr     = &expr___cat2_cat3_nop_encoding,
       .display  = "{SY}{SS}{JP}{SAT}(nop{NOP}) {UL}{NAME}.{COND} {EI}{DST_HALF}{DST}, {SRC1}, {SRC2}",
       .num_fields = 3,
       .fields   = {
          { .name = "SRC2", .low = 16, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_2src_cond__case0_src2,
          },
          { .name = "NOP", .low = 0, .high = 0,
            .expr = &expr___cat2_cat3_nop_value,
            .type = TYPE_UINT,
          },
          { .name = "SRC1", .low = 0, .high = 15,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_2src_cond__case0_src1,
          },
       },
};
static const struct isa_field_params __instruction_cat2_2src_cond__default_src2 = {
       .num_params = 2,
       .params = {
           { .name= "SRC2_R",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_field_params __instruction_cat2_2src_cond__default_src1 = {
       .num_params = 2,
       .params = {
           { .name= "SRC1_R",  .as = "SRC_R" },
           { .name= "FULL",  .as = "FULL" },

       },
};
static const struct isa_case __instruction_cat2_2src_cond__default = {
       .display  = "{SY}{SS}{JP}{SAT}{REPEAT}{UL}{NAME}.{COND} {EI}{DST_HALF}{DST}, {SRC1}, {SRC2}",
       .num_fields = 3,
       .fields   = {
          { .name = "SRC2", .low = 16, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_2src_cond__default_src2,
          },
          { .name = "COND", .low = 48, .high = 50,
            .type = TYPE_ENUM,
            .enums = &enum___cond,
          },
          { .name = "SRC1", .low = 0, .high = 15,
            .type = TYPE_BITSET,
            .bitsets = __multisrc,
            .params = &__instruction_cat2_2src_cond__default_src1,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat2_2src_cond = {

       .parent   = &bitset___instruction_cat2,
       .name     = "#instruction-cat2-2src-cond",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4000000000000000,
       .dontcare = 0x0,
       .mask     = 0xe000000000000000,
       .num_cases = 2,
       .cases    = {
            &__instruction_cat2_2src_cond__case0,
            &__instruction_cat2_2src_cond__default,
       },
};
static const struct isa_case prede__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_prede = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "prede",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x782000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &prede__default,
       },
};
static const struct isa_case bar__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_bar = {

       .parent   = &bitset___instruction_cat7,
       .name     = "bar",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xe002000000000000,
       .dontcare = 0x5ffffffffffff,
       .mask     = 0xe787ffffffffffff,
       .num_cases = 1,
       .cases    = {
            &bar__default,
       },
};
static const struct isa_case sel_f32__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sel_f32 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "sel.f32",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6680000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &sel_f32__default,
       },
};
static const struct isa_case conv__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___two,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_conv = {

       .parent   = &bitset___instruction_cat5,
       .name     = "conv",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa200000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &conv__default,
       },
};
static const struct isa_case isam__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_isam = {

       .parent   = &bitset___instruction_cat5,
       .name     = "isam",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa000000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &isam__default,
       },
};
static const struct isa_case samgq__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___one,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_samgq = {

       .parent   = &bitset___instruction_cat5,
       .name     = "samgq",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa180000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &samgq__default,
       },
};
static const struct isa_case predf__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_predf = {

       .parent   = &bitset___instruction_cat0_1src,
       .name     = "predf",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x702000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe78ee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &predf__default,
       },
};
static const struct isa_case __instruction_cat0_branch_1src__default = {
       .display  = "{SY}{SS}{EQ}{JP}{NAME} {INV1}p0.{COMP1}, #{IMMED}",
       .num_fields = 2,
       .fields   = {
          { .name = "INV1", .low = 52, .high = 52,
            .display = "!",
            .type = TYPE_BOOL,
          },
          { .name = "COMP1", .low = 53, .high = 54,
            .type = TYPE_ENUM,
            .enums = &enum___swiz,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat0_branch_1src = {

       .parent   = &bitset___instruction_cat0_branch,
       .name     = "#instruction-cat0-branch-1src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80000000000000,
       .dontcare = 0xce81f00000000,
       .mask     = 0xe78ee81f00000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat0_branch_1src__default,
       },
};
static const struct isa_case mad_f16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_mad_f16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "mad.f16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6300000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &mad_f16__default,
       },
};
static const struct isa_case stp__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} p[{DST}{OFF}], {SRC}, {SIZE}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_stp = {

       .parent   = &bitset___instruction_cat6_a3xx_st,
       .name     = "stp",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc140010000800000,
       .dontcare = 0x300000007fc000,
       .mask     = 0xe7f0010000ffc001,
       .num_cases = 1,
       .cases    = {
            &stp__default,
       },
};
static const struct isa_case __reg_relative_gpr__case0 = {
       .expr     = &expr___offset_zero,
       .display  = "r<a0.x>",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_case __reg_relative_gpr__default = {
       .display  = "r<a0.x + {OFFSET}>",
       .num_fields = 1,
       .fields   = {
          { .name = "OFFSET", .low = 0, .high = 9,
            .type = TYPE_INT,
          },
       },
};
static const struct isa_bitset bitset___reg_relative_gpr = {

       .name     = "#reg-relative-gpr",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 2,
       .cases    = {
            &__reg_relative_gpr__case0,
            &__reg_relative_gpr__default,
       },
};
static const struct isa_case ldp__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} {DST}, p[{SRC}{OFF}], {SIZE}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_ldp = {

       .parent   = &bitset___instruction_cat6_a3xx_ld,
       .name     = "ldp",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc080000000800001,
       .dontcare = 0x31ff0000400000,
       .mask     = 0xe7f1ff0000c00001,
       .num_cases = 1,
       .cases    = {
            &ldp__default,
       },
};
static const struct isa_case flow_rev__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_flow_rev = {

       .parent   = &bitset___instruction_cat0_0src,
       .name     = "flow_rev",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x580000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe7fee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &flow_rev__default,
       },
};
static const struct isa_case mad_u16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_mad_u16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "mad.u16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6000000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &mad_u16__default,
       },
};
static const struct isa_case kill__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_kill = {

       .parent   = &bitset___instruction_cat0_1src,
       .name     = "kill",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x280000000000000,
       .dontcare = 0xc080000000000,
       .mask     = 0xe78ee8ff00000000,
       .num_cases = 1,
       .cases    = {
            &kill__default,
       },
};
static const struct isa_case __instruction_cat6_a3xx_atomic_1src__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset___instruction_cat6_a3xx_atomic_1src = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic,
       .name     = "#instruction-cat6-a3xx-atomic-1src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe0000100000001ff,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6_a3xx_atomic_1src__default,
       },
};
static const struct isa_case sel_f16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_sel_f16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "sel.f16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6600000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &sel_f16__default,
       },
};
static const struct isa_case sub_u__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_sub_u = {

       .parent   = &bitset___instruction_cat2_2src,
       .name     = "sub.u",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4240000000000000,
       .dontcare = 0x7000000000000,
       .mask     = 0xe7e7000000000000,
       .num_cases = 1,
       .cases    = {
            &sub_u__default,
       },
};
static const struct isa_case atomic_sub__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_sub = {

       .parent   = &bitset___instruction_cat6_a3xx_atomic_2src,
       .name     = "atomic.sub",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc440000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe7c00100000001ff,
       .num_cases = 1,
       .cases    = {
            &atomic_sub__default,
       },
};
static const struct isa_case convm__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___two,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_convm = {

       .parent   = &bitset___instruction_cat5,
       .name     = "convm",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa240000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &convm__default,
       },
};
static const struct isa_case mad_u24__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_mad_u24 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "mad.u24",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6200000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &mad_u24__default,
       },
};
static const struct isa_case fence__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_fence = {

       .parent   = &bitset___instruction_cat7,
       .name     = "fence",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xe082000000000000,
       .dontcare = 0x5ffffffffffff,
       .mask     = 0xe787ffffffffffff,
       .num_cases = 1,
       .cases    = {
            &fence__default,
       },
};
static const struct isa_field_params __instruction_cat6_a3xx_ibo__default_ssbo = {
       .num_params = 1,
       .params = {
           { .name= "SSBO_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_field_params __instruction_cat6_a3xx_ibo__default_src3 = {
       .num_params = 1,
       .params = {
           { .name= "SRC3_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_field_params __instruction_cat6_a3xx_ibo__default_src2 = {
       .num_params = 1,
       .params = {
           { .name= "SRC2_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_case __instruction_cat6_a3xx_ibo__default = {
       .display  = "{SY}{JP}{NAME}.{TYPED}.{D}d.{TYPE}.{TYPE_SIZE} g[{SSBO}], {SRC1}, {SRC2}, {SRC3}",
       .num_fields = 12,
       .fields   = {
          { .name = "TYPE_SIZE", .low = 0, .high = 0,
            .expr = &expr___cat6_type_size,
            .type = TYPE_UINT,
          },
          { .name = "D_MINUS_ONE", .low = 9, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "TYPE_SIZE_MINUS_ONE", .low = 12, .high = 13,
            .type = TYPE_UINT,
          },
          { .name = "SRC2_IM", .low = 23, .high = 23,
            .type = TYPE_BOOL,
          },
          { .name = "SRC3_IM", .low = 40, .high = 40,
            .type = TYPE_BOOL,
          },
          { .name = "TYPED", .low = 11, .high = 11,
            .type = TYPE_BITSET,
            .bitsets = __cat6_typed,
          },
          { .name = "D", .low = 0, .high = 0,
            .expr = &expr___cat6_d,
            .type = TYPE_UINT,
          },
          { .name = "SSBO", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &__instruction_cat6_a3xx_ibo__default_ssbo,
          },
          { .name = "SSBO_IM", .low = 53, .high = 53,
            .type = TYPE_BOOL,
          },
          { .name = "SRC1", .low = 1, .high = 8,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC3", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &__instruction_cat6_a3xx_ibo__default_src3,
          },
          { .name = "SRC2", .low = 24, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &__instruction_cat6_a3xx_ibo__default_src2,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat6_a3xx_ibo = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "#instruction-cat6-a3xx-ibo",
       .gen      = {
           .min  = 0,
           .max  = 599,
       },
       .match    = 0xc000000000000001,
       .dontcare = 0x100000007fc000,
       .mask     = 0xe0100000007fc001,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat6_a3xx_ibo__default,
       },
};
static const struct isa_case madsh_m16__default = {
       .num_fields = 1,
       .fields   = {
          { .name = "FULL", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_madsh_m16 = {

       .parent   = &bitset___instruction_cat3,
       .name     = "madsh.m16",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x6180000000000000,
       .dontcare = 0x2000,
       .mask     = 0xe780000000002000,
       .num_cases = 1,
       .cases    = {
            &madsh_m16__default,
       },
};
static const struct isa_case getbuf__default = {
       .num_fields = 4,
       .fields   = {
          { .name = "NUM_SRC", .low = 0, .high = 0,
            .expr = &expr___zero,
            .type = TYPE_UINT,
          },
          { .name = "HAS_TYPE", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_TEX", .low = 0, .high = 0,
            .expr = &expr___true,
            .type = TYPE_BOOL,
          },
          { .name = "HAS_SAMP", .low = 0, .high = 0,
            .expr = &expr___false,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_bitset bitset_getbuf = {

       .parent   = &bitset___instruction_cat5,
       .name     = "getbuf",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xa2c0000000000000,
       .dontcare = 0x20000,
       .mask     = 0xe7c0000000060000,
       .num_cases = 1,
       .cases    = {
            &getbuf__default,
       },
};
static const struct isa_case cbits_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_cbits_b = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "cbits.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x47a0000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &cbits_b__default,
       },
};
static const struct isa_case atomic_b_and__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_atomic_b_and = {

       .parent   = &bitset___instruction_cat6_a6xx_ibo,
       .name     = "atomic.b.and",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc030000000660001,
       .dontcare = 0x0,
       .mask     = 0xe7f0010000ffc031,
       .num_cases = 1,
       .cases    = {
            &atomic_b_and__default,
       },
};
static const struct isa_field_params __instruction_cat6_a3xx_atomic__case0_ssbo = {
       .num_params = 1,
       .params = {
           { .name= "SSBO_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_case __instruction_cat6_a3xx_atomic__case0 = {
       .expr     = &expr___cat6_global,
       .display  = "{SY}{JP}{NAME}.{TYPED}.{D}d.{TYPE}.{TYPE_SIZE}.g {DST}, g[{SSBO}], {SRC1}, {SRC2}, {SRC3}",
       .num_fields = 3,
       .fields   = {
          { .name = "SRC3", .low = 1, .high = 8,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SSBO", .low = 41, .high = 48,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &__instruction_cat6_a3xx_atomic__case0_ssbo,
          },
          { .name = "SSBO_IM", .low = 53, .high = 53,
            .type = TYPE_BOOL,
          },
       },
};
static const struct isa_field_params __instruction_cat6_a3xx_atomic__default_src1 = {
       .num_params = 1,
       .params = {
           { .name= "SRC1_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_field_params __instruction_cat6_a3xx_atomic__default_src2 = {
       .num_params = 1,
       .params = {
           { .name= "SRC2_IM",  .as = "SRC_IM" },

       },
};
static const struct isa_case __instruction_cat6_a3xx_atomic__default = {
       .display  = "{SY}{JP}{NAME}.{TYPED}.{D}d.{TYPE}.{TYPE_SIZE}.l {DST}, l[{SRC1}], {SRC2}",
       .num_fields = 13,
       .fields   = {
          { .name = "TYPE_SIZE", .low = 0, .high = 0,
            .expr = &expr___cat6_type_size,
            .type = TYPE_UINT,
          },
          { .name = "SRC1_IM", .low = 22, .high = 22,
            .type = TYPE_BOOL,
          },
          { .name = "D_MINUS_ONE", .low = 9, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "TYPE_SIZE_MINUS_ONE", .low = 12, .high = 13,
            .type = TYPE_UINT,
          },
          { .name = "#instruction-cat6-a3xx-atomic#assert3", .low = 53, .high = 53,
            .type = TYPE_ASSERT,
            .val = 0,
          },
          { .name = "SRC2_IM", .low = 23, .high = 23,
            .type = TYPE_BOOL,
          },
          { .name = "#instruction-cat6-a3xx-atomic#assert2", .low = 41, .high = 48,
            .type = TYPE_ASSERT,
            .val = 0,
          },
          { .name = "TYPED", .low = 11, .high = 11,
            .type = TYPE_BITSET,
            .bitsets = __cat6_typed,
          },
          { .name = "DST", .low = 32, .high = 39,
            .type = TYPE_BITSET,
            .bitsets = __reg_gpr,
          },
          { .name = "SRC1", .low = 14, .high = 21,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &__instruction_cat6_a3xx_atomic__default_src1,
          },
          { .name = "D", .low = 0, .high = 0,
            .expr = &expr___cat6_d,
            .type = TYPE_UINT,
          },
          { .name = "G", .low = 52, .high = 52,
            .type = TYPE_BOOL,
          },
          { .name = "SRC2", .low = 24, .high = 31,
            .type = TYPE_BITSET,
            .bitsets = __cat6_src,
            .params = &__instruction_cat6_a3xx_atomic__default_src2,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat6_a3xx_atomic = {

       .parent   = &bitset___instruction_cat6_a3xx,
       .name     = "#instruction-cat6-a3xx-atomic",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc000000000000001,
       .dontcare = 0x100000001fe,
       .mask     = 0xe0000100000001ff,
       .num_cases = 2,
       .cases    = {
            &__instruction_cat6_a3xx_atomic__case0,
            &__instruction_cat6_a3xx_atomic__default,
       },
};
static const struct isa_case stlw__default = {
       .display  = "{SY}{JP}{NAME}.{TYPE} l[{DST}{OFF}], {SRC}, {SIZE}",
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_stlw = {

       .parent   = &bitset___instruction_cat6_a3xx_st,
       .name     = "stlw",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0xc2c0010000800000,
       .dontcare = 0x300000007fc001,
       .mask     = 0xe7f0010000ffc001,
       .num_cases = 1,
       .cases    = {
            &stlw__default,
       },
};
static const struct isa_case __instruction_cat0_branch_2src__default = {
       .display  = "{SY}{SS}{EQ}{JP}{NAME} {INV1}p0.{COMP1}, {INV2}p0.{COMP2}, #{IMMED}",
       .num_fields = 4,
       .fields   = {
          { .name = "INV1", .low = 52, .high = 52,
            .display = "!",
            .type = TYPE_BOOL,
          },
          { .name = "INV2", .low = 45, .high = 45,
            .display = "!",
            .type = TYPE_BOOL,
          },
          { .name = "COMP1", .low = 53, .high = 54,
            .type = TYPE_ENUM,
            .enums = &enum___swiz,
          },
          { .name = "COMP2", .low = 46, .high = 47,
            .type = TYPE_ENUM,
            .enums = &enum___swiz,
          },
       },
};
static const struct isa_bitset bitset___instruction_cat0_branch_2src = {

       .parent   = &bitset___instruction_cat0_branch,
       .name     = "#instruction-cat0-branch-2src",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x80000000000000,
       .dontcare = 0xc081f00000000,
       .mask     = 0xe78e081f00000000,
       .num_cases = 1,
       .cases    = {
            &__instruction_cat0_branch_2src__default,
       },
};
static const struct isa_case not_b__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_not_b = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "not.b",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x43c0000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &not_b__default,
       },
};
static const struct isa_case rndne_f__default = {
       .num_fields = 0,
       .fields   = {
       },
};
static const struct isa_bitset bitset_rndne_f = {

       .parent   = &bitset___instruction_cat2_1src,
       .name     = "rndne.f",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x4160000000000000,
       .dontcare = 0x70000ffff0000,
       .mask     = 0xe7e70000ffff0000,
       .num_cases = 1,
       .cases    = {
            &rndne_f__default,
       },
};
static const struct isa_case __reg_const__default = {
       .display  = "c{CONST}.{SWIZ}",
       .num_fields = 2,
       .fields   = {
          { .name = "CONST", .low = 2, .high = 10,
            .type = TYPE_UINT,
          },
          { .name = "SWIZ", .low = 0, .high = 1,
            .type = TYPE_ENUM,
            .enums = &enum___swiz,
          },
       },
};
static const struct isa_bitset bitset___reg_const = {

       .name     = "#reg-const",
       .gen      = {
           .min  = 0,
           .max  = -1,
       },
       .match    = 0x0,
       .dontcare = 0x0,
       .mask     = 0x0,
       .num_cases = 1,
       .cases    = {
            &__reg_const__default,
       },
};

/*
 * bitset hierarchy root tables (where decoding starts from):
 */

const struct isa_bitset *__cat5_type[] = {
          &bitset___cat5_type,
    (void *)0
};
const struct isa_bitset *__cat6_src[] = {
          &bitset___cat6_src,
    (void *)0
};
const struct isa_bitset *__cat3_src[] = {
          &bitset___cat3_src_relative_const,
          &bitset___cat3_src_const,
          &bitset___cat3_src_gpr,
          &bitset___cat3_src_relative_gpr,
    (void *)0
};
const struct isa_bitset *__cat5_samp_s2en_bindless_a1[] = {
          &bitset___cat5_samp_s2en_bindless_a1,
    (void *)0
};
const struct isa_bitset *__cat6_typed[] = {
          &bitset___cat6_typed,
    (void *)0
};
const struct isa_bitset *__cat1_relative_gpr_src[] = {
          &bitset___cat1_relative_gpr_src,
    (void *)0
};
const struct isa_bitset *__reg_gpr[] = {
          &bitset___reg_gpr,
    (void *)0
};
const struct isa_bitset *__reg_relative_const[] = {
          &bitset___reg_relative_const,
    (void *)0
};
const struct isa_bitset *__reg_relative_gpr[] = {
          &bitset___reg_relative_gpr,
    (void *)0
};
const struct isa_bitset *__cat1_relative_const_src[] = {
          &bitset___cat1_relative_const_src,
    (void *)0
};
const struct isa_bitset *__cat5_src2[] = {
          &bitset___cat5_src2,
    (void *)0
};
const struct isa_bitset *__cat5_tex[] = {
          &bitset___cat5_tex,
    (void *)0
};
const struct isa_bitset *__cat1_gpr_src[] = {
          &bitset___cat1_gpr_src,
    (void *)0
};
const struct isa_bitset *__cat1_dst[] = {
          &bitset___cat1_dst,
    (void *)0
};
const struct isa_bitset *__cat6_base[] = {
          &bitset___cat6_base,
    (void *)0
};
const struct isa_bitset *__cat5_src3[] = {
          &bitset___cat5_src3,
    (void *)0
};
const struct isa_bitset *__cat5_s2en_bindless_base[] = {
          &bitset___cat5_s2en_bindless_base,
    (void *)0
};
const struct isa_bitset *__multisrc[] = {
          &bitset___multisrc_immed_flut_half,
          &bitset___multisrc_const,
          &bitset___multisrc_immed_flut_full,
          &bitset___multisrc_gpr,
          &bitset___multisrc_relative_gpr,
          &bitset___mulitsrc_immed,
          &bitset___multisrc_relative_const,
    (void *)0
};
const struct isa_bitset *__cat1_immed_src[] = {
          &bitset___cat1_immed_src,
    (void *)0
};
const struct isa_bitset *__cat5_tex_s2en_bindless[] = {
          &bitset___cat5_tex_s2en_bindless,
    (void *)0
};
const struct isa_bitset *__cat5_src1[] = {
          &bitset___cat5_src1,
    (void *)0
};
const struct isa_bitset *__cat5_samp[] = {
          &bitset___cat5_samp,
    (void *)0
};
const struct isa_bitset *__instruction[] = {
          &bitset_sel_b16,
          &bitset_floor_f,
          &bitset_isamm,
          &bitset_mull_u,
          &bitset_rgetinfo,
          &bitset_exp2,
          &bitset_ldg,
          &bitset_shb,
          &bitset_predt,
          &bitset_mov_immed,
          &bitset_mad_s24,
          &bitset_cut,
          &bitset_getbit_b,
          &bitset_shr_b,
          &bitset_mov_gpr,
          &bitset_max_u,
          &bitset_msad,
          &bitset_atomic_b_max,
          &bitset_stib_b,
          &bitset_cmpv_f,
          &bitset_getinfo,
          &bitset_braa,
          &bitset_xor_b,
          &bitset_max_s,
          &bitset_sub_u,
          &bitset_prede,
          &bitset_ldib_b,
          &bitset_getwid,
          &bitset_sign_f,
          &bitset_sad_s32,
          &bitset_stl,
          &bitset_mgen_b,
          &bitset_atomic_b_xchg,
          &bitset_saml,
          &bitset_mul_u24,
          &bitset_atomic_xor,
          &bitset_samb,
          &bitset_atomic_add,
          &bitset_ldc,
          &bitset_min_s,
          &bitset_cmps_s,
          &bitset_setrm,
          &bitset_nop,
          &bitset_log2,
          &bitset_shl_b,
          &bitset_atomic_b_cmpxchg,
          &bitset_shps,
          &bitset_sel_s32,
          &bitset_dsypp_1,
          &bitset_absneg_f,
          &bitset_add_s,
          &bitset_getsize,
          &bitset_mad_f32,
          &bitset_or_b,
          &bitset_cmpv_s,
          &bitset_min_f,
          &bitset_ldl,
          &bitset_min_u,
          &bitset_mad_s16,
          &bitset_sam,
          &bitset_ret,
          &bitset_cmps_u,
          &bitset_atomic_b_or,
          &bitset_atomic_cmpxchg,
          &bitset_sin,
          &bitset_samgp3,
          &bitset_atomic_dec,
          &bitset_sqrt,
          &bitset_shpe,
          &bitset_add_u,
          &bitset_dsy,
          &bitset_brac,
          &bitset_atomic_min,
          &bitset_bary_f,
          &bitset_call,
          &bitset_ceil_f,
          &bitset_getpos,
          &bitset_dsxpp_1,
          &bitset_atomic_and,
          &bitset_samgp0,
          &bitset_resinfo,
          &bitset_rcp,
          &bitset_gather4r,
          &bitset_ball,
          &bitset_cmps_f,
          &bitset_atomic_or,
          &bitset_gather4a,
          &bitset_atomic_b_xor,
          &bitset_add_f,
          &bitset_ldlw,
          &bitset_hexp2,
          &bitset_atomic_xchg,
          &bitset_atomic_b_min,
          &bitset_chsh,
          &bitset_chmask,
          &bitset_hrsq,
          &bitset_emit,
          &bitset_madsh_u16,
          &bitset_rndaz_f,
          &bitset_jump,
          &bitset_samgp2,
          &bitset_cos,
          &bitset_stc,
          &bitset_clz_b,
          &bitset_mov_relgpr,
          &bitset_atomic_max,
          &bitset_cmpv_u,
          &bitset_getspid,
          &bitset_max_f,
          &bitset_resinfo_b,
          &bitset_rsq,
          &bitset_sad_s16,
          &bitset_rgetpos,
          &bitset_stg,
          &bitset_atomic_b_sub,
          &bitset_mul_f,
          &bitset_sub_s,
          &bitset_end,
          &bitset_stgb,
          &bitset_bany,
          &bitset_hlog2,
          &bitset_absneg_s,
          &bitset_clz_s,
          &bitset_atomic_inc,
          &bitset_sel_b32,
          &bitset_ldgb,
          &bitset_bkt,
          &bitset_and_b,
          &bitset_getlod,
          &bitset_sel_s16,
          &bitset_movmsk,
          &bitset_samgp1,
          &bitset_trunc_f,
          &bitset_brax,
          &bitset_brao,
          &bitset_mov_relconst,
          &bitset_ldlv,
          &bitset_stib,
          &bitset_bfrev_b,
          &bitset_dsx,
          &bitset_gather4b,
          &bitset_ashr_b,
          &bitset_isaml,
          &bitset_gather4g,
          &bitset_mul_s24,
          &bitset_getone,
          &bitset_atomic_b_add,
          &bitset_mov_const,
          &bitset_br,
          &bitset_bar,
          &bitset_sel_f32,
          &bitset_conv,
          &bitset_isam,
          &bitset_samgq,
          &bitset_predf,
          &bitset_mad_f16,
          &bitset_stp,
          &bitset_ldp,
          &bitset_flow_rev,
          &bitset_mad_u16,
          &bitset_kill,
          &bitset_sel_f16,
          &bitset_atomic_sub,
          &bitset_convm,
          &bitset_mad_u24,
          &bitset_fence,
          &bitset_madsh_m16,
          &bitset_getbuf,
          &bitset_cbits_b,
          &bitset_atomic_b_and,
          &bitset_stlw,
          &bitset_not_b,
          &bitset_rndne_f,
    (void *)0
};
const struct isa_bitset *__reg_const[] = {
          &bitset___reg_const,
    (void *)0
};
const struct isa_bitset *__cat1_const_src[] = {
          &bitset___cat1_const_src,
    (void *)0
};

