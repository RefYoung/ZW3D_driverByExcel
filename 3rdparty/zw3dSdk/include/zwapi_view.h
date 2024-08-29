/**
@file zwapi_view.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D View API
*/
/**
@defgroup zwapi_view View
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D View API
*/

#pragma once
#ifndef ZW_API_VIEW_H /* this ifndef surrounds entire header */
#define ZW_API_VIEW_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name View Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_view

    Determine whether the view is a section view.

    @param [in] idView id view

    @retval succeeds
    -        1 - it is section view
    -        0 - it is not section view
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern int cvxViewIsSection(int idView);

    /**
    @ingroup zwapi_view

    Determine whether the view is a standard view.

    @param [in] idView id view

    @retval succeeds
    -        1 - it is standard view
    -        0 - it is not standard view
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern int cvxViewIsStandard(int idView);

    /**
    @ingroup zwapi_view

    Gets the specified type of the standard view.

    @param [in] idView id view
    @param [out] type view type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxViewInqStandardType(int idView, evxViewStd *type);


    //====================================================================================================================
    /** @name View Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_view

    Activate the specified view.

    @param [in] idView id view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxViewActivate(int idView);

    /**
    @ingroup zwapi_view

    Sets the active view extent.

    @param [in] Extent view extent (mm)

    */
    extern void cvxViewExtent(double Extent);

    /**
    @ingroup zwapi_view

    Retrieves the position, orientation and extent of the active view.

    @param [out] Frame align active view with specified coordinate frame
    @param [out] Extent view extent

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_MEMORY
    */
    extern void cvxViewGet(svxMatrix *Frame, double *Extent);

    /**
    @ingroup zwapi_view

    Aligns the active view with the specified frame and
    sets the specified view extent.

    @param [in] Frame align active view with specified coordinate frame
    @param [in] Extent view extent

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern void cvxViewSet(svxMatrix *Frame, double Extent);

    /**
    @ingroup zwapi_view

    Moves the origin of the active view to the specified point.

    @param [in] Origin new view origin

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxViewOrigin(svxPoint *Origin);

    /**
    @ingroup zwapi_view

    Changes the orientation of the active view (part, sketch, cam plan)  
    to the specified standard view type and then does a "zoom all".

    @note
    the input view extent is only used if the "zoom all"
    doesn't find any geometry.

    @param [in] Type standard view type
    @param [in] NullExtent view extent used if no geometry

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxViewStd(evxViewStd Type, double NullExtent);

    /**
    @ingroup zwapi_view

    Make specified bounding box visible in world coordinates.

    @param [in] Scale scale factor
    @param [in] BndBox the 3D bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxViewSetBndBox(double Scale, const svxBndBox *BndBox);

    /**
    @ingroup zwapi_view

    Get the global or client coordinates of active View.

    @param [in] includeFrame 1=include window frame; 0=exclude window frame;
    @param [in] isGlobal 1=get global coordinates; 0=get client coordinates;
    @param [out] tlX top left X
    @param [out] tlY top left Y
    @param [out] brX bottom right X
    @param [out] brY bottom right Y

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxGetViewRect(int includeFrame, int isGlobal, int *tlX, int *tlY, int *brX, int *brY);


    //====================================================================================================================
    /** @name Custom View */
    //====================================================================================================================
    /**
    @ingroup zwapi_view

    Add a custom view.

    @param [in] Name custom view name
    @param [in] LyrVis store current layer visibility(1 to store, 0 not to store)
    @param [in] ObjVis store current object visibility(1 to store, 0 not to store)
    @param [out] idView index of view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCustomViewAdd(char *Name, int LyrVis, int ObjVis, int *idView);

    /**
    @ingroup zwapi_view

    Changes the orientation of the active view (part, sketch, cam plan)  
    to the specified custom view type and then does a "zoom all".

    @note
    the input view extent is only used if the "zoom all"
    doesn't find any geometry.

    @param [in] idView index of custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxCustomViewActivate(int idView);

    /**
    @ingroup zwapi_view

    Delete specified custom view.

    @note
    the view can not be the current active view.

    @param [in] idView index of custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxCustomViewDel(int idView);

    /**
    @ingroup zwapi_view

    Get index of custom view of specified name.

    @param [in] Name custom view name
    @param [out] idView index of custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxCustomViewId(vxName Name, int *idView);

    /**
    @ingroup zwapi_view

    Get index list of custom view in active file.

    This function allocates memory for the array output via "customViewList". The calling
    procedure is responsible for deallocating the memory.

    @param [out] count number of index in list
    @param [out] customViewList index of custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV*/
    extern evxErrors cvxCustomViewListGet(int *count, int **customViewList);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_VIEW_H */
