/**
@file zwapi_cm_forms.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE API of the Cam Forms.
*/
/**
@defgroup zwapi_cm_forms Cam Forms API
@ingroup CamModel
@brief
@details THE MODULE FOR THE API of the Cam Forms.
*/

#pragma once
#ifndef ZW_API_CAM_FORM_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_FORM_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Forms Data */
    //====================================================================================================================
    /**
    @brief cam nc output setting
    @ingroup zwapi_cm_forms
    */
    typedef struct svxNcSetting
    {
        vxName machine;
        char filename[512];
        vxName part_id;
        vxName programmer;
        vxName space;
        vxName tool_changes;
        vxName spd_fd;
        vxName tool_num;
        vxName coolant;
        char prog_comment[256];
    } svxNcSetting;

    /**
    @brief cam output folder type
    @ingroup zwapi_cm_forms
    */
    typedef enum evxCmOutFldType
    {
        CM_OUTFLD_FLD,
        CM_OUTFLD_NC
    } evxCmOutFldType;

    /**
    @brief cam output type
    @ingroup zwapi_cm_forms
    */
    typedef enum evxCmOutType
    {
        CM_OUT_CL,
        CM_OUT_NC,
        CM_OUT_TOOL,
        CM_OUT_OP,
        CM_OUT_XML,
        CM_OUT_HTML
    } evxCmOutType;

    //====================================================================================================================
    /** @name Cam Forms Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_forms

    Modify the parameter of the clearances.

    @param [in] dClearZ Clearances Form's Clear Z
    @param [in] dAppZ Clearances Form's Approach Z
    @param [in] dRtZ Clearances Form's Retract Z
    @param [in] dAutoClear Clearances Form's Auto Clear
    @param [in] iMiniClr Clearances Form's Check the status of Auto Clear

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmSetClearance(double dClearZ, double dAppZ, double dRtZ, double dAutoClear, int iMiniClr);

    /**
    @ingroup zwapi_cm_forms

    Get the parameter of the clearances.

    @param [in] dClearZ Clearances Form's Clear Z
    @param [in] dAppZ Clearances Form's Approach Z
    @param [in] dRtZ Clearances Form's Retract Z
    @param [in] dAutoClear Clearances Form's Auto Clear
    @param [in] iMiniClr Clearances Form's Check the status of Auto Clear

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_SETVDATA_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmGetClearance(double *dClearZ, double *dAppZ, double *dRtZ, double *dAutoClear, int *iMiniClr);

    /**
    @ingroup zwapi_cm_forms

    Modify the parameter of the speed and feed .

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] FeedRough The Feed of Rough Operation
    @param [in] FeedFinish The Feed of Finish Operation
    @param [in] SpeedRough The Speed of Rough Operation
    @param [in] SpeedFinish The Speed of Finish Operation
    @param [in] pName This is the name of the operation you want to modify

    */
    extern evxErrors cvxCmSetSAndF(double FeedRough, double FeedFinish, double SpeedRough, double SpeedFinish, char *pName);

    /**
    @ingroup zwapi_cm_forms

    Output the ManHours.

    @param [in] idx_opedef  index list of operations
    @param [in] cnt  count of operations
    @param [out] manhours  manhours (in unit : second ) traveled for operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_GETTPATH_ERROR
    -        ZW_API_CAM_GETTOOL_ERROR
    -        ZW_API_CAM_GETTPATHINFO_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOutputManhours(int *idx_opedef, int cnt, double *manhours);

    /**
    @ingroup zwapi_cm_forms

    Insert a NC item or NC folder to the NC folder.

    @param [in] idx_fld index of nc folder to insert. -1:root folder of Output
    @param [out] idx_out index of nc or nc folder
    @param [in] fldType insert type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOutputInsNC(int idx_fld, int *idx_out, evxCmOutFldType fldType);

    /**
    @ingroup zwapi_cm_forms

    Delete a NC item or NC folder.

    @param [in] idx_in index of nc or nc folder
    @param [in] fldType type of nc

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOutputDelNC(int idx_in, evxCmOutFldType fldType);

    /**
    @ingroup zwapi_cm_forms

    Get attributes of the NC item. Its value is output via "ncSet".

    @param [in] idx_nc index of nc
    @param [out] ncSet attribute of nc

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETMACH_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmGetOutputNCSet(int idx_nc, svxNcSetting *ncSet);

    /**
    @ingroup zwapi_cm_forms

    Set attributes of the NC item.
    Members of ncSet should not be NULL.

    @param [in] idx_nc index of nc
    @param [in] ncSet attribute of nc

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETMACH_ERROR
    -        ZW_API_CAM_GETFORMSTATE_ERROR
    -        ZW_API_CAM_FORMDEFINE_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_CAM_GUITOTXT_ERROR
    -        ZW_API_CAM_GUIFROMTXT_ERROR
    -        ZW_API_CAM_GETFORMITEM_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmSetOutputNCSet(int idx_nc, svxNcSetting *ncSet);

    /**
    @ingroup zwapi_cm_forms

    Insert operations to the NC item.

    @param [in] idx_nc index of nc
    @param [in] cnt count of operations
    @param [in] idx_op list of operations

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOutputInsOps(int idx_nc, int cnt, int *idx_op);

    /**
    @ingroup zwapi_cm_forms

    Delete operations of the NC item.

    @param [in] idx_nc index of nc
    @param [in] cnt count of operations
    @param [in] idx_op list of operations

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOutputDelOps(int idx_nc, int cnt, int *idx_op);

    /**
    @ingroup zwapi_cm_forms

    Output files of the NC item, depends on evxCmOutType.

    @param [in] idx_nc index of nc
    @param [in] outType out type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_OUTCL_ERROR
    -        ZW_API_CAM_OUTNC_ERROR
    -        ZW_API_CAM_OUTTOOL_ERROR
    -        ZW_API_CAM_OUTOPLIST_ERROR
    -        ZW_API_CAM_OUTOPXML_ERROR
    -        ZW_API_CAM_OUTOPHTML_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOutputNC(int idx_nc, evxCmOutType outType);

    /**
    @ingroup zwapi_cm_forms

    Insert operations to the NC item.

    @param [in] op_cnt number of operations
    @param [in] idx_opList index of operations
    @param [out] idx_nc index of nc node

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_OUTNC_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmOpsOutputNc(int op_cnt, int *idx_opList, int *idx_nc);

    /**
    @ingroup zwapi_cm_forms

    Clear the output form.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxCmMsgClear();


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_FORM_H */
