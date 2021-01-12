#ifndef __WORKSPACE_WM_WPXIMAP__
#define __WORKSPACE_WM_WPXIMAP__

#include "wscreen.h"
#include "drawing.h"

/* system images */
#define WSIReturnArrow			1
#define WSIHighlightedReturnArrow	2
#define WSIScrollerDimple		3
#define WSIArrowLeft			4
#define WSIHighlightedArrowLeft	        5
#define WSIArrowRight			6
#define WSIHighlightedArrowRight	7
#define WSIArrowUp			8
#define WSIHighlightedArrowUp		9
#define WSIArrowDown			10
#define WSIHighlightedArrowDown		11
#define WSICheckMark			12

typedef struct W_Pixmap {
  struct W_Screen *screen;
  Pixmap pixmap;
  Pixmap mask;
  unsigned short width;
  unsigned short height;
  short depth;
  short refCount;
} W_Pixmap;

/* ---[ WINGs/wpixmap.c ]------------------------------------------------- */

WMPixmap* WMRetainPixmap(WMPixmap *pixmap);

void WMReleasePixmap(WMPixmap *pixmap);

WMPixmap* WMCreatePixmap(WMScreen *scrPtr, int width, int height, int depth,
                         Bool masked);

WMPixmap* WMCreatePixmapFromXPixmaps(WMScreen *scrPtr, Pixmap pixmap,
                                     Pixmap mask, int width, int height,
                                     int depth);

WMPixmap* WMCreatePixmapFromRImage(WMScreen *scrPtr, RImage *image,
                                   int threshold);

WMPixmap* WMCreatePixmapFromXPMData(WMScreen *scrPtr, char **data);

WMSize WMGetPixmapSize(WMPixmap *pixmap);

WMPixmap* WMCreatePixmapFromFile(WMScreen *scrPtr, const char *fileName);

WMPixmap* WMCreateBlendedPixmapFromRImage(WMScreen *scrPtr, RImage *image,
                                          const RColor *color);

WMPixmap* WMCreateBlendedPixmapFromFile(WMScreen *scrPtr, const char *fileName,
                                        const RColor *color);

WMPixmap* WMCreateScaledBlendedPixmapFromFile(WMScreen *scrPtr, const char *fileName,
                                              const RColor *color,
                                              unsigned int width,
                                              unsigned int height);

void WMDrawPixmap(WMPixmap *pixmap, Drawable d, int x, int y);

Pixmap WMGetPixmapXID(WMPixmap *pixmap);

Pixmap WMGetPixmapMaskXID(WMPixmap *pixmap);

WMPixmap* WMGetSystemPixmap(WMScreen *scr, int image);

#endif