/**
@file zwapi_cmd_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Command
Container and Command Parameter.
*/
/**
@defgroup zwapi_cmd_data Command Data
@ingroup CommandParameters
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Command
Container and Command Parameter.
*/

#pragma once
#ifndef ZW_API_CMD_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_CMD_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

//====================================================================================================================
/** @name Command Operation Data */
//====================================================================================================================
/*  command license codes */
#define VX_CODE_GENERAL 0.0
#define VX_CODE_ADV_RENDERING 1.0
#define VX_CODE_ASSEMBLY 2.0
#define VX_CODE_ADV_ASSEMBLY 17179869184.0
#define VX_CODE_DRAFTING 4.0
#define VX_CODE_WIREFRAME 8589934592.0
#define VX_CODE_MODELING 512.0
#define VX_CODE_ADV_MODELING 34359738368.0
#define VX_CODE_ADV_SURF 256.0
#define VX_CODE_MOLD_DESIGN 1024.0
#define VX_CODE_HEALING 4294967296.0
#define VX_CODE_POST 2199023255552.0
#define VX_CODE_KEYSHOT 576460752303423488.0
#define VX_CODE_ELECTRODE 1152921504606846976.0
#define VX_CODE_PARTSOLUTIONS 32768.0
#define VX_CODE_MISUMI VX_CODE_GENERAL

    /**
    @brief command action type
    @ingroup zwapi_cmd_data
    */
    typedef enum evxCmdAction
    {
        VX_CMD_START = 0, /**<@brief  called before command start */
        VX_CMD_FINISHED,  /**<@brief  called after command finished (notify only) */
    } evxCmdAction;

    /**
    @brief command state type
    @ingroup zwapi_cmd_data
    */
    typedef enum evxCmdState
    {
        VX_CMD_ENABLE  = 0, /**<@brief  command state type: enable */
        VX_CMD_DISABLE = 1, /**<@brief  command state type: disable */
    } evxCmdState;

    /**
    @brief command action parameter
    @ingroup zwapi_cmd_data
    */
    typedef struct svxCmdActionParam
    {
        int (*pfn)(void *param, const char *); /**<@brief callback function, the 2nd parameter is the command name */
        void *param;                           /**<@brief parameter */
    } svxCmdActionParam;

    /**
    @brief command types
    @ingroup zwapi_cmd_data
    */
    typedef enum evxCmdType
    {
        VX_STANDARD_COMMAND  = -1, /**<@brief  non-history command */
        VX_HIST_GENERAL      = 0,  /**<@brief  general-purpose history operation */
        VX_HIST_SOLID_CREATE = 11, /**<@brief  "solid create" history operation */
        VX_HIST_SOLID_EDIT   = 12, /**<@brief  "solid edit" history operation */
        VX_HIST_SURF_CREATE  = 13, /**<@brief  "surface create" history operation */
        VX_HIST_SURF_EDIT    = 14, /**<@brief  "surface edit" history operation */
        VX_HIST_CRV_CREATE   = 15, /**<@brief  "curve create" history operation */
        VX_HIST_CRV_EDIT     = 16, /**<@brief  "curve edit" history operation */
        VX_HIST_COMP         = 17, /**<@brief  "component" history operation */
        VX_HIST_SKETCH       = 18, /**<@brief  "sketch" history operation */
        VX_HIST_DATUM        = 19, /**<@brief  "datum" history operation */
        VX_HIST_FILLET       = 20, /**<@brief  "fillet/chamfer" history operation */
        VX_HIST_SHELL        = 21, /**<@brief  "shell" history operation */
        VX_HIST_SHT_METAL    = 22, /**<@brief  "sheet metal" history operation */
        VX_HIST_HOLE         = 23, /**<@brief  "hole" history operation */
        VX_HIST_CRV_LIST     = 24, /**<@brief  "curve list" history operation */
        VX_HIST_IMPORT       = 25, /**<@brief  "import" history operation */
        VX_HIST_REF_GEOM     = 26, /**<@brief  "reference geometry" history operation */
        VX_HIST_EQN          = 27, /**<@brief  "equation" history operation */
        VX_HIST_HEAL         = 28, /**<@brief  "heal" history operation */
        VX_HIST_ERASE        = 29, /**<@brief  "erase" history operation */
        VX_HIST_BLANK        = 30, /**<@brief  "blank/unblank" history operation */
        VX_HIST_ATTRIBUTE    = 33, /**<@brief  "attributes" history operation */
        VX_HIST_RENDER       = 34, /**<@brief  "rendering" history operation */
        VX_HIST_ANALYZE      = 35, /**<@brief  "analyze" history operation */
        VX_HIST_MOVE         = 37, /**<@brief  "copy/move/pattern" history operation */
        VX_HIST_TEXT         = 38, /**<@brief  "text" history operation */
        VX_HIST_POINT        = 39, /**<@brief  "point" history operation */
        VX_HIST_DRAFT        = 40, /**<@brief  "draft" history operation */
        VX_HIST_ASSEMBLY     = 41, /**<@brief  "assembly" history operation */
        VX_HIST_TAG          = 42, /**<@brief  "tag" history operation */
        VX_HIST_MOLD         = 43  /**<@brief  "mold design" history operation */
    } evxCmdType;

    //====================================================================================================================
    /** @name Data Get Data */
    //====================================================================================================================
    /**
    @brief numeric input field type
    @ingroup zwapi_cmd_data
    */
    typedef enum evxFldNumType
    {
        VX_INP_DOUBLE   = 0, /**<@brief  double */
        VX_INP_INTEGER  = 1, /**<@brief  int */
        VX_INP_DISTANCE = 2, /**<@brief  distance */
        VX_INP_ANGLE    = 3  /**<@brief  angle */
    } evxFldNumType;

    /**
    @brief point input data types
    @ingroup zwapi_cmd_data
    */
    typedef enum evxFldType
    {
        VX_FLD_NULL = 0, /**<@brief  NULL if error */
        VX_FLD_NUM  = 1, /**<@brief  dimensionless number */
        VX_FLD_DST  = 2, /**<@brief  distance (mm) */
        VX_FLD_ANG  = 3, /**<@brief  angle (radians) */
        VX_FLD_PNT  = 4, /**<@brief  3D point */
        VX_FLD_ENT  = 5, /**<@brief  entity pick */
        VX_FLD_TXT  = 6, /**<@brief  text */
        VX_FLD_DATA = 7, /**<@brief  data container (i.e. VDATA) */
    } evxFldType;

    /**
    @brief field data
    @ingroup zwapi_cmd_data
    */
    typedef struct svxFldData
    {
        int fld_id;          /**<@brief  id of field */
        vxLongName fld_name; /**<@brief  name of field (i.e. label, maybe is empty string) */
        evxFldType fld_type; /**<@brief  type of field */
        int count;           /**<@brief  number of field data */
        svxData *fld_data;   /**<@brief  list of field data */
    } svxFldData;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_CMD_DATA_H */
