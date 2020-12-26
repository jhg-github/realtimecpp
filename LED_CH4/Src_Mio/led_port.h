/*
 * led_port.h
 *
 *  Created on: Dec 26, 2020
 *      Author: javi
 */

#ifndef LED_PORT_H_
#define LED_PORT_H_

#include <cstdint>
#include "led_base.h"
//#include <mcal.h>

class led_port : public led_base{
public:
	typedef std::uint32_t port_odr_type;
	typedef std::uint32_t bval_type;

	led_port(const port_odr_type p, const bval_type b)
			: port_odr(p), bval(b){
		// set pin to low
		*reinterpret_cast<volatile bval_type*>(port_odr) &= static_cast<bval_type>(~bval);
	}

	virtual ~led_port() {}

	virtual void toggle() {
		*reinterpret_cast<volatile bval_type*>(port_odr) ^= bval;
		is_on = !is_on;
	}

private:
	const port_odr_type port_odr;
	const bval_type bval;
};


#endif /* LED_PORT_H_ */
