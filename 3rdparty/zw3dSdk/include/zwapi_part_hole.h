/**
@file zwapi_part_hole.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Hole Data API
*/
/**
@defgroup zwapi_part_hole Hole Attribute
@ingroup PartObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Hole Data API
*/

#pragma once
#ifndef ZW_API_HOLE_H /* this ifndef surrounds entire header */
#define ZW_API_HOLE_H

#include "zwapi_cmd_shape_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Part Hole */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_hole

    Outputs a list of holes that belong to the specified part.  
    The calling procedure MUST deallocate the output list using  
    cvxPartFreeHoles(Count, Holes);

    The "idInsFace" and "idUntilFace" fields of the "svxHoleData"  
    structure are not currently supported.  They are always output  
    as zero.  "ThreadType" is always output as VX_THREAD_CUSTOM.

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part name (Part[0]=0 or NULL for active part)
    @param [out] Count number of holes
    @param [out] Holes list of holes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqHoles(const vxLongPath File, const vxRootName Part, int *Count, svxHoleData **Holes);

    /**
    @ingroup zwapi_part_hole

    Frees memory associated with the input hole list.  
    The input memory pointer (*Holes) is set to NULL.

    @param [in] Count number of holes
    @param [in,out] Holes list of holes

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxPartFreeHoles(int Count, svxHoleData **Holes);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_HOLE_H */
