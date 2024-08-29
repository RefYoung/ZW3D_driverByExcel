/**
@file zwapi_xn.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Transaction Operation API
*/
/**
@defgroup zwapi_xn Transaction
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Transaction Operation API
*/

#pragma once
#ifndef ZW_API_XN_H /* this ifndef surrounds entire header */
#define ZW_API_XN_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Undo/Redo */
    //====================================================================================================================
    /**
    @ingroup zwapi_xn

    Returns the current number of operations in the current transaction.  
    This number is passed to cvxEntNew() or cvxEntNewList() as a  
    reference point for finding entities created after completion of a  
    particular operation.

    */
    extern int cvxOpCount(void);

    /**
    @ingroup zwapi_xn

    Get the present undo step count.

    */
    extern int cvxXnUndoCount();

    /**
    @ingroup zwapi_xn

    Creates and logs an undo-redo transaction with a unique name,  
    which is output via "Name".  The transaction is essentially  
    empty, but serves as a marker in the undo-redo transaction  
    list. The marker can be passed to cvxUndoRedoTo() to undo or redo  
    all transactions up to, and including, the marker.

    This function will cause any recently-logged database operations  
    to be flushed to an undo-redo transaction linked to the last-logged  
    transaction.

    This function assumes "Name" is a character pointer to at least  
    sizeof(vxName) bytes of memory allocated by the calling procedure.

    @see cvxCmdMarker().

    @param [out] Name name of undo-redo transaction marker

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxUndoRedoMarker(vxName Name);

    /**
    @ingroup zwapi_xn

    If "Undo" is non-zero, undo the last operation.  
    If "Undo" is zero, redo the last undone operation.

    @param [in] Undo 1-undo, 0-redo

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    extern evxErrors cvxUndoRedo(int Undo);

    /**
    @ingroup zwapi_xn

    Undo/redo up to, and including, the specified transaction --  
    or to the start/end of the undo-redo transaction list --  
    whichever is encountered first.

    @see cvxCmdMarker().

    @param [in] Undo 1-undo, 0-redo
    @param [in] Name undo-redo transaction name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -
    */
    extern evxErrors cvxUndoRedoTo(int Undo, vxName Name);

    /**
    @ingroup zwapi_xn

    If history regen is not active, the input name is assigned to  
    the last operation in the active part's history.  The name is  
    forced to be unique within the active history by appending an  
    id to it if necessary.  The seed name should be short enough  
    that a 4 character id can be appended to it without making the  
    name longer than 31 single-byte characters.

    @param [in] NewName new name for last history operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxPartNameLastOp(vxName NewName);


    //====================================================================================================================
    /** @name Transaction Bundle */
    //====================================================================================================================
    /**
    @ingroup zwapi_xn

    Bundle the steps from the iCount+1 to the present into a new step(transaction).

    Make sure the present steps is greater than iCount, use cvxXnUndoCount() to get it.

    @param [in] iCount  special step count
    @param [in] xn_name  transaction name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    extern evxErrors cvxXnBundle(int iCount, const char *xn_name);

    /**
    @ingroup zwapi_xn

    This function causes subsequent undo-redo transactions to be  
    bundled into one transaction with display update disabled.  
    The input array "Settings" is used to back up settings modified  
    by this function.  This function MUST ALWAYS be paired with a  
    subsequent call to cvxUndoBundleEnd() which requires "Settings"  
    as input.

    If a custom operation is not active at the time this function is  
    called, a new undo-redo transaction will automatically be initiated.

    @param [in] DisableManager 1 to disable update of the Manager form, else 0
    @param [in,out] Settings[] pointer to an empty array of 8 integers

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxUndoBundleStart(int DisableManager, int Settings[]);

    /**
    @ingroup zwapi_xn

    Terminates undo-redo transaction bundling initiated by a previous call to  
    cvxUndoBundleStart(). Refreshes the display if "Redraw" is non-zero.  
    This function MUST ALWAYS be paired with a call to cvxUndoBundleStart()  
    and absolutely requires the "Settings" output by cvxUndoBundleStart()  
    as input in order to properly restore the original settings.

    If a custom operation is not active at the time this function is  
    called, the current undo-redo transaction will be closed.

    @param [in] RefreshDisplay 1 to refresh the display, else 0
    @param [in] Settings[] array of 8 integer settings output by cvxUndoBundleStart()
    @param [in] isError 1 if there was an error during the transaction, else 0

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxUndoBundleEnd(int RefreshDisplay, int Settings[], int isError);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_XN_H */
