    /*
     * Copyright (C) 1994-2003 The XFree86 Project, Inc.  All Rights Reserved.
     *
     * Permission is hereby granted, free of charge, to any person obtaining a copy
     * of this software and associated documentation files (the "Software"), to deal
     * in the Software without restriction, including without limitation the rights
     * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
     * copies of the Software, and to permit persons to whom the Software is fur-
     * nished to do so, subject to the following conditions:
     *
     * The above copyright notice and this permission notice shall be included in
     * all copies or substantial portions of the Software.
     *
     * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
     * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FIT-
     * NESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
     * XFREE86 PROJECT BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
     * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CON-
     * NECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
     *
     * Except as contained in this notice, the name of the XFree86 Project shall not
     * be used in advertising or otherwise to promote the sale, use or other deal-
     * ings in this Software without prior written authorization from the XFree86
     * Project.
     */

    /*
     * Authors: Wilhelm Viktor , <wilhelm@cubietech.com>
     */

    #ifdef HAVE_CONFIG_H
    #include "config.h"
    #endif

    #include <string.h>

    /* all driver need this */
    #include "xf86_OSproc.h"

    #include "mipointer.h"
    #include "micmap.h"
    #include "colormapst.h"
    #include "xf86cmap.h"
    #include "shadow.h"
    #include "dgaproc.h"


    #include "xorg-server.h"
    #include "xf86.h"
    #include "xf86cmap.h"
    #include <xf86drm.h>
    #include "xf86xv.h"
    #include "xf86Crtc.h"


    /* for visuals */
    #include "fb.h"

    #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 6
    #include "xf86Resources.h"
    #include "xf86RAC.h"
    #endif

    #include "fbdevhw.h"

    #include "xf86xv.h"
    #include "compat-api.h"
    #ifdef XSERVER_LIBPCIACCESS
    #include <pciaccess.h>
    #endif

    #include <linux/fb.h>
    #include "cubie_hdmi.h"
    #include "drv_display.h"
#if 1
    /* i2c tools add by Wilhelm Viktor*/
    #include <errno.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <linux/i2c-dev.h>
    #include <fcntl.h>
    #include <xf86DDC.h>
    #include <sys/ioctl.h>
#endif

#define IGNORE(x) (x=x)
static void fbdev_hdmi_crtc_dpms(xf86CrtcPtr crtc, int mode)
{
    IGNORE(crtc);
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    IGNORE(mode);
}

static Bool fbdev_hdmi_crtc_lock(xf86CrtcPtr crtc)
{
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    IGNORE( crtc );

    return TRUE;
}

static void fbdev_hdmi_crtc_unlock(xf86CrtcPtr crtc)
{
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    IGNORE( crtc );
}

static Bool fbdev_hdmi_crtc_mode_fixup(xf86CrtcPtr crtc, DisplayModePtr mode, DisplayModePtr adjusted_mode)
{
    IGNORE( crtc );
    IGNORE( mode );
    IGNORE( adjusted_mode );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);

    return TRUE;
}

