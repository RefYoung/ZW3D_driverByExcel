/**
@file zwapi_math_matrix.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Matrix API
*/
/**
@defgroup zwapi_math_matrix Matrix API
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Matrix API
*/

#pragma once
#ifndef ZW_API_MATRIX_H /* this ifndef surrounds entire header */
#define ZW_API_MATRIX_H

#include "zwapi_math_data.h"


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Transformation Matrix */
    //====================================================================================================================

    /**
    @ingroup zwapi_math_matrix

    Calculates the eigenvalues and eigenvectors of a 3x3 matrix.

    Three real-valued eigenvalues are output in Values, which is an array
    that must be provided by the caller and must be dimensioned large
    enough to hold at least 3 double precision numbers.  
    The caller may pass NULL for the Values argument if the eigenvalues are not wanted.   
    This function always computes three eigenvalues, repeating values in
    the Values array if necessary.

    The eigenvectors corresponding to the eigenvalues are output in
    Vectors, which is an array that must be provided by the caller and
    must be dimensioned large enough to hold at least 3 svxVector
    structures.   
    The caller may pass NULL for the Vectors argument if the
    eigenvectors are not wanted.

    Vectors[i] is the eigenvector corresponding to the eigenvalue
    Values[i], but the eigenvalues are not sorted.   
    The largest or smallest eigenvalue may be in any element of the Values array.

    @param [in] Mat3x3 matrix
    @param [out] Values three real-valued eigenvalues (or NULL)
    @param [out] Vectors three eigenvectors for the eigenvalues (or NULL)

    Returns:
    succeeds:
    -        ZW_API_NO_ERROR
    fails:
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxMatEigen(const double Mat3x3[3][3], double *Values, svxVector *Vectors);

    /**
    @ingroup zwapi_math_matrix

    Initializes "Mat" to the identity matrix.

    @param [out] Mat transformation matrix

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxMatInit(svxMatrix *Mat);

    /**
    @ingroup zwapi_math_matrix

    Output an inverted version of "Mat" via "InvMat".

    @param [in] Mat transformation matrix
    @param [out] InvMat inverted transformation matrix

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern void cvxMatInvert(svxMatrix *Mat, svxMatrix *InvMat);

    /**
    @ingroup zwapi_math_matrix

    Matrix multiply (Mat3 = Mat1 * Mat2).

    @param [in] Mat1 first transformation matrix
    @param [in] Mat2 second transformation matrix
    @param [out] Mat3 resulting matrix

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxMatMult(svxMatrix *Mat1, svxMatrix *Mat2, svxMatrix *Mat3);

    /**
    @ingroup zwapi_math_matrix

    Composes a transformation matrix that defines a reference
    frame whose origin coincides with "Origin", whose Z axis
    points in the direction of "zAxis", with arbitrary X and
    Y axis.

    @param [in] Origin origin
    @param [in] zAxis direction of Z axis
    @param [out] Mat transformation matrix

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxMatPntVec(svxPoint *Origin, svxVector *zAxis, svxMatrix *Mat);

    /**
    @ingroup zwapi_math_matrix

    Compose a transformation matrix that defines a reference frame
    with an origin coinciding with "Origin" and X and Y axes being
    aligned to the directions given by "xAxis" and "yAxis", respectively.  
    The "xAxis" and "yAxis" inputs need not be unit vectors, and as
    long as they are not parallel, they do not have to be perpendicular.

    @param [in] Origin origin, optional
    @param [in] xAxis direction of x axis
    @param [in] yAxis direction of y axis
    @param [out] Mat transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxMatPntVecs(svxPoint *Origin, svxVector *xAxis, svxVector *yAxis, svxMatrix *Mat);

    /**
    @ingroup zwapi_math_matrix

    Gets the origin, x-direction, y-direction and z-direction of matrix.

    @param [in] Mat origin, optional
    @param [out] Origin origin (NULL to ignore)
    @param [out] xAxis x direction (NULL to ignore)
    @param [out] yAxis y direction (NULL to ignore)
    @param [out] zAxis z direction (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxMatGetPntVecs(const svxMatrix *Mat, svxPoint *Origin, svxVector *xAxis, svxVector *yAxis, svxVector *zAxis);

    /**
    @ingroup zwapi_math_matrix

    Initializes a transformation matrix "Mat" to perform rotations
    by the specified angle about the specified axis.

    @param [in,out] Mat transformation matrix
    @param [in] Angle rotation angle (deg)
    @param [in] Axis axis of rotation

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxMatRotate(svxMatrix *Mat, double Angle, svxAxis *Axis);

    /**
    @ingroup zwapi_math_matrix

    Initializes "Mat" so that it will scale points by sX, sY, sZ
    relative to "Point".

    @param [in,out] Mat transformation matrix
    @param [in] Point reference point
    @param [in] sX X scale
    @param [in] sY Y scale
    @param [in] sZ Z scale

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxMatScale(svxMatrix *Mat, svxPoint *Point, double sX, double sY, double sZ);

    /**
    @ingroup zwapi_math_matrix

    Make sure "identity" flag associated with "Mat" is set correctly.

    @param [in,out] Mat transformation matrix

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxMatSetIdentity(svxMatrix *Mat);

    /**
    @ingroup zwapi_math_matrix

    Applies transformation matrix "Mat" to "Frame".

    @param [in] Mat transformation matrix
    @param [in,out] Frame coordinate frame (i.e. transform)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxMatTransform(svxMatrix *Mat, svxMatrix *Frame);

    /**
    @ingroup zwapi_math_matrix

    Initializes "Mat" so that it will translate points by dX, dY, dZ.

    @param [in,out] Mat transformation matrix
    @param [in] dX X distance
    @param [in] dY Y distance
    @param [in] dZ Z distance

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxMatTranslate(svxMatrix *Mat, double dX, double dY, double dZ);

    /**
    @ingroup zwapi_math_matrix

    Initializes "Mat" to the specified standard view.

    @param [out] Mat transformation matrix
    @param [in] Type standard view type

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxMatView(svxMatrix *Mat, evxViewStd Type);

    /**
    @ingroup zwapi_math_matrix

       Conversion Transform Matrix to Euler Angles. Two categories of rotation sequence:        
       1. Proper Euler Angle - when the first and third rotation are around the same axes.      
          121: X-axis, Y-axis, X-axis                                                           
          131: X-axis, Z-axis, X-axis                                                           
          212: Y-axis, X-axis, Y-axis                                                           
          232: Y-axis, Z-axis, Y-axis                                                           
          313: Z-axis, X-axis, Z-axis                                                           
          323: Z-axis, Y-axis, Z-axis                                                           
       2. Tait-Bryan or Roll-Pitch-Yaw Angles - when three rotations are around different axes.  
          123: X-axis (Roll), Y-axis (Pitch), Z-axis (Yaw)                                      
          132: X-axis (Roll), Z-axis (Yaw), Y-axis (Pitch)                                      
          213: Y-axis (Pitch), X-axis (Roll), Z-axis (Yaw)                                      
          231: Y-axis (Pitch), Z-axis (Yaw), X-axis (Roll)                                      
          312: Z-axis (Yaw), X-axis (Roll), Y-axis (Pitch)                                      
          321: Z-axis (Yaw), Y-axis (Pitch), X-axis (Roll)

    @param [in] Seq rotation sequence type, see description
    @param [in] pMat transformation matrix
    @param [out] pzMatEuler Euler angles and translate vector

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxMatToEuler(evxEulerAngSeq Seq, svxMatrix *pMat, svxMatEuler *pzMatEuler);

    /**
    @ingroup zwapi_math_matrix

       Conversion from Euler Angles to Transform Matrix. Two categories of rotation sequence:   
       1. Proper Euler Angle - when the first and third rotation are around the same axes.      
          121: X-axis, Y-axis, X-axis                                                           
          131: X-axis, Z-axis, X-axis                                                           
          212: Y-axis, X-axis, Y-axis                                                           
          232: Y-axis, Z-axis, Y-axis                                                           
          313: Z-axis, X-axis, Z-axis                                                           
          323: Z-axis, Y-axis, Z-axis                                                           
       2. Tait-Bryan or Roll-Pitch-Yaw Angles - when three rotations are around different axes.  
          123: X-axis (Roll), Y-axis (Pitch), Z-axis (Yaw)                                      
          132: X-axis (Roll), Z-axis (Yaw), Y-axis (Pitch)                                      
          213: Y-axis (Pitch), X-axis (Roll), Z-axis (Yaw)                                      
          231: Y-axis (Pitch), Z-axis (Yaw), X-axis (Roll)                                      
          312: Z-axis (Yaw), X-axis (Roll), Y-axis (Pitch)  
          321: Z-axis (Yaw), Y-axis (Pitch), X-axis (Roll)

    @param [in] Seq rotation sequence type, see description
    @param [in] pzMatEuler Euler angles and translate vector
    @param [out] pMat transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxMatFromEuler(evxEulerAngSeq Seq, const svxMatEuler *pzMatEuler, svxMatrix *pMat);


    //====================================================================================================================
    /** @name Object Transformation */
    //====================================================================================================================
    /**
    @ingroup zwapi_math_matrix

    Applies transformation matrix "Mat" to "Point".

    Transform point from local to world space, if *Mat is a local matrix.  
    Transform point form world to local space. if *Mat is the inverse of a local matrix.

    @param [in] Mat transformation matrix
    @param [in,out] Point point

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxPntTransform(svxMatrix *Mat, svxPoint *Point);

    /**
    @ingroup zwapi_math_matrix

    Applies transformation matrix "Mat" to "Point".

    @param [in] Mat transformation matrix
    @param [in] Count number of points to transform
    @param [in] Points list of points to transform

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxPntTransformList(svxMatrix *Mat, int Count, svxPoint *Points);

    /**
    @ingroup zwapi_math_matrix

    Applies transformation matrix "Mat" to "Axis".

    @param [in] Mat transformation matrix
    @param [in,out] Axis axis

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxAxisTransform(svxMatrix *Mat, svxAxis *Axis);

    /**
    @ingroup zwapi_math_matrix

    Applies transformation matrix "Mat" to "Vector".

    @param [in] Mat transformation matrix
    @param [in,out] Vector vector

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxVecTransform(svxMatrix *Mat, svxVector *Vector);

    /**
    @ingroup zwapi_math_matrix

    Applies transformation matrix "Mat" to "Crv".  
    Assumes "Mat" is an affine transform. 

    @param [in] Mat transformation matrix
    @param [in,out] Crv curve

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxCrvTransform(svxMatrix *Mat, svxCurve *Crv);

    /**
    @ingroup zwapi_math_matrix

    Applies transformation matrix "Mat" to "Srf".  
    Assumes "Mat" is an affine transform.

    @param [in] Mat transformation matrix
    @param [in,out] Srf surface

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxSrfTransform(svxMatrix *Mat, svxSurface *Srf);

    /**
    @ingroup zwapi_math_matrix

    Apply the specified transform to the specified bounding box.

    If the bounding box has not been modified since initialized, do nothing.

    @param [in] Mat transformation matrix
    @param [in,out] Box bounding box

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxBndBoxTransform(svxMatrix *Mat, svxBndBox *Box);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MATRIX_H */
