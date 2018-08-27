/**
 *    @file message_service.c
 */

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/

#include "ble_general.h"
#include "gatt_db_app_interface.h"
#include "gatt_server_interface.h"
#include "gap_interface.h"
#include "battery_interface.h"
#include "gatt_uuid_decl_x.def"
#include "gatt_db_handles.h"
#include "FunctionLib.h"
#include "fsl_lpuart_driver.h"

#include "message_service.h"
#include "common_service.h"


/************************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
************************************************************************************/

/*! Message Service - Subscribed Client*/
static deviceId_t mMsg_SubscribedClientId;

/************************************************************************************
*************************************************************************************
* Public Functions definitions
*************************************************************************************
********************************************************************************** */

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/**
 *    Start service.
 *
 *    @return      gBleSuccess_c
 */

bleResult_t Msg_Start (void)
{
    return gBleSuccess_c;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/**
 *    Stop service.
 *
 *    @return      gBleSuccess_c
 */

bleResult_t Msg_Stop(void)
{
    mMsg_SubscribedClientId = gInvalidDeviceId_c;
    return gBleSuccess_c;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/**
 *    Subscribe service.
 *
 *    @param    clientDeviceId   Client Device ID.
 *
 *    @return                    gBleSuccess_c
 */

bleResult_t Msg_Subscribe(deviceId_t clientDeviceId)
{
    mMsg_SubscribedClientId = clientDeviceId;
    return gBleSuccess_c;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/**
 *    Unsubscribe device.
 *
 *    @return      gBleSuccess_c
 */

bleResult_t Msg_Unsubscribe(void)
{
    mMsg_SubscribedClientId = gInvalidDeviceId_c;
    return gBleSuccess_c;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/**
 *    Record characteristic value.
 *
 *    @param    data   Data to be recorded.
 *
 *    @return          gBleSuccess_c or error
 */

bleResult_t Msg_RecordOutMessage(uint8_t * data)
{
    bleResult_t result;
    
    result = CommonService_RecordCharValue(mMsg_SubscribedClientId, service_message, gBleCustom_MessageOutUUID_d,  data, gBleCustom_MessageOutLength_d);
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/**
 *    Send received data to host MCU.
 *
 *    @param    data   Received data.
 *
 *    @return          gBleSuccess_c or error
 */

bleResult_t Msg_HandleInMessage(uint8_t * data)
{
    static hostInterface_packet_t tmpPacket;
    
    tmpPacket.type = packetType_messageIn;
    tmpPacket.length = gBleCustom_MessageInLength_d;
    tmpPacket.data[gBleCustom_MessageInLength_d] = gHostInterface_trailerByte;
    
    FLib_MemCpy(tmpPacket.data, data, gBleCustom_MessageInLength_d);
    
    return (bleResult_t)HostInterface_TxQueueMsgPut((hostInterface_packet_t *)&tmpPacket, true);
}

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
