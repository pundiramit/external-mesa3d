mkdir -p prebuilt-intermediates/{glsl,ir3,main,nir,spirv,cle,isl,perf,genxml,compiler,lima,midgard,iris,util,virgl,vulkan,bifrost,isa}

python src/compiler/glsl/ir_expression_operation.py strings > prebuilt-intermediates/glsl/ir_expression_operation_strings.h 
python src/compiler/glsl/ir_expression_operation.py constant > prebuilt-intermediates/glsl/ir_expression_operation_constant.h
python src/compiler/glsl/ir_expression_operation.py enum > prebuilt-intermediates/glsl/ir_expression_operation.h

python3 src/freedreno/ir3/ir3_nir_trig.py -p src/compiler/nir > prebuilt-intermediates/ir3/ir3_nir_trig.c
python3 src/freedreno/ir3/ir3_nir_imul.py -p src/compiler/nir > prebuilt-intermediates/ir3/ir3_nir_imul.c
python3 src/freedreno/isa/decode.py src/freedreno/isa/ir3.xml prebuilt-intermediates/isa/ir3-isa.c
python3 src/freedreno/isa/encode.py src/freedreno/isa/ir3.xml prebuilt-intermediates/isa/encode.h

python src/mesa/main/format_pack.py  src/mesa/main/formats.csv  > prebuilt-intermediates/main/format_pack.c
python src/mesa/main/format_fallback.py  src/mesa/main/formats.csv /dev/stdout  > prebuilt-intermediates/main/format_fallback.c

python src/compiler/nir/nir_builder_opcodes_h.py src/compiler/nir/nir_opcodes.py > prebuilt-intermediates/nir/nir_builder_opcodes.h
python src/compiler/nir/nir_constant_expressions.py src/compiler/nir/nir_opcodes.py > prebuilt-intermediates/nir/nir_constant_expressions.c
python src/compiler/nir/nir_opcodes_c.py src/compiler/nir/nir_opcodes.py > prebuilt-intermediates/nir/nir_opcodes.c
python src/compiler/nir/nir_opcodes_h.py src/compiler/nir/nir_opcodes.py > prebuilt-intermediates/nir/nir_opcodes.h
python src/compiler/nir/nir_opt_algebraic.py src/compiler/nir/nir_opt_algebraic.py > prebuilt-intermediates/nir/nir_opt_algebraic.c
python src/compiler/nir/nir_intrinsics_c.py --outdir prebuilt-intermediates/nir/ || ( prebuilt-intermediates/nir/nir_intrinsics.c; false)
python src/compiler/nir/nir_intrinsics_h.py --outdir prebuilt-intermediates/nir/ || ( prebuilt-intermediates/nir/nir_intrinsics.h; false)
python src/compiler/nir/nir_intrinsics_indices_h.py --outdir prebuilt-intermediates/nir/ || ( prebuilt-intermediates/nir/nir_intrinsics_indices.h; false)

python src/compiler/spirv/spirv_info_c.py src/compiler/spirv/spirv.core.grammar.json prebuilt-intermediates/spirv/spirv_info.c || ( prebuilt-intermediates/spirv/spirv_info.c; false)
python src/compiler/spirv/vtn_gather_types_c.py src/compiler/spirv/spirv.core.grammar.json prebuilt-intermediates/spirv/vtn_gather_types.c || ( prebuilt-intermediates/spirv/vtn_gather_types.c; false)
python src/compiler/spirv/vtn_generator_ids_h.py src/compiler/spirv/spir-v.xml prebuilt-intermediates/spirv/vtn_generator_ids.h

python src/util/format_srgb.py > prebuilt-intermediates/util/format_srgb.c

python src/intel/genxml/gen_zipped_file.py src/broadcom/cle/v3d_packet_v21.xml src/broadcom/cle/v3d_packet_v33.xml > prebuilt-intermediates/cle/v3d_xml.h

python src/broadcom/cle/gen_pack_header.py src/broadcom/cle/v3d_packet_v21.xml 21 > prebuilt-intermediates/cle/v3d_packet_v21_pack.h
python src/broadcom/cle/gen_pack_header.py src/broadcom/cle/v3d_packet_v33.xml 33 > prebuilt-intermediates/cle/v3d_packet_v33_pack.h


python src/intel/isl/gen_format_layout.py --csv src/intel/isl/isl_format_layout.csv --out prebuilt-intermediates/isl/isl_format_layout.c

python src/intel/genxml/gen_bits_header.py --cpp-guard=GENX_BITS_H  \
		src/intel/genxml/gen4.xml \
		src/intel/genxml/gen45.xml \
		src/intel/genxml/gen5.xml \
		src/intel/genxml/gen6.xml \
		src/intel/genxml/gen7.xml \
		src/intel/genxml/gen75.xml \
		src/intel/genxml/gen8.xml \
		src/intel/genxml/gen9.xml \
		src/intel/genxml/gen11.xml \
		src/intel/genxml/gen12.xml \
		src/intel/genxml/gen125.xml \
						> prebuilt-intermediates/genxml/genX_bits.h

