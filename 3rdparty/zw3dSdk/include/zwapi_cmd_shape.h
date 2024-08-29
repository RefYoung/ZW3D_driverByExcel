/**
@file zwapi_cmd_shape.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Shape Commands of Part API
*/
/**
@defgroup zwapi_cmd_shape Shape Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Shape Commands of Part API
*/

#pragma once
#ifndef ZW_API_SHAPE_FTR_H /* this ifndef surrounds entire header */
#define ZW_API_SHAPE_FTR_H

#include "zwapi_cmd_shape_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Basic Shape */
    //====================================================================================================================
    /**********************************************************************
    *! -Sketch- : zwapi_cmd_sk_create.h
    *  extern int cvxPartSkNew(svxMatrix* Plane, int* idEnt);
    *  extern int cvxPartSkPlane(svxSketchData* SkData, int* idSketch);
    **********************************************************************/

    /**********************************************************************
    *! -Cosmetic Sketch- : zwapi_cmd_sk_create.h
    *  extern int cvxPartSkNew(svxMatrix* Plane, int* idEnt);
    *  extern int cvxPartSkPlane(svxSketchData* SkData, int* idSketch);
    **********************************************************************/

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartBox().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data box data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartBoxInit(svxBoxData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates a box shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Box->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".

    @note
    Interface cvxPartBoxInit() can initialize variables of this function.  
    This command doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Box box definition
    @param [out] idShape id of new shape

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartBox(svxBoxData *Box, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartCyl().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data cylinder data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCylInit(svxCylData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates a cylinder shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Cyl->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".

    @note
    Interface cvxPartCylInit() can initialize variables of this function.  
    This command doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Cyl cylinder definition
    @param [out] idShape id of new shape(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCyl(svxCylData *Cyl, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartCone().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data cone data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartConeInit(svxConeData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates a cone shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Cone->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".

    @note
    Interface cvxPartConeInit() can initialize variables of this function.  
    This command doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Cone cone definition
    @param [out] idShape id of new shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCone(svxConeData *Cone, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartSphere().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data sphere data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSphereInit(svxSphereData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates a sphere shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Sphere->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".

    @note
    Interface cvxPartSphereInit() can initialize variables of this function.  
    This command doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Sphere sphere definition
    @param [out] idShape id of new shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSphere(svxSphereData *Sphere, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartEllipsoid().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data ellipsoid data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartEllipsoidInit(svxEllsoData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates a ellipsoid shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Ellso->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".

    @note
    Interface cvxPartEllipsoidInit() can initialize variables of this function.  
    This command doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Ellso ellipsoid definition
    @param [out] idShape id of new shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartEllipsoid(svxEllsoData *Ellso, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartExtrude().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data extruded shape data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartExtrudeInit(svxExtrudeData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates an extruded shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Ext->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".  If multiple shapes
    could be created, use cvxEntNewList() to get their id's.

    @note
    Interface cvxPartExtrudeInit() can initialize variables of this function.  
    cvxPartExtrude doesn't support multi-base shape since R2024 when boolean type 
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and 
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Ext extrusion input data
    @param [out] idShape id of new shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartExtrude(svxExtrudeData *Ext, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartRevolve().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data revolved shape data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartRevolveInit(svxRevolveData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates a revolved shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Ext->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".  If multiple shapes
    could be created, use cvxEntNewList() to get their id's.

    @note
    Interface cvxPartRevolveInit() can initialize variables of this function.  
    cvxPartRevolve doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Rev input data
    @param [out] idShape id of new shape

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
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartRevolve(svxRevolveData *Rev, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartSweep().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data swept shape data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSweepInit(svxSweepData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates a swept shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Ext->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".  If multiple shapes
    could be created, use cvxEntNewList() to get their id's.

    @note
    Interface cvxPartSweepInit() can initialize variables of this function.  
    cvxPartSweep doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Swp sweep input data
    @param [in] Options data pointer reserved for future use (input NULL)
    @param [out] idShape id of new shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxPartSweep(svxSweepData *Swp, void *Options, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartSpiralSweep().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data spiral sweep shape data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSpiralSweepInit(svxSpiralSweepData *data);

    /**
    @ingroup zwapi_cmd_shape

    Creates a spiral sweep shape and adds it to the active part using the
    specified combination method.  If "idShape" is not NULL and
    "Ext->Combine = V_BOOL_NONE", the id of the shape created
    by this function is output via "idShape".  If multiple shapes
    could be created, use cvxEntNewList() to get their id's.

    @note
    Interface cvxPartSpiralSweepInit() can initialize variables of this function.  
    cvxPartSpiralSweep doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] SpiralSwp sweep input data
    @param [out] idShape id of new shape (NULL to ignore)
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSpiralSweep(const svxSpiralSweepData *SpiralSwp, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartLoft().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command loft data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartLoftInit(svxLoftData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to create a loft feature.

    @note
    Interface cvxPartLoftInit() can initialize variables of this function.  
    cvxPartLoft doesn't support multi-base shape since R2024 when boolean type
    is VX_BOOL_ADD, and it will set the boolean type to VX_BOOL_NONE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @param [in] Loft loft input data
    @param [out] idShape id of new shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartLoft(svxLoftData *Loft, int *idShape);


    //====================================================================================================================
    /** @name Engineering Feature */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_shape

    Adds fillets to the specified edges.

    Use cvxPartPartialResults() to disable/enable the prompt to
    calculate/display partial results for failed fillets.

    @param [in] Count number of edges to fillet
    @param [in] Edges pointer to list of edge id's
    @param [in] Radius fillet radius

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFillet(int Count, int *Edges, double Radius);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartFilletAll().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data chamfer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartFilletAllInit(svxChamFlltData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use the function to create symmetric and asymmetric fillets.

    @note
    Interface cvxPartFilletAllInit() can initialize variables of this function.

    @param [in] Fillet fillet data
    @param [out] idFillet index of new fillet feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFilletAll(const svxChamFlltData *Fillet, int *idFillet);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartFaceFillet().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data face fillet data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartFaceFilletInit(svxFaceFlltData *data);

    /**
    @ingroup zwapi_cmd_shape

    Create fillet by the input faces and other variables.

    @note
    Interface cvxPartFaceFilletInit() can initialize variables of this function.

    @param [in] data face fillet data
    @param [out] idFillet index of new fillet feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFaceFillet(const svxFaceFlltData *data, int *idFillet);

    /**
    @ingroup zwapi_cmd_shape

    Adds chamfers to the specified edges.

    @param [in] Count number of edges to chamfer
    @param [in] Edges pointer to list of edge id's
    @param [in] Setback setback (mm)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartChamConst(int Count, int *Edges, double Setback);

    /**
    @ingroup zwapi_cmd_shape

    Adds chamfers to the specified edges.

    @param [in] Count number of edges to chamfer
    @param [in] Edges pointer to list of edge id's
    @param [in] idFace id of face on first side of chamfer
    @param [in] Setback setback (mm) on first side of chamfer
    @param [in] Angle angle of chamfer (deg)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartChamAng(int Count, int *Edges, int idFace, double Setback, double Angle);

    /**
    @ingroup zwapi_cmd_shape

    Adds chamfers to the specified edges.

    @param [in] Count number of edges to chamfer
    @param [in] Edges pointer to list of edge id's
    @param [in] idFace id of face on first side of chamfer
    @param [in] Setback1 setback (mm) on first side of chamfer
    @param [in] Setback2 setback (mm) on second side of chamfer

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartChamAsym(int Count, int *Edges, int idFace, double Setback1, double Setback2);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the svxChamFlltSetData structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data set-list data for chamfer or fillet command

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxChamFlltSetDataInit(svxChamFlltSetData *data);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartChamferAll().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data chamfer data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartChamferAllInit(svxChamFlltData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use the function to create symmetric and asymmetric chamfers.

    @note
    Interface cvxPartChamferAllInit() can initialize variables of this function.

    @param [in] Chamfer chamfer data
    @param [out] idChamfer index of new chamfer feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartChamferAll(const svxChamFlltData *Chamfer, int *idChamfer);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartDraft().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] method draft method
    @param [out] data template command Draft data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDraftInit(evxDraftMethods method, svxDraftData *data);

    /**
    @ingroup zwapi_cmd_shape

    Adds the specified draft(s) to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idDraft" if the output is not required.

    @note
    Interface cvxPartDraftInit() can initialize variables of this function.

    @param [in] Draft Draft Data
    @param [out] idDraft id of feature operation that created Draft (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OBJ
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartDraft(const svxDraftData *Draft, int *idDraft);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartHole().

    HoleOpt = VX_CLEARANCE_HOLE,type use evxClearHoleType;
    else type use evxHoleType.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] HoleOpt hole method
    @param [in] type hole shape type(see description)
    @param [out] data hole data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartHoleInit(evxHoleOpt HoleOpt, int type, svxHoleData *data);

    /**
    @ingroup zwapi_cmd_shape

    Adds the specified hole(s) to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idOp" if the output is not required.

    @note
    Interface cvxPartHoleInit() can initialize variables of this function.

    @param [in] Data hole data
    @param [out] idOp id of feature operation that created hole

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartHole(svxHoleData *Data, int *idOp);

    /**
    @ingroup zwapi_cmd_shape

    Use the first input face to initialize the parameters of the cvxPartModifyHole().
    It will get the hole data of the input face to initialize the data.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] idFace id face of the specified hole
    @param [out] data hole data to initialize

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartModifyHoleInit(int idFace, svxHoleData *data);

    /**
    @ingroup zwapi_cmd_shape

    Modify the hole data of the input hole faces.

    @note
    Interface cvxPartModifyHoleInit() can initialize variables of this function.

    @param [in] cntFace count of the face to modify
    @param [in] pFace face list
    @param [in] data hole data
    @param [out] idFtr index of the new feature(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartModifyHole(int cntFace, int *pFace, const svxHoleData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartFlagHoles().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data flag hole data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartFlagHolesInit(svxFlagHoleData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use the Flag Hole command to assign hole attributes so drawing
    sheets will recognize these features as holes.

    @note
    Interface cvxPartFlagHolesInit() can initialize variables of this function.

    @param [in] data flag hole data
    @param [out] idFtr feature id (pass in NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFlagHoles(const svxFlagHoleData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartRib().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command rib data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartRibInit(svxRibData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to create a rib feature using an open profile sketch,
    curve, edge or curve list. The required inputs include the profile,
    rib thickness, draft angle, boundary faces and the draft plane.
    The boundary faces can limit or expand the extent of the rib feature.

    @note
    Interface cvxPartRibInit() can initialize variables of this function.

    @param [in] Rib rib input data
    @param [out] idRib id of rib feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartRib(svxRibData *Rib, int *idRib);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartFlagExtThread().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data flag ext thread data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartFlagExtThreadInit(svxFlagExtThreadData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use the Flag Ext Thread command to assign hole attributes so drawing
    sheets will recognize these features as holes.but only visible in 3D.

    @note
    Interface cvxPartFlagExtThreadInit() can initialize variables of this function.

    @param [in] data flag ext thread data
    @param [out] idFtr feature id (pass in NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFlagExtThread(const svxFlagExtThreadData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartThreadAt().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data thread definition data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartThreadAtInit(svxThreadData *data);

    /**
    @ingroup zwapi_cmd_shape

    Adds thread attribute data (Thread) to the specified face (idFace)
    of the active part.  The thread is placed on the end of the face
    nearest the input reference point (Pnt). A cosmetic representation
    of the thread displayed. Actual geometry representing the thread is
    not created.

    Interface cvxPartThreadAtInit() can initialize variables of this function.

    @note
    cvxPartFlagExtThread() interface has the same function as this interface.
    Users can use the cvxPartFlagExtThread() interface to set more parameters.

    @param [in] idFace face id
    @param [in] Pnt point on or near face identifying thread location
    @param [in] Thread thread definition

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartThreadAt(int idFace, svxPoint *Pnt, svxThreadData *Thread);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartLip().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command lib data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartLipInit(svxLipData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to create a constant lip feature along selected edges
    based on two offset distances. The required inputs include the face edges
    to feature and the 1st and 2nd offsets.

    @note
    Interface cvxPartLipInit() can initialize variables of this function.

    @param [in] Lip lip input data
    @param [out] idLip id of lip feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartLip(svxLipData *Lip, int *idLip);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartStock().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command stock data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartStockInit(svxStockData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to create an extruded stock feature that completely
    encloses faces, shapes or blocks.

    @note
    Interface cvxPartStockInit() can initialize variables of this function.

    @param [in] Stock stock input data
    @param [out] idShape id of stock shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartStock(svxStockData *Stock, int *idShape);


    //====================================================================================================================
    /** @name Edit Shape */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_shape

    Offset a face with distance "Dis".  Original surface will be deleted
    if "Keep=0".

    @param [in] idFace face id
    @param [in] Dis offset distance
    @param [in] Keep 1 to keep "Original surface"; 0 to delete it

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartFaceOffset(int idFace, double Dis, int Keep);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartShapeFaceOffset().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data shape face offset data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartShapeFaceOffsetInit(svxFaceOffData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to offset one or more faces of a shape.

    @note
    Interface cvxPartShapeFaceOffsetInit() can initialize variables of this function.

    @param [in] Offset face offset input data
    @param [out] idOffset id of offset feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartShapeFaceOffset(svxFaceOffData *Offset, int *idOffset);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartShell().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Shell input data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartShellInit(svxShellData *data);

    /**
    @ingroup zwapi_cmd_shape

    Adds the specified shell(s) to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idShell" if the output is not required.

    @note
    Interface cvxPartShellInit() can initialize variables of this function.

    @param [in] Shell Shell data
    @param [out] idShell id of feature operation that created Shell (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OBJ
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartShell(const svxShellData *Shell, int *idShell);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartThicken().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command thicken data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartThickenInit(svxThickenData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to create a thicken feature.

    @note
    Interface cvxPartThickenInit() can initialize variables of this function.

    @param [in] Thicken thicken input data
    @param [out] idShape id of thicken shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartThicken(svxThickenData *Thicken, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Combines one or more shapes with a base shape using a boolean operation.

    @param [in] Type boolean combination method
    @param [in] idBase id of base shape
    @param [in] Count no. of shapes to combine with "idBase"
    @param [in] Shapes list of id's of shapes to combine with "idBase"
    @param [in] Keep 1 to keep "Shapes"; 0 to delete them

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartBool(evxBoolType Type, int idBase, int Count, int *Shapes, int Keep);

    /**
    @ingroup zwapi_cmd_shape

    Combines one or more operator shapes with one or more base
    shapes using the specified boolean combination method. The
    resulting shape(s) are output via "ResultList".

    The memory referenced by "ResultList" is allocated by this function.
    The calling procedure is responsible to free the memory
    referenced by "ResultList" (cvxMemFree((void**)ResultList)).

    If you do not need the list of output shapes, input NULL
    for "ResultCount" and "ResultList" and no list of results
    will be output by this function.

    @param [in] Type boolean combination method
    @param [in] BaseCount number of base shapes
    @param [in] BaseList list of base shape id's
    @param [in] OpCount number of operator shapes
    @param [in] OpList list of operator shape id's
    @param [out] ResultCount number of resulting shapes (NULL to ignore)
    @param [out] ResultList list of id's of resulting shapes (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    extern evxErrors cvxPartBool2(evxBoolType Type, int BaseCount, int *BaseList, int OpCount, int *OpList, int *ResultCount, int **ResultList);

    /**
    @ingroup zwapi_cmd_shape

    Combines one or more operator shapes with one or more base
    shapes using the specified boolean combination method.
    If bounding faces are defined (FaceCount and FaceList), an
    attempt is made to limit the resulting shapes to the regions
    between the bounding faces.

    The resulting shape(s) are output via "ResultList".  The memory
    referenced by "ResultList" is allocated by this function.

    The calling procedure is responsible to free the memory
    referenced by "ResultList" (cvxMemFree((void**)ResultList)).

    If you do not need the list of output shapes, input NULL
    for "ResultCount" and "ResultList" and no list of results
    will be output by this function.

    @param [in] Type boolean combination method
    @param [in] BaseCount number of base shapes
    @param [in] BaseList list of base shape id's
    @param [in] OpCount number of operator shapes
    @param [in] OpList list of operator shape id's
    @param [in] FaceCount number of bounding faces (0 if undefined)
    @param [in] FaceList list of bounding faces (NULL if undefined)
    @param [out] ResultCount number of resulting shapes (NULL to ignore)
    @param [out] ResultList list of id's of resulting shapes (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INVALID_OBJ
    */
    extern evxErrors cvxPartBool3(evxBoolType Type, int BaseCount, int *BaseList, int OpCount,
                                  int *OpList, int FaceCount, int *FaceList, int *ResultCount, int **ResultList);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartDivide().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command divide data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDivideInit(svxDivideData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to divide a solid or open shape where it intersects with faces,
    shapes, or datum planes.   
    The result will be two distinct solids or shapes.   
    This function can also divide an open shape or result in one or more open shapes.

    @note
    Interface cvxPartDivideInit() can initialize variables of this function.  
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] Divide divide input data
    @param [out] numShape number of resulting shapes (NULL to ignore)
    @param [out] idShapes list of id's of resulting shapes (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartDivide(svxDivideData *Divide, int *numShape, int **idShapes);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartTrim().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Trim data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartTrimInit(svxTrimData *data);

    /**
    @ingroup zwapi_cmd_shape

    Trim a shape by the input trimming data. The trimming face/faceset should
    extend outside the boundaries of the base face/faceset.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @note
    Interface cvxPartTrimInit() can initialize variables of this function.

    @param [in] Trim trim input data
    @param [out] numShape number of resulting shapes (NULL to ignore)
    @param [out] idShapes list of id's of resulting shapes (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartTrim(svxTrimData *Trim, int *numShape, int **idShapes);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to simplify a part by removing specified faces. The function will
    attempt to extend and reconnect faces to close the resulting gaps in the part.

    @param [in] numEnts number of face or feature to remove and gap edges to fill
    @param [in] idEnts list of id's of face or feature to remove and gap edges to fill
    @param [out] idSimplify id of simplify feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSimplify(int numEnts, int *idEnts, int *idSimplify);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartReplace().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data shape replace data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartReplaceInit(svxReplaceData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to replace one or more faces of a shape.

    @note
    Interface cvxPartReplaceInit() can initialize variables of this function.

    @param [in] Replace replace input data
    @param [out] idReplace id of replace feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartReplace(const svxReplaceData *Replace, int *idReplace);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartInlay().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command inlay data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartInlayInit(svxInlayData *data);

    /**
    @ingroup zwapi_cmd_shape

    The function is used to embed a set of closed loops of curves, as it would
    be generated by an outline text font, into a face and then offset the new
    interior faces created by the desired distance, giving a raised or sunken
    text effect. it will create new faces, edges, vertices, etc., allowing for
    sharp transitions from the raised surfaces to the base surface.

    @note
    Interface cvxPartInlayInit() can initialize variables of this function.

    @param [in] Inlay inlay input data
    @param [out] idInlay id of inlay feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartInlay(svxInlayData *Inlay, int *idInlay);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the svxPartSelfX structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data  part resolve self intersection data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxPartSelfXInit(svxPartSelfX *data);

    /**
    @ingroup zwapi_cmd_shape

    The corresponding function of this interface is Shape->Resolve SelfX.

    Use this function to remove self intersections and inverted regions 
    (including inverted inner loop cases) on selected faces as well as can be done.

    Faces that intersect other faces in the shape will be split and 
    the unnecessary faces will be removed. The shape will not be split.

    @note
    Interface cvxPartSelfXInit() can initialize variables resolve self intersection 
    of this function.

    @param [in] data     part resolve self intersection data 
    @param [out] idShape id of shape feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSelfX(const svxPartSelfX *data, int *idShape);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the svxPunch structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data  part punch data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxPartPunchInit(svxPunch *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to perform a punch operation between two shapes.

    @note
    Interface cvxPartPunchInit() can initialize variables resolve self intersection
    of this function.

    @param [in] data
    @param [out] idPunch

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartPunch(const svxPunch *data, int *idPunch);

    //====================================================================================================================
    /** @name Morph */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartTwist().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data shape twist data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartTwistInit(svxTwistData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to twist shapes along specified axis.

    @note
    Interface cvxPartTwistInit() can initialize variables of this function.

    @param [in] Twist twist input data
    @param [out] idTwist id of Twist feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartTwist(const svxTwistData *Twist, int *idTwist);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartTaper().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data shape taper data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartTaperInit(svxTaperData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to taper shape and make it smaller in specified side.

    @note
    Interface cvxPartTaperInit() can initialize variables of this function.

    @param [in] Taper taper input data
    @param [out] idTaper id of taper feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartTaper(const svxTaperData *Taper, int *idTaper);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartStretch().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data shape stretch data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartStretchInit(svxStretchData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to stretch shape along X, Y and Z direction in specified range.

    @note
    Interface cvxPartStretchInit() can initialize variables of this function.

    @param [in] Stretch stretch input data
    @param [out] idStretch id of Stretch feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartStretch(const svxStretchData *Stretch, int *idStretch);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartMorphToCrv().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data shape morph to curve data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartMorphToCrvInit(svxMorphToCrvData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to transforms (morphs) shapes by warping face geometry.

    @note
    Interface cvxPartMorphToCrvInit() can initialize variables of this function.

    @param [in] MorphToCrv morph to curve input data
    @param [out] idMorphToCrv id of morph to curve feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartMorphToCrv(const svxMorphToCrvData *MorphToCrv, int *idMorphToCrv);


    //====================================================================================================================
    /** @name Basic Editing */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_shape

    Initialize the svxPtnData structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type pattern type
    @param [out] data pattern data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPtnDataInit(evxPatternType type, svxPtnData *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to pattern any combination of shapes, faces, curves, points,
    text, sketches, datum planes and patterns of patterns. eight different methods
    of patterning are available, each method requires different types of input.

    @note
    Interface cvxPtnDataInit() can initialize variables(Pattern.inpData) of this function.

    @param [in] Count number of entities for pattern
    @param [in] idEnts list of id's of entities (supported entities include:
                       shape,face,curve,point,sketch,datum plane,datum axis,datum CSYS)
    @param [in] Pattern pattern input data
    @param [out] idPattern id of pattern feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartPatternGeom(int Count, int *idEnts, const svxPtnGeom *Pattern, int *idPattern);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the svxPtnVarTbl structure.

    pCell of ptnVarTbl will be initialized to the postion of the pattern instance, the position defined 
    like this (such as: first direction x number is 3 and second direction y number is 2, B is the base feature):
    @verbatim
    -----------
    y
    ^ * O O      if the '*' should be modified, pCell[i] = 1;
    | B & O      if the '&' should be modified, pCell[i] = 10000;
    |-------> x

    normally pCell[i] = x*10000+y; and B(0,0) can't be modified.
    @endverbatim

    pVal of ptnVarTbl will be initialized to the value of the dimension.

    @note
    Do not assign a value to variable "ptnVarTbl" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.  
    The calling procedure MUST deallocate the output list pCell and pVal with cvxMemFree.

    @param [in] firstNum first direction patterned number
    @param [in] secondNum second direction patterned number
    @param [in] dimName the name of the dimension to be modified
    @param [out] ptnVarTbl table pattern data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPtnVarTblInit(int firstNum, int secondNum, const char *dimName, svxPtnVarTbl *ptnVarTbl);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to pattern any combination of features. eight different methods
    of patterning are available, each method requires different types of input.

    @note
    Interface cvxPtnDataInit() can initialize variables(Pattern.inpData) of this function.   
    Interface cvxPtnVarTblInit() can initialize table variables(svxPtnVarTbl), cvxPtnDataInit() should be called 
    before this Interface.

    @param [in] Count number of entities for pattern
    @param [in] idFtrs list of id's of features
    @param [in] Pattern pattern input data
    @param [out] idPattern id of pattern feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartPatternFtr(int Count, int *idFtrs, const svxPtnFtr *Pattern, int *idPattern);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartMirrorGeom().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data mirror geometry data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartMirrorGeominit(svxMirrorGeom *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to mirror any combination of shapes, components, curves, points,
    sketches and datum planes.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @note
    Interface cvxPartMirrorGeomInit() can initialize variables of this function.

    @param [in] Mirror mirror geometry input data
    @param [out] NumNewEnts number of new entities (NULL to ignore)
    @param [out] idNewEnts list of id's of new entities (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartMirrorGeom(svxMirrorGeom *Mirror, int *NumNewEnts, int **idNewEnts);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartMirrorFtr().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data mirror feature data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartMirrorFtrInit(svxMirrorFtr *data);

    /**
    @ingroup zwapi_cmd_shape

    Use this function to mirror features.

    @note
    Interface cvxPartMirrorFtrInit() can initialize variables of this function.

    @param [in] Mirror mirror feature input data
    @param [out] idFtr id of mirror feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartMirrorFtr(svxMirrorFtr *Mirror, int *idFtr);

    /**
    @ingroup zwapi_cmd_shape

    Moves the specified geometry within the active part from one point
    "Start->Pnt" to another "End->Pnt".   
    It also changes the orientation of the part based on "Start->Dir" and "End->Dir".    
    If the directions are same, the orientation of the geometry is not changed -- it is simply
    translated.

    @param [in] idEntity id of geometry entity to move
    @param [in] Start start point and direction
    @param [in] End end point and direction

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartMovePntToPnt(int idEntity, svxAxis *Start, svxAxis *End);

    /**
    @ingroup zwapi_cmd_shape

    Applies the specified general transformation to a geometry entity,
    moving the entity within the active part.

    If "Mat" includes scaling, the scale factors are ignored.

    @param [in] idEntity id of geometry entity to move
    @param [in] Mat transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartMoveTransform(int idEntity, const svxMatrix *Mat);

    /**
    @ingroup zwapi_cmd_shape

    Applies the specified general transformation to a list of geometry
    entities, moving the entities within the active part.

    "Entities" may be NULL only if "Count" is 0.

    If "Mat" includes scaling, the scale factors are ignored.

    It is not an error if "Count" is 0.

    @param [in] Count number of entities to transform
    @param [in] Entities list of geometry entity ids
    @param [in] Mat transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -
    */
    extern evxErrors cvxPartMoveTransformList(int Count, const int *Entities, const svxMatrix *Mat);

    /**
    @ingroup zwapi_cmd_shape

    Adds the specified Move(s) to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idMove" if the output is not required.

    @param [in] Move Move data
    @param [out] idMove Move feature id (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartMove(const svxMoveData *Move, int *idMove);

    /**
    @ingroup zwapi_cmd_shape

    Copies the specified geometry within the active part along specified
    direction "Dir" with distance "Dis".  If "idCopy" is not NULL, the id
    of the new copy is output.

    @param [in] idEntity id of geometry entity to copy
    @param [in] Dir direction
    @param [in] Dis distance
    @param [out] idCopy id of copied entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCopyDirDis(int idEntity, svxVector *Dir, double Dis, int *idCopy);

    /**
    @ingroup zwapi_cmd_shape

    Copies the specified geometry within the active part from one point
    "Start->Pnt" to another "End->Pnt".  It also changes the orientation
    of the part based on "Start->Dir" and "End->Dir".   If the directions
    are same, the orientation of the geometry is not changed -- it is simply
    translated.  If "idCopy" is not NULL, the id of the new copy is output.

    @param [in] idEntity id of geometry entity to copy
    @param [in] Start start point and direction
    @param [in] End end point and direction
    @param [out] idCopy id of copied entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCopyPntToPnt(int idEntity, svxAxis *Start, svxAxis *End, int *idCopy);

    /**
    @ingroup zwapi_cmd_shape

    Copies the specified geometry entity and applies the specified general
    transformation to the copy, moving the copy within the active part.
    If "idCopy" is not NULL, the id of the new copy is output.

    If "Mat" includes scaling, the scale factors are ignored.

    @param [in] idEntity id of geometry entity to copy
    @param [in] Mat transformation matrix
    @param [out] idCopy id of new entity (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCopyTransform(int idEntity, const svxMatrix *Mat, int *idCopy);

    /**
    @ingroup zwapi_cmd_shape

    Copies the specified geometry entities and applies the specified general
    transformation to the copy, moving the copy within the active part.The calling
    procedure MUST deallocate the output list with cvxMemFree().

    If "Mat" includes scaling, the scale factors are ignored.

    @param [in] Count number of entities to transform
    @param [in] Entities list of geometry entity ids
    @param [in] Mat transformation matrix
    @param [out] EntCnt number of new entities (NULL to ignore)
    @param [out] idList id of new entities (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCopyTransformList(const int Count, const int *Entities, const svxMatrix *Mat, int *EntCnt, int **idList);

    /**
    @ingroup zwapi_cmd_shape

    Initialize the parameters of the cvxPartCopy().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Copy data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartCopyInit(svxCopyData *data);

    /**
    @ingroup zwapi_cmd_shape

    Adds the specified Copy(s) to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idCopy" if the output is not required.

    @note
    Interface cvxPartCopyInit() can initialize variables of this function.

    @param [in] Copy Copy data
    @param [out] idCopy Copy feature id (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartCopy(const svxCopyData *Copy, int *idCopy);

    /**
    @ingroup zwapi_cmd_shape

    Scales the specified entities in the active part by the
    input scale factors relative to the X, Y, Z axes and origin
    of the active part. 

    If "idDatum > 0", the entities(idEnts)
    are scaled relative to the origin and the X, Y, Z axes of
    the reference plane.

    @param [in] Count number of entities
    @param [in] idEnts list of entity id's
    @param [in] X_scale X scale factor
    @param [in] Y_scale Y scale factor
    @param [in] Z_scale Z scale factor
    @param [in] idDatum optional datum plane entity (input 0 to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartScale(int Count, int *idEnts, double X_scale, double Y_scale, double Z_scale, int idDatum);

    /**
    @ingroup zwapi_cmd_shape

    Scales the specified entities in the active part by the
    input scale factors relative to the X, Y, Z axes and origin
    of the active part.

    If "idDatum > 0", the entities(idEnts)
    are scaled relative to the origin and the X, Y, Z axes of
    the reference plane.

    @param [in] Count number of entities
    @param [in] idEnts list of entity id's
    @param [in] X_scale X scale factor
    @param [in] Y_scale Y scale factor
    @param [in] Z_scale Z scale factor
    @param [in] idDatum optional datum plane entity (input 0 to ignore)
    @param [in] CentPnt optional center point entity (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartScale2(int Count, int *idEnts, double X_scale, double Y_scale, double Z_scale, int idDatum, svxPoint *CentPnt);

    /**
    @ingroup zwapi_cmd_shape

    Get spacing variables of specified pattern feature.

    @note
    The calling procedure MUST deallocate the output varList with cvxMemFree.
    When spacingType = 1, varList maybe NULL and varNumber maybe 0 after calling this function.
    Because pattern feature may not set second direction.

    @param [in] idPatternFeature pattern feature
    @param [in] spacingType 0 - get first direction's spacing variable list, 1 - get second direction's spacing variable list
    @param [out] varList list of spacing variables
    @param [out] varNumber number of spacing variables

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPtnSpacingTableVariableGet(int idPatternFeature, int spacingType, double **varList, int *varNumber);

    /**
    @ingroup zwapi_cmd_shape

    Set spacing variables of specified pattern feature.

    @note
    If pattern feature specified by idPatternFeature doesn't set second direction,
    this function will return ZW_API_INVALID_OUTPUT when spacingType = 1.
    After calling this function, you need to call "cvxCmdSend("$CdPlayAutoAut");" to regen pattern feature.

    @param [in] idPatternFeature id of pattern feature
    @param [in] spacingType 0 - get first direction's spacing variable list, 1 - get second direction's spacing variable list
    @param [in] varList list of spacing variables
    @param [in] varNumber number of spacing variables

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPtnSpacingTableVariableSet(int idPatternFeature, int spacingType, const double *varList, int varNumber);

    /**
    @ingroup zwapi_cmd_shape

    Get parameter table from pattern feature specified by idPatternFeature.

    pCell of ptnVarTbl will be initialized to the postion of the pattern instance, the position defined
    like this (such as: first direction x number is 3 and second direction y number is 2, B is the base feature):
    @verbatim
    -----------
    y
    ^ * O $      if the '*' should be modified, pCell[i] = 1;
    | B & O      if the '&' should be modified, pCell[i] = 10000;
    |-------> x  if the '$' should be modified, pCell[i] = 20001;

    normally pCell[i] = x*10000+y; and B(0,0) can't be modified.
    @endverbatim

    pVal of ptnVarTbl will be initialized to the value of the dimension.

    @note
    Do not assign a value to variable "ptnVarTbl" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.
    The calling procedure MUST deallocate the output valTbl with cvxPtnVarTblMemFree.

    @param [in] idPatternFeature id of pattern feature
    @param [out] paramTblType type of parameter table, 0 - Parameter increment table, 1 - Instance parameter table
    @param [out] valTbl column list of parameter table
    @param [out] columnNumber number of table column

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OBJ
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPtnParameterTableVariableGet(int idPatternFeature, int *paramTblType, svxPtnVarTbl **valTbl, int *columnNumber);

    /**
    @ingroup zwapi_cmd_shape

    Set parameter to parameter table of pattern feature.

    @note
    After calling this function, you need to call "cvxCmdSend("$CdPlayAutoAut");" to regen pattern feature.

    @param [in] idPatternFeature id of pattern feature
    @param [in] row row of table where the cell you want to modified is located in. start from 0.
    @param [in] column column of table where the cell you want to modified is located in. start from 0.
    @param [in] value value you want to set on specified cell

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OBJ
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPtnParameterTableVariableSet(int idPatternFeature, int row, int column, double value);

    /**
    @ingroup zwapi_cmd_shape

    Frees memory at valTbl, valTbl.pCell and valTbl.pVal.

    @param [in] valTbl column list of parameter table
    @param [in] columnNumber number of table column

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxPtnVarTblMemFree(svxPtnVarTbl **valTbl, int columnNumber);

    //====================================================================================================================
    /** @name Datum */
    //====================================================================================================================
/**********************************************************************
*! -Datum Axis- : zwapi_cmd_datum.h
*  extern int cvxPartAxisNew(svxAxisData *Axis, int *idAxis);
**********************************************************************/

/**********************************************************************
*! -Datum Plane- : zwapi_cmd_datum.h
*  extern int cvxPartDatum(svxMatrix* Frame, int* idDatum);
*  extern int cvxPartDatum2(svxMatrix* Frame, int iCode, int* idDatum);
*  extern int cvxPartNewDatum(svxMatrix* Frame, int* idDatum);
*  extern int cvxPartPlnCrv(int idCrv, svxPoint* Origin, svxPoint* Xaxis, int* idPln);
*  extern int cvxPartPlnCrv2(int idCrv, svxData* Origin, svxData* Xaxis, int Flip, int* idPln);
*  extern int cvxPartPlnSrf(int idFace, svxPoint* Origin, int* idPln);
*  extern int cvxPartPlnSrf2(int idFace, svxPoint* Origin, svxPoint* XZ, int Flip, int* idPln);
*  extern int cvxPartPlaneNew(svxPlaneData* Plane, int* idPlane);
*  extern int cvxPartPlaneAddInit(evxNewPlaneMethods method, svxNewPlaneData* data);
*  extern int cvxPartPlaneAdd(const svxNewPlaneData* plane, int* idPlane);
**********************************************************************/

/**********************************************************************
*! -Datum CSYS- : zwapi_cmd_datum.h
*  extern int cvxPartCSYSNewInit(evxCSYSMethods method, svxCSYSData* data);
*  extern int cvxPartCSYSNew(svxCSYSData* CSYS, int* idCSYS);
**********************************************************************/

/**********************************************************************
*! -LCS- : zwapi_cmd_datum.h
*  extern int cvxPartActiveAsLCS(int id);
**********************************************************************/

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SHAPE_FTR_H */
