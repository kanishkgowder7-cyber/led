/*
 * led_driver.h
 *
 *  Created on: Oct 8, 2026
 *      Author: Jeetesh
 */

#ifndef INC_LED_H_
#define INC_LED_H_
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void led()
{
	struct led
	{
		int ledno;
		int *status;
	};
	GPIO_TypeDef *led[]={GPIOB,GPIOE,GPIOB};
	uint16_t pin[]={GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_14};
	int m,n;
	printf("enter number of LEDs and number of times to be toggled: ");
	scanf("%d %d",&n,&m);
	struct led *l=malloc(n*sizeof(struct led));
	for(int i=0;i<n;i++)
	{
		l[i].ledno=i+1;
		l[i].status=malloc(sizeof(int));
		*l[i].status=0;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			HAL_GPIO_TogglePin(led[i],pin[i]);
			HAL_Delay(100);
			*l[i].status=!(*l[i].status);
			HAL_GPIO_TogglePin(led[i],pin[i]);
			HAL_Delay(100);
			*l[i].status=!(*l[i].status);
		}
	}
	for (int i = 0; i < n; i++)
		free(l[i].status);
    free(l);
}
#endif /* INC_LED_H_ */
