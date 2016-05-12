/* sensor_lsm9ds0_gyro.h - header file for LSM9DS0 gyroscope sensor driver */

/*
* Copyright (c) 2016 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef __SENSOR_LSM9DS0_GYRO_H__
#define __SENSOR_LSM9DS0_GYRO_H__

#include <stdint.h>
#include <i2c.h>
#include <misc/util.h>

#define DEG2RAD					0.017453292519943295769236907684

#define LSM9DS0_GYRO_REG_WHO_AM_I_G		0x0F
#define LSM9DS0_GYRO_VAL_WHO_AM_I_G		0xD4

#define LSM9DS0_GYRO_REG_CTRL_REG1_G            0x20
#define LSM9DS0_GYRO_MASK_CTRL_REG1_G_DR        (BIT(7) | BIT(6))
#define LSM9DS0_GYRO_SHIFT_CTRL_REG1_G_DR       6
#define LSM9DS0_GYRO_MASK_CTRL_REG1_G_BW        (BIT(5) | BIT(4))
#define LSM9DS0_GYRO_SHIFT_CTRL_REG1_G_BW       4
#define LSM9DS0_GYRO_MASK_CTRL_REG1_G_PD        BIT(3)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG1_G_PD       3
#define LSM9DS0_GYRO_MASK_CTRL_REG1_G_ZEN       BIT(2)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG1_G_ZEN      2
#define LSM9DS0_GYRO_MASK_CTRL_REG1_G_XEN       BIT(1)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG1_G_XEN      1
#define LSM9DS0_GYRO_MASK_CTRL_REG1_G_YEN       BIT(0)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG1_G_YEN      0

#define LSM9DS0_GYRO_REG_CTRL_REG2_G            0x21
#define LSM9DS0_GYRO_MASK_CTRL_REG2_G_HPM       (BIT(5) | BIT(4))
#define LSM9DS0_GYRO_SHIFT_CTRL_REG2_G_HPM      4
#define LSM9DS0_GYRO_MASK_CTRL_REG2_G_HPCF      (BIT(3) | BIT(2) | BIT(1) | \
						 BIT(0))

#define LSM9DS0_GYRO_REG_CTRL_REG3_G            0x22
#define LSM9DS0_GYRO_MASK_CTRL_REG3_G_I1_INT1   BIT(7)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG3_G_I1_INT1  7
#define LSM9DS0_GYRO_MASK_CTRL_REG3_G_I1_BOOT   BIT(6)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG3_G_I1_BOOT  6
#define LSM9DS0_GYRO_MASK_CTRL_REG3_G_H_L       BIT(5)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG3_G_H_L      5
#define LSM9DS0_GYRO_MASK_CTRL_REG3_G_PP_OD     BIT(4)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG3_G_PP_OD    4
#define LSM9DS0_GYRO_MASK_CTRL_REG3_G_I2_DRDY   BIT(3)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG3_G_I2_DRDY  3
#define LSM9DS0_GYRO_MASK_CTRL_REG3_G_I2_WTM    BIT(2)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG3_G_I2_WTM   2
#define LSM9DS0_GYRO_MASK_CTRL_REG3_G_I2_OR     BIT(1)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG3_G_I2_OR    1
#define LSM9DS0_GYRO_MASK_CTRL_REG3_G_I2_E      BIT(0)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG3_G_I2_E     0

#define LSM9DS0_GYRO_REG_CTRL_REG4_G            0x23
#define LSM9DS0_GYRO_MASK_CTRL_REG4_G_BDU       BIT(7)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG4_G_BDU      7
#define LSM9DS0_GYRO_MASK_CTRL_REG4_G_BLE       BIT(6)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG4_G_BLE      6
#define LSM9DS0_GYRO_MASK_CTRL_REG4_G_FS        (BIT(5) | BIT(4))
#define LSM9DS0_GYRO_SHIFT_CTRL_REG4_G_FS       4
#define LSM9DS0_GYRO_MASK_CTRL_REG4_G_ST        (BIT(2) | BIT(1))
#define LSM9DS0_GYRO_SHIFT_CTRL_REG4_G_ST       1

#define LSM9DS0_GYRO_REG_CTRL_REG5_G            0x24
#define LSM9DS0_GYRO_MASK_CTRL_REG5_G_BOOT      BIT(7)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG5_G_BOOT     7
#define LSM9DS0_GYRO_MASK_CTRL_REG5_G_FIFO_EN   BIT(6)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG5_G_FIFO_EN  6
#define LSM9DS0_GYRO_MASK_CTRL_REG5_G_HPEN      BIT(4)
#define LSM9DS0_GYRO_SHIFT_CTRL_REG5_G_HPEN     4
#define LSM9DS0_GYRO_MASK_CTRL_REG5_G_INT1_SEL  (BIT(3) | BIT(2))
#define LSM9DS0_GYRO_SHIFT_CTRL_REG5_G_INT1_SEL 2
#define LSM9DS0_GYRO_MASK_CTRL_REG5_G_OUT_SEL   (BIT(1) | BIT(0))
#define LSM9DS0_GYRO_SHIFT_CTRL_REG5_G_OUT_SEL  0

#define LSM9DS0_GYRO_REG_DATACAPTURE_G          0x25

#define LSM9DS0_GYRO_REG_STATUS_REG_G           0x27
#define LSM9DS0_GYRO_MASK_STATUS_REG_G_ZYXOR    BIT(7)
#define LSM9DS0_GYRO_SHIFT_STATUS_REG_G_ZYXOR   7
#define LSM9DS0_GYRO_MASK_STATUS_REG_G_ZOR      BIT(6)
#define LSM9DS0_GYRO_SHIFT_STATUS_REG_G_ZOR     6
#define LSM9DS0_GYRO_MASK_STATUS_REG_G_YOR      BIT(5)
#define LSM9DS0_GYRO_SHIFT_STATUS_REG_G_YOR     5
#define LSM9DS0_GYRO_MASK_STATUS_REG_G_XOR      BIT(4)
#define LSM9DS0_GYRO_SHIFT_STATUS_REG_G_XOR     4
#define LSM9DS0_GYRO_MASK_STATUS_REG_G_ZYXDA    BIT(3)
#define LSM9DS0_GYRO_SHIFT_STATUS_REG_G_ZYXDA   3
#define LSM9DS0_GYRO_MASK_STATUS_REG_G_ZDA      BIT(2)
#define LSM9DS0_GYRO_SHIFT_STATUS_REG_G_ZDA     2
#define LSM9DS0_GYRO_MASK_STATUS_REG_G_YDA      BIT(1)
#define LSM9DS0_GYRO_SHIFT_STATUS_REG_G_YDA     1
#define LSM9DS0_GYRO_MASK_STATUS_REG_G_XDA      BIT(0)
#define LSM9DS0_GYRO_SHIFT_STATUS_REG_G_XDA     0

#define LSM9DS0_GYRO_REG_OUT_X_L_G              0x28
#define LSM9DS0_GYRO_REG_OUT_X_H_G              0x29
#define LSM9DS0_GYRO_REG_OUT_Y_L_G              0x2A
#define LSM9DS0_GYRO_REG_OUT_Y_H_G              0x2B
#define LSM9DS0_GYRO_REG_OUT_Z_L_G              0x2C
#define LSM9DS0_GYRO_REG_OUT_Z_H_G              0x2D

#define LSM9DS0_GYRO_REG_FIFO_CTRL_REG_G        0x2E
#define LSM9DS0_GYRO_MASK_FIFO_CTRL_REG_G_FM    (BIT(7) | BIT(6) | BIT(5))
#define LSM9DS0_GYRO_SHIFT_FIFO_CTRL_REG_G_FM   5
#define LSM9DS0_GYRO_MASK_FIFO_CTRL_REG_G_WTM   (BIT(4) | BIT(3) | BIT(2) | \
						 BIT(1) | BIT(0))
#define LSM9DS0_GYRO_SHIFT_FIFO_CTRL_REG_G_WTM  0

#define LSM9DS0_GYRO_REG_FIFO_SRC_REG_G         0x2F
#define LSM9DS0_GYRO_MASK_FIFO_SRC_REG_G_WTM    BIT(7)
#define LSM9DS0_GYRO_SHIFT_FIFO_SRC_REG_G_WTM   7
#define LSM9DS0_GYRO_MASK_FIFO_SRC_REG_G_OVRN   BIT(6)
#define LSM9DS0_GYRO_SHIFT_FIFO_SRC_REG_G_OVRN  6
#define LSM9DS0_GYRO_MASK_FIFO_SRC_REG_G_EMPTY  BIT(5)
#define LSM9DS0_GYRO_SHIFT_FIFO_SRC_REG_G_EMPTY 5
#define LSM9DS0_GYRO_MASK_FIFO_SRC_REG_G_FSS    (BIT(4) | BIT(3) | BIT(2) | \
						 BIT(1) | BIT(0))
#define LSM9DS0_GYRO_SHIFT_FIFO_SRC_REG_G_FSS   0

#define LSM9DS0_GYRO_REG_INT1_CFG_G             0x30
#define LSM9DS0_GYRO_MASK_INT1_CFG_G_ANDOR      BIT(7)
#define LSM9DS0_GYRO_SHIFT_INT1_CFG_G_ANDOR     7
#define LSM9DS0_GYRO_MASK_INT1_CFG_G_LIR        BIT(6)
#define LSM9DS0_GYRO_SHIFT_INT1_CFG_G_LIR       6
#define LSM9DS0_GYRO_MASK_INT1_CFG_G_ZHIE       BIT(5)
#define LSM9DS0_GYRO_SHIFT_INT1_CFG_G_ZHIE      5
#define LSM9DS0_GYRO_MASK_INT1_CFG_G_ZLIE       BIT(4)
#define LSM9DS0_GYRO_SHIFT_INT1_CFG_G_ZLIE      4
#define LSM9DS0_GYRO_MASK_INT1_CFG_G_YHIE       BIT(3)
#define LSM9DS0_GYRO_SHIFT_INT1_CFG_G_YHIE      3
#define LSM9DS0_GYRO_MASK_INT1_CFG_G_YLIE       BIT(2)
#define LSM9DS0_GYRO_SHIFT_INT1_CFG_G_YLIE      2
#define LSM9DS0_GYRO_MASK_INT1_CFG_G_XHIE       BIT(1)
#define LSM9DS0_GYRO_SHIFT_INT1_CFG_G_XHIE      1
#define LSM9DS0_GYRO_MASK_INT1_CFG_G_XLIE       BIT(0)
#define LSM9DS0_GYRO_SHIFT_INT1_CFG_G_XLIE      0

#define LSM9DS0_GYRO_REG_INT1_SRC_G             0x31
#define LSM9DS0_GYRO_MASK_INT1_SRC_G_IA         BIT(6)
#define LSM9DS0_GYRO_SHIFT_INT1_SRC_G_IA        6
#define LSM9DS0_GYRO_MASK_INT1_SRC_G_ZH         BIT(5)
#define LSM9DS0_GYRO_SHIFT_INT1_SRC_G_ZH        5
#define LSM9DS0_GYRO_MASK_INT1_SRC_G_ZL         BIT(4)
#define LSM9DS0_GYRO_SHIFT_INT1_SRC_G_ZL        4
#define LSM9DS0_GYRO_MASK_INT1_SRC_G_YH         BIT(3)
#define LSM9DS0_GYRO_SHIFT_INT1_SRC_G_YH        3
#define LSM9DS0_GYRO_MASK_INT1_SRC_G_YL         BIT(2)
#define LSM9DS0_GYRO_SHIFT_INT1_SRC_G_YL        2
#define LSM9DS0_GYRO_MASK_INT1_SRC_G_XH         BIT(1)
#define LSM9DS0_GYRO_SHIFT_INT1_SRC_G_XH        1
#define LSM9DS0_GYRO_MASK_INT1_SRC_G_XL         BIT(0)
#define LSM9DS0_GYRO_SHIFT_INT1_SRC_G_XL        0

#define LSM9DS0_GYRO_REG_INT1_THS_XH_G          0x32
#define LSM9DS0_GYRO_MASK_INT1_THS_XH_G         (BIT(6) | BIT(5) | BIT(4) | \
						 BIT(3) | BIT(2) | BIT(1) | \
						 BIT(0))

#define LSM9DS0_GYRO_REG_INT1_THS_XL_G          0x33

#define LSM9DS0_GYRO_REG_INT1_THS_YH_G          0x34
#define LSM9DS0_GYRO_MASK_INT1_THS_YH_G         (BIT(6) | BIT(5) | BIT(4) | \
						 BIT(3) | BIT(2) | BIT(1) | \
						 BIT(0))

#define LSM9DS0_GYRO_REG_INT1_THS_YL_G          0x35

#define LSM9DS0_GYRO_REG_INT1_THS_ZH_G          0x36
#define LSM9DS0_GYRO_MASK_INT1_THS_ZH_G         (BIT(6) | BIT(5) | BIT(4) | \
						 BIT(3) | BIT(2) | BIT(1) | \
						 BIT(0))

#define LSM9DS0_GYRO_REG_INT1_THS_ZL_G          0x37

#define LSM9DS0_GYRO_REG_INT1_DURATION_G        0x38
#define LSM9DS0_GYRO_MASK_INT1_DURATION_G_WAIT  BIT(7)
#define LSM9DS0_GYRO_SHIFT_INT1_DURATION_G_WAIT 7
#define LSM9DS0_GYRO_MASK_INT1_DURATION_G_D     (BIT(6) | BIT(5) | BIT(4) | \
						 BIT(3) | BIT(2) | BIT(1) | \
						 BIT(0))
#define LSM9DS0_GYRO_SHIFT_INT1_DURATION_G_D    0

#if defined(CONFIG_LSM9DS0_GYRO_I2C_ADDR_6A)
	#define LSM9DS0_GYRO_I2C_ADDR           0x6A
#elif defined(CONFIG_LSM9DS0_GYRO_I2c_ADDR_6B)
	#define LSM9DS0_GYRO_I2C_ADDR           0x6B
#endif

#if defined(CONFIG_LSM9DS0_GYRO_FULLSCALE_245)
	#define LSM9DS0_GYRO_DEFAULT_FULLSCALE  0
#elif defined(CONFIG_LSM9DS0_GYRO_FULLSCALE_500)
	#define LSM9DS0_GYRO_DEFAULT_FULLSCALE  1
#elif defined(CONFIG_LSM9DS0_GYRO_FULLSCALE_2000)
	#define LSM9DS0_GYRO_DEFAULT_FULLSCALE  2
#endif

#if defined(CONFIG_LSM9DS0_GYRO_SAMPLING_RATE_95)
	#define LSM9DS0_GYRO_DEFAULT_SAMPLING_RATE      0
#elif defined(CONFIG_LSM9DS0_GYRO_SAMPLING_RATE_190)
	#define LSM9DS0_GYRO_DEFAULT_SAMPLING_RATE      1
#elif defined(CONFIG_LSM9DS0_GYRO_SAMPLING_RATE_380)
	#define LSM9DS0_GYRO_DEFAULT_SAMPLING_RATE      2
#elif defined(CONFIG_LSM9DS0_GYRO_SAMPLING_RATE_760)
	#define LSM9DS0_GYRO_DEFAULT_SAMPLING_RATE      3
#endif

#if defined(CONFIG_LSM9DS0_GYRO_SAMPLING_RATE_RUNTIME) || \
	defined(CONFIG_LSM9DS0_GYRO_FULLSCALE_RUNTIME)
	#define LSM9DS0_GYRO_SET_ATTR
#endif

struct lsm9ds0_gyro_config {
	char *i2c_master_dev_name;
	uint16_t i2c_slave_addr;

#if CONFIG_LSM9DS0_GYRO_TRIGGER_DRDY
	char *gpio_drdy_dev_name;
	uint8_t gpio_drdy_int_pin;
#endif
};

struct lsm9ds0_gyro_data {
	struct device *i2c_master;

#if defined(CONFIG_LSM9DS0_GYRO_TRIGGERS)
	struct nano_sem sem;
#endif

#if defined(CONFIG_LSM9DS0_GYRO_TRIGGER_DRDY)
	char __stack fiber_stack[CONFIG_LSM9DS0_GYRO_FIBER_STACK_SIZE];
	struct device *dev;

	struct device *gpio_drdy;
	struct gpio_callback gpio_cb;
	struct sensor_trigger trigger_drdy;
	sensor_trigger_handler_t handler_drdy;
#endif

	int sample_x, sample_y, sample_z;
#if defined(CONFIG_LSM9DS0_GYRO_FULLSCALE_RUNTIME)
	uint8_t sample_fs;
	uint8_t fs;
#endif
};

#if defined(CONFIG_LSM9DS0_GYRO_TRIGGER_DRDY)
int lsm9ds0_gyro_trigger_set(struct device *dev,
			     const struct sensor_trigger *trig,
			     sensor_trigger_handler_t handler);

int lsm9ds0_gyro_init_interrupt(struct device *dev);
#endif

#define SYS_LOG_DOMAIN "LSM9DS0_GYRO"
#define SYS_LOG_LEVEL CONFIG_LSM9DS0_GYRO_SYS_LOG_LEVEL
#include <misc/sys_log.h>
#endif /* __SENSOR_LSM9DS0_GYRO_H__ */