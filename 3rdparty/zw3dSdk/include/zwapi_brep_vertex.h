/**
@file zwapi_brep_vertex.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Vertex API
*/
/**
@defgroup zwapi_brep_vertex Vertex API
@ingroup BrepEntityModel
@brief
@details THE MODULE FOR THE ZW3D Vertex API
*/

#pragma once
#ifndef ZW_API_VERTEX_H /* this ifndef surrounds entire header */
#define ZW_API_VERTEX_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Vertex */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_vertex

    Gets all associated edges of the specified vertex of edge in the active file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idEdge the index of edge
    @param [in] EndPnt 0 to use the starting vertex of the edge,
                       1 to use the end vertex of the edge
    @param [out] Count the count of edges
    @param [out] Edges the list of edges

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqVertexEdges(int idEdge, int EndPnt, int *Count, int **Edges);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_VERTEX_H */
