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

#include "util/u_dump.h"
#include "freedreno_batch.h"

#include "freedreno_tracepoints.h"

#define __NEEDS_TRACE_PRIV
#include "util/u_trace_priv.h"

/*
 * start_state_restore
 */
struct __payload_start_state_restore {
};
#define __print_start_state_restore NULL
static const struct u_tracepoint __tp_start_state_restore = {
    ALIGN_POT(sizeof(struct __payload_start_state_restore), 8),   /* keep size 64b aligned */
    "start_state_restore",
    __print_start_state_restore,
};
void __trace_start_state_restore(struct u_trace *ut
) {
   struct __payload_start_state_restore *__entry =
      (struct __payload_start_state_restore *)u_trace_append(ut, &__tp_start_state_restore);
   (void)__entry;
}

/*
 * end_blit
 */
struct __payload_end_blit {
};
#define __print_end_blit NULL
static const struct u_tracepoint __tp_end_blit = {
    ALIGN_POT(sizeof(struct __payload_end_blit), 8),   /* keep size 64b aligned */
    "end_blit",
    __print_end_blit,
};
void __trace_end_blit(struct u_trace *ut
) {
   struct __payload_end_blit *__entry =
      (struct __payload_end_blit *)u_trace_append(ut, &__tp_end_blit);
   (void)__entry;
}

/*
 * end_clear_restore
 */
struct __payload_end_clear_restore {
};
#define __print_end_clear_restore NULL
static const struct u_tracepoint __tp_end_clear_restore = {
    ALIGN_POT(sizeof(struct __payload_end_clear_restore), 8),   /* keep size 64b aligned */
    "end_clear_restore",
    __print_end_clear_restore,
};
void __trace_end_clear_restore(struct u_trace *ut
) {
   struct __payload_end_clear_restore *__entry =
      (struct __payload_end_clear_restore *)u_trace_append(ut, &__tp_end_clear_restore);
   (void)__entry;
}

/*
 * start_clear_restore
 */
struct __payload_start_clear_restore {
         uint16_t fast_cleared;
};
static void __print_start_clear_restore(FILE *out, const void *arg) {
   const struct __payload_start_clear_restore *__entry =
      (const struct __payload_start_clear_restore *)arg;
   fprintf(out, "fast_cleared: 0x%x\n"
           , __entry->fast_cleared
   );
}
static const struct u_tracepoint __tp_start_clear_restore = {
    ALIGN_POT(sizeof(struct __payload_start_clear_restore), 8),   /* keep size 64b aligned */
    "start_clear_restore",
    __print_start_clear_restore,
};
void __trace_start_clear_restore(struct u_trace *ut
     , uint16_t fast_cleared
) {
   struct __payload_start_clear_restore *__entry =
      (struct __payload_start_clear_restore *)u_trace_append(ut, &__tp_start_clear_restore);
   (void)__entry;
        __entry->fast_cleared = fast_cleared;
}

/*
 * render_gmem
 */
struct __payload_render_gmem {
         uint16_t nbins_x;
         uint16_t nbins_y;
         uint16_t bin_w;
         uint16_t bin_h;
};
static void __print_render_gmem(FILE *out, const void *arg) {
   const struct __payload_render_gmem *__entry =
      (const struct __payload_render_gmem *)arg;
   fprintf(out, "%ux%u bins of %ux%u\n"
           , __entry->nbins_x
           , __entry->nbins_y
           , __entry->bin_w
           , __entry->bin_h
   );
}
static const struct u_tracepoint __tp_render_gmem = {
    ALIGN_POT(sizeof(struct __payload_render_gmem), 8),   /* keep size 64b aligned */
    "render_gmem",
    __print_render_gmem,
};
void __trace_render_gmem(struct u_trace *ut
     , uint16_t nbins_x
     , uint16_t nbins_y
     , uint16_t bin_w
     , uint16_t bin_h
) {
   struct __payload_render_gmem *__entry =
      (struct __payload_render_gmem *)u_trace_append(ut, &__tp_render_gmem);
   (void)__entry;
        __entry->nbins_x = nbins_x;
        __entry->nbins_y = nbins_y;
        __entry->bin_w = bin_w;
        __entry->bin_h = bin_h;
}

