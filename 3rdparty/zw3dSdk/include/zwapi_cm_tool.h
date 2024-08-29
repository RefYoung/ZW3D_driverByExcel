/**
@file zwapi_cm_tool.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE API of the Cam Tool.
*/
/**
@defgroup zwapi_cm_tool Cam Tool
@ingroup CamModel
@brief
@details THE MODULE FOR THE API of the Cam Tool.
*/

#pragma once
#ifndef ZW_API_CAM_TOOL_H /* this ifndef surrounds entire header */
#define ZW_API_CAM_TOOL_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Cam Tool Data */
    //====================================================================================================================
    /**
    @brief cam tool type
    @ingroup zwapi_cm_tool
    */
    typedef enum evxCmToolType
    {
        CM_TOOL_TYPE_MILL,    /**<@brief  mill */
        CM_TOOL_TYPE_FLAME,   /**<@brief  flame */
        CM_TOOL_TYPE_DRILL,   /**<@brief  drill */
        CM_TOOL_TYPE_TAP,     /**<@brief  tap */
        CM_TOOL_TYPE_CENTER,  /**<@brief  center */
        CM_TOOL_TYPE_CHAMFER, /**<@brief  chamfer */
        CM_TOOL_TYPE_REAM,    /**<@brief  ream */
        CM_TOOL_TYPE_BORE     /**<@brief  bore */
    } evxCmToolType;

    /**
    @brief cam tool sub type
    @ingroup zwapi_cm_tool
    */
    typedef enum evxCmToolSubType
    {
        CM_TOOL_SUBTYPE_NULL = -1, /**<@brief  NULL */
        CM_TOOL_SUBTYPE_BALLNOSE,  /**<@brief  taperball */
        CM_TOOL_SUBTYPE_BULLNOSE,  /**<@brief  taperbull */
        CM_TOOL_SUBTYPE_ENDNOSE    /**<@brief  end */
    } evxCmToolSubType;

    /**
    @brief cam tool attribute
    @ingroup zwapi_cm_tool
    */
    typedef enum evxCmToolAttr
    {
        CM_TOOL_NAME = 400,     /**<@brief  tool name */
        CM_TOOL_TYPE,           /**<@brief  tool type */
        CM_TOOL_SUBTYPE,        /**<@brief  tool subtype */
        CM_TOOL_ID,             /**<@brief  tool id */
        CM_TOOL_LEN,            /**<@brief  tool_length*/
        CM_TOOL_CUTTERDIAMETER, /**<@brief  tool diameter*/
        CM_TOOL_HOLDER,         /**<@brief  tool holder name*/
        /*  tool register data in active machine */
        CM_TOOLCHANGER_LOCATION,
        CM_TOOLCHANGER_DIAMETER,
        CM_TOOLCHANGER_HEIGHT
    } evxCmToolAttr;

    /**
    @brief cam holder struct
    @ingroup zwapi_cm_tool
    */
    typedef struct svxCmToolHolderLayer
    {
        double top;    /**<@brief  cam holder top value */
        double bottom; /**<@brief  cam holder bottom value */
        double height; /**<@brief  cam holder height value */
    } svxCmToolHolderLayer;

    /**
    @brief cam tool coolant type
    @ingroup zwapi_cm_tool
    */
    typedef enum evxCmToolCoolant
    {
        CM_TOOL_COOLANT_FLOOD = 1, /**<@brief  coolant Flood */
        CM_TOOL_COOLANT_MIST,      /**<@brief  coolant Mist */
        CM_TOOL_COOLANT_THROUGH,   /**<@brief  coolant Through */
        CM_TOOL_COOLANT_AIR,       /**<@brief  coolant Air */
        CM_TOOL_COOLANT_OFF        /**<@brief  coolant Off */
    } evxCmToolCoolant;

    //====================================================================================================================
    /** @name Cam Query Fun */
    //====================================================================================================================
    /**
    @ingroup zwapi_cm_tool

    Insert a tool into active CamPlan.

    @param [in] tltype tool type
    @param [in] subtype sub type of tool
    @param [out] idx_tool index of the new tool

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_FORMDEFINE_ERROR
    -        ZW_API_CAM_UPVADTA_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GETFORMITEM_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmToolInsert(evxCmToolType tltype, evxCmToolSubType subtype, int *idx_tool);

    /**
    @ingroup zwapi_cm_tool

    Insert the tool from the library into CamPlan.

    @param [in] template_path template path
    @param [in] file_name file name
    @param [in] library_name library name
    @param [in] tool_name tool name
    @param [out] idx_tool tool index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_GETFORMITEM_ERROR
    -        ZW_API_CAM_SETFORMITEM_ERROR
    -        ZW_API_CAM_GETFORMSTATE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmToolInsertAsTemplate(const vxLongPath template_path, const vxName file_name, const vxName library_name, const vxName tool_name, int *idx_tool);

    /**
    @ingroup zwapi_cm_tool

    Delete the tool in CamPlan.

    @param [in] idx_tool index of the tool

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmToolDelete(int idx_tool);

    /**
    @ingroup zwapi_cm_tool

    Inquire the tool's attribute.

    @see cvxCmToolSetAttr().

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] idx_tool index of the tool
    @param [in] attr enumeration of tool attribute
    @param [out] value the values return; user needs to free the memory

    */
    extern evxErrors cvxCmToolGetAttr(int idx_tool, evxCmToolAttr attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_tool

    Set the tool's attribute.
    "attr" can't be CM_TOOL_TYPE or CM_TOOL_SUBTYPE.
    While "attr" is CM_TOOL_HOLDER, holder (depends on its name) is from active CAM plan
    or current Library or default Library in proper older.

    @verbatim
    "value->type"                 &     "value->cnt" depends on "attr", as follows:
    ZW_CAM_ATTR_VALUE_TYPE_STRING       <=32     CM_TOOL_NAME
                                                 CM_TOOL_ID
                                                 CM_TOOL_HOLDER
    ZW_CAM_ATTR_VALUE_TYPE_DOUBLE       1        CM_TOOL_LEN
                                                 CM_TOOL_CUTTERDIAMETER
    ZW_CAM_ATTR_VALUE_TYPE_INTEGER      1        CM_TOOLCHANGER_LOCATION
                                                 CM_TOOLCHANGER_DIAMETER
                                                 CM_TOOLCHANGER_HEIGHT
    @endverbatim

    The following is a simple code to set tool name and length:
    @code
       void TestApi(void)
       {
       svxCmAttrValue attr;
       int index=-1;
       char toolName[32]={"MillTool"};
       double toolLen=99.0;

       cvxCmToolInsert(CM_TOOL_TYPE_MILL, CM_TOOL_SUBTYPE_ENDNOSE, &index);
       if (index < 0) return;

       attr.type = ZW_CAM_ATTR_VALUE_TYPE_STRING;
       attr.cnt = 32;
       attr.data = (void *)toolName;
       cvxCmToolSetAttr(index, CM_TOOL_NAME, &attr);

       attr.type = ZW_CAM_ATTR_VALUE_TYPE_DOUBLE;
       attr.cnt = 1;
       attr.data = (void *)&toolLen;
       cvxCmToolSetAttr(index, CM_TOOL_LEN, &attr);

       return;
       }
    @endcode

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] idx_tool index of the tool
    @param [in] attr enumeration of tool attribute
    @param [in] value the values needed

    */
    extern evxErrors cvxCmToolSetAttr(int idx_tool, evxCmToolAttr attr, svxCmAttrValue *value);

    /**
    @ingroup zwapi_cm_tool

    Insert the holder from the library into CamPlan.

    @param [in] template_path template path
    @param [in] file_name file name
    @param [in] library_name library name
    @param [in] holder_name holder name
    @param [out] idx_holder holder index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_GETHOLDER_ERROR
    -        ZW_API_CAM_GETVDATA_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmHolderInsertAsTemplate(const vxLongPath template_path, const vxName file_name,
                                                 const vxName library_name, const vxName holder_name, int *idx_holder);

    /**
    @ingroup zwapi_cm_tool

    Insert the speed from the library into CamPlan.

    Returns ZW_API_NO_ERROR if it succeeds; the other value of evxErrors if function fails.
    @param [in] template_path template path
    @param [in] file_name file name
    @param [in] library_name library name
    @param [in] spdfd_name speed   name
    @param [out] idx_speed speed index

    */
    extern evxErrors cvxCmSpeedInsertAsTemplate(const vxLongPath template_path, const vxName file_name,
                                                const vxName library_name, const vxName spdfd_name, int *idx_speed);

    /**
    @ingroup zwapi_cm_tool

    Inquire the tool's attribute.

    @param [in] idx_tool index of the tool
    @param [in] attr enumeration of tool attribute
    @param [out] value value of the attribute, caller should allocate memory

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CAM_GETTOOLNAME_ERROR
    -        ZW_API_CAM_GETTOOLTYPE_ERROR
    -        ZW_API_CAM_GETTOOLSUBTYPE_ERROR
    -        ZW_API_CAM_GETTOOLID_ERROR
    -        ZW_API_CAM_GETTOOLLEN_ERROR
    -        ZW_API_CAM_GETTOOLDIA_ERROR
    -        ZW_API_CAM_GETHOLDER_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCmToolGetData(int idx_tool, evxCmToolAttr attr, char *value);

    /**
    @ingroup zwapi_cm_tool

    Get the tool register

    @param [in] idx_tool index of the tool
    @param [out] toolId register tool id
    @param [in] sizeToolId size of Register tool id
    @param [out] Dreg register tool Diameter
    @param [in] sizeDreg Size of register tool Diameter
    @param [out] Hreg register tool Height
    @param [in] sizeHreg size of Register tool Height

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    */
    extern evxErrors cvxCmToolGetRegister(int idx_tool, char *toolId, int sizeToolId, char *Dreg, int sizeDreg, char *Hreg, int sizeHreg);

    /**
    @ingroup zwapi_cm_tool

    Set the tool register

    @param [in] idx_tool index of the tool
    @param [in] toolId register tool id
    @param [in] Dreg register tool Diameter
    @param [in] Hreg register tool Height

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    */
    extern evxErrors cvxCmToolSetRegister(int idx_tool, const char *toolId, const char *Dreg, const char *Hreg);


    /**
    @ingroup zwapi_cm_tool

    Set the tool coolant

    @param [in] idx_tool index of the tool
    @param [in] coolant tool coolant type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLCOOLANT_ERROR
    */
    extern evxErrors cvxCmToolSetCoolant(int idx_tool, evxCmToolCoolant coolant);

    /**
    @ingroup zwapi_cm_tool

    Get the tool coolant

    @param [in] idx_tool index of the tool
    @param [out] coolant tool coolant type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLCOOLANT_ERROR
    */
    extern evxErrors cvxCmToolGetCoolant(int idx_tool, evxCmToolCoolant *coolant);

    /**
    @ingroup zwapi_cm_tool

    Add a new holder or add a new holder layer

    @param [in] idx_tool index of the tool
    @param [in] holderInfo one holder layer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_SETHOLDERINFO_ERROR
    */
    extern evxErrors cvxCmToolAddHolderLayer(int idx_tool, const svxCmToolHolderLayer *holderInfo);

    /**
    @ingroup zwapi_cm_tool

    Delete a holder layer

    @param [in] idx_tool index of the tool
    @param [in] layerIndex holder layer index

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOL_ERROR
    -        ZW_API_CAM_GETHOLDERID_ERROR
    -        ZW_API_CAM_SETHOLDERINFO_ERROR
    */
    extern evxErrors cvxCmToolDelHolderLayer(int idx_tool, int layerIndex);

    /**
    @ingroup zwapi_cm_tool

    Inquire the holder's attribute.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idx_tool index of the tool
    @param [out] layerCnt holder layer count
    @param [out] holderInfo holder all layer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETHOLDERID_ERROR
    -        ZW_API_CAM_GETHOLDEREXIST_ERROR
    -        ZW_API_CAM_GETHOLDERINFO_ERROR
    */
    extern evxErrors cvxCmToolGetHolderLayers(int idx_tool, int *layerCnt, svxCmToolHolderLayer **holderInfo);


    /**
    @ingroup zwapi_cm_tool

    Set the holder's attribute.

    @param [in] idx_tool index of the tool
    @param [in] layerIndex holder layer index
    @param [in] holderInfo holder one layer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETHOLDERID_ERROR
    -        ZW_API_CAM_GETHOLDEREXIST_ERROR
    -        ZW_API_CAM_GETHOLDERINFO_ERROR
    */
    extern evxErrors cvxCmToolSetHolderLayer(int idx_tool, int layerIndex, const svxCmToolHolderLayer *holderInfo);

    /**
    @ingroup zwapi_cm_tool

    Set the spindle speed value

    @param [in] idx_tool index of the tool
    @param [in] rowIdx spindle speed row index
    @param [in] spdValue spindle speed value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    -        ZW_API_CAM_SETSPDFD_ERROR
    */
    extern evxErrors cvxCmToolSetSpindleSpd(int idx_tool, int rowIdx, double spdValue);

    /**
    @ingroup zwapi_cm_tool

    Get the spindle speed value

    @param [in] idx_tool index of the tool
    @param [in] rowIdx spindle speed row index
    @param [out] spdValue spindle speed value
    @param [out] spdUnit spindle speed unit
    @param [in] spdUnitSize spindle speed unit size

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETSPDFD_ERROR
    -        ZW_API_INVALID_OUTPUT  
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxCmToolGetSpindleSpd(int idx_tool, int rowIdx, double *spdValue, char *spdUnit, int spdUnitSize);

    /**
    @ingroup zwapi_cm_tool

    Set the Feed Rate value

    @param [in] idx_tool index of the tool
    @param [in] rowIdx Feed Rate row index
    @param [in] pzFeedRate Feed Rate struct

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CAM_GETTOOLSHAPE_ERROR
    -        ZW_API_CAM_GETSPDFD_ERROR
    -        ZW_API_CAM_SETSPDFD_ERROR
    */
    extern evxErrors cvxCmToolSetFeedRate(int idx_tool, int rowIdx, const svxFeedRate *pzFeedRate);

    /**
    @ingroup zwapi_cm_tool

    Get the Feed Rate value

    @param [in] idx_tool index of the tool
    @param [in] rowIdx Feed Rate row index
    @param [out] feedRate Feed Rate struct

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CAM_GETSPDFD_ERROR
    */
    extern evxErrors cvxCmToolGetFeedRate(int idx_tool, int rowIdx, svxFeedRate *feedRate);

    /**
    @ingroup zwapi_cm_tool

    Get the Spindle speed, Feed Rate table row count

    @param [in] idx_tool index of the tool
    @param [out] rowCnt Spindle Speed, Feed Rate row count

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CAM_GETSPDFD_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxCmToolGetSpdFdRowCnt(int idx_tool, int *rowCnt);


    /**
    @ingroup zwapi_cm_tool

    Set the Holder Name

    @param [in] idx_tool index of the tool
    @param [in] holderName Holder Name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CAM_GETHOLDER_ERROR
    -        ZW_API_CAM_GETHOLDEREXIST_ERROR
    -        ZW_API_CAM_SETHOLDERINFO_ERROR
    */
    extern evxErrors cvxCmToolRenameHolder(int idx_tool, const char *holderName);

    /**
    @ingroup zwapi_cm_tool

    Get the Holder Name

    @param [in] idx_tool index of the tool
    @param [out] holderName Holder Name
    @param [in] sizeHolderName size of holder name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_CAM_GETHOLDER_ERROR
    */
    extern evxErrors cvxCmToolGetHolderName(int idx_tool, char *holderName, int sizeHolderName);

    /**
    @ingroup zwapi_cm_tool

    Open the tool form, default mill tool

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxCmToolOpenMillForm(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_CAM_TOOL_H */
