/**
@file zwapi_cmd_udf_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the UDF
functions.
*/
/**
@defgroup zwapi_cmd_udf_data UDF Data
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the UDF
functions.
*/

#pragma once
#ifndef ZW_API_UDF_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_UDF_DATA_H

#include "zwapi_cmd_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name UDF Creation Data */
    //====================================================================================================================
    /**
    @brief field parameters of UDF command
    @ingroup zwapi_cmd_udf_data
    */
    typedef struct svxUDFParam
    {
        int fld_id;             /**<@brief  id of field */
        int is_list;            /**<@brief  1- is list, else 0 */
        evxFldType fld_type;    /**<@brief  type  of  field */
        vxLongName description; /**<@brief  description of parameter, use to set the different data */
    } svxUDFParam;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_UDF_H */
