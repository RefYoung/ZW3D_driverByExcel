/**
@file zwapi_dwg_view.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing View API
*/
/**
@defgroup zwapi_dwg_view Drawing View API
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Drawing View API
*/

#pragma once
#ifndef ZW_API_DWG_VIEW_H /* this ifndef surrounds entire header */
#define ZW_API_DWG_VIEW_H

#include "zwapi_dwg_data.h"
#include "zwapi_cmd_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name View Query/Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_view

    Outputs a list of the view entity IDs in the special drawing.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDrawing drawing id
    @param [in] type view type
    @param [out] count count of the object
    @param [out] views view list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgInqViews(int idDrawing, evxViewType type, int *count, int **views);

    /**
    @ingroup zwapi_dwg_view

    Check whether the views in the specified drawing has outdated and need to be updated,  
    output 1 if one of the views need to be updated.

    @param [in] idDrawing the index of drawing
    @param [out] modified 1 if one of the views in specified drawing need to be updated

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgInqViewMod(int idDrawing, int *modified);

    /**
    @ingroup zwapi_dwg_view

    Get the type(evxViewType) of specified view.  
    It can't get the corresponding type if "*type = VX_VIEW_ALL".

    @param [in] idView the index of view
    @param [out] type the type of specified view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgInqViewType(int idView, evxViewType *type);

    /**
    @ingroup zwapi_dwg_view

    Get the type(evxViewTypeEx) of specified view.  
    Types of view are more detailed than cvxDwgInqViewType().

    @param [in] viewId index of view in sheeting
    @param [out] viewType type of view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgInqViewTypeEx(int viewId, evxViewTypeEx *viewType);

    /**
    @ingroup zwapi_dwg_view

    Gets the attribute data of specified view. if index of view less than 0, the  
    function will get the global variables for view layout attributes used in CdV3Ins.

    @param [in] idView index of view (<= 0 to get the global variables)
    @param [out] viewAttr view attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgViewAtGet(int idView, svxViewAt *viewAttr);

    /**
    @ingroup zwapi_dwg_view

    Set the attribute of specified view. if index of view less than 0, the  
    function will set the global variables for view layout attributes used in CdV3Ins.

    @param [in] idView index of view (<= 0 to set the global variables)
    @param [in] viewAttr view attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxDwgViewAtSet(int idView, svxViewAt *viewAttr);

    /**
    @ingroup zwapi_dwg_view

    Lock/Unlock the location of view

    @param [in] idView id view
    @param [in] lock 1 is lock ,0 is unlock

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgViewLockSet(int idView, int lock);

    /**
    @ingroup zwapi_dwg_view

    Determine whether the view is locked.

    @param [in] idView id view
    @param [out] isLock 1 is lock ,0 is unlock

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgViewLockGet(int idView, int *isLock);

    /**
    @ingroup zwapi_dwg_view

    Gets the coordinates of the four vertices of the border.

    @param [in] idView index of view
    @param [out] UpperLeft top left corner
    @param [out] UpperRight top right corner
    @param [out] BottomLeft left bottom
    @param [out] BottomRight right bottom

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgViewDottedBorderGet(int idView, svxPoint2 *UpperLeft,
                                               svxPoint2 *UpperRight, svxPoint2 *BottomLeft, svxPoint2 *BottomRight);

    /**
    @ingroup zwapi_dwg_view

    Outputs source part object of the drawing view.

    @param [in] idView view id, -1 to get the active view for the target sheet
    @param [out] part part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgViewInqPart(int idView, svxCompName *part);

    /**
    @ingroup zwapi_dwg_view

    Inquire the name of the active item of configuration table by the source part object of the drawing view.

    @param [in] idView view id, -1 to get the active view for the target sheet
    @param [out] partCfg the name of the active item of configuration table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgViewInqPartConfig(int idView, vxName partCfg);

    /**
    @ingroup zwapi_dwg_view

    Inquire the name of the active item of configuration table by the source part object of the drawing view.

    @param [in] idView view id, -1 to get the active view for the target sheet
    @param [out] partCfg the name of the active item of configuration table
    @param [in] size max size of partCfg.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgViewInqPartConfigByLongName(int idView, char *partCfg, int size);

    /**
    @ingroup zwapi_dwg_view

    Output sub-views of the specified view.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idView index of view
    @param [out] count number of idViews
    @param [out]  idViews list of child view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgViewInqChildView(int idView, int *count, int **idViews);

    /**
    @ingroup zwapi_dwg_view

    Output parent-view of the specified view.
    
    @param [in] idView index of view
    @param [out] parentView index of parent view, -1 if not exist
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgViewInqParentView(int idView, int *parentView);

    /**
    @ingroup zwapi_dwg_view

    This function is to associate the entities with the view.

    @param [in] idView index of view (idView = -1 to disassociate)
    @param [in] count number of idEnts
    @param [in] idEnts list of entity id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgViewEntitiesAssociate(int idView, int count, int *idEnts);

    /**
    @ingroup zwapi_dwg_view

    Get perspective projection by view id.

    @param [in] idView id view
    @param [out] projection projection angle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_APPI_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgViewInqProjection(int idView, evxViewProjAngle *projection);

    /**
    @ingroup zwapi_dwg_view

    Gets the starting position of the view.

    @param [in] idView index of view
    @param [out] point position of specified view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgViewLocationGet(int idView, svxPoint2 *point);

    /**
    @ingroup zwapi_dwg_view

    Get alignment by idView.

    @param [in] idView id of view
    @param [out] align 1 if application alignment, else 0.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgAlignmentGet(int idView, int *align);

    /**
    @ingroup zwapi_dwg_view

    Get the origin point of specified view.  
    If idEnt is not NULL, output the id of origin point.

    @param [in] idView id of view
    @param [out] pnt origin point of specified view
    @param [out] idEnt id of origin point(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgViewInqOrgPnt(int idView, svxPoint2 *pnt, int *idEnt);

    /**
    @ingroup zwapi_dwg_view

    Set Attribute of special break line.  
    Before you use this function, you'd better calling cvxDwgBrkLineAtGet() to initialize brkLineAt.

    @param [in] brkLnViewId id of break line
    @param [in] brkLineAt Attribute of Break Line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxDwgBrkLineAtSet(int brkLnViewId, const svxDwgBrkLineAt *brkLineAt);

    /**
    @ingroup zwapi_dwg_view

    Get attribute of special break line.  
    If brkLineAt->layerName = "",it means layer by view.

    @param [in] brkLnViewId id of break line
    @param [out] brkLineAt Attribute of Break Line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgBrkLineAtGet(int brkLnViewId, svxDwgBrkLineAt *brkLineAt);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DWG_VIEW_H */
