
#ifndef SRC_GENERALDEF_H_
#define SRC_GENERALDEF_H_

/************************************ includes *******************************/
#include <stdint.h>

/********************************* macros ************************************/
/* Useful general-purpose macros */
#define UNUSED(x) ((void)(x))
#define ATTR_UNUSED(x) (x) __attribute__((unused))

#define ELEMENTS(vector) (sizeof(vector) / sizeof((vector)[0]))

#define MAKE_UINT16_T(high, low) (((((uint16_t)(high)) & 0xff) << 8) + (((uint16_t)(low)) & 0xff))
#define MAKE_INT16_T(high, low) (((((int16_t)(high)) & 0xff) << 8) + (((int16_t)(low)) & 0xff))

#define LOW_BYTE(w) ((uint8_t)(((uint16_t)(w)) & 0xff))
#define HIGH_BYTE(w) ((uint8_t)((((uint16_t)(w)) >> 8) & 0xff))

#define LOW_WORD(w) ((uint16_t)(((uint32_t)(w)) & 0xffff))
#define HIGH_WORD(w) ((uint16_t)((((uint32_t)(w)) >> 16) & 0xffff))

#define HTONS(x) ((uint16_t)((((x) >> 8) & 0xff) | (((x)&0xff) << 8)))

#define readRegister(base, offset) (*((volatile uint32_t*)((base) + (offset))))
#define writeRegister(base, offset, data) (*((volatile uint32_t*)((base)+(offset))) = (data))

#endif /* SRC_GENERALDEF_H_ */
