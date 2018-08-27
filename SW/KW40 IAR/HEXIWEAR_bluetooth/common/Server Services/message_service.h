/**
 *    @file message_service.h
 */

#ifndef _MESSAGE_SERVICE_H_
#define _MESSAGE_SERVICE_H_

#include "host_mcu_interface.h"

/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/

/**
 *    Start service.
 *
 *    @return      gBleSuccess_c
 */
bleResult_t Msg_Start (void);

/**
 *    Stop service.
 *
 *    @return      gBleSuccess_c
 */
bleResult_t Msg_Stop (void);

/**
 *    Subscribe service.
 *
 *    @param    clientDeviceId   Client Device ID.
 *
 *    @return                    gBleSuccess_c
 */
bleResult_t Msg_Subscribe(deviceId_t clientDeviceId);

/**
 *    Unsubscribe device.
 *
 *    @return      gBleSuccess_c
 */
bleResult_t Msg_Unsubscribe(void);

/**
 *    Record characteristic value.
 *
 *    @param    data   Data to be recorded.
 *
 *    @return          gBleSuccess_c or error
 */
bleResult_t Msg_RecordOutMessage(uint8_t *data);

/**
 *    Send received data to host MCU.
 *
 *    @param    data   Received data.
 *
 *    @return          gBleSuccess_c or error
 */
bleResult_t Msg_HandleInMessage(uint8_t * data);

#endif /*_MESSAGE_SERVICE_H_ */

/*! *********************************************************************************
 * @}
 ********************************************************************************** */

