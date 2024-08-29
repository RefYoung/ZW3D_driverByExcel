/**
@file zwapi_part_config.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Part Config API
*/
/**
@defgroup zwapi_part_config Part Configuration
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Part Config API
*/

#pragma once
#ifndef ZW_API_PART_CONFIG_H /* this ifndef surrounds entire header */
#define ZW_API_PART_CONFIG_H

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Part Config Activate */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_config

    Add a configuration id to the configuration table.  
    COnfiguration properties can be set for through idCfg  
    and interface cvxCfgTblInfosSet().

    @param [in] cfgName config name
    @param [in] cfgDes config description(Max = 96bytes,NULL to ignore)
    @param [out] idCfg id of config

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCfgTblAdd(vxName cfgName, char *cfgDes, int *idCfg);

    /**
    @ingroup zwapi_part_config

    Active the specified configuration to current part.

    @param [in] idCfg config id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartCfgActivate(int idCfg);

    /**
    @ingroup zwapi_part_config

    Outputs the active configuration id of current active part.

    @param [out] idCfg the id of current active configuration

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqActiveCfg(int *idCfg);

    /**
    @ingroup zwapi_part_config

    Outputs the active configuration id of specified file.

    @param [in] fileName file name, NULL for active file name
    @param [in] rootName root name, NULL for active root name
    @param [out] idCfg the id of current active configuration

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqActiveCfgByName(const vxLongPath fileName, const vxRootName rootName, int *idCfg);


    //====================================================================================================================
    /** @name Part Config Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_config

    Outputs the configuration id list of current active part.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [out] Count the number of part configuration
    @param [out] CfgList the list of part configuration id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_AIP_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqCfgList(int *Count, int **CfgList);

    /**
    @ingroup zwapi_part_config

    Outputs the configuration id list of specified file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] fileName file name, NULL for active file name
    @param [in] rootName root name, NULL for active root name
    @param [out] count the number of part configuration
    @param [out] cfgList the list of part configuration id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqCfgListByName(const vxLongPath fileName, const vxRootName rootName, int *count, int **cfgList);


    //====================================================================================================================
    /** @name Part Config Info */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_config

    This interface can modify data that already exists in the configuration table.

    Get Id by cvxPartInqCfgList();  
    Get info by cvxPartInqConfigTableInfos();

    Multiple values for each row of configuration can be set at once.

    @note
    When using this interface to set the configuration table,there are too many structure parameters,  
    which makes the interface difficult to use.  
    Therefore ,after all the new interfaces that replace this interface are available,  
    this interface will be discarded.  
    Now,it is recommended that customers use cvxPartCfgTblAttrSet() to add, modify, and delete attribute  
    related items to the configuration table.

    @param [in] idCfg configuration id
    @param [in] info config table info that changed

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCfgTblInfosSet(int idCfg, svxPartCfgInfo *info);

    /**
    @ingroup zwapi_part_config

    Get specified id configuration table infos.  
    Get Id by cvxPartInqCfgList();

    The memory referenced by "partcfg" is allocated by this function.  
    The calling procedure is responsible to free it (cvxPartFreeCfgTbl(partcfg)).

    @param [in] idCfg configuration id
    @param [out]  partCfg configuration infos

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqCfgTblInfos(int idCfg, svxPartCfgInfo **partCfg);

    /**
    @ingroup zwapi_part_config

    Get specified id configuration table infos.  
    Get idCfg by cvxPartInqCfgList()/cvxPartInqCfgListByName();

    The memory referenced by "partCfg" is allocated by this function.  
    The calling procedure is responsible to free it (cvxPartFreeCfgTbl(&partCfg)).

    @param [in] fileName file name, NULL for active file name
    @param [in] rootName root name, NULL for active root name
    @param [in] idCfg configuration id
    @param [out]  partCfg configuration infos

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_MEMORY_ERROR
    -        Zw_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqCfgTblInfosByName(const vxLongPath fileName, const vxRootName rootName, int idCfg, svxPartCfgInfo **partCfg);

    /**
    @ingroup zwapi_part_config

    Frees memory associated with the input config table infos list.  
    The input memory pointer (*cfginfo) is set to NULL.

    @param [in,out] cfginfo list of config table info

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxPartFreeCfgTbl(svxPartCfgInfo **cfginfo);

    /**
    @ingroup zwapi_part_config

    User can add, modify, and delete items in the configuration table through the 
    attribute value and attribute type.

    The enumerations that can be used for types are: \n
    VX_AT_USER     ,VX_AT_NUMBER  ,VX_AT_DESIGNER   ,VX_AT_COST       ,VX_AT_SUPPLIER   ,VX_AT_DESCRIPT, \n
    VX_AT_KEYWORD  ,VX_AT_MANAGER ,VX_AT_MATERIAL   ,VX_AT_NO_SECTION ,VX_AT_NO_HATCH   ,VX_AT_NO_BOM,   \n
    VX_AT_AREA     ,VX_AT_VOLUME  ,VX_AT_MASS       ,VX_AT_LENGTH     ,VX_AT_WIDTH      ,VX_AT_HEIGHT.

    The value of attrs can be obtained through interface cvxPartAtItemGet(),cvxPartAtItemGetInFile()...

    @param [in] markDel  1 is delete attribute, -1 if add attribute(default attribute), else 0 is modify \n
                         (If it exists, it will be modified;if it does not exist ,it will be added and modified.).
    @param [in] idCfg  configuration id
    @param [in] cnt  count of types(attrs)
    @param [in] types  attribute type
    @param [in] attrs  attribute data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_TABLE_GETDATA_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxPartCfgTblAttrSet(int markDel, int idCfg, int cnt, evxAtItemId *types, svxAttribute *attrs);

    /**
    @ingroup zwapi_part_config

    User can add, modify, and delete color item in the configuration table.

    @param [in] markDelClr  1 is delete color, -1 if add color(default color), else 0 is modify
                            (If it exists, it will be modified;if it does not exist ,it will be added and modified.).
    @param [in] idCfg  configuration id
    @param [in] color  part color.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_TABLE_GETDATA_ERROR
    */
    extern evxErrors cvxPartCfgTblColorSet(int markDelClr, int idCfg, svxColor color);

    /**
    @ingroup zwapi_part_config

    User can add, modify, and delete instance name item in the configuration table.

    @param [in] markDelInstName  1 is delete instance name, -1 if add instance name(default instance name), else 0 is modify
                                  (If it exists, it will be modified;if it does not exist ,it will be added and modified.).
    @param [in] idCfg  configuration id
    @param [in] instanceName  instance name.NULL to use default value.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_TABLE_GETDATA_ERROR
    */
    extern evxErrors cvxPartCfgTblInstNameSet(int markDelInstName, int idCfg, vxLongName instanceName);

    /**
    @ingroup zwapi_part_config

    User can add, modify, and delete variable item in the configuration table.

    @note
    If the user wants to modify the value of the variable, it is recommended to modify svxVariable.Expression.

    @param [in] markDelVars  1 is delete variable, -1 if add variable(default variable), else 0 is modify  
                                  (If it exists, it will be modified;if it does not exist ,it will be added and modified.).
    @param [in] idCfg  configuration id
    @param [in] cnt  count of vars
    @param [in] vars  list of variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_TABLE_GETDATA_ERROR
    */
    extern evxErrors cvxPartCfgTblVarsSet(int markDelVars, int idCfg, int cnt, svxVariable *vars);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PART_CONFIG_H */
