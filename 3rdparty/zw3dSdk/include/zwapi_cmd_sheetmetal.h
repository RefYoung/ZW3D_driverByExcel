/**
@file zwapi_cmd_sheetmetal.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sheet Metal Commands API
*/
/**
@defgroup zwapi_cmd_sheetmetal Sheet Metal Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Sheet Metal Commands API
*/

#pragma once
#ifndef ZW_API_SHEET_METAL_FTR_H /* this ifndef surrounds entire header */
#define ZW_API_SHEET_METAL_FTR_H

#include "zwapi_cmd_sheetmetal_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Base */
    //====================================================================================================================
    /**********************************************************************
    *! -Sketch- : zwapi_cmd_sk_create.h
    *  extern evxErrors cvxPartSkNew(svxMatrix* Plane, int* idEnt);
    *  extern evxErrors cvxPartSkPlane(svxSketchData* SkData, int* idSketch);
    **********************************************************************/

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdExtrudeTab().

    Default values are used when some parameters are set to NULL.
    When users want to know what the default value is, they can use
    the interface cvxPartSmdAtGet() to get it.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Smd Extrude Tab data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdExtrudeTabInit(svxSmdExtrudeTabData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to create sheet metal flange feature, can create tab feature.
    Extrude a close profile to be a base tab.

    @note
    Interface cvxPartSmdExtrudeTabInit() can initialize variables of this function.

    @param [in] data Smd Extrude Tab data
    @param [out] idExtTab id of tab (NULL to ignore)

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
    extern evxErrors cvxPartSmdExtrudeTab(const svxSmdExtrudeTabData *data, int *idExtTab);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdExtrudeFlange().

    Default values are used when some parameters are set to NULL.
    When users want to know what the default value is, they can use
    the interface cvxPartSmdAtGet() to get it.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Smd Extrude Flange data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdExtrudeFlangeinit(svxExtrudeFlangeData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to create sheet metal flange feature, can create flange feature.
    Extrude a close or open profile to be a flange, it will offset the thick and add the bend.

    @note
    Interface cvxPartSmdExtrudeFlangeInit() can initialize variables of this function.

    @param [in] data smd extrude flange data
    @param [out] idExtFlange id of smd extrude flange (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartSmdExtrudeFlange(const svxExtrudeFlangeData *data, int *idExtFlange);


    //====================================================================================================================
    /** @name Flange */
    //====================================================================================================================

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the relief parameter of svxSmdFullFlangeData/svxSmdFlangeProfData/
    svxSmdPartialFlangeData/svxSmdHemFlangeData/svxSmdFlangeData.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Smd Relief data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdReliefDataInit(svxSmdReliefData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdFullFlange().

    Default values are used when some parameters are set to NULL.
    When users want to know what the default value is, they can use
    the interface cvxPartSmdAtGet() to get it.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Smd Full Flange data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdFullFlangeInit(svxSmdFullFlangeData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to add full face flanges to the multi-edges of a sheet metal part.

    @note
    Interface cvxPartSmdFullFlangeInit() can initialize variables of this function.

    @param [in] data Smd Full Flange data
    @param [out] idFull id of full flange ,NULL to ignore

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
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartSmdFullFlange(const svxSmdFullFlangeData *data, int *idFull);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the matrix of the idProfile of svxSmdFlangeProfData.

    @note
    Call this interface first to get the matrix of the input profile if you will create a
    profile for adding a flange. You need use the output matrix as the profile's matrix.

    @param [in] idEdge id of edge to add flange with profile
    @param [in] angle the bend angle
    @param [out] skMat the matrix of the profile

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    */
    extern evxErrors cvxPartSmdProfFlangeProfMatInit(int idEdge, double angle, svxMatrix *skMat);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdProfFlange().

    Default values are used when some parameters are set to NULL.
    When users want to know what the default value is, they can use
    the interface cvxPartSmdAtGet() to get it.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Smd Flange with Profile data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdProfFlangeInit(svxSmdFlangeProfData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to create a sheet metal profile flange.
    This function is similar to cvxPartSmdFullFlange(),
    but the shape of the bend and flanges is controlled by the profile.

    Interface cvxPartSmdProfFlangeInit() can initialize variables of this function.

    @note
    You must call cvxPartSmdProfFlangeProfMatInit() to get the profile's matrix if you will create a
    profile for adding a flange.

    @param [in] data Smd Flange with profile data
    @param [out] idFlange id of Flange with profile ,NULL to ignore

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
    extern evxErrors cvxPartSmdProfFlange(const svxSmdFlangeProfData *data, int *idFlange);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdPartialFlange().

    Default values are used when some parameters are set to NULL.
    When users want to know what the default value is, they can use
    the interface cvxPartSmdAtGet() to get it.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Smd Partial Flange data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdPartialFlangeInit(svxSmdPartialFlangeData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to add a partial flange to the edge of a sheet metal part.

    @note
    Interface cvxPartSmdPartialFlangeInit() can initialize variables of this function.

    @param [in] data Smd Partial Flange data
    @param [out] idPartial id of Partial Flange, NULL to ignore

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
    extern evxErrors cvxPartSmdPartialFlange(const svxSmdPartialFlangeData *data, int *idPartial);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdHemFlange().

    Default values are used when some parameters are set to NULL.
    When users want to know what the default value is, they can use
    the interface cvxPartSmdAtGet() to get it.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] hemType 0 is Full hem, 1 is Partial hem.
    @param [out] data template command Smd Hem Flange data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdHemFlangeInit(int hemType, svxSmdHemFlangeData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to add various curly shape on edges of the sheet metal model,
    the thickness are same as the sheet metal model.

    @note
    Interface cvxPartSmdHemFlangeInit() can initialize variables of this function.

    @param [in] data Smd Hem Flange data
    @param [out] idHem id of hem flange , NULL to ignore

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
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxPartSmdHemFlange(const svxSmdHemFlangeData *data, int *idHem);


    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdLftFlange().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] method smd lofted flange method
    @param [out] data smd jog data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdLftFlangeInit(evxSmdLftFlangeMethod method, svxSmdLoftedFlangeData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to create lofted flange.
    It supports Fold/Unfold Sheet Metal Parts.

    @note
    Interface cvxPartSmdLftFlangeInit() can initialize variables of this function.

    @param [in] data smd lofted flange data
    @param [out] idLft feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdLftFlange(const svxSmdLoftedFlangeData *data, int *idLft);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdSweptFlange().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] corType smd relief type
    @param [out] data smd Swept flange data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdSweptFlangeInit(evxSmdCornerRelief corType, svxSmdSweptFlangeData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Swept Flange is similar to Sweep, you need a profile and path to create the flange.
    To create a swept flange, you need an open profile sketch as the profile,
    and a series of existing sheet metal edges as the path.

    @note
    Interface cvxPartSmdSweptFlangeInit() can initialize variables of this function.

    @param [in] data smd swept flange data
    @param [out] idSwept feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdSweptFlange(const svxSmdSweptFlangeData *data, int *idSwept);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdFoldByLine().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data smd Fold by Line data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdFoldByLineInit(svxSmdFoldByLineData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to create bends along a line.
    This line can be a three-dimensional or two-dimensional line.

    @note
    Interface cvxPartSmdFoldByLineInit() can initialize variables of this function.

    @param [in] data smd Fold by Line data
    @param [out] idFbl feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdFoldByLine(const svxSmdFoldByLineData *data, int *idFbl);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdJog().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data smd jog data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdJogInit(svxSmdJogData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this command to create two bends and two flange along a line,
    and lifting material between the to bends which are described
    in the notes below.

    @note
    Interface cvxPartSmdJogInit() can initialize variables of this function.

    @param [in] data smd jog data
    @param [out] idJog feature id of jog(NULL to ignore)

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
    extern evxErrors cvxPartSmdJog(const svxSmdJogData *data, int *idJog);


    //====================================================================================================================
    /** @name Editing */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdExtendFlange().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type extend flange type
    @param [out] data smd extend flange data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdExtendFlangeInit(evxSmdExtendFlangeMethod type, svxSmdExtendFlangeData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use function to stretch an existing tab or flange from its picked edges.
    It would be helpful if users don't want to redefine the flange
    or an Extrusion tab feature to change the size for replay efficiency,
    or you want to work on an imported/converted sheet metal part
    that doesn't have any redefine-able features.

    @note
    Interface cvxPartSmdExtendFlangeInit() can initialize variables of this function.

    @param [in] data smd extend flange data
    @param [out] idFtr feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdExtendFlange(const svxSmdExtendFlangeData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdFlange().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    Some parameters are gotten form interface cvxPartSmdAtGet();

    @param [out] data template command Smd Flange data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdFlangeInit(svxSmdFlangeData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to add face flanges to the multi-edges of a sheet metal part.

    @note
    Interface cvxPartSmdFlangeInit() can initialize variables of this function.

    @param [in] data Smd Flange data
    @param [out] idFlange id of flange ,NULL to ignore

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
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartSmdFlange(const svxSmdFlangeData *data, int *idFlange);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdBendTaper().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] taperType 0 is linear,Use an angle value or a distance value to taper the bend.
                1 is tangent,Use a distance value to taper the bend. The edge of the bend is tangent to the web.
                default:0
    @param [out] data smd bend taper definition side data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdBendTaperDefDataInit(int taperType, svxSmdBendTaperDefData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdBendTaper().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.  
    Structure svxSmdBendTaperDefData can be initialized through interface cvxPartSmdBendTaperDefDataInit().

    @param [in] method Specify the side you want to taper
    @param [out] data smd bend taper data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdBendTaperInit(evxSmdTaperSideMethod method, svxSmdBendTaperData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this command to miter the flange to change its profile
    and avoid the interference with other flanges, or make some gap,
    especially on the imported sheet metal which has no flange features.
    The system will specify the stationary face automatically,
    but you do have modify permission for designing the shape.

    @note
    Interface cvxPartSmdBendTaperInit() can initialize variables of this function.

    @param [in] data smd bend taper data
    @param [out] idFtr feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdBendTaper(const svxSmdBendTaperData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdNormalCut().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Smd Normal Cut data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdNormalCutinit(svxNormalCutData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to create Normal Cut at shapes by Profile P.
    Pass in NULL for "idShapes" and "numShape" if the output is not require, or it will return the new shapes.

    @note
    Interface cvxPartSmdNormalCutInit() can initialize variables of this function.

    @param [in] pData NormalCut data
    @param [out] numShape number of resulting shapes (NULL to ignore)
    @param [out] idShapes list of id's of resulting shapes (NULL to ignore)

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
    extern evxErrors cvxPartSmdNormalCut(const svxNormalCutData *pData, int *numShape, int **idShapes);


    //====================================================================================================================
    /** @name Corner */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdCloseCorner().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type method, 0-close by edge, 1- close by bend(face)
    @param [out] data template command Smd Close Corner data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdCloseCornerInit(int type, svxCloseCornerData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Adds the specified close corner feature to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idSmdCorner" if the output is not required.

    @note
    Interface cvxPartSmdCloseCornerInit() can initialize variables of this function.

    @param [in] CornerData close corner data
    @param [out] idSmdCorner index of close corner (NULL to ignore)

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
    extern evxErrors cvxPartSmdCloseCorner(const svxCloseCornerData *CornerData, int *idSmdCorner);


    //====================================================================================================================
    /** @name Form */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdDimple().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data dimple data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdDimpleInit(svxDimpleData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to create a raised dimple feature in a sheet metal part.
    The dimple(s) can be placed on any flat face including flanges and will
    be extended in the direction of the face.

    @note
    Interface cvxPartSmdDimpleInit() can initialize variables of this function.

    @param [in] Dimple dimple input data
    @param [out] idDimple id of dimple feature (NULL to ignore)

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
    extern evxErrors cvxPartSmdDimple(svxDimpleData *Dimple, int *idDimple);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdLouver().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Smd Louver data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdLouverInit(svxLouverData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Adds the specified louver feature to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idSmdLouver" if the output is not required.

    @note
    Interface cvxPartSmdLouverInit() can initialize variables of this function.

    @param [in] LouverData louver data
    @param [out] idSmdLouver index of louver (NULL to ignore)

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
    extern evxErrors cvxPartSmdLouver(const svxLouverData *LouverData, int *idSmdLouver);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdPunch().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data template command Smd Punch data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdPunchInit(svxPunchData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to act on the sheet metal, which can be completed punching forming.
    Pass in NULL for "idShape" if the output is not require, or it will return the new shape.

    @note
    Interface cvxPartSmdPunchInit() can initialize variables of this function.

    @param [in] pData Punch data
    @param [out] idShape id's of resulting shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartSmdPunch(const svxPunchData *pData, int *idShape);


    //====================================================================================================================
    /** @name Bend */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sheetmetal

    Adds the specified fold(s) to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idSmdFold" if the output is not required.

    @param [in] Fold Smdfold data
    @param [out] idSmdFold Smdfold id

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
    extern evxErrors cvxPartSmdFold(const svxFoldData *Fold, int *idSmdFold);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Adds the specified unfold(s) to the active part and outputs the
    id of the corresponding history operation.

    Pass in NULL for "idSmdUnfold" if the output is not required.

    @param [in] Unfold SmdUnfold data
    @param [out] idSmdUnfold SmdUnfold id

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
    extern evxErrors cvxPartSmdUnfold(const svxUnfoldData *Unfold, int *idSmdUnfold);


    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdFlatten().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data smd flatten data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdFlattenInit(svxSmdFlattenData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this command to generate flat entity and flat pattern.
    User can create multiple flatten commands in one file,
    which generate two sub-nodes of flat entity and flat pattern.
    Flat pattern applies to drawing sheet.

    If there had crated flat patten in sheet metal module,
    when making drawing sheet, user can project flat pattern by "Standard".

    @note
    Interface cvxPartSmdExtendFlangeInit() can initialize variables of this function.

    @param [in] data smd flatten data
    @param [out] idFtr feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdFlatten(const svxSmdFlattenData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdLnUnfold().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data smd linear unfold data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdLnUnfoldInit(svxSmdLinearUnfoldData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this command to unfold or change the bend angle.
    The bend is limited to cylindrical face or modified cylindrical face.

    @note
    Interface cvxPartSmdLnUnfoldInit() can initialize variables of this function.

    @param [in] data smd linear unfold data
    @param [out] idFtr feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdLnUnfold(const svxSmdLinearUnfoldData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdChangeBend().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type change bend type
    @param [out] data smd change bend data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdChangeBendInit(evxSmdChangeBendType type, svxSmdChangeBendData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Use this function to modify the bending radius of the bend.

    @note
    Interface cvxPartSmdChangeBendInit() can initialize variables of this function.

    @param [in] data smd change bend data
    @param [out] idFtr feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdChangeBend(const svxSmdChangeBendData *data, int *idFtr);


    //====================================================================================================================
    /** @name Convert */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdRip().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data smd rip data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdRipInit(svxSmdRipData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Create a rip in a sheet metal part.

    @note
    Interface cvxPartSmdRipInit() can initialize variables of this function.

    @param [in] data smd rip data
    @param [out] idFtr feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdRip(const svxSmdRipData *data, int *idFtr);

    /**
    @ingroup zwapi_cmd_sheetmetal

    Initialize the parameters of the cvxPartSmdMarkBend().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data smd mark bend data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartSmdMarkBendInit(svxSmdMarkBendData *data);

    /**
    @ingroup zwapi_cmd_sheetmetal

    A key characteristic of sheet metal parts are its bend faces.
    The Sheet Metal Tooltab contains commands to fold and unfold a sheet metal part.
    In order to perform these commands any bend radii (other than those created during
    the Create Full and Partial Sheet Metal Flange commands) need to be marked.

    @note
    Interface cvxPartSmdMarkBendInit() can initialize variables of this function.

    @param [in] data smd mark bend data
    @param [out] idFtr feature id(NULL to ignore)

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
    extern evxErrors cvxPartSmdMarkBend(const svxSmdMarkBendData *data, int *idFtr);

//====================================================================================================================
/** @name Basic Editing */
//====================================================================================================================
/**********************************************************************
*! -Pattern Geometry- : zwapi_cmd_shape.h
*  extern int cvxPartPatternGeom(int Count, int* idEnts, const svxPtnGeom* Pattern, int* idPattern);
**********************************************************************/

/**********************************************************************
*! -Pattern Feature- : zwapi_cmd_shape.h
*  extern int cvxPartPatternFtr(int Count, int* idFtrs, const svxPtnFtr* Pattern, int* idPattern);
**********************************************************************/

/**********************************************************************
*! -Mirror Geometry- : zwapi_cmd_shape.h
*  extern int cvxPartMirrorGeom(svxMirrorGeom* Mirror, int* NumNewEnts, int** idNewEnts);
**********************************************************************/

/**********************************************************************
*! -Mirror Feature- : zwapi_cmd_shape.h
*  extern int cvxPartMirrorFtr(svxMirrorFtr* Mirror, int* idFtr);
**********************************************************************/

/**********************************************************************
*! -Fillet-  : zwapi_cmd_shape.h
*  extern evxErrors cvxPartFillet(int Count, int* Edges, double Radius);
*  extern evxErrors cvxPartFilletAllInit(svxChamFlltData* data);
*  extern evxErrors cvxPartFilletAll(const svxChamFlltData* Fillet, int* idFillet);
**********************************************************************/

/**********************************************************************
*! -Chamfer-  : zwapi_cmd_shape.h
*  extern evxErrors cvxPartChamConst(int Count, int* Edges, double Sb);
*  extern evxErrors cvxPartChamAng(int Cnt, int* Edges, int idFace, double Sb, double Angle);
*  extern evxErrors cvxPartChamAsym(int Cnt, int* Edges, int idFace, double Sb1, double Sb2);
*  extern evxErrors cvxChamFlltSetDataInit(svxChamFlltSetData* data);
*  extern evxErrors cvxPartChamferAllInit(svxChamFlltData* data);
*  extern evxErrors cvxPartChamferAll(const svxChamFlltData* Chamfer, int* idChamfer);
**********************************************************************/

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SHEET_METAL_FTR_H */
