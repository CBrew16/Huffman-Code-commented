#define MAX 256
#ifndef CAMO_H
#define CAMO_H

#endif //CAMO_H
//
// Created by Cameron Brewster on 2024-11-20.


/*****************************************************************************
**
* Filename: priority_queue.c
* Author: Cameron Brewster
* Student ID: 251 337 087
* Version: 3
* Date Created: Nov 20th
* Last Modified: Nov 29th
*
* Description:
* - This C file implements a Huffman tree for compressing and decompressing a text file.
* - It builds a huffman tree based on the frequency of characters that appear in the text file and their associated huffman codes by traversing the tree
* - It then decompresses the encoded text file to its original format by re-traversing the Huffman Tree
*
*
* Dependencies:
*#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "compress_and_decompress.h"
#include <string.h>
*
*
* Compilation:
* gcc compress_and_decompress.c priority_queue.c ptest.c write_to_files.c -o 1
* ./1 <FileName.txt> <CompressedFileName.huf>
*****************************************************************************/

/*
 * File name: compress_and_decompress.h
 * Author: Cameron Brewster
 * Student ID: 251 337 087
 * Version 3
 * Date Created: Nov 20th
 * Last modified: Nov 29th
 *
 * Description:
 * This .h file defines the structure and function for the bulding of a huffman tree while implementing created priortity queue functions.
 * Additionally, it deals with compressing a text file using a huffman tree (encoding) and decompressing (decoding) a compressed string with a huffman tree

 *Dependencies: The text file traversal and priority queue implementations done by the priority_queue.h
 * "priority_queue.h"
 * Compilation: gcc compress_and_decompress.c priority_queue.c ptest.c write_to_files.c -o 1
 * ./1 <FileName.txt> <CompressedFileName.huf>
*****************************************************************************/

/*****************************************************************************
**
*/

#include "priority_queue.h"

// Create a Tree data structure for the Huffman Nodes




/*****************************************************************************
**
* Function: createLeafNode
*
* Purpose:
* Allocated memory for a leaf node in the huffman tree and initializes its structure
* The leaf node holds a character and its frequency
* This function is specifically used to create a leaf node
*
* Parameters:
* char data - a character to be added to the leaf node in the tree
* int frequency - An integer to hold the frequency associated with that character
* Returns:
* HuffmanNode* - a pointer to the newly created leaf node to be implemented into the tree
*
* Errors:
* - If memory allocation fails returns NULL
*
* Notes:
* - This function is intended to allocate memory for a leaf node. This is specific as only leaf nodes in the huffman tree have a character stored
* - It initializes the Huffman node structure for a leaf node. Also setting left and right pointers to Null

*****************************************************************************/
HuffmanNode *createLeafNode(char data, int frequency);

/*****************************************************************************
**
* Function: createInternalNodes
*
* Purpose:
* Allocates memory for a new internal node in the Huffman tree and initializes its structure:
* Left and Right pointers are initialized to its children
* The data is initialized to NULL character
* The frequency is initialized to the sum of left child + right child's frequency
* This function is used to create internal nodes that can be implemented into the tree structure
*
* Parameters:
* HuffmanNode* left - A pointer to the left child node, which is either a leaf node or another internal node.
* HuffmanNode* right - A pointer to the right child node, which is either a leaf node or another internal node.
*
* Returns:
* HuffmanNode* - A pointer to the newly created internal node to be implemented as an internal node in the tree
*
* Errors:
* - If memory allocation fails it returns a print statement and exits

* Notes:
* - Internal nodes are only used to connect the tree's strucutre
* - Internal nodes hold the sum of the frequencies of each of their child nodes (left + right)
* - Internal nodes do not hold a character; The data (character) is set to NULL
* - Left child or right child can be an internal node or leaf node
*
*****************************************************************************/

HuffmanNode *createInternalNodes(HuffmanNode* left, HuffmanNode *right);


/*****************************************************************************
**
* Function: buildHuffmanTree
*
* Purpose:
* - To build the huffman tree from the bottom up
*
* Method:
* The first two nodes with the smallest frequencies are dequeued from the priority queue.
* These two nodes are leaf nodes (representing characters and their frequencies).
* A new internal node is created with the two dequeued nodes as its left and right children.
* The newly created internal node (parent of the two leaf nodes) is re-queued back into the priority queue
* This process continues until only one node remains in the queue, which becomes the root node
*
* Parameters:
* Queue* queue - A pointer to a priority queue of Huffman nodes. (Sorted from lowest frequency to highest)
*
*
* Returns:
* HuffmanNode* - A pointer to the root node of the Huffman tree (last remaining node in the queue)
*
* Errors:
* - N/A
*
* Notes:
* - The priority queue is expected to order the nodes by frequency, with the node having the smallest frequency
*   at the front.
* - This process builds the binary tree where leaf nodes represent characters, and internal nodes represent
*   merged nodes with combined frequencies.
*   The re-queueing of internal nodes is essential as it connects the tree to other internal nodes or leaf nodes based on sorted queue
*   Finally, the root note is what connects the left and right subtrees at the end of the queue
*
*****************************************************************************/

HuffmanNode* buildHuffmanTree(Queue* queue);


