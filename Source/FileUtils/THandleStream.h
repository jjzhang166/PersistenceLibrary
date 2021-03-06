/*
 * Persistence Library / FileUtils / THandleStream
 *
 * Copyright (c) 2016-2018 Ondrej Sterba <osterba@atlas.cz>
 *
 * https://github.com/embedded-tools/PersistenceLibrary
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 */

#ifndef THANDLESTREAM___H
#define THANDLESTREAM___H

#include <stdio.h>
#include "tstream.h"

class THandleStream:public TStream
{
private:
protected:
    FILE* m_fileHandle;
	int   m_fileSize;
    
public:
    THandleStream(void);
    THandleStream(FILE* AHandle);
    virtual ~THandleStream();

    virtual void Close();

    virtual long ReadBuffer(void* Buffer, long Count);
    virtual long WriteBuffer(void* Buffer, long Count);
	virtual long Seek(long Offset, ESeekOrigin Origin);
	virtual long GetPosition();
	virtual long GetSize();

};


#endif
