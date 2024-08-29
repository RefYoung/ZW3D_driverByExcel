/**
@file zwapi_ui_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Generic Data Types and Structures of the
functions of UI Controls.
*/
/**
@defgroup zwapi_ui_data UI Data
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Generic Data Types and Structures of the
functions of UI Controls.
*/

#pragma once
#ifndef ZW_API_UI_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_UI_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Form Add To Data */
    //====================================================================================================================
    /**
    @brief form type that the "Form" add to
    @ingroup zwapi_ui_data
    */
    typedef enum evxFormAddTo
    {
        VX_FILE_BROWSER, /**<@brief  add the form to file browser*/
        VX_UI_MANAGER,   /**<@brief..add the form to UI manager*/
    } evxFormAddTo;

    //====================================================================================================================
    /** @name Form Function Data */
    //====================================================================================================================
    /**
    @brief gui form action (see cvxFormFunc())
    @ingroup zwapi_ui_data
    */
    typedef enum evxFormAction
    {
        VX_FORM_INIT    = -4, /**<@brief  initialize form */
        VX_FORM_CANCEL  = -3, /**<@brief  take down the form */
        VX_FORM_RESET   = -2, /**<@brief  reset form values */
        VX_FORM_APPLY   = -1, /**<@brief  apply form values and leave form up */
        VX_FORM_OKAY    = 0,  /**<@brief  accept form values and take form down */
        VX_FORM_DEFAULT = 1   /**<@brief  default form values */
    } evxFormAction;

    /**
    @brief form info that the "Form" add to. When user wants to add a form to UI manager or File browser by using dll,  
           he has to create svxFormInfo to store form information and Use cvxFormInsertTo() or cvxFormAddTO() to add.
    @ingroup zwapi_ui_data
    */
    typedef struct svxFormInfo
    {
        vxLongName Formname;  /**<@brief  form name */
        vxLongName Iconame;   /**<@brief  icon name */
        vxLongName Labelname; /**<@brief  page label */
        vxPath Tooltips;      /**<@brief  tooltips */
    } svxFormInfo;

    //====================================================================================================================
    /** @name Form Field Data */
    //====================================================================================================================
    /**
    @brief gui form template field (i.e. widget) classes
    @ingroup zwapi_ui_data
    */
    typedef enum evxFormFldClass
    {
        VX_FORM_FLD_NULL      = -1, /**<@brief  null */
        VX_FORM_FLD_NUM       = 0,  /**<@brief  numeric input */
        VX_FORM_FLD_SLIDER    = 1,  /**<@brief  bounded numeric input (slider bar) */
        VX_FORM_FLD_TXT_IN    = 2,  /**<@brief  text input */
        VX_FORM_FLD_TXT_OUT   = 3,  /**<@brief  text output */
        VX_FORM_FLD_TXT_BTN   = 4,  /**<@brief  text input with an extra button */
        VX_FORM_FLD_TXT_LBL   = 5,  /**<@brief  toggle+label+text */
        VX_FORM_FLD_DATA      = 6,  /**<@brief  data input for handling a template */
        VX_FORM_FLD_LIST      = 7,  /**<@brief  scrolling list */
        VX_FORM_FLD_OPT       = 8,  /**<@brief  exclusive/non-exclusive group of options */
        VX_FORM_FLD_BTNS      = 9,  /**<@brief  menu button group */
        VX_FORM_FLD_GROUP     = 10, /**<@brief  widget grouping entity */
        VX_FORM_FLD_LABEL     = 11, /**<@brief  label only */
        VX_FORM_FLD_SEPARATOR = 12, /**<@brief  separator */
        VX_FORM_FLD_COLOR     = 13, /**<@brief  color widget */
        VX_FORM_FLD_TREE      = 14, /**<@brief  tree widget */
        VX_FORM_FLD_COMBO     = 15, /**<@brief  combo widget */
        VX_FORM_FLD_TAB       = 16, /**<@brief  tab widget */
        VX_FORM_FLD_PROGRESS  = 17, /**<@brief  progress control widget */
        VX_FORM_FLD_TABLE     = 18  /**<@brief  table widget */
    } evxFormFldClass;

    /**
    @brief command template field classes
    @ingroup zwapi_ui_data
    */
    typedef enum evxCmdFldClass
    {
        VX_CMD_FLD_NULL        = 0,  /**<@brief  null */
        VX_CMD_FLD_TEXT        = 1,  /**<@brief  text string */
        VX_CMD_FLD_NUM         = 2,  /**<@brief  number */
        VX_CMD_FLD_DIST        = 3,  /**<@brief  distance */
        VX_CMD_FLD_ANGLE       = 4,  /**<@brief  angle */
        VX_CMD_FLD_POINT       = 5,  /**<@brief  point */
        VX_CMD_FLD_ENTITY      = 6,  /**<@brief  entity */
        VX_CMD_FLD_OPTION      = 7,  /**<@brief  option */
        VX_CMD_FLD_CONT        = 8,  /**<@brief  continue */
        VX_CMD_FLD_FORM        = 9,  /**<@brief  gui form */
        VX_CMD_FLD_WIN         = 10, /**<@brief  pick window */
        VX_CMD_FLD_CMD         = 11, /**<@brief  input via a sub-command */
        VX_CMD_FLD_PIN         = 12, /**<@brief  pin entity pick */
        VX_CMD_FLD_OPTGROUP    = 13, /**<@brief  option group */
        VX_CMD_FLD_NUMUNIT     = 14, /**<@brief  number with unit */
        VX_CMD_FLD_CUSTOMINPUT = 15, /**<@brief  custom input */
        VX_CMD_FLD_PICK        = 16, /**<@brief  pick control */
    } evxCmdFldClass;

    /**
    @brief template field data
    @ingroup zwapi_ui_data
    */
    typedef struct svxTplFld
    {
        char Name[65];  /**<@brief  field name (i.e. label) */
        int Id;         /**<@brief  command field or gui widget id */
        int Class;      /**<@brief  see evxFormFldClass or evxCmdFldClass */
        void *Callback; /**<@brief  pointer to field's callback function */
    } svxTplFld;

    //====================================================================================================================
    /** @name Cursor Management Data */
    //====================================================================================================================
    /**
    @brief cursor display type
    @ingroup zwapi_ui_data
    */
    typedef enum evxCursorType
    {
        VX_CURSOR_STD          = 0, /**<@brief  standard arrow cursor */
        VX_CURSOR_MOUSE        = 1, /**<@brief  mouse shaped cursor */
        VX_CURSOR_BUSY         = 2, /**<@brief  cursor used to indicate system is busy */
        VX_CURSOR_WRENCH       = 3, /**<@brief  wrench shaped cursor */
        VX_CURSOR_PLIERS       = 4, /**<@brief  cursor shaped like pliers */
        VX_CURSOR_SCREW_DRIVER = 5, /**<@brief  screw driver shaped cursor */
        VX_CURSOR_HAMMER       = 6, /**<@brief  cursor shaped like a hammer */
        VX_CURSOR_TOGGLE       = 7, /**<@brief  cursor with two semi-circular arrows */
        VX_CURSOR_HAND         = 8, /**<@brief  cursor shaped like a hand */
        VX_CURSOR_WRENCH_PLUS  = 9  /**<@brief  wrench shaped cursor with plus */
    } evxCursorType;

    //====================================================================================================================
    /** @name List Widget Data */
    //====================================================================================================================
    /**
    @brief UI event type
    @ingroup zwapi_ui_data
    */
    typedef enum evxUiEvt
    {
        VX_UIEVT_INVALID = -6,              /**<@brief  invalid */
        VX_UIEVT_HELP    = -5,              /**<@brief  help */
        VX_UIEVT_CANCEL  = -3,              /**<@brief  cancel */
        VX_UIEVT_RESET   = -2,              /**<@brief  reset */
        VX_UIEVT_APPLY   = -1,              /**<@brief  apply */
        VX_UIEVT_OKAY    = 0,               /**<@brief  accept */
        VX_UIEVT_DEF     = 1,               /**<@brief  default */
        VX_UIEVT_LBTNCLK,                   /**<@brief  left button click (mouse) */
        VX_UIEVT_LBTNUP = VX_UIEVT_LBTNCLK, /**<@brief  left button click up (mouse) */
        VX_UIEVT_MBTNCLK,                   /**<@brief  middle button click (mouse) */
        VX_UIEVT_RBTNCLK,                   /**<@brief  right button click (mouse) */
        VX_UIEVT_LBTNDCLK,                  /**<@brief  left button double click (mouse) */
        VX_UIEVT_CHAR,                      /**<@brief  key up and down (keyboard) */
        VX_UIEVT_FOCUSKILL,                 /**<@brief  keyboard kill focus */
        VX_UIEVT_SCROLL,                    /**<@brief  slider (scroll) */
        VX_UIEVT_HOTKEY,                    /**<@brief  hotkey */
        VX_UIEVT_CMDONOFF,                  /**<@brief  command with on/off suffix */
        VX_UIEVT_FOCUSSET,                  /**<@brief  keyboard set focus */
        VX_UIEVT_STRING,                    /**<@brief  string */
        VX_UIEVT_HOVER,                     /**<@brief  Hover for tooltip */
        VX_UIEVT_LBTNDOWN,                  /**<@brief  left button down event */
        VX_UIEVT_SORT,                      /**<@brief  update sequence */
        VX_UIEVT_DATACHANGE,                /**<@brief  data change */
        VX_UIEVT_PREVIEW,                   /**<@brief  preview */
        VX_UIEVT_SELCHANGED = 19,           /**<@brief  system event log change */
        VX_UIEVT_STATECHANGED,              /**<@brief  change state */
        VX_UIEVT_MOUSEMOVE,                 /**<@brief  mouse move event */
        VX_UIEVT_DROP = 22,                 /**<@brief  drop event */
        VX_UIEVT_IGNORE,                    /**<@brief  ignore event */
    } evxUiEvt;

    /**
    @brief ListWidget event date
    @ingroup zwapi_ui_data
    */
    typedef struct svxListCallBackParam
    {
        evxUiEvt evt; /**<@brief  event type */
        int iRow;     /**<@brief  row number */
        int key;      /**<@brief  the vale of keyboard */
    } svxListCallBackParam;

    //====================================================================================================================
    /** @name Table Attribute Data */
    //====================================================================================================================
    /**
    @brief table attributes
    @ingroup zwapi_ui_data
    */
    typedef struct svxTableAt
    {
        int Row, Col; /**<@brief  specification of row/column that attributes are applied to;
                     ** Row > -1 and Col > -1 identifies a specific cell in the table;
                     ** Row > -1 and Col = -1 identifies an entire row;
                     ** Row = -1 and Col > -1 identifies an entire column;
                     ** Row = -1 and Col = -1 identifies the entire table.
                     */

        int RowHeight; /**<@brief  row height; 0 to ignore; -1 for default height */
        int ColWidth;  /**<@brief  column width; 0 to ignore; -1 for default height */

        int SetBgColor;   /**<@brief  1 to set background color of table cells specified by
                     ** "Row" and "Col"; 0 to ignore.
                     */
        svxColor BgColor; /**<@brief  background color if "SetBgColor = 1" */

        int SetFgColor;   /**<@brief  1 to set foreground color of table cells specified by
                     ** "Row" and "Col"; 0 to ignore.
                     */
        svxColor FgColor; /**<@brief  foreground color if "SetFgColor = 1" */

        int SortRows; /**<@brief  1 to sort rows on column header; -1 to not sort; 0 to ignore */

        int AutoSize; /**<@brief  1 to auto-size all rows to the size of the largest item;
                     ** 2 to auto-size all columns to the size of the largest item;
                     ** 3 to auto-size all rows and columns; -1 to disable auto-size;
                     ** 0 to ignore.
                     */

        int AllowResize; /**<@brief  1 to allow rows to be resized; 2 to allow columns to be resized;
                     ** 3 to allow both to be resized; -1 to disable resize; 0 to ignore.
                     ** The priority of auto size is higher than that of allowsize.
                     */

        int Editable; /**<@brief  1 to make cells specified by "Row" and "Col" editable;
                     ** -1 to make specified cells not editable; 0 to ignore.
                     */
    } svxTableAt;

    //====================================================================================================================
    /** @name Table Callback Data */
    //====================================================================================================================
    /**
    @brief table widget event types
    @ingroup zwapi_ui_data
    */
    typedef enum evxTableEvent
    {
        VX_LEFT_CLICK  = 2,     /**<@brief  left button click (mouse) */
        VX_RIGHT_CLICK = 4,     /**<@brief  right button click (mouse) */
        VX_LEFT_DOUBLE_CLICK,   /**<@brief  left button double click (mouse) */
        VX_KEY_UP_DOWN,         /**<@brief  key up and down (keyboard) */
        VX_HOT_KEY = 9,         /**<@brief  hotkey */
        VX_SORT    = 15,        /**<@brief  sort event */
        VX_DATA_CHANGED,        /**<@brief  data changed event */
        VX_CELL_BUTTON_CLICKED, /**<@brief  button in table cell clicked event */
        VX_MOUSE_MOVE        = 21,
        VX_CELL_CLOSE_EDITOR = 23, /**<@brief  table cell close editor event */
    } evxTableEvent;

    /**
    @brief table widget alignment mode
    @ingroup zwapi_ui_data
    */
    typedef enum evxTableAlignFlag
    {
        VX_TABLE_ALIGN_CENTER = 0, /**<@brief  align center */
        VX_TABLE_ALIGN_LEFT   = 1, /**<@brief  align left */
        VX_TABLE_ALIGN_RIGHT  = 2, /**<@brief  align right */
    } evxTableAlignFlag;

    /**
    @brief table widget resize mode
    @ingroup zwapi_ui_data
    */
    typedef enum evxTableResizeMode
    {
        VX_TABLE_RESIZE_MODE_INTERACTIVE      = 0, /**<@brief  QHeaderView::Interactive */
        VX_TABLE_RESIZE_MODE_STRETCH          = 1, /**<@brief  QHeaderView::Stretch */
        VX_TABLE_RESIZE_MODE_FIXED            = 2, /**<@brief  QHeaderView::Fixed */
        VX_TABLE_RESIZE_MODE_RESIZETOCONTENTS = 3, /**<@brief  QHeaderView::ResizeToContents */
    } evxTableResizeMode;

    /**
    @brief keyboard event
    @ingroup zwapi_ui_data
    */
    typedef struct svxKeyEvent
    {
        unsigned int modifier; /**<@brief  Synchronous key:CTRL, SHIFT, ALT, or WIN key etc. */
        unsigned int keyCode;  /**<@brief  A~Z, F1~F12, 0~9 etc, mapping to Microsoft virtual key directly */
    } svxKeyEvent;

    /**
    @brief data type
    @ingroup zwapi_ui_data
    */
    typedef enum evxDateType
    {
        VX_DATE_WITH_TIME, /**<@brief  with time */
        VX_DATE_ONLY,      /**<@brief  only date */
    } evxDateType;

    /**
    @brief table cell data
    @ingroup zwapi_ui_data
    */
    typedef struct svxTableCellData
    {
        union svxCellData
        {
            struct svxTextData
            {
                const char *pImage;     /**<@brief In */
                char *buf;              /**<@brief In/Out */
                int nBufSize;           /**<@brief In */
                const char *btnToolTip; /**<@brief In */
                int btnWidth;           /**<@brief In */
                int btnHeight;          /**<@brief In */
                unsigned char isCIF;    /**<@brief In: 0-ANSI string, 1-buf is multi-byte string in CIF format */
            } textData;
            struct svxComboData
            {
                const char *pImageList; /**<@brief In */
                const char *pTextList;  /**<@brief In */
                char *pSelTextBuf;      /**<@brief In/Out */
                int nBufSize;           /**<@brief In */
                int iSel;               /**<@brief In/Out */
            } comboData;
            struct svxCheckData
            {
                const char *psLabel; /**<@brief In */
                int iCheck;          /**<@brief In/Out */
            } checkBoxData;
            struct svxDateData
            {
                int secsFromEpoch;    /**<@brief In/Out */
                evxDateType dateType; /**<@brief In */
            } dateData;
            struct svxColorData
            {
                unsigned char type; /**<@brief In: 0-true color, 1-index color, 2-include FROM PART */
                int clrIndex;       /**<@brief In/Out */
                int r, g, b;        /**<@brief In/Out */
            } colorData;
            struct svxNumData
            {
                int iMin;     /**<@brief In */
                int iMax;     /**<@brief In */
                char *buf;    /**<@brief In/Out */
                int nBufSize; /**<@brief In */
            } numData;
        } cellData;
        int iAttrData;
        struct svxCompareData
        {
            int iType;           /**<@brief In 1-integer, 2-string, 3-double */
            int iInteger;        /**<@brief In */
            const char *pString; /**<@brief In */
            double dDouble;      /**<@brief In */
            int iKeyCol;         /**<@brief In */
        } compareData;
        int idx;
        int txtMaxLen;
        const char *placeHolderText;
        void *validator;
    } svxTableCellData;

    /**
    @brief table widget callback function parameters
    @ingroup zwapi_ui_data
    */
    typedef struct svxTableCallBackParam
    {
        evxTableEvent evt;         /**<@brief  table widget event types */
        svxKeyEvent key;           /**<@brief  keyboard event */
        int iRow;                  /**<@brief  row */
        int iCol;                  /**<@brief  column */
        svxTableCellData cellData; /**<@brief  table cell data */
        int *pResult;
        int iSortSequenceSize; /**<@brief size of aSortSequence */
        int *aSortSequence;
    } svxTableCallBackParam;

    //====================================================================================================================
    /** @name Tree Widget Header Data */
    //====================================================================================================================
    /**
    @brief ui alignment types
    @ingroup zwapi_ui_data
    */
    typedef enum evxAlignFlag
    {
        VX_ALIGN_CENTER = 0, /**<@brief  center align */
        VX_ALIGN_LEFT   = 1, /**<@brief  left align */
        VX_ALIGN_RIGHT  = 2, /**<@brief  right align */
    } evxAlignFlag;

    //====================================================================================================================
    /** @name Table Cell Data */
    //====================================================================================================================
    /**
    @brief table cell types
    @ingroup zwapi_ui_data
    */
    typedef enum evxTableCellType
    {
        VX_TABLECELL_TYPE_TEXT           = 0, /**<@brief  text */
        VX_TABLECELL_TYPE_COMBOBOX       = 1, /**<@brief  combobox */
        VX_TABLECELL_TYPE_CHECKBOX       = 2, /**<@brief  checkbox */
        VX_TABLECELL_TYPE_INDEX_COMBOBOX = 3, /**<@brief  index combobox */
        VX_TABLECELL_TYPE_INPUT_COMBOBOX = 4, /**<@brief  input combobox */
        VX_TABLECELL_TYPE_TEXT_BUTTON    = 5, /**<@brief  text button */
        VX_TABLECELL_TYPE_DATE           = 6, /**<@brief  date */
        VX_TABLECELL_TYPE_COLOR          = 7, /**<@brief  color */
        VX_TABLECELL_TYPE_NUMBER         = 8, /**<@brief  number */
    } evxTableCellType;

    //====================================================================================================================
    /** @name Tree Item Data */
    //====================================================================================================================
    /**
    @brief tree item data
    @ingroup zwapi_ui_data
    */
    typedef enum evxTreeItemFlag
    {
        VX_TREE_NO_ITEM_FLAGS           = 0x0000,     /**<@brief  The item does not have any properties set */
        VX_TREE_IS_SELECTABLE           = 0x0001,     /**<@brief  The item can be selected */
        VX_TREE_IS_EDITABLE             = 0x0002,     /**<@brief  The item can be edited */
        VX_TREE_IS_DRAG_ENABLE          = 0x0004,     /**<@brief  The item be dragged */
        VX_TREE_IS_DROP_ENABLE          = 0x0008,     /**<@brief  The item be used as a drop target */
        VX_TREE_IS_CHECKABLE            = 0x0010,     /**<@brief  The item can be checked or unchecked by the user */
        VX_TREE_IS_ENABLE               = 0x0020,     /**<@brief  The user can interact with the item */
        VX_TREE_IS_TRISTATE             = 0x0040,     /**<@brief  The item's state depends on the state of its children */
        VX_TREE_ITEM_NEVER_HAS_CHILDREN = 0x0080,     /**<@brief  The item never has child items */
        VX_TREE_ITEM_IS_USER_TRISTATE   = 0x0100,     /**<@brief  The user can cycle through three separate states */
        VX_TREE_ITEM_IS_GRAY            = 0x00010000, /**<@brief  The item shown in gray */
    } evxTreeItemFlag;

    /**
    @brief integer tree widget item id
    @ingroup zwapi_ui_data
    */
    typedef int vxTreeItemId;


