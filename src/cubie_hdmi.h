#ifndef CUBIE_HDMI_H
#define CUBIE_HDMI_H
typedef struct _fb_videomode {
    const char *name;   /* optional */ 
    int refresh;        /* optional */
    int xres;
    int yres;
    int pixclock;        
    int left_margin;
    int right_margin;    
    int upper_margin;    
    int lower_margin;    
    int hsync_len;       
    int vsync_len;       
    int sync;
    int vmode;
    int flag;
} fb_videomode, *fb_videomodeptr;

/* -------------------------------------------------------------------- */
/* our private data, and two functions to allocate/free this            */

typedef struct {
        unsigned char*                  fbstart;
        unsigned char*                  fbmem;
        int                             fboff;
        int                             lineLength;
        int                             rotate;
        Bool                            shadowFB;
        void                            *shadow;
        CloseScreenProcPtr              CloseScreen;
        CreateScreenResourcesProcPtr    CreateScreenResources;
        void                            (*PointerMoved)(SCRN_ARG_TYPE arg, int x
, int y);
        EntityInfoPtr                   pEnt;
        /* DGA info */
        DGAModePtr                      pDGAMode;
        int                             nDGAMode;
        OptionInfoPtr                   Options;

	/*add by Wilhelm*/
	int				max_displayX;
	int				max_displayY;
	struct udev_monitor *uevent_monitor;
	pointer			uevent_handler
} FBDevRec, *FBDevPtr;
#define FBDEVPTR(p) ((FBDevPtr)((p)->driverPrivate))
#endif