/*****************************************************************************
 * Function: getCode
 *
 * Purpose:
 *   This function recursively traverses a Huffman tree and generates unique Huffman codes for each leaf node
 *   It appends 0 or 1 to the string of codes based on the traversal direction
 *   Helper function for HuffmanCodes function
 *
 *
 * Parameters:
 *   HuffmanNode *root - Pointer to the root of the huffman tree
 *   char codes[256][MAX] - A 2D array where the 256 represents the ASCII value of a character and the max represents the traversal code to that character based on the huffman tree
 *   char *currentCode - A string that gets 0s or 1s appended to it depending on the direction traversed - For a character
 *   int depth - Tracks the current depth in the tree to append the next character
 *
 *
 * Process:
 * -
 * - If the code traverses left - Append 1 to the currentCode string
 * NOTE: Our code was printing opposite so we has to change traversing left to append 1 although its supposed to be 0
 * - If the code traverses right - Append 0 to the currentCode string

 * Returns: Void
 *

 * Errors:
 *   - If the `root` is NULL, the function simply returns without making any changes.

 *
 * Notes:
 * - This function uses recursion to traverse the Huffman tree.
 * - It should append '0' for left traversal and '1' for right traversal but in this implementation, '1' is appended for left traversal and '0' for right traversal
 * - The currentCode string has a null character added at the end
 * - It is essential as it develops a Unique binary tree traversal for each character (In the form of 1's and 0's)
 * - This function populates the codes string which is reaccessed by the compress function to finalize the compressed output string
 * - It associates a certain string of (0s and 1s) defined by the tree traversal for a certain ASCII character and puts that in the 2D array 'codes'
 *****************************************************************************/
void getCode(HuffmanNode *root, char codes[256][MAX], char* currentCode, int depth);

/*****************************************************************************
**
* Function: HuffmanCodes
*
* Purpose:
* This function generates the Huffman codes for all characters in the Huffman tree.
* It handles the edge case where the tree only has one node
* Implements the getCode function to generate codes
* Initializes the codes array to be used in the getCode function
*
* Parameters:
* - HuffmanNode *root: A pointer to the root of the Huffman tree.
* -char codes[256][MAX] - A 2D array where the 256 represents the ASCII value of a character and the max represents the traversal code to that character based on the huffman tree
*
* Returns:
* - void
*
* Errors:
*   - N/A: The function assumes the `root` is valid and points to a valid Huffman tree.
*   - If the `root` is NULL, no operation is performed.
*
* Notes:
*   - This function handles the edge case where the tree contains only a single character and assigns 0 to the character
*   - Else, it calls the getCode function to generate the codes.
*   - The codes array is updated by calling getCodes function
*
*****************************************************************************/

void HuffmanCodes(HuffmanNode *root, char codes[256][MAX]);
/*****************************************************************************
**
* Function: freeHuffmanTree
*
* Purpose:
* This function recursively frees every node in the Huffman Tree
*
* Parameters:
* - HuffmanNode* root: A pointer to the root node of the Huffman tree.
*
*
* Returns:
*   - void
*
* Errors:
*   - N/A
*
* Notes:
*   - Recursively calls the left and right subtrees to free each node
*    - It first frees the left and right subtrees, and then frees the root
*  - Edge case if there's no tree to free; Returns immediately
*
*****************************************************************************/

void freeHuffmanTree(HuffmanNode* root);

/*****************************************************************************
**
* Function: compress
*
* Purpose:
* This function compresses the input file by encoding each character in the file
* This function reads from the file and then looks up the ASCII value of that character in the codes 2D array and finds the encoded string associated with it

* Parameters:
*   - const char *filename: The name of the file to be compressed.
*   - char *compressed: A pointer to the array where the encoded string is stored
*   - HuffmanNode *root: The root node of the Huffman tree.
*   -char codes[256][MAX] - A 2D array where the 256 represents the ASCII value of a character and the max represents the traversal code to that character based on the huffman tree,
*
*
* Returns:
*   - void
*
* Errors:
*   - If the file cannot be opened (DNE or can't be found) the function prints an error message and exits
*
* Notes:
*   -The function reads the input file character by character using fgetc()
*   - It only accessing a pre-populated 2D array (codes) to see the code associated with each character read
*   - This is essential as it reads a character and then appends that code so a string. This makes sure it follows the order of the file
*   - At the end of the file it adds a NULL character to end the compressed string '\0'
*   - The file is closed at the end of the function
*
*****************************************************************************/

void compress(const char *filename, char *compressed, HuffmanNode *root, char codes[256][MAX]);


/*****************************************************************************
**
* Function: decompress
*
* Purpose:
*   This function decompresses a previously compressed string using the Huffman tree.
*   It traverses the encoded string and decodes it by traversing down  the Huffman tree
*   Moves left or right depending on 0 or 1 until it reaches a leaf node
* Once a leaf node is reached, it is appended to the decompressed string
*
* Parameters:
* - const char *compressed: Pointer to the encoded string
* - char *decompressed: A pointer to the decompressed array of characters
*   - HuffmanNode *root: Pointer to the root node of the Huffman Tree
*
* Returns:
*   - void
*
* Errors:
*   - If root is NULL (Tree DNE) the function prints an error message and exits.
*   - If an invalid character (not 0 or 1) is encountered in the compressed data, the function prints an error message and exits.
*
* Notes:
*  - The function works by traversing the compressed binary one character at a time
*  **Note : As mentioned before our output was backwards. So instead were traversing left if a 1 is read and traversing right if a 0 is read
*  We understand this is opposite of how the huffman tree is supposed to be traversed (0 for left 1 for right) however it was essential for us to generate the proper output
*  - After reaching a leaf, the function resets to the root of the tree to decode the next character.
*  - The decompressed string is null-terminated at the end to mark the end of the string.
*
*****************************************************************************/
void decompress(const char *compressed, char *decompressed, HuffmanNode *root);

