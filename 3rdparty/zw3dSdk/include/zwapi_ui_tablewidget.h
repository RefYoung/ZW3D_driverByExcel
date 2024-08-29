/**
@file zwapi_ui_tablewidget.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Table Widget API
*/
/**
@defgroup zwapi_ui_tablewidget Table Widget
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Table Widget API
*/

#pragma once
#ifndef ZW_API_TABLE_WIDGET_H /* this ifndef surrounds entire header */
#define ZW_API_TABLE_WIDGET_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Table Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_tablewidget

    Initialize the parameters of the cvxTableAtSet().

    @note
    Do not assign a value to variable "data" before calling this function.  
    The cvxMemZero() is called inside the interface to empty everything.

    @param [out] data table attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableAtSetInit(svxTableAt *data);

    /**
    @ingroup zwapi_ui_tablewidget

    Applies the attributes specified in "At" to the GUI table identified  
    by "Form" and "idTable".

    @note
    Interface cvxTableAtSetInit() can initialize variables of this function.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] At table attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxTableAtSet(char *Form, int idTable, svxTableAt *At);

    /**
    @ingroup zwapi_ui_tablewidget

    Sets the number of rows and columns in the specified table.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] NumRow number of rows (0 to ignore)
    @param [in] NumCol number of columns (0 to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableSizeSet(char *Form, int idTable, int NumRow, int NumCol);

    /**
    @ingroup zwapi_ui_tablewidget

    Set selected range of the table.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] SelRange select range  
                         left: left column  
                         right: right column  
                         top: top row  
                         bottom: bottom row
    @param [in] bSelect select the range or not,1 for select

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableSetSelRange(const char *Form, int idTable, svxRectangle *SelRange, int bSelect);

    /**
    @ingroup zwapi_ui_tablewidget

    Get selected range of the table, The calling procedure MUST deallocate  
    the output list with cvxMemFree().

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [out] RangeCnt number of ranges
    @param [out] SelRange selected range  
                          left: left column  
                          right: right column  
                          top: top row  
                          bottom: bottom row

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableGetSelRange(const char *Form, int idTable, int *RangeCnt, svxRectangle **SelRange);

    /**
    @ingroup zwapi_ui_tablewidget

    Unselect all items

    @param [in] Form GUI form name
    @param [in] idTable table field id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableUnselectAll(const char *Form, int idTable);


    //====================================================================================================================
    /** @name Table Callback */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_tablewidget

    Get callback parameters for the table widget when the callback function being invoked.  
    For specific usage, please refer to the case TableSet in ApiExample.

    The function will allocate memory to "param", please call cvxTableCallBackParamFree() function to free memory.

    @param [in] form form name
    @param [in] idTable field id
    @param [out] param assigned with table cell callback function parameter pointer

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableCallBackParamGet(const char *form, int idTable, svxTableCallBackParam *param);

    /**
    @ingroup zwapi_ui_tablewidget

    Frees memory for struct svxTableCallBackParam pointer.  
    Sets pointer to NULL if memory was freed successfully.

    @param [in] param address of pointer to be Free

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxTableCallBackParamFree(svxTableCallBackParam *param);


    //====================================================================================================================
    /** @name Table Row/Column */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_tablewidget

    Get the row count the specified table.

    @param [in] Form GUI form name
    @param [in] idTable table field id

    @retval return
    -        the row count the specified table
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxTableRowCnt(const char *Form, int idTable);

    /**
    @ingroup zwapi_ui_tablewidget

    Get the column count of the specified table.

    @param [in] Form GUI form name
    @param [in] idTable table field id

    @retval return
    -        the column count of the specified table.
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxTableColCnt(const char *Form, int idTable);

    /**
    @ingroup zwapi_ui_tablewidget

    Insert a row to table.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row Row id (>=0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableRowInsert(const char *Form, int idTable, int Row);

    /**
    @ingroup zwapi_ui_tablewidget

    Remove a row from table.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row Row id (>=0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableRowRemove(const char *Form, int idTable, int Row);

    /**
    @ingroup zwapi_ui_tablewidget

    Insert a column to table.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Col Column id (>=0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableColInsert(const char *Form, int idTable, int Col);

    /**
    @ingroup zwapi_ui_tablewidget

    Remove a column from table.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Col Column id (>=0)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableColRemove(const char *Form, int idTable, int Col);


    //====================================================================================================================
    /** @name Table Combobox */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a combo box of options  
    specified by the input list of comma-delimited text labels.

    Options: each option is separated by ',' ("1,2,3").

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Options null-terminated, comma-delimited list of text labels

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxTableComboSet(char *Form, int idTable, int Row, int Col, char *Options);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a combo box of options  
    specified by the input list of comma-delimited text labels and images.

    Options: each option is separated by ',' ("1,2,3").  
    Images: each image is separated by ',' ("A.png,B.png,C.png").

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Options null-terminated, comma-delimited list of text labels
    @param [in] Images null-terminated, comma-delimited list of image,
                       it will be ignored when it is NULL

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableComboSet2(const char *Form, int idTable, int Row, int Col, char *Options, char *Images);

    /**
    @ingroup zwapi_ui_tablewidget

    Get the data for the specified table cell defined as combo box or indexed combo box or editable combo box.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [out] Index Selected index
    @param [out] Text Selected text
    @param [in] nBytes string max size of text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableComboGet(const char *Form, int idTable, int Row, int Col, int *Index, char *Text, int nBytes);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a indexed combo box of options  
    specified by the input list of comma-delimited text labels.

    Options: each option is separated by ',' ("1,2,3").

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Options null-terminated, comma-delimited list of text labels

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableIndexComboSet(char *Form, int idTable, int Row, int Col, char *Options);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a editable combo box of options  
    specified by the input list of comma-delimited text labels.

    Options: each option is separated by ',' ("1,2,3").

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Options null-terminated, comma-delimited list of text labels

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableInputComboSet(char *Form, int idTable, int Row, int Col, char *Options);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a indexed combo box of options  
    specified by the input list of comma-delimited text labels and images.

    Options: each option is separated by ',' ("1,2,3").

    Images: each image is separated by ',' ("A.png,B.png,C.png").

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Options null-terminated, comma-delimited list of text labels
    @param [in] Images null-terminated, comma-delimited list of image,
                       it will be ignored when it is NULL

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableIndexComboSet2(const char *Form, int idTable, int Row, int Col, char *Options, char *Images);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a editable combo box of options  
    specified by the input list of comma-delimited text labels and images.

    Options: each option is separated by ',' ("1,2,3").

    Images: each image is separated by ',' ("A.png,B.png,C.png").

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Options null-terminated, comma-delimited list of text labels
    @param [in] Images null-terminated, comma-delimited list of image
                       it will be ignored when it is NULL

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableInputComboSet2(const char *Form, int idTable, int Row, int Col, char *Options, char *Images);

    /**
    @ingroup zwapi_ui_tablewidget

    Set the option index for the specified table cell defined as combo box or indexed combo box or editable combo box.  
    If variable Index is not equal to -1, variable IdxText can be empty,  
    and when variable Index equals -1, set variable IdxText to the selected text.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Index Option index
    @param [in] IdxText null-terminated, Option text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableComboSetOption(const char *Form, int idTable, int Row, int Col, int Index, char *IdxText);


    //====================================================================================================================
    /** @name Table Cell */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_tablewidget

    Get the type of the table cell identified by "Row" and "Col".

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [out] Type Table cell type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableTypeGet(const char *Form, int idTable, int Row, int Col, evxTableCellType *Type);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes sure the table cell identified by "Row" and "Col" is visible  
    within a table that may scroll vertically or horizontally beyond the  
    limits of the display area on its parent form.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxTableVisSet(char *Form, int idTable, int Row, int Col);

    /**
    @ingroup zwapi_ui_tablewidget

    Get check state of the table cell identified by "Row" and "Col" defined as check box.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)

    @retval return
    -        1 - if checked
    -        0 - if not checked or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxTableIsCheck(const char *Form, int idTable, int Row, int Col);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a check box  
    specified by variable check.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Check 1-check, 0-uncheck

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableCheckSet(const char *Form, int idTable, int Row, int Col, int Check);

    /**
    @ingroup zwapi_ui_tablewidget

    Get the text of the table cell identified by "Row" and "Col".

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [out] text text to get
    @param [in] nBytes string max size of text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableCellTextGet(char *Form, int idTable, int Row, int Col, char *text, int nBytes);

    /**
    @ingroup zwapi_ui_tablewidget

    change a cell in table which was specified by VmUiItem2RC(item, iRow, iCol) to "selectable" .

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] State 0 - disable, 1 - enable, 2 - enable & editable

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxTableCellEnableSet(const char *Form, int idTable, int Row, int Col, int State);

    /**
    @ingroup zwapi_ui_tablewidget

    Set the tooltip of the table cell identified by "Row" and "Col".

    @note
    The row and column can not both be -1.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=-1)
    @param [in] Col table column (>=-1)
    @param [in] tip tooltip string

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxTableCellTipSet(const char *Form, int idTable, int Row, int Col, const char *tip);

    /**
    @ingroup zwapi_ui_tablewidget

    Get the tooltip of the table cell identified by "Row" and "Col".

    @note
    The row and column can not both be -1.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=-1)
    @param [in] Col table column (>=-1)
    @param [out] tip tooltip string
    @param [in] nBytes max size of tooltip string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableCellTipGet(const char *Form, int idTable, int Row, int Col, char *tip, int nBytes);

    /**
    @ingroup zwapi_ui_tablewidget

    Set the text of the table cell identified by "Row" and "Col".

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] text text to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableCellTextSet(char *Form, int idTable, int Row, int Col, char *text);

    /**
    @ingroup zwapi_ui_tablewidget

    Set the text and image of the table cell identified by "Row" and "Col".

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Text null-terminated, cell text, it will be ignored when it is NULL
    @param [in] Image null-terminated, image, it will be ignored when it is NULL

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableCellTextSet2(const char *Form, int idTable, int Row, int Col, char *Text, char *Image);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a date editor.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Date Date to set (time in seconds elapsed since 00:00:00 Jan 1, 1970)
    @param [in] DateType Date type to set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableDateSet(const char *Form, int idTable, int Row, int Col, int Date, evxDateType DateType);

    /**
    @ingroup zwapi_ui_tablewidget

    Get the date of the table cell identified by "Row" and "Col".

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [out] Date Date to get (time in seconds elapsed since 00:00:00 Jan 1, 1970)
    @param [out] DateType Date type to get

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableDateGet(const char *Form, int idTable, int Row, int Col, int *Date, evxDateType *DateType);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a color type editor.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Color true color, such as RGB(255,0,0), it can be NULL when the Type is not 0
    @param [in] ClrIdx index color (VX_COLOR_NULL ~ VX_COLOR_LAST)
    @param [in] Type color type: 0-true color, 1-index color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableColorSet(const char *Form, int idTable, int Row, int Col, const svxColor *Color, int ClrIdx, unsigned char Type);

    /**
    @ingroup zwapi_ui_tablewidget

    Get the color of the table cell identified by "Row" and "Col".

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [out] Color true color, such as RGB(255,0,0)
    @param [out] ClrIdx index color (VX_COLOR_NULL ~ VX_COLOR_LAST)
    @param [out] Type color type: 0-true color, 1-index color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableColorGet(const char *Form, int idTable, int Row, int Col, svxColor *Color, int *ClrIdx, unsigned char *Type);

    /**
    @ingroup zwapi_ui_tablewidget

    Makes the table cell identified by "Row" and "Col" a number editor.

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [in] Num null-terminated, number value

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    extern evxErrors cvxTableNumSet(const char *Form, int idTable, int Row, int Col, const char *Num);

    /**
    @ingroup zwapi_ui_tablewidget

    Get number of the table cell identified by "Row" and "Col".

    @param [in] Form GUI form name
    @param [in] idTable table field id
    @param [in] Row table row (>=0)
    @param [in] Col table column (>=0)
    @param [out] Num Number to get
    @param [in] nBytes string max size of Num

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTableNumGet(const char *Form, int idTable, int Row, int Col, char *Num, int Bytes);

    /**
    @ingroup zwapi_ui_tablewidget

    Get the text of the specified cell, the invoker should make sure that the
    For now we support 'ZeTextCell', 'ZeStrComboCell', 'ZeIndexComboCell',
    'ZeInputComboCell' type cell.

    @param [in] Form  form name
    @param [in] idTable  form field
    @param [in] row  row number
    @param [in] col  column number
    @param [out] text  text to store the output text
    @param [in] sizeText  text size

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_TABLE_GETDATA_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableGetText(const char *Form, int idTable, int row, int col, char *text, int sizeText);

    //====================================================================================================================
    /** @name Table Header */
    //====================================================================================================================

    /**
    @ingroup zwapi_ui_tablewidget

    Set the visibility of the horizontal head.

    @param [in] Form  form name
    @param [in] idTable  field id
    @param [in] visible  visible state (1: visible; 0: invisible)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxTableHorHeaderVisibleSet(const char *Form, int idTable, int visible);

    /**
    @ingroup zwapi_ui_tablewidget

    Set the visibility of the vertical head.

    @param [in] Form  form name
    @param [in] idTable  field id
    @param [in] visible  visible state (1: visible; 0: invisible)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxTableVerHeaderVisibleSet(const char *Form, int idTable, int visible);

    /**
    @ingroup zwapi_ui_tablewidget

    Set the Horizontal header string list to table.

    This interface means the header represented by the top row of the table.

    @param [in] Form  form name
    @param [in] idTable  field id
    @param [in] num  number of header list
    @param [in] pHeaderList  header string list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxTableSetHorHeaderList(const char *Form, int idTable, int num, const char **pHeaderList);

    /**
    @ingroup zwapi_ui_tablewidget

    Set the Vertical header string list to table.

    This interface means the header represented by the leftmost column of the table.

    @param [in] Form  form name
    @param [in] idTable  field id
    @param [in] num  number of header list
    @param [in] pHeaderList  header string list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxTableSetVerHeaderList(const char *Form, int idTable, int num, const char **pHeaderList);

    /**
    @ingroup zwapi_ui_tablewidget

    Set header text alignment direction: Center, Left, Right.

    @param [in] Form  form name
    @param [in] idTable  field id
    @param [in] isVertical  Direction: 0-Horizontal, 1-Vertical
    @param [in] align  Alignment mode

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTableSetHeaderAlignment(const char *Form, int idTable, int isVertical, evxTableAlignFlag align);

    /**
    @ingroup zwapi_ui_tablewidget

    set header resize mode of col index,

    0 for QHeaderView::Interactive,

    1 for QHeaderView::Stretch,

    2 for QHeaderView::Fixed,

    3 for QHeaderView::ResizeToContents

    @param [in] Form form name
    @param [in] idTable field id
    @param [in] col column index(>=0)
    @param [in] mode resize mode

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxTableSetHeaderColResizeMode(const char *Form, int idTable, int col, evxTableResizeMode mode);

    /**
    @ingroup zwapi_ui_tablewidget

    set header column size limitation to affect the behavior of resizing and display for columns' width.

    @param [in] Form  form name
    @param [in] idTable  field id
    @param [in] size  the header section limited size(>=-1)
    @param [in] isMin  if it is 1, means minimum limitation, else maximum

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxTableSetHeaderSectionSize(const char *Form, int idTable, int size, int isMin);

    /**
    @ingroup zwapi_ui_tablewidget

    Set header item checked state in table Widget.

    When isVertical = 1, set current vertical header item check state.

    When isVertical = 0, set current horizontal header item check state.

    @param [in] Form form name
    @param [in] idTable form field
    @param [in] isVertical 1-vertical, 0-horizontal
    @param [in] item item number
    @param [in] check 1-check, 0-uncheck

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_TABLE_SETDATA_ERROR
    */
    extern evxErrors cvxTableHeaderCellCheck(const char *Form, int idTable, int isVertical, int item, int check);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_TABLE_WIDGET_H */