/*
 * end_state_restore
 */
struct __payload_end_state_restore {
};
#define __print_end_state_restore NULL
static const struct u_tracepoint __tp_end_state_restore = {
    ALIGN_POT(sizeof(struct __payload_end_state_restore), 8),   /* keep size 64b aligned */
    "end_state_restore",
    __print_end_state_restore,
};
void __trace_end_state_restore(struct u_trace *ut
) {
   struct __payload_end_state_restore *__entry =
      (struct __payload_end_state_restore *)u_trace_append(ut, &__tp_end_state_restore);
   (void)__entry;
}

/*
 * start_binning_ib
 */
struct __payload_start_binning_ib {
};
#define __print_start_binning_ib NULL
static const struct u_tracepoint __tp_start_binning_ib = {
    ALIGN_POT(sizeof(struct __payload_start_binning_ib), 8),   /* keep size 64b aligned */
    "start_binning_ib",
    __print_start_binning_ib,
};
void __trace_start_binning_ib(struct u_trace *ut
) {
   struct __payload_start_binning_ib *__entry =
      (struct __payload_start_binning_ib *)u_trace_append(ut, &__tp_start_binning_ib);
   (void)__entry;
}

/*
 * end_binning_ib
 */
struct __payload_end_binning_ib {
};
#define __print_end_binning_ib NULL
static const struct u_tracepoint __tp_end_binning_ib = {
    ALIGN_POT(sizeof(struct __payload_end_binning_ib), 8),   /* keep size 64b aligned */
    "end_binning_ib",
    __print_end_binning_ib,
};
void __trace_end_binning_ib(struct u_trace *ut
) {
   struct __payload_end_binning_ib *__entry =
      (struct __payload_end_binning_ib *)u_trace_append(ut, &__tp_end_binning_ib);
   (void)__entry;
}

/*
 * start_draw_ib
 */
struct __payload_start_draw_ib {
};
#define __print_start_draw_ib NULL
static const struct u_tracepoint __tp_start_draw_ib = {
    ALIGN_POT(sizeof(struct __payload_start_draw_ib), 8),   /* keep size 64b aligned */
    "start_draw_ib",
    __print_start_draw_ib,
};
void __trace_start_draw_ib(struct u_trace *ut
) {
   struct __payload_start_draw_ib *__entry =
      (struct __payload_start_draw_ib *)u_trace_append(ut, &__tp_start_draw_ib);
   (void)__entry;
}

/*
 * end_compute
 */
struct __payload_end_compute {
};
#define __print_end_compute NULL
static const struct u_tracepoint __tp_end_compute = {
    ALIGN_POT(sizeof(struct __payload_end_compute), 8),   /* keep size 64b aligned */
    "end_compute",
    __print_end_compute,
};
void __trace_end_compute(struct u_trace *ut
) {
   struct __payload_end_compute *__entry =
      (struct __payload_end_compute *)u_trace_append(ut, &__tp_end_compute);
   (void)__entry;
}

/*
 * end_resolve
 */
struct __payload_end_resolve {
};
#define __print_end_resolve NULL
static const struct u_tracepoint __tp_end_resolve = {
    ALIGN_POT(sizeof(struct __payload_end_resolve), 8),   /* keep size 64b aligned */
    "end_resolve",
    __print_end_resolve,
};
void __trace_end_resolve(struct u_trace *ut
) {
   struct __payload_end_resolve *__entry =
      (struct __payload_end_resolve *)u_trace_append(ut, &__tp_end_resolve);
   (void)__entry;
}

/*
 * end_vsc_overflow_test
 */
