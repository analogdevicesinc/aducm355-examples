/*! *****************************************************************************
 * \brief: Implements bootloader for the Palmsens Measurement Firmware
 * @version  V0.1
 * @author   Analog Devices
 * @date     July 2018

   Copyright (c) 2018 Analog Devices, Inc.  All Rights Reserved.
   This software is proprietary and confidential to Analog Devices, Inc. and its licensors

*****************************************************************************/

#define ATTRIBUTE_INTERRUPT
#define WEAK_PROTO(proto)              __weak proto
#define WEAK_FUNC(func)                __weak func
#define WEAK_PROTOTYPE(x) WEAK_PROTO ( void x (void)) ATTRIBUTE_INTERRUPT ;
#define WEAK_FUNCTION(x)  WEAK_FUNC  ( void x (void)) { while(1); }

// #define WRITEPROTECT_BOOTLOADER
// #define DISABLE_SERIALWIRE

#include <stddef.h>     /* for 'NULL' */
#include <adi_types.h>
#include <ADuCM355.h>

typedef void  ( *IntFunc )( void );
typedef void  ( *ADIIntFunc )( void );

typedef union
{
    ADIIntFunc __fun;
    void *__ptr;
    IntFunc __ifunc;
} IntVector;

WEAK_FUNCTION( NmiSR                    )
WEAK_FUNCTION( HardFault_Handler        )
WEAK_FUNCTION( MemManage_Handler        )
WEAK_FUNCTION( RESERVED_VECTOR              )

WEAK_PROTOTYPE( ResetISR                  )

extern uint32_t FINAL_CRC_PAGE;  /* Linker Symbol */

// Interrupt Vector Table
#pragma segment="CSTACK"
#pragma location = ".intvec"
const IntVector __vector_table[] =
{
    // grab stack pointer "end" address from ICF file
    { .__ptr = __sfe( "CSTACK" ) },

    // exception mappings...
    { .__ifunc = ResetISR                 },   /* -15 */
    { .__ifunc = NmiSR                    },   /* -14 */
    { .__ifunc = HardFault_Handler        },   /* -13 */
    { .__ifunc = RESERVED_VECTOR          },   /* -12 */
    { .__ifunc = RESERVED_VECTOR          },   /* -11 */
    { .__ifunc = RESERVED_VECTOR          },   /* -10 */
    { .__ifunc = RESERVED_VECTOR          },   /* -09 */
    { .__ifunc = RESERVED_VECTOR          },   /* -08 */
    { .__ifunc = RESERVED_VECTOR          },   /* -07 */
    { .__ifunc = RESERVED_VECTOR          },   /* -06 */
    { .__ifunc = RESERVED_VECTOR          },   /* -05 */
    { .__ifunc = RESERVED_VECTOR          },   /* -04 */
    { .__ifunc = RESERVED_VECTOR          },   /* -03 */
    { .__ifunc = RESERVED_VECTOR          },   /* -02 */
    { .__ifunc = RESERVED_VECTOR          },   /* -01 */
} ;

#pragma location="ReadProtectedKeyHash"
#ifdef DISABLE_SERIALWIRE
__root const uint32_t ReadProKeyHsh[] = { 0x12345678, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#else
__root const uint32_t ReadProKeyHsh[] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#endif

#pragma location="CRC_ReadProtectedKeyHash"
__root const uint32_t CrcOfReadKey = 0xA79C3203;

#pragma location="FinalCRCPage"
__root const uint32_t FinalCRCPage = (uint32_t)&FINAL_CRC_PAGE;


#pragma location="WriteProtect"
#ifdef WRITEPROTECT_BOOTLOADER
__root const uint32_t WriteProtection = (uint32_t)0xFFFFFFFE;
#else
__root const uint32_t WriteProtection = (uint32_t)0xFFFFFFFF;
#endif
/*The pages are protected in groups of four, with each bit
in the 32-bit word corresponding to four continuous flash
pages*/

//*****************************************************************************
//
// Application Entry point
//
//*****************************************************************************
extern int main(void);


//*****************************************************************************
// IAR system startup functions.
//*****************************************************************************
WEAK_PROTO( void __iar_init_core (void));
WEAK_PROTO( void __iar_init_vfp  (void));
extern      void __cmain();

//*****************************************************************************
// Function    : ResetISR (-15)
// Description : Reset event handler
//*****************************************************************************

WEAK_FUNC (void ResetISR (void))
{
    // Call IAR system startup
    __iar_init_core();
    __iar_init_vfp();

    __cmain();

    // Stick here if main returns
    while(1);
}