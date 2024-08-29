/**
@file zwapi_cmd_udf.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D UDF API
*/
/**
@defgroup zwapi_cmd_udf UDF API
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D UDF API
*/

#pragma once
#ifndef ZW_API_UDF_H /* this ifndef surrounds entire header */
#define ZW_API_UDF_H

#include "zwapi_cmd_udf_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name UDF Creation */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_udf

    Initialize the specified UDF model, it will create a UDF command template.

    If it successes, you can execute this command by follow steps: 
    1. cvxDataCreate("CdUDFCmd", &idData);                         
    2. calls cvxPartUDFInqFlds() to get field parameters;          
    3. calls cvxDataSet(idData, idFld, data) to set the data;      
    4. calls ZwApiCmdExec(idData) to execute the UDF command;      
    5. calls cvxPartUDFTerm to free the UDF template data.

    @param [in] udfPath path of UDF model

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxPartUDFInit(const vxLongPath udfPath);

    /**
    @ingroup zwapi_cmd_udf

    Get the field parameters of current UDF command.

    @note
    You must call the function cvxPartUDFInit() first.

    @param [out] cnt count of fields
    @param [out]  fldParams value of field parameters

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartUDFInqFlds(int *cnt, svxUDFParam **fldParams);

    /**
    @ingroup zwapi_cmd_udf

    Destruct data after execute a user define feature command.

    */
    extern void cvxPartUDFTerm();

    /**
    @ingroup zwapi_cmd_udf

    Explode custom feature into the operations that define it.

    @param [in] idFtr index of UDF feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartUDFExplode(int idFtr);


    //====================================================================================================================
    /** @name UDF Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_udf

    Get source file full path of specified UDF feature.

    @param [in] idFtr index of UDF feature
    @param [out] file source file path of UDF feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartUDFInqPath(int idFtr, vxPath file);

    /**
    @ingroup zwapi_cmd_udf

    Get source file full path of specified UDF feature.

    @param [in] idFtr index of UDF feature
    @param [out] file source file path of UDF feature
    @param [in] sizefile max size of file

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartUDFInqLongPath(int idFtr, char *file, int sizefile);

    /**
    @ingroup zwapi_cmd_udf

    Get sub-feature list in specified UDF feature.

    This function allocates memory for the array output via "ftrList". The calling
    procedure is responsible for deallocating the memory.

    @param [in] idFtr index of UDF feature
    @param [out] count number of sub-feature in UDF feature
    @param [out]  ftrList list of sub-feature in UDF feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_ONJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartUDFInqSubFtrs(int idFtr, int *count, int **ftrList);

    /**
    @ingroup zwapi_cmd_udf

    Get the type of the feature: UDF or not.

    @param [in] idFtr index of feature
    @param [out] isUDF 1 - is a UDF feature, 0 - is not a UDF feature, -1 - is not a feature

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartFtrIsUDF(int idFtr, int *isUDF);

    /**
    @ingroup zwapi_cmd_udf

    Replace the specified UDF to the new one by the path of UDF file.
    It requires that the new UDF has the same references as the old one, or it will fail.

    @param [in] idFtr index of UDF feature
    @param [in] file the file path of UDF to replace

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxPartUDFReplace(int idFtr, const vxLongPath file);


    //====================================================================================================================
    /** @name UDF Path */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_udf

    Set the default open directory for the wizard UDF.

    @param [in] path full path of UDF

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxPartUDFWizardPathSet(const vxLongPath path);

    /**
    @ingroup zwapi_cmd_udf

    Set the default open directory for the Insert UDF.

    @param [in] path full path of UDF

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    extern evxErrors cvxPartUDFInsPathSet(const vxLongPath path);

    /**
    @ingroup zwapi_cmd_udf

    Get the default open directory for the wizard UDF.

    @param [out] Dir full path of UDF

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        Zw_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartUDFWizardPathGet(vxPath Dir);

    /**
    @ingroup zwapi_cmd_udf

    Get the default open directory for the wizard UDF.

    A Dir that is too long (longer than "sizeDir") is truncated.

    It is assumed that the input "Dir" is no longer than 512 bytes.

    @param [out] Dir full path of UDF
    @param [in] sizeDir max size of Dir

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        Zw_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartUDFWizardPathGetByLongPath(char *Dir, int sizeDir);

    /**
    @ingroup zwapi_cmd_udf

    Get the default open directory for the Insert UDF.

    @param [out] Dir full path of UDF

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        Zw_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartUDFInsPathGet(vxPath Dir);

    /**
    @ingroup zwapi_cmd_udf

    Get the default open directory for the Insert UDF.
    A Dir that is too long (longer than "sizeDir") is truncated.
    It is assumed that the input "Dir" is no longer than 512 bytes.

    @param [out] Dir full path of UDF
    @param [in] sizeDir max size of Dir

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        Zw_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartUDFInsPathGetByLongPath(char *Dir, int sizeDir);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_UDF_H */
