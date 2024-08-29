/**
@file zwapi_cmd_ecadboard.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D ECAD Board API
*/
/**
@defgroup zwapi_cmd_ecadboard ECAD Board Commands
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D ECAD Board API
*/

#pragma once
#ifndef ZW_API_ECAD_BOARD_H /* this ifndef surrounds entire header */
#define ZW_API_ECAD_BOARD_H

#include "zwapi_cmd_ecadboard_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Basic Shape */
    //====================================================================================================================
    /**********************************************************************
    *! -Sketch- : zwapi_cmd_sk_create.h
    *  extern evxErrors cvxPartSkNew(svxMatrix* Plane, int* idEnt);
    *  extern evxErrors cvxPartSkPlane(svxSketchData* SkData, int* idSketch);
    **********************************************************************/

    /**********************************************************************
    *! -Cosmetic sketch- : zwapi_cmd_sk_create.h
    *  extern evxErrors cvxHatchPtnDataInit(svxHatchPtnData* data);
    *  extern evxErrors cvxPartCosSkPlane(const svxSketchData* SkData, int isAddHatPtn, const svxHatchPtnData* PatData, int* idSketch);
    **********************************************************************/

    /**********************************************************************
    *! -Extrude Tab- : zwapi_cmd_sheetmetal.h
    *  extern evxErrors cvxPartSmdExtrudeTabInit(svxSmdExtrudeTabData* data);
    *  extern evxErrors cvxPartSmdExtrudeTab(const svxSmdExtrudeTabData* data, int* idExtTab);
    **********************************************************************/

    /**********************************************************************
    *! -Full Flange- : zwapi_cmd_sheetmetal.h
    *  extern evxErrors cvxPartSmdFullFlangeInit(svxSmdFullFlangeData* data);
    *  extern evxErrors cvxPartSmdFullFlange(const svxSmdFullFlangeData* data, int* idFull);
    **********************************************************************/

    /**********************************************************************
    *! -Partial Flange- : zwapi_cmd_sheetmetal.h
    *  extern evxErrors cvxPartSmdPartialFlangeInit(svxSmdPartialFlangeData* data);
    *  extern evxErrors cvxPartSmdPartialFlange(const svxSmdPartialFlangeData* data, int* idPartial);
    **********************************************************************/

    /**********************************************************************
    *! -Lofted Flange- : zwapi_cmd_sheetmetal.h
    *  extern evxErrors cvxPartSmdLftFlangeInit(evxSmdLftFlangeMethod method, svxSmdLoftedFlangeData* data);
    *  extern evxErrors cvxPartSmdLftFlange(const svxSmdLoftedFlangeData* data, int* idLft);
    **********************************************************************/

    //====================================================================================================================
    /** @name Basic Face */
    //====================================================================================================================
    /**********************************************************************
    *! -N-sided- : zwapi_cmd_freeform.h
    *  extern evxErrors cvxPartNSidedInit(svxNSidedData* data);
    *  extern evxErrors cvxPartNSided(const svxNSidedData* NSidedData, int* idShape);
    **********************************************************************/

    //====================================================================================================================
    /** @name Engineer Feature */
    //====================================================================================================================
    /**
    @ingroup zwapi_cmd_ecadboard

    Initialize the parameters of the cvxPartEcadRgnSet().

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data Region set data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartEcadRgnSetInit(svxEcadRgnSetData *data);

    /**
    @ingroup zwapi_cmd_ecadboard

    ECAD "Region Set" command.
    The sketch must be cosmetic.

    @note
    Interface cvxPartEcadRgnSetInit() can initialize variables of this function.

    @param [in] pRgnSetData region set data
    @param [out] idFtr id of feature(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartEcadRgnSet(const svxEcadRgnSetData *pRgnSetData, int *idFtr);

    /**
    @ingroup zwapi_cmd_ecadboard

    Use the input sketch to cut the sheet metal shape.
    It likes Extrude_Remove command and the extrude length is the thickness of
    the tab shape in current part.

    @param [in] idSketch id sketch to cut the tab shape
    @param [out] idFtr id of feature(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxPartEcadRgnCut(int idSketch, int *idFtr);

/**********************************************************************
*! -Fillet- : zwapi_cmd_shape.h
*  extern evxErrors cvxPartFilletAllInit(svxChamFlltData* data);
*  extern evxErrors cvxPartFilletAll(const svxChamFlltData* Fillet, int* idFillet);
**********************************************************************/

