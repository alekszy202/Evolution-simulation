#pragma once

/*
Struct holding log information.
@struct logPart Log information.
@param no Generation's number.
@param elements Number of elements.
@param died Number of dead individuals.
@param alive Number of alive invdiiduals.
@param cloned Number of cloned invdiiduals.
*/
struct logPart {
	//Generation's number.
	int no;
	//Number of elements.
	int elements;
	//Number of dead individuals.
	int died;
	//Number of alive invdiiduals.
	int alive;
	//Number of cloned individuals.
	int cloned;
};

//File reading defines.
#define FILE_CORRECT			0
#define FILE_DOES_NOT_EXIST		1
#define FILE_EMPTY				2
#define FILE_BAD_FORMAT			3