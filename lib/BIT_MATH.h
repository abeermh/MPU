#ifndef _BIT_MATH_H  			//header guared
#define _BIT_MATH_H

#define SET_BIT( REG,BIT_NUM)  REG|=(1<<BIT_NUM)
#define CLR_BIT( REG,BIT_NUM)		REG&=(~(1<<BIT_NUM))
#define TOGGLE_BIT( REG,BIT_NUM)		REG^=(1<<BIT_NUM)
#define GET_BIT( REG,BIT_NUM)		((REG>>BIT_NUM)&1)

#endif
