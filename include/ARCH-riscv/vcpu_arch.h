/* SPDX-License-Identifier: GPL-2.0-only or License-Ref-kk-custom */
/*
 * Copyright (C) 2021 Kernkonzept GmbH.
 * Author(s): Georg Kotheimer <georg.kotheimer@kernkonzept.com>
 */
#pragma once

L4_CV L4_INLINE
int
l4vcpu_is_irq_entry(l4_vcpu_state_t const *vcpu) L4_NOTHROW
{
  return vcpu->r.cause == L4_riscv_ec_l4_ipc_upcall;
}

L4_CV L4_INLINE
int
l4vcpu_is_page_fault_entry(l4_vcpu_state_t const *vcpu) L4_NOTHROW
{
  switch(vcpu->r.cause)
    {
    case L4_riscv_exc_inst_page_fault:
    case L4_riscv_exc_load_page_fault:
    case L4_riscv_exc_store_page_fault:
      return 1;
    default:
      return 0;
    }
}
