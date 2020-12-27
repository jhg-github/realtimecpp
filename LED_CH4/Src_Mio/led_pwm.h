/*
 * led_pwm.h
 *
 *  Created on: Dec 27, 2020
 *      Author: javi
 */

#ifndef LED_PWM_H_
#define LED_PWM_H_


#include <cstdint>
#include "pwm.h"


class led_pwm : public led_base {
public:
	explicit led_pwm(pwm* p) : my_pwm(p) {}
	virtual ~led_pwm() {}

	void start() const {
		my_pwm->start();
	}

	virtual void toggle(){
		is_on = (my_pwm->get_duty() > 0U);
		my_pwm->set_duty(is_on ? 0U : 100U);
		is_on = !is_on;
	}

	void dimming(const std::uint8_t duty){
		my_pwm->set_duty(duty);
		is_on = (duty != 0U);
	}

private:
	pwm* my_pwm;
};



#endif /* LED_PWM_H_ */
