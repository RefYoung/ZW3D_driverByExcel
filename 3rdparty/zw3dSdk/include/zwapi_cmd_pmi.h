/**
@file zwapi_cmd_pmi.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D PMI Commands API
*/
/**
@defgroup zwapi_cmd_pmi PMI Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D PMI Commands API
*/

#pragma once
#ifndef ZW_API_PMI_H /* this ifndef surrounds entire header */
#define ZW_API_PMI_H

#include "zwapi_cmd_pmi_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Dimension */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI linear dimension between the specified two entities in part.
    Supported entities include two points, a point and a line,two parallel lines,
    two parallel faces.

    @param [in] idEnt1 id of the first entity
    @param [in] idEnt2 id of the second entity
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddLineDim(int idEnt1, int idEnt2, const svxPoint *TextPnt, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a symmetric annotation based on entity and a center line.
    Supported entities include two points, a point and a line,two parallel lines,
    two parallel faces.

    @param [in] iEntId id of the entity
    @param [in] iCenterLineId id of the entity Center Line
    @param [in] TextPnt point coordinate of text placement point
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
    @param [out] idDim id of the dimension created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartAddSymmetryDim(svxPntOnEnt iEntId, svxPntOnEnt iCenterLineId, svxPntOnEnt TextPnt, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI angle dimension between the specified two entities in part.
    Supported entities include two points, a point and a line,two parallel lines,
    two parallel faces.

    @param [in] idEnt1 id of the first entity
    @param [in] idEnt2 id of the second entity
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] idPlane id of insertion plane (datum or planar face),
                0 to use default view plane
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
    extern evxErrors cvxPartAddAngleDim(int idEnt1, int idEnt2, const svxPoint *TextPnt, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI radius dimension between the specified entity in part.
    Supported entities include circle or face.

    @param [in] idEnt id of the first entity
    @param [in] radType radial or diametric dim type, please refer to evxRadDimType
    @param [in] text input user text (NULL to ignore)
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddRadDim(int idEnt, int radType, const char *text, const svxPoint *TextPnt, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI chamfer dimension between the specified two entities in part.
    Supported entities include two points, a point and a line,two parallel lines,
    two parallel faces.

    @param [in] idEnt1 id of the first entity
    @param [in] idEnt2 id of the second entity
    @param [in] TextPos point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddChamferDim(int idEnt1, int idEnt2, const svxPoint *TextPos, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI arc dimension between the specified entity in part.
    Supported entities include circle or face.

    @param [in] idEnt id of the first entity
    @param [in] text input user text (NULL to ignore)
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddArcDim(int idEnt, const char *text, const svxPoint *TextPnt, int idPlane, int *idDim);


    //====================================================================================================================
    /** @name Annotation */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI coordinate dimension to specifies leader point.

    @param [in] LeaderPnt point coordinate of leader point,
                          if idParent is a point, LeaderPnt set to NULL
    @param [in] idParent id of the parent entity of the leader point,
                         if no parent entity, idParent is equal to 0
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] idDatum Specifies a datum plane to define a local coordinate frame.
                        0 to use default datum
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use current view plane
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
    extern evxErrors cvxPartAddCoorDim(svxPoint *LeaderPnt, int idParent, const svxPoint *TextPnt, int idDatum, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI label dimension for the specified entity which includes edge, curve, face or datum plane.
    If leadPnt doesn't on entity, it will be projected into the entity.
    If leadPnt is null, it will be set to a point on entity.
    Set idEnt to -1 when there is no entity.

    @param [in] idEnt id of the entity where the leader point is located (0 to ignore)
    @param [in] leadPnt leader point (NULL to use default point on entity or ignore)
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] text datum label name
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddLabelDim(int idEnt, svxPoint *leadPnt, const svxPoint *TextPnt, char *text, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI datum feature dimension for the specified entity in part.
    Supported entities include edge and face.

    @param [in] idEnt id of the first entity
    @param [in] leadPnt point coordinate of text placement point (NULL to use critical point)
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] text datum label name
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddDatumDim(int idEnt, svxPoint *leadPnt, const svxPoint *TextPnt, char *text, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI datum target dimension for the specified entity in part.
    Supported entities include edge and face.

    @param [in] idEnt id of the first entity
    @param [in] radRype type of DatumT dimension
    @param [in] diameter diameter
    @param [in] width width
    @param [in] height height
    @param [in] leadPnt point coordinate of text placement point (NULL to use critical point)
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] text datum label name
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddDatumTargetDim(int idEnt, int radRype, double diameter, double width, double height, svxPoint *leadPnt, const svxPoint *TextPnt, char *text, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI datum feature dimension for the specified entity in part.
    Supported entities include edge and face.

    @param [in] idEnt id of the first entity
    @param [in] leadPnt point coordinate of text placement point (NULL to use critical point)
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] text datum label name
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddFcsDim(int idEnt, svxPoint *leadPnt, const svxPoint *TextPnt, char *text, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI surface finish dimension for the specified entity in part.
    Supported entities include edge and face.

    @param [in] idEnt id of the first entity
    @param [in] leadPnt point coordinate of text placement point (NULL to use critical point)
    @param [in] TextPnt point coordinate of text placement point (NULL to ignore, automatic calculation)
    @param [in] textGrp Roughness PMI text define
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartAddSymSrfDim(int idEnt, svxPoint *leadPnt, const svxPoint *TextPnt, svxRoughTexts *textGrp, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI center line dimension of the specified entity in part.
    Supported entity is face.

    @param [in] idEnt id of the first entity
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddCenLinDim(int idEnt, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI center mark dimension of the specified entity in part.
    Supported entity is arc, circle, face.

    @param [in] idEnt id of the first entity
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddCenMarkDim(int idEnt, int idPlane, int *idDim);


    //====================================================================================================================
    /** @name Text */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI text annotation in part.

    @param [in] TextPnt point coordinate of text placement point
    @param [in] text datum label name
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddPMIText(svxPoint *TextPnt, char *text, int idPlane, int *idDim);

    /**
    @ingroup zwapi_cmd_pmi

    Create a PMI balloon annotation in part.

    @param [in] TextPnt point coordinate of text placement point
    @param [in] text balloon string
    @param [in] fImage image flag: 1-image, 0-text
    @param [in] idPlane id of insertion plane (datum or planar face),
                        0 to use default view plane
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
    extern evxErrors cvxPartAddBalloon(svxPoint *TextPnt, char *text, int fImage, int idPlane, int *idDim);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_PMI_H */
