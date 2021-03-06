/******************************************************************************
 *    Copyright (c) 2009-2010.
 *    All rights reserved.
 * ***
 *
 ******************************************************************************/

#ifndef HISFC300H
#define HISFC300H
/******************************************************************************/
/*
 *  Defines for new spi interfaces
 *
 *****************************************************************************/
/******************************************************************************/

#ifndef CONFIG_HISFC300NEW_REG_BASE_ADDRESS
#  define CONFIG_HISFC300NEW_REG_BASE_ADDRESS            (0x60020000)
#  warning NOT config CONFIG_HISFC300NEW_REG_BASE_ADDRESS, \
	used default value, maybe invalid.
#endif /* CONFIG_HISFC300NEW_REG_BASE_ADDRESS */

#ifndef CONFIG_HISFC300NEW_BUFFER_BASE_ADDRESS
#  define CONFIG_HISFC300NEW_BUFFER_BASE_ADDRESS         (0x26000000)
#  warning NOT config CONFIG_HISFC300NEW_BUFFER_BASE_ADDRESS, \
	used default value, maybe invalid.
#endif /* CONFIG_HISFC300NEW_BUFFER_BASE_ADDRESS */

#ifndef CONFIG_HISFC300NEW_PERIPHERY_REGBASE
#  define CONFIG_HISFC300NEW_PERIPHERY_REGBASE           (0x101F5000)
#  warning NOT config CONFIG_HISFC300NEW_PERIPHERY_REGBASE, \
	used default value, maybe invalid.
#endif /* CONFIG_HISFC300NEW_PERIPHERY_REGBASE */

#ifndef CONFIG_HISFC300NEW_CHIP_NUM
#  define CONFIG_HISFC300NEW_CHIP_NUM                    (2)
#  warning NOT config CONFIG_HISFC300NEW_CHIP_NUM, \
	used default value, maybe invalid.
#endif /* CONFIG_HISFC300NEW_CHIP_NUM */

/*****************************************************************************/

#define HISFC300NEW_REG_BASE_LEN                              (0x100)
#define HISFC300NEW_PERIPHERY_REG_LEN                         (0x100)
#define HISFC300NEW_BUFFER_BASE_LEN               (0x4000000) /* 64MB */

#define HISFC300_MAX_READY_WAIT_JIFFIES        (40 * HZ)
/*****************************************************************************/
/* this function only for debug, reg read is slower then dma read */
#undef CONFIG_HISFC300NEW_SHOW_CYCLE_TIMING

#define HISFC300_GLOBAL_CONFIG                         0x0100
#define HISFC300_GLOBAL_CONFIG_READ_DELAY(_n)      (((_n) & 0x03) << 3)
#define HISFC300_GLOBAL_CONFIG_ADDR_MODE_4B        (1 << 2)
#define HISFC300_GLOBAL_CONFIG_WRITE_PROTECT       (1 << 1)
#define HISFC300_GLOBAL_CONFIG_SPI_MODE3           (1 << 0)

#define HISFC300_TIMING					0x0110
#define HISFC300_TIMING_TSHSL(_n)			((_n) & 0xF)
#define HISFC300_TIMING_TCSS(_n)			(((_n) & 0x7) << 8)
#define HISFC300_TIMING_TCSH(_n)			(((_n) & 0x7) << 12)
#define HISFC300_VERSION				(0x01F8)
#define HISFC300_VERSION_VERSION(_n)                  ((_n) & 0x0FFFF)

#define HISFC300_VERSION_SEL				0x01FC
#define HISFC300_VERSION_SEL_SEL(_n)		 ((_n) & 0x1)
#define HISFC300_BUS_CONFIG1                           0x0200
#define HISFC300_BUS_CONFIG1_READ_EN             (1<<31)
#define HISFC300_BUS_CONFIG1_WRITE_EN            (1<<30)
#define HISFC300_BUS_CONFIG1_WRITE_INS(_n)       ((_n & 0xFF) << 22)
#define HISFC300_BUS_CONFIG1_WRITE_DUMMY_CNT(_n) ((_n & 0x7) << 19)
#define HISFC300_BUS_CONFIG1_WRITE_IF_TYPE(_n)   ((_n & 0x7) << 16)
#define HISFC300_BUS_CONFIG1_READ_INS(_n)        ((_n & 0xFF) << 8)
#define HISFC300_BUS_CONFIG1_READ_PREF_CNT(_n)   ((_n & 0x3) << 6)
#define HISFC300_BUS_CONFIG1_READ_DUMMY_CNT(_n)  ((_n & 0x7) << 3)
#define HISFC300_BUS_CONFIG1_READ_IF_TYPE(_n)    (_n & 0x7)

#define HISFC300_BUS_CONFIG2                           0x0204
#define HISFC300_BUS_CONFIG2_WIP_LOCATE(_n)    (_n & 0x7)

