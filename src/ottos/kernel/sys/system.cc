/* syscalls.cc
 * 
 * Copyright (c) 2011 The ottos project.
 *
 * This work is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 * 
 * This work is distributed in the hope that it will be useful, but without
 * any warranty; without even the implied warranty of merchantability or
 * fitness for a particular purpose. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *
 *  Created on: 27 Oct 2011
 *      Author: Thomas Bargetz <thomas.bargetz@gmail.com>
 */

#include <ottos/system.h>
#include <ottos/syscalls.h>

asm("\t .bss _reg_val, 4");
asm("\t .global _reg_val");
asm("reg_val_a .field _reg_val, 32");

extern int reg_val;

#define PUT_TO_REGISTER(reg, val) ({ \
  reg_val = val; \
  asm volatile("\t LDR "reg", reg_val_a"); \
})

#define READ_FROM_REGISTER(reg, var) ({ \
  PUT_TO_REGISTER(reg, var); \
  asm volatile("\t STR "reg", ["reg",#0]"); \
  var = reg_val; \
})

#pragma SWI_ALIAS(1)
EXTERN void swi(int syscall_nr);

#define REG_0 r0
#define REG_1 r1
#define REG_2 r2

EXTERN

void sys_yield() {
  swi(SYS_YIELD);
}

address_t sys_open(char* filename, int flags) {

  // store registers temporary
  /*int t[2] = {0, 0};
  READ_FROM_REGISTER(REG_1, t[0]);
  READ_FROM_REGISTER(REG_2, t[1]);

  // put sys call params
  PUT_TO_REGISTER(REG_1, (int) filename);
  PUT_TO_REGISTER(REG_2, flags);
  swi(SYS_OPEN);

  // read return */
  address_t address = (address_t) 0;
  /* READ_FROM_REGISTER(0, address);

  // reset registers to temporary state
  PUT_TO_REGISTER(REG_1, t[0]);
  PUT_TO_REGISTER(REG_2, t[1]);
  */
  return address;
}
