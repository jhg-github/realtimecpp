/*
 * pwm.h
 *
 *  Created on: Dec 27, 2020
 *      Author: javi
 */

#ifndef PWM_H_
#define PWM_H_

#include <cstdint>
#include <algorithm>


class pwm {
public:
	explicit pwm(TIM_HandleTypeDef * const htim, const std::uint32_t Channel) : htim(htim), channel(Channel), duty_cycle(0U) {
		set_duty(duty_cycle);
	}

	~pwm() {}

	void start() const {
		HAL_TIM_PWM_Start(htim, channel);
	}

	void set_duty(const std::uint8_t duty){
		duty_cycle = std::min<std::uint8_t>(duty, 100U);
		__HAL_TIM_SET_COMPARE(htim, channel, duty);
	}

	std::uint8_t get_duty() const{
		return duty_cycle;
	}

private:
	TIM_HandleTypeDef * const htim;
	const std::uint32_t channel;
	std::uint8_t duty_cycle;
};


#endif /* PWM_H_ */
