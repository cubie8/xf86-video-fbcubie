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

static int fbdev_hdmi_output_mode_valid(xf86OutputPtr output, DisplayModePtr pMode)
{
    IGNORE( output );
    IGNORE( pMode );

    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    /* TODO: return MODE_ERROR in case of unsupported mode */
    xf86DrvMsg(0, X_INFO, "Mode %i x %i valid\n", pMode->HDisplay, pMode->VDisplay );

    return MODE_OK;
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
 //   MaliPtr fPtr = MALIPTR(output->scrn);
    int file;
    fb_videomodeptr	my_fb_videomodeptr = output->driver_private;
    IGNORE( output );
    IGNORE( mode );
    IGNORE( adjusted_mode );
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    file = open("/dev/fb0",O_RDWR);

    if ( ioctl(file , FBIOPUT_VSCREENINFO, &my_fb_videomodeptr) < 0 )
    {
        xf86DrvMsg(0, X_INFO, "Unable to get VSCREENINFO\n");
    }
//    if ( ioctl( fPtr->fb_hdmi_fd, FBIOGET_VSCREENINFO, &fPtr->fb_hdmi_var ) < 0 )
//    {
//        xf86DrvMsg(0, X_INFO, "Unable to get VSCREENINFO\n");
//    }

   // fPtr->fb_hdmi_var.xres = mode->HDisplay;
  //  fPtr->fb_hdmi_var.yres = mode->VDisplay;
  //  fPtr->fb_hdmi_var.xres_virtual = mode->HDisplay;
  //  fPtr->fb_hdmi_var.yres_virtual = mode->VDisplay*2;
  //  xf86DrvMsg(0, X_INFO, "Changing mode to %i %i %i %i\n", fPtr->fb_hdmi_var.xres, fPtr->fb_hdmi_var.yres, fPtr->fb_hdmi_var.xres_virtual, fPtr->fb_hdmi_var.yres_virtual);
  //  if ( ioctl( fPtr->fb_hdmi_fd, FBIOPUT_VSCREENINFO, &fPtr->fb_hdmi_var ) < 0 )
  //  {
    //    xf86DrvMsg(0, X_INFO, "Unable to set mode!\n");
 //   }

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

static DisplayModePtr fbdev_hdmi_output_get_modes(xf86OutputPtr output)
{
    DisplayModePtr mode_ptr;
    DisplayModePtr Modes = NULL,VModes = NULL, First = NULL;
    DisplayModePtr VFirst, End, VEnd;
    ScrnInfoPtr pScrn = output->scrn;

	int file,size,i;
	void *private_data = xnfcalloc(1, 18 * sizeof(fb_videomode));
	fb_videomodeptr	mymode;
	unsigned long arg[4];

    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
	file = open("/dev/disp",O_RDWR);
	if(file < 0){
		xf86DrvMsg(0, X_INFO, "%s %s fb0 open failed! %d\n",__FILE__,__func__,__LINE__);
	}

	arg[0] = 1;
	arg[1] =(unsigned long *) private_data;
	size = ioctl(file,DISP_CMD_HDMI_GET_VIDEOMODE_LIST,arg);

	if(size <= 0 || size > 18){
		xf86DrvMsg(0, X_INFO, "%s %s size err!%d\n",__FILE__,__func__,__LINE__);
	}

    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);

/*
get edid operate because of have api get it
so I read a file to instead of the api now
*/

    int edid_file;
    edid_file = open("/edid_rawdata", O_RDWR);
    static  char data_array[256];
    static  char *data = data_array;
    memset(data,0,256);
    read(edid_file,data,128);

    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);

    xf86MonPtr mon = NULL;
    mon = xf86InterpretEDID(pScrn->scrnIndex,data);
    xf86OutputSetEDID(output, mon);

	mymode = private_data;
	output->driver_private = private_data;
	xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
	for(i=0; i<size; mymode++, i++){


        	DisplayModePtr Mode,VMode;
		Mode = convert_to_video_timing(mymode);
		VMode = convert_to_video_timing(mymode);

		Modes = xf86ModesAdd(Modes, Mode);
            if(!VModes)
                VModes = VMode;
            else{
                VModes->next = VMode;
                VMode->prev  = VModes;
                VModes       = VModes->next;
            }

		if(!First){
			First = Modes;
			VFirst= VModes;
            	}
		End = Modes;
		VEnd= VModes;
    xf86DrvMsg(0, X_INFO, "%s VRefresh %f clock %d %d\n",Modes->name,Modes->VRefresh,Modes->Clock,__LINE__);
	}
        pScrn->monitor->Modes   = First;
        pScrn->monitor->Last    = End;
	pScrn->modes		= VFirst;