#define HISFC300_BUS_FLASH_SIZE                        0x0210
#define HISFC300_BUS_FLASH_SIZE_CS0_MASK         0x0F
#define HISFC300_BUS_FLASH_SIZE_CS1_MASK         (0x0F << 8)
#define HISFC300_BUS_BASE_ADDR_CS0                     0x0214
#define HISFC300_BUS_BASE_ADDR_CS1                     0x0218
#define HISFC300_BUS_ALIAS_ADDR                        0x021C
#define HISFC300_BUS_ALIAS_CS                          0x0220
#define HISFC300_CMD_CONFIG                            0x0300
#define HISFC300_CMD_CONFIG_MEM_IF_TYPE(_n)        (((_n) & 0x07) << 17)
#define HISFC300_CMD_CONFIG_DATA_CNT(_n)           (((_n - 1) & 0x3F) << 9)
#define HISFC300_CMD_CONFIG_RW_READ                (1<<8)
#define HISFC300_CMD_CONFIG_DATA_EN                (1<<7)
#define HISFC300_CMD_CONFIG_DUMMY_CNT(_n)          (((_n) & 0x07) << 4)
#define HISFC300_CMD_CONFIG_ADDR_EN                (1<<3)
#define HISFC300_CMD_CONFIG_SEL_CS(_cs)            (((_cs) & 0x01) << 1)
#define HISFC300_CMD_CONFIG_START                  (1<<0)

#define HISFC300_CMD_INS                               0x0308
#define HISFC300_CMD_ADDR                              0x030C
#define HISFC300_CMD_ADDR_MASK                     0x3FFFFFFF
#define HISFC300_CMD_DATABUF0                          0x0400
#define HISFC300_CMD_DATABUF15                         0x043C

#define SPI_CMD_SR_QE			(0x1<<9) /* quad enable */

#define HISFC300_IFCYCLE_STD           0
#define HISFC300_IFCYCLE_DUAL          1
#define HISFC300_IFCYCLE_DUAL_ADDR     2
#define HISFC300_IFCYCLE_DUAL_CMD      3
#define HISFC300_IFCYCLE_QUAD          5
#define HISFC300_IFCYCLE_QUAD_ADDR     6
#define HISFC300_IFCYCLE_QUAD_CMD      7

#define HISFC300_REG_BUF_SIZE \
	(HISFC300_CMD_DATABUF15 - HISFC300_CMD_DATABUF0 + 0x04)
#define HISFC300_REG_BUF_MASK                 (HISFC300_REG_BUF_SIZE - 1)

#undef  READ
#define READ           1

#undef  WRITE
#define WRITE          0

#undef  FALSE
#define FALSE          0

#undef  TRUE
#define TRUE           1

/*****************************************************************************/
struct hisfc_spi {
	char *name;
	int chipselect;
	unsigned long long chipsize;
	unsigned int erasesize;
	void __iomem *iobase;

	unsigned int addrcycle;
	struct spi_operation  read[1];
	struct spi_operation  write[1];
	struct spi_operation  erase[MAX_SPI_OP];
};


struct hisfc300_host {
	struct mtd_info   mtd[1];
	void __iomem     *iobase;
	void __iomem     *regbase;
	struct device    *dev;
	struct mutex      lock;
	void __iomem     *sysreg;

	int add_partition;
	int num_chip;
	struct hisfc_spi spi[CONFIG_HISFC300NEW_CHIP_NUM+1];

	int (*suspend)(struct platform_device *pltdev, pm_message_t state);
	int (*resume)(struct platform_device *pltdev);
};

#define MTD300_TO_HOST(_mtd)               ((struct hisfc300_host *)(_mtd))
/*****************************************************************************/
#define hisfc300_read(_host, _reg) \
		readl((unsigned)((char *)_host->regbase + (_reg)))

#define hisfc300_write(_host, _reg, _value) \
		writel((unsigned)(_value), \
			(unsigned)((char *)_host->regbase + (_reg)))

#define HISFC300_CMD_WAIT_CPU_FINISH(_host) do {\
		unsigned int timeout = 0x10000000; \
		while (((hisfc300_read((_host), HISFC300_CMD_CONFIG) \
				& HISFC300_CMD_CONFIG_START)) && timeout) \
			--timeout; \
			if (!timeout) \
				DBG_BUG("cmd wait cpu finish timeout\n"); \
	} while (0)
/*****************************************************************************/
#if 0
#  define DBG_MSG(_fmt, arg...)
#else
#  define DBG_MSG(_fmt, arg...) \
	printk(KERN_INFO "%s(%d): " _fmt, __FILE__, __LINE__, ##arg);
#endif

#define DBG_WARN(_fmt, arg...) \
	printk(KERN_INFO "%s(%d): " _fmt, __FILE__, __LINE__, ##arg);

#define DBG_BUG(fmt, args...) do {\
	printk(KERN_ERR "%s(%d): BUG: " fmt, __FILE__, __LINE__, ##args); \
	while (1) \
		; \
} while (0)
/*****************************************************************************/
#ifndef NULL
#  define NULL         (void *)0
#endif
/*****************************************************************************/
extern void hisfc300_set_system_clock(struct hisfc300_host *host,
		struct spi_operation *op, int clk_en);

extern void hisfc300_get_best_clock(unsigned int *clock);

#ifdef CONFIG_HISFC300NEW_SHOW_CYCLE_TIMING
char *hisfc300_get_clock_str(unsigned int clk_reg)
#endif /* CONFIG_HISFC300NEW_SHOW_CYCLE_TIMING */

#endif /* HISFC300H */