/**********************************************************************
*! -Chamfer- : zwapi_cmd_shape.h
*  extern evxErrors cvxChamFlltSetDataInit(svxChamFlltSetData* data);
*  extern evxErrors cvxPartChamferAllInit(svxChamFlltData* data);
*  extern evxErrors cvxPartChamferAll(const svxChamFlltData* Chamfer, int* idChamfer);
**********************************************************************/

/**********************************************************************
*! -Hole- : zwapi_cmd_shape.h
*  extern evxErrors cvxPartHoleInit(evxHoleOpt HoleOpt, int type, svxHoleData* data);
*  extern evxErrors cvxPartHole(svxHoleData* Data, int* idOp);
**********************************************************************/

/**********************************************************************
*! -Add Shape/Remove shape/Intersect shape- : zwapi_cmd_shape.h
*  extern evxErrors cvxPartBool(evxBoolType, int idBase, int Count, int* Shapes, int Keep);
*  extern evxErrors cvxPartBool2(evxBoolType Type, int BaseCount, int* BaseList, int OpCount, int* OpList, int* ResultCount, int** ResultList);
*  extern evxErrors cvxPartBool3(evxBoolType Type, int BaseCount, int* BaseList, int OpCount, int* OpList, int FaceCount, int* FaceList, int* ResultCount, int** ResultList);
**********************************************************************/

    //====================================================================================================================
    /** @name Bend */
    //====================================================================================================================
/**********************************************************************
*! -Fold- : zwapi_cmd_sheetmetal.h
*  extern evxErrors cvxPartSmdFoldByLineInit(svxSmdFoldByLineData* data);
*  extern evxErrors cvxPartSmdFoldByLine(const svxSmdFoldByLineData* data, int* idFbl);
**********************************************************************/

/**********************************************************************
*! -Unfold- : zwapi_cmd_sheetmetal.h
*  extern evxErrors cvxPartSmdUnfold(const svxUnfoldData* Unfold, int* idSmdUnfold);
**********************************************************************/

/**********************************************************************
*! -Flatten- : zwapi_cmd_sheetmetal.h
*  extern evxErrors cvxPartSmdFlattenInit(svxSmdFlattenData* data);
*  extern evxErrors cvxPartSmdFlatten(const svxSmdFlattenData* data, int* idFtr);
**********************************************************************/

/**********************************************************************
*! -Linear Unfold- : zwapi_cmd_sheetmetal.h
*  extern evxErrors cvxPartSmdLnUnfoldInit(svxSmdLinearUnfoldData* data);
*  extern evxErrors cvxPartSmdLnUnfold(const svxSmdLinearUnfoldData* data, int* idFtr);
**********************************************************************/

/**********************************************************************
*! -Linear Unfold- : zwapi_cmd_sheetmetal.h
*  extern evxErrors cvxPartSmdChangeBendInit(evxSmdChangeBendType type, svxSmdChangeBendData* data);
*  extern evxErrors cvxPartSmdChangeBend(const svxSmdChangeBendData* data, int* idFtr);
**********************************************************************/

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
*! -Move-  : zwapi_cmd_shape.h
*  extern int cvxPartMove(const svxMoveData *Move, int *idMove);
**********************************************************************/

/**********************************************************************
*! -Copy-  : zwapi_cmd_shape.h
*  extern int cvxPartCopy(const svxCopyData *Copy, int *idCopy);
**********************************************************************/

/**********************************************************************
*! -Scale-  : zwapi_cmd_shape.h
*  extern int cvxPartScale(int Count, int* idEnts, double X, double Y, double Z, int idDatum);
*  extern int cvxPartScale2(int Count, int* idEnts, double X, double Y, double Z, int idDatum, svxPoint* CentPnt);
**********************************************************************/

    //====================================================================================================================
    /** @name Datum */
    //====================================================================================================================
/**********************************************************************
*! -Datum Axis- : zwapi_datum.h
*  extern int cvxPartAxisNew(svxAxisData *Axis, int *idAxis);
**********************************************************************/

/**********************************************************************
*! -Datum Plane- : zwapi_datum.h
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
*! -Datum CSYS- : zwapi_datum.h
*  extern int cvxPartCSYSNewInit(evxCSYSMethods method, svxCSYSData* data);
*  extern int cvxPartCSYSNew(svxCSYSData* CSYS, int* idCSYS);
**********************************************************************/

/**********************************************************************
*! -LCS- : zwapi_datum.h
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

#endif /* ZW_API_ECAD_BOARD_H */
