/*
 * led_base.h
 *
 *  Created on: Dec 26, 2020
 *      Author: javi
 */

#ifndef LED_BASE_H_
#define LED_BASE_H_

class led_base{
public:

	virtual void toggle() = 0;	// pure abstract
	virtual ~led_base() {}		// virtual destructor

	// interface for querying the LED state
	bool state_is_on() const { return is_on;}

protected:
	bool is_on;

	// a prtotected default contructor
	led_base() : is_on(false){	}

private:
	// private non-implemented copy constructor
	led_base(const led_base&) = delete;

	// private non-implemented copy assignment operator
	const led_base& operator=(const led_base&) = delete;
};



#endif /* LED_BASE_H_ */
