/**
@file zwapi_ui_treeview.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Tree View API
*/
/**
@defgroup zwapi_ui_treeview Tree View
@ingroup UIModel
@brief
@details THE MODULE FOR THE ZW3D Tree View API
*/

#pragma once
#ifndef ZW_API_TREE_VIEW_H /* this ifndef surrounds entire header */
#define ZW_API_TREE_VIEW_H

#include "zwapi_ui_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Tree Widget Header */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_treeview

    Set the icon of tree header according to specified section.  
    This interface is used for the widget TreeView.

    @param [in] name form name
    @param [in] field field number
    @param [in] section section of tree header
    @param [in] icon tree header icon name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxTreeSetHeaderIcon(const char *name, int field, int section, const char *icon);

    /**
    @ingroup zwapi_ui_treeview

    This function sets the label for the header of the specified column of the tree widget.

    @note
    When the user does not use this interface to set the header information of the tree node,   
    user cannot do other processing on the header information.  
    For example, user cannot set the alignment of the header information.(cvxTreeSetHeaderTextAlignment).

    @param [in] form form name
    @param [in] field field id
    @param [in] col column
    @param [in] text text

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxTreeSetHeaderText(const char *form, int field, int col, const char *text);

    /**
    @ingroup zwapi_ui_treeview

    This function gets the header size of the specified tree widget.

    @param [in] form form name
    @param [in] field the item id
    @param [out] width width of the item
    @param [out] height height of the item

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeHeaderGetSize(const char *form, int field, int *width, int *height);

    /**
    @ingroup zwapi_ui_treeview

    This function sets the tree view header text alignment by column index.

    @note
    When the user does not use the cvxTreeSetHeaderText() interface to set the header 
    information of the tree control, calling this interface will have no effect.

    @param [in] form form name
    @param [in] field field number
    @param [in] col column to set
    @param [in] align alignment flag

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxTreeSetHeaderTextAlignment(const char *form, int field, int col, evxAlignFlag align);


    //====================================================================================================================
    /** @name Tree Widget Column */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_treeview

    This function sets the number of columns displayed in the specified tree widget.

    @param [in] form form name
    @param [in] field field id
    @param [out] count count

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxTreeSetColumnCount(const char *form, int field, int count);

    /**
    @ingroup zwapi_ui_treeview

    This function get the number of columns displayed in the specified tree widget.

    @param [in] form form name
    @param [in] field field id

    @retval return
    -        the number of columns.
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxTreeGetColumnCount(const char *form, int field);

    /**
    @ingroup zwapi_ui_treeview

    Set the width of the given column to the width specified.

    @param [in] form form name
    @param [in] field field number
    @param [in] col column to set
    @param [in] width width

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxTreeSetColumnWidth(const char *form, int field, int col, int width);

    /**
    @ingroup zwapi_ui_treeview

    Get the width of the given column.

    @param [in] form form name
    @param [in] field field number
    @param [in] col column to get

    @retval return
    -        the width of the given column.
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern int cvxTreeGetColumnWidth(const char *form, int field, int col);

    /**
    @ingroup zwapi_ui_treeview

    Hide or show the specified column.

    @param [in] form form name
    @param [in] field field number
    @param [in] col column to set
    @param [in] hide whether to hide the column (1 to hide, 0 to show)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxTreeSetColumnHidden(const char *form, int field, int col, int hide);

    /**
    @ingroup zwapi_ui_treeview

    Get visible state of the specified column.

    @param [in] form form name
    @param [in] field field number
    @param [in] col column to query

    @retval return
    -        1 - the column is hidden
    -        0 - the column is not hidden or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern int cvxTreeIsColumnHidden(const char *form, int field, int col);

    /**
    @ingroup zwapi_ui_treeview

    Resize the width of the special column to show their contents completely.

    @param [in] form form name
    @param [in] field field number
    @param [in] col column (-1 to resize all columns)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxTreeAutoResizeColumn(const char *form, int field, int col);


    //====================================================================================================================
    /** @name Tree Widget State */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_treeview

    Expand all the nodes of the tree.

    @param [in] form form name
    @param [in] field field number

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxTreeExpandAll(const char *form, int field);

    /**
    @ingroup zwapi_ui_treeview

    Collapse all the nodes of the tree.

    @param [in] form form name
    @param [in] field field number

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern void cvxTreeCollapseAll(const char *form, int field);

    /**
    @ingroup zwapi_ui_treeview

    This function is to un-select all highlighted nodes of the tree widget.

    @param [in] form form name
    @param [in] field field id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeUnselectAll(const char *form, int field);

    /**
    @ingroup zwapi_ui_treeview

    This function sets the selection mode of a tree widget.

    @param [in] form form name
    @param [in] field field number
    @param [in] mode tree view control selection mode  
                     0: No selection;  
                     1: Single selection;  
                     2: Multiple selection;  
                     3: Extended selection;  
                     4: Contiguous selection

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxTreeSetSelectionMode(const char *form, int field, int mode);

    /**
    @ingroup zwapi_ui_treeview

    This function sets the tree view control selection behavior.  
    behavior 0 for select items, 1 for select rows, and 2 for select columns.

    @param [in] form form name
    @param [in] field field number
    @param [in] behavior tree view control selection behavior

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern evxErrors cvxTreeSetSelectionBehavior(const char *form, int field, int behavior);


    //====================================================================================================================
    /** @name Tree Widget Callback */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_treeview

    Get callback parameters for the tree widget when the callback function being invoked.

    @param [in] form form name
    @param [in] field filed id
    @param [in] itemId item id
    @param [out] cbp assigned with tree callback function parameter pointer

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetCbParam(const char *form, int field, int itemId, svxTreeCbParam *cbp);


    //====================================================================================================================
    /** @name Tree Item */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_treeview

    This function gets and return the total nodes of tree in the specified tree widget,
    including children nodes.

    @param [in] form form name
    @param [in] field field id

    @retval return
    -        number of tree items
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxTreeItemsCount(const char *form, int field);

    /**
    @ingroup zwapi_ui_treeview

    Add a node with specified informations to the tree widget.

    @param [in] form form name
    @param [in] field field number
    @param [in] parentId Parent node id, if without parent, assign 0
    @param [in] siblingId Prev sibling node id, if without previous node, assign VX_INSERT_LAST
    @param [in] label Node label text
    @param [in] imgIdx Index of the item's expanded image in the imagelist
    @param [in] folderIdx Index of the  item's collapsed image in the imagelist
    @param [in] itemType Node type
    @param [in] dbIdx Object index in database
    @param [in] itemflag evxTreeItemFlag
    @param [out] outItemId new added node's id
    @param [in] cmdName icon name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeAddItem(const char *form, int field, int parentId, int siblingId, const char *label,
                                    int imgIdx, int folderIdx, evxTreeItemType itemType, int dbIdx, int itemflag, int *outItemId, const char *cmdName);

    /**
    @ingroup zwapi_ui_treeview

    Set the specified nodes' flags.

    @param [in] form form name
    @param [in] field field number
    @param [in] count number of nodes to set
    @param [in] ids tree node ids
    @param [in] flag tree node flag (evxTreeItemFlag)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeSetItemFlag(const char *form, int field, int count, int *ids, int flag);

    /**
    @ingroup zwapi_ui_treeview

    Get flag of the specified node.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id
    @param [out] flag tree node flag (evxTreeItemFlag)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetItemFlag(const char *form, int field, int id, int *flag);

    /**
    @ingroup zwapi_ui_treeview

    Set the cell item (the specified column of the specified tree node) icon by name.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id
    @param [in] col column to set
    @param [in] iconName icon name without extension name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeSetItemIconNameByColumn(const char *form, int field, int id, int col, const char *iconName);

    /**
    @ingroup zwapi_ui_treeview

    Set the cell item text for the specified column of the specified tree node.

    @param [in] form form name
    @param [in] field field id
    @param [in] id tree item id
    @param [in] col column
    @param [in] text column text

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeSetItemTextByColumn(const char *form, int field, int id, int col, const char *text);

    /**
    @ingroup zwapi_ui_treeview

    Get the cell item text of the specified column of the tree node.

    @param [in] form form name
    @param [in] field field id
    @param [in] id tree item id
    @param [in] col column
    @param [out] text column text
    @param [in] size column text size

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern void cvxTreeGetItemTextByColumn(const char *form, int field, int id, int col, char *text, int size);

    /**
    @ingroup zwapi_ui_treeview

    Set text's RGB color of specified cell.

    @param [in] form form name
    @param [in] field field id
    @param [in] id tree item id
    @param [in] col column id (-1 to set whole row)
    @param [in] color color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeSetItemTextColor(const char *form, int field, int id, int col, svxColor *color);

    /**
    @ingroup zwapi_ui_treeview

    Get object index in database which the specified node is associated to.

    @param [in] form form name
    @param [in] field field id
    @param [in] id tree node id
    @param [out] objectIndex object index in database matched to node

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeGetDBIdByItem(const char *form, int field, int id, int *objectIndex);

    /**
    @ingroup zwapi_ui_treeview

    Delete specified tree node and its descendants. if id is VX_INVALID_ITEM, then delete all.

    @param [in] form form name
    @param [in] field field id
    @param [in] id node to be deleted (-1 to delete all nodes)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeDeleteItem(const char *form, int field, int id);

    /**
    @ingroup zwapi_ui_treeview

    Delete specified node's descendants. if id is INVALID_TNODE_ID, return directly.

    @param [in] form form name
    @param [in] field field id
    @param [in] id node to be deleted

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeDeleteSubItem(const char *form, int field, int id);

    /**
    @ingroup zwapi_ui_treeview

    Activate the specified node to edit by a line edit.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id
    @param [in] col column
    @param [in] defaultLabel default text when editing

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeEditItemByLineEdit(const char *form, int field, int id, int col, const char *defaultLabel);

    /**
    @ingroup zwapi_ui_treeview

    Makes the cell identified by "id" and "col" a indexed combo box of options  
    specified by the input list of comma-delimited text labels and images.

    Options: each option is separated by ',' ("1,2,3").

    Images: each image is separated by ',' ("A.png,B.png,C.png").

    @param [in] form form name
    @param [in] field field id
    @param [in] id tree item id
    @param [in] col column
    @param [in] Options null-terminated, comma-delimited list of text labels (NULL to ignore)
    @param [in] Images null-terminated, comma-delimited list of image (NULL to ignore)
    @param [in] curIndex the current index of combobox

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    extern evxErrors cvxTreeEditItemByComboBox(const char *form, int field, int id, int col, const char *Options, const char *Images, int curIndex);

    /**
    @ingroup zwapi_ui_treeview

    Get previous sibling node.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id
    @param [out] prevId previous sibling node id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetPrevSiblingItem(const char *form, int field, int id, int *prevId);

    /**
    @ingroup zwapi_ui_treeview

    Get next sibling node.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id
    @param [out] nextId next sibling node id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetNextSiblingItem(const char *form, int field, int id, int *nextId);

    /**
    @ingroup zwapi_ui_treeview

    Get the nth(index) child item of the specified node from the tree widget.   
    If the node has no child node or index is not valid, child_id will be VX_INVALID_ITEM.

    @param [in] form form name
    @param [in] field field id
    @param [in] id parent node id
    @param [in] index index of node, 0 based
    @param [out] child_id first child node id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetChildItem(const char *form, int field, int id, int index, int *child_id);

    /**
    @ingroup zwapi_ui_treeview

    Get the count of the child nodes for the specified node from the tree widget.

    @param [in] form form name
    @param [in] field field id
    @param [in] id parent node id
    @param [out] count count of the child nodes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetChildrenCount(const char *form, int field, int id, int *count);

    /**
    @ingroup zwapi_ui_treeview

    Get the parent node id for the specified tree node.

    @param [in] form form name
    @param [in] field field id
    @param [in] id tree node id
    @param [out] parent parent node id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetParentItem(const char *form, int field, int id, int *parent);

    /**
    @ingroup zwapi_ui_treeview

    Move tree nodes to the specified position with all its descendants.

    @param [in] form form name
    @param [in] field field number
    @param [in] numNodes number of nodes moved
    @param [in] ids list of nodes moved
    @param [in] insParentId destination node's parent. If none, pass with 0
    @param [in] siblingId destination node's prev sibling,  
                          if insert as first child, pass with VX_INSERT_FIRST,  
                          if insert as last child,  pass with VX_INSERT_LAST

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeMoveItems(const char *form, int field, int numNodes, int *ids, int insParentId, int siblingId);

    /**
    @ingroup zwapi_ui_treeview

    Get all descendants or only children of the specified parent node. The calling  
    procedure MUST deallocate the output list.

    @param [in] form form name
    @param [in] field form field id
    @param [in] isAll 1-all descendants, 0-only children
    @param [in] parent parent id
    @param [out] num number of nodes
    @param [out] ids node IDs

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetDescendants(const char *form, int field, int isAll, int parent, int *num, int **ids);

    /**
    @ingroup zwapi_ui_treeview

    Get all of the current selected nodes of the tree widget. The calling procedure  
    MUST deallocate the output list.

    @param [in] form form name
    @param [in] field field number
    @param [out] count number of nodes
    @param [out] ids IDs of selected nodes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    extern evxErrors cvxTreeGetSelectedItems(const char *form, int field, int *count, int **ids);


    //====================================================================================================================
    /** @name Tree Item State */
    //====================================================================================================================
    /**
    @ingroup zwapi_ui_treeview

    Judge whether the tree node is selected.

    @param [in] form form name
    @param [in] field filed id
    @param [in] id node to be checked

    @retval return
    -        1 - the node is selected
    -        0 - the node is not selected or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FORM_EXIST_ERROR
    */
    extern int cvxTreeIsItemSelected(const char *form, int field, int id);

    /**
    @ingroup zwapi_ui_treeview

    This function is to select the specified node of the tree widget.

    @param [in] form form name
    @param [in] field field id
    @param [in] id tree node id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeSelectItem(const char *form, int field, int id);

    /**
    @ingroup zwapi_ui_treeview

    Set the checkable state of the specified tree node.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id
    @param [in] checkable checkable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeSetItemCheckable(const char *form, int field, int id, int checkable);

    /**
    @ingroup zwapi_ui_treeview

    Get check state of the tree node identified by id defined as check box.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id

    @retval return
    -         evxTreeCheckState
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxTreeCheckState cvxTreeGetItemCheckState(const char *form, int field, int id);

    /**
    @ingroup zwapi_ui_treeview

    Set check state of the tree node identified by id defined as check box.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id
    @param [in] checkState check state
    @param [in] extToChild flag to set children nodes check state

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern void cvxTreeSetItemCheckState(const char *form, int field, int id, evxTreeCheckState checkState, int extToChild);

    /**
    @ingroup zwapi_ui_treeview

    Check whether the specified node is expanded.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id

    @retval succeeds
    -        1 - the node is expanded
    -        0 - the node is not expanded or function fails
    @warning
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern int cvxTreeItemIsExpand(const char *form, int field, int id);

    /**
    @ingroup zwapi_ui_treeview

    Set expand status of specified tree node.

    @param [in] form form name
    @param [in] field field number
    @param [in] id tree node id
    @param [in] option status (1 to expand, 2 to collapse, 3 to toggle)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FORM_EXIST_ERROR
    -        ZW_API_INVALID_INPUT
    */
    extern evxErrors cvxTreeExpandItem(const char *form, int field, int id, int option);


/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_TREE_VIEW_H */
