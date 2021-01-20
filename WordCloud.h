/** WordCloud.h
 * ===========================================================
 * Name: CS220, Spring 2021
 *
 * Purpose:  Produces a word cloud given a word list and their
 * 			 frequency.
 * ===========================================================*/

#ifndef WORDCLOUD_H
#define WORDCLOUD_H

#include "PEX1.h"

/**
 * @brief Build the word cloud.
 * @param argWordCounts - parallel array with frequency of words
 * @param argWords  - parallel array with word list
 * @param argFileName - html file to output word cloud to
 * @return returns 1 on success and 0 on failure
 * @pre argWordCount points to array of WordCount values of size argNumWords
 * @post the file named argFileName will be appended to
 */
int BuildWordCloud(WordCount* argWordCount, STRING argFileName, int argNumWords);


#endif // WORDCLOUD_H