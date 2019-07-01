/* SPDX-License-Identifier: GPL-2.0-only or License-Ref-kk-custom */
/*
 * Copyright (C) 2021 Kernkonzept GmbH.
 * Author(s): Georg Kotheimer <georg.kotheimer@kernkonzept.com>
 */

#include <l4/vcpu/vcpu.h>

#include <stdio.h>

void l4vcpu_print_state_arch(l4_vcpu_state_t const *vcpu,
                             const char *prefix) L4_NOTHROW
{
  printf("%svcpu=%p ip=%08lx  status=%08lx cause=%08lx label=%08lx\n",
         prefix, vcpu, vcpu->r.ip, vcpu->r.status, vcpu->r.cause, vcpu->i.label);
  for (unsigned i = 0; i < 31; ++i)
    printf("%sr[%2d]=%08lx%s", (i & 3) == 0 ? prefix : "", i, vcpu->r.r[i],
           (i & 3) == 3 ? "\n" : " ");
}
