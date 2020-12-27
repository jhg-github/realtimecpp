/*
 * mcal.h
 *
 *  Created on: Dec 26, 2020
 *      Author: javi
 */

#ifndef MCAL_H_
#define MCAL_H_

#include <cstdint>

namespace mcal
  {
    namespace reg
    {
    	constexpr std::uint32_t odr_offset = UINT32_C(0x14);

		constexpr std::uint32_t porta = GPIOA_BASE;
		constexpr std::uint32_t porta_odr = static_cast<std::uint32_t>(porta + odr_offset);

		constexpr std::uint32_t portb = GPIOB_BASE;
		constexpr std::uint32_t portb_odr = static_cast<std::uint32_t>(portb + odr_offset);

		constexpr std::uint32_t bval0 = 0x01U;
		constexpr std::uint32_t bval1 = 0x01U << 1U;
		constexpr std::uint32_t bval2 = 0x01U << 2U;
		constexpr std::uint32_t bval3 = 0x01U << 3U;
		constexpr std::uint32_t bval4 = 0x01U << 4U;
		constexpr std::uint32_t bval5 = 0x01U << 5U;
		constexpr std::uint32_t bval6 = 0x01U << 6U;
		constexpr std::uint32_t bval7 = 0x01U << 7U;
		constexpr std::uint32_t bval8 = 0x01U << 8U;
		constexpr std::uint32_t bval9 = 0x01U << 9U;
		constexpr std::uint32_t bval10 = 0x01U << 10U;
    }
  }

#endif /* MCAL_H_ */
