/**
@file zwapi_dwg_attribute.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Attribute API
*/
/**
@defgroup zwapi_dwg_attribute Drawing Attribute
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Drawing Attribute API
*/

#pragma once
#ifndef ZW_API_DWG_AT_H /* this ifndef surrounds entire header */
#define ZW_API_DWG_AT_H

#include "zwapi_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Drawing Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_attribute

    Retrieves attribute data from the specified drawing in the active file.

    @param [in] idDrawing drawing id
    @param [out] drawingAt attribute of drawing

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgAtGet(int idDrawing, svxDrawingAt *drawingAt);

    /**
    @ingroup zwapi_dwg_attribute

    Set the drawing data.
    if useTemplate is 1 or templateName is not NULL,
    add the template to the drawing or replace the template of the drawing
    else it will create new drawing border and insert block to drawing

    @param [in] idDrawing drawing id
    @param [in] drawingAt attribute of drawing

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgAtSet(int idDrawing, svxDrawingAt *drawingAt);

    /**
    @ingroup zwapi_dwg_attribute

    Outputs the sheet attribute of specified item.
    The itemId includes all of evxAtItemId.
    If the sheet has associated parts, this function also can inquire
    the parts item attribute.

    When itemId is VX_AT_USER, the name of the user-defined attribute must
    be assigned to At->label before calling this function.

    @param [in] itemId item id
    @param [out] At item attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    */
    extern evxErrors cvxDwgAtItemGet(evxAtItemId itemId, svxAttribute *At);

/**********************************************************************
*! -Item Attribute- : zwapi_part_attribute.h
*  extern evxErrors cvxPartAtItemGetInFile(vxLongName File, vxLongName Root, evxAtItemId itemId, svxAttribute *At);
*  extern evxErrors cvxPartAtItemSetInFile(vxLongName File, vxLongName Root, evxAtItemId itemId, svxAttribute *At);
**********************************************************************/
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DWG_AT_H */
