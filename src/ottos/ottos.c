/* ottos.cc
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
 *  Created on: Oct 19, 2011
 *      Author: Matthias Schmid <m.schmid@students.fhv.at>
 */

#include <ottos/system.h>
#include <ottos/kernel.h>
#include <ottos/const.h>

#include "../../bin/led_test.h"
#include "../../bin/serial_test.h"
#include "../../bin/console.h"

#include "kernel/intc/irq.h"
#include "kernel/pm/process.h"
#include "kernel/timer/timer.h"
#include "dev/devices.h"
#include "../hal/uart.h"

#include "../fs/fs.h"
#include "../fs/vfat/fat_filelib.h"

#include "../../drivers/mmchs/mmchs.h"

void timer_test() {


  process_table_init();

  process_create(1, (int)toggle_led1);
  process_create(1, (int)toggle_led2);

  devices_init();

  irq_init();

  timer_init();
  //timer_add_handler(toggle_led_1, 5000);
  //timer_add_handler(toggle_led_2, 10000);

  irq_register_context_switch();

  irq_enable();
  kernel_to_user_mode();
}

void devices_test() {
  devices_init();
}

//void process_test() {
//
//
//  process_table_init();
//
//  process_create(1, (int)toggle_led1_yield);
//  process_create(1, (int)toggle_led2_yield);
//
//  devices_init();
//
//  // switch to user mode
//  kernel_to_user_mode();
//  sys_yield();
//
//}

void serial_test() {



   process_table_init();

//    process_create(1, (int)serial_test_test_yield);
//    process_create(1, (int)toggle_led1_yield);
//    process_create(1, (int)toggle_led2_yield);


   //process_create(1, (int) led1_on);
   //process_create(1, (int) led1_off);
   process_create(1, (int) toggle_led1);
   process_create(1, (int) toggle_led2);
   //process_create(1, (int) serial_test_write_1);
   //process_create(1, (int) serial_test_write_2);
   //process_create(1, (int) serial_test_write_3);
   //process_create(1, (int) serial_test_write_4);
   //process_create(1, (int) serial_test_write_5);
   process_create(1, (int) serial_test_calculator);

    devices_init();
    serial_test_create();

    irq_init();

    timer_init();

    irq_register_context_switch();

    irq_enable();
    kernel_to_user_mode();
//    sys_yield();

//    serial_test_test();
}

void serial_test_calc() {

  process_table_init();
  process_create(1, (int) toggle_led1);
  process_create(1, (int) serial_test_calculator);

  devices_init();

  irq_init();

  timer_init();

  irq_register_context_switch();

  irq_enable();
  kernel_to_user_mode();
}

void process_exit_test() {

  process_table_init();
  process_create(1, (int) serial_test_write_exit_1);
  process_create(1, (int) serial_test_write_exit_2);
  process_create(1, (int) toggle_led1);

  devices_init();

  irq_init();
  timer_init();
  irq_register_context_switch();
  irq_enable();

  kernel_to_user_mode();
}

void dummy_process() {
  for(;;);
}

void console_test() {

  process_table_init();
  //process_create(1, (int) toggle_led1);
  //process_create(1, (int) toggle_led2);

  //process_create(1, (int) dummy_process);
  // process_create(1, (int) console_start);

  devices_init();

  irq_init();

  timer_init();

  irq_register_context_switch();

  irq_enable();
  kernel_to_user_mode();
}

void fs_test() {
  file_t* file;
  char buffer[512];
  //char text[] = { 't', 'e', 's', 't', '\n', '\r' };
  char text[] = "new file\n\r\0";

  devices_init();
  mmchs_init();
  fs_init();
  fl_listdirectory("/");

  file = (file_t*) fl_fopen("/test/thenewest.txt", "a");
  fl_fwrite(text, sizeof(text), sizeof(text), file);
  fl_fclose(file);

  fl_listdirectory("/test/");

  file = (file_t*) fl_fopen("/test/thenewest.txt", "r");
  fl_fread(buffer, 512, sizeof(text), file);
  kernel_print(buffer);
  fl_fclose(file);


}

int main(int argc, char **argv) {

//  process_test();
//  timer_test();
//  serial_test();
//  serial_test_calc();
//  process_exit_test();
//  console_test();
  fs_test();

  for(;;);

  return 0;
}
