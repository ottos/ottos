/* led_1_test.h
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

#ifndef LED_1_TEST_H_
#define LED_1_TEST_H_


extern int toggle_led1(void);
extern int toggle_led2(void);

extern void toggle_led1_limited(void);
extern void toggle_led2_limited(void);

extern int toggle_led1_yield(void);
extern int toggle_led2_yield(void);
extern void led1_off();
extern void led1_on();


#endif /* LED_1_TEST_H_ */
