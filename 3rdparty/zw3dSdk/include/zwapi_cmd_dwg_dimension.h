/**
@file zwapi_cmd_dwg_dimension.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Dimension Command of Drawing API
*/
/**
@defgroup zwapi_cmd_dwg_dimension Drawing Dimension Commands
@ingroup DrawingCommands
@brief
@details THE MODULE FOR THE ZW3D Dimension Command of Drawing API
*/

#pragma once
#ifndef ZW_API_DIMENSION_H /* this ifndef surrounds entire header */
#define ZW_API_DIMENSION_H

#include "zwapi_cmd_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Dimension */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_dwg_dimension

    Add auto dimension by special parameter.

    @note
    Interface cvxDwgAutoDimAddInit() can initialize variables of this function.

    @param [in] pDimData dimension parameters
    @param [out] idDim id of Dim (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgAutoDimAdd(const svxDimAuto *pDimData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgAutoDimAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data auto dimension data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgAutoDimAddInit(svxDimAuto *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a Linear dimension between the specified obj in drawing.

    pData->cons.type is set by evxDimLineType, as follows:   
    VX_DIM_LINE_LH -- horizontal     
    VX_DIM_LINE_LV -- vertical       
    VX_DIM_LINE_LA -- aligned        
    VX_DIM_LINE_LR -- rotated        
    VX_DIM_LINE_LP -- projected      

    @param [in] pData data of line dimension
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgLineDimAdd(const svxDwgLineDim *pData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a Baseline dimension between the specified object in drawing.

    pData->sub.cons.type is set by evxDimLineType, as follows:    
    VX_DIM_LINE_LH -- horizontal     
    VX_DIM_LINE_LV -- vertical       
    VX_DIM_LINE_LA -- aligned        
    VX_DIM_LINE_LR -- rotated        
    VX_DIM_LINE_LP -- projected      

    @param [in] pData data of BaseLine dimension
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgBaseLineDimAdd(const svxDwgLineGrpDim *pData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a Continuous dimension between the specified object in drawing.

    pData->sub.cons.type is set by evxDimLineType, as follows:     
    VX_DIM_LINE_LH -- horizontal     
    VX_DIM_LINE_LV -- vertical       
    VX_DIM_LINE_LA -- aligned        
    VX_DIM_LINE_LR -- rotated        
    VX_DIM_LINE_LP -- projected      

    @param [in] pData data of Continuous dimension
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgContinuousDimAdd(const svxDwgLineGrpDim *pData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a Ordinate dimension between the specified object in drawing.

    pData->sub.cons.type is set by evxDimLineType, as follows:      
    VX_DIM_LINE_LH -- horizontal      
    VX_DIM_LINE_LV -- vertical      
    VX_DIM_LINE_LA -- aligned      
    VX_DIM_LINE_LR -- rotated      
    VX_DIM_LINE_LP -- projected      
    VX_DIM_LINE_LO -- ordinate     

    @param [in] pData data of Ordinate dimension
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgOrdinateDimAdd(const svxDwgOrdinateDim *pData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a Linear offset dimension between the specified two entities in drawing.
    Supported entities include two lines, a point and a line

    type of pData  is as follows by evxDimLineOffset:      
    VX_DIM_OFFSET_LOL offset dimension - line to line      
    VX_DIM_OFFSET_LOP offset dimension - line to point

    @param [in] pData data of LineOffset dimension
    @param [out] idDim id of the dimension created (input NULL to ignore)

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
    extern evxErrors cvxDwgLineOffsetDimAdd(const svxDwgLineOffsetDim *pData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a symmetry dimension in a drawing sheet.

    @param [in] symmetryDimData symmetry dimension input data
    @param [out] idDim id of the symmetry dimension (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_AIP_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgSymmetryDimAdd(const svxDwgSymmetryDimData *symmetryDimData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgLnrChmDimAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data the info of the linear chamfer dim

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgLnrChmDimAddInit(svxDwgLnrChmDimData *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a linear chamfer dimension in sheeting. dimInfo must initialize before use.

    @note
    Interface cvxDwgLnrChmDimAddInit() can initialize variables of this function.

    @param [in] DimData the information of linear chamfer dim which will create
    @param [out] idDim id of the linear chamfer dim (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INPUT_TYPE_eRROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgLnrChmDimAdd(const svxDwgLnrChmDimData *DimData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create an angular dimension in a drawing sheet.

    @param [in] angDimData angular dimension input data
    @param [out] idDim id of the angular dimension (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgAngDimAdd(const svxDwgAngDimData *angDimData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a radial or diametric dimension for the specified entity in drawing.

    @param [in] radDimData radial or diametric input data
    @param [out] idDim id of the dimension created (input NULL to ignore)

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
    extern evxErrors cvxDwgRadDimAdd(const svxRadDimData *radDimData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create an arc length dimension in a drawing sheet.

    @param [in] arcDimData arc dimension input data
    @param [out] idDim id of the arc dimension (input NULL to ignore)

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
    extern evxErrors cvxDwgArcDimAdd(const svxDwgArcDimData *arcDimData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgHoleCallOutDimAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Hole Callout data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgHoleCallOutDimAddinit(svxDwgHoleCallOutDim *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a Hole Callout dimension between the specified holes in drawing.
    pData->iCalloutemt is set by evxCalloutEmt combined
    Memory for the idDims is allocated by this function. The calling procedure is responsible to free the memory

    @note
    Interface cvxDwgHoleCallOutDimAddInit() can initialize variables of this function.

    @param [in] pData data of hole callout dimension
    @param [out] numDim number of resulting dimension (NULL to ignore)
    @param [out]  idDims id of list of id's of resulting dimension (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACt_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgHoleCallOutDimAdd(const svxDwgHoleCallOutDim *pData, int *numDim, int **idDims);


    //====================================================================================================================
    /** @name Annotation */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a label coordinate dimension for the specified entity in drawing.

    @param [in] coorDimData label coordinate dimension input data
    @param [out] idDim id of the dimension created (input NULL to ignore)

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
    extern evxErrors cvxDwgLabelCoorDimAdd(const svxLabelCoorDimData *coorDimData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a label dimension.

    @param [in] pLabel information needed by creating dimension label
    @param [out] idDim id of Dim (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgLabelDimAdd(const svxDimLabel *pLabel, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a Balloon dimension between the specified points in drawing.

    @note
       This function has updated in ZW3D 2024 SP(28.05), and svxDwgBalloonDim is different from previous version,
    you may meet some compatibility issues.
       If you have used pData->condition before, you need to change to pData->condition and pData->subCondition now.

       When pData->condition = VX_BALLOON_CON_USER_TEXT and you want to set pData->text
    like you set text by using "Custom Editor" in zw3d, the input format of text is like:
       1.When you want to insert text of the corresponding type in "Insert column" e.g File-Name,
    the text you want to insert be like:<TC_Name>. The format is <TC_YouVariable>.
       2.When you want to insert text from "Insert variable" e.g "Sheet_scale"
    the text you want to insert be like [$Sheet_scale]. The format is [$YouVariable].

    @param [in] pData data of balloon dimension
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgBalloonDimAdd(const svxDwgBalloonDim *pData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgAutoBlnAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Information of creating auto balloon

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgAutoBlnAddInit(svxDwgAtBlnData *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create auto balloon. all values of atBllnInfo need initialization.

    @note
    Interface cvxDwgAutoBlnAddInit() can initialize variables of this function.

    @param [in] atBlnData the information of Creating auto balloon
    @param [out] idDimCount number of created balloon dim id (input NULL to ignore)
    @param [out]  idDimList list of created balloon dim id (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgAutoBlnAdd(const svxDwgAtBlnData *atBlnData, int *idDimCount, int **idDimList);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgStkBlnAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data information of creating stack balloons

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgStkBlnAddInit(svxDwgStkBlnData *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create stack balloons in sheeting.

    @note
    Interface cvxDwgStkBlnAddInit() can initialize variables of this function.

    @param [in] stkBlnData  information of creating stack balloons
    @param [out] idDimCount number of stacked balloon dim id (input NULL to ignore)
    @param [out]  idDimList list of stacked balloon dim id (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_aPI_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgStkBlnAdd(const svxDwgStkBlnData *stkBlnData, int *idDimCount, int **idDimList);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a feature control dimension for the specified entity in drawing.

    @param [in] pData data of feature control dimension
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgFtrCtrlDimAdd(const svxDwgFtrCtrl *pData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a datum dimension for the specified entity in drawing.

    @param [in] datumData datum input data
    @param [out] idDim id of the dimension created (input NULL to ignore)

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
    extern evxErrors cvxDwgDatumDimAdd(const svxDatumDimData *datumData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgDatumTargDimAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data datum target dim data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgDatumTargDimAddInit(svxDatumTargDimData *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a datum target dimension for the specified entity in drawing.

    @note
    Interface cvxDwgDatumTargDimAddInit() can initialize variables of this function.

    @param [in] datumTData datum target input data
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgDatumTargDimAdd(const svxDatumTargDimData *datumTData, int *idDim);

    //====================================================================================================================
    /** @name Symbol */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgCenterMarkDimAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Center Mark data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgCenterMarkDimAddInit(svxCenterMark *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Center dimension with specify coordinate.

    @verbatim
    default value: 
       svxCenterDim 
          cmSize   : 4.254534 
          breakLen : 1.5 
          overRun  : 3.06324 
          scaleFac : 1
    @endverbatim

    @note
    Interface cvxDwgCenterMarkDimAddInit() can initialize variables of this function.

    @param [in] pzCenterMark id of the first entity
    @param [out] idDim id of dim (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgCenterMarkDimAdd(const svxCenterMark *pzCenterMark, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgCenMarkCirDimAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data center mark circle dim data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgCenMarkCirDimAddInit(svxCenMarkCirDimData *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a center mark circle dimension for the specified entities in drawing.

    @note
    Interface cvxDwgCenMarkCirDimAddInit() can initialize variables of this function.

    @param [in] cmcDimData center mark circle dimension input data
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_aPI_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgCenMarkCirDimAdd(const svxCenMarkCirDimData *cmcDimData, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgCenterLineDimAdd().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Center Line data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgCenterLineDimAddInit(svxCenterLine *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Create a center line dimension by two lines or two points.

    By two lines: should be the same type, one is a straight line, the other must be a straight line;
        one is a arc or a circle, the other must be a arc or circle;

    By two points: any point; 
    default value: 
       svxCenterDim 
          cmSize   : 4.254534 
          breakLen : 1.5 
          overRun  : 3.06324 
          scaleFac : 1

    @note
    Interface cvxDwgCenterLineDimAddInit() can initialize variables of this function.

    @param [in] pzCenterLine info of two lines or two points
    @param [out] idDim id of dim (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    */
    extern evxErrors cvxDwgCenterLineDimAdd(const svxCenterLine *pzCenterLine, int *idDim);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Creates a standard weld symbol with specified data.

    @note
    Interface cvxDwgSymWeldNewInit() can initialize variables of this function.

    @param [in] idEnt id of the parent entity of the reference point (0 to ignore)
    @param [in] refPoint coordinate of the reference point
    @param [in] data weld symbol data
    @param [out] idSymWeld index of new symbol (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgSymWeldNew(int idEnt, svxPoint2 *refPoint, const svxSymWeld *data, int *idSymWeld);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgSymWeldNew().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data weld symbol data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymWeldNewInit(svxSymWeld *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgSymSurfNew().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data surface finish symbol data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgSymSurfNewInit(svxSymSurf *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Creates a surface finish symbol with specified data.

    @note
    Interface cvxDwgSymSurfNewInit() can initialize variables of this function.

    @param [in] idEnt id of the parent entity of the reference point (0 to ignore)
    @param [in] refPoint coordinate of the reference point
    @param [in] data surface finish symbol data
    @param [out] idSymSurf index of new symbol (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgSymSurfNew(int idEnt, svxPoint2 *refPoint, const svxSymSurf *data, int *idSymSurf);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Creates a new image with the symbol image data.

    If the "locked" of data is true, the width and the height's aspect ratio
    should be the same as the image. The width and the height can also be
    zero and it will be calculated based on the input points.

    if idSymImg != NULL, output the id of new image.

    @note
    Interface cvxDwgSymImgNewInit() can initialize variables of this function.

    @param [in] data symbol image data
    @param [in] embed 1-embed image file,0 not
    @param [in] locked 1-lock aspect ratio,0 not
    @param [out] idSymImg image id (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_PATH
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    */
    extern evxErrors cvxDwgSymImgNew(svxSymImg *data, int embed, int locked, int *idSymImg);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the parameters of the cvxDwgSymImgNew().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data image symbol data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgSymImgNewInit(svxSymImg *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Insert the symbol of specified file to current file.
    Output the new symbol id if "symId" is not NULL.

    The "symName" can be inquired by cvxRootInqSymbol().

    @param [in] fileName file name of specified symbol
    @param [in] symName name of symbol
    @param [in] pnt insert position
    @param [out] symId symbol id (pass in NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgInsertSymbol(const vxLongPath fileName, const vxLongName symName, svxPoint2 *pnt, int *symId);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Use this function to save a group of entities to the active
    symbol library for later use. if BasePnt is NULL, the function
    will use the first critical point of the first entity to make
    up the user symbol as the reference point, see the function
    description of cvxEntPnt() for detail of the critical point.

    All user symbol blocks can be inquired by cvxRootInqSymbol().

    @param [in] count number of entities that make up the user symbol
    @param [in] idEnt list of index of entities that make up the user symbol
    @param [in] BasePnt reference point (NULL to use the first critical point of the first entity)
    @param [in] Name name of new user symbol to create
    @param [out] idBlock index of new user symbol (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEEC_ERROR
    */
    extern evxErrors cvxDwgUserSymNew(int count, int *idEnt, svxPoint2 *BasePnt, const vxRootName Name, int *idBlock);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Use this function to create drawing sheet intersection symbol.

    @param [in] data   intersection symbol input data
    @param [out] idSym id of drawing sheet intersection symbol feature (NULL to ignore) 

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
    extern evxErrors cvxDwgIsectSym(const svxDwgIsectSym *data, int *idSym);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Initialize the svxDwgHoleMark structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type  drawing sheet hole mark type
    @param [out] data drawing sheet hole mark data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgHoleMarkInit(evxDwgHoleMarkType type, svxDwgHoleMark *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Use this function to mark holes in drawing sheet.

    @note
    Interface cvxDwgHoleMarkInit() can initialize variables hole mark
    of this function.

    @param [in] data  data of hole mark

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
    extern evxErrors cvxDwgHoleMark(const svxDwgHoleMark *data);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Modify the text of specified balloon.

    @param [in] idBalloon index of balloon
    @param [in] condition text condition
    @param [in] subCondition text sub condition
    @param [in] text text to set on balloon, taking effect  
                only when condition = VX_DWG_CON_USER_TEXT or subCondition = VX_DWG_SUB_CON_ID,  
                otherwise can set to NULL 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgBalloonTextSet(int idBalloon, evxDwgBalloonTextCondition condition, evxDwgBalloonTextSubCondition subCondition, const char *text);

    /**
    @ingroup zwapi_cmd_dwg_dimension

    Get the displayed text of specified balloon.

    @param [in] idBalloon index of balloon
    @param [out] text displayed text on balloon
    @param [in] nbytes size of output buff

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgBalloonTextGet(int idBalloon, char *text, int nbytes);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DIMENSION_H */
