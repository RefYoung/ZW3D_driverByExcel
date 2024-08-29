/**
@file zwapi_math_nurbscurve.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Nurbs Curve API
*/
/**
@defgroup zwapi_math_nurbscurve NURBS Curve
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Nurbs Curve API
*/

#pragma once
#ifndef ZW_API_NURBS_CURVE_H /* this ifndef surrounds entire header */
#define ZW_API_NURBS_CURVE_H

#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Curve Evaluate */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbscurve

    Evaluates the NURBS representation of the curve entity
    specified by "idCurve".  Outputs the point coordinates (Point)
    and normal direction (Normal) at the specified "t" parameter
    value.   
    Use cvxCrvParam() to get the curve's parameter limits.  
    The "Normal" output is an arbitrary direction that is perpendicular
    to the curve at "t" and is not the same as the normal direction that
    is a function of curvature at "t".

    @see cvxCrvEvalCrvtr() if you need the normal that points toward the curve's center of curvature.

    @param [in] idCurve curve entity id
    @param [in] T t parameter value on curve
    @param [out] Point point on curve
    @param [out] Normal normal at point on curve

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxCrvEval(int idCurve, double T, svxPoint *Point, svxVector *Normal);

    /**
    @ingroup zwapi_math_nurbscurve

    Evaluates a curve at a specified parameter value.

    "level" specifies the level of evaluation. The higher the level, more
    data gets returned (at the expense of greater computation).

    @verbatim
                         level
          |  0  |     1     |     2      |    3
          +-----+-----------+------------+--------
          | pnt |  deriv_1  |  deriv_2   | deriv_3
    @endverbatim

    @param [in] idCurve curve entity id
    @param [in] t t parameter value on curve
    @param [in] level level of evaluation(0 ~ 3), See description below
    @param [out] eval Result

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCrvEval2(const int idCurve, const double t, const int level, svxEvalCurv *eval);

    /**
    @ingroup zwapi_math_nurbscurve

    Evaluates a pre-edge at a specified parameter value. the difference between the function  
    and cvxCrvEval2() is that cvxCrvEval2() simply evaluates point on a curve, the function computes  
    directional and point on the surface from the UV curve.

    "level" specifies the level of evaluation. The higher the level, more
    data gets returned (at the expense of greater computation).

    @verbatim
                         level
          |  0  |     1     |     2      |    3
          +-----+-----------+------------+--------
          | pnt |  deriv_1  |  deriv_2   | deriv_3
    @endverbatim

    @param [in] idPreEdge index of pre-edge
    @param [in] t t parameter value on curve
    @param [in] level level of evaluation(0 ~ 3). See description below
    @param [out] eval Result

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPreEdgeEval(const int idPreEdge, const double t, const int level, svxEvalCurv *eval);

    /**
    @ingroup zwapi_math_nurbscurve

    Evaluates curvature, point and unit principal normal vector of a given curve
    at the specified parameter.Use cvxCrvParam() to get the curve's parameter limits.

    @param [in] idCurve curve entity id
    @param [in] t parameter at which the curvature is evaluated
    @param [out] point point at the specified parameter (input NULL to ignore).
    @param [out] normal unit principal normal vector at the specified parameter
                        (input NULL to ignore).
    @param [out] curvature curvature at the specified parameter (input NULL to ignore).

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCrvEvalCrvtr(const int idCurve, const double t, svxPoint *point, svxPoint *normal, double *curvature);


    //====================================================================================================================
    /** @name Curve Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbscurve

    Check if the specified curve is a straight line.

    @param [in] idCurve index of curve

    @retval return
    -        0: the specified curve is not a straight line
    -        1: the specified curve is a straight line
    -        -1: the id is not a curve or function fails
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern int cvxCrvIsLine(int idCurve);

    /**
    @ingroup zwapi_math_nurbscurve

    Outputs the minimum and maximum t parameter values of the
    NURBS representation of the specified curve entity.

    @param [in] idCurve curve entity id
    @param [out] T min/max T values

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxCrvParam(int idCurve, svxLimit *T);

    /**
    @ingroup zwapi_math_nurbscurve

    Get the maximum and minimum radius of the spline curve.  
    If curvature of curve = 0, Rad = -1 (the radius of curvature is infinite).

    @param [in] idCurve id of curve
    @param [out] minRad minimum radius(NULL to ignore)
    @param [out] maxRad maximum radius(NULL to ignore)
    @param [out] isFlat 1 if the curve is flat, else 0(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxCrvMinMaxRad(int idCurve, double *minRad, double *maxRad, int *isFlat);

    /**
    @ingroup zwapi_math_nurbscurve

    Get the flag of continuity of curves.

    @param [in] Count number of curves
    @param [in] Curves list of curves
    @param [out] Continuity continuity flag (0 to discontinuous;  
                            1 to position continuous;  
                            2 to tangent continuous)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCrvInqContinuity(int Count, int *Curves, int *Continuity);

    /**
    @ingroup zwapi_math_nurbscurve

    Initialize the parameters of the cvxCrvInqMultiContinuity().

    @note
    Do not assign a value to variable "data" before calling this function.   
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxCrvContinuityTolListInit(svxCrvContinuityTolList *data);

    /**
    @ingroup zwapi_math_nurbscurve

    For all input lines, judge the continuity relationship between two lines. 

    cntContinuity is the number of intersections between every two line segments. 

    data is the continuity of the two line segments represented by the intersection. 

    Unlike the cvxCrvInqContinuity interface can only judge the overall continuity of 
    all input line segments, and requires that the line segments are closed at last. 

    The cvxCrvInqMultiContinuity interface can judge the continuity between any two 
    line segments, and there are no other use requirements. 

    @note
    Interface cvxCrvContinuityTolListInit() can initialize variables of this function.

    @param [in] cnt              count of curves 
    @param [in] curves           list of curve id 
    @param [in] tols             list of curve continuity tolerance 
    @param [out] cntContinuity   count of data 
    @param [out] data            list of continuity data 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxCrvInqMultiContinuity(int cnt, const int *curves, const svxCrvContinuityTolList *tols, int *cntContinuity, svxCrvContinuityData **data);

    /**
    @ingroup zwapi_math_nurbscurve

    Use the function to find connected chain of curves or edges and output a list
    of indices of the edges or curves.

    If the seed is a curve, the chain consists of curves that are connected end-to-end,
    but without any requirement for tangency between curve.

    If the seed is an edge, the chain consists of edges that are tangent, i.e. smoothly  
    connected end-to-end. If type is 0, an edge may bound any number of faces. If type  
    is 1, only open edges are included in the chain, the requirement for tangency between  
    edges is suspended, so a chain of open edges may continue around sharp corners. If  
    type is 2, only manifold edges are included in the chain, i.e. edges that are shared  
    by exactly two faces, or edges that have seams with the same face on both sides.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] nSeeds number of seed edges or curves
    @param [in] idSeeds list of id of seed edges or curves
    @param [in] type type of edges, only effects the find result of the seed edge  
                     0: find continuously tangent edges that may be bound by any number of faces  
                     1: find connected open edges  
                     2: find continuously tangent manifold edges that are shared by exactly two  
                     faces or are seams having the same face on both sides
    @param [out] Count number of curves found
    @param [out] idCrvs list of curves found

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartCurveChainFind(int nSeeds, int *idSeeds, int type, int *Count, int **idCrvs);


    //====================================================================================================================
    /** @name Curve Point */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbscurve

    Gets point on a curve at a specified fraction of the curve's length.  
    For example, to evaluate the curve at its minimum parameter value,  
    set frac to 0.0; to evaluate the curve at its maximum parameter value,  
    set frac to 1.0; and to evaluate the mid-point of the curve where the  
    length from each end is the same, set frac to 0.5.

    @param [in] idCurve curve entity id
    @param [in] Fraction fraction of curve length (0.0 to 1.0)
    @param [out] Point output point on curve

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxCrvGetPntAtLenFraction(int idCurve, double Fraction, svxPoint *Point);

    /**
    @ingroup zwapi_math_nurbscurve

    Outputs the T parameter value of the projection of the input XYZ  
    point onto the NURBS representation of the specified curve.  It  
    is assumed that "Pnt" lies on or very close to the curve.

    @param [in] idCurve id of curve entity
    @param [in] Pnt coordinates of point to project onto curve
    @param [out] T T parameter value of point-on-curve
    @param [out] ProjPnt XYZ coordinates of projected point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxCrvPntProj(int idCurve, svxPoint *Pnt, double *T, svxPoint *ProjPnt);

    /**
    @ingroup zwapi_math_nurbscurve

    Get point on a curve at a specified distance from the specified
    start point of the curve.

    @param [in] idCurve curve entity id
    @param [in] StartT T parameter value of starting point
    @param [in] Length Length of interval
    @param [out] T T parameter value of output point(NULL to ignore)
    @param [out] Point output point on curve(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxCrvGetPntAtDist(int idCurve, double StartT, double Length, double *T, svxPoint *Point);

    /**
    @ingroup zwapi_math_nurbscurve

    Calculates inflection points of the specified curve and outputs the list of  
    parameter value and coordinates of inflection points found.The calling  
    procedure MUST deallocate the output list.

    @param [in] idCurve id of curve in the active object
    @param [out] Count number of inflection points found
    @param [out] T T parameter value of each inflection points (NULL to ignore)
    @param [out] InfPnts the array of inflection points (NULL to ignore)

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
    extern evxErrors cvxCrvGetInflections(int idCurve, int *Count, double **T, svxPoint **InfPnts);

    /**
    @ingroup zwapi_math_nurbscurve

    Gets the extreme point of curve in the specified direction. if the curve is  
    on a plane perpendicular to direction, the extreme point output is start point  
    of curve.

    @param [in] idCurve id of curve in active part
    @param [in] Dir direction
    @param [out] isPerp output 1 if the curve is on a plane perpendicular to direction, else 0
    @param [out] Point extreme point

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
    extern evxErrors cvxCrvInqExtreme(int idCurve, const svxVector *Dir, int *isPerp, svxPoint *Point);

    /**
    @ingroup zwapi_math_nurbscurve

    Return the extremum points of specified curve and its bounding box.

    The list of extremum points must be freed by caller.

    @param [in] idCurve id of curve entity
    @param [out] Count extremum point count
    @param [out] Pnts list of extremum points
    @param [out] BndBox optional curve tight bounding box (or NULL)

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
    extern evxErrors cvxCrvExtremum(int idCurve, int *Count, svxPoint **Pnts, svxBndBox *BndBox);

    /**
    @ingroup zwapi_math_nurbscurve

    Find cusps of the specified curve and outputs the list of  
    parameter value and coordinates of cusps.The calling  
    procedure MUST deallocate the output list.

    @param [in] idCurve id of curve in the active object
    @param [out] Count number of cusps found
    @param [out] T T parameter value of each cusps (NULL to ignore)
    @param [out] Cusps the array of cusps found (NULL to ignore)

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
    extern evxErrors cvxCrvGetCusps(int idCurve, int *Count, double **T, svxPoint **Cusps);


    //====================================================================================================================
    /** @name Curve Length */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbscurve

    Calculates the length of the specified curve and outputs it via "Len".

    @param [in] idCurve id of curve in the active object
    @param [out] Len curve length (mm)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxCrvLen(int idCurve, double *Len);

    /**
    @ingroup zwapi_math_nurbscurve

    Calculates the curve length of a NURBS curve from the parameter T1 to T2.

    @param [in] idCurve curve entity id
    @param [in] T1 T parameter value of start point
    @param [in] T2 T parameter value of end point
    @param [out] Length length of a NURBS curve from T1 to T2

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxCrvLen2(int idCurve, double T1, double T2, double *Length);


    //====================================================================================================================
    /** @name Edge Sew */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbscurve

    Matches and sews free edges in the active part using the input proximity  
    tolerance.  If "Tol" is input as 0.0, the active part's default proximity  
    tolerance is used.

    Input NULL for "OpenEdges" and/or "MaxGap" if you are not interested in  
    the information returned via those variables.

    @param [in] Tol 3D proximity tolerance (mm) (0.0 for default)
    @param [out] OpenEdges number of unmatched/open edges after sew (or NULL)
    @param [out] MaxGap maximum gap between all unmatched edges (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxPartSew(double Tol, int *OpenEdges, double *MaxGap);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_NURBS_CURVE_H */
