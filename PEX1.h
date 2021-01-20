/** PEX1.h
 * ===========================================================
 * Name: CS220, Spring 2021
 *
 * Purpose:  Code provided for PEX 1 - Debugging a word cloud
 * ===========================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define STRING char*
#define MAX_WORD_LENGTH 5
#define MAX_WORD_LENGTH_STRING "5"


typedef struct {
    STRING word;
    int count;
} WordCount;

/**
 * @brief Counts the unique words in a file
 * @param argFileName text file to count words in
 * @return number of total words in the file
 * @pre argFileName is the name of a valid text file
 * @post returns the count of words (0 if the file does not open)
 */
int CountWordsInFile(STRING argFileName);

/** 
 * @brief free the memory used to count word frequencies
 * @param argWordCount word count to be deleted
 * @pre argWordCount is a pointer to WordCount array
 * @post memory is freed; argWordCount is unchanged
 */
void DeleteWordCount(WordCount* argWordCount);

/** 
 * @brief Removes non alphas from the input word and makes it all uppercase
 * @param argWord word to convert
 * @pre argWord is a null-terminated string
 * @post argWord is altered to remove non-alpha and make all uppercase
 */
void RemovePunctuationMakeUpperCase(STRING argWord);

/** 
 * @brief Prints the words and their frequencies
 * @param argWordCounts - array of word frequencies
 * @param argWords - array of words
 * @pre  argWordCount is an array of WordCount, the last array entry is null string
 * @post console output
 */
void PrintWordsToConsole(WordCount* argWordCount);

/** 
 * @brief count the number of unique words 
 * @param argWordCounts array of word frequencies
 * @pre  argWordCount is an array of WordCount, the last array entry is null string
 * @post returns the number of unique words
 */
int NumUniqueWords(WordCount* argWordCount);

/** 
 * @brief Allocates memory for the word list array.
 * @param argNumberOfWords number of words in the file.
 * @return array of WordCounts.
 * @pre argNumberOfWords is positive value
 * @post memory is allocated [argNumberOfWords + 1] for array and all strings are set to NULL
 */
WordCount* CreateWordCountArray(int argNumberOfWords);

/** 
 * @brief Reads a file of words to exclude from the word cloud.
 * @param argFileName text file to get exclude words from
 * @return Array containing words to exclude, or NULL
 * @pre  argFileName is valid file name of text file
 * @post creates WordCount array [size + 1], last element has NULL word; or returns NULL
 */
WordCount* ReadExclusionFile(STRING argFileName);

/** 
 * @brief Reads a file of words from story to build the word cloud.
 * @param argFileName text file build word cloud from
 * @param argExclusionList WordCount array with words to exclude
 * @return Map containing words and counts from story
 * @pre  argExclusionList is an array of WordCount
 * @post returns allocated array of Word
 */
WordCount* ReadStoryFile(STRING argFileName, WordCount* argExclusionList);

/** 
 * @brief Checks if a word is already stored in an existing WordCount
 * @param argWordCount array to search in
 * @param argBuffer word to look for
 * @return bool returns true/false for word existing in argWordCount
 * @pre  argWordCount is an array of WordCount; argBuffer is null terminated string
 * @post return value
 */
bool WordExistsInWordCount(WordCount* argWordCount, STRING argBuffer);

/** 
 * @brief Updates count of unique words and adds word to array (argWordCount)
 * @param argWordCount array to search in
 * @param argBuffer word to look for
 * @pre  argWordCount is an array of WordCount; argBuffer is a null terminated string
 * @post updated argWordCount array
 */
void UpdateWordCount(WordCount* argWordCount, STRING argBuffer);

/** 
 * @brief Quicksorts the arrays
 * @param argWordCounts - array of word frequencies
 * @param argWords - array of words
 * @param argLow - low index into arrays
 * @param argHigh - high index into arrays
 * @pre  argWordCount is an array of WordCount; argLow and argHigh are values in range of array index, argHigh >= argLow
 * @post array is sorted
 */
void QuickSortWords(WordCount* argWordCount, int argLow, int argHigh);

/** 
 * @brief Partitions the arrays into upper and lower portions around a pivot
 * @param argWordCounts array of word frequencies
 * @param argWords array of words
 * @param argLow low index into arrays
 * @param argHigh high index into arrays
 * @return pivot index
 * @pre argLow and argHigh are values in range of array index, argHigh >= argLow; argWordCount is an array of WordCount
 * @post array is partitioned
 */
int QuickSortPartition(WordCount* argWordCount, int argLow, int argHigh);
