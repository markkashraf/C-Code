/*
 * utils.h
 *
 * Created: 9/7/2023 3:51:01 PM
 *  Author: Mark
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(REGISTER,BIT) REGISTER |= (1<<BIT)
#define RESET_BIT(REGISTER,BIT) REGISTER &= ~(1<<BIT)
#define TOGGLE_BIT(REGISTER,BIT) REGISTER ^= (1<<BIT)
#define READ_BIT(REGISTER,BIT) (REGISTER & (1<<BIT)) >> BIT



#endif /* UTILS_H_ */