python src/intel/genxml/gen_zipped_file.py \
		src/intel/genxml/gen4.xml \
		src/intel/genxml/gen45.xml \
		src/intel/genxml/gen5.xml \
		src/intel/genxml/gen6.xml \
		src/intel/genxml/gen7.xml \
		src/intel/genxml/gen75.xml \
		src/intel/genxml/gen8.xml \
		src/intel/genxml/gen9.xml \
		src/intel/genxml/gen11.xml \
		src/intel/genxml/gen12.xml \
		src/intel/genxml/gen125.xml \
						> prebuilt-intermediates/genxml/genX_xml.h


python  src/vulkan/util/vk_entrypoints_gen.py --xml src/vulkan/registry/vk.xml \
	--proto --weak --prefix anv --device-prefix gen7 --device-prefix gen75 --device-prefix gen8 \
	--device-prefix gen9 --device-prefix gen11 --device-prefix gen12 --device-prefix gen125 \
	--out-c prebuilt-intermediates/vulkan/anv_entrypoints.c --out-h prebuilt-intermediates/vulkan/anv_entrypoints.h
python  src/vulkan/util/gen_enum_to_str.py  --xml src/vulkan/registry/vk.xml   --outdir prebuilt-intermediates/util/
python src/vulkan/util/vk_entrypoints_gen.py --xml src/vulkan/registry/vk.xml \
	--proto --weak --prefix vk_common --out-c prebuilt-intermediates/util/vk_common_entrypoints.c \
	--out-h prebuilt-intermediates/util//vk_common_entrypoints.h
python src/vulkan/util/vk_dispatch_table_gen.py --xml src/vulkan/registry/vk.xml\
	--out-c prebuilt-intermediates/util/vk_dispatch_table.c
python src/vulkan/util/vk_dispatch_table_gen.py --xml src/vulkan/registry/vk.xml \
	--out-h prebuilt-intermediates/util/vk_dispatch_table.h
python src/vulkan/util/vk_extensions_gen.py --xml src/vulkan/registry/vk.xml --out-c prebuilt-intermediates/util/vk_extensions.c
python src/vulkan/util/vk_extensions_gen.py --xml src/vulkan/registry/vk.xml --out-h prebuilt-intermediates/util/vk_extensions.h


python3 src/gallium/auxiliary/util/u_tracepoints.py -p src/gallium/auxiliary/util -C prebuilt-intermediates/util/u_tracepoints.c -H prebuilt-intermediates/util/u_tracepoints.h
python3 src/gallium/drivers/freedreno/freedreno_tracepoints.py -p src/gallium/auxiliary/util -C prebuilt-intermediates/freedreno_tracepoints.c -H prebuilt-intermediates/freedreno_tracepoints.h
python src/gallium/drivers/lima/ir/lima_nir_algebraic.py -p src/compiler/nir/ > prebuilt-intermediates/lima/lima_nir_algebraic.c
python src/panfrost/midgard/midgard_nir_algebraic.py -p src/compiler/nir/ > prebuilt-intermediates/midgard/midgard_nir_algebraic.c
python3 src/panfrost/bifrost/gen_disasm.py src/panfrost/bifrost/ISA.xml > prebuilt-intermediates/bifrost/bifrost_gen_disasm.c
python3 src/panfrost/bifrost/bifrost_nir_algebraic.py -p src/compiler/nir/ > prebuilt-intermediates/bifrost/bifrost_nir_algebraic.c
python3 src/panfrost/bifrost/bi_builder.h.py src/panfrost/bifrost/ISA.xml > prebuilt-intermediates/bifrost/bi_builder.h
python3 src/panfrost/bifrost/bi_opcodes.c.py src/panfrost/bifrost/ISA.xml > prebuilt-intermediates/bifrost/bi_opcodes.c
python3 src/panfrost/bifrost/bi_opcodes.h.py src/panfrost/bifrost/ISA.xml > prebuilt-intermediates/bifrost/bi_opcodes.h
python3 src/panfrost/bifrost/bi_packer.c.py src/panfrost/bifrost/ISA.xml > prebuilt-intermediates/bifrost/bi_packer.c
python3 src/panfrost/bifrost/bi_printer.c.py src/panfrost/bifrost/ISA.xml > prebuilt-intermediates/bifrost/bi_printer.c


python src/intel/compiler/brw_nir_trig_workarounds.py -p src/compiler/nir > prebuilt-intermediates/compiler/brw_nir_trig_workarounds.c

python src/intel/perf/gen_perf.py  --code=prebuilt-intermediates/perf/gen_perf_metrics.c   --header=prebuilt-intermediates/perf/gen_perf_metrics.h \
		src/intel/perf/oa-hsw.xml \
		src/intel/perf/oa-bdw.xml \
		src/intel/perf/oa-chv.xml \
		src/intel/perf/oa-sklgt2.xml \
		src/intel/perf/oa-sklgt3.xml \
		src/intel/perf/oa-sklgt4.xml \
		src/intel/perf/oa-bxt.xml \
		src/intel/perf/oa-kblgt2.xml \
		src/intel/perf/oa-kblgt3.xml \
		src/intel/perf/oa-glk.xml \
		src/intel/perf/oa-cflgt2.xml \
		src/intel/perf/oa-cflgt3.xml \
		src/intel/perf/oa-icl.xml \
		src/intel/perf/oa-ehl.xml \
		src/intel/perf/oa-tglgt1.xml \
		src/intel/perf/oa-tglgt2.xml \
		src/intel/perf/oa-rkl.xml \
		src/intel/perf/oa-dg1.xml \
		src/intel/perf/oa-adl.xml
