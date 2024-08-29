/**
@file zwapi_cmd_direct_edit.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Direct Edit Commands API
*/
/**
@defgroup zwapi_cmd_direct_edit Direct Edit
@ingroup PartandAssemblyCommands
@brief
@details THE MODULE FOR THE ZW3D Direct Edit Commands API
*/

#pragma once
#ifndef ZW_API_DIRECT_EDIT_H /* this ifndef surrounds entire header */
#define ZW_API_DIRECT_EDIT_H

#include "zwapi_cmd_direct_edit_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Modify */
    //====================================================================================================================

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEMove structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type   part or assembly DE(Direct Edit) move type
    @param [out] data  part or assembly DE(Direct Edit) move data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDEMoveInit(evxDEMoveCopyType type, svxDEMove *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Use this function to DE(Direct Edit) move faces. Six different methods of 
    move are available, each method requires different types of input.

    @note
    Interface cvxPartDEMoveInit() can initialize variables DE(Direct Edit) move
    of this function.

    @param [in] data  part or assembly DE(Direct Edit) move input data
    @param [out] idMove  id of DE(Direct Edit) move feature (NULL to ignore)

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
    extern evxErrors cvxPartDEMove(const svxDEMove *data, int *idMove);

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEAlignMove structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type  DE(Direct Edit) align move type
    @param [out] data DE(Direct Edit) align move data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDEAlignMoveInit(evxDEAlignMoveType type, svxDEAlignMove *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Interface cvxPartDEAlignMoveInit() can initialize variables DE(Direct Edit) move 
    of this function.

    @param [in] data     DE(Direct Edit) align move input data
    @param [out] idMove  id of DE(Direct Edit) align move feature (NULL to ignore) 

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
    extern evxErrors cvxPartDEAlignMove(const svxDEAlignMove *data, int *idMove);

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEDimMove structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type  DE(Direct Edit) dim move type
    @param [out] data DE(Direct Edit) dim move data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDEDimMoveInit(evxDEDimMoveType type, svxDEDimMove *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Use this function to DE(Direct Edit) dim move faces. Two different methods of 
    move are available, each method requires different types of input.

    @note
    Interface cvxPartDEDimMoveInit() can initialize variables DE(Direct Edit) move 
    of this function.

    @param [in] data     DE(Direct Edit) dim move input data
    @param [out] idMove  id of DE(Direct Edit) dim move feature (NULL to ignore)

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
    extern evxErrors cvxPartDEDimMove(const svxDEDimMove *data, int *idMove);

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEOffset structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDEOffsetInit(svxDEOffset *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Use this function to change DE(Direct Edit) face offset.

    @note
    Interface cvxPartDEOffsetInit() can initialize variables DE(Direct Edit) offset
    of this function.

    @param [in] data       DE(Direct Edit) face offset input data
    @param [out] idOffset  id of DE(Direct Edit) face offset feature (NULL to ignore)

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
    extern evxErrors cvxPartDEOffset(const svxDEOffset *data, int *idOffset);

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEDraft structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data DE(Direct Edit) face draft data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR  
    */
    extern evxErrors cvxPartDEDraftInit(svxDEDraft *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEDraft structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] data  DE(Direct Edit) face draft input data
    @param [out] idDraft   id of DE(Direct Edit) face draft feature (NULL to ignore)

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
    extern evxErrors cvxPartDEDraft(const svxDEDraft *data, int *idDraft);

    //====================================================================================================================
    /** @name Reuse */
    //====================================================================================================================

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDECopy structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type    part or assembly DE(Direct Edit) copy type
    @param [out] data   id of DE(Direct Edit) face draft feature (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDECopyInit(evxDEMoveCopyType type, svxDECopy *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Use this function to DE(Direct Edit) copy faces. Six different methods of 
    copy are available, each method requires different types of input.

    @note
    Interface cvxPartDECopyInit() can initialize variables DE(Direct Edit) copy
    of this function.

    @param [in] data    part or assembly DE(Direct Edit) copy input data
    @param [out] idCopy   id of DE(Direct Edit) copy feature (NULL to ignore)

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
    -        ZW_API_INPUT_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxPartDECopy(const svxDECopy *data, int *idCopy);

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEMirror structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data   DE(Direct Edit) face mirror data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDEMirrorInit(svxDEMirror *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Use this function to create DE(Direct Edit) face mirror.

    @note
    Interface cvxPartDEMirrorInit() can initialize variables DE(Direct Edit) mirror
    of this function.

    @param [in] data    DE(Direct Edit) mirror input data
    @param [out] idMirror  id of DE(Direct Edit) mirror feature (NULL to ignore)

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
    extern evxErrors cvxPartDEMirror(const svxDEMirror *data, int *idMirror);

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEPattern structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [in] type    part or assembly DE(Direct Edit) pattern type
    @param [out] data  part or assembly DE(Direct Edit) pattern data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDEPtnInit(evxDEPtnType type, svxDEPattern *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Use this function to DE(Direct Edit) pattern faces. Six different methods of 
    pattern are available, each method requires different types of input.

    @note
    Interface cvxPartDEMirrorInit() can initialize variables DE(Direct Edit) mirror
    of this function.

    @param [in] data     part or assembly DE(Direct Edit) pattern input data
    @param [out] idPtn  id of DE(Direct Edit) pattern feature (NULL to ignore)

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
    extern evxErrors cvxPartDEPtn(const svxDEPattern *data, int *idPtn);

    //====================================================================================================================
    /** @name Resize */
    //====================================================================================================================

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDEFllt structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data  DE(Direct Edit) face fillet data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDEFlltInit(svxDEFllt *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Use this function to modify DE(Direct Edit) face fillet.

    @note
    Interface cvxPartDEMirrorInit() can initialize variables DE(Direct Edit) mirror
    of this function.

    @param [in] data     DE(Direct Edit) fillet input data 
    @param [out] idFllt  id of DE(Direct Edit) fillet feature (NULL to ignore)

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
    extern evxErrors cvxPartDEFllt(const svxDEFllt *data, int *idFllt);

    /**
    @ingroup zwapi_cmd_direct_edit

    Initialize the svxDERad structure.

    @note
    Do not assign a value to variable "data" before calling this function.
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data  DE(Direct Edit) face radius data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxPartDERadInit(svxDERad *data);

    /**
    @ingroup zwapi_cmd_direct_edit

    Use this function to modify DE(Direct Edit) face radius.

    @note
    Interface cvxPartDEMirrorInit() can initialize variables DE(Direct Edit) mirror
    of this function.

    @param [in] data     DE(Direct Edit) radius input data
    @param [out] idRad  id of DE(Direct Edit) radius feature (NULL to ignore)

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
    extern evxErrors cvxPartDERad(const svxDERad *data, int *idRad);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DATUM_H */