/*
 * Persistence Library / Graphics / TCanvas
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

#ifndef TCANVAS___H
#define TCANVAS___H

#include "TAlign.h"
#include "TColorRGB.h"
#include "TFont.h"
#include "TGraphicsData.h"
#include "TPosition.h"
#include "TRectangle.h"
#include "TVerticalAlign.h"
#include "TFilter3x3.h"
#include "TFilter5x5.h"
#include "TFilter7x7.h"
#include "TColorRGB.h"

typedef union
{
	struct
	{
		unsigned short Fractional;
		unsigned short Integral;
	} Part;
	unsigned long Value;
} TScaledCoordinate;

typedef int (*FilteredPixelCallback)(short x, short y, TColorRGB color);

class TCanvas
{
private:
    TGraphicsData* m_graphicsData;
    TColorRGB      m_backgroundColor;
    TColorRGB      m_foregroundColor;
    bool           m_blending;    

public:
    TCanvas(TGraphicsData* vram);
	virtual ~TCanvas();

	static int FastSqrt(int x);
	
	void DrawElipse(TRectangle area, unsigned char antialiasingFactor=1);
    void DrawGradient(TRectangle area, TColorRGB topLeftColor, TColorRGB topRightColor, TColorRGB bottomLeftColor, TColorRGB bottomRightColor);
	void DrawLine(TPosition startPosition, TPosition endPosition, unsigned char startWidth, unsigned char endWidth, unsigned char antialiasFactor);
	void DrawLine(TPosition startPosition, TPosition endPosition, unsigned char startWidth, unsigned char endWidth, unsigned char antialiasFactor, TPosition* previousPoint, TPosition* nextPoint);
	void DrawPolyLine(TPosition* positionArray, short positionArrayLength, unsigned char width, unsigned char antialiasFactor);
	void DrawRectangle(TRectangle rectangle);
	void DrawRoundedRectangle(TRectangle rectangle, short radius, unsigned char antialiasingFactor );
    void DrawCharacter (TFontCharacter character, TPosition position);
    void DrawCharacterVertical (TFontCharacter character, TPosition position, bool directionUp);
	void DrawText(TFont font, const char* text, TPosition position);
	void DrawText(TFont font, const char* text, TRectangle area, TAlign horizontalAlign, TVerticalAlign verticalAlign);
	void DrawTextVertical(TFont font, const char* text, TPosition position, bool directionUp=false);
	void DrawTextVertical(TFont font, const char* text, TRectangle area, TAlign horizontalAlign, TVerticalAlign verticalAlign, bool directionUp=false);
	void DrawImage(TPosition targetPosition, TGraphicsData* image, TRectangle* imageRectangle=NULL);
	void DrawMaskedImage(TPosition targetPosition, TGraphicsData* image, TRectangle* imageRectangle=NULL, TColorRGB maskColor=TColorRGB(255,0,255));
	void DrawTiledImage(TRectangle targetArea, TGraphicsData* image, TRectangle* imageRectangle=NULL);    
	void DrawScaledImage(TRectangle targetArea, TGraphicsData* image, TRectangle* imageRectangle=NULL);
	void SetForegroundColor(TColorRGB foregroundColor);
	void SetBackgroundColor(TColorRGB backgroundColor);
    void SetPixelColor(short x, short y, TColorRGB color);
    void SetPixelColorIndex(short x, short y, unsigned char colorIndex);

	TColorRGB GetForegroundColor();
    TColorRGB GetBackgroundColor();
    TColorRGB GetPixelColor(short x, short y);
    unsigned char GetPixelColorIndex(short x, short y);

	bool ApplyFilter(TFilter3x3* filter, FilteredPixelCallback callback);
	bool ApplyFilter(TFilter5x5* filter, FilteredPixelCallback callback);
	bool ApplyFilter(TFilter7x7* filter, FilteredPixelCallback callback);

private:
	TGraphicsData* m_vram;

};

#endif
