/**
@file zwapi_brep_preedge.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D pre-edge API
*/
/**
@defgroup zwapi_brep_preedge Preedge API
@ingroup BrepEntityModel
@brief
@details THE MODULE FOR THE ZW3D pre-edge API
*/

#pragma once
#ifndef ZW_API_PREEDGE_H /* this ifndef surrounds entire header */
#define ZW_API_PREEDGE_H

#include "zwapi_brep_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name pre-edge Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_preedge

    Outputs information about the specified PreEdge (idPreEdge) to the structure
    referenced by the input pointer (PreEdge).

    @param [in] idPreEdge id of PreEdge within a loop on a face in the active part
    @param [out] PreEdge information about the PreEdge

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqPreEdgeInfo(int idPreEdge, svxPreEdge *PreEdge);

    /**
    @ingroup zwapi_brep_preedge

    Gets the coordinates of the specified PreEdge's start point
    relative to its parent loop direction.  Also, outputs the id
    of the PreEdge's parent edge.

    @param [in] idPreEdge id of PreEdge within a loop on a face
    @param [out] idEdge id of PreEdge's parent edge
    @param [out] StartPnt coordinates of PreEdge start point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInqPreEdgeStartPnt(int idPreEdge, int *idEdge, svxPoint2 *StartPnt);

/**********************************************************************
*! -pre-edge Evaluate- : zwapi_math_nurbscurve.h
*  extern evxErrors cvxPreEdgeEval(const int idPreEdge, const double t, const int level, svxEvalCurv* eval);
**********************************************************************/

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_H */