//	VFirst->prev		= VEnd;
//	VEnd->next		= VFirst;
	mode_ptr	= VFirst;
//	mode_ptr	= First;
	close(file);
	close(edid_file);
    return mode_ptr;
#if 0
//    mode_ptr =   fbdev_make_mode( 1024, 600 ,NULL);
    //pScrn->monitor
    /* add EDID detect by Wilhelm Viktor */
    DisplayModePtr Modes = NULL,VModes = NULL, First = NULL,VFirst, End, VEnd,prefered;
    int i,file,max_x=0,max_y=0;
    float max_refresh=0;
    static  char data_array[256];
    static  char *data;
    xf86MonPtr mon = NULL;
    data = (char *) data_array;
    file = open("/dev/i2c-1", O_RDWR);
    ioctl(file,I2C_SLAVE_FORCE,0x50);
    memset(data,0,256);
    read(file,data,128);
    mon = xf86InterpretEDID(pScrn->scrnIndex,data);
    xf86OutputSetEDID(output, mon);
    /* std modes add */
    for(i=0; i<8; i++){
        DisplayModePtr Mode,VMode;
        if(mon->timings2[i].hsize && mon->timings2[i].vsize && mon->timings2[i].refresh){
            Mode = fbdev_make_mode_edid(mon->timings2[i].hsize,mon->timings2[i].vsize,
                mon->timings2[i].refresh,0);
            VMode = fbdev_make_mode_edid(mon->timings2[i].hsize,mon->timings2[i].vsize,
                mon->timings2[i].refresh,1);
            Modes = xf86ModesAdd(Modes, Mode);
            if(!VModes)
                VModes = VMode;
            else{
                VModes->next = VMode;
                VMode->prev  = VModes;
                VModes       = VModes->next;
            }
            if(!First){
                First = Modes;
                VFirst= VModes;
            }
    //      xf86DrvMsg(pScrn->scrnIndex, X_INFO, "VModes %p %p %p  %d\n",VModes,VModes->prev,VModes->next,i);
            if((max_x * max_y) < (Modes->HDisplay * Modes->VDisplay)){
                prefered    = VModes;
                max_x       = Modes->HDisplay;
                max_y       = Modes->VDisplay;
            }
            End = Modes;
            VEnd= VModes;
            xf86DrvMsg(pScrn->scrnIndex, X_INFO, "HDisplay %d VDisplay %d\n",Modes->HDisplay,Modes->VDisplay);
            xf86DrvMsg(pScrn->scrnIndex, X_INFO, "hsize %d vsize %d refresh %d\n",mon->timings2[i].hsize,
                mon->timings2[i].vsize,mon->timings2[i].refresh);
        }
    }
    pScrn->monitor->Modes   = First;
    pScrn->monitor->Last    = End;

//  VEnd->next      = VFirst;
//  VFirst->prev        = VEnd;
//  pScrn->modes        = prefered;
    mode_ptr        = prefered;
//  xf86SetModeDefaultName(mode_ptr);
    /* detailed timing modes add */
    {
    }
        xf86DrvMsg(0, X_INFO, "pScrn->modes %p \n",pScrn->modes);
    xf86DrvMsg(0, X_INFO, "%s %s %d\n",__FILE__,__func__,__LINE__);
    close(file);
#endif
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


