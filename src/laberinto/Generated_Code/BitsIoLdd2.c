/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : BitsIoLdd2.c
**     Project     : laberinto
**     Processor   : MKE06Z128VLK4
**     Component   : BitsIO_LDD
**     Version     : Component 01.029, Driver 01.05, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-06-08, 16:12, # CodeGen: 37
**     Abstract    :
**         The HAL BitsIO component provides a low level API for unified
**         access to general purpose digital input/output 32 pins across
**         various device designs.
**
**         RTOS drivers using HAL BitsIO API are simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : BitsIoLdd2
**          Port                                           : GPIOB
**          Pins                                           : 2
**            Pin0                                         : 
**              Pin                                        : PTH3/KBI1_P27/I2C1_SDA
**            Pin1                                         : 
**              Pin                                        : PTH4/KBI1_P28/I2C1_SCL
**          Direction                                      : Input
**          Initialization                                 : 
**            Init. direction                              : Input
**            Init. value                                  : 0
**            Auto initialization                          : yes
**          Safe mode                                      : yes
**     Contents    :
**         Init   - LDD_TDeviceData* BitsIoLdd2_Init(LDD_TUserData *UserDataPtr);
**         GetDir - bool BitsIoLdd2_GetDir(LDD_TDeviceData *DeviceDataPtr);
**         GetVal - uint32_t BitsIoLdd2_GetVal(LDD_TDeviceData *DeviceDataPtr);
**         GetBit - LDD_TError BitsIoLdd2_GetBit(LDD_TDeviceData *DeviceDataPtr, uint8_t Bit,...
**
**     (c) 2012 by Freescale
** ###################################################################*/
/*!
** @file BitsIoLdd2.c
** @version 01.05
** @brief
**         The HAL BitsIO component provides a low level API for unified
**         access to general purpose digital input/output 32 pins across
**         various device designs.
**
**         RTOS drivers using HAL BitsIO API are simpler and more
**         portable to various microprocessors.
*/         
/*!
**  @addtogroup BitsIoLdd2_module BitsIoLdd2 module documentation
**  @{
*/         

/* MODULE BitsIoLdd2. */

/* {Default RTOS Adapter} No RTOS includes */
#include "BitsIoLdd2.h"

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TUserData *UserDataPtr;          /* Pointer to user data */
} BitsIoLdd2_TDeviceData;              /* Device data structure type */

typedef BitsIoLdd2_TDeviceData *BitsIoLdd2_TDeviceDataPtr ; /* Pointer to the device data structure. */

static const uint32_t BitsIoLdd2_PIN_MASK_MAP[2U] = {
   0x08000000U, 0x10000000U
};                                     /* Map of masks for each pin */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static BitsIoLdd2_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;


/*
** ===================================================================
**     Method      :  BitsIoLdd2_Init (component BitsIO_LDD)
*/
/*!
**     @brief
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     @param
**         UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* BitsIoLdd2_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  BitsIoLdd2_TDeviceDataPtr DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Configure pin directions */
  /* GPIOB_PDDR: PDD&=~0x18000000 */
  GPIOB_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x18000000));
  /* GPIOB_PIDR: PID&=~0x18000000 */
  GPIOB_PIDR &= (uint32_t)~(uint32_t)(GPIO_PIDR_PID(0x18000000));
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_BitsIoLdd2_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  BitsIoLdd2_GetDir (component BitsIO_LDD)
*/
/*!
**     @brief
**         Returns the selected direction.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Possible values:
**                           [false] - Input
**                           [true] - Output
*/
/* ===================================================================*/
bool BitsIoLdd2_GetDir(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  return (bool)FALSE;                  /* Pin is fixed to GPI mode */
}

/*
** ===================================================================
**     Method      :  BitsIoLdd2_GetVal (component BitsIO_LDD)
*/
/*!
**     @brief
**         Returns the value of the Input/Output component. If the
**         direction is [input] then reads the input value of the pins
**         and returns it. If the direction is [output] then returns
**         the last written value (see [Safe mode] property for
**         limitations).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Input value
*/
/* ===================================================================*/
uint32_t BitsIoLdd2_GetVal(LDD_TDeviceData *DeviceDataPtr)
{
  uint32_t PortData;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  PortData = GPIO_PDD_GetPortDataInput(BitsIoLdd2_MODULE_BASE_ADDRESS) & BitsIoLdd2_PORT_MASK;
  return PortData >> BitsIoLdd2_PIN_ALLOC_0_INDEX; /* Return port data shifted with the offset of the first allocated pin*/
}

/*
** ===================================================================
**     Method      :  BitsIoLdd2_GetBit (component BitsIO_LDD)
*/
/*!
**     @brief
**         Returns the value of the specified bit/pin of the
**         Input/Output component. If the direction is [input] then it
**         reads the input value of the pin and returns it. If the
**         direction is [output] then it returns the last written value
**         (see [Safe mode] property for limitations).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         Bit             - Bit/pin number to read
**     @param
**         BitVal          - The returned value: 
**                           [false] - logical "0" (Low level)
**                           [true] - logical "1" (High level)
**     @return
**                         - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_INDEX - Invalid pin index
**                           ERR_PARAM_VALUE - Invalid output parameter
*/
/* ===================================================================*/
LDD_TError BitsIoLdd2_GetBit(LDD_TDeviceData *DeviceDataPtr, uint8_t Bit, bool *BitVal)
{
  uint32_t Mask = 0;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Bit number value - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (Bit > 1U) {
    return ERR_PARAM_INDEX;
  }
  /* Bit value returned - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (BitVal == NULL) {
    return ERR_PARAM_VALUE;
  }
  Mask = BitsIoLdd2_PIN_MASK_MAP[Bit];
  if ((GPIO_PDD_GetPortDataInput(BitsIoLdd2_MODULE_BASE_ADDRESS) & Mask) != 0U) {
    *BitVal = (bool)TRUE;
  } else {
    *BitVal = (bool)FALSE;
  }
  return ERR_OK;
}

/* END BitsIoLdd2. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/