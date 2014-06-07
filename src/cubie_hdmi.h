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

typedef struct _cubie_hdmi{
	fb_videomodeptr prefered;
} cubie_hdmirec, *cubie_hdmiptr;

#endif
