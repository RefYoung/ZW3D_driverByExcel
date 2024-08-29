/**
@file zwapi_part_sheetmetal_attribute.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sheet Metal Attributes API
*/
/**
@defgroup zwapi_part_sheetmetal_attribute Sheet Metal Attribute
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Sheet Metal Attributes API
*/

#pragma once
#ifndef ZW_API_SHEET_METAL_AT_H /* this ifndef surrounds entire header */
#define ZW_API_SHEET_METAL_AT_H

#include "zwapi_cmd_sheetmetal_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sheet Metal Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Get the sheet metal attribute values.

    @param [out] at sheet metal attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartSmdAtGet(svxSmdAt *at);

    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Set the sheet metal attribute values.
    If there is no sheet metal, it will create one.

    @note
    if you just want to set some specified variables of svxSmdAt, you'd better  
    call cvxPartSmdAtGet to get the global values to initialize "at" first.

    @param [in] at sheet metal attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartSmdAtSet(const svxSmdAt *at);


    //====================================================================================================================
    /** @name Flange Face */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Get the faces on the same side as the stationary face(statFaces).  
    Get the faces opposite the stationary face(pairStatFaces).

    @see Interface cvxPartInqSmdStatFace can only obtain one face of sheet metal 
    whose attribute is the stationary face.

    @note
    Sheet metal must have a stationary face to call this interface.  
    The memory referenced by "statFcs" is allocated by this function.  
    The calling procedure is responsible to free it (cvxMemFree((void**)statFcs)).  
    The memory referenced by "pairStatFcs" is allocated by this function.  
    The calling procedure is responsible to free it (cvxMemFree((void**)pairStatFcs)).

    @param [in] idShape shape id
    @param [out] countStat count of "statFcs" (NULL to ignore)
    @param [out] statFcs see description(NULL to ignore)
    @param [out] countPair count of "pairStatFcs" (NULL to ignore)
    @param [out] pairStatFcs see description(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    @retval other
    -       -1 - not found stationary face
    */
    extern int cvxPartInqSmdStatFcs(int idShape, int *countStat, int **statFcs, int *countPair, int **pairStatFcs);

    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Get the stationary face of the shape specified by idFace.

    @see cvxPartInqSmdStatFcs.  
    This interface can obtain all faces on one side of the sheet metal stationary face and 
    all faces on the poopsite side.  
    This interface can obtain all faces except sheet metal thickness faces.

    @param [in] idShape id of sheet metal solid
    @param [out] idFace id of stationary face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqSmdStatFace(int idShape, int *idFace);

    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Outputs a list of indices of the face opposite to the input face in a sheet metal solid.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idFace index of face
    @param [out] count number of opposite faces
    @param [out] faces list of opposite face id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqSmdPairFaces(int idFace, int *count, int **faces);

    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Get surface type of sheet metal.

    @param [in] idFace face id
    @param [out] type sheet metal surface type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxPartInqSmdSrfType(int idFace, evxSmdSurfaceType *type);

    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Get thickness of the specified sheet metal.

    @param [in] idShape index of shape
    @param [out] thick thick

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqShtMetalThick(int idShape, double *thick);

    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Set the stationary face of a sheet metal part.

    @param [in] idFace id of face
    @param [out] idFtr id of feature(NULL to ignore)

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
    extern evxErrors cvxPartSmdStatFaceSet(int idFace, int *idFtr);

    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Gets a list of sheet metal flat solid id in the active part.

    The memory referenced by "solids" is allocated by this function.  
    The calling procedure is responsible to free it (cvxMemFree((void**)solids)).

    @param [out] cnts count of "solids"
    @param [out]  solids list of sheet metal flat solid id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartGetFlatSolids(int *cnts, int **solids);

    //====================================================================================================================
    /** @name Sheet Metal Flatten */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_sheetmetal_attribute

    Gets a list of sheet metal flatten id and flatten name in the active part.  
    At least one of idFlattens and flattenNames must exist.

    The memory referenced by "idFlattens" is allocated by this function.  
    The calling procedure is responsible to free it (cvxMemFree((void**)idFlattens)).  
    The memory referenced by "FlattenNames" is allocated by this function.  
    The calling procedure is responsible to free it (cvxMemFree((void**)FlattenNames)).

    @param [out] count count of idFlattens(flattenNames).
    @param [out]  idFlattens list of flatten id
    @param [out]  flattenNames list of flatten name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartInqFlattens(int *count, int **idFlattens, vxLongName **flattenNames);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SHEET_METAL_AT_H */
