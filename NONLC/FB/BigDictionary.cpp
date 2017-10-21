/**************************************************************************
 * File Name : BigDictionary.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-10-2017
 *
 * Last Modified : Fri Oct 20 18:43:18 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
// (a) Given a big dictionary (has ~1Mwords) that has only [A-Z] and a string of characters, named “input”, onlycontains [A-Z]. find all the words that can be formed by the characters in theinput. 
// (b) the input is a list of words. Return a list of lists of words thateach list is formed by exactly the characters in the input list.  For example: two lists {“DEBIT”, “CARD”} and{“BAD”, “CREDIT”} are formed by the same exact group of characters.
// Build trie for the dictionary. Use a hashmap to store char:cnt;
