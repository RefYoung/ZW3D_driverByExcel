/**
@file zwapi_brep_loop.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Loop API
*/
/**
@defgroup zwapi_brep_loop Loop API
@ingroup BrepEntityModel
@brief
@details THE MODULE FOR THE ZW3D Loop API
*/

#pragma once
#ifndef ZW_API_LOOP_H /* this ifndef surrounds entire header */
#define ZW_API_LOOP_H


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Loop query */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_loop

    Outputs a list of indices of the edges that belong to a loop
    on a face in the active file. Edges are output in the order
    they occur in the loop.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    Outer loops proceed counterclockwise relative to the natural
    normal of the parent surface.  Inner loops are clockwise
    relative to the natural surface normal.

    @param [in] idLoop loop id
    @param [out] Count number of edges
    @param [out] Edges list of edge id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqLoopEdges(int idLoop, int *Count, int **Edges);

    /**
    @ingroup zwapi_brep_loop

    Outputs the id of the parent face of the specified loop within the active file.

    @param [in] idLoop loop id
    @param [out] idFace id of loop's parent face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqLoopFace(int idLoop, int *idFace);

    /**
    @ingroup zwapi_brep_loop

    Outputs a list of indices of the PreEdges that belong to a loop
    on a face in the active file. PreEdges are output in the order
    they occur in the loop.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    Outer loops proceed counterclockwise relative to the natural
    normal of the parent surface.  Inner loops are clockwise
    relative to the natural surface normal.

    @param [in] idLoop loop id
    @param [out] Count number of PreEdges
    @param [out] PreEdges list of PreEdge id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqLoopPreEdges(int idLoop, int *Count, int **PreEdges);

    /**
    @ingroup zwapi_brep_loop

    Determine whether a given loop is an outer or inner loop.

    @param [in] idLoop loop id
    @param [out] isInner inner loop flag (1=inner, 0=outer)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxPartInqLoopInner(int idLoop, int *isInner);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_LOOP_H */
