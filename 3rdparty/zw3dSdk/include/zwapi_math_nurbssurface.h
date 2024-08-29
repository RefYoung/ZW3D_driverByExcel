/**
@file zwapi_math_nurbssurface.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Nurbs Surface API
*/
/**
@defgroup zwapi_math_nurbssurface NURBS Surface
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Nurbs Surface API
*/

#pragma once
#ifndef ZW_API_NURBS_SURFACE_H /* this ifndef surrounds entire header */
#define ZW_API_NURBS_SURFACE_H

#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Surface Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbssurface

    Adds a face to the active part using the specified surface and trim curves.  
    The face is sewn to adjacent faces with matching edges.

    It is assumed the trim curves are 2D NURBS curves defined in the UV space of  
    the specified surface.  If no trim curves are input (NumCurves=0), trim  
    curves are automatically created around the "rectangular" surface boundary.

    The input 3D proximity tolerance (Tol) is used to match the endpoints of  
    trim curves when they are sorted into loops, and to match edges of the  
    new face to edges to existing faces if the "Sew" option is enabled.

    If "Tol" is input as 0.0, the active part's default proximity tolerance is used.

    If "idFace" is not NULL, the database id of the new face entity is output.

    This function copies data passed to it.  The calling procedure is  
    responsible for deallocating memory referenced by the input data structures.

    @note
    Faces will not add successfully to the active part unless there  
    is an active feature (i.e. history operation) for them to link to.  This is  
    accomplished by putting your code inside the callback function associated  
    with a command-template-defined custom history operation (see cvxTplInit()).  
    When the history is regenerated, ZW3D will expect the input parameters defined  
    by the command template to provide sufficient input to the callback function  
    to re-create (i.e. regenerate) the original geometry.

    The other option is to start your code with cvxPartHistStart(), which  
    defines a "static" feature (i.e. history operation) for program-generated  
    geometry (e.g. faces) to attach to.  When you are done adding geometry,  
    call cvxPartHistEnd().  This function will cause all existing part geometry  
    and history to be bundled into a single static "StartData" history operation.

    @param [in] Srf NURBS surface geometry
    @param [in] NumCurves number of trim curves
    @param [in] TrimCurves list of 2D NURBS UV trim curves
    @param [in] Code non-zero integer code for labeling the face
    @param [in] Sew 1 to sew face to adjacent faces, else 0
    @param [in] Tol 3D proximity tolerance (mm) (0.0 for default)
    @param [out] idFace database id of new face entity (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartFace(svxSurface *Srf, int NumCurves, svxCurve *TrimCurves, int Code, int Sew, double Tol, int *idFace);

    /**
    @ingroup zwapi_math_nurbssurface

    Modify a face to the active part using the specified surface and trim curves.  
    The face is sewn to adjacent faces with matching edges.

    It is assumed the trim curves are 2D NURBS curves defined in the UV space of  
    the specified surface.  If no trim curves are input (NumCurves=0), trim  
    curves are automatically created around the "rectangular" surface boundary.

    The input 3D proximity tolerance (Tol) is used to match the endpoints of  
    trim curves when they are sorted into loops, and to match edges of the  
    new face to edges to existing faces if the "Sew" option is enabled.

    If "Tol" is input as 0.0, the active part's default proximity tolerance is used.

    This function copies data passed to it.  The calling procedure is  
    responsible for deallocating memory referenced by the input data structures.

    @note
    Faces will not modify successfully to the active part unless there  
    is an active feature (i.e. history operation) for them to link to.  This is  
    accomplished by putting your code inside the callback function associated  
    with a command-template-defined custom history operation. When the history  
    is regenerated, ZW3D will expect the input parameters defined by the command  
    template to provide sufficient input to the callback function to re-create  
    (i.e. regenerate) the original geometry.

    The other option is to start your code with cvxPartHistStart(), which  
    defines a "static" feature (i.e. history operation) for program-generated  
    geometry (e.g. faces) to attach to.  When you are done adding geometry,  
    call cvxPartHistEnd().  This function will cause all existing part geometry  
    and history to be bundled into a single static "StartData" history operation.

    @param [in] idFace index of face
    @param [in] Srf NURBS surface geometry
    @param [in] NumCurves number of trim curves
    @param [in] TrimCurves list of 2D NURBS UV trim curves
    @param [in] Sew 1 to sew face to adjacent faces, else 0
    @param [in] Tol 3D proximity tolerance (mm) (0.0 for default)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartFaceMod(int idFace, svxSurface *Srf, int NumCurves, svxCurve *TrimCurves, int Sew, double Tol);

    //====================================================================================================================
    /** @name Surface Evaluate */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbssurface

    Evaluates a point in the space of the specified NURBS surface.  Outputs  
    the 3D point coordinates (Point), normal direction (Normal) and UV tangent  
    directions at the specified U,V location on the surface.

    @note
    The direction of "Normal" is set to reflect the outward  
    normal of the face, where "outward" means the direction that points  
    towards the outside of the shape that the face is associated with.  
    This may be opposite the natural normal of the NURBS surface associated  
    with the face.

    If you want the natural normal of the NURBS surface associated with  
    the face,  call cvxVecReverse() to reverse the "Normal" if Srf->OutNormal=0.

    @param [in] Srf pointer to NURBS surface data structure
    @param [in] U U parameter value on face
    @param [in] V V parameter value on face
    @param [out] Point point on face (input NULL to ignore)
    @param [out] Normal normal at point on face (input NULL to ignore)
    @param [out] Utan U tangent direction (input NULL to ignore)
    @param [out] Vtan V tangent direction (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxSrfEval(svxSurface *Srf, double U, double V, svxPoint *Point, svxVector *Normal, svxVector *Utan, svxVector *Vtan);

    /**
    @ingroup zwapi_math_nurbssurface

    Get the surface diameter in the specified UV point. the surface type  
    must be one of the following:                               
    1.Cylinder: the cylinder diameter.                          
    2.Torus: the distance of the point specified from the axis.   
    3.Cone: the distance of the point specified from the axis.   

    @param [in] Srf pointer to NURB surface data structure
    @param [in] U U parameter value on face
    @param [in] V V parameter value on face
    @param [out] Diameter diameter of specified point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxSrfDiameterEval(svxSurface *Srf, double U, double V, double *Diameter);


    //====================================================================================================================
    /** @name Surface Find Face/Edge */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbssurface

    Use the function to find connected groups of faces and output a list  
    of indices of the faces. the function provides several methods for  
    finding faces that form certain kinds of features, such as bosses,  
    pockets, holes and fillets. also support custom method, please refer  
    to the description of input variables for details.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] findData face search data
    @param [out] Count number of faces found
    @param [out] idFaces list of faces found

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartFaceFind(svxFaceFind *findData, int *Count, int **idFaces);

    /**
    @ingroup zwapi_math_nurbssurface

    Use the function to find edges that bound one or more seed faces.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] nSeeds number of seed faces
    @param [in] idSeeds list of id of seed faces
    @param [in] type type of boundary
    @param [out] Count number of edges found
    @param [out] idEdges list of edges found

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxPartFaceEdgesFind(int nSeeds, int *idSeeds, evxEdgeLoopType type, int *Count, int **idEdges);


    //====================================================================================================================
    /** @name Surface Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_nurbssurface

    Get the axis of the specified surface. the surface type must be  
    one of the following: Cylinder, Torus and Cone.

    @param [in] Srf pointer to NURBS surface data structure
    @param [out] startPnt start point of axis line
    @param [out] endPnt end point of axis line

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
    extern evxErrors cvxSrfAxis(svxSurface *Srf, svxPoint *startPnt, svxPoint *endPnt);

    /**
    @ingroup zwapi_math_nurbssurface

    Get the pole point of the specified surface in a specified direction.

    @param [in] srf pointer to NURBS surface data structure
    @param [in] dir direction
    @param [out] pnt pole point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxSrfGetPole(svxSurface *srf, const svxPoint *dir, svxPoint *pnt);

    /**
    @ingroup zwapi_math_nurbssurface

    This routine determines which, if any, boundaries of srf are poles.  
    It sets the flags in the array poles appropriately.

    @param [in] srf pointer to NURBS surface data structure
    @param [in] tol the tolerance
    @param [out] poles[4]  poles[i] = 0 means the i-th boundary is not a pole.  
                           poles[i] = 1 means it is a pole.  
                           The boundaries are numbered counterclockwise, starting at  
                           the bottom (v=0).   
                           fPoles[0] -> pole at loV  
                           fPoles[1] -> pole at hiU  
                           fPoles[2] -> pole at hiV  
                           fPoles[3] -> pole at loU

    @retval return
    -        0 - No poles found or error occurs
    -        1 - At least one pole found
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern int cvxSrfFindPoles(svxSurface *srf, double tol, int poles[4]);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_NURBS_SURFACE_H */