struct __payload_end_vsc_overflow_test {
};
#define __print_end_vsc_overflow_test NULL
static const struct u_tracepoint __tp_end_vsc_overflow_test = {
    ALIGN_POT(sizeof(struct __payload_end_vsc_overflow_test), 8),   /* keep size 64b aligned */
    "end_vsc_overflow_test",
    __print_end_vsc_overflow_test,
};
void __trace_end_vsc_overflow_test(struct u_trace *ut
) {
   struct __payload_end_vsc_overflow_test *__entry =
      (struct __payload_end_vsc_overflow_test *)u_trace_append(ut, &__tp_end_vsc_overflow_test);
   (void)__entry;
}

/*
 * start_compute
 */
struct __payload_start_compute {
};
#define __print_start_compute NULL
static const struct u_tracepoint __tp_start_compute = {
    ALIGN_POT(sizeof(struct __payload_start_compute), 8),   /* keep size 64b aligned */
    "start_compute",
    __print_start_compute,
};
void __trace_start_compute(struct u_trace *ut
) {
   struct __payload_start_compute *__entry =
      (struct __payload_start_compute *)u_trace_append(ut, &__tp_start_compute);
   (void)__entry;
}

/*
 * start_prologue
 */
struct __payload_start_prologue {
};
#define __print_start_prologue NULL
static const struct u_tracepoint __tp_start_prologue = {
    ALIGN_POT(sizeof(struct __payload_start_prologue), 8),   /* keep size 64b aligned */
    "start_prologue",
    __print_start_prologue,
};
void __trace_start_prologue(struct u_trace *ut
) {
   struct __payload_start_prologue *__entry =
      (struct __payload_start_prologue *)u_trace_append(ut, &__tp_start_prologue);
   (void)__entry;
}

/*
 * flush_batch
 */
struct __payload_flush_batch {
         struct fd_batch * batch;
         uint16_t cleared;
         uint16_t gmem_reason;
         uint16_t num_draws;
};
static void __print_flush_batch(FILE *out, const void *arg) {
   const struct __payload_flush_batch *__entry =
      (const struct __payload_flush_batch *)arg;
   fprintf(out, "%p: cleared=%x, gmem_reason=%x, num_draws=%u\n"
           , __entry->batch
           , __entry->cleared
           , __entry->gmem_reason
           , __entry->num_draws
   );
}
static const struct u_tracepoint __tp_flush_batch = {
    ALIGN_POT(sizeof(struct __payload_flush_batch), 8),   /* keep size 64b aligned */
    "flush_batch",
    __print_flush_batch,
};
void __trace_flush_batch(struct u_trace *ut
     , struct fd_batch * batch
     , uint16_t cleared
     , uint16_t gmem_reason
     , uint16_t num_draws
) {
   struct __payload_flush_batch *__entry =
      (struct __payload_flush_batch *)u_trace_append(ut, &__tp_flush_batch);
   (void)__entry;
        __entry->batch = batch;
        __entry->cleared = cleared;
        __entry->gmem_reason = gmem_reason;
        __entry->num_draws = num_draws;
}

/*
 * end_draw_ib
 */
struct __payload_end_draw_ib {
};
#define __print_end_draw_ib NULL
static const struct u_tracepoint __tp_end_draw_ib = {
    ALIGN_POT(sizeof(struct __payload_end_draw_ib), 8),   /* keep size 64b aligned */
    "end_draw_ib",
    __print_end_draw_ib,
};
void __trace_end_draw_ib(struct u_trace *ut
) {
   struct __payload_end_draw_ib *__entry =
      (struct __payload_end_draw_ib *)u_trace_append(ut, &__tp_end_draw_ib);
   (void)__entry;
}

/*
 * end_prologue
 */
struct __payload_end_prologue {
};
#define __print_end_prologue NULL
static const struct u_tracepoint __tp_end_prologue = {
    ALIGN_POT(sizeof(struct __payload_end_prologue), 8),   /* keep size 64b aligned */
    "end_prologue",
    __print_end_prologue,
};
void __trace_end_prologue(struct u_trace *ut
) {
   struct __payload_end_prologue *__entry =
      (struct __payload_end_prologue *)u_trace_append(ut, &__tp_end_prologue);
   (void)__entry;
}

/*
 * start_tile
 */
