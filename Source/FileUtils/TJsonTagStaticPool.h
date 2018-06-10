/*
 * Persistence Library / Basic types / TXMLTagBasePool 
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

#ifndef TJSONSTATICPOOL___H
#define TJSONSTATICPOOL___H

#include <stdlib.h>
#include "tjsontag.h"
#include "TJsonTagBasePool.h"

class TJsonTagStaticPool : public TJsonTagBasePool
{
protected:        
    virtual TJsonTag*       GetJsonTag(short i) = 0;
    virtual unsigned short  GetJsonTagCount() = 0;        

public:
    virtual TJsonTag*       CreateJsonTag() = 0;
    virtual bool            DeleteJsonTag(TJsonTag* tag) = 0;
    virtual void            Clear() = 0;

};




#endif