/*  tree widget item options */
#define VX_INVALID_ITEM ((vxTreeItemId)-1)
#define VX_INVISIBLE_ROOT_ITEM ((vxTreeItemId)0)
#define VX_INSERT_LAST ((vxTreeItemId)-1) /* Insert at last position  */
#define VX_INSERT_FIRST ((vxTreeItemId)0) /* Insert node at first position */

    /**
    @brief tree widget item types
    @ingroup zwapi_ui_data
    */
    typedef enum evxTreeItemType
    {
        VX_ITEM       = 0, /**<@brief  item */
        VX_FINISHMARK = 1  /**<@brief  finish mark */
    } evxTreeItemType;

    /**
    @brief tree widget event types
    @ingroup zwapi_ui_data
    */
    typedef enum
    {
        VX_EMPTY = 0,
        VX_LEFT_DOWN,          /**<@brief  left mouse click down */
        VX_LEFT_UP,            /**<@brief  left mouse click up */
        VX_MIDDLE_DOWN,        /**<@brief  middle mouse click up */
        VX_MIDDLE_UP,          /**<@brief  middle mouse click up */
        VX_RIGHT_DOWN,         /**<@brief  right mouse click down */
        VX_RIGHT_UP,           /**<@brief  right mouse click up */
        VX_BOX_SELECTION_DONE, /**<@brief  box selection over */
        VX_LABEL_CHANGED,      /**<@brief  label name check */
        VX_EDITOR_CLOSED,      /**<@brief  item editor closed*/
        VX_DBL_LEFT,           /**<@brief  left mouse double click */
        VX_DROP,               /**<@brief  drop after dragging */
        VX_KEY_PRESS,          /**<@brief  key */
        VX_HOVER,              /**<@brief  normal hover */
        VX_HOVER_TIMEOUT,      /**<@brief  item hovered timeout */
        VX_ENTER,
        VX_LEAVE
    } evxTreeEvent;

    /**
    @brief tree widget element codes
    @ingroup zwapi_ui_data
    */
    typedef enum evxTreeHitPos
    {
        VXTHP_BUTTON    = 0x0001, /**<@brief  hit on expand button associated with a node */
        VXTHP_ICON      = 0x0002, /**<@brief  Hit on node's icon */
        VXTHP_LABEL     = 0x0004, /**<@brief  Hit on node's label name */
        VXTHP_ITEM      = 0x0006, /**<@brief  V_ZDM_ICON|V_ZDM_LABEL */
        VXTHP_SPACE     = 0x0008, /**<@brief  Hit on design tree space */
        VXTHP_CHECKBOX  = 0x0010, /**<@brief  Hit on the checkbox */
        VXTHP_APD_ICON1 = 0x0020, /**<@brief  Hit on node's second icon */
        VXTHP_APD_ICON2 = 0x0040, /**<@brief  Hit on node's third icon */
        VXTHP_HEADER    = 0x0080, /**<@brief  Hit on the header of the tree */
    } evxTreeHitPos;

    /**
    @brief tree widget callback function parameters
    @ingroup zwapi_ui_data
    */
    typedef struct svxTreeCbParam
    {
        evxTreeEvent mode;
        const char *shell;
        int field;
        vxTreeItemId item; /**<@brief current hover id */
        int column;        /**<@brief  the column where the current item is located */
        union uvxU
        {
            struct svxDRAG /**<@brief  drag multiple nodes */
            {
                vxTreeItemId pressedItem;
                vxTreeItemId *selection;
                int num;
                vxTreeItemId droppedItem;
                int dropPos; /**<@brief  0:item,1:above,2:below,3:viewport, */
            } svxdrag;

            struct svxHIT
            {
                evxTreeHitPos pos; /**<@brief  Clicking position (evxTreeHitPos)*/
            } svxhit;

            struct svxSELECTION /**<@brief  multiple nodes selection */
            {
                vxTreeItemId *idList;
                int num;
            } svxselection;

            struct svxLABELEDIT
            {
                char *text; /**<@brief  pointer to node's label string */
            } svxlabel;
        } uvxu;

        svxKeyEvent key; /**<@brief  key*/

        int state; /**<@brief  1:state is on, 0:state is off
                                 or V_ZDM_EXPAND/V_ZDM_COLLAPSE */

        int itemIsDisabled; /**<@brief  1:node is disabled, 0:node is enabled 
                                 if success/ok/enable next procedure, assign it to 0, else to 1 */
    } svxTreeCbParam;

    //====================================================================================================================
    /** @name Tree Item State Data */
    //====================================================================================================================
    /**
    @brief check tree item state
    @ingroup zwapi_ui_data
    */
    typedef enum evxTreeCheckState
    {
        VX_TREE_ITEM_UNCHECKED,        /**<@brief  The item not checked */
        VX_TREE_ITEM_BLACK_CHECKED = 4 /**<@brief  The item checked */
    } evxTreeCheckState;

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_TREE_H */