struct __payload_start_tile {
         uint16_t bin_h;
         uint16_t yoff;
         uint16_t bin_w;
         uint16_t xoff;
};
static void __print_start_tile(FILE *out, const void *arg) {
   const struct __payload_start_tile *__entry =
      (const struct __payload_start_tile *)arg;
   fprintf(out, "bin_h=%d, yoff=%d, bin_w=%d, xoff=%d\n"
           , __entry->bin_h
           , __entry->yoff
           , __entry->bin_w
           , __entry->xoff
   );
}
static const struct u_tracepoint __tp_start_tile = {
    ALIGN_POT(sizeof(struct __payload_start_tile), 8),   /* keep size 64b aligned */
    "start_tile",
    __print_start_tile,
};
void __trace_start_tile(struct u_trace *ut
     , uint16_t bin_h
     , uint16_t yoff
     , uint16_t bin_w
     , uint16_t xoff
) {
   struct __payload_start_tile *__entry =
      (struct __payload_start_tile *)u_trace_append(ut, &__tp_start_tile);
   (void)__entry;
        __entry->bin_h = bin_h;
        __entry->yoff = yoff;
        __entry->bin_w = bin_w;
        __entry->xoff = xoff;
}

/*
 * start_blit
 */
struct __payload_start_blit {
         enum pipe_texture_target src_target;
         enum pipe_texture_target dst_target;
};
static void __print_start_blit(FILE *out, const void *arg) {
   const struct __payload_start_blit *__entry =
      (const struct __payload_start_blit *)arg;
   fprintf(out, "%s -> %s\n"
           , util_str_tex_target(__entry->src_target, true)
           , util_str_tex_target(__entry->dst_target, true)
   );
}
static const struct u_tracepoint __tp_start_blit = {
    ALIGN_POT(sizeof(struct __payload_start_blit), 8),   /* keep size 64b aligned */
    "start_blit",
    __print_start_blit,
};
void __trace_start_blit(struct u_trace *ut
     , enum pipe_texture_target src_target
     , enum pipe_texture_target dst_target
) {
   struct __payload_start_blit *__entry =
      (struct __payload_start_blit *)u_trace_append(ut, &__tp_start_blit);
   (void)__entry;
        __entry->src_target = src_target;
        __entry->dst_target = dst_target;
}

/*
 * start_vsc_overflow_test
 */
struct __payload_start_vsc_overflow_test {
};
#define __print_start_vsc_overflow_test NULL
static const struct u_tracepoint __tp_start_vsc_overflow_test = {
    ALIGN_POT(sizeof(struct __payload_start_vsc_overflow_test), 8),   /* keep size 64b aligned */
    "start_vsc_overflow_test",
    __print_start_vsc_overflow_test,
};
void __trace_start_vsc_overflow_test(struct u_trace *ut
) {
   struct __payload_start_vsc_overflow_test *__entry =
      (struct __payload_start_vsc_overflow_test *)u_trace_append(ut, &__tp_start_vsc_overflow_test);
   (void)__entry;
}

/*
 * render_sysmem
 */
struct __payload_render_sysmem {
};
#define __print_render_sysmem NULL
static const struct u_tracepoint __tp_render_sysmem = {
    ALIGN_POT(sizeof(struct __payload_render_sysmem), 8),   /* keep size 64b aligned */
    "render_sysmem",
    __print_render_sysmem,
};
void __trace_render_sysmem(struct u_trace *ut
) {
   struct __payload_render_sysmem *__entry =
      (struct __payload_render_sysmem *)u_trace_append(ut, &__tp_render_sysmem);
   (void)__entry;
}

/*
 * start_resolve
 */
struct __payload_start_resolve {
};
#define __print_start_resolve NULL
static const struct u_tracepoint __tp_start_resolve = {
    ALIGN_POT(sizeof(struct __payload_start_resolve), 8),   /* keep size 64b aligned */
    "start_resolve",
    __print_start_resolve,
};
void __trace_start_resolve(struct u_trace *ut
) {
   struct __payload_start_resolve *__entry =
      (struct __payload_start_resolve *)u_trace_append(ut, &__tp_start_resolve);
   (void)__entry;
}

