/**
@file zwapi_brep_edge.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Edge API
*/
/**
@defgroup zwapi_brep_edge Edge API
@ingroup BrepEntityModel
@brief
@details THE MODULE FOR THE ZW3D Edge API
*/

#pragma once
#ifndef ZW_API_EDGE_H /* this ifndef surrounds entire header */
#define ZW_API_EDGE_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Edge Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_edge

    Check if the specified edge is an open edge.

    @param [in] idEdge edge id (in active file)

    @retval return
    -        0: the specified edge is not an open edge
    -        1: the specified edge is an open edge
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern int cvxPartInqEdgeOpen(int idEdge);

    /**
    @ingroup zwapi_brep_edge

    Gets the type of specified edge.

    @param [in] idEdge edge id (in active file)
    @param [out] EdgeType edge type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqEdgeType(int idEdge, evxEdgeType *EdgeType);

    /**
    @ingroup zwapi_brep_edge

    Outputs a list of indices of the faces connected to an edge
    in the active file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idEdge edge id
    @param [out] Count number of faces
    @param [out] Faces list of face id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqEdgeFaces(int idEdge, int *Count, int **Faces);

    /**
    @ingroup zwapi_brep_edge

    Gets a list of the pre-edges associated with the specified edge. 
    Memory for the list is allocated by this function and must be freed by the calling procedure.

    @param [in] idEdge edge id
    @param [out] Count number of pre-edges associated with the specified edge
    @param [out] PreEdges list of pre-edges associated with the specified edge

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqEdgePreEdges(int idEdge, int *Count, int **PreEdges);

    /**
    @ingroup zwapi_brep_edge

    Get the id of the parent loop of the specified edge on the specified face.

    @param [in] idFace face id
    @param [in] idEdge edge id
    @param [out] idLoop loop id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqEdgeLoop(int idFace, int idEdge, int *idLoop);

    /**
    @ingroup zwapi_brep_edge

    Outputs the shape connected to an edge in the active file.

    @param [in] idEdge index of edge
    @param [out] idShape index of shape

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqEdgeShape(int idEdge, int *idShape);

    /**
    @ingroup zwapi_brep_edge

    Outputs the NURBS curve geometry of the specified edge in the active part.

    If "idFace <= 0", the 3D definition of the edge is output.

    If "idFace > 0", the UV definition of the edge corresponding to the
    specified face or loop is output.

    The calling procedure is responsible for deallocating the memory
    assigned by this function to the "Crv" structure using cvxCurveFree().

    The direction of UV curves output by this function follow the direction
    of their parent loops.  3D curves are not given a specific orientation.

    Outer loops proceed counterclockwise relative to the natural normal of
    the parent surface.  Inner loops are clockwise.

    It is assumed the specified edge (idEdge) resides in the active part.

    @note cvxCurveFree() can use to free Crv.

    @param [in] idEdge edge id
    @param [in] idFace optional face or loop id for retrieving UV geometry (else 0)
    @param [out] Crv edge's curve geometry

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqEdgeCrv(int idEdge, int idFace, svxCurve *Crv);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_EDGE_H */