static void fbdev_hdmi_crtc_prepare(xf86CrtcPtr crtc)
{
    IGNORE( crtc );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static void fbdev_hdmi_crtc_mode_set(xf86CrtcPtr crtc, DisplayModePtr mode, DisplayModePtr adjusted_mode, int x, int y)
{
    IGNORE( crtc );
    IGNORE( mode );
    IGNORE( adjusted_mode );
    IGNORE( x );
    IGNORE( y );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static void fbdev_hdmi_crtc_commit(xf86CrtcPtr crtc)
{
    IGNORE( crtc );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static void fbdev_hdmi_crtc_gamma_set(xf86CrtcPtr crtc, CARD16 *red, CARD16 *green, CARD16 *blue, int size)
{
    IGNORE( crtc );
    IGNORE( red );
    IGNORE( green );
    IGNORE( blue );
    IGNORE( size );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static void fbdev_hdmi_crtc_set_origin(xf86CrtcPtr crtc, int x, int y)
{
    IGNORE( crtc );
    IGNORE( x );
    IGNORE( y );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static const xf86CrtcFuncsRec fbdev_hdmi_crtc_funcs =
{
    .dpms = fbdev_hdmi_crtc_dpms,
    .save = NULL,
    .restore = NULL,
    .lock = fbdev_hdmi_crtc_lock,
    .unlock = fbdev_hdmi_crtc_unlock,
    .mode_fixup = fbdev_hdmi_crtc_mode_fixup,
    .prepare = fbdev_hdmi_crtc_prepare,
    .mode_set = fbdev_hdmi_crtc_mode_set,
    .commit = fbdev_hdmi_crtc_commit,
    .gamma_set = fbdev_hdmi_crtc_gamma_set,
    .shadow_allocate = NULL,
    .shadow_create = NULL,
    .shadow_destroy = NULL,
    .set_cursor_colors = NULL,
    .set_cursor_position = NULL,
    .show_cursor = NULL,
    .hide_cursor = NULL,
    .load_cursor_image = NULL,
    .load_cursor_argb = NULL,
    .destroy = NULL,
    .set_mode_major = NULL,
    .set_origin = fbdev_hdmi_crtc_set_origin,
};

static void fbdev_hdmi_output_dpms(xf86OutputPtr output, int mode)
{
//    MaliPtr fPtr = MALIPTR(output->scrn);
//
//    if ( mode == DPMSModeOn )
//    {
//        ioctl(fPtr->fb_hdmi_fd, FBIOBLANK, FB_BLANK_UNBLANK);
//    }
//    else if( mode == DPMSModeOff )
//    {
//        ioctl(fPtr->fb_hdmi_fd, FBIOBLANK, FB_BLANK_POWERDOWN);
//    }
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static void fbdev_hdmi_output_save(xf86OutputPtr output)
{
    IGNORE( output );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static void fbdev_hdmi_output_restore(xf86OutputPtr output)
{
    IGNORE( output );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

struct cubie_resolution_support {
	int	HDisplay;
	int	VDisplay;
};
static struct cubie_resolution_support cubie_resolution_support_list[10]={
	{720,240},
	{720,288},
	{720,480},
	{720,576},
	{1280,720},
	{1920,540},
	{1920,1080},
	{1920,2160},
	{1280,1440},
	{3840,2160},
};

static int fbdev_hdmi_output_mode_valid(xf86OutputPtr output, DisplayModePtr pMode)
{
    /* TODO: return MODE_ERROR in case of unsupported mode */
    int i;
    IGNORE( output );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    for(i=0;i<10;i++){
	if((cubie_resolution_support_list[i].HDisplay == pMode->HDisplay)
	&& (cubie_resolution_support_list[i].VDisplay == pMode->VDisplay)){
	return MODE_OK;
	}
    }
    xf86DrvMsg(0, X_INFO, "Mode %i x %i unvalid\n", pMode->HDisplay, pMode->VDisplay );
    return -1;
}

static Bool fbdev_hdmi_output_mode_fixup(xf86OutputPtr output, DisplayModePtr mode, DisplayModePtr adjusted_mode)
{
    IGNORE( output );
    IGNORE( mode );
    IGNORE( adjusted_mode );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);

    return TRUE;
}

static void fbdev_hdmi_output_prepare(xf86OutputPtr output)
{
    IGNORE( output );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static void fbdev_hdmi_output_commit(xf86OutputPtr output)
{
    output->funcs->dpms(output, DPMSModeOn);
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
}

static void fbdev_hdmi_output_mode_set(xf86OutputPtr output, DisplayModePtr mode, DisplayModePtr adjusted_mode)
{
}

static xf86OutputStatus fbdev_hdmi_output_detect(xf86OutputPtr output)
{
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    IGNORE( output );

    return XF86OutputStatusConnected;
}

DisplayModePtr fbdev_make_mode( int xres, int yres, DisplayModePtr prev )
{
    DisplayModePtr mode_ptr;
    unsigned int hactive_s = xres;
    unsigned int vactive_s = yres;

    mode_ptr = xnfcalloc(1, sizeof(DisplayModeRec));



    mode_ptr->type = M_T_DRIVER;
    mode_ptr->name = "1024x600";

   // xf86SetModeDefaultName(mode_ptr);
        
    mode_ptr->next = NULL;
    mode_ptr->prev = prev;

    return mode_ptr;
}
/*
static inline void
convert_to_video_timing(struct fb_videomode *timing,
            struct drm_display_mode *mode)
{
    DRM_DEBUG_KMS("%s\n", __FILE__);

    memset(timing, 0, sizeof(*timing));

    timing->pixclock = mode->clock * 1000;
    timing->refresh = drm_mode_vrefresh(mode);

    timing->xres = mode->hdisplay;
    timing->right_margin = mode->hsync_start - mode->hdisplay;
    timing->hsync_len = mode->hsync_end - mode->hsync_start;
    timing->left_margin = mode->htotal - mode->hsync_end;

    timing->yres = mode->vdisplay;
    timing->lower_margin = mode->vsync_start - mode->vdisplay;
    timing->vsync_len = mode->vsync_end - mode->vsync_start;
    timing->upper_margin = mode->vtotal - mode->vsync_end;

    if (mode->flags & DRM_MODE_FLAG_INTERLACE)
        timing->vmode = FB_VMODE_INTERLACED;
    else
        timing->vmode = FB_VMODE_NONINTERLACED;

    if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
        timing->vmode |= FB_VMODE_DOUBLE;
}
*/
static DisplayModePtr
convert_to_video_timing(fb_videomodeptr timing)
{
	DisplayModePtr mode;
    mode = xnfcalloc(1, sizeof(DisplayModeRec));
    memset(mode, 0, sizeof(DisplayModeRec));

    mode->Clock		= timing->pixclock / 1000;
    mode->VRefresh	= timing->refresh;

    mode->HDisplay	= timing->xres;
    mode->HSyncStart	= timing->xres + timing->right_margin;
    mode->HSyncEnd	= mode->HSyncStart + timing->hsync_len;
    mode->HTotal	= mode->HSyncEnd + timing->left_margin;

    mode->VDisplay	= timing->yres;
    mode->VSyncStart	= timing->yres + timing->lower_margin;
    mode->VSyncEnd	= mode->VSyncStart + timing->vsync_len;
    mode->VTotal	= mode->VSyncEnd + timing->upper_margin;

    mode->type		= M_T_DRIVER;
    xf86SetModeDefaultName(mode);
    xf86DrvMsg(0, X_INFO, "%s VRefresh %f clock %d %d\n",mode->name,mode->VRefresh,mode->Clock,__LINE__);
    return mode;
}

static void          
fbdev2xfree_timing(struct fb_var_screeninfo *var, DisplayModePtr mode)                                                                      
{
    mode->Clock = var->pixclock ? 1000000000 / var->pixclock : 0;                                                                           
    mode->HDisplay = var->xres;
    mode->HSyncStart = mode->HDisplay + var->right_margin;
    mode->HSyncEnd = mode->HSyncStart + var->hsync_len;
    mode->HTotal = mode->HSyncEnd + var->left_margin;
    mode->VDisplay = var->yres;
    mode->VSyncStart = mode->VDisplay + var->lower_margin;
    mode->VSyncEnd = mode->VSyncStart + var->vsync_len;
    mode->VTotal = mode->VSyncEnd + var->upper_margin;                                                                                      
    mode->Flags = 0; 
    mode->Flags |= var->sync & FB_SYNC_HOR_HIGH_ACT ? V_PHSYNC : V_NHSYNC;
    mode->Flags |= var->sync & FB_SYNC_VERT_HIGH_ACT ? V_PVSYNC : V_NVSYNC;
    mode->Flags |= var->sync & FB_SYNC_COMP_HIGH_ACT ? V_PCSYNC : V_NCSYNC;                                                                 
    if (var->sync & FB_SYNC_BROADCAST)
        mode->Flags |= V_BCAST;
    if ((var->vmode & FB_VMODE_MASK) == FB_VMODE_INTERLACED)
        mode->Flags |= V_INTERLACE;
    else if ((var->vmode & FB_VMODE_MASK) == FB_VMODE_DOUBLE)                                                                               
        mode->Flags |= V_DBLSCAN;
    mode->SynthClock = mode->Clock;
    mode->CrtcHDisplay = mode->HDisplay;
    mode->CrtcHSyncStart = mode->HSyncStart;
    mode->CrtcHSyncEnd = mode->HSyncEnd;
    mode->CrtcHTotal = mode->HTotal;
    mode->CrtcVDisplay = mode->VDisplay;
    mode->CrtcVSyncStart = mode->VSyncStart;
    mode->CrtcVSyncEnd = mode->VSyncEnd;
    mode->CrtcVTotal = mode->VTotal;
    mode->CrtcHAdjusted = FALSE;
    mode->CrtcVAdjusted = FALSE;                                                                                                            
}
static DisplayModePtr
fb2mode(fb_videomodeptr fb_videomode, int size)
{
	DisplayModePtr displaymode = NULL , Mode = NULL;

    for (i = 0; i < size; i++,fb_videomode++) {
        DisplayModePtr Mode;

        Mode = calloc(1, sizeof(DisplayModeRec));
        if (Mode) {
			fbdev2xfree_timing(fb_videomode , Mode);
			Modes = xf86ModesAdd(Modes, Mode);
        }
		if(!displaymode)
			displaymode = Modes;
    }
	return displaymode;
}

static char edid_array[1024];
static char *edid_data = edid_array;
static DisplayModePtr fbdev_hdmi_output_get_modes(xf86OutputPtr output)
{
    DisplayModePtr mode_ptr;
    DisplayModePtr Modes = NULL, Last = NULL;
    ScrnInfoPtr pScrn = output->scrn;
    FBDevPtr fbdevptr = FBDEVPTR(pScrn);
	int file,size,i;
	void *private_data = xnfcalloc(1, 18 * sizeof(fb_videomode));
	unsigned long arg[4];


    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
	file = open("/dev/disp",O_RDWR);
	if(file < 0){
		xf86DrvMsg(0, X_INFO, "%s %s fb0 open failed! %d\n",__FILE__,__func__,__LINE__);
	}

	memset(edid_data,0,1024);
	arg[0] = 1;
	arg[1] =(unsigned long *) edid_data;
	size = ioctl(file,DISP_CMD_HDMI_GET_EDID,arg);

	if(size < 0 ){
		xf86DrvMsg(0, X_INFO, "%s %s DISP_CMD_HDMI_GET_EDID err!%d\n",__FILE__,__func__,__LINE__);
	}

	memset(private_data,0,1024);
	arg[0] = 1;
	arg[1] =(unsigned long *) private_data;
	size = ioctl(file,DISP_CMD_HDMI_GET_VIDEOMODE_LIST,arg);

	if(size <= 0 || size > 18){
		xf86DrvMsg(0, X_INFO, "%s %s size err!%d\n",__FILE__,__func__,__LINE__);
	}

    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);

    xf86MonPtr mon = NULL;
    mon = xf86InterpretEDID(pScrn->scrnIndex,edid_data);
    if(mon){
	mon->flags |= MONITOR_EDID_COMPLETE_RAWDATA;
	xf86OutputSetEDID(output, mon);
    }else{
	xf86DrvMsg(0, X_INFO, "%s %s xf86InterpretEDID err %d\n",__FILE__,__func__,__LINE__);
    }

	mode_ptr = fb2mode((fb_videomodeptr)private_data , size);
 /*
    mode_ptr = xf86OutputGetEDIDModes(output);
    Last     =  mode_ptr;
while(Last){
    xf86DrvMsg(0, X_INFO, "%s HD %d VD %d %d\n",
	Last->name,Last->HDisplay,Last->VDisplay,__LINE__);
    xf86SetModeCrtc(Last,pScrn->adjustFlags);
	if(fbdevptr->max_displayX < Last->HDisplay)
		fbdevptr->max_displayX = Last->HDisplay;
	if(fbdevptr->max_displayY < Last->VDisplay)
		fbdevptr->max_displayY = Last->VDisplay;
	if(pScrn->virtualX<Last->HDisplay)
		pScrn->virtualX = Last->HDisplay;
	if(pScrn->virtualY<Last->VDisplay)
		pScrn->virtualY = Last->VDisplay;
	xf86DrvMsg(0, X_INFO, "MAXX %d MAXY %d HD %d VD %d\n",fbdevptr->max_displayX,fbdevptr->max_displayY,Last->HDisplay,Last->VDisplay);

    if(Last->next)
	Last = Last->next;
     else
	break;

    if(Last == mode_ptr)
	break;
}
*/
	
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
return mode_ptr;
 
}


#ifdef RANDR_GET_CRTC_INTERFACE
static xf86CrtcPtr fbdev_hdmi_output_get_crtc(xf86OutputPtr output)
{
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    return output->crtc;
}
#endif

static void fbdev_hdmi_output_destroy(xf86OutputPtr output)
{
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    IGNORE( output );
}

static const xf86OutputFuncsRec fbdev_hdmi_output_funcs =
{
    .create_resources = NULL,
    .dpms = fbdev_hdmi_output_dpms,
    .save = fbdev_hdmi_output_save,
    .restore = fbdev_hdmi_output_restore,
    .mode_valid = fbdev_hdmi_output_mode_valid,
    .mode_fixup = fbdev_hdmi_output_mode_fixup,
    .prepare = fbdev_hdmi_output_prepare,
    .commit = fbdev_hdmi_output_commit,
    .mode_set = fbdev_hdmi_output_mode_set,
    .detect = fbdev_hdmi_output_detect,
    .get_modes = fbdev_hdmi_output_get_modes,
#ifdef RANDR_12_INTERFACE
    .set_property = NULL,
#endif
#ifdef RANDR_13_INTERFACE
    .get_property = NULL,
#endif
#ifdef RANDR_GET_CRTC_INTERFACE
    .get_crtc = fbdev_hdmi_output_get_crtc,
#endif
    .destroy = fbdev_hdmi_output_destroy,
};

Bool FBDEV_hdmi_init(ScrnInfoPtr pScrn)
{
    xf86CrtcPtr crtc;
    xf86OutputPtr output;

    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    crtc = xf86CrtcCreate(pScrn, &fbdev_hdmi_crtc_funcs);

    if(crtc == NULL) return FALSE;

    output = xf86OutputCreate(pScrn, &fbdev_hdmi_output_funcs, "HDMI");

    if(output == NULL) return FALSE;

    output->possible_crtcs = (1 << 0);

    return TRUE;
}


