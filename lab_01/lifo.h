#ifndef _lifo_h
#define _lifo_h
//! \file lifo.h
//! \brief A header file that contains implementation of a LIFO queue.
//! \author Piotr Żurek
//! \date 2012

//! \struct Lifo
//! \brief A structure representing a node in LIFO queue.
//!
//! This structure represents a single node in a LIFO queue.
struct Lifo {
	const char *txt; //!< The text, that is contained by a node.
	Lifo *next; //!< A pointer to next node on a queue.
};
//! \fn init()
//! \brief Function initialising a Lifo structure.
//!
//! This is a function that initialises a Lifo structure.
//! \return A Lifo structure initialised with null text and a pointer to NULL.
Lifo* init();
//! \fn insert(Lifo* head, const char* txt)
//! \brief Function inserting text into queue.
//!
//! This function inserts a given string of characters into the LIFO queue.
//! \param head A pointer to the beginning of the LIFO queue, of type Lifo*.
//! \param txt The text, that is to be inserted to the queue, of type const char*.
void insert(Lifo* head, const char* txt);
//! \fn get(Lifo* head)
//! \brief Function taking first text from the queue.
//!
//! This function takes a string of characters from the LIFO queue.
//! \param head A pointer to the beginning of the LIFO queue, of type Lifo*.
//! \return A string of characters, of type const char*, or 0 on error.
const char* get(Lifo* head);
#endif
