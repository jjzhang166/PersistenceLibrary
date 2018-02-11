/*
 * Persistence Library / Graphics / TCachedWindowsBmpFile
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

#ifndef TCACHEDWINDOWSBMPFILE___H
#define TCACHEDWINDOWSBMPFILE___H

#include "TGraphicsData.h"
#include <stdlib.h>

class TCachedWindowsBmpFile : public TGraphicsData
{

public:
	TCachedWindowsBmpFile(const char* filename);
	virtual ~TCachedWindowsBmpFile();

	unsigned char* ScanLine(short line);

};

#endif
