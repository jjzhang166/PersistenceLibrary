/*
 * Persistence Library / Persistence / TXMLParserInterface
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

#ifndef TXMLPARSERINTERFACE___H
#define TXMLPARSERINTERFACE___H

#include "TXMLTalkerInterface.h"

class TXMLParserInterface
{
	public:
		virtual bool Parse (const char* partialXml, int partialXmlLength) = 0;
		virtual void SetTalker(TXMLTalkerInterface* pTalker) = 0;
		virtual TXMLTalkerInterface* GetTalker() = 0;

};



#endif
