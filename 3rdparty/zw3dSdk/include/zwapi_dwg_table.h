/**
@file zwapi_dwg_table.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing Table API
*/
/**
@defgroup zwapi_dwg_table Drawing Table API
@ingroup DrawingObjectsModel
@brief
@details THE MODULE FOR THE ZW3D Drawing Table API
*/

#pragma once
#ifndef ZW_API_DWG_TABLE_H /* this ifndef surrounds entire header */
#define ZW_API_DWG_TABLE_H

#include "zwapi_dwg_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


    //====================================================================================================================
    /** @name Table Query/Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_table

    Outputs a list of the table entity IDs in the special drawing.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] idDrawing drawing id
    @param [in] type table type
    @param [out] count count of the object
    @param [out] tables table list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgInqTables(int idDrawing, evxTableType type, int *count, int **tables);

    /**
    @ingroup zwapi_dwg_table

    Gets the type of the specified table.

    @param [in] idTable id of table
    @param [out] type table type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern evxErrors cvxDwgInqTableType(int idTable, evxTableType *type);

    /**
    @ingroup zwapi_dwg_table

    Get the row and column count of table.

    @param [in] iTblIdx index of table
    @param [out] pRowNum row number of table
    @param [out] pColNum column number of table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxDwgGetTableSize(int iTblIdx, int *pRowNum, int *pColNum);

    /**
    @ingroup zwapi_dwg_table

    Adjust table size to minimum.

    @param [in] idTable id of table

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgTableAdjustSize(int idTable);

    /**
    @ingroup zwapi_dwg_table

    Modify the insert position of the table.

    @note
    Because this function has an internal call to the "cvxDispRedraw()" function,
    it must be called on the main thread.

    @param [in] idTable id of table
    @param [in] pnt new insert point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    extern evxErrors cvxDwgTableInsPntSet(int idTable, svxPoint2 *pnt);

    /**
    @ingroup zwapi_dwg_table

    Get the insert position of the table.

    @param [in] idTable id of table
    @param [out] pnt insert point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxDwgTableInsPntGet(int idTable, svxPoint2 *pnt);

    /**
    @ingroup zwapi_dwg_table

    Export the specified table to excel file.
    The file type is '.xls' or '.xlsx'.

    @param [in] idTable table id
    @param [in] path export file full path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_PATH
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDwgTableExport(int idTable, const vxLongPath path);

    /**
    @ingroup zwapi_dwg_table

    Link the specified table to the specified excel.

    @param [in] idTable table id
    @param [in] path the linked excel file full path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_WRONG_ROOT_ENV
    */
    extern evxErrors cvxDwgTableLinkToExcel(int idTable, const vxLongPath path);

    //====================================================================================================================
    /** @name Table Row/column Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_table

    Set the row height of the specified row in the table.

    @param [in] idTable index of table
    @param [in] Row index of row
    @param [in] Height height of row, auto adjust row height when Height < 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgTableRowHeightSet(int idTable, int Row, double Height);

    /**
    @ingroup zwapi_dwg_table

    Insert a row below the specified row in the table.

    @param [in] idTable index of table
    @param [in] Row index of row

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgTableRowInsert(int idTable, int Row);

    /**
    @ingroup zwapi_dwg_table

    delete specified row from table.

    @param [in] idTable index of table
    @param [in] Row index of row

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgTableRowDelete(int idTable, int Row);

    /**
    @ingroup zwapi_dwg_table

    Set the column width of the specified column in the table.

    @param [in] idTable index of table
    @param [in] Col index of column
    @param [in] Width width of column, auto adjust column width when width < 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgTableColWidthSet(int idTable, int Col, double Width);

    /**
    @ingroup zwapi_dwg_table

    Insert a column to the right of the specified column in the table.

    @param [in] idTable index of table
    @param [in] Col index of column

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgTableColInsert(int idTable, int Col);

    /**
    @ingroup zwapi_dwg_table

    Delete specified column from table.

    @param [in] idTable index of table
    @param [in] Col index of column

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern evxErrors cvxDwgTableColDelete(int idTable, int Col);


    //====================================================================================================================
    /** @name Table Cell Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_table

    Get text attribute of the specified cell in the table.

    @param [in] idTable index of table
    @param [in] Row index of row
    @param [in] Col index of column
    @param [out] TextAt attribute of text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgTableCellAtGet(int idTable, int Row, int Col, svxTextAt *TextAt);

    /**
    @ingroup zwapi_dwg_table

    Set text attribute of the specified cell in the table.

    Row>0 && Col>0: set text attribute of the specified cell, TextAT can be NULL     
    Row>0 && Col<0: set text attribute of specified row, TextAT can be NULL         
    Row<0 && Col>0: set text attribute of specified column, TextAT can be NULL      
    Row<0 && Col<0: set text attribute for the entire table, TextAT can not be NULL

    @note
    Because this function has an internal call to the "cvxDispRedraw()" function,
    it must be called on the main thread.

    @param [in] idTable index of table
    @param [in] Row index of row
    @param [in] Col index of column
    @param [in] TextAt attribute of text (NULL to use table attribute)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgTableCellAtSet(int idTable, int Row, int Col, svxTextAt *TextAt);


    //====================================================================================================================
    /** @name Table Cell Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_dwg_table

    Modify the value of specified cell of table.

    @param [in] idTable table id
    @param [in] Row row of table
    @param [in] Col column of table
    @param [in] Value modify value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_aPI_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    extern evxErrors cvxDwgTableCellSet(int idTable, int Row, int Col, char *Value);

    /**
    @ingroup zwapi_dwg_table

    Get the value of specified cell of table.

    @param [in] idTable table id
    @param [in] Row row of table
    @param [in] Col column of table
    @param [out] Value value of specified cell
    @param [in] nBytes string max size of value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxDwgTableCellGet(int idTable, int Row, int Col, char *Value, int nBytes);

    /**
    @ingroup zwapi_dwg_table

    merge the selected (endRow-startRow+1)*(endCol-startCol+1) cells to one cell.

    if kFirstData = 0 and the selected cells have a lot of data, it will fail to
    merge them.

    @note
    1 <= startRow <= endRow <= maxRow, 1 <= startCol <= endCol <= maxCol.
    maxRow is the maximum row of the table, maxCol is the maximum column of the table.

    @param [in] idTable table id
    @param [in] startRow start row
    @param [in] endRow end row
    @param [in] startCol start column
    @param [in] endCol end column
    @param [in] kFirstData flag of keep the first data when merging some cells

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    extern void cvxDwgTableCellsMerge(int idTable, int startRow, int endRow, int startCol, int endCol, int kFirstData);

    /**
    @ingroup zwapi_dwg_table

    un-merge the selected cells.

    @param [in] idTable table id
    @param [in] minRow min row
    @param [in] maxRow max row
    @param [in] minCol min column
    @param [in] maxCol max column

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    extern void cvxDwgTableCellsUnMerge(int idTable, int minRow, int maxRow, int minCol, int maxCol);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DWG_TABLE_H */
