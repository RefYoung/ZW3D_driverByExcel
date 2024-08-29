/**
@file zwapi_brep_shape.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Shape API
*/
/**
@defgroup zwapi_brep_shape Shape API
@ingroup BrepEntityModel
@brief
@details THE MODULE FOR THE ZW3D Shape API
*/

#pragma once
#ifndef ZW_API_SHAPE_H /* this ifndef surrounds entire header */
#define ZW_API_SAHPE_H

#include "zwapi_brep_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Shape Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_shape

    Retrieves attribute data from the specified shell in the active file.
    If index is small than 1 or an inactive object, return 1.

    @param [in] idShape the shell index
    @param [out] At shell attribute data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxShellAtGet(int idShape, svxPartAttribute *At);

    /**
    @ingroup zwapi_brep_shape

    Outputs the attribute of specified item for the specified shell.

    The itemId includes part items of evxAtItemId (VX_AT_USER~VX_AT_HEIGHT).

    When itemId is VX_AT_USER, the name of the user-defined attribute must
    be assigned to At->label before calling this function.  For all other
    itemId values, At->label can be an empty string (At->label[0]=0) when
    this function is called.

    @param [in] idShape the shell index
    @param [in] itemId item id
    @param [in,out] At attribute item data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxShellAtItemGet(int idShape, evxAtItemId itemId, svxAttribute *At);

    /**
    @ingroup zwapi_brep_shape

    Sets the attribute of specified item for the specified shell.

    The itemId includes part items of evxAtItemId (VX_AT_USER~VX_AT_HEIGHT).

    When itemId is VX_AT_USER, the name of the user-defined attribute must
    be assigned to At->label before calling this function.  For all other
    itemId values, At->label can be an empty string (At->label[0]=0) when
    this function is called.

    @param [in] idShape the shell index
    @param [in] itemId item id
    @param [in] At attribute item data to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxShellAtItemSet(int idShape, evxAtItemId itemId, svxAttribute *At);

    /**
    @ingroup zwapi_brep_shape

    Get the flag indicating if shape is open.

    @param [in] idShape shape id (in active file)
    @param [out] isOpen open flag for shape (1=open, 0=closed)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_wRONG_ROOT_ENV
    */
    extern evxErrors cvxPartInqShapeOpen(int idShape, int *isOpen);

    /**
    @ingroup zwapi_brep_shape

    Gets the bounding box of the specified shape in the active file.
    If "*Mat = NULL" && the target object class isn't VX_ROOT_PART(evxRootType),
    the bounding box coordinates are given relative to the global frame of the parent part.

    If the target object class is VX_ROOT_PART && "*Mat = NULL", initializes "Mat" to
    the identity matrix. The "idShape" must belong to the active part, a bounding box
    relative to the specified local coordinate frame is output.

    @see cvxPartInqEntBox,cvxPartInqFaceBox,cvxEntBndBox. The three interfaces have
    similar functions.

    @param [in] idShape shape or face id
    @param [in] Mat optional local frame (or NULL)
    @param [out] Box shape bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqShapeBox(int idShape, svxMatrix *Mat, svxBndBox *Box);

    /**
    @ingroup zwapi_brep_shape

    Calculates mass properties for the specified shape in the active part.
    If Density = 0, the shape's default density is used.

    @param [in] idShape id of shape in active part
    @param [in] Density density (kg/mm^3)
    @param [out] Prop mass properties for specified shape

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqShapeMass(int idShape, double Density, svxMassProp *Prop);

    /**
    @ingroup zwapi_brep_shape

    Outputs the structural attributes of specified shape.

    @param [in] idShape entity id
    @param [out] at structural attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxPartShapeStructGet(int idShape, svxWeldAttr *at);

    //====================================================================================================================
    /** @name Shape Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_shape

    Outputs a list of indices of the shapes that belong to
    the specified part.  The calling procedure MUST deallocate
    the output list with cvxMemFree().

    @param [in] File part file name (File[0]=0 or NULL for active file)
    @param [in] Part part name (Part[0]=0 or NULL for active part)
    @param [out] Count number of shapes
    @param [out] Shapes list of shape id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartInqShapes(const vxLongPath File, const vxRootName Part, int *Count, int **Shapes);

    /**
    @ingroup zwapi_brep_shape

    Outputs the id of the component from which the specified shape
    was merged.  Outputs "idComp = 0" if the shape was not merged
    from a component.

    @param [in] idShape shape id (in active file)
    @param [out] idComp shape's parent component (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartInqShapeComp(int idShape, int *idComp);

    /**
    @ingroup zwapi_brep_shape

    Outputs a list of indices of the edges that belong to
    the specified shape in the active file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idShape shape id
    @param [out] Count number of edges
    @param [out] Edges list of edge id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqShapeEdges(int idShape, int *Count, int **Edges);

    /**
    @ingroup zwapi_brep_shape

    Outputs a list of indices of the faces that belong to
    the specified shape in the active file.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idShape shape id
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
    extern evxErrors cvxPartInqShapeFaces(int idShape, int *Count, int **Faces);

    /**
    @ingroup zwapi_brep_shape

    Outputs a list of indices of the features associated with the
    specified shape in the active part. By default (Option = 0),
    this includes features that generate the shape, features on
    which the generative features are dependent for their definition
    and features that modify attributes of the shape.  If "Option=1",
    only features that generate shape geometry are output, insofar as
    that classification can be made.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idShape shape id
    @param [in] Option 0-get all dependencies; 1-get just shape generating features
    @param [out] Count number of features
    @param [out] Features list of feature id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxPartInqShapeFtrs(int idShape, int Option, int *Count, int **Features);

    /**
    @ingroup zwapi_brep_shape

    Gets the extreme point of shape in the specified direction, if the farthest
    end of the specified direction are faces or edges, the function also outputs
    the list of faces or edges, in this case, the extreme point output is only any
    point on a face or edge.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idShape id of shape in active part
    @param [in] Dir direction
    @param [out] Count number of faces or edges (NULL to ignore)
    @param [out]  idEnts list of faces or edges (NULL to ignore)
    @param [out] Point extreme point (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_output
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartInqShapeExtreme(int idShape, const svxVector *Dir, int *Count, int **idEnts, svxPoint *Point);

    /**
    @ingroup zwapi_brep_shape

    Outputs the transformation matrix associated with the specified shape,
    which was inserted from a part by command "CdInstPartAsShp".
    Now this function is just used for Misumi modify shape.

    @param [in] idShape shape id
    @param [out] Matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxInstShpGetMatrix(int idShape, svxMatrix *Matrix);

    //====================================================================================================================
    /** @name Entity Query Shape */
    //====================================================================================================================
    /**
    @ingroup zwapi_brep_shape

    Outputs the id of the shape that the specified face
    or edge (idEntity) belongs to.  It is assumed the
    entity resides in the active object.  If "idShape = 0"
    is output, the entity could not be located or didn't
    belong to a faceset.

    @param [in] idEntity entity id (in active file)
    @param [out] idShape shape id (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    extern evxErrors cvxPartInqEntShape(int idEntity, int *idShape);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_H */
