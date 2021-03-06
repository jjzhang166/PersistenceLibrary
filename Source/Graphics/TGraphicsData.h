/*
 * Persistence Library / Graphics / TGraphicsData
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

#ifndef TGRAPHICSDATA___H
#define TGRAPHICSDATA___H

#include "ePixelFormat.h"
#include "TColorRGB.h"


class TGraphicsData
{

public:
	TGraphicsData(short width, short height, ePixelFormat pixelFormat, TColorRGB backgroundColor=0);
	virtual ~TGraphicsData();

    void            Clear();

	short           GetWidth();
	short           GetHeight();
	ePixelFormat    GetPixelFormat();
	unsigned short  GetBytesPerLine();
	unsigned long   GetBytesTotal();
    short           GetBitsPerPixel();
	unsigned char*  ScanLine(short line);
    unsigned char*  CreatePalette(unsigned short colorCount);
	unsigned char*  GetPalette();
	short           GetColorCount();
	TColorRGB		GetTransparentColor();
	bool            IsTransparentColorUsed();
	void		    SetTransparentColor(TColorRGB color);
	TColorRGB       GetPixelColor(short x, short y);
    unsigned char   GetPixelColorIndex(short x, short y);
	void            SetPixelColor(short x, short y, TColorRGB color);
    void            SetPixelColorIndex(short x, short y, unsigned char colorIndex);
    TColorRGB       GetPaletteColor(unsigned char colorIndex);
    void            SetPaletteColor(unsigned char colorIndex, TColorRGB colorValue);
	void			ClearTransparentColor();

	bool LoadFromROM   (const unsigned char* image);
	bool LoadFromFile  (const char* filename);    
    bool SaveToFile    (const char* filename); 

protected:
	
	unsigned char*  m_bitmapData;
	bool            m_bitmapNeedsUnalloc;
	unsigned long   m_bitmapDataSize;
	short           m_bytesPerLine;		
	TColorRGB		m_transparentColor;
	bool            m_transparentColorUsed;
	short           m_bitmapWidth;
	short           m_bitmapHeight;
	short           m_planes;
	ePixelFormat    m_pixelFormat;
	unsigned char*  m_colorPalette;
	unsigned long   m_colorPaletteSize;    
	bool            m_colorPaletteNeedsUnalloc;
	unsigned short  m_colorCount;
	bool            m_flipImage;
	bool            m_readOnly;

};

#endif
