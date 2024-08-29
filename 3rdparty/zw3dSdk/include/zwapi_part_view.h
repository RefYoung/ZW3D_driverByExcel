/**
@file zwapi_part_view.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note MAIN HEADER FILE FOR THE ZW3D Part View API
*/
/**
@defgroup zwapi_part_view Part View API
@ingroup PartObjectsModel
@brief
@details MAIN MODULE FOR THE ZW3D Part View API
*/

#pragma once
#ifndef ZW_API_PART_VIEW_H /* this ifndef surrounds entire header */
#define ZW_API_PART_VIEW_H

#include "zwapi_part_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Part View */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_view

    Outputs the parameters of the specified view saved in the active part.

    @param [in] idView database id of view saved in the active part
    @param [out] View view information

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
    */
    extern evxErrors cvxPartInqView(int idView, svxView *View);

    /**
    @ingroup zwapi_part_view

    Outputs all view ids under the view manager for the current part,including  
    standard views,custom views, and sectional views.

    This function allocates memory for the array output via "Views". The calling  
    procedure is responsible for deallocating the memory.

    @param [out] Count number of 3D views saved in the active part
    @param [out] Views list of id's of 3D views saved in the active part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqViews(int *Count, int **Views);

    /**
    @ingroup zwapi_part_view

    Initialize the parameters of the cvxPartViewAdd().

    @note
    Do not assign a value to variable "data" before calling this function.  
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data view data(z3prt,z3asm)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartViewAddInit(svxView *data);

    /**
    @ingroup zwapi_part_view

    Creates a new view with the specified definition and adds it to  
    the active part.  Outputs the id of the new view via "idView".

    @note
    Interface cvxPartViewAddInit() can initialize variables of this function.

    @param [in] View view definition
    @param [out] idView id of new view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartViewAdd(svxView *View, int *idView);

    /**
    @ingroup zwapi_part_view

    Record the view object in view manager.

    @param [in] idView view id
    @param [in] View view information

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartViewRecord(int idView, svxView *View);


    //====================================================================================================================
    /** @name Part Display */
    //====================================================================================================================
    /**
    @ingroup zwapi_part_view

    Set the scope of display traversal to include all objects, originating  
    with the root object.  This affects operations such as drawing and  
    picking in all views.

    */
    extern void cvxPartShowAll(void);

    /**
    @ingroup zwapi_part_view

    Limit the scope of display traversal to only the active target object.  
    This affects operations such as drawing and picking in all views.  For  
    example, when the root object is an assembly and the active target is  
    one of its components, this function prevents other components in the  
    assembly from being drawn.  If the root object is the active target,  
    this function and cvxPartShowAll() produce the same results.

    */
    extern void cvxPartShowTarg(void);

    /**
    @ingroup zwapi_part_view

    This interface opens a small window to preview the contents of a file.

    @note
    The fileName cannot be equal to the active file name.  
    The rootName cannot be equal to the active root name.  
    If the small window is open, the small window is not refreshed.

    @see cvxPartClosePreview()

    @param [in] fileName file name
    @param [in] rootName root name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartShowPreview(const vxLongPath fileName, const vxRootName rootName);

    /**
    @ingroup zwapi_part_view

    Close the file preview window.

    @see cvxPartShowPreview()

    */
    extern void cvxPartClosePreview();

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PART_VIEW_H */
