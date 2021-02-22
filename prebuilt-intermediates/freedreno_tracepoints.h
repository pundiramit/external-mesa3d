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


#ifndef _FREEDRENO_TRACEPOINTS_H
#define _FREEDRENO_TRACEPOINTS_H

#include "util/u_dump.h"
#include "freedreno_batch.h"

#include "util/u_trace.h"

void __trace_render_gmem(struct u_trace *ut
     , uint16_t nbins_x
     , uint16_t nbins_y
     , uint16_t bin_w
     , uint16_t bin_h
);
static inline void trace_render_gmem(struct u_trace *ut
     , uint16_t nbins_x
     , uint16_t nbins_y
     , uint16_t bin_w
     , uint16_t bin_h
) {
   if (likely(!ut->enabled))
      return;
   __trace_render_gmem(ut
        , nbins_x
        , nbins_y
        , bin_w
        , bin_h
   );
}
void __trace_start_state_restore(struct u_trace *ut
);
static inline void trace_start_state_restore(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_state_restore(ut
   );
}
void __trace_start_tile(struct u_trace *ut
     , uint16_t bin_h
     , uint16_t yoff
     , uint16_t bin_w
     , uint16_t xoff
);
static inline void trace_start_tile(struct u_trace *ut
     , uint16_t bin_h
     , uint16_t yoff
     , uint16_t bin_w
     , uint16_t xoff
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_tile(ut
        , bin_h
        , yoff
        , bin_w
        , xoff
   );
}
void __trace_flush_batch(struct u_trace *ut
     , struct fd_batch * batch
     , uint16_t cleared
     , uint16_t gmem_reason
     , uint16_t num_draws
);
static inline void trace_flush_batch(struct u_trace *ut
     , struct fd_batch * batch
     , uint16_t cleared
     , uint16_t gmem_reason
     , uint16_t num_draws
) {
   if (likely(!ut->enabled))
      return;
   __trace_flush_batch(ut
        , batch
        , cleared
        , gmem_reason
        , num_draws
   );
}
void __trace_end_vsc_overflow_test(struct u_trace *ut
);
static inline void trace_end_vsc_overflow_test(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_vsc_overflow_test(ut
   );
}
void __trace_end_draw_ib(struct u_trace *ut
);
static inline void trace_end_draw_ib(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_draw_ib(ut
   );
}
void __trace_end_clear_restore(struct u_trace *ut
);
static inline void trace_end_clear_restore(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_clear_restore(ut
   );
}
void __trace_start_binning_ib(struct u_trace *ut
);
static inline void trace_start_binning_ib(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_binning_ib(ut
   );
}
void __trace_render_sysmem(struct u_trace *ut
);
static inline void trace_render_sysmem(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_render_sysmem(ut
   );
}
void __trace_start_vsc_overflow_test(struct u_trace *ut
);
static inline void trace_start_vsc_overflow_test(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_vsc_overflow_test(ut
   );
}
void __trace_end_compute(struct u_trace *ut
);
static inline void trace_end_compute(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_compute(ut
   );
}
void __trace_start_compute(struct u_trace *ut
);
static inline void trace_start_compute(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_compute(ut
   );
}
void __trace_end_prologue(struct u_trace *ut
);
static inline void trace_end_prologue(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_prologue(ut
   );
}
void __trace_start_draw_ib(struct u_trace *ut
);
static inline void trace_start_draw_ib(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_draw_ib(ut
   );
}
void __trace_end_blit(struct u_trace *ut
);
static inline void trace_end_blit(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_blit(ut
   );
}
void __trace_start_blit(struct u_trace *ut
     , enum pipe_texture_target src_target
     , enum pipe_texture_target dst_target
);
static inline void trace_start_blit(struct u_trace *ut
     , enum pipe_texture_target src_target
     , enum pipe_texture_target dst_target
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_blit(ut
        , src_target
        , dst_target
   );
}
void __trace_end_binning_ib(struct u_trace *ut
);
static inline void trace_end_binning_ib(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_binning_ib(ut
   );
}
void __trace_start_prologue(struct u_trace *ut
);
static inline void trace_start_prologue(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_prologue(ut
   );
}
void __trace_start_resolve(struct u_trace *ut
);
static inline void trace_start_resolve(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_resolve(ut
   );
}
void __trace_end_resolve(struct u_trace *ut
);
static inline void trace_end_resolve(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_resolve(ut
   );
}
void __trace_start_clear_restore(struct u_trace *ut
     , uint16_t fast_cleared
);
static inline void trace_start_clear_restore(struct u_trace *ut
     , uint16_t fast_cleared
) {
   if (likely(!ut->enabled))
      return;
   __trace_start_clear_restore(ut
        , fast_cleared
   );
}
void __trace_end_state_restore(struct u_trace *ut
);
static inline void trace_end_state_restore(struct u_trace *ut
) {
   if (likely(!ut->enabled))
      return;
   __trace_end_state_restore(ut
   );
}

#endif /* _FREEDRENO_TRACEPOINTS_H */
