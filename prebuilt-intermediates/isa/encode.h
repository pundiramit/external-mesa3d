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

#include <stdbool.h>
#include <stdint.h>



/**
 * Opaque type from the PoV of generated code, but allows state to be passed
 * thru to the hand written helpers used by the generated code.
 */
struct encode_state;

struct bitset_params;

static uint64_t
pack_field(unsigned low, unsigned high, uint64_t val)
{
   val &= ((UINT64_C(1) << (1 + high - low)) - 1);
   return val << low;
}

/*
 * Forward-declarations (so we don't have to figure out which order to
 * emit various encoders when they have reference each other)
 */

static uint64_t encode__cat5_type(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);
static uint64_t encode__cat5_src2(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat6_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__instruction(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);
static uint64_t encode__multisrc(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat5_src3(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat1_const_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat5_s2en_bindless_base(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);
static uint64_t encode__reg_relative_const(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat6_base(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);
static uint64_t encode__cat1_gpr_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat5_samp(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);
static uint64_t encode__cat1_dst(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat6_typed(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);
static uint64_t encode__cat1_relative_gpr_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat1_relative_const_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat5_src1(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat5_samp_s2en_bindless_a1(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);
static uint64_t encode__cat1_immed_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__reg_const(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__reg_gpr(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat5_tex(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);
static uint64_t encode__cat3_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__reg_relative_gpr(struct encode_state *s, struct bitset_params *p, struct ir3_register * src);
static uint64_t encode__cat5_tex_s2en_bindless(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src);


/*
 * Expression evaluators:
 */

struct bitset_params {
   int64_t SRC_R;
   int64_t FULL;
   int64_t BINDLESS;
   int64_t BASE_HI;
   int64_t HAS_TYPE;
   int64_t NUM_SRC;
   int64_t HALF;
   int64_t O;
   int64_t DESC_MODE;
   int64_t HAS_SAMP;
   int64_t HAS_TEX;
   int64_t SRC_IM;
   int64_t SRC_TYPE;
   int64_t DST_REL;
};

#define push(v) do {             assert(sp < ARRAY_SIZE(stack));             stack[sp] = (v);             sp++;         } while (0)
#define peek() ({             assert(sp < ARRAY_SIZE(stack));             stack[sp - 1];         })
#define pop() ({             assert(sp > 0);             --sp;             stack[sp];         })






          
static inline int64_t
__cat5_type_expr_anon_23(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t HAS_TYPE;

          HAS_TYPE = p->HAS_TYPE;
    return HAS_TYPE;
}



          
static inline int64_t
__cat5_src2_expr_anon_18(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t NUM_SRC;
    int64_t O;

          NUM_SRC = p->NUM_SRC;

          O = p->O;
    return O || (NUM_SRC > 1);
}



          
static inline int64_t
__cat6_src_expr_anon_32(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t SRC_IM;

          SRC_IM = p->SRC_IM;
    return SRC_IM;
}



          
static inline int64_t
__instruction_expr___dest_half(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DST_CONV;
    int64_t DST;
    int64_t FULL;

          DST_CONV = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);

          { 
 struct bitset_params bp = {
 };

          DST = encode__reg_gpr(s, &bp, src->regs[0]);
          }

          FULL = !(src->regs[1]->flags & IR3_REG_HALF);
    return (FULL == DST_CONV) && (DST <= 0xf7 /* p0.x */);
}


          
static inline int64_t
__instruction_expr___cat2_cat3_nop_encoding(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t SRC2_R;
    int64_t SRC1_R;
    int64_t REPEAT;

          SRC2_R = extract_SRC2_R(src);

          SRC1_R = extract_SRC1_R(src);

          REPEAT = src->repeat;
    return ((SRC1_R != 0) || (SRC2_R != 0)) && (REPEAT == 0);
}


          
static inline int64_t
__instruction_expr___cat2_cat3_nop_value(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t SRC2_R;
    int64_t SRC1_R;

          SRC2_R = extract_SRC2_R(src);

          SRC1_R = extract_SRC1_R(src);
    return SRC1_R | (SRC2_R << 1);
}


          
static inline int64_t
__instruction_expr___zero(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    return 0;
}


          
static inline int64_t
__instruction_expr___true(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    return 1;
}


          
static inline int64_t
__instruction_expr___one(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    return 1;
}


          
static inline int64_t
__instruction_expr___false(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    return 0;
}


          
static inline int64_t
__instruction_expr_anon_16(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t S2EN_BINDLESS;

          S2EN_BINDLESS = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
    return S2EN_BINDLESS;
}


          
static inline int64_t
__instruction_expr___cat5_s2enb_is_bindless(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DESC_MODE;

          DESC_MODE = extract_cat5_DESC_MODE(src);
    return (DESC_MODE == 1) /* CAT5_BINDLESS_A1_UNIFORM */ ||
	(DESC_MODE == 2) /* CAT5_BINDLESS_NONUNIFORM */ ||
	(DESC_MODE == 3) /* CAT5_BINDLESS_A1_NONUNIFORM */ ||
	(DESC_MODE == 5) /* CAT5_BINDLESS_UNIFORM */ ||
	(DESC_MODE == 6) /* CAT5_BINDLESS_IMM */ ||
	(DESC_MODE == 7) /* CAT5_BINDLESS_A1_IMM */;
}


          
static inline int64_t
__instruction_expr___cat5_s2enb_is_uniform(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DESC_MODE;

          DESC_MODE = extract_cat5_DESC_MODE(src);
    return (DESC_MODE == 1) /* CAT5_BINDLESS_A1_UNIFORM */ ||
	(DESC_MODE == 4) /* CAT5_UNIFORM */ ||
	(DESC_MODE == 5) /* CAT5_BINDLESS_UNIFORM */;
}


          
static inline int64_t
__instruction_expr___cat5_s2enb_uses_a1(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DESC_MODE;

          DESC_MODE = extract_cat5_DESC_MODE(src);
    return (DESC_MODE == 1) /* CAT5_BINDLESS_A1_UNIFORM */ ||
	(DESC_MODE == 3) /* CAT5_BINDLESS_A1_NONUNIFORM */ ||
	(DESC_MODE == 7) /* CAT5_BINDLESS_A1_IMM */;
}


          
static inline int64_t
__instruction_expr___cat5_s2enb_is_indirect(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DESC_MODE;

          DESC_MODE = extract_cat5_DESC_MODE(src);
    return DESC_MODE < 6  /* CAT5_BINDLESS_IMM */;
}


          
static inline int64_t
__instruction_expr_anon_15(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t TYPE;

          { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

          TYPE = encode__cat5_type(s, &bp, src);
          }
    return (TYPE == 0) /* f16 */ ||
			(TYPE == 2) /* u16 */ ||
			(TYPE == 4) /* s16 */ ||
			(TYPE == 6) /* u8 */  ||
			(TYPE == 7) /* s8 */;
}


          
static inline int64_t
__instruction_expr___multisrc_half(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t FULL;

          FULL = extract_cat5_FULL(src);
    return !FULL;
}


          
static inline int64_t
__instruction_expr___cat6_d(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t D_MINUS_ONE;

          D_MINUS_ONE = src->cat6.d - 1;
    return D_MINUS_ONE + 1;
}


          
static inline int64_t
__instruction_expr___cat6_direct(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t MODE;

          MODE = extract_cat6_DESC_MODE(src);
    return MODE == 0;
}


          
static inline int64_t
__instruction_expr___cat6_type_size(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t TYPE_SIZE_MINUS_ONE;

          TYPE_SIZE_MINUS_ONE = src->cat6.iim_val - 1;
    return TYPE_SIZE_MINUS_ONE + 1;
}


          
static inline int64_t
__instruction_expr_anon_28(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t OFF_HI;
    int64_t OFF_LO;

          OFF_HI = src->cat6.dst_offset >> 8;

          OFF_LO = src->cat6.dst_offset & 0xff;
    return (OFF_HI << 8) | OFF_LO;
}


          
static inline int64_t
__instruction_expr___two(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    return 2;
}


          
static inline int64_t
__instruction_expr___cat6_global(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t G;

          G = !!(src->flags & IR3_INSTR_G);
    return G;
}


          
static inline int64_t
__instruction_expr_anon_4(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DST;
    int64_t DST_TYPE;
    int64_t SRC_TYPE;

          { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

          DST = encode__cat1_dst(s, &bp, src->regs[0]);
          }

          DST_TYPE = src->cat1.dst_type;

          SRC_TYPE = src->cat1.src_type;
    return (DST == 0xf4 /* a0.x */) && (SRC_TYPE == 4 /* s16 */) && (DST_TYPE == 4);
}


          
static inline int64_t
__instruction_expr_anon_5(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DST;
    int64_t DST_TYPE;
    int64_t SRC_TYPE;

          { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

          DST = encode__cat1_dst(s, &bp, src->regs[0]);
          }

          DST_TYPE = src->cat1.dst_type;

          SRC_TYPE = src->cat1.src_type;
    return (DST == 0xf5 /* a0.y */) && (SRC_TYPE == 2 /* u16 */) && (DST_TYPE == 2);
}


          
static inline int64_t
__instruction_expr_anon_6(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DST_TYPE;
    int64_t SRC_TYPE;

          DST_TYPE = src->cat1.dst_type;

          SRC_TYPE = src->cat1.src_type;
    return SRC_TYPE != DST_TYPE;
}


          
static inline int64_t
__instruction_expr_anon_3(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t DST_TYPE;

          DST_TYPE = src->cat1.dst_type;
    return (DST_TYPE == 0) /* f16 */ ||
			(DST_TYPE == 2) /* u16 */ ||
			(DST_TYPE == 4) /* s16 */ ||
			(DST_TYPE == 6) /* u8 */  ||
			(DST_TYPE == 7) /* s8 */;
}


          
static inline int64_t
__instruction_expr_anon_2(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t SRC_TYPE;

          SRC_TYPE = src->cat1.src_type;
    return (SRC_TYPE == 0) /* f16 */ ||
			(SRC_TYPE == 2) /* u16 */ ||
			(SRC_TYPE == 4) /* s16 */ ||
			(SRC_TYPE == 6) /* u8 */  ||
			(SRC_TYPE == 7) /* s8 */;
}


          
static inline int64_t
__instruction_expr_anon_25(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t SRC2_REG;

          SRC2_REG = !(src->regs[2]->flags & IR3_REG_IMMED);
    return !SRC2_REG;
}


          
static inline int64_t
__instruction_expr_anon_26(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t G;

          G = (src->flags & IR3_INSTR_G) && !(src->regs[4]->flags & IR3_REG_IMMED);
    return !G;
}


          
static inline int64_t
__instruction_expr_anon_27(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t OFF_HI;
    int64_t OFF_LO;

          OFF_HI = src->cat6.dst_offset >> 8;

          OFF_LO = src->cat6.dst_offset;
    return (OFF_HI << 8) | OFF_LO;
}


          
static inline int64_t
__instruction_expr_anon_29(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t K;

          K = 0;
    return K;
}


          
static inline int64_t
__instruction_expr_anon_12(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t REPEAT;

          REPEAT = util_last_bit(src->regs[0]->wrmask) - 1;
    return (REPEAT + 1) * 32;
}



          
static inline int64_t
__multisrc_expr___multisrc_half(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t FULL;

          FULL = p->FULL;
    return !FULL;
}



          
static inline int64_t
__cat5_src3_expr___cat5_s2enb_is_indirect(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t DESC_MODE;

          DESC_MODE = p->DESC_MODE;
    return DESC_MODE < 6  /* CAT5_BINDLESS_IMM */;
}


          
static inline int64_t
__cat5_src3_expr_anon_24(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t BINDLESS;

          BINDLESS = p->BINDLESS;
    return !BINDLESS;
}


          
static inline int64_t
__cat5_src3_expr___cat5_s2enb_uses_a1(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t DESC_MODE;

          DESC_MODE = p->DESC_MODE;
    return (DESC_MODE == 1) /* CAT5_BINDLESS_A1_UNIFORM */ ||
	(DESC_MODE == 3) /* CAT5_BINDLESS_A1_NONUNIFORM */ ||
	(DESC_MODE == 7) /* CAT5_BINDLESS_A1_IMM */;
}




          
static inline int64_t
__cat5_s2en_bindless_base_expr_anon_14(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t BINDLESS;

          BINDLESS = p->BINDLESS;
    return BINDLESS;
}


          
static inline int64_t
__cat5_s2en_bindless_base_expr_anon_13(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t BASE_HI;
    int64_t BASE_LO;

          BASE_HI = p->BASE_HI;

          BASE_LO = src->cat5.tex_base & 0x1;
    return (BASE_HI * 2) | BASE_LO;
}



          
static inline int64_t
__reg_relative_const_expr___offset_zero(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t OFFSET;

          OFFSET = src->array.offset;
    return OFFSET == 0;
}



          
static inline int64_t
__cat6_base_expr_anon_31(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t BINDLESS;

          BINDLESS = p->BINDLESS;
    return BINDLESS;
}




          
static inline int64_t
__cat5_samp_expr_anon_19(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t HAS_SAMP;

          HAS_SAMP = p->HAS_SAMP;
    return HAS_SAMP;
}



          
static inline int64_t
__cat1_dst_expr_anon_0(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t DST_REL;
    int64_t OFFSET;

          DST_REL = p->DST_REL;

          OFFSET = src->array.offset;
    return (OFFSET == 0) && DST_REL;
}


          
static inline int64_t
__cat1_dst_expr_anon_1(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t DST_REL;

          DST_REL = p->DST_REL;
    return DST_REL;
}



          
static inline int64_t
__cat6_typed_expr_anon_30(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t TYPED;

          TYPED = src->cat6.typed;
    return TYPED;
}





          
static inline int64_t
__cat5_src1_expr_anon_17(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t NUM_SRC;

          NUM_SRC = p->NUM_SRC;
    return NUM_SRC > 0;
}



          
static inline int64_t
__cat5_samp_s2en_bindless_a1_expr_anon_20(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t HAS_SAMP;

          HAS_SAMP = p->HAS_SAMP;
    return HAS_SAMP;
}



          
static inline int64_t
__cat1_immed_src_expr_anon_7(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t SRC_TYPE;

          SRC_TYPE = p->SRC_TYPE;
    return SRC_TYPE == 0 /* f16 */;
}


          
static inline int64_t
__cat1_immed_src_expr_anon_8(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t SRC_TYPE;

          SRC_TYPE = p->SRC_TYPE;
    return SRC_TYPE == 1 /* f32 */;
}


          
static inline int64_t
__cat1_immed_src_expr_anon_9(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t IMMED;
    int64_t SRC_TYPE;

          IMMED = src->uim_val;

          SRC_TYPE = p->SRC_TYPE;
    return (SRC_TYPE == 3 /* u32 */) && (IMMED > 0x1000);
}


          
static inline int64_t
__cat1_immed_src_expr_anon_10(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t SRC_TYPE;

          SRC_TYPE = p->SRC_TYPE;
    return SRC_TYPE == 4 /* s16 */;
}


          
static inline int64_t
__cat1_immed_src_expr_anon_11(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t SRC_TYPE;

          SRC_TYPE = p->SRC_TYPE;
    return SRC_TYPE == 5 /* s32 */;
}




          
static inline int64_t
__reg_gpr_expr___reg_gpr_a0(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t GPR;

          GPR = src->num >> 2;
    return GPR == 61 /* a0.* */;
}


          
static inline int64_t
__reg_gpr_expr___reg_gpr_p0(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t GPR;

          GPR = src->num >> 2;
    return GPR == 62 /* p0.x */;
}



          
static inline int64_t
__cat5_tex_expr_anon_21(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t HAS_TEX;

          HAS_TEX = p->HAS_TEX;
    return HAS_TEX;
}




          
static inline int64_t
__reg_relative_gpr_expr___offset_zero(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
    int64_t OFFSET;

          OFFSET = src->array.offset;
    return OFFSET == 0;
}



          
static inline int64_t
__cat5_tex_s2en_bindless_expr_anon_22(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
    int64_t HAS_TEX;

          HAS_TEX = p->HAS_TEX;
    return HAS_TEX;
}


#undef pop
#undef peek
#undef push










/*
 * The actual encoder definitions
 */


static uint64_t
encode__cat5_type(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_type_expr_anon_23(s, p, src)) {


           
    {

             fld = src->cat5.type;
          val |= pack_field(0, 2, fld);  /* TYPE */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = src->cat5.type;
          val |= pack_field(0, 2, fld);  /* TYPE */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat5_src2(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_src2_expr_anon_18(s, p, src)) {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }



       
    {

      val |= pack_field(0, 7, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {



       
    {

      val |= pack_field(0, 7, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat6_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat6_src_expr_anon_32(s, p, src)) {


           
    {

             fld = src->iim_val;
          val |= pack_field(0, 7, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = src->num >> 2;
          val |= pack_field(2, 7, fld);  /* GPR */
           
    }


           
    {

             fld = src->num & 0x3;
          val |= pack_field(0, 1, fld);  /* SWIZ */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__instruction(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
   switch (__instruction_case(s, src)) {
   case OPC_LOG2: {
       
      uint64_t fld, val = 0x8040000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SQRT: {
       
      uint64_t fld, val = 0x80c0000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_TRUNC_F: {
       
      uint64_t fld, val = 0x41a0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETSIZE: {
       
      uint64_t fld, val = 0xa280000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MUL_F: {
       
      uint64_t fld, val = 0x4060000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CMPS_F: {
       
      uint64_t fld, val = 0x40a0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_XCHG: {
       
      uint64_t fld, val = 0xc030000000648001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SHB: {
       
      uint64_t fld, val = 0x47c0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SUB_S: {
       
      uint64_t fld, val = 0x4260000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_HEXP2: {
       
      uint64_t fld, val = 0x8160000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SHPS: {
       
      uint64_t fld, val = 0x382000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MUL_U24: {
       
      uint64_t fld, val = 0x4600000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_NOT_B: {
       
      uint64_t fld, val = 0x43c0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_STL: {
       
      uint64_t fld, val = 0xc100010000800000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


           
    {

             fld = src->cat6.dst_offset >> 8;
          val |= pack_field(9, 13, fld);  /* OFF_HI */
           
    }


           
    {

             fld = src->cat6.dst_offset & 0xff;
          val |= pack_field(32, 39, fld);  /* OFF_LO */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_LDIB_B: {
       
      uint64_t fld, val = 0xc020000000618000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_HLOG2: {
       
      uint64_t fld, val = 0x8140000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_ADD: {
       
      uint64_t fld, val = 0xc030000000640001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAD_U24: {
       
      uint64_t fld, val = 0x6200000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CONV: {
       
      uint64_t fld, val = 0xa200000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BKT: {
       
      uint64_t fld, val = 0x2000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_DSX: {
       
      uint64_t fld, val = 0xa380000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_XOR: {
       
      uint64_t fld, val = 0xc680000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_DSYPP_1: {
       
      uint64_t fld, val = 0xa640000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___false(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___false(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAX_S: {
       
      uint64_t fld, val = 0x4320000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_STGB: {
       
      uint64_t fld, val = 0xc700000000000001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[3]->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[3]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[4]->flags & IR3_REG_IMMED),  /* SRC3_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[4]); }
          val |= pack_field(32, 39, fld);  /* SRC3 */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }


           
    {

             fld = !!(src->regs[4]->flags & IR3_REG_IMMED);
          val |= pack_field(40, 40, fld);  /* SRC3_IM */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_CMPXCHG: {
       
      uint64_t fld, val = 0xc540000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MADSH_U16: {
       
      uint64_t fld, val = 0x6080000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SETRM: {
       
      uint64_t fld, val = 0x4780000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETBUF: {
       
      uint64_t fld, val = 0xa2c0000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_ADD: {
       
      uint64_t fld, val = 0xc400000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MOV_IMMED: {
       
      uint64_t fld, val = 0x2040000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_4(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_TYPE = src->cat1.src_type,  /* SRC_TYPE */
 };

             fld = encode__cat1_immed_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 31, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 244);
       
    }


       
    {

      val |= pack_field(50, 52, 4);
       
    }


       
    {

      val |= pack_field(46, 48, 4);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(32, 39, 245);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(50, 52, 2);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_5(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_TYPE = src->cat1.src_type,  /* SRC_TYPE */
 };

             fld = encode__cat1_immed_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 31, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 245);
       
    }


       
    {

      val |= pack_field(50, 52, 2);
       
    }


       
    {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_6(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_TYPE = src->cat1.src_type,  /* SRC_TYPE */
 };

             fld = encode__cat1_immed_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 31, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_TYPE = src->cat1.src_type,  /* SRC_TYPE */
 };

             fld = encode__cat1_immed_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 31, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BAR: {
       
      uint64_t fld, val = 0xe002000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat7.g;
          val |= pack_field(54, 54, fld);  /* G */
           
    }


           
    {

             fld = src->cat7.l;
          val |= pack_field(53, 53, fld);  /* L */
           
    }


           
    {

             fld = src->cat7.r;
          val |= pack_field(52, 52, fld);  /* R */
           
    }


           
    {

             fld = src->cat7.w;
          val |= pack_field(51, 51, fld);  /* W */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CUT: {
       
      uint64_t fld, val = 0x400000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ADD_F: {
       
      uint64_t fld, val = 0x4000000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ASHR_B: {
       
      uint64_t fld, val = 0x4700000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CMPS_U: {
       
      uint64_t fld, val = 0x4280000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_OR_B: {
       
      uint64_t fld, val = 0x43a0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BANY: {
       
      uint64_t fld, val = 0x80008000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.inv1;
          val |= pack_field(52, 52, fld);  /* INV1 */
           
    }


           
    {

             fld = src->cat0.comp1;
          val |= pack_field(53, 54, fld);  /* COMP1 */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SIN: {
       
      uint64_t fld, val = 0x8080000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MIN_U: {
       
      uint64_t fld, val = 0x42c0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_FLOOR_F: {
       
      uint64_t fld, val = 0x4120000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BARY_F: {
       
      uint64_t fld, val = 0x4720000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_FLOW_REV: {
       
      uint64_t fld, val = 0x580000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAMGP2: {
       
      uint64_t fld, val = 0xa580000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_EXP2: {
       
      uint64_t fld, val = 0x8060000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RGETPOS: {
       
      uint64_t fld, val = 0xa680000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_XCHG: {
       
      uint64_t fld, val = 0xc480000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAD_F16: {
       
      uint64_t fld, val = 0x6300000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MIN_S: {
       
      uint64_t fld, val = 0x42e0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_STLW: {
       
      uint64_t fld, val = 0xc2c0010000800000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


           
    {

             fld = src->cat6.dst_offset >> 8;
          val |= pack_field(9, 13, fld);  /* OFF_HI */
           
    }


           
    {

             fld = src->cat6.dst_offset & 0xff;
          val |= pack_field(32, 39, fld);  /* OFF_LO */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETWID: {
       
      uint64_t fld, val = 0xc020000000494000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_STIB: {
       
      uint64_t fld, val = 0xc740000000000001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[3]->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[3]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[4]->flags & IR3_REG_IMMED),  /* SRC3_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[4]); }
          val |= pack_field(32, 39, fld);  /* SRC3 */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }


           
    {

             fld = !!(src->regs[4]->flags & IR3_REG_IMMED);
          val |= pack_field(40, 40, fld);  /* SRC3_IM */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CLZ_S: {
       
      uint64_t fld, val = 0x4680000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_NOP: {
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_AND: {
       
      uint64_t fld, val = 0xc600000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_DEC: {
       
      uint64_t fld, val = 0xc500000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SUB_U: {
       
      uint64_t fld, val = 0x4240000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MOV_RELCONST: {
       
      uint64_t fld, val = 0x2000000000000c00;
      (void)fld;


    
    if (__instruction_expr_anon_4(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_relative_const_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 244);
       
    }


       
    {

      val |= pack_field(50, 52, 4);
       
    }


       
    {

      val |= pack_field(46, 48, 4);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(32, 39, 245);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(50, 52, 2);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_5(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_relative_const_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 245);
       
    }


       
    {

      val |= pack_field(50, 52, 2);
       
    }


       
    {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_6(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_relative_const_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_relative_const_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_LDG: {
       
      uint64_t fld, val = 0xc000000000800001;
      (void)fld;


    
    if (__instruction_expr_anon_25(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             fld = src->regs[2]->iim_val;
          val |= pack_field(1, 13, fld);  /* OFF */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


           
    {

             fld = !(src->regs[2]->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC2_REG */
           
    }



       
    {

      val |= pack_field(9, 13, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC2 */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


           
    {

             fld = !(src->regs[2]->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC2_REG */
           
    }



       
    {

      val |= pack_field(9, 13, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_PREDE: {
       
      uint64_t fld, val = 0x782000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAX_U: {
       
      uint64_t fld, val = 0x4300000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CONVM: {
       
      uint64_t fld, val = 0xa240000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BRAO: {
       
      uint64_t fld, val = 0x80002000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.inv1;
          val |= pack_field(52, 52, fld);  /* INV1 */
           
    }


           
    {

             fld = src->cat0.comp1;
          val |= pack_field(53, 54, fld);  /* COMP1 */
           
    }


           
    {

             fld = src->cat0.inv2;
          val |= pack_field(45, 45, fld);  /* INV2 */
           
    }


           
    {

             fld = src->cat0.comp2;
          val |= pack_field(46, 47, fld);  /* COMP2 */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SHR_B: {
       
      uint64_t fld, val = 0x46e0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_FENCE: {
       
      uint64_t fld, val = 0xe082000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat7.g;
          val |= pack_field(54, 54, fld);  /* G */
           
    }


           
    {

             fld = src->cat7.l;
          val |= pack_field(53, 53, fld);  /* L */
           
    }


           
    {

             fld = src->cat7.r;
          val |= pack_field(52, 52, fld);  /* R */
           
    }


           
    {

             fld = src->cat7.w;
          val |= pack_field(51, 51, fld);  /* W */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_OR: {
       
      uint64_t fld, val = 0xc030000000664001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_LDLV: {
       
      uint64_t fld, val = 0xc7c0000000c00000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->regs[1]->uim_val;
          val |= pack_field(1, 13, fld);  /* OFF */
           
    }


           
    {

             fld = src->regs[2]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_STG: {
       
      uint64_t fld, val = 0xc0c0000000800000;
      (void)fld;


    
    if (__instruction_expr_anon_26(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


           
    {

             fld = 1;
          val |= pack_field(40, 40, fld);  /* DST_OFF */
           
    }


           
    {

             fld = (src->flags & IR3_INSTR_G) && !(src->regs[4]->flags & IR3_REG_IMMED);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.dst_offset >> 8;
          val |= pack_field(9, 13, fld);  /* OFF_HI */
           
    }


           
    {

             fld = src->cat6.dst_offset;
          val |= pack_field(32, 39, fld);  /* OFF_LO */
           
    }



       
    {

      val |= pack_field(9, 13, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[4]); }
          val |= pack_field(32, 39, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


           
    {

             fld = 1;
          val |= pack_field(40, 40, fld);  /* DST_OFF */
           
    }


           
    {

             fld = (src->flags & IR3_INSTR_G) && !(src->regs[4]->flags & IR3_REG_IMMED);
          val |= pack_field(52, 52, fld);  /* G */
           
    }



       
    {

      val |= pack_field(9, 13, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ISAML: {
       
      uint64_t fld, val = 0xa040000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAD_S32: {
       
      uint64_t fld, val = 0x6780000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAD_U16: {
       
      uint64_t fld, val = 0x6000000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_SUB: {
       
      uint64_t fld, val = 0xc030000000644001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CALL: {
       
      uint64_t fld, val = 0x180000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ISAMM: {
       
      uint64_t fld, val = 0xa080000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_STC: {
       
      uint64_t fld, val = 0xc700000000800000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->regs[1]->uim_val;
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC */
           
    }


           
    {

             fld = 0 /* XXX */;
          val |= pack_field(24, 26, fld);  /* SIZE */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAMGP0: {
       
      uint64_t fld, val = 0xa500000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_OR: {
       
      uint64_t fld, val = 0xc640000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MUL_S24: {
       
      uint64_t fld, val = 0x4620000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ADD_U: {
       
      uint64_t fld, val = 0x4200000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GATHER4A: {
       
      uint64_t fld, val = 0xa4c0000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_INC: {
       
      uint64_t fld, val = 0xc4c0000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MADSH_M16: {
       
      uint64_t fld, val = 0x6180000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAD_F32: {
       
      uint64_t fld, val = 0x6380000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAD_S16: {
       
      uint64_t fld, val = 0x6700000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETONE: {
       
      uint64_t fld, val = 0x282000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MSAD: {
       
      uint64_t fld, val = 0x47e0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_JUMP: {
       
      uint64_t fld, val = 0x100000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GATHER4R: {
       
      uint64_t fld, val = 0xa400000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETLOD: {
       
      uint64_t fld, val = 0xa1c0000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BRAA: {
       
      uint64_t fld, val = 0x80004000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.inv1;
          val |= pack_field(52, 52, fld);  /* INV1 */
           
    }


           
    {

             fld = src->cat0.comp1;
          val |= pack_field(53, 54, fld);  /* COMP1 */
           
    }


           
    {

             fld = src->cat0.inv2;
          val |= pack_field(45, 45, fld);  /* INV2 */
           
    }


           
    {

             fld = src->cat0.comp2;
          val |= pack_field(46, 47, fld);  /* COMP2 */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RESINFO: {
       
      uint64_t fld, val = 0xc3c0000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RNDAZ_F: {
       
      uint64_t fld, val = 0x4180000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RESINFO_B: {
       
      uint64_t fld, val = 0xc02000000063c000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___true(s, p, src),  /* TRUE */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CHSH: {
       
      uint64_t fld, val = 0x500000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_STP: {
       
      uint64_t fld, val = 0xc140010000800000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(1, 8, fld);  /* SRC */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


           
    {

             fld = src->cat6.dst_offset >> 8;
          val |= pack_field(9, 13, fld);  /* OFF_HI */
           
    }


           
    {

             fld = src->cat6.dst_offset & 0xff;
          val |= pack_field(32, 39, fld);  /* OFF_LO */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SHPE: {
       
      uint64_t fld, val = 0x402000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETINFO: {
       
      uint64_t fld, val = 0xa340000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CLZ_B: {
       
      uint64_t fld, val = 0x46a0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAM: {
       
      uint64_t fld, val = 0xa0c0000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SHL_B: {
       
      uint64_t fld, val = 0x46c0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CMPV_U: {
       
      uint64_t fld, val = 0x4420000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_MIN: {
       
      uint64_t fld, val = 0xc030000000658001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SIGN_F: {
       
      uint64_t fld, val = 0x4080000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_AND_B: {
       
      uint64_t fld, val = 0x4380000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BRAX: {
       
      uint64_t fld, val = 0x8000c000000000;
      (void)fld;

      return val;

    }
   case OPC_EMIT: {
       
      uint64_t fld, val = 0x380000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_LDC: {
       
      uint64_t fld, val = 0xc026000000478000;
      (void)fld;


    
    if (__instruction_expr_anon_29(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[2]->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SRC2 */
           
    }


           
    {

             fld = 0;
          val |= pack_field(52, 52, fld);  /* K */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(32, 39, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC1_IM */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.d;
          val |= pack_field(9, 10, fld);  /* OFFSET */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[2]->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SRC2 */
           
    }


           
    {

             fld = 0;
          val |= pack_field(52, 52, fld);  /* K */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC1_IM */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BALL: {
       
      uint64_t fld, val = 0x8000a000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.inv1;
          val |= pack_field(52, 52, fld);  /* INV1 */
           
    }


           
    {

             fld = src->cat0.comp1;
          val |= pack_field(53, 54, fld);  /* COMP1 */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CEIL_F: {
       
      uint64_t fld, val = 0x4140000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAD_S24: {
       
      uint64_t fld, val = 0x6280000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MGEN_B: {
       
      uint64_t fld, val = 0x4740000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_COS: {
       
      uint64_t fld, val = 0x80a0000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAMB: {
       
      uint64_t fld, val = 0xa100000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MOVMSK: {
       
      uint64_t fld, val = 0x260cc00000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = util_last_bit(src->regs[0]->wrmask) - 1;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MOV_CONST: {
       
      uint64_t fld, val = 0x2020000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_4(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_const_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 10, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 244);
       
    }


       
    {

      val |= pack_field(50, 52, 4);
       
    }


       
    {

      val |= pack_field(46, 48, 4);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(32, 39, 245);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(50, 52, 2);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_5(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_const_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 10, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 245);
       
    }


       
    {

      val |= pack_field(50, 52, 2);
       
    }


       
    {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_6(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_const_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 10, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_const_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 10, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_END: {
       
      uint64_t fld, val = 0x300000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_MAX: {
       
      uint64_t fld, val = 0xc5c0000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MOV_GPR: {
       
      uint64_t fld, val = 0x2000000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_4(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_gpr_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 244);
       
    }


       
    {

      val |= pack_field(50, 52, 4);
       
    }


       
    {

      val |= pack_field(46, 48, 4);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(32, 39, 245);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(50, 52, 2);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_5(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_gpr_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 245);
       
    }


       
    {

      val |= pack_field(50, 52, 2);
       
    }


       
    {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_6(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_gpr_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_gpr_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_MIN: {
       
      uint64_t fld, val = 0xc580000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CMPV_F: {
       
      uint64_t fld, val = 0x40e0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAX_F: {
       
      uint64_t fld, val = 0x4040000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SEL_S32: {
       
      uint64_t fld, val = 0x6580000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ABSNEG_S: {
       
      uint64_t fld, val = 0x4340000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_LDL: {
       
      uint64_t fld, val = 0xc040000000800001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(14, 21, fld);  /* SRC */
           
    }


           
    {

             fld = src->regs[2]->uim_val;
          val |= pack_field(1, 13, fld);  /* OFF */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MAD_S16: {
       
      uint64_t fld, val = 0x6100000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_PREDT: {
       
      uint64_t fld, val = 0x682000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.inv1;
          val |= pack_field(52, 52, fld);  /* INV1 */
           
    }


           
    {

             fld = src->cat0.comp1;
          val |= pack_field(53, 54, fld);  /* COMP1 */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_LDGB: {
       
      uint64_t fld, val = 0xc6c0000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[2]->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[2]); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[3]->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[3]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_MAX: {
       
      uint64_t fld, val = 0xc03000000065c001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RSQ: {
       
      uint64_t fld, val = 0x8020000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CBITS_B: {
       
      uint64_t fld, val = 0x47a0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CHMASK: {
       
      uint64_t fld, val = 0x480000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ADD_S: {
       
      uint64_t fld, val = 0x4220000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RGETINFO: {
       
      uint64_t fld, val = 0xa6c0000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___zero(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BR: {
       
      uint64_t fld, val = 0x80000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.inv1;
          val |= pack_field(52, 52, fld);  /* INV1 */
           
    }


           
    {

             fld = src->cat0.comp1;
          val |= pack_field(53, 54, fld);  /* COMP1 */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETBIT_B: {
       
      uint64_t fld, val = 0x4760000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SEL_F32: {
       
      uint64_t fld, val = 0x6680000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BRAC: {
       
      uint64_t fld, val = 0x80006000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.idx;
          val |= pack_field(32, 36, fld);  /* INDEX */
           
    }


           
    {

             fld = src->cat0.immed;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETSPID: {
       
      uint64_t fld, val = 0xc020000000490000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RNDNE_F: {
       
      uint64_t fld, val = 0x4160000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_XOR_B: {
       
      uint64_t fld, val = 0x43e0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ISAM: {
       
      uint64_t fld, val = 0xa000000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAMGQ: {
       
      uint64_t fld, val = 0xa180000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SEL_F16: {
       
      uint64_t fld, val = 0x6600000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SEL_B16: {
       
      uint64_t fld, val = 0x6400000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_DSY: {
       
      uint64_t fld, val = 0xa3c0000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SEL_B32: {
       
      uint64_t fld, val = 0x6480000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_DSXPP_1: {
       
      uint64_t fld, val = 0xa600000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___false(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___false(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___false(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GETPOS: {
       
      uint64_t fld, val = 0xa300000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___false(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_CMPXCHG: {
       
      uint64_t fld, val = 0xc030000000654001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MOV_RELGPR: {
       
      uint64_t fld, val = 0x2000000000000800;
      (void)fld;


    
    if (__instruction_expr_anon_4(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_relative_gpr_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 244);
       
    }


       
    {

      val |= pack_field(50, 52, 4);
       
    }


       
    {

      val |= pack_field(46, 48, 4);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(32, 39, 245);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(50, 52, 2);
       
    }


       
    if (__instruction_expr_anon_5(s, p, src)) {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_5(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_relative_gpr_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }



       
    {

      val |= pack_field(32, 39, 245);
       
    }


       
    {

      val |= pack_field(50, 52, 2);
       
    }


       
    {

      val |= pack_field(46, 48, 2);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__instruction_expr_anon_6(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_relative_gpr_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat1.src_type;
          val |= pack_field(50, 52, fld);  /* SRC_TYPE */
           
    }


           
    {

             fld = src->cat1.dst_type;
          val |= pack_field(46, 48, fld);  /* DST_TYPE */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EVEN);
          val |= pack_field(55, 55, fld);  /* EVEN */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_POS_INF);
          val |= pack_field(56, 56, fld);  /* POS_INF */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .DST_REL = !!(src->regs[0]->flags & IR3_REG_RELATIV),  /* DST_REL */
 };

             fld = encode__cat1_dst(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .HALF = __instruction_expr_anon_2(s, p, src),  /* HALF */
 };

             fld = encode__cat1_relative_gpr_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_RELATIV);
          val |= pack_field(49, 49, fld);  /* DST_REL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RET: {
       
      uint64_t fld, val = 0x200000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 42, fld);  /* REPEAT */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SEL_S16: {
       
      uint64_t fld, val = 0x6500000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(14, 14, fld);  /* SRC1_NEG */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[1]); }
          val |= pack_field(0, 12, fld);  /* SRC1 */
           
    }


           
    {

             fld = !!(src->regs[2]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(30, 30, fld);  /* SRC2_NEG */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(15, 15, fld);  /* SRC2_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(47, 54, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & (IR3_REG_FNEG | IR3_REG_SNEG | IR3_REG_BNOT));
          val |= pack_field(31, 31, fld);  /* SRC3_NEG */
           
    }


           
    {

             fld = !!(src->regs[3]->flags & IR3_REG_R);
          val |= pack_field(29, 29, fld);  /* SRC3_R */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat3_src(s, &bp, src->regs[3]); }
          val |= pack_field(16, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_XOR: {
       
      uint64_t fld, val = 0xc030000000668001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MIN_F: {
       
      uint64_t fld, val = 0x4020000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CMPV_S: {
       
      uint64_t fld, val = 0x4440000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_B_AND: {
       
      uint64_t fld, val = 0xc030000000660001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAMGP3: {
       
      uint64_t fld, val = 0xa5c0000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_MULL_U: {
       
      uint64_t fld, val = 0x4640000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAML: {
       
      uint64_t fld, val = 0xa140000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___two(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_LDP: {
       
      uint64_t fld, val = 0xc080000000800001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(14, 21, fld);  /* SRC */
           
    }


           
    {

             fld = src->regs[2]->uim_val;
          val |= pack_field(1, 13, fld);  /* OFF */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_STIB_B: {
       
      uint64_t fld, val = 0xc020000000674000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             fld = extract_cat6_DESC_MODE(src);
          val |= pack_field(6, 7, fld);  /* MODE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = !!(src->flags & IR3_INSTR_B),  /* BINDLESS */
 };

             fld = encode__cat6_base(s, &bp, src); }
          val |= pack_field(1, 3, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[3]); }
          val |= pack_field(32, 39, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[2]); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = __instruction_expr___cat6_direct(s, p, src),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_B);
          val |= pack_field(8, 8, fld);  /* BINDLESS */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ATOMIC_SUB: {
       
      uint64_t fld, val = 0xc440000000000001;
      (void)fld;


    
    if (__instruction_expr___cat6_global(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(src->regs[1]->flags & IR3_REG_IMMED),  /* SSBO_IM */
 };

             fld = encode__cat6_src(s, &bp, src->regs[1]); }
          val |= pack_field(41, 48, fld);  /* SSBO */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, extract_cat6_SRC(src, 3)); }
          val |= pack_field(1, 8, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_IMMED);
          val |= pack_field(53, 53, fld);  /* SSBO_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat6_typed(s, &bp, src); }
          val |= pack_field(11, 11, fld);  /* TYPED */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED),  /* SRC1_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 1)); }
          val |= pack_field(14, 21, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_IM = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED),  /* SRC2_IM */
 };

             fld = encode__cat6_src(s, &bp, extract_cat6_SRC(src, 2)); }
          val |= pack_field(24, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_G);
          val |= pack_field(52, 52, fld);  /* G */
           
    }


           
    {

             fld = src->cat6.d - 1;
          val |= pack_field(9, 10, fld);  /* D_MINUS_ONE */
           
    }


           
    {

             fld = src->cat6.iim_val - 1;
          val |= pack_field(12, 13, fld);  /* TYPE_SIZE_MINUS_ONE */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 1)->flags & IR3_REG_IMMED);
          val |= pack_field(22, 22, fld);  /* SRC1_IM */
           
    }


           
    {

             fld = !!(extract_cat6_SRC(src, 2)->flags & IR3_REG_IMMED);
          val |= pack_field(23, 23, fld);  /* SRC2_IM */
           
    }



       
    {

      val |= pack_field(53, 53, 0);
       
    }


       
    {

      val |= pack_field(41, 48, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_SAMGP1: {
       
      uint64_t fld, val = 0xa540000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_LDLW: {
       
      uint64_t fld, val = 0xc280000000800001;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat6.type;
          val |= pack_field(49, 51, fld);  /* TYPE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[1]); }
          val |= pack_field(14, 21, fld);  /* SRC */
           
    }


           
    {

             fld = src->regs[2]->uim_val;
          val |= pack_field(1, 13, fld);  /* OFF */
           
    }


           
    {

             fld = src->regs[3]->uim_val;
          val |= pack_field(24, 31, fld);  /* SIZE */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GATHER4G: {
       
      uint64_t fld, val = 0xa440000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_ABSNEG_F: {
       
      uint64_t fld, val = 0x40c0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_KILL: {
       
      uint64_t fld, val = 0x280000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.inv1;
          val |= pack_field(52, 52, fld);  /* INV1 */
           
    }


           
    {

             fld = src->cat0.comp1;
          val |= pack_field(53, 54, fld);  /* COMP1 */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_PREDF: {
       
      uint64_t fld, val = 0x702000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = 0;
          val |= pack_field(48, 48, fld);  /* EQ */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = src->cat0.inv1;
          val |= pack_field(52, 52, fld);  /* INV1 */
           
    }


           
    {

             fld = src->cat0.comp1;
          val |= pack_field(53, 54, fld);  /* COMP1 */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_RCP: {
       
      uint64_t fld, val = 0x8000000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_CMPS_S: {
       
      uint64_t fld, val = 0x42a0000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = src->cat2.condition;
          val |= pack_field(48, 50, fld);  /* COND */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC2_R(src),  /* SRC2_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[2]); }
          val |= pack_field(16, 31, fld);  /* SRC2 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_HRSQ: {
       
      uint64_t fld, val = 0x8120000000000000;
      (void)fld;


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = !!(src->regs[1]->flags & IR3_REG_R),  /* SRC_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


           
    {

             fld = !!(src->regs[1]->flags & IR3_REG_R);
          val |= pack_field(43, 43, fld);  /* SRC_R */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_BFREV_B: {
       
      uint64_t fld, val = 0x4660000000000000;
      (void)fld;


    
    if (__instruction_expr___cat2_cat3_nop_encoding(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = __instruction_expr___zero(s, p, src),  /* ZERO */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SS);
          val |= pack_field(44, 44, fld);  /* SS */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_SAT);
          val |= pack_field(42, 42, fld);  /* SAT */
           
    }


           
    {

             fld = src->repeat;
          val |= pack_field(40, 41, fld);  /* REPEAT */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_UL);
          val |= pack_field(45, 45, fld);  /* UL */
           
    }


           
    {

             fld = !!(src->regs[0]->flags & IR3_REG_EI);
          val |= pack_field(47, 47, fld);  /* EI */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .SRC_R = extract_SRC1_R(src),  /* SRC1_R */
    .FULL = !(src->regs[1]->flags & IR3_REG_HALF),  /* FULL */
 };

             fld = encode__multisrc(s, &bp, src->regs[1]); }
          val |= pack_field(0, 15, fld);  /* SRC1 */
           
    }


           
    {

             fld = extract_SRC2_R(src);
          val |= pack_field(51, 51, fld);  /* SRC2_R */
           
    }


           
    {

             fld = extract_SRC1_R(src);
          val |= pack_field(43, 43, fld);  /* SRC1_R */
           
    }


           
    {

             fld = ((src->regs[0]->num >> 2) == 62) ? 0 :
			!!((src->regs[1]->flags ^ src->regs[0]->flags) & IR3_REG_HALF);
          val |= pack_field(46, 46, fld);  /* DST_CONV */
           
    }


           
    {

             fld = !(src->regs[1]->flags & IR3_REG_HALF);
          val |= pack_field(52, 52, fld);  /* FULL */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case OPC_GATHER4B: {
       
      uint64_t fld, val = 0xa480000000000000;
      (void)fld;


    
    if (__instruction_expr_anon_16(s, p, src)) {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .BASE_HI = src->cat5.tex_base >> 1,  /* BASE_HI */
 };

             fld = encode__cat5_s2en_bindless_base(s, &bp, src); }
          val |= pack_field(47, 47, fld);  /* BASE */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .BINDLESS = __instruction_expr___cat5_s2enb_is_bindless(s, p, src),  /* BINDLESS */
    .DESC_MODE = extract_cat5_DESC_MODE(src),  /* DESC_MODE */
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_src3(s, &bp, src->regs[1]); }
          val |= pack_field(21, 28, fld);  /* SRC3 */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_DESC_MODE(src);
          val |= pack_field(29, 31, fld);  /* DESC_MODE */
           
    }


           
    {

             fld = src->cat5.tex_base >> 1;
          val |= pack_field(19, 20, fld);  /* BASE_HI */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = !!(src->flags & IR3_INSTR_SY);
          val |= pack_field(60, 60, fld);  /* SY */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_JP);
          val |= pack_field(59, 59, fld);  /* JP */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_3D);
          val |= pack_field(48, 48, fld);  /* 3D */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_A);
          val |= pack_field(49, 49, fld);  /* A */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_O);
          val |= pack_field(52, 52, fld);  /* O */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_P);
          val |= pack_field(53, 53, fld);  /* P */
           
    }


           
    {

             fld = !!(src->flags & IR3_INSTR_S);
          val |= pack_field(50, 50, fld);  /* S */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TYPE = __instruction_expr___true(s, p, src),  /* HAS_TYPE */
 };

             fld = encode__cat5_type(s, &bp, src); }
          val |= pack_field(44, 46, fld);  /* TYPE */
           
    }


           
    {

             fld = src->regs[0]->wrmask;
          val |= pack_field(40, 43, fld);  /* WRMASK */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src->regs[0]); }
          val |= pack_field(32, 39, fld);  /* DST */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
 };

             fld = encode__cat5_src1(s, &bp, extract_cat5_SRC(src, 1)); }
          val |= pack_field(1, 8, fld);  /* SRC1 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .NUM_SRC = __instruction_expr___one(s, p, src),  /* NUM_SRC */
    .HALF = __instruction_expr___multisrc_half(s, p, src),  /* HALF */
    .O = !!(src->flags & IR3_INSTR_O),  /* O */
 };

             fld = encode__cat5_src2(s, &bp, extract_cat5_SRC(src, 2)); }
          val |= pack_field(9, 16, fld);  /* SRC2 */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = __instruction_expr___true(s, p, src),  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, src); }
          val |= pack_field(21, 24, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = __instruction_expr___true(s, p, src),  /* HAS_TEX */
 };

             fld = encode__cat5_tex(s, &bp, src); }
          val |= pack_field(25, 31, fld);  /* TEX */
           
    }


           
    {

             fld = !!(src->flags & (IR3_INSTR_S2EN | IR3_INSTR_B));
          val |= pack_field(51, 51, fld);  /* S2EN_BINDLESS */
           
    }


           
    {

             fld = extract_cat5_FULL(src);
          val |= pack_field(0, 0, fld);  /* FULL */
           
    }



       
    {

      val |= pack_field(19, 20, 0);
       
    }


       
    {

      val |= pack_field(47, 47, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   default:
      /* Note that we need the default case, because there are
       * instructions which we never expect to be encoded, (ie.
       * meta/macro instructions) as they are removed/replace
       * in earlier stages of the compiler.
       */
      break;
   }
   mesa_loge("Unhandled #instruction encode case: 0x%x\n", __instruction_case(s, src));
   return 0;
}


static uint64_t
encode__multisrc(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
   switch (__multisrc_case(s, src)) {
   case REG_MULTISRC_IMMED_FLUT_FULL: {
       
      uint64_t fld, val = 0x2800;
      (void)fld;


    
    {


           
    {

             fld = extract_ABSNEG(src);
          val |= pack_field(14, 15, fld);  /* ABSNEG */
           
    }


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 9, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_MULTISRC_RELATIVE_GPR: {
       
      uint64_t fld, val = 0x800;
      (void)fld;


    
    {


           
    {

             fld = extract_ABSNEG(src);
          val |= pack_field(14, 15, fld);  /* ABSNEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_relative_gpr(s, &bp, src); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_MULTISRC_GPR: {
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    {


           
    {

             fld = extract_ABSNEG(src);
          val |= pack_field(14, 15, fld);  /* ABSNEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_MULTISRC_IMMED_FLUT_HALF: {
       
      uint64_t fld, val = 0x2c00;
      (void)fld;


    
    {


           
    {

             fld = extract_ABSNEG(src);
          val |= pack_field(14, 15, fld);  /* ABSNEG */
           
    }


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 9, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_MULTISRC_CONST: {
       
      uint64_t fld, val = 0x1000;
      (void)fld;


    
    {


           
    {

             fld = extract_ABSNEG(src);
          val |= pack_field(14, 15, fld);  /* ABSNEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_const(s, &bp, src); }
          val |= pack_field(0, 10, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_MULITSRC_IMMED: {
       
      uint64_t fld, val = 0x2000;
      (void)fld;


    
    if (__multisrc_expr___multisrc_half(s, p, src)) {


           
    {

             fld = extract_ABSNEG(src);
          val |= pack_field(14, 15, fld);  /* ABSNEG */
           
    }


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 10, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = extract_ABSNEG(src);
          val |= pack_field(14, 15, fld);  /* ABSNEG */
           
    }


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 10, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_MULTISRC_RELATIVE_CONST: {
       
      uint64_t fld, val = 0xc00;
      (void)fld;


    
    {


           
    {

             fld = extract_ABSNEG(src);
          val |= pack_field(14, 15, fld);  /* ABSNEG */
           
    }


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_relative_const(s, &bp, src); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   default:
      /* Note that we need the default case, because there are
       * instructions which we never expect to be encoded, (ie.
       * meta/macro instructions) as they are removed/replace
       * in earlier stages of the compiler.
       */
      break;
   }
   mesa_loge("Unhandled #multisrc encode case: 0x%x\n", __multisrc_case(s, src));
   return 0;
}


static uint64_t
encode__cat5_src3(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_src3_expr___cat5_s2enb_is_indirect(s, p, src)) {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__cat5_src3_expr___cat5_s2enb_uses_a1(s, p, src)) {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__cat5_samp_s2en_bindless_a1(s, &bp, s->instr); }
          val |= pack_field(0, 7, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = p->HAS_SAMP,  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, s->instr); }
          val |= pack_field(0, 3, fld);  /* SAMP */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             { 
 struct bitset_params bp = {
    .HAS_SAMP = p->HAS_SAMP,  /* HAS_SAMP */
 };

             fld = encode__cat5_samp(s, &bp, s->instr); }
          val |= pack_field(0, 3, fld);  /* SAMP */
           
    }


           
    {

             { 
 struct bitset_params bp = {
    .HAS_TEX = p->HAS_TEX,  /* HAS_TEX */
 };

             fld = encode__cat5_tex_s2en_bindless(s, &bp, s->instr); }
          val |= pack_field(4, 7, fld);  /* TEX */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat1_const_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_const(s, &bp, src); }
          val |= pack_field(0, 10, fld);  /* CONST */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat5_s2en_bindless_base(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_s2en_bindless_base_expr_anon_14(s, p, src)) {


           
    {

             fld = src->cat5.tex_base & 0x1;
          val |= pack_field(0, 0, fld);  /* BASE_LO */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__reg_relative_const(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__reg_relative_const_expr___offset_zero(s, p, src)) {


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = src->array.offset;
          val |= pack_field(0, 9, fld);  /* OFFSET */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat6_base(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat6_base_expr_anon_31(s, p, src)) {


           
    {

             fld = src->cat6.base;
          val |= pack_field(0, 2, fld);  /* BASE */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat1_gpr_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat5_samp(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_samp_expr_anon_19(s, p, src)) {


           
    {

             fld = src->cat5.samp;
          val |= pack_field(0, 3, fld);  /* SAMP */
           
    }



       
    {

      val |= pack_field(0, 3, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {



       
    {

      val |= pack_field(0, 3, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat1_dst(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat1_dst_expr_anon_0(s, p, src)) {


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__cat1_dst_expr_anon_1(s, p, src)) {


           
    {

             fld = src->array.offset;
          val |= pack_field(0, 7, fld);  /* OFFSET */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src); }
          val |= pack_field(0, 7, fld);  /* DST */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat6_typed(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat6_typed_expr_anon_30(s, p, src)) {


           
    {

             fld = src->cat6.typed;
          val |= pack_field(0, 0, fld);  /* TYPED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = src->cat6.typed;
          val |= pack_field(0, 0, fld);  /* TYPED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat1_relative_gpr_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_relative_gpr(s, &bp, src); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat1_relative_const_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_relative_const(s, &bp, src); }
          val |= pack_field(0, 9, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat5_src1(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_src1_expr_anon_17(s, p, src)) {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }



       
    {

      val |= pack_field(0, 7, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {



       
    {

      val |= pack_field(0, 7, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat5_samp_s2en_bindless_a1(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_samp_s2en_bindless_a1_expr_anon_20(s, p, src)) {


           
    {

             fld = src->cat5.samp;
          val |= pack_field(0, 8, fld);  /* SAMP */
           
    }



       
    {

      val |= pack_field(0, 7, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {



       
    {

      val |= pack_field(0, 7, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat1_immed_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat1_immed_src_expr_anon_7(s, p, src)) {


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 15, fld);  /* IMMED */
           
    }


           
    if (__cat1_immed_src_expr_anon_8(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    } else


           
    if (__cat1_immed_src_expr_anon_9(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    } else


           
    if (__cat1_immed_src_expr_anon_10(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 15, fld);  /* IMMED */
           
    } else


           
    if (__cat1_immed_src_expr_anon_11(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    } else


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__cat1_immed_src_expr_anon_8(s, p, src)) {


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


           
    if (__cat1_immed_src_expr_anon_9(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    } else


           
    if (__cat1_immed_src_expr_anon_10(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 15, fld);  /* IMMED */
           
    } else


           
    if (__cat1_immed_src_expr_anon_11(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    } else


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__cat1_immed_src_expr_anon_9(s, p, src)) {


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


           
    if (__cat1_immed_src_expr_anon_10(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 15, fld);  /* IMMED */
           
    } else


           
    if (__cat1_immed_src_expr_anon_11(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    } else


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    if (__cat1_immed_src_expr_anon_10(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 15, fld);  /* IMMED */
           
    } else


           
    if (__cat1_immed_src_expr_anon_11(s, p, src)) {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    } else


           
    {

             fld = src->uim_val;
          val |= pack_field(0, 31, fld);  /* IMMED */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__reg_const(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    {


           
    {

             fld = src->num >> 2;
          val |= pack_field(2, 10, fld);  /* CONST */
           
    }


           
    {

             fld = src->num & 0x3;
          val |= pack_field(0, 1, fld);  /* SWIZ */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__reg_gpr(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__reg_gpr_expr___reg_gpr_a0(s, p, src)) {


           
    {

             fld = src->num & 0x3;
          val |= pack_field(0, 1, fld);  /* SWIZ */
           
    }


           
    {

             fld = src->num >> 2;
          val |= pack_field(2, 7, fld);  /* GPR */
           
    }



       
    {

      val |= pack_field(2, 7, 61);
       
    }


       
    if (__reg_gpr_expr___reg_gpr_p0(s, p, src)) {

      val |= pack_field(2, 7, 62);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    if (__reg_gpr_expr___reg_gpr_p0(s, p, src)) {


           
    {

             fld = src->num & 0x3;
          val |= pack_field(0, 1, fld);  /* SWIZ */
           
    }


           
    {

             fld = src->num >> 2;
          val |= pack_field(2, 7, fld);  /* GPR */
           
    }



       
    {

      val |= pack_field(2, 7, 62);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = src->num >> 2;
          val |= pack_field(2, 7, fld);  /* GPR */
           
    }


           
    {

             fld = src->num & 0x3;
          val |= pack_field(0, 1, fld);  /* SWIZ */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat5_tex(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_tex_expr_anon_21(s, p, src)) {


           
    {

             fld = src->cat5.tex;
          val |= pack_field(0, 6, fld);  /* TEX */
           
    }



       
    {

      val |= pack_field(0, 6, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {



       
    {

      val |= pack_field(0, 6, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat3_src(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
   switch (__cat3_src_case(s, src)) {
   case REG_CAT3_SRC_RELATIVE_GPR: {
       
      uint64_t fld, val = 0x800;
      (void)fld;


    
    {


           
    {

             fld = src->array.offset;
          val |= pack_field(0, 9, fld);  /* OFFSET */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_CAT3_SRC_GPR: {
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    {


           
    {

             { 
 struct bitset_params bp = {
 };

             fld = encode__reg_gpr(s, &bp, src); }
          val |= pack_field(0, 7, fld);  /* SRC */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_CAT3_SRC_RELATIVE_CONST: {
       
      uint64_t fld, val = 0xc00;
      (void)fld;


    
    {


           
    {

             fld = src->array.offset;
          val |= pack_field(0, 9, fld);  /* OFFSET */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   case REG_CAT3_SRC_CONST: {
       
      uint64_t fld, val = 0x1000;
      (void)fld;


    
    {


           
    {

             fld = src->num >> 2;
          val |= pack_field(2, 10, fld);  /* CONST */
           
    }


           
    {

             fld = src->num & 0x3;
          val |= pack_field(0, 1, fld);  /* SWIZ */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

    }
   default:
      /* Note that we need the default case, because there are
       * instructions which we never expect to be encoded, (ie.
       * meta/macro instructions) as they are removed/replace
       * in earlier stages of the compiler.
       */
      break;
   }
   mesa_loge("Unhandled #cat3-src encode case: 0x%x\n", __cat3_src_case(s, src));
   return 0;
}


static uint64_t
encode__reg_relative_gpr(struct encode_state *s, struct bitset_params *p, struct ir3_register * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__reg_relative_gpr_expr___offset_zero(s, p, src)) {


      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {


           
    {

             fld = src->array.offset;
          val |= pack_field(0, 9, fld);  /* OFFSET */
           
    }


      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


static uint64_t
encode__cat5_tex_s2en_bindless(struct encode_state *s, struct bitset_params *p, struct ir3_instruction * src)
{
       
      uint64_t fld, val = 0x0;
      (void)fld;


    
    if (__cat5_tex_s2en_bindless_expr_anon_22(s, p, src)) {


           
    {

             fld = src->cat5.samp >> 4;
          val |= pack_field(0, 3, fld);  /* TEX */
           
    }



       
    {

      val |= pack_field(0, 3, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    } else


    
    {



       
    {

      val |= pack_field(0, 3, 0);
       
    }

      {}  /* in case no unconditional field to close out last '} else' */
    
    }

      return val;

